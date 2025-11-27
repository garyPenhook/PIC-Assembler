#pragma once

#include <string>
#include <map>
#include <cstdint>
#include <stdexcept>

class ExpressionError : public std::runtime_error {
public:
    explicit ExpressionError(const std::string& msg) : std::runtime_error(msg) {}
};

class ExpressionEvaluator {
public:
    // Constructor with optional symbol table and current program counter
    explicit ExpressionEvaluator(const std::map<std::string, uint32_t>* symbols = nullptr,
                                uint16_t currentPC = 0);

    // Evaluate expression and return value
    // Supports: +, -, *, /, %, &, |, ^, <<, >>, ~, !, ==, !=, <, >, <=, >=, &&, ||
    // Also supports: HIGH(expr), LOW(expr), UPPER(expr), $ (program counter)
    // Number formats: 0x123 (hex), 0b1010 (binary), 123 (decimal), H'FF', B'10101010', O'377'
    uint32_t evaluate(const std::string& expression);

    // Set symbol table (for label references)
    void setSymbols(const std::map<std::string, uint32_t>* symbols);

    // Set current program counter (for $ reference)
    void setCurrentPC(uint16_t pc);

private:
    const std::map<std::string, uint32_t>* symbols;
    uint16_t currentPC;
    std::string expr;
    size_t pos;

    // Parsing functions (recursive descent parser)
    uint32_t parseExpression();
    uint32_t parseLogicalOr();
    uint32_t parseLogicalAnd();
    uint32_t parseBitwiseOr();
    uint32_t parseBitwiseXor();
    uint32_t parseBitwiseAnd();
    uint32_t parseEquality();
    uint32_t parseComparison();
    uint32_t parseShift();
    uint32_t parseAddition();
    uint32_t parseMultiplication();
    uint32_t parseUnary();
    uint32_t parsePrimary();

    // Helper functions
    uint32_t parseNumber();
    uint32_t parseIdentifier();
    uint32_t parseFunction(const std::string& funcName);
    char peek();
    char advance();
    void skipWhitespace();
    bool isAtEnd();
};
