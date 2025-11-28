#pragma once

#include <string>
#include <map>
#include <cstdint>

// Forward declaration for SectionType (defined in parser.h)
enum class SectionType;

// Symbol type enumeration
enum class SymbolType {
    LABEL,          // Code label
    CONSTANT,       // EQU constant
    VARIABLE,       // SET variable
    DATA_SYMBOL,    // Variable in UDATA/IDATA section
    DEVICE_REGISTER // Built-in device register from .inc file
};

// Symbol information structure with section tracking
struct SymbolInfo {
    uint16_t value;
    SymbolType type;
    std::string sectionName;  // Which section this symbol belongs to
    SectionType sectionType;  // Type of section
};

class SymbolTable {
public:
    // Add a label with its address
    void addLabel(const std::string& label, uint16_t address);

    // Add a constant definition (EQU - cannot be changed)
    void addConstant(const std::string& name, uint16_t value);

    // Add a variable definition (SET - can be reassigned)
    void addVariable(const std::string& name, uint16_t value);

    // Add a data symbol (in UDATA/IDATA section) with section information
    void addDataSymbol(const std::string& name, uint16_t address,
                       const std::string& sectionName, SectionType sectionType);

    // Get address of a label
    uint16_t getLabel(const std::string& label) const;

    // Get value of a constant
    uint16_t getConstant(const std::string& name) const;

    // Check if label exists
    bool hasLabel(const std::string& label) const;

    // Check if constant exists
    bool hasConstant(const std::string& name) const;

    // Check if variable exists
    bool hasVariable(const std::string& name) const;

    // Check if symbol exists (label, constant, or variable)
    bool hasSymbol(const std::string& name) const;

    // Check if symbol is a data symbol (in UDATA/IDATA)
    bool isDataSymbol(const std::string& name) const;

    // Get the section a symbol belongs to
    std::string getSymbolSection(const std::string& name) const;

    // Add a device register from .inc files
    void addDeviceRegister(const std::string& name, uint16_t address);

    // Check if a symbol is a device register
    bool isDeviceRegister(const std::string& name) const;

    // Clear all device registers (for switching devices)
    void clearDeviceRegisters();

    // Get symbol value (works for labels, constants, variables, and device registers)
    uint16_t getSymbol(const std::string& name) const;

    // Get all symbols as a map (for expression evaluation)
    std::map<std::string, uint32_t> getAllSymbols() const;

    // Clear all symbols
    void clear();

private:
    std::map<std::string, uint16_t> labels;
    std::map<std::string, uint16_t> constants;
    std::map<std::string, uint16_t> variables;
    std::map<std::string, SymbolInfo> dataSymbols;      // Section-aware symbols
    std::map<std::string, uint16_t> deviceRegisters;   // Built-in device registers
};
