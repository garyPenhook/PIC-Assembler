#pragma once

#include "lexer.h"
#include <string>
#include <vector>
#include <map>

struct MacroDefinition {
    std::string name;
    std::vector<std::string> parameters;
    std::vector<Token> body;
    int definitionLine;
    std::vector<std::string> localLabels;
};

class MacroTable {
public:
    void addMacro(const std::string& name, const MacroDefinition& macro);
    bool hasMacro(const std::string& name) const;
    const MacroDefinition& getMacro(const std::string& name) const;

    // Expand macro with argument substitution and LOCAL label generation
    std::vector<Token> expand(const std::string& name,
                             const std::vector<std::string>& args,
                             int callLine,
                             int& localLabelCounter);
private:
    std::map<std::string, MacroDefinition> macros;
};
