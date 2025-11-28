#include "parser.h"
#include "assembler.h"
#include "expression.h"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <regex>

Parser::Parser(const std::vector<Token>& tokens, Architecture arch)
    : tokens(tokens), currentPos(0), programCounter(0), currentArch(arch), defaultRadix(10),
      insideCBLOCK(false), cblockAddress(0),
      currentSectionType(SectionType::CODE), currentSectionName("_default_code"),
      codeProgramCounter(0), dataProgramCounter(0),
      insideMacroDefinition(false),
      macroExpansionDepth(0), localLabelCounter(0), conditionalDepth(0) {}

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
    try {
        if (str.empty()) {
            throw InvalidNumberFormatException(str, "empty number string");
        }

        std::string trimmed = str;
        // Remove whitespace
        trimmed.erase(0, trimmed.find_first_not_of(" \t"));
        trimmed.erase(trimmed.find_last_not_of(" \t") + 1);

        // Check if it's a symbol reference first
        if (symbolTable.hasSymbol(trimmed)) {
            return symbolTable.getSymbol(trimmed);
        }

        try {
            // Check for MPASM-style quoted numbers: D'255', H'FF', O'377', B'11111111'
            if (trimmed.length() >= 4 && trimmed[1] == '\'' && trimmed.back() == '\'') {
                char prefix = std::toupper(trimmed[0]);
                std::string numPart = trimmed.substr(2, trimmed.length() - 3);  // Extract between quotes

                if (prefix == 'D') {
                    return static_cast<uint16_t>(std::stoi(numPart, nullptr, 10));
                } else if (prefix == 'H') {
                    return static_cast<uint16_t>(std::stoi(numPart, nullptr, 16));
                } else if (prefix == 'O') {
                    return static_cast<uint16_t>(std::stoi(numPart, nullptr, 8));
                } else if (prefix == 'B') {
                    return static_cast<uint16_t>(std::stoi(numPart, nullptr, 2));
                }
            }

            // Check for hex (0x prefix)
            if (trimmed.size() >= 3 && trimmed[0] == '0' && (trimmed[1] == 'x' || trimmed[1] == 'X')) {
                return static_cast<uint16_t>(std::stoi(trimmed.substr(2), nullptr, 16));
            }

            // Check for octal (0o prefix)
            if (trimmed.size() >= 3 && trimmed[0] == '0' && (trimmed[1] == 'o' || trimmed[1] == 'O')) {
                return static_cast<uint16_t>(std::stoi(trimmed.substr(2), nullptr, 8));
            }

            // Check for binary (0b prefix)
            if (trimmed.size() >= 3 && trimmed[0] == '0' && (trimmed[1] == 'b' || trimmed[1] == 'B')) {
                return static_cast<uint16_t>(std::stoi(trimmed.substr(2), nullptr, 2));
            }

            // Check for hex (H suffix - MPASM style)
            if (trimmed.size() >= 2 && (trimmed.back() == 'h' || trimmed.back() == 'H')) {
                std::string hexStr = trimmed.substr(0, trimmed.length() - 1);
                return static_cast<uint16_t>(std::stoi(hexStr, nullptr, 16));
            }

            // Check for octal (O suffix - MPASM style)
            if (trimmed.size() >= 2 && (trimmed.back() == 'o' || trimmed.back() == 'O')) {
                std::string octStr = trimmed.substr(0, trimmed.length() - 1);
                return static_cast<uint16_t>(std::stoi(octStr, nullptr, 8));
            }

            // Check for binary (B suffix - MPASM style)
            if (trimmed.size() >= 2 && (trimmed.back() == 'b' || trimmed.back() == 'B')) {
                std::string binStr = trimmed.substr(0, trimmed.length() - 1);
                return static_cast<uint16_t>(std::stoi(binStr, nullptr, 2));
            }

            // Bare number - use default radix
            return static_cast<uint16_t>(std::stoi(trimmed, nullptr, defaultRadix));
        } catch (const std::invalid_argument&) {
            throw InvalidNumberFormatException(str, "invalid number format");
        } catch (const std::out_of_range&) {
            throw InvalidNumberFormatException(str, "number out of range (must be 0-65535)");
        }
    } catch (const InvalidNumberFormatException&) {
        throw;  // Re-throw our custom exception
    } catch (const std::exception& e) {
        throw InvalidNumberFormatException(str, std::string(e.what()));
    }
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
        check(TokenType::HEX_NUMBER) || check(TokenType::OCTAL_NUMBER) ||
        check(TokenType::BINARY_NUMBER) || check(TokenType::IDENTIFIER)) {

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
    uint16_t val;

    // Check if attempting to redefine a device register
    if (symbolTable.isDeviceRegister(label)) {
        errorReporter.reportError(current().line, current().column,
            "Cannot redefine device register: '" + label + "'",
            "Device register is read-only. Load it from device include file.", "");
        return;
    }

    // Check if value is a symbol reference
    if (symbolTable.hasSymbol(value)) {
        // Reference to another symbol
        val = symbolTable.getSymbol(value);
    } else {
        // Direct numeric value
        try {
            val = parseNumber(value);
        } catch (...) {
            // If parsing fails and it's not a symbol, default to 0 and report error
            errorReporter.reportError(current().line, current().column,
                "Invalid value for EQU: '" + value + "'",
                "Use a numeric value or a previously defined symbol", "");
            val = 0;
        }
    }

    symbolTable.addConstant(label, val);
}

void Parser::handleSET(const std::string& label, const std::string& value) {
    uint16_t val;

    // Check if attempting to redefine a device register
    if (symbolTable.isDeviceRegister(label)) {
        errorReporter.reportError(current().line, current().column,
            "Cannot redefine device register: '" + label + "'",
            "Device register is read-only. Load it from device include file.", "");
        return;
    }

    // Check if value is a symbol reference
    if (symbolTable.hasSymbol(value)) {
        // Reference to another symbol
        val = symbolTable.getSymbol(value);
    } else {
        // Direct numeric value
        try {
            val = parseNumber(value);
        } catch (...) {
            // If parsing fails and it's not a symbol, default to 0 and report error
            errorReporter.reportError(current().line, current().column,
                "Invalid value for SET: '" + value + "'",
                "Use a numeric value or a previously defined symbol", "");
            val = 0;
        }
    }

    // SET allows reassignment - use addVariable which allows overwriting
    symbolTable.addVariable(label, val);
}

void Parser::handleRADIX(const std::string& radixType) {
    std::string radix = radixType;
    std::transform(radix.begin(), radix.end(), radix.begin(), ::toupper);

    if (radix == "DEC" || radix == "DECIMAL") {
        defaultRadix = 10;
    } else if (radix == "HEX" || radix == "HEXADECIMAL") {
        defaultRadix = 16;
    } else if (radix == "OCT" || radix == "OCTAL") {
        defaultRadix = 8;
    } else if (radix == "BIN" || radix == "BINARY") {
        defaultRadix = 2;
    } else {
        errorReporter.reportError(current().line, current().column,
            "Invalid RADIX value: '" + radixType + "'",
            "Use DEC, HEX, OCT, or BIN", "");
    }
}

void Parser::handleDataDirective(const std::string& directiveName) {
    // Create a DataDefinition at current program counter
    DataDefinition dataDef;
    dataDef.address = programCounter;
    dataDef.sourceCode = directiveName;
    dataDef.lineNumber = current().line;

    // Parse all data values separated by commas
    advance();  // Skip the directive keyword itself
    int byteCount = 0;

    while (!check(TokenType::END_OF_FILE) && !check(TokenType::MNEMONIC) &&
           !check(TokenType::DIRECTIVE) && !check(TokenType::IDENTIFIER)) {

        if (check(TokenType::DECIMAL_NUMBER) || check(TokenType::HEX_NUMBER) ||
            check(TokenType::OCTAL_NUMBER) || check(TokenType::BINARY_NUMBER)) {
            uint16_t value = parseNumber(current().value);
            // For DB, store as single byte; for DW/DA, store as two bytes (little-endian)
            if (directiveName == "DB") {
                dataDef.bytes.push_back(value & 0xFF);
                byteCount += 1;
            } else {  // DW, DA, or DATA
                dataDef.bytes.push_back(value & 0xFF);
                dataDef.bytes.push_back((value >> 8) & 0xFF);
                byteCount += 2;
            }
            advance();
        } else if (check(TokenType::COMMA)) {
            advance();  // Skip comma
        } else {
            break;  // End of data values
        }
    }

    // Add data definition to collection
    if (!dataDef.bytes.empty()) {
        dataDefinitions.push_back(dataDef);
        // Advance program counter by number of words used
        // PIC16: Each word is 2 bytes
        programCounter += (byteCount + 1) / 2;  // Round up
    }
}

void Parser::parseDirective(const Token& directive) {
    std::string dirName = directive.value;
    std::transform(dirName.begin(), dirName.end(), dirName.begin(), ::toupper);

    if (dirName == "ORG") {
        // ORG address
        // Current position is at ORG token, peek at next token
        advance();  // Move to the address value
        if (check(TokenType::DECIMAL_NUMBER) || check(TokenType::HEX_NUMBER) ||
            check(TokenType::OCTAL_NUMBER) || check(TokenType::BINARY_NUMBER)) {
            handleORG(current().value);
            advance();  // Move past the address value
            // Now currentPos points to the token after the address
        }
        // Back up one position so the main loop can advance
        if (currentPos > 0) currentPos--;
    } else if (dirName == "END") {
        // End of assembly - nothing to do
    } else if (dirName == "DB" || dirName == "DW" || dirName == "DA" || dirName == "DATA") {
        // Data definition directive
        handleDataDirective(dirName);
        // Back up one position so the main loop can advance
        if (currentPos > 0) currentPos--;
    } else if (dirName == "PROCESSOR") {
        // PROCESSOR deviceName - set target device
        advance();  // Skip to device name
        if (check(TokenType::IDENTIFIER)) {
            advance();  // Skip past device name
        }
        // Back up one position
        if (currentPos > 0) currentPos--;
    } else if (dirName == "BANKSEL") {
        // BANKSEL symbol - Automatic bank selection (PIC16)
        advance();  // Move to symbol
        if (check(TokenType::IDENTIFIER)) {
            std::string symbol = current().value;
            handleBANKSEL(symbol, generatedInstructions);
            advance();
        } else {
            errorReporter.reportError(directive.line, directive.column, "BANKSEL requires a symbol name", "", "");
        }
        if (currentPos > 0) currentPos--;
    } else if (dirName == "PAGESEL") {
        // PAGESEL label - Automatic page selection (PIC18)
        advance();  // Move to label
        if (check(TokenType::IDENTIFIER)) {
            std::string label = current().value;
            handlePAGESEL(label, generatedInstructions);
            advance();
        } else {
            errorReporter.reportError(directive.line, directive.column, "PAGESEL requires a label name", "", "");
        }
        if (currentPos > 0) currentPos--;
    } else if (dirName == "__CONFIG" || dirName == "CONFIG") {
        // Configuration directive
        handleConfigDirective();
        // Back up one position
        if (currentPos > 0) currentPos--;
    } else if (dirName == "RADIX") {
        // RADIX directive - set default number base
        advance();  // Move to radix type
        if (check(TokenType::IDENTIFIER)) {
            handleRADIX(current().value);
            advance();  // Skip radix type
        }
        // Back up one position
        if (currentPos > 0) currentPos--;
    } else if (dirName == "CBLOCK") {
        // CBLOCK directive - sequential constant block
        advance();  // Move past CBLOCK
        std::string startAddr = "";
        if (check(TokenType::DECIMAL_NUMBER) || check(TokenType::HEX_NUMBER) ||
            check(TokenType::OCTAL_NUMBER) || check(TokenType::BINARY_NUMBER)) {
            startAddr = current().value;
            advance();  // Skip address
        }
        handleCBLOCK(startAddr);
        // Back up one position
        if (currentPos > 0) currentPos--;
    } else if (dirName == "ENDC") {
        // ENDC without CBLOCK
        if (!insideCBLOCK) {
            errorReporter.reportError(directive.line, directive.column, "ENDC without CBLOCK", "", "");
        }
        insideCBLOCK = false;
    } else if (dirName == "DT") {
        // DT directive - Define Table (generates RETLW instructions)
        handleDT();
        // Back up one position
        if (currentPos > 0) currentPos--;
    } else if (dirName == "MACRO") {
        // MACRO definition
        advance();  // Move past MACRO keyword
        if (check(TokenType::IDENTIFIER)) {
            std::string macroName = current().value;
            handleMACRO(macroName);
        } else {
            errorReporter.reportError(directive.line, directive.column, "MACRO requires a name", "", "");
        }
        // Back up one position
        if (currentPos > 0) currentPos--;
    } else if (dirName == "ENDM") {
        // ENDM outside of MACRO
        errorReporter.reportError(directive.line, directive.column, "ENDM without MACRO", "", "");
    } else if (dirName == "LOCAL") {
        // LOCAL directive (processed during macro definition)
        if (!insideMacroDefinition) {
            errorReporter.reportError(directive.line, directive.column, "LOCAL outside of MACRO", "", "");
        }
    } else if (dirName == "EXITM") {
        // EXITM outside of MACRO (processed during expansion)
        if (!insideMacroDefinition) {
            errorReporter.reportError(directive.line, directive.column, "EXITM outside of MACRO", "", "");
        }
    } else if (dirName == "IF") {
        // IF expression - evaluate at assembly time using current symbol table
        advance();  // Move to expression
        std::string condition = "";
        // Collect all tokens on this line as the condition
        uint32_t conditionLine = directive.line;
        while (!check(TokenType::END_OF_FILE) && current().line == conditionLine) {
            if (!condition.empty()) condition += " ";
            condition += current().value;
            advance();
        }
        handleIF(condition);
        if (currentPos > 0) currentPos--;
    } else if (dirName == "IFDEF") {
        // IFDEF symbol
        advance();  // Move to symbol
        if (check(TokenType::IDENTIFIER)) {
            std::string symbol = current().value;
            handleIFDEF(symbol);
            advance();
        } else {
            errorReporter.reportError(directive.line, directive.column, "IFDEF requires a symbol name", "", "");
        }
        if (currentPos > 0) currentPos--;
    } else if (dirName == "IFNDEF") {
        // IFNDEF symbol
        advance();  // Move to symbol
        if (check(TokenType::IDENTIFIER)) {
            std::string symbol = current().value;
            handleIFNDEF(symbol);
            advance();
        } else {
            errorReporter.reportError(directive.line, directive.column, "IFNDEF requires a symbol name", "", "");
        }
        if (currentPos > 0) currentPos--;
    } else if (dirName == "ELIF") {
        // ELIF expression
        advance();  // Move to expression
        std::string condition = "";
        // Collect all tokens on this line as the condition
        uint32_t conditionLine = directive.line;
        while (!check(TokenType::END_OF_FILE) && current().line == conditionLine) {
            if (!condition.empty()) condition += " ";
            condition += current().value;
            advance();
        }
        handleELIF(condition);
        if (currentPos > 0) currentPos--;
    } else if (dirName == "ELSE") {
        // ELSE - switch conditional block
        handleELSE();
    } else if (dirName == "ENDIF") {
        // ENDIF - end conditional block
        handleENDIF();
    } else if (dirName == "CODE") {
        // CODE [name] [address] - switch to CODE section
        advance();  // Move past CODE
        std::string nameAndAddress = "";
        // Collect all tokens on this line as section name/address
        uint32_t directiveLine = directive.line;
        while (!check(TokenType::END_OF_FILE) && current().line == directiveLine) {
            if (!nameAndAddress.empty()) nameAndAddress += " ";
            nameAndAddress += current().value;
            advance();
        }
        handleCODE(nameAndAddress);
        if (currentPos > 0) currentPos--;
    } else if (dirName == "UDATA" || dirName == "UDATA_ACS" || dirName == "UDATA_OVR" || dirName == "UDATA_SHR") {
        // UDATA [name] [address] - switch to UDATA section
        advance();  // Move past UDATA
        std::string nameAndAddress = "";
        // Collect all tokens on this line as section name/address
        uint32_t directiveLine = directive.line;
        while (!check(TokenType::END_OF_FILE) && current().line == directiveLine) {
            if (!nameAndAddress.empty()) nameAndAddress += " ";
            nameAndAddress += current().value;
            advance();
        }
        // Determine section type based on directive name
        SectionType sectionType = SectionType::UDATA;
        if (dirName == "UDATA_ACS") sectionType = SectionType::UDATA_ACS;
        else if (dirName == "UDATA_OVR") sectionType = SectionType::UDATA_OVR;
        else if (dirName == "UDATA_SHR") sectionType = SectionType::UDATA_SHR;

        handleUDATA(nameAndAddress, sectionType);
        if (currentPos > 0) currentPos--;
    } else if (dirName == "IDATA" || dirName == "IDATA_ACS") {
        // IDATA [name] [address] - switch to IDATA section
        advance();  // Move past IDATA
        std::string nameAndAddress = "";
        // Collect all tokens on this line as section name/address
        uint32_t directiveLine = directive.line;
        while (!check(TokenType::END_OF_FILE) && current().line == directiveLine) {
            if (!nameAndAddress.empty()) nameAndAddress += " ";
            nameAndAddress += current().value;
            advance();
        }
        handleIDATA(nameAndAddress);
        if (currentPos > 0) currentPos--;
    } else if (dirName == "RES") {
        // RES size - reserve space in UDATA section
        advance();  // Move past RES
        if (check(TokenType::DECIMAL_NUMBER) || check(TokenType::HEX_NUMBER) ||
            check(TokenType::OCTAL_NUMBER) || check(TokenType::BINARY_NUMBER)) {
            handleRES(current().value);
            advance();  // Skip size value
        } else {
            errorReporter.reportError(directive.line, directive.column, "RES requires a size value", "", "");
        }
        if (currentPos > 0) currentPos--;
    }
}

void Parser::firstPass() {
    // First pass: collect all labels and handle directives
    // This populates the symbol table before code generation
    currentPos = 0;
    programCounter = 0;

    // Initialize section state
    currentSectionType = SectionType::CODE;
    currentSectionName = "_default_code";
    codeProgramCounter = 0;
    dataProgramCounter = (currentArch == Architecture::PIC16) ? PIC16_DATA_START : PIC18_DATA_START;

    // Create implicit default CODE section
    SectionDefinition defaultCode;
    defaultCode.name = "_default_code";
    defaultCode.type = SectionType::CODE;
    defaultCode.startAddress = 0;
    defaultCode.currentAddress = 0;
    defaultCode.hasExplicitAddress = true;
    defaultCode.isAbsolute = true;
    namedSections.clear();
    namedSections[defaultCode.name] = defaultCode;

    while (!check(TokenType::END_OF_FILE)) {
        // Check for conditional directives - ALWAYS process them even in inactive blocks
        if (check(TokenType::DIRECTIVE)) {
            std::string dirName = current().value;
            std::transform(dirName.begin(), dirName.end(), dirName.begin(), ::toupper);

            // Conditional directives are ALWAYS processed
            if (dirName == "IF" || dirName == "IFDEF" || dirName == "IFNDEF" ||
                dirName == "ELIF" || dirName == "ELSE" || dirName == "ENDIF") {
                parseDirective(current());
                advance();
                continue;
            }
        }

        // Skip processing if we're in an inactive conditional block
        if (!shouldProcessCurrentLine()) {
            advance();
            continue;
        }

        // Check for labels and EQU constants
        if (check(TokenType::IDENTIFIER)) {
            Token& identToken = current();
            if (peek().type == TokenType::COLON) {
                // Register label at current program counter
                std::string label = identToken.value;
                symbolTable.addLabel(label, programCounter);
                advance();  // Skip identifier
                advance();  // Skip colon
                continue;
            } else if (peek().type == TokenType::DIRECTIVE) {
                // Check if it's an EQU directive
                Token& directiveToken = peek();
                std::string dirName = directiveToken.value;
                std::transform(dirName.begin(), dirName.end(), dirName.begin(), ::toupper);

                if (dirName == "EQU") {
                    // Handle EQU: LABEL EQU value
                    std::string label = identToken.value;
                    advance();  // Skip identifier
                    advance();  // Skip EQU

                    // Get the value (next token should be a number or identifier)
                    if (check(TokenType::DECIMAL_NUMBER) || check(TokenType::HEX_NUMBER) ||
                        check(TokenType::OCTAL_NUMBER) || check(TokenType::BINARY_NUMBER) ||
                        check(TokenType::IDENTIFIER)) {
                        std::string value = current().value;
                        handleEQU(label, value);
                        advance();  // Skip value
                    }
                    continue;
                } else if (dirName == "SET") {
                    // Handle SET: LABEL SET value
                    std::string label = identToken.value;
                    advance();  // Skip identifier
                    advance();  // Skip SET

                    // Get the value (next token should be a number or identifier)
                    if (check(TokenType::DECIMAL_NUMBER) || check(TokenType::HEX_NUMBER) ||
                        check(TokenType::OCTAL_NUMBER) || check(TokenType::BINARY_NUMBER) ||
                        check(TokenType::IDENTIFIER)) {
                        std::string value = current().value;
                        handleSET(label, value);
                        advance();  // Skip value
                    }
                    continue;
                } else if (dirName == "MACRO") {
                    // Handle MACRO: NAME MACRO parameters...ENDM
                    std::string macroName = identToken.value;
                    advance();  // Skip identifier (macro name)
                    advance();  // Skip MACRO keyword
                    handleMACRO(macroName);
                    continue;
                }
            }
        }

        // Check for directives
        if (check(TokenType::DIRECTIVE)) {
            std::string dirName = current().value;
            std::transform(dirName.begin(), dirName.end(), dirName.begin(), ::toupper);

            // Handle MACRO specially - need to register in symbol table but don't parseDirective
            if (dirName == "MACRO") {
                advance();  // Move past MACRO keyword
                if (check(TokenType::IDENTIFIER)) {
                    std::string macroName = current().value;
                    handleMACRO(macroName);
                    // handleMACRO advances past ENDM, so continue
                    continue;
                }
            }

            parseDirective(current());

            // If it was a DT directive, the PC is already advanced in handleDT
            // Clear the generated instructions since we're only in first pass
            if (dirName == "DT") {
                generatedInstructions.clear();
            }

            advance();  // Skip past the directive and its operands
            continue;
        }

        // Check for mnemonics - they increment program counter
        if (check(TokenType::MNEMONIC)) {
            // Mnemonics only valid in CODE sections
            if (currentSectionType != SectionType::CODE) {
                errorReporter.reportError(current().line, current().column,
                    "Instructions only allowed in CODE sections",
                    "Use CODE directive before adding instructions", "");
            } else {
                programCounter++;
                codeProgramCounter++;
                // Update current section's address
                if (!currentSectionName.empty() && namedSections.find(currentSectionName) != namedSections.end()) {
                    namedSections[currentSectionName].currentAddress = codeProgramCounter;
                }
            }
            advance();
            continue;
        }

        // Skip other tokens
        advance();
    }

    // Reset position and state for second pass
    currentPos = 0;
    programCounter = 0;
    currentSectionType = SectionType::CODE;
    currentSectionName = "_default_code";
    codeProgramCounter = 0;
    dataProgramCounter = (currentArch == Architecture::PIC16) ? PIC16_DATA_START : PIC18_DATA_START;
}

std::vector<ParsedInstruction> Parser::parse() {
    // Two-pass assembly
    firstPass();  // First pass: collect all labels

    // Clear data definitions and generated instructions from first pass before second pass
    // (they were only needed to advance PC during first pass)
    dataDefinitions.clear();
    generatedInstructions.clear();

    // Reset conditional stack for second pass
    conditionalStack.clear();
    conditionalDepth = 0;
    currentPos = 0;
    programCounter = 0;

    // Initialize section state for second pass (same as firstPass)
    currentSectionType = SectionType::CODE;
    currentSectionName = "_default_code";
    codeProgramCounter = 0;
    dataProgramCounter = (currentArch == Architecture::PIC16) ? PIC16_DATA_START : PIC18_DATA_START;

    // Second pass: generate code using complete symbol table
    std::vector<ParsedInstruction> instructions;

    while (!check(TokenType::END_OF_FILE)) {
        // Check for conditional directives - ALWAYS process them even in inactive blocks
        if (check(TokenType::DIRECTIVE)) {
            std::string dirName = current().value;
            std::transform(dirName.begin(), dirName.end(), dirName.begin(), ::toupper);

            // Conditional directives are ALWAYS processed
            if (dirName == "IF" || dirName == "IFDEF" || dirName == "IFNDEF" ||
                dirName == "ELIF" || dirName == "ELSE" || dirName == "ENDIF") {
                parseDirective(current());
                advance();
                continue;
            }
        }

        // Skip processing if we're in an inactive conditional block
        if (!shouldProcessCurrentLine()) {
            advance();
            continue;
        }
        // Check for labels and EQU constants
        if (check(TokenType::IDENTIFIER)) {
            Token& identToken = current();
            if (peek().type == TokenType::COLON) {
                // This is a label
                std::string label = identToken.value;
                advance();  // Skip identifier
                advance();  // Skip colon
                symbolTable.addLabel(label, programCounter);
                continue;
            } else if (peek().type == TokenType::DIRECTIVE) {
                // Check if it's an EQU directive
                Token& directiveToken = peek();
                std::string dirName = directiveToken.value;
                std::transform(dirName.begin(), dirName.end(), dirName.begin(), ::toupper);

                if (dirName == "EQU") {
                    // Skip EQU in second pass (already processed in first pass)
                    advance();  // Skip identifier
                    advance();  // Skip EQU

                    // Skip the value
                    if (check(TokenType::DECIMAL_NUMBER) || check(TokenType::HEX_NUMBER) ||
                        check(TokenType::OCTAL_NUMBER) || check(TokenType::BINARY_NUMBER) ||
                        check(TokenType::IDENTIFIER)) {
                        advance();  // Skip value
                    }
                    continue;
                } else if (dirName == "SET") {
                    // Skip SET in second pass (already processed in first pass)
                    advance();  // Skip identifier
                    advance();  // Skip SET

                    // Skip the value
                    if (check(TokenType::DECIMAL_NUMBER) || check(TokenType::HEX_NUMBER) ||
                        check(TokenType::OCTAL_NUMBER) || check(TokenType::BINARY_NUMBER) ||
                        check(TokenType::IDENTIFIER)) {
                        advance();  // Skip value
                    }
                    continue;
                } else if (dirName == "MACRO") {
                    // Skip MACRO definitions in second pass (already registered in first pass)
                    advance();  // Skip identifier (macro name)
                    advance();  // Skip MACRO keyword
                    // Skip macro parameters
                    while (check(TokenType::IDENTIFIER) || check(TokenType::COMMA)) {
                        advance();
                    }
                    // Skip macro body until ENDM
                    int depth = 1;
                    while (!check(TokenType::END_OF_FILE) && depth > 0) {
                        if (check(TokenType::DIRECTIVE)) {
                            std::string innerDir = current().value;
                            std::transform(innerDir.begin(), innerDir.end(), innerDir.begin(), ::toupper);
                            if (innerDir == "MACRO") depth++;
                            else if (innerDir == "ENDM") depth--;
                        }
                        advance();
                    }
                    continue;
                }
            }
        }

        // Check for directives
        if (check(TokenType::DIRECTIVE)) {
            std::string dirName = current().value;
            std::transform(dirName.begin(), dirName.end(), dirName.begin(), ::toupper);

            // Skip MACRO definitions in second pass (already registered in first pass)
            if (dirName == "MACRO") {
                advance();  // Move past MACRO keyword
                if (check(TokenType::IDENTIFIER)) {
                    advance();  // Skip macro name
                }
                // Skip macro parameters
                while (check(TokenType::IDENTIFIER) || check(TokenType::COMMA)) {
                    advance();
                }
                // Skip macro body until ENDM
                int depth = 1;
                while (!check(TokenType::END_OF_FILE) && depth > 0) {
                    if (check(TokenType::DIRECTIVE)) {
                        std::string innerDir = current().value;
                        std::transform(innerDir.begin(), innerDir.end(), innerDir.begin(), ::toupper);
                        if (innerDir == "MACRO") depth++;
                        else if (innerDir == "ENDM") depth--;
                    }
                    advance();
                }
                continue;
            }

            parseDirective(current());

            // If it was a DT directive, add generated RETLW instructions
            if (dirName == "DT" && !generatedInstructions.empty()) {
                for (auto& instr : generatedInstructions) {
                    instructions.push_back(instr);
                }
                generatedInstructions.clear();
            }

            advance();  // Skip past the directive and its operands
            continue;
        }

        // Check for mnemonics
        if (check(TokenType::MNEMONIC)) {
            // Mnemonics only valid in CODE sections
            if (currentSectionType != SectionType::CODE) {
                errorReporter.reportError(current().line, current().column,
                    "Instructions only allowed in CODE sections",
                    "Use CODE directive before adding instructions", "");
                advance();
                continue;
            }

            Token& mnemonicToken = current();
            advance();
            try {
                ParsedInstruction instr = parseInstruction(mnemonicToken);
                instructions.push_back(instr);

                // Advance PC counters
                programCounter++;
                codeProgramCounter++;
                if (!currentSectionName.empty() && namedSections.find(currentSectionName) != namedSections.end()) {
                    namedSections[currentSectionName].currentAddress = codeProgramCounter;
                }
            } catch (const ParseError& e) {
                // Error already reported
            }
            continue;
        }

        // Check for macro invocation
        if (check(TokenType::IDENTIFIER) && macroTable.hasMacro(current().value)) {
            std::string macroName = current().value;
            int callLine = current().line;
            advance();

            auto macroInstructions = expandMacro(macroName, callLine);
            instructions.insert(instructions.end(),
                               macroInstructions.begin(),
                               macroInstructions.end());
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

void Parser::handleConfigDirective() {
    // Save line number for error reporting
    int lineNumber = current().line;
    std::string sourceLine = current().value;

    // Move past CONFIG/__CONFIG directive
    advance();

    // Parse the configuration value
    // Supports: __CONFIG 0x3F72 or __CONFIG _FOSC_INTRC & _WDTE_OFF & ...
    uint16_t configValue = 0xFFFF;  // Default: all bits set (unprogrammed state)
    bool firstOperand = true;

    // Collect all tokens until we hit end of line/file or another directive
    while (!check(TokenType::END_OF_FILE) &&
           !check(TokenType::MNEMONIC) &&
           !check(TokenType::DIRECTIVE)) {

        if (check(TokenType::HEX_NUMBER) || check(TokenType::DECIMAL_NUMBER) ||
            check(TokenType::OCTAL_NUMBER) || check(TokenType::BINARY_NUMBER)) {
            // Direct numeric value
            uint16_t value = parseNumber(current().value);
            if (firstOperand) {
                configValue = value;
                firstOperand = false;
            } else {
                // AND with previous value
                configValue &= value;
            }
            sourceLine += " " + current().value;
            advance();
        } else if (check(TokenType::IDENTIFIER)) {
            // Symbolic name (e.g., _FOSC_INTRC, _WDTE_OFF)
            std::string symbol = current().value;
            sourceLine += " " + symbol;

            // Try to resolve from symbol table
            if (symbolTable.hasSymbol(symbol)) {
                uint16_t value = symbolTable.getSymbol(symbol);
                if (firstOperand) {
                    configValue = value;
                    firstOperand = false;
                } else {
                    // AND with previous value
                    configValue &= value;
                }
            } else {
                // Symbol not defined - report warning but continue
                errorReporter.reportWarning(lineNumber, 0,
                    "CONFIG symbol '" + symbol + "' not defined, treating as 0xFFFF",
                    "Define the symbol with EQU or use numeric value", "");
            }
            advance();
        } else if (current().value == "&") {
            // AND operator - just skip it
            sourceLine += " &";
            advance();
        } else if (current().value == "|") {
            // OR operator
            sourceLine += " |";
            advance();
            // Next value will be ORed
            if (check(TokenType::HEX_NUMBER) || check(TokenType::DECIMAL_NUMBER) ||
                check(TokenType::OCTAL_NUMBER) || check(TokenType::BINARY_NUMBER)) {
                uint16_t value = parseNumber(current().value);
                configValue |= value;
                sourceLine += " " + current().value;
                advance();
            } else if (check(TokenType::IDENTIFIER)) {
                std::string symbol = current().value;
                if (symbolTable.hasSymbol(symbol)) {
                    configValue |= symbolTable.getSymbol(symbol);
                }
                sourceLine += " " + symbol;
                advance();
            }
        } else {
            // Unknown token, skip it
            advance();
        }

        // Stop at comma (for potential future multi-word CONFIG support)
        if (current().value == ",") {
            break;
        }
    }

    // Determine CONFIG word address based on architecture
    uint32_t configAddress;
    switch (currentArch) {
        case Architecture::PIC12:
            configAddress = 0x2007;  // PIC12 baseline config at 0x2007
            break;
        case Architecture::PIC16:
            configAddress = 0x2007;  // PIC16 mid-range config at 0x2007
            break;
        case Architecture::PIC18:
            configAddress = 0x300000;  // PIC18 config starts at 0x300000
            break;
        default:
            configAddress = 0x2007;
    }

    // Create ConfigWord entry
    ConfigWord config;
    config.address = configAddress;
    config.value = configValue;
    config.sourceCode = sourceLine;
    config.lineNumber = lineNumber;

    configWords.push_back(config);
}

void Parser::handleCBLOCK(const std::string& startAddrStr) {
    if (insideCBLOCK) {
        errorReporter.reportError(current().line, current().column, "Nested CBLOCK not allowed", "", "");
        return;
    }

    // Parse starting address (optional - continues from last if omitted)
    if (!startAddrStr.empty()) {
        cblockAddress = parseNumber(startAddrStr);
    }

    insideCBLOCK = true;

    // Process CBLOCK body
    while (!check(TokenType::END_OF_FILE)) {
        if (check(TokenType::DIRECTIVE)) {
            std::string dirName = current().value;
            std::transform(dirName.begin(), dirName.end(), dirName.begin(), ::toupper);

            if (dirName == "ENDC") {
                insideCBLOCK = false;
                advance();
                return;
            }
        }

        if (check(TokenType::IDENTIFIER)) {
            std::string varName = current().value;
            uint16_t size = 1;

            advance();

            // Check for :size suffix (e.g., var3:2)
            if (check(TokenType::COLON)) {
                advance();
                if (check(TokenType::DECIMAL_NUMBER) || check(TokenType::HEX_NUMBER) ||
                    check(TokenType::OCTAL_NUMBER) || check(TokenType::BINARY_NUMBER)) {
                    size = parseNumber(current().value);
                    advance();
                } else {
                    errorReporter.reportError(current().line, current().column, "Expected size after ':'", "", "");
                }
            }

            // Add constant to symbol table
            symbolTable.addConstant(varName, cblockAddress);
            cblockAddress += size;
        } else {
            advance();
        }
    }

    errorReporter.reportError(current().line, current().column, "CBLOCK without ENDC", "", "");
}

void Parser::handleDT() {
    advance();  // Skip DT directive

    bool expectingValue = true;

    while (!check(TokenType::END_OF_FILE) &&
           !check(TokenType::MNEMONIC) &&
           !check(TokenType::DIRECTIVE) &&
           !(check(TokenType::IDENTIFIER) && peek().type != TokenType::COMMA)) {

        if (check(TokenType::STRING)) {
            // Process each character in string
            std::string str = current().value;
            // Remove quotes if present
            if (!str.empty() && str.front() == '"' && str.back() == '"') {
                str = str.substr(1, str.length() - 2);
            }

            for (char c : str) {
                createRETLWInstruction(static_cast<uint8_t>(c));
            }
            advance();
            expectingValue = false;
        }
        else if (check(TokenType::DECIMAL_NUMBER) ||
                 check(TokenType::HEX_NUMBER) ||
                 check(TokenType::BINARY_NUMBER) ||
                 check(TokenType::OCTAL_NUMBER)) {

            uint16_t value = parseNumber(current().value);
            if (value > 255) {
                errorReporter.reportWarning(current().line, current().column,
                    "DT value " + std::to_string(value) + " truncated to 8 bits", "", "");
            }
            createRETLWInstruction(value & 0xFF);
            advance();
            expectingValue = false;
        }
        else if (check(TokenType::IDENTIFIER) && symbolTable.hasSymbol(current().value)) {
            // Symbol reference
            uint16_t value = symbolTable.getSymbol(current().value);
            if (value > 255) {
                errorReporter.reportWarning(current().line, current().column,
                    "DT symbol value " + std::to_string(value) + " truncated to 8 bits", "", "");
            }
            createRETLWInstruction(value & 0xFF);
            advance();
            expectingValue = false;
        }
        else if (check(TokenType::COMMA)) {
            if (expectingValue) {
                errorReporter.reportError(current().line, current().column,
                    "Expected value after comma", "", "");
            }
            advance();
            expectingValue = true;
        }
        else {
            break;  // End of DT values
        }
    }
}

void Parser::createRETLWInstruction(uint8_t literal) {
    ParsedInstruction instr{};
    instr.type = InstructionType::RETLW;
    instr.mnemonic = "RETLW";
    instr.k_value = literal;
    instr.address = programCounter;
    instr.line_number = current().line;
    instr.valid = true;

    generatedInstructions.push_back(instr);
    programCounter++;
}

void Parser::handleMACRO(const std::string& macroName) {
    if (insideMacroDefinition) {
        errorReporter.reportError(current().line, current().column, "Nested MACRO definitions not allowed", "", "");
        return;
    }

    insideMacroDefinition = true;
    currentMacro = MacroDefinition{};
    currentMacro.name = macroName;
    currentMacro.definitionLine = current().line;
    currentMacro.parameters.clear();
    currentMacro.localLabels.clear();
    macroBodyTokens.clear();

    // Note: macro name and MACRO keyword already advanced past by caller

    // Parse parameters (space or comma separated)
    // Stop at: MNEMONIC, DIRECTIVE, end of line, or non-parameter token
    uint32_t macroLine = current().line;
    while (check(TokenType::IDENTIFIER) || check(TokenType::COMMA)) {
        if (check(TokenType::COMMA)) {
            advance();
            continue;
        }

        // Stop if we hit a different line (macro parameters should be on first line)
        if (current().line != macroLine) {
            break;
        }

        currentMacro.parameters.push_back(current().value);
        advance();
    }

    // Collect body tokens until ENDM
    while (!check(TokenType::END_OF_FILE)) {
        if (check(TokenType::DIRECTIVE)) {
            std::string dirName = current().value;
            std::transform(dirName.begin(), dirName.end(), dirName.begin(), ::toupper);

            if (dirName == "ENDM") {
                currentMacro.body = macroBodyTokens;
                macroTable.addMacro(currentMacro.name, currentMacro);
                insideMacroDefinition = false;
                advance();
                return;
            }
            else if (dirName == "LOCAL") {
                // Parse LOCAL labels
                advance();
                while (check(TokenType::IDENTIFIER) || check(TokenType::COMMA)) {
                    if (check(TokenType::COMMA)) {
                        advance();
                        continue;
                    }
                    currentMacro.localLabels.push_back(current().value);
                    advance();
                }
                continue;  // Don't add LOCAL directive to body
            }
        }

        macroBodyTokens.push_back(current());
        advance();
    }

    errorReporter.reportError(current().line, current().column, "MACRO without ENDM", "", "");
}

void Parser::handleLOCAL() {
    // LOCAL directive is handled within handleMACRO
    // This is just a placeholder in case it's called elsewhere
}

std::vector<std::string> Parser::parseMacroArguments() {
    std::vector<std::string> args;

    // Track the line number where macro invocation starts
    uint32_t startLine = current().line;

    while (!check(TokenType::END_OF_FILE) &&
           current().line == startLine &&  // Stop at end of line
           !check(TokenType::MNEMONIC) &&
           !check(TokenType::DIRECTIVE) &&
           !(check(TokenType::IDENTIFIER) && peek().type == TokenType::COLON)) {

        if (check(TokenType::COMMA)) {
            advance();
            continue;
        }

        if (check(TokenType::IDENTIFIER) || check(TokenType::DECIMAL_NUMBER) ||
            check(TokenType::HEX_NUMBER) || check(TokenType::BINARY_NUMBER) ||
            check(TokenType::OCTAL_NUMBER)) {
            args.push_back(current().value);
            advance();
        } else {
            break;
        }
    }

    return args;
}

std::vector<ParsedInstruction> Parser::expandMacro(const std::string& macroName, int callLine) {
    if (macroExpansionDepth >= MAX_MACRO_DEPTH) {
        errorReporter.reportError(callLine, 0, "Macro expansion depth exceeded (recursive macro?)", "", "");
        return {};
    }

    macroExpansionDepth++;

    // Parse arguments
    std::vector<std::string> args = parseMacroArguments();

    // Expand macro
    try {
        std::vector<Token> expandedTokens = macroTable.expand(macroName, args, callLine, localLabelCounter);

        // Create sub-parser for expanded tokens
        Parser macroParser(expandedTokens, currentArch);
        macroParser.symbolTable = this->symbolTable;
        macroParser.programCounter = this->programCounter;
        macroParser.macroTable = this->macroTable;
        macroParser.macroExpansionDepth = this->macroExpansionDepth;
        macroParser.localLabelCounter = this->localLabelCounter;

        auto macroInstructions = macroParser.parse();

        // Update our state
        this->programCounter = macroParser.programCounter;
        this->localLabelCounter = macroParser.localLabelCounter;

        macroExpansionDepth--;

        return macroInstructions;
    } catch (const std::exception& e) {
        errorReporter.reportError(callLine, 0, std::string("Macro expansion error: ") + e.what(), "", "");
        macroExpansionDepth--;
        return {};
    }
}

// Assembly-time conditional directive handlers

bool Parser::shouldProcessCurrentLine() const {
    // If no conditional blocks are active, always process
    if (conditionalStack.empty()) {
        return true;
    }
    // Check if the current block is active
    return conditionalStack.back().isActive;
}

void Parser::handleIF(const std::string& condition) {
    AssemblyConditionalBlock block;
    block.type = AssemblyConditionalBlock::IF_TYPE;
    block.condition = condition;
    block.startLine = current().line;

    // Evaluate the condition using the current symbol table
    try {
        // Get symbol map for expression evaluation
        auto symbolMap = buildSymbolMap();
        ExpressionEvaluator evaluator(&symbolMap, programCounter);
        uint32_t result = evaluator.evaluate(condition);
        block.conditionMet = (result != 0);
        block.anyBranchTaken = block.conditionMet;
    } catch (const std::exception& e) {
        errorReporter.reportError(current().line, current().column,
            "IF condition evaluation error: " + std::string(e.what()), "", "");
        block.conditionMet = false;
        block.anyBranchTaken = false;
    }

    // Determine if we should process code in this block
    if (conditionalStack.empty()) {
        // No parent conditional block - process based on our condition
        block.isActive = block.conditionMet;
    } else {
        // Parent conditional block - only process if parent is active AND our condition is met
        block.isActive = conditionalStack.back().isActive && block.conditionMet;
    }

    conditionalStack.push_back(block);
    conditionalDepth++;
}

void Parser::handleIFDEF(const std::string& symbol) {
    AssemblyConditionalBlock block;
    block.type = AssemblyConditionalBlock::IFDEF_TYPE;
    block.symbol = symbol;
    block.startLine = current().line;

    // Check if symbol is defined (either constant, variable, or label)
    block.conditionMet = symbolTable.hasSymbol(symbol);
    block.anyBranchTaken = block.conditionMet;

    // Determine if we should process code in this block
    if (conditionalStack.empty()) {
        block.isActive = block.conditionMet;
    } else {
        block.isActive = conditionalStack.back().isActive && block.conditionMet;
    }

    conditionalStack.push_back(block);
    conditionalDepth++;
}

void Parser::handleIFNDEF(const std::string& symbol) {
    AssemblyConditionalBlock block;
    block.type = AssemblyConditionalBlock::IFNDEF_TYPE;
    block.symbol = symbol;
    block.startLine = current().line;

    // Check if symbol is NOT defined
    block.conditionMet = !symbolTable.hasSymbol(symbol);
    block.anyBranchTaken = block.conditionMet;

    // Determine if we should process code in this block
    if (conditionalStack.empty()) {
        block.isActive = block.conditionMet;
    } else {
        block.isActive = conditionalStack.back().isActive && block.conditionMet;
    }

    conditionalStack.push_back(block);
    conditionalDepth++;
}

void Parser::handleELIF(const std::string& condition) {
    if (conditionalStack.empty()) {
        errorReporter.reportError(current().line, current().column,
            "ELIF without IF", "", "");
        return;
    }

    AssemblyConditionalBlock& block = conditionalStack.back();

    // ELIF only works after IF (not after IFDEF/IFNDEF)
    if (block.type != AssemblyConditionalBlock::IF_TYPE) {
        errorReporter.reportError(current().line, current().column,
            "ELIF can only follow IF, not IFDEF/IFNDEF", "", "");
        return;
    }

    // If a previous branch was taken, deactivate
    if (block.anyBranchTaken) {
        block.isActive = false;
        return;
    }

    // Try to evaluate the ELIF condition
    try {
        // Get symbol map for expression evaluation
        auto symbolMap = buildSymbolMap();
        ExpressionEvaluator evaluator(&symbolMap, programCounter);
        uint32_t result = evaluator.evaluate(condition);
        bool conditionMet = (result != 0);

        block.condition = condition;
        block.conditionMet = conditionMet;

        // Determine if we should process this branch
        if (conditionalStack.size() > 1) {
            // Check parent block status
            block.isActive = conditionalStack[conditionalStack.size() - 2].isActive && conditionMet;
        } else {
            block.isActive = conditionMet;
        }

        if (conditionMet) {
            block.anyBranchTaken = true;
        }
    } catch (const std::exception& e) {
        errorReporter.reportError(current().line, current().column,
            "ELIF condition evaluation error: " + std::string(e.what()), "", "");
        block.isActive = false;
    }
}

void Parser::handleELSE() {
    if (conditionalStack.empty()) {
        errorReporter.reportError(current().line, current().column,
            "ELSE without IF/IFDEF/IFNDEF", "", "");
        return;
    }

    AssemblyConditionalBlock& block = conditionalStack.back();

    // If a previous branch (IF or ELIF) was taken, deactivate ELSE
    if (block.anyBranchTaken) {
        block.isActive = false;
    } else {
        // ELSE is active if the previous condition was false and parent is active
        if (conditionalStack.size() > 1) {
            block.isActive = conditionalStack[conditionalStack.size() - 2].isActive;
        } else {
            block.isActive = true;
        }
        block.anyBranchTaken = true;
    }
}

void Parser::handleENDIF() {
    if (conditionalStack.empty()) {
        errorReporter.reportError(current().line, current().column,
            "ENDIF without IF/IFDEF/IFNDEF", "", "");
        return;
    }

    conditionalStack.pop_back();
    conditionalDepth--;
}

std::map<std::string, uint32_t> Parser::buildSymbolMap() const {
    // Build a map of all symbols for expression evaluation
    return symbolTable.getAllSymbols();
}

void Parser::handleBANKSEL(const std::string& symbol, std::vector<ParsedInstruction>& instructions) {
    // BANKSEL - Automatic bank selection for PIC16/PIC18
    // For PIC16: Sets RP1:RP0 bits in STATUS register (2 instructions)
    // For PIC18: Sets BSR register (2 instructions)

    if (currentArch == Architecture::PIC18) {
        // PIC18 - Set BSR (Bank Select Register) for indirect addressing
        // BSR[3:0] selects the 256-byte RAM bank
        // Always advance PC by 2 (MOVLW + MOVWF)
        programCounter += 2;

        if (!symbolTable.hasSymbol(symbol)) {
            // Symbol might not be defined yet in first pass
            // Don't report error - let second pass handle it
            return;
        }

        uint16_t address = symbolTable.getSymbol(symbol);
        uint8_t bankNum = (address >> 8) & 0x0F;  // Bank = address / 256

        // Generate: MOVLW bank_number; MOVWF BSR
        ParsedInstruction movlw;
        movlw.type = InstructionType::MOVLW;
        movlw.mnemonic = "MOVLW";
        movlw.k_value = bankNum;
        movlw.line_number = current().line;
        movlw.address = programCounter - 2;  // Use adjusted address
        movlw.valid = true;
        generatedInstructions.push_back(movlw);

        // MOVWF BSR (0xE8 is BSR in PIC18 data memory, but as file register it's 0xE8 in lower 256)
        ParsedInstruction movwf;
        movwf.type = InstructionType::MOVWF;
        movwf.mnemonic = "MOVWF";
        movwf.f_reg = 0xE8;  // BSR register in PIC18 (within 0-255 range for MOVWF)
        movwf.line_number = current().line;
        movwf.address = programCounter - 1;  // Use adjusted address
        movwf.valid = true;
        generatedInstructions.push_back(movwf);

    } else if (currentArch == Architecture::PIC16) {
        // PIC16 - Set RP1:RP0 bits in STATUS register
        // Bank 0: RP1=0, RP0=0
        // Bank 1: RP1=0, RP0=1
        // Bank 2: RP1=1, RP0=0
        // Bank 3: RP1=1, RP0=1
        // Always generates 2 instructions (one for RP0, one for RP1)
        programCounter += 2;

        if (!symbolTable.hasSymbol(symbol)) {
            // Symbol might not be defined yet in first pass
            // Don't report error - let second pass handle it
            return;
        }

        uint16_t address = symbolTable.getSymbol(symbol);
        uint8_t bankNum = (address / 128) & 0x03;  // Bank = address / 128, max 4 banks
        bool rp0 = (bankNum & 0x01) != 0;  // RP0 is bit 5 of STATUS
        bool rp1 = (bankNum & 0x02) != 0;  // RP1 is bit 6 of STATUS

        // STATUS register is at address 0x03, RP1 is bit 6, RP0 is bit 5
        const uint8_t STATUS_REG = 0x03;
        const uint8_t RP0_BIT = 5;
        const uint8_t RP1_BIT = 6;

        // Generate BCF/BSF instructions to set appropriate bits
        if (!rp0) {
            // Clear RP0: BCF STATUS, 5
            ParsedInstruction bcf_rp0;
            bcf_rp0.type = InstructionType::BCF;
            bcf_rp0.mnemonic = "BCF";
            bcf_rp0.f_reg = STATUS_REG;
            bcf_rp0.b_bit = RP0_BIT;
            bcf_rp0.line_number = current().line;
            bcf_rp0.address = programCounter - 2;  // Use adjusted address
            bcf_rp0.valid = true;
            generatedInstructions.push_back(bcf_rp0);
        } else {
            // Set RP0: BSF STATUS, 5
            ParsedInstruction bsf_rp0;
            bsf_rp0.type = InstructionType::BSF;
            bsf_rp0.mnemonic = "BSF";
            bsf_rp0.f_reg = STATUS_REG;
            bsf_rp0.b_bit = RP0_BIT;
            bsf_rp0.line_number = current().line;
            bsf_rp0.address = programCounter - 2;  // Use adjusted address
            bsf_rp0.valid = true;
            generatedInstructions.push_back(bsf_rp0);
        }

        if (!rp1) {
            // Clear RP1: BCF STATUS, 6
            ParsedInstruction bcf_rp1;
            bcf_rp1.type = InstructionType::BCF;
            bcf_rp1.mnemonic = "BCF";
            bcf_rp1.f_reg = STATUS_REG;
            bcf_rp1.b_bit = RP1_BIT;
            bcf_rp1.line_number = current().line;
            bcf_rp1.address = programCounter - 1;  // Use adjusted address
            bcf_rp1.valid = true;
            generatedInstructions.push_back(bcf_rp1);
        } else {
            // Set RP1: BSF STATUS, 6
            ParsedInstruction bsf_rp1;
            bsf_rp1.type = InstructionType::BSF;
            bsf_rp1.mnemonic = "BSF";
            bsf_rp1.f_reg = STATUS_REG;
            bsf_rp1.b_bit = RP1_BIT;
            bsf_rp1.line_number = current().line;
            bsf_rp1.address = programCounter - 1;  // Use adjusted address
            bsf_rp1.valid = true;
            generatedInstructions.push_back(bsf_rp1);
        }
    }
}

void Parser::handlePAGESEL(const std::string& label, std::vector<ParsedInstruction>& instructions) {
    // PAGESEL - Automatic page selection for PIC18
    // Sets PCLATH[7:3] to select the 2KB page

    if (currentArch != Architecture::PIC18) {
        std::string archName = (currentArch == Architecture::PIC16 ? "PIC16" : "PIC12");
        errorReporter.reportWarning(current().line, current().column,
            "PAGESEL is only for PIC18, not supported on " + archName, "", "");
        // Still advance PC by 2 since PAGESEL always generates 2 instructions
        programCounter += 2;
        return;
    }

    // Always advance PC by 2 (PAGESEL always generates MOVLW + MOVWF)
    // This ensures correct PC tracking even if symbol doesn't exist yet (first pass)
    programCounter += 2;

    if (!symbolTable.hasSymbol(label)) {
        // In first pass, symbol might not be defined yet
        // Don't report error - just skip code generation
        // Second pass will handle it when symbol is available
        return;
    }

    uint16_t address = symbolTable.getSymbol(label);
    // Page = (address >> 11) & 0xFF (divide by 2048, max 255)
    // But we shift right by 8 from the page number to get the byte value for PCLATH
    uint8_t pageValue = (address >> 8) & 0xE0;  // Bits 7-5 of page number go to PCLATH[7:5]

    // Generate: MOVLW page_value; MOVWF PCLATH
    ParsedInstruction movlw;
    movlw.type = InstructionType::MOVLW;
    movlw.mnemonic = "MOVLW";
    movlw.k_value = pageValue;
    movlw.line_number = current().line;
    movlw.address = programCounter - 2;  // Use adjusted address since we already incremented
    movlw.valid = true;
    generatedInstructions.push_back(movlw);

    // MOVWF PCLATH (0xFA is PCLATH in PIC18 data memory, within 0-255 range for MOVWF)
    ParsedInstruction movwf;
    movwf.type = InstructionType::MOVWF;
    movwf.mnemonic = "MOVWF";
    movwf.f_reg = 0xFA;  // PCLATH register in PIC18 (within 0-255 range for MOVWF)
    movwf.line_number = current().line;
    movwf.address = programCounter - 1;  // Use adjusted address since we already incremented
    movwf.valid = true;
    generatedInstructions.push_back(movwf);
}

// Section directive handlers and helper functions

uint16_t Parser::getDefaultDataAddress(SectionType type) const {
    switch (type) {
        case SectionType::UDATA:
        case SectionType::UDATA_OVR:
        case SectionType::UDATA_SHR:
            return (currentArch == Architecture::PIC16)
                ? PIC16_DATA_START
                : PIC18_DATA_START;
        case SectionType::UDATA_ACS:
            return PIC18_ACS_START;  // PIC18 access bank
        case SectionType::IDATA:
        case SectionType::IDATA_ACS:
            return (currentArch == Architecture::PIC16)
                ? PIC16_DATA_START
                : PIC18_DATA_START;
        default:
            return 0;
    }
}

void Parser::validateDataAddress(uint16_t address, SectionType type) {
    // For PIC16: Check if address is in valid data memory range
    if (currentArch == Architecture::PIC16) {
        // PIC16 typically has banks: 0x20-0x7F, 0xA0-0xFF, etc.
        // For now, just warn about SFR area (0x00-0x1F)
        if (address < 0x20) {
            errorReporter.reportWarning(current().line, current().column,
                "Data address 0x" + std::to_string(address) + " in special function register area",
                "Use addresses 0x20 and above for general purpose RAM");
        }
    }

    // For PIC18 UDATA_ACS: Must be in access bank
    if (type == SectionType::UDATA_ACS) {
        if (currentArch != Architecture::PIC18) {
            errorReporter.reportError(current().line, current().column,
                "UDATA_ACS only supported on PIC18 architecture", "", "");
        }
        // Access bank is typically 0x000-0x05F and 0xF60-0xFFF
        // For simplicity, we'll allow 0x000-0x0FF for now
        if (address > 0x0FF) {
            errorReporter.reportWarning(current().line, current().column,
                "UDATA_ACS address 0x" + std::to_string(address) + " may be outside access bank", "");
        }
    }
}

void Parser::validateCodeAddress(uint16_t address) {
    // Validate against device specs would go here
    // For now, just prevent obviously invalid addresses
    if (address > 0xFFFF) {
        errorReporter.reportError(current().line, current().column,
            "Code address exceeds 16-bit address space", "", "");
    }
}

void Parser::handleCODE(const std::string& nameAndAddress) {
    // Parse: [name] CODE [address]
    // Examples:
    //   CODE           -> unnamed CODE section at implicit address
    //   CODE 0x100     -> unnamed CODE section at 0x100
    //   RESET CODE 0   -> named "RESET" section at 0x0000
    //   RESET CODE     -> switch to existing named section or create at implicit address

    std::string sectionName = "";
    uint16_t address = codeProgramCounter;
    bool hasAddress = false;

    // Simple parsing: if there are tokens, treat first as name, second as address
    // This is a simplified approach - full MPASM parsing would be more complex
    std::istringstream iss(nameAndAddress);
    std::string token1, token2;
    iss >> token1;
    if (iss >> token2) {
        sectionName = token1;
        try {
            address = parseNumber(token2);
            hasAddress = true;
        } catch (...) {
            // If we can't parse as number, treat both as section name parts
            sectionName = nameAndAddress;
        }
    } else if (!token1.empty()) {
        // Single token - could be name or address
        try {
            address = parseNumber(token1);
            hasAddress = true;
            sectionName = "_default_code";
        } catch (...) {
            sectionName = token1;
        }
    } else {
        sectionName = "_default_code";
    }

    validateCodeAddress(address);

    // Check if this is a new section or switching to existing
    if (!sectionName.empty() && namedSections.find(sectionName) != namedSections.end()) {
        // Switching to existing section
        auto& section = namedSections[sectionName];
        if (section.type != SectionType::CODE) {
            errorReporter.reportError(current().line, current().column,
                "Section '" + sectionName + "' was previously defined as a " +
                (section.type == SectionType::CODE ? "CODE" : "DATA") + " section",
                "Cannot switch to CODE if previously UDATA", "");
            return;
        }
        currentSectionType = section.type;
        currentSectionName = sectionName;
        programCounter = section.currentAddress;
        codeProgramCounter = programCounter;
    } else {
        // Creating new CODE section
        SectionDefinition section;
        section.name = sectionName;
        section.type = SectionType::CODE;
        section.startAddress = address;
        section.currentAddress = address;
        section.hasExplicitAddress = hasAddress;
        section.isAbsolute = true;

        namedSections[sectionName] = section;
        currentSectionType = SectionType::CODE;
        currentSectionName = sectionName;
        programCounter = address;
        codeProgramCounter = address;
    }
}

void Parser::handleUDATA(const std::string& nameAndAddress, SectionType type) {
    // Parse: [name] UDATA [address]
    // Similar structure to handleCODE but for data sections

    std::string sectionName = "";
    uint16_t address = getDefaultDataAddress(type);
    bool hasAddress = false;

    std::istringstream iss(nameAndAddress);
    std::string token1, token2;
    iss >> token1;
    if (iss >> token2) {
        sectionName = token1;
        try {
            address = parseNumber(token2);
            hasAddress = true;
        } catch (...) {
            sectionName = nameAndAddress;
        }
    } else if (!token1.empty()) {
        try {
            address = parseNumber(token1);
            hasAddress = true;
            sectionName = "_default_data";
        } catch (...) {
            sectionName = token1;
        }
    } else {
        sectionName = "_default_data";
    }

    validateDataAddress(address, type);

    // Check if this is a new section or switching to existing
    if (!sectionName.empty() && namedSections.find(sectionName) != namedSections.end()) {
        // Switching to existing section
        auto& section = namedSections[sectionName];
        if (section.type != type) {
            errorReporter.reportError(current().line, current().column,
                "Section '" + sectionName + "' was previously defined with different type",
                "Cannot change section type", "");
            return;
        }
        currentSectionType = section.type;
        currentSectionName = sectionName;
        programCounter = section.currentAddress;
        dataProgramCounter = programCounter;
    } else {
        // Creating new UDATA section
        SectionDefinition section;
        section.name = sectionName;
        section.type = type;
        section.startAddress = address;
        section.currentAddress = address;
        section.hasExplicitAddress = hasAddress;
        section.isAbsolute = true;

        namedSections[sectionName] = section;
        currentSectionType = type;
        currentSectionName = sectionName;
        programCounter = address;
        dataProgramCounter = address;
    }
}

void Parser::handleIDATA(const std::string& nameAndAddress) {
    // IDATA sections allocate in data memory but store initial values in program memory
    // For now, treat similar to UDATA but mark as initialized

    std::string sectionName = "";
    uint16_t address = getDefaultDataAddress(SectionType::IDATA);
    bool hasAddress = false;

    std::istringstream iss(nameAndAddress);
    std::string token1, token2;
    iss >> token1;
    if (iss >> token2) {
        sectionName = token1;
        try {
            address = parseNumber(token2);
            hasAddress = true;
        } catch (...) {
            sectionName = nameAndAddress;
        }
    } else if (!token1.empty()) {
        try {
            address = parseNumber(token1);
            hasAddress = true;
            sectionName = "_default_idata";
        } catch (...) {
            sectionName = token1;
        }
    } else {
        sectionName = "_default_idata";
    }

    validateDataAddress(address, SectionType::IDATA);

    // Check if this is a new section or switching to existing
    if (!sectionName.empty() && namedSections.find(sectionName) != namedSections.end()) {
        // Switching to existing section
        auto& section = namedSections[sectionName];
        if (section.type != SectionType::IDATA && section.type != SectionType::IDATA_ACS) {
            errorReporter.reportError(current().line, current().column,
                "Section '" + sectionName + "' was previously defined with different type",
                "Cannot change section type", "");
            return;
        }
        currentSectionType = section.type;
        currentSectionName = sectionName;
        programCounter = section.currentAddress;
        dataProgramCounter = programCounter;
    } else {
        // Creating new IDATA section
        SectionDefinition section;
        section.name = sectionName;
        section.type = SectionType::IDATA;
        section.startAddress = address;
        section.currentAddress = address;
        section.hasExplicitAddress = hasAddress;
        section.isAbsolute = true;

        namedSections[sectionName] = section;
        currentSectionType = SectionType::IDATA;
        currentSectionName = sectionName;
        programCounter = address;
        dataProgramCounter = address;
    }
}

void Parser::handleRES(const std::string& sizeStr) {
    // RES directive - only valid inside UDATA/IDATA sections
    if (currentSectionType != SectionType::UDATA &&
        currentSectionType != SectionType::UDATA_ACS &&
        currentSectionType != SectionType::UDATA_OVR &&
        currentSectionType != SectionType::UDATA_SHR &&
        currentSectionType != SectionType::IDATA &&
        currentSectionType != SectionType::IDATA_ACS) {
        errorReporter.reportError(current().line, current().column,
            "RES directive only valid in UDATA/IDATA sections",
            "Use RES inside a UDATA or IDATA section", "");
        return;
    }

    // Format: label RES size
    // The label should have been processed already
    // Just advance the data PC by size bytes
    uint16_t size = 0;
    try {
        size = parseNumber(sizeStr);
    } catch (...) {
        errorReporter.reportError(current().line, current().column,
            "RES requires a numeric size value",
            "Example: var RES 2", "");
        return;
    }

    // Advance data program counter
    dataProgramCounter += size;
    programCounter = dataProgramCounter;

    // Update current section's address
    if (!currentSectionName.empty() && namedSections.find(currentSectionName) != namedSections.end()) {
        namedSections[currentSectionName].currentAddress = dataProgramCounter;
    }
}

void Parser::loadDeviceRegistersFromFile(const std::string& filePath) {
    // Load device register definitions from .inc files
    // Opens a file and extracts EQU statements, adding them as device registers

    std::ifstream file(filePath);
    if (!file.is_open()) {
        // File not found - warn but don't fail
        errorReporter.reportWarning(0, 0,
            "Device include file not found: " + filePath,
            "Register definitions will not be available");
        return;
    }

    std::string line;
    int lineNum = 0;

    // Regex for EQU statements: NAME equ HEX_VALUE
    // Matches: PORTA equ 0000h, STATUS equ 0x0003, WREG EQU 0009, etc.
    std::regex equRegex(
        R"(^\s*(\w+)\s+equ\s+(?:0x|H')?([0-9A-Fa-f]+)(?:h|')?\s*(?:;.*)?$)",
        std::regex_constants::icase
    );

    while (std::getline(file, line)) {
        lineNum++;

        // Skip empty lines and comments
        if (line.empty() || line[0] == ';') {
            continue;
        }

        // Skip lines with preprocessor directives
        if (line[0] == '#') {
            continue;
        }

        // Skip lines with C-style #define
        if (line.find("#define") != std::string::npos) {
            continue;
        }

        // Skip bitfield metadata (contains _POSN, _MASK, _SIZE, _LENGTH)
        if (line.find("_POSN") != std::string::npos ||
            line.find("_MASK") != std::string::npos ||
            line.find("_SIZE") != std::string::npos ||
            line.find("_LENGTH") != std::string::npos) {
            continue;
        }

        // Try to match EQU statement
        std::smatch match;
        if (std::regex_match(line, match, equRegex)) {
            std::string name = match[1].str();
            std::string hexValue = match[2].str();

            try {
                uint16_t address = std::stoul(hexValue, nullptr, 16);

                // Add to symbol table as device register
                symbolTable.addDeviceRegister(name, address);
            } catch (const std::exception& e) {
                // Invalid number format - skip
                errorReporter.reportWarning(lineNum, 0,
                    "Invalid hex value in EQU: " + hexValue,
                    "Skipping register definition");
            }
        }
    }
}
