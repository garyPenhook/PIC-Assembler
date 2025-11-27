#include "parser.h"
#include <sstream>
#include <algorithm>
#include <cctype>

Parser::Parser(const std::vector<Token>& tokens, Architecture arch)
    : tokens(tokens), currentPos(0), programCounter(0), currentArch(arch) {}

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
                std::string hint = "File register must be in range 0-255 (0x00-0xFF).\n" +
                                 std::string("  Format: MNEMONIC f,d where f=file register, d=0 (W) or 1 (file)");
                errorReporter.reportOperandError(instr.line_number,
                                               "f=" + std::to_string(instr.f_reg),
                                               "0-255", std::to_string(instr.f_reg));
                throw ParseError(instr.line_number, "Invalid file register: " + std::to_string(instr.f_reg));
            }
            break;

        case InstructionType::CLRF:
        case InstructionType::MOVWF:
            if (!isValidFileRegister(instr.f_reg)) {
                errorReporter.reportOperandError(instr.line_number,
                                               "f=" + std::to_string(instr.f_reg),
                                               "0-255", std::to_string(instr.f_reg));
                throw ParseError(instr.line_number, "Invalid file register: " + std::to_string(instr.f_reg));
            }
            break;

        case InstructionType::BCF:
        case InstructionType::BSF:
        case InstructionType::BTFSC:
        case InstructionType::BTFSS:
        case InstructionType::BTG:
            if (!isValidFileRegister(instr.f_reg)) {
                errorReporter.reportOperandError(instr.line_number,
                                               "f=" + std::to_string(instr.f_reg),
                                               "0-255", std::to_string(instr.f_reg));
                throw ParseError(instr.line_number, "Invalid file register: " + std::to_string(instr.f_reg));
            }
            if (!isValidBitPosition(instr.b_bit)) {
                std::string hint = "Bit position must be in range 0-7 (0=LSB, 7=MSB).\n" +
                                 std::string("  Format: MNEMONIC f,b where f=file register, b=bit position");
                errorReporter.reportOperandError(instr.line_number,
                                               "b=" + std::to_string(instr.b_bit),
                                               "0-7", std::to_string(instr.b_bit));
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
        // Provide helpful suggestions for common typos
        std::vector<std::string> suggestions;
        std::string upper = mnemonic.value;
        std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);

        // Check for common mnemonics with typos
        if (upper.find("MOV") != std::string::npos) {
            suggestions.push_back("MOVF - Move file register to W");
            suggestions.push_back("MOVWF - Move W to file register");
            suggestions.push_back("MOVLW - Move literal to W");
        } else if (upper.find("ADD") != std::string::npos) {
            suggestions.push_back("ADDWF - Add W to file register");
            suggestions.push_back("ADDLW - Add literal to W");
            suggestions.push_back("ADDWFC - Add W to file with carry (PIC18)");
        } else if (upper.find("INC") != std::string::npos) {
            suggestions.push_back("INCF - Increment file register");
            suggestions.push_back("INCFSZ - Increment, skip if zero");
        }

        errorReporter.reportSyntaxError(mnemonic.line, "Unknown mnemonic: '" + mnemonic.value + "'",
                                       suggestions, "");
        throw ParseError(mnemonic.line, "Unknown mnemonic: " + mnemonic.value);
    }

    // Check if instruction is valid for current architecture
    if (!iset.isValidForArchitecture(instr.type)) {
        std::string archName = (currentArch == Architecture::PIC16) ? "PIC16" : "PIC18";
        std::string requiredArch = (currentArch == Architecture::PIC16) ? "PIC18" : "PIC16";
        errorReporter.reportArchitectureError(mnemonic.line, mnemonic.value, archName, requiredArch);
        throw ParseError(mnemonic.line, "Instruction '" + mnemonic.value + "' not available in " +
                        archName + " architecture");
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
                // Error already reported
            }
            continue;
        }

        // Check for identifiers that might be mispelled mnemonics
        if (check(TokenType::IDENTIFIER)) {
            Token& token = current();
            // Check if this looks like it could be a mnemonic (all caps or mixed case with letters only)
            bool looksLikeMnemonic = true;
            for (char c : token.value) {
                if (!std::isalpha(c)) {
                    looksLikeMnemonic = false;
                    break;
                }
            }

            if (looksLikeMnemonic) {
                // This looks like a mnemonic but isn't recognized
                std::vector<std::string> suggestions;
                std::string upper = token.value;
                std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);

                if (upper.find("MOV") != std::string::npos) {
                    suggestions.push_back("MOVF - Move file register to W");
                    suggestions.push_back("MOVWF - Move W to file register");
                    suggestions.push_back("MOVLW - Move literal to W");
                } else if (upper.find("ADD") != std::string::npos) {
                    suggestions.push_back("ADDWF - Add W to file register");
                    suggestions.push_back("ADDLW - Add literal to W");
                } else if (upper.find("INC") != std::string::npos) {
                    suggestions.push_back("INCF - Increment file register");
                    suggestions.push_back("INCFSZ - Increment, skip if zero");
                } else if (upper.find("DEC") != std::string::npos) {
                    suggestions.push_back("DECF - Decrement file register");
                    suggestions.push_back("DECFSZ - Decrement, skip if zero");
                }

                errorReporter.reportSyntaxError(token.line,
                    "Unknown instruction '" + token.value + "'",
                    suggestions, "");
                advance();
                continue;
            }
        }

        // Skip unknown tokens
        advance();
    }

    return instructions;
}
