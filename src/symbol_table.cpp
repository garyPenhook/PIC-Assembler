#include "symbol_table.h"
#include <stdexcept>

void SymbolTable::addLabel(const std::string& label, uint16_t address) {
    labels[label] = address;
}

void SymbolTable::addConstant(const std::string& name, uint16_t value) {
    constants[name] = value;
}

void SymbolTable::addVariable(const std::string& name, uint16_t value) {
    variables[name] = value;
}

uint16_t SymbolTable::getLabel(const std::string& label) const {
    auto it = labels.find(label);
    if (it == labels.end()) {
        throw std::runtime_error("Undefined label: " + label);
    }
    return it->second;
}

uint16_t SymbolTable::getConstant(const std::string& name) const {
    auto it = constants.find(name);
    if (it == constants.end()) {
        throw std::runtime_error("Undefined constant: " + name);
    }
    return it->second;
}

bool SymbolTable::hasLabel(const std::string& label) const {
    return labels.find(label) != labels.end();
}

bool SymbolTable::hasConstant(const std::string& name) const {
    return constants.find(name) != constants.end();
}

bool SymbolTable::hasVariable(const std::string& name) const {
    return variables.find(name) != variables.end();
}

bool SymbolTable::hasSymbol(const std::string& name) const {
    return hasLabel(name) || hasConstant(name) || hasVariable(name);
}

uint16_t SymbolTable::getSymbol(const std::string& name) const {
    if (hasLabel(name)) {
        return getLabel(name);
    }
    if (hasConstant(name)) {
        return getConstant(name);
    }
    if (hasVariable(name)) {
        auto it = variables.find(name);
        return it->second;
    }
    throw std::runtime_error("Undefined symbol: " + name);
}

void SymbolTable::clear() {
    labels.clear();
    constants.clear();
    variables.clear();
}
