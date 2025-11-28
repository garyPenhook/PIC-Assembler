#include "macro_table.h"
#include <algorithm>
#include <sstream>
#include <stdexcept>

void MacroTable::addMacro(const std::string& name, const MacroDefinition& macro) {
    std::string upperName = name;
    std::transform(upperName.begin(), upperName.end(), upperName.begin(), ::toupper);
    macros[upperName] = macro;
}

bool MacroTable::hasMacro(const std::string& name) const {
    std::string upperName = name;
    std::transform(upperName.begin(), upperName.end(), upperName.begin(), ::toupper);
    return macros.find(upperName) != macros.end();
}

const MacroDefinition& MacroTable::getMacro(const std::string& name) const {
    std::string upperName = name;
    std::transform(upperName.begin(), upperName.end(), upperName.begin(), ::toupper);
    return macros.at(upperName);
}

std::vector<Token> MacroTable::expand(const std::string& name,
                                     const std::vector<std::string>& args,
                                     int callLine,
                                     int& localLabelCounter) {
    const MacroDefinition& macro = getMacro(name);

    if (args.size() != macro.parameters.size()) {
        throw std::runtime_error("Macro " + name + " expects " +
                        std::to_string(macro.parameters.size()) + " arguments, got " +
                        std::to_string(args.size()));
    }

    // Build parameter substitution map
    std::map<std::string, std::string> substitutions;
    for (size_t i = 0; i < args.size(); i++) {
        std::string paramUpper = macro.parameters[i];
        std::transform(paramUpper.begin(), paramUpper.end(), paramUpper.begin(), ::toupper);
        substitutions[paramUpper] = args[i];
    }

    // Build LOCAL label substitution map
    std::map<std::string, std::string> localLabelMap;
    for (const auto& localLabel : macro.localLabels) {
        std::string uniqueLabel = "??L" + std::to_string(localLabelCounter++);
        localLabelMap[localLabel] = uniqueLabel;
    }

    // Substitute parameters and LOCAL labels in body
    std::vector<Token> expanded;

    for (const Token& token : macro.body) {
        // Handle EXITM
        if (token.type == TokenType::DIRECTIVE) {
            std::string dirName = token.value;
            std::transform(dirName.begin(), dirName.end(), dirName.begin(), ::toupper);
            if (dirName == "EXITM") {
                break;  // Stop macro expansion
            }
        }

        Token newToken = token;
        newToken.line = callLine;  // Preserve call context for errors

        // Substitute parameters
        if (token.type == TokenType::IDENTIFIER) {
            std::string upperValue = token.value;
            std::transform(upperValue.begin(), upperValue.end(),
                          upperValue.begin(), ::toupper);

            // Check parameter substitution
            auto paramIt = substitutions.find(upperValue);
            if (paramIt != substitutions.end()) {
                newToken.value = paramIt->second;
            }

            // Check LOCAL label substitution
            auto localIt = localLabelMap.find(upperValue);
            if (localIt != localLabelMap.end()) {
                newToken.value = localIt->second;
            }
        }

        expanded.push_back(newToken);
    }

    return expanded;
}
