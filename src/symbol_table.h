#pragma once

#include <string>
#include <map>
#include <cstdint>

class SymbolTable {
public:
    // Add a label with its address
    void addLabel(const std::string& label, uint16_t address);

    // Add a constant definition (EQU)
    void addConstant(const std::string& name, uint16_t value);

    // Get address of a label
    uint16_t getLabel(const std::string& label) const;

    // Get value of a constant
    uint16_t getConstant(const std::string& name) const;

    // Check if label exists
    bool hasLabel(const std::string& label) const;

    // Check if constant exists
    bool hasConstant(const std::string& name) const;

    // Check if symbol exists (label or constant)
    bool hasSymbol(const std::string& name) const;

    // Get symbol value (works for both labels and constants)
    uint16_t getSymbol(const std::string& name) const;

    // Clear all symbols
    void clear();

private:
    std::map<std::string, uint16_t> labels;
    std::map<std::string, uint16_t> constants;
};
