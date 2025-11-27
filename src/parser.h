#pragma once

#include "lexer.h"
#include "instruction.h"
#include "symbol_table.h"
#include "error_reporter.h"
#include "exceptions.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>
#include <cstdint>

// Forward declaration to avoid circular include
struct DataDefinition;

struct ParsedInstruction {
    InstructionType type;
    std::string mnemonic;
    uint8_t f_reg;       // File register (0-255)
    uint8_t d_bit;       // Destination bit (0-1)
    uint8_t b_bit;       // Bit position (0-7)
    uint16_t k_value;    // Literal value
    std::string label;   // Label if present
    uint16_t address;    // Memory address
    int line_number;
    bool valid;
};

class ParseError : public std::runtime_error {
public:
    ParseError(int line, const std::string& message)
        : std::runtime_error("Line " + std::to_string(line) + ": " + message),
          line(line), message(message) {}
    int getLine() const { return line; }
    std::string getMessage() const { return message; }
private:
    int line;
    std::string message;
};

class Parser {
public:
    Parser(const std::vector<Token>& tokens, Architecture arch = Architecture::PIC16);

    // Parse all tokens and return list of instructions (two-pass: labels first, then code)
    std::vector<ParsedInstruction> parse();

    // First pass: collect all labels and populate symbol table
    void firstPass();

    // Get parsed data definitions
    const std::vector<DataDefinition>& getDataDefinitions() const { return dataDefinitions; }

    // Get symbol table after parsing
    const SymbolTable& getSymbolTable() const { return symbolTable; }

    // Get error reporter
    const ErrorReporter& getErrorReporter() const { return errorReporter; }
    ErrorReporter& getErrorReporter() { return errorReporter; }

private:
    std::vector<Token> tokens;
    size_t currentPos;
    SymbolTable symbolTable;
    uint16_t programCounter;
    ErrorReporter errorReporter;
    Architecture currentArch;
    std::vector<DataDefinition> dataDefinitions;

    // Helper functions
    Token& current();
    const Token& current() const;
    Token& peek(size_t offset = 1);
    const Token& peek(size_t offset = 1) const;
    void advance();
    bool match(TokenType type);
    bool check(TokenType type) const;
    Token& consume(TokenType type, const std::string& message);

    // Parsing functions
    ParsedInstruction parseInstruction(const Token& mnemonic);
    void parseOperands(ParsedInstruction& instr, const std::string& operandStr);
    uint16_t parseNumber(const std::string& str);
    void parseDirective(const Token& directive);
    void handleORG(const std::string& arg);
    void handleEQU(const std::string& label, const std::string& value);
    void handleBANKSEL(const std::string& label, std::vector<ParsedInstruction>& instructions);
    void handlePAGESEL(const std::string& label, std::vector<ParsedInstruction>& instructions);
    void handleDataDirective(const std::string& directiveName);

    // Validation
    void validateOperands(ParsedInstruction& instr);
    bool isValidFileRegister(uint8_t reg) const;
    bool isValidBitPosition(uint8_t bit) const;
};
