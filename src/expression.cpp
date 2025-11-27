#include "expression.h"
#include <cctype>
#include <cmath>
#include <sstream>

ExpressionEvaluator::ExpressionEvaluator(const std::map<std::string, uint32_t>* symbols,
                                         uint16_t currentPC)
    : symbols(symbols), currentPC(currentPC), pos(0) {
}

void ExpressionEvaluator::setSymbols(const std::map<std::string, uint32_t>* syms) {
    symbols = syms;
}

void ExpressionEvaluator::setCurrentPC(uint16_t pc) {
    currentPC = pc;
}

uint32_t ExpressionEvaluator::evaluate(const std::string& expression) {
    expr = expression;
    pos = 0;
    return parseExpression();
}

char ExpressionEvaluator::peek() {
    if (pos >= expr.length()) return '\0';
    return expr[pos];
}

char ExpressionEvaluator::advance() {
    if (pos >= expr.length()) return '\0';
    return expr[pos++];
}

void ExpressionEvaluator::skipWhitespace() {
    while (pos < expr.length() && std::isspace(expr[pos])) {
        pos++;
    }
}

bool ExpressionEvaluator::isAtEnd() {
    skipWhitespace();
    return pos >= expr.length();
}

uint32_t ExpressionEvaluator::parseExpression() {
    return parseLogicalOr();
}

uint32_t ExpressionEvaluator::parseLogicalOr() {
    uint32_t result = parseLogicalAnd();
    while (peek() == '|' && expr[pos + 1] == '|') {
        skipWhitespace();
        advance(); advance();  // consume ||
        uint32_t right = parseLogicalAnd();
        result = (result || right) ? 1 : 0;
    }
    return result;
}

uint32_t ExpressionEvaluator::parseLogicalAnd() {
    uint32_t result = parseBitwiseOr();
    while (peek() == '&' && expr[pos + 1] == '&') {
        skipWhitespace();
        advance(); advance();  // consume &&
        uint32_t right = parseBitwiseOr();
        result = (result && right) ? 1 : 0;
    }
    return result;
}

uint32_t ExpressionEvaluator::parseBitwiseOr() {
    uint32_t result = parseBitwiseXor();
    while (peek() == '|' && expr[pos + 1] != '|') {
        skipWhitespace();
        advance();  // consume |
        uint32_t right = parseBitwiseXor();
        result |= right;
    }
    return result;
}

uint32_t ExpressionEvaluator::parseBitwiseXor() {
    uint32_t result = parseBitwiseAnd();
    while (peek() == '^') {
        skipWhitespace();
        advance();  // consume ^
        uint32_t right = parseBitwiseAnd();
        result ^= right;
    }
    return result;
}

uint32_t ExpressionEvaluator::parseBitwiseAnd() {
    uint32_t result = parseEquality();
    while (peek() == '&' && expr[pos + 1] != '&') {
        skipWhitespace();
        advance();  // consume &
        uint32_t right = parseEquality();
        result &= right;
    }
    return result;
}

uint32_t ExpressionEvaluator::parseEquality() {
    uint32_t result = parseComparison();
    while (true) {
        skipWhitespace();
        if (peek() == '=' && expr[pos + 1] == '=') {
            advance(); advance();
            uint32_t right = parseComparison();
            result = (result == right) ? 1 : 0;
        } else if (peek() == '!' && expr[pos + 1] == '=') {
            advance(); advance();
            uint32_t right = parseComparison();
            result = (result != right) ? 1 : 0;
        } else {
            break;
        }
    }
    return result;
}

uint32_t ExpressionEvaluator::parseComparison() {
    uint32_t result = parseShift();
    while (true) {
        skipWhitespace();
        if (peek() == '<' && expr[pos + 1] == '=') {
            advance(); advance();
            uint32_t right = parseShift();
            result = (result <= right) ? 1 : 0;
        } else if (peek() == '>' && expr[pos + 1] == '=') {
            advance(); advance();
            uint32_t right = parseShift();
            result = (result >= right) ? 1 : 0;
        } else if (peek() == '<' && expr[pos + 1] != '<') {
            advance();
            uint32_t right = parseShift();
            result = (result < right) ? 1 : 0;
        } else if (peek() == '>' && expr[pos + 1] != '>') {
            advance();
            uint32_t right = parseShift();
            result = (result > right) ? 1 : 0;
        } else {
            break;
        }
    }
    return result;
}

uint32_t ExpressionEvaluator::parseShift() {
    uint32_t result = parseAddition();
    while (true) {
        skipWhitespace();
        if (peek() == '<' && expr[pos + 1] == '<') {
            advance(); advance();
            uint32_t right = parseAddition();
            result = result << right;
        } else if (peek() == '>' && expr[pos + 1] == '>') {
            advance(); advance();
            uint32_t right = parseAddition();
            result = result >> right;
        } else {
            break;
        }
    }
    return result;
}

uint32_t ExpressionEvaluator::parseAddition() {
    uint32_t result = parseMultiplication();
    while (true) {
        skipWhitespace();
        if (peek() == '+') {
            advance();
            uint32_t right = parseMultiplication();
            result = result + right;
        } else if (peek() == '-') {
            advance();
            uint32_t right = parseMultiplication();
            result = result - right;
        } else {
            break;
        }
    }
    return result;
}

uint32_t ExpressionEvaluator::parseMultiplication() {
    uint32_t result = parseUnary();
    while (true) {
        skipWhitespace();
        if (peek() == '*') {
            advance();
            uint32_t right = parseUnary();
            result = result * right;
        } else if (peek() == '/') {
            advance();
            uint32_t right = parseUnary();
            if (right == 0) throw ExpressionError("Division by zero");
            result = result / right;
        } else if (peek() == '%') {
            advance();
            uint32_t right = parseUnary();
            if (right == 0) throw ExpressionError("Division by zero in modulo");
            result = result % right;
        } else {
            break;
        }
    }
    return result;
}

uint32_t ExpressionEvaluator::parseUnary() {
    skipWhitespace();
    if (peek() == '!') {
        advance();
        uint32_t val = parseUnary();
        return val == 0 ? 1 : 0;
    } else if (peek() == '~') {
        advance();
        uint32_t val = parseUnary();
        return ~val;
    } else if (peek() == '-') {
        advance();
        uint32_t val = parseUnary();
        return -(int32_t)val;
    }
    return parsePrimary();
}

uint32_t ExpressionEvaluator::parsePrimary() {
    skipWhitespace();

    // Program counter reference
    if (peek() == '$') {
        advance();
        return currentPC;
    }

    // Parentheses
    if (peek() == '(') {
        advance();
        uint32_t result = parseExpression();
        skipWhitespace();
        if (peek() != ')') {
            throw ExpressionError("Expected ')'");
        }
        advance();
        return result;
    }

    // Number or identifier/function
    if (std::isdigit(peek()) || (peek() == '0' && expr[pos + 1] == 'x') ||
        (peek() == '0' && expr[pos + 1] == 'b') || peek() == 'H' || peek() == 'B' ||
        peek() == 'O') {
        return parseNumber();
    } else if (std::isalpha(peek()) || peek() == '_') {
        return parseIdentifier();
    } else {
        std::string errMsg = std::string("Unexpected character: ") + peek();
        throw ExpressionError(errMsg);
    }
}

uint32_t ExpressionEvaluator::parseNumber() {
    skipWhitespace();

    // MPASM format: H'FF', B'10101010', O'377', D'255'
    if ((peek() == 'H' || peek() == 'h') && expr[pos + 1] == '\'') {
        advance(); advance();  // consume H'
        std::string numStr;
        while (peek() != '\'' && !isAtEnd()) {
            numStr += advance();
        }
        if (peek() != '\'') throw ExpressionError("Unterminated MPASM hex constant");
        advance();
        try {
            return std::stoul(numStr, nullptr, 16);
        } catch (...) {
            throw ExpressionError("Invalid hex constant: " + numStr);
        }
    }

    if ((peek() == 'B' || peek() == 'b') && expr[pos + 1] == '\'') {
        advance(); advance();  // consume B'
        std::string numStr;
        while (peek() != '\'' && !isAtEnd()) {
            numStr += advance();
        }
        if (peek() != '\'') throw ExpressionError("Unterminated MPASM binary constant");
        advance();
        try {
            return std::stoul(numStr, nullptr, 2);
        } catch (...) {
            throw ExpressionError("Invalid binary constant: " + numStr);
        }
    }

    if ((peek() == 'O' || peek() == 'o') && expr[pos + 1] == '\'') {
        advance(); advance();  // consume O'
        std::string numStr;
        while (peek() != '\'' && !isAtEnd()) {
            numStr += advance();
        }
        if (peek() != '\'') throw ExpressionError("Unterminated MPASM octal constant");
        advance();
        try {
            return std::stoul(numStr, nullptr, 8);
        } catch (...) {
            throw ExpressionError("Invalid octal constant: " + numStr);
        }
    }

    if ((peek() == 'D' || peek() == 'd') && expr[pos + 1] == '\'') {
        advance(); advance();  // consume D'
        std::string numStr;
        while (peek() != '\'' && !isAtEnd()) {
            numStr += advance();
        }
        if (peek() != '\'') throw ExpressionError("Unterminated MPASM decimal constant");
        advance();
        try {
            return std::stoul(numStr, nullptr, 10);
        } catch (...) {
            throw ExpressionError("Invalid decimal constant: " + numStr);
        }
    }

    // C-style format: 0xFF, 0b1010, decimal
    if (peek() == '0' && (expr[pos + 1] == 'x' || expr[pos + 1] == 'X')) {
        advance(); advance();  // consume 0x
        std::string numStr;
        while (std::isxdigit(peek())) {
            numStr += advance();
        }
        if (numStr.empty()) throw ExpressionError("Invalid hex constant");
        return std::stoul(numStr, nullptr, 16);
    }

    if (peek() == '0' && (expr[pos + 1] == 'b' || expr[pos + 1] == 'B')) {
        advance(); advance();  // consume 0b
        std::string numStr;
        while (peek() == '0' || peek() == '1') {
            numStr += advance();
        }
        if (numStr.empty()) throw ExpressionError("Invalid binary constant");
        return std::stoul(numStr, nullptr, 2);
    }

    // Decimal number
    std::string numStr;
    while (std::isdigit(peek())) {
        numStr += advance();
    }
    if (numStr.empty()) throw ExpressionError("Expected number");
    try {
        return std::stoul(numStr, nullptr, 10);
    } catch (...) {
        throw ExpressionError("Invalid number: " + numStr);
    }
}

uint32_t ExpressionEvaluator::parseIdentifier() {
    skipWhitespace();
    std::string ident;
    while (std::isalnum(peek()) || peek() == '_') {
        ident += advance();
    }

    skipWhitespace();

    // Check if it's a function call
    if (peek() == '(') {
        return parseFunction(ident);
    }

    // Symbol reference - lookup in symbol table
    if (symbols && symbols->count(ident) > 0) {
        return symbols->at(ident);
    }

    throw ExpressionError("Undefined symbol: " + ident);
}

uint32_t ExpressionEvaluator::parseFunction(const std::string& funcName) {
    advance();  // consume '('

    if (funcName == "HIGH" || funcName == "high") {
        uint32_t val = parseExpression();
        skipWhitespace();
        if (peek() != ')') throw ExpressionError("Expected ')'");
        advance();
        return (val >> 8) & 0xFF;
    }
    else if (funcName == "LOW" || funcName == "low") {
        uint32_t val = parseExpression();
        skipWhitespace();
        if (peek() != ')') throw ExpressionError("Expected ')'");
        advance();
        return val & 0xFF;
    }
    else if (funcName == "UPPER" || funcName == "upper") {
        uint32_t val = parseExpression();
        skipWhitespace();
        if (peek() != ')') throw ExpressionError("Expected ')'");
        advance();
        return (val >> 16) & 0xFF;
    }
    else {
        throw ExpressionError("Unknown function: " + funcName);
    }
}
