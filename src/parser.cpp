#include "parser.h"
#include <sstream>
#include <algorithm>
#include <cctype>

Parser::Parser(const std::vector<Token>& tokens)
    : tokens(tokens), currentPos(0), programCounter(0) {}

Token& Parser::current() {
    static Token eof{TokenType::END_OF_FILE, "", 0, 0};
    if (currentPos >= tokens.size()) {
        return eof;
    }
    return tokens[currentPos];
}

const Token& Parser::current() const {
    static Token eof{TokenType::END_OF_FILE, "", 0, 0};
    if (currentPos >= tokens.size()) {
        return eof;
    }
    return tokens[currentPos];
}

Token& Parser::peek(size_t offset) {
    static Token eof{TokenType::END_OF_FILE, "", 0, 0};
    if (currentPos + offset >= tokens.size()) {
        return eof;
    }
    return tokens[currentPos + offset];
}

const Token& Parser::peek(size_t offset) const {
    static Token eof{TokenType::END_OF_FILE, "", 0, 0};
    if (currentPos + offset >= tokens.size()) {
        return eof;
    }
    return tokens[currentPos + offset];
}

void Parser::advance() {
    if (currentPos < tokens.size()) {
        currentPos++;
    }
}

bool Parser::match(TokenType type) {
    if (check(type)) {
        advance();
        return true;
    }
    return false;
}

bool Parser::check(TokenType type) const {
    return current().type == type;
}

Token& Parser::consume(TokenType type, const std::string& message) {
    if (!check(type)) {
        throw ParseError(current().line, message);
    }
    Token& token = current();
    advance();
    return token;
}

uint16_t Parser::parseNumber(const std::string& str) {
    if (str.empty()) {
        throw std::runtime_error("Empty number string");
    }

    std::string trimmed = str;
    // Remove whitespace
    trimmed.erase(0, trimmed.find_first_not_of(" \t"));
    trimmed.erase(trimmed.find_last_not_of(" \t") + 1);

    // Check for hex (0x prefix)
    if (trimmed.size() >= 3 && trimmed[0] == '0' && (trimmed[1] == 'x' || trimmed[1] == 'X')) {
        return static_cast<uint16_t>(std::stoi(trimmed.substr(2), nullptr, 16));
    }

    // Check for hex (H suffix - MPASM style)
    if (trimmed.size() >= 2 && (trimmed.back() == 'h' || trimmed.back() == 'H')) {
        std::string hexStr = trimmed.substr(0, trimmed.length() - 1);
        return static_cast<uint16_t>(std::stoi(hexStr, nullptr, 16));
    }

    // Check for binary (0b prefix)
    if (trimmed.size() >= 3 && trimmed[0] == '0' && (trimmed[1] == 'b' || trimmed[1] == 'B')) {
        return static_cast<uint16_t>(std::stoi(trimmed.substr(2), nullptr, 2));
    }

    // Check for binary (B suffix - MPASM style)
    if (trimmed.size() >= 2 && (trimmed.back() == 'b' || trimmed.back() == 'B')) {
        std::string binStr = trimmed.substr(0, trimmed.length() - 1);
        return static_cast<uint16_t>(std::stoi(binStr, nullptr, 2));
    }

    // Decimal
    return static_cast<uint16_t>(std::stoi(trimmed));
}

void Parser::parseOperands(ParsedInstruction& instr, const std::string& operandStr) {
    if (operandStr.empty()) {
        return;
    }

    std::istringstream iss(operandStr);
    std::string part;

    // For byte-oriented: f,d or f (first operand is file register)
    // For bit-oriented: f,b (first is file, second is bit)
    // For literal: k (immediate value)

    switch (instr.type) {
        case InstructionType::ADDWF:
        case InstructionType::ANDWF:
        case InstructionType::COMF:
        case InstructionType::DECF:
        case InstructionType::DECFSZ:
        case InstructionType::INCF:
        case InstructionType::INCFSZ:
        case InstructionType::IORWF:
        case InstructionType::MOVF:
        case InstructionType::RLF:
        case InstructionType::RRF:
        case InstructionType::SUBWF:
        case InstructionType::SWAPF:
        case InstructionType::XORWF: {
            // Format: f,d
            size_t commaPos = operandStr.find(',');
            if (commaPos == std::string::npos) {
                throw ParseError(instr.line_number, "Missing destination in byte-oriented instruction");
            }
            std::string fStr = operandStr.substr(0, commaPos);
            std::string dStr = operandStr.substr(commaPos + 1);

            // Remove whitespace
            fStr.erase(0, fStr.find_first_not_of(" \t"));
            fStr.erase(fStr.find_last_not_of(" \t") + 1);
            dStr.erase(0, dStr.find_first_not_of(" \t"));
            dStr.erase(dStr.find_last_not_of(" \t") + 1);

            instr.f_reg = static_cast<uint8_t>(parseNumber(fStr));
            instr.d_bit = static_cast<uint8_t>(parseNumber(dStr)) & 1;
            break;
        }

        case InstructionType::CLRF:
        case InstructionType::MOVWF: {
            // Format: f
            instr.f_reg = static_cast<uint8_t>(parseNumber(operandStr));
            break;
        }

        case InstructionType::BCF:
        case InstructionType::BSF:
        case InstructionType::BTFSC:
        case InstructionType::BTFSS: {
            // Format: f,b
            size_t commaPos = operandStr.find(',');
            if (commaPos == std::string::npos) {
                throw ParseError(instr.line_number, "Missing bit position in bit-oriented instruction");
            }
            std::string fStr = operandStr.substr(0, commaPos);
            std::string bStr = operandStr.substr(commaPos + 1);

            // Remove whitespace
            fStr.erase(0, fStr.find_first_not_of(" \t"));
            fStr.erase(fStr.find_last_not_of(" \t") + 1);
            bStr.erase(0, bStr.find_first_not_of(" \t"));
            bStr.erase(bStr.find_last_not_of(" \t") + 1);

            instr.f_reg = static_cast<uint8_t>(parseNumber(fStr));
            instr.b_bit = static_cast<uint8_t>(parseNumber(bStr)) & 0x07;
            break;
        }

        case InstructionType::ADDLW:
        case InstructionType::ANDLW:
        case InstructionType::IORLW:
        case InstructionType::MOVLW:
        case InstructionType::RETLW:
        case InstructionType::SUBLW:
        case InstructionType::XORLW:
        case InstructionType::CALL:
        case InstructionType::GOTO: {
            // Format: k or label
            std::string opStr = operandStr;
            opStr.erase(0, opStr.find_first_not_of(" \t"));
            opStr.erase(opStr.find_last_not_of(" \t") + 1);

            // Try to parse as number
            try {
                instr.k_value = parseNumber(opStr);
            } catch (...) {
                // Try as symbol
                if (symbolTable.hasSymbol(opStr)) {
                    instr.k_value = symbolTable.getSymbol(opStr);
                } else {
                    throw ParseError(instr.line_number, "Undefined symbol: " + opStr);
                }
            }
            break;
        }

        default:
            break;
    }
}

void Parser::validateOperands(ParsedInstruction& instr) {
    instr.valid = true;

    switch (instr.type) {
        case InstructionType::CLRW:
        case InstructionType::NOP:
        case InstructionType::CLRWDT:
        case InstructionType::RETFIE:
        case InstructionType::RETURN:
        case InstructionType::SLEEP:
            // No operands required
            break;

        case InstructionType::ADDWF:
        case InstructionType::ANDWF:
        case InstructionType::COMF:
        case InstructionType::DECF:
        case InstructionType::DECFSZ:
        case InstructionType::INCF:
        case InstructionType::INCFSZ:
        case InstructionType::IORWF:
        case InstructionType::MOVF:
        case InstructionType::RLF:
        case InstructionType::RRF:
        case InstructionType::SUBWF:
        case InstructionType::SWAPF:
        case InstructionType::XORWF:
            if (!isValidFileRegister(instr.f_reg)) {
                throw ParseError(instr.line_number, "Invalid file register: " + std::to_string(instr.f_reg));
            }
            break;

        case InstructionType::CLRF:
        case InstructionType::MOVWF:
            if (!isValidFileRegister(instr.f_reg)) {
                throw ParseError(instr.line_number, "Invalid file register: " + std::to_string(instr.f_reg));
            }
            break;

        case InstructionType::BCF:
        case InstructionType::BSF:
        case InstructionType::BTFSC:
        case InstructionType::BTFSS:
            if (!isValidFileRegister(instr.f_reg)) {
                throw ParseError(instr.line_number, "Invalid file register: " + std::to_string(instr.f_reg));
            }
            if (!isValidBitPosition(instr.b_bit)) {
                throw ParseError(instr.line_number, "Invalid bit position: " + std::to_string(instr.b_bit));
            }
            break;

        default:
            break;
    }
}

bool Parser::isValidFileRegister(uint8_t reg) const {
    return reg <= 255;  // 8-bit file register
}

bool Parser::isValidBitPosition(uint8_t bit) const {
    return bit <= 7;  // 3-bit bit position
}

ParsedInstruction Parser::parseInstruction(const Token& mnemonic) {
    ParsedInstruction instr{};
    instr.mnemonic = mnemonic.value;
    instr.line_number = mnemonic.line;
    instr.address = programCounter;

    InstructionSet& iset = InstructionSet::getInstance();
    instr.type = iset.getMnemonicType(mnemonic.value);

    if (instr.type == InstructionType::INVALID) {
        throw ParseError(mnemonic.line, "Unknown mnemonic: " + mnemonic.value);
    }

    // Skip optional operands if instruction has none
    if (check(TokenType::COMMA) || check(TokenType::DECIMAL_NUMBER) ||
        check(TokenType::HEX_NUMBER) || check(TokenType::BINARY_NUMBER) ||
        check(TokenType::IDENTIFIER)) {

        // Collect operand tokens
        std::string operandStr;
        while (!check(TokenType::END_OF_FILE) && !check(TokenType::DIRECTIVE) &&
               !check(TokenType::MNEMONIC)) {
            operandStr += current().value;
            advance();

            if (check(TokenType::END_OF_FILE) || check(TokenType::MNEMONIC) ||
                check(TokenType::DIRECTIVE)) {
                break;
            }

            // Add space between operands if next token is not a comma
            if (!check(TokenType::COMMA) && !check(TokenType::END_OF_FILE) &&
                !check(TokenType::MNEMONIC) && !check(TokenType::DIRECTIVE)) {
                operandStr += " ";
            }
        }

        if (!operandStr.empty()) {
            parseOperands(instr, operandStr);
        }
    }

    validateOperands(instr);
    programCounter++;

    return instr;
}

void Parser::handleORG(const std::string& arg) {
    programCounter = static_cast<uint16_t>(parseNumber(arg));
}

void Parser::handleEQU(const std::string& label, const std::string& value) {
    uint16_t val = parseNumber(value);
    symbolTable.addConstant(label, val);
}

void Parser::parseDirective(const Token& directive) {
    std::string dirName = directive.value;
    std::transform(dirName.begin(), dirName.end(), dirName.begin(), ::toupper);

    if (dirName == "ORG") {
        if (check(TokenType::DECIMAL_NUMBER) || check(TokenType::HEX_NUMBER)) {
            handleORG(current().value);
            advance();
        }
    } else if (dirName == "END") {
        // End of assembly
    }
}

std::vector<ParsedInstruction> Parser::parse() {
    std::vector<ParsedInstruction> instructions;

    while (!check(TokenType::END_OF_FILE)) {
        // Check for labels
        if (check(TokenType::IDENTIFIER)) {
            Token& identToken = current();
            if (peek().type == TokenType::COLON) {
                // This is a label
                std::string label = identToken.value;
                advance();  // Skip identifier
                advance();  // Skip colon
                symbolTable.addLabel(label, programCounter);
                continue;
            }
        }

        // Check for directives
        if (check(TokenType::DIRECTIVE)) {
            parseDirective(current());
            advance();
            continue;
        }

        // Check for mnemonics
        if (check(TokenType::MNEMONIC)) {
            Token& mnemonicToken = current();
            advance();
            try {
                ParsedInstruction instr = parseInstruction(mnemonicToken);
                instructions.push_back(instr);
            } catch (const ParseError& e) {
                throw e;
            }
            continue;
        }

        // Skip unknown tokens
        advance();
    }

    return instructions;
}
