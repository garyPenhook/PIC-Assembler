#pragma once

#include <string>
#include <vector>
#include <cstdint>

enum class TokenType {
    // Literals and identifiers
    IDENTIFIER,
    DECIMAL_NUMBER,
    HEX_NUMBER,
    BINARY_NUMBER,
    STRING,

    // Operators and delimiters
    COMMA,
    COLON,
    LPAREN,
    RPAREN,

    // Keywords/mnemonics
    MNEMONIC,
    DIRECTIVE,

    // Special
    COMMENT,
    NEWLINE,
    END_OF_FILE,
    INVALID
};

struct Token {
    TokenType type;
    std::string value;
    uint32_t line;
    uint32_t column;
};

class Lexer {
public:
    explicit Lexer(const std::string& source);

    // Get the next token
    Token nextToken();

    // Peek at the next token without consuming it
    Token peekToken();

    // Reset to beginning
    void reset();

    // Get all tokens at once
    std::vector<Token> tokenize();

private:
    std::string source;
    size_t position;
    uint32_t line;
    uint32_t column;
    Token nextTokenCache;
    bool cacheValid;

    // Helper functions
    char currentChar() const;
    char peekChar(size_t offset = 1) const;
    void advance();
    void skipWhitespace();
    void skipComment();

    Token readIdentifierOrMnemonic();
    Token readNumber();
    Token readHexNumber();
    Token readBinaryNumber();
    Token readString();

    bool isMnemonic(const std::string& str) const;
    bool isDirective(const std::string& str) const;
    bool isHexDigit(char c) const;
    bool isBinaryDigit(char c) const;
};
