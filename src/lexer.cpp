#include "lexer.h"
#include <cctype>
#include <algorithm>

Lexer::Lexer(const std::string& source)
    : source(source), position(0), line(1), column(1), cacheValid(false) {}

char Lexer::currentChar() const {
    if (position >= source.length()) return '\0';
    return source[position];
}

char Lexer::peekChar(size_t offset) const {
    if (position + offset >= source.length()) return '\0';
    return source[position + offset];
}

void Lexer::advance() {
    if (position < source.length()) {
        if (source[position] == '\n') {
            line++;
            column = 1;
        } else {
            column++;
        }
        position++;
    }
}

void Lexer::skipWhitespace() {
    while (position < source.length() && (currentChar() == ' ' || currentChar() == '\t')) {
        advance();
    }
}

void Lexer::skipComment() {
    if (currentChar() == ';') {
        while (position < source.length() && currentChar() != '\n') {
            advance();
        }
    }
}

bool Lexer::isMnemonic(const std::string& str) const {
    static const std::vector<std::string> mnemonics = {
        // PIC16/PIC18 Shared
        "ADDWF", "ANDWF", "CLRF", "CLRW", "COMF", "DECF", "DECFSZ", "INCF", "INCFSZ",
        "IORWF", "MOVF", "MOVWF", "NOP", "RLF", "RRF", "SUBWF", "SWAPF", "XORWF",
        "BCF", "BSF", "BTFSC", "BTFSS",
        "ADDLW", "ANDLW", "CALL", "CLRWDT", "GOTO", "IORLW", "MOVLW", "RETFIE",
        "RETLW", "RETURN", "SLEEP", "SUBLW", "XORLW",

        // PIC18 Specific
        "ADDWFC", "DCFSNZ", "INFSNZ", "MOVFF", "MULWF", "NEGF", "RLCF", "RLNCF", "RRCF", "RRNCF",
        "SETF", "SUBFWB", "SUBWFB", "TSTFSZ", "BTG", "CPFSEQ", "CPFSGT", "CPFSLT",
        "BC", "BN", "BNC", "BNN", "BNOV", "BNZ", "BOV", "BRA", "BZ",
        "CALLW", "RCALL", "DAW", "POP", "PUSH", "RESET",
        "ADDFSR", "LFSR", "MOVLB", "MULLW", "SUBFSR", "TBLRD", "TBLWT"
    };
    auto upper = str;
    std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    return std::find(mnemonics.begin(), mnemonics.end(), upper) != mnemonics.end();
}

bool Lexer::isDirective(const std::string& str) const {
    static const std::vector<std::string> directives = {
        // Preprocessor-only directives (removed: INCLUDE, DEFINE, IFDEF, IFNDEF, IF, ELIF, ELSE, ENDIF, ERROR, WARNING, LINE)
        // They are processed before the lexer and won't appear in the token stream
        "ORG", "END", "EQU", "SET",
        "DB", "DW", "DA", "DATA", "PROCESSOR", "__CONFIG", "CONFIG",
        "BANKSEL", "PAGESEL", "UDATA", "CODE", "RADIX",
        "CBLOCK", "ENDC", "DT", "MACRO", "ENDM", "LOCAL", "EXITM"
    };
    auto upper = str;
    std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    return std::find(directives.begin(), directives.end(), upper) != directives.end();
}

bool Lexer::isHexDigit(char c) const {
    return std::isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

bool Lexer::isOctalDigit(char c) const {
    return c >= '0' && c <= '7';
}

bool Lexer::isBinaryDigit(char c) const {
    return c == '0' || c == '1';
}

Token Lexer::readIdentifierOrMnemonic() {
    uint32_t startLine = line;
    uint32_t startColumn = column;
    std::string value;

    // Check for MPASM-style quoted numbers: D'255', H'FF', O'377', B'11111111'
    if (position < source.length() && std::isalpha(currentChar())) {
        char prefix = std::toupper(currentChar());
        if ((prefix == 'D' || prefix == 'H' || prefix == 'O' || prefix == 'B') &&
            position + 1 < source.length() && peekChar() == '\'') {
            // This looks like a quoted number
            value += currentChar();  // Add prefix (D/H/O/B)
            advance();
            value += currentChar();  // Add opening quote
            advance();

            std::string numPart;
            while (position < source.length() && currentChar() != '\'') {
                numPart += currentChar();
                value += currentChar();
                advance();
            }

            if (position < source.length() && currentChar() == '\'') {
                value += currentChar();  // Add closing quote
                advance();

                // Determine type based on prefix
                if (prefix == 'D') {
                    return {TokenType::DECIMAL_NUMBER, value, startLine, startColumn};
                } else if (prefix == 'H') {
                    return {TokenType::HEX_NUMBER, value, startLine, startColumn};
                } else if (prefix == 'O') {
                    return {TokenType::OCTAL_NUMBER, value, startLine, startColumn};
                } else if (prefix == 'B') {
                    return {TokenType::BINARY_NUMBER, value, startLine, startColumn};
                }
            }
            // If we didn't find closing quote, treat as identifier (fall through)
        }
    }

    while (position < source.length() && (std::isalnum(currentChar()) || currentChar() == '_')) {
        value += currentChar();
        advance();
    }

    // Check if this is a number with suffix (h/o/b)
    if (value.length() >= 2) {
        char suffix = std::tolower(value.back());
        std::string numPart = value.substr(0, value.length() - 1);

        // Check for hex suffix (h or H)
        if (suffix == 'h') {
            bool allHex = true;
            for (char c : numPart) {
                if (!isHexDigit(c)) {
                    allHex = false;
                    break;
                }
            }
            if (allHex && !numPart.empty()) {
                return {TokenType::HEX_NUMBER, value, startLine, startColumn};
            }
        }

        // Check for octal suffix (o or O)
        if (suffix == 'o') {
            bool allOctal = true;
            for (char c : numPart) {
                if (!isOctalDigit(c)) {
                    allOctal = false;
                    break;
                }
            }
            if (allOctal && !numPart.empty()) {
                return {TokenType::OCTAL_NUMBER, value, startLine, startColumn};
            }
        }

        // Check for binary suffix (b or B)
        if (suffix == 'b') {
            bool allBinary = true;
            for (char c : numPart) {
                if (!isBinaryDigit(c)) {
                    allBinary = false;
                    break;
                }
            }
            if (allBinary && !numPart.empty()) {
                return {TokenType::BINARY_NUMBER, value, startLine, startColumn};
            }
        }
    }

    TokenType type = TokenType::IDENTIFIER;
    if (isMnemonic(value)) {
        type = TokenType::MNEMONIC;
    } else if (isDirective(value)) {
        type = TokenType::DIRECTIVE;
    }

    return {type, value, startLine, startColumn};
}

Token Lexer::readNumber() {
    uint32_t startLine = line;
    uint32_t startColumn = column;
    std::string value;

    while (position < source.length() && std::isdigit(currentChar())) {
        value += currentChar();
        advance();
    }

    // Check for suffix-style notation (h/o/b)
    if (position < source.length()) {
        char nextChar = std::tolower(currentChar());

        // Check for hex suffix (h)
        if (nextChar == 'h') {
            bool allHex = true;
            for (char c : value) {
                if (!isHexDigit(c)) {
                    allHex = false;
                    break;
                }
            }
            if (allHex) {
                value += currentChar();
                advance();
                return {TokenType::HEX_NUMBER, value, startLine, startColumn};
            }
        }

        // Check for octal suffix (o)
        if (nextChar == 'o') {
            bool allOctal = true;
            for (char c : value) {
                if (!isOctalDigit(c)) {
                    allOctal = false;
                    break;
                }
            }
            if (allOctal) {
                value += currentChar();
                advance();
                return {TokenType::OCTAL_NUMBER, value, startLine, startColumn};
            }
        }

        // Check for binary suffix (b)
        if (nextChar == 'b') {
            bool allBinary = true;
            for (char c : value) {
                if (!isBinaryDigit(c)) {
                    allBinary = false;
                    break;
                }
            }
            if (allBinary) {
                value += currentChar();
                advance();
                return {TokenType::BINARY_NUMBER, value, startLine, startColumn};
            }
        }
    }

    return {TokenType::DECIMAL_NUMBER, value, startLine, startColumn};
}

Token Lexer::readHexNumber() {
    uint32_t startLine = line;
    uint32_t startColumn = column;
    std::string value;
    value += currentChar();  // Add '0'
    advance();

    if (currentChar() == 'x' || currentChar() == 'X') {
        value += currentChar();  // Add 'x' or 'X'
        advance();
    }

    // Ensure at least one hex digit after 0x
    if (!isHexDigit(currentChar())) {
        throw InvalidNumberFormatException(value, "expected hex digit after '" + value + "'");
    }

    while (position < source.length() && isHexDigit(currentChar())) {
        value += currentChar();
        advance();
    }

    return {TokenType::HEX_NUMBER, value, startLine, startColumn};
}

Token Lexer::readOctalNumber() {
    uint32_t startLine = line;
    uint32_t startColumn = column;
    std::string value;
    value += currentChar();  // Add '0'
    advance();

    if (currentChar() == 'o' || currentChar() == 'O') {
        value += currentChar();  // Add 'o' or 'O'
        advance();
    }

    // Ensure at least one octal digit after 0o
    if (!isOctalDigit(currentChar())) {
        throw InvalidNumberFormatException(value, "expected octal digit (0-7) after '" + value + "'");
    }

    while (position < source.length() && isOctalDigit(currentChar())) {
        value += currentChar();
        advance();
    }

    return {TokenType::OCTAL_NUMBER, value, startLine, startColumn};
}

Token Lexer::readBinaryNumber() {
    uint32_t startLine = line;
    uint32_t startColumn = column;
    std::string value;
    value += currentChar();  // Add '0'
    advance();

    if (currentChar() == 'b' || currentChar() == 'B') {
        value += currentChar();  // Add 'b' or 'B'
        advance();
    }

    // Ensure at least one binary digit after 0b
    if (!isBinaryDigit(currentChar())) {
        throw InvalidNumberFormatException(value, "expected binary digit (0 or 1) after '" + value + "'");
    }

    while (position < source.length() && isBinaryDigit(currentChar())) {
        value += currentChar();
        advance();
    }

    return {TokenType::BINARY_NUMBER, value, startLine, startColumn};
}

Token Lexer::readString() {
    uint32_t startLine = line;
    uint32_t startColumn = column;
    std::string value;

    advance(); // Skip opening quote

    while (position < source.length() && currentChar() != '"') {
        if (currentChar() == '\\') {
            advance();
            if (position < source.length()) {
                value += currentChar();
                advance();
            } else {
                throw UnterminatedStringException(startLine, startColumn);
            }
        } else if (currentChar() == '\n') {
            // String literals cannot span multiple lines
            throw UnterminatedStringException(startLine, startColumn);
        } else {
            value += currentChar();
            advance();
        }
    }

    if (currentChar() != '"') {
        throw UnterminatedStringException(startLine, startColumn);
    }

    advance(); // Skip closing quote
    return {TokenType::STRING, value, startLine, startColumn};
}

Token Lexer::nextToken() {
    if (cacheValid) {
        cacheValid = false;
        return nextTokenCache;
    }

    skipWhitespace();

    if (position >= source.length()) {
        return {TokenType::END_OF_FILE, "", line, column};
    }

    char c = currentChar();
    uint32_t tokenLine = line;
    uint32_t tokenColumn = column;

    // Comments
    if (c == ';') {
        skipComment();
        return nextToken();
    }

    // Newline
    if (c == '\n') {
        advance();
        return {TokenType::NEWLINE, "\n", tokenLine, tokenColumn};
    }

    // Single-character tokens
    if (c == ',') {
        advance();
        return {TokenType::COMMA, ",", tokenLine, tokenColumn};
    }
    if (c == ':') {
        advance();
        return {TokenType::COLON, ":", tokenLine, tokenColumn};
    }
    if (c == '(') {
        advance();
        return {TokenType::LPAREN, "(", tokenLine, tokenColumn};
    }
    if (c == ')') {
        advance();
        return {TokenType::RPAREN, ")", tokenLine, tokenColumn};
    }

    // Strings
    if (c == '"') {
        return readString();
    }

    // Numbers
    if (c == '0' && (peekChar() == 'x' || peekChar() == 'X')) {
        return readHexNumber();
    }
    if (c == '0' && (peekChar() == 'o' || peekChar() == 'O')) {
        return readOctalNumber();
    }
    if (c == '0' && (peekChar() == 'b' || peekChar() == 'B')) {
        return readBinaryNumber();
    }
    if (std::isdigit(c)) {
        return readNumber();
    }

    // Identifiers and keywords
    if (std::isalpha(c) || c == '_') {
        return readIdentifierOrMnemonic();
    }

    // Invalid character
    advance();
    return {TokenType::INVALID, std::string(1, c), tokenLine, tokenColumn};
}

Token Lexer::peekToken() {
    if (!cacheValid) {
        nextTokenCache = nextToken();
        cacheValid = true;
    }
    return nextTokenCache;
}

void Lexer::reset() {
    position = 0;
    line = 1;
    column = 1;
    cacheValid = false;
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    reset();

    Token token = nextToken();
    while (token.type != TokenType::END_OF_FILE) {
        if (token.type != TokenType::NEWLINE && token.type != TokenType::COMMENT) {
            tokens.push_back(token);
        }
        token = nextToken();
    }
    tokens.push_back(token);

    return tokens;
}
