#pragma once

#include "lexer.h"
#include "instruction.h"
#include "symbol_table.h"
#include "error_reporter.h"
#include "exceptions.h"
#include "macro_table.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>
#include <cstdint>
#include <map>

// Forward declaration to avoid circular include
struct DataDefinition;
struct ConfigWord;

// Section type enumeration
enum class SectionType {
    CODE,           // Executable code section
    UDATA,          // Uninitialized data (RAM)
    UDATA_ACS,      // Access bank uninitialized data (PIC18 only)
    UDATA_OVR,      // Overlayed uninitialized data (shared address space)
    UDATA_SHR,      // Shared uninitialized data (across banks)
    IDATA,          // Initialized data (stored in ROM, copied to RAM)
    IDATA_ACS,      // Access bank initialized data (PIC18 only)
    NONE            // No section defined yet (initial state)
};

// Section definition structure for named sections
struct SectionDefinition {
    std::string name;           // Section name (e.g., "MY_DATA")
    SectionType type;           // Section type
    uint16_t startAddress;      // Starting address (if specified)
    uint16_t currentAddress;    // Current allocation address
    bool hasExplicitAddress;    // Was address explicitly specified?
    bool isAbsolute;            // Absolute vs relocatable (always absolute for this impl)
};

// Assembly-time conditional block structure (different from preprocessor ConditionalBlock)
struct AssemblyConditionalBlock {
    enum Type {
        IF_TYPE,
        IFDEF_TYPE,
        IFNDEF_TYPE,
        ELSE_TYPE
    };

    Type type;
    std::string condition;        // For IF: expression to evaluate
    std::string symbol;           // For IFDEF/IFNDEF: symbol name
    bool conditionMet;            // Was condition true?
    bool anyBranchTaken;          // Has any branch been taken (for ELSE)?
    bool isActive;                // Should we process lines in this block?
    uint32_t startLine;           // Where block started
};

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

    // Get parsed configuration words
    const std::vector<ConfigWord>& getConfigWords() const { return configWords; }

    // Get symbol table after parsing
    const SymbolTable& getSymbolTable() const { return symbolTable; }

    // Get error reporter
    const ErrorReporter& getErrorReporter() const { return errorReporter; }
    ErrorReporter& getErrorReporter() { return errorReporter; }

    // Device register loading from .inc files
    void loadDeviceRegistersFromFile(const std::string& filePath);

private:
    std::vector<Token> tokens;
    size_t currentPos;
    SymbolTable symbolTable;
    uint16_t programCounter;
    ErrorReporter errorReporter;
    Architecture currentArch;
    std::vector<DataDefinition> dataDefinitions;
    std::vector<ConfigWord> configWords;
    std::vector<ParsedInstruction> generatedInstructions;  // For DT/macros
    int defaultRadix;  // Default number base (DEC=10, HEX=16, OCT=8)

    // CBLOCK state
    bool insideCBLOCK;
    uint16_t cblockAddress;

    // Section state
    SectionType currentSectionType;
    std::string currentSectionName;
    std::map<std::string, SectionDefinition> namedSections;  // Track all named sections
    uint16_t codeProgramCounter;    // PC for CODE sections
    uint16_t dataProgramCounter;    // PC for UDATA/IDATA sections

    // Default section addresses (architecture-dependent)
    static constexpr uint16_t PIC16_DATA_START = 0x20;  // PIC16 general purpose RAM
    static constexpr uint16_t PIC18_DATA_START = 0x000; // PIC18 data memory start
    static constexpr uint16_t PIC18_ACS_START = 0x000;  // PIC18 access bank start

    // MACRO state
    MacroTable macroTable;
    bool insideMacroDefinition;
    MacroDefinition currentMacro;
    std::vector<Token> macroBodyTokens;
    int macroExpansionDepth;
    int localLabelCounter;
    static constexpr int MAX_MACRO_DEPTH = 100;

    // Conditional block state (assembly-time IF/IFDEF/IFNDEF/ELSE/ENDIF)
    std::vector<AssemblyConditionalBlock> conditionalStack;
    int conditionalDepth;

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
    void handleSET(const std::string& label, const std::string& value);
    void handleRADIX(const std::string& radixType);
    void handleBANKSEL(const std::string& label, std::vector<ParsedInstruction>& instructions);
    void handlePAGESEL(const std::string& label, std::vector<ParsedInstruction>& instructions);
    void handleDataDirective(const std::string& directiveName);
    void handleConfigDirective();
    void handleCBLOCK(const std::string& startAddrStr);
    void handleDT();
    void createRETLWInstruction(uint8_t literal);
    void handleMACRO(const std::string& macroName);
    void handleLOCAL();
    std::vector<std::string> parseMacroArguments();
    std::vector<ParsedInstruction> expandMacro(const std::string& macroName, int callLine);

    // Conditional directive handlers
    void handleIF(const std::string& condition);
    void handleIFDEF(const std::string& symbol);
    void handleIFNDEF(const std::string& symbol);
    void handleELSE();
    void handleELIF(const std::string& condition);
    void handleENDIF();
    bool shouldProcessCurrentLine() const;

    // Helper for conditional evaluation
    std::map<std::string, uint32_t> buildSymbolMap() const;

    // Section directive handlers
    void handleCODE(const std::string& nameAndAddress);
    void handleUDATA(const std::string& nameAndAddress, SectionType type);
    void handleIDATA(const std::string& nameAndAddress);
    void handleRES(const std::string& sizeStr);

    // Section helper functions
    uint16_t getDefaultDataAddress(SectionType type) const;
    void validateDataAddress(uint16_t address, SectionType type);
    void validateCodeAddress(uint16_t address);

    // Validation
    void validateOperands(ParsedInstruction& instr);
    bool isValidFileRegister(uint8_t reg) const;
    bool isValidBitPosition(uint8_t bit) const;
};
