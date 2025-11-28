#include "symbol_table.h"
#include <stdexcept>
#include <algorithm>

// Helper function for case-insensitive symbol names
static std::string toUpper(const std::string& str) {
    std::string upper = str;
    std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    return upper;
}

void SymbolTable::addLabel(const std::string& label, uint16_t address) {
    labels[toUpper(label)] = address;
}

void SymbolTable::addConstant(const std::string& name, uint16_t value) {
    constants[toUpper(name)] = value;
}

void SymbolTable::addVariable(const std::string& name, uint16_t value) {
    variables[toUpper(name)] = value;
}

void SymbolTable::addDataSymbol(const std::string& name, uint16_t address,
                                 const std::string& sectionName, SectionType sectionType) {
    SymbolInfo info;
    info.value = address;
    info.type = SymbolType::DATA_SYMBOL;
    info.sectionName = sectionName;
    info.sectionType = sectionType;
    dataSymbols[toUpper(name)] = info;
}

void SymbolTable::addDeviceRegister(const std::string& name, uint16_t address) {
    deviceRegisters[toUpper(name)] = address;
}

uint16_t SymbolTable::getLabel(const std::string& label) const {
    auto it = labels.find(toUpper(label));
    if (it == labels.end()) {
        throw std::runtime_error("Undefined label: " + label);
    }
    return it->second;
}

uint16_t SymbolTable::getConstant(const std::string& name) const {
    auto it = constants.find(toUpper(name));
    if (it == constants.end()) {
        throw std::runtime_error("Undefined constant: " + name);
    }
    return it->second;
}

bool SymbolTable::hasLabel(const std::string& label) const {
    return labels.find(toUpper(label)) != labels.end();
}

bool SymbolTable::hasConstant(const std::string& name) const {
    return constants.find(toUpper(name)) != constants.end();
}

bool SymbolTable::hasVariable(const std::string& name) const {
    return variables.find(toUpper(name)) != variables.end();
}

bool SymbolTable::hasSymbol(const std::string& name) const {
    return hasLabel(name) || hasConstant(name) || hasVariable(name) ||
           isDataSymbol(name) || isDeviceRegister(name);
}

bool SymbolTable::isDataSymbol(const std::string& name) const {
    return dataSymbols.find(toUpper(name)) != dataSymbols.end();
}

bool SymbolTable::isDeviceRegister(const std::string& name) const {
    return deviceRegisters.find(toUpper(name)) != deviceRegisters.end();
}

std::string SymbolTable::getSymbolSection(const std::string& name) const {
    auto it = dataSymbols.find(toUpper(name));
    if (it != dataSymbols.end()) {
        return it->second.sectionName;
    }
    return "";  // Not a data symbol or not found
}

void SymbolTable::clearDeviceRegisters() {
    deviceRegisters.clear();
}

uint16_t SymbolTable::getSymbol(const std::string& name) const {
    // Device registers have highest priority
    if (isDeviceRegister(name)) {
        auto it = deviceRegisters.find(toUpper(name));
        return it->second;
    }
    if (hasLabel(name)) {
        return getLabel(name);
    }
    if (hasConstant(name)) {
        return getConstant(name);
    }
    if (hasVariable(name)) {
        auto it = variables.find(toUpper(name));
        return it->second;
    }
    if (isDataSymbol(name)) {
        auto it = dataSymbols.find(toUpper(name));
        return it->second.value;
    }
    throw std::runtime_error("Undefined symbol: " + name);
}

std::map<std::string, uint32_t> SymbolTable::getAllSymbols() const {
    std::map<std::string, uint32_t> result;

    // Add all device registers (highest priority)
    for (const auto& [name, value] : deviceRegisters) {
        result[name] = value;
    }

    // Add all labels
    for (const auto& [name, value] : labels) {
        result[name] = value;
    }

    // Add all constants
    for (const auto& [name, value] : constants) {
        result[name] = value;
    }

    // Add all variables
    for (const auto& [name, value] : variables) {
        result[name] = value;
    }

    // Add all data symbols
    for (const auto& [name, info] : dataSymbols) {
        result[name] = info.value;
    }

    return result;
}

void SymbolTable::clear() {
    labels.clear();
    constants.clear();
    variables.clear();
    dataSymbols.clear();
    deviceRegisters.clear();
}
