#include "preprocessor.h"
#include "expression.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <filesystem>
#include <cctype>
#include <iostream>

namespace fs = std::filesystem;

// === Constructor ===

Preprocessor::Preprocessor(const std::string& baseDir)
    : baseDirectory(baseDir), includeDepth(0) {
    // Define built-in symbols
    defineSymbol("__PIC_ASSEMBLER__", "1");
    defineSymbol("__GNSASM__", "1");
}

// === Main Entry Point ===

std::string Preprocessor::process(const std::string& source, const std::string& filename) {
    errorReporter.clear();
    defines.clear();
    conditionalStack.clear();
    includedFiles.clear();
    lineMapping.clear();
    includeDepth = 0;

    // Re-define built-in symbols
    defineSymbol("__PIC_ASSEMBLER__", "1");
    defineSymbol("__GNSASM__", "1");

    try {
        // Split source into lines
        std::vector<std::string> lines;
        std::istringstream iss(source);
        std::string line;
        while (std::getline(iss, line)) {
            lines.push_back(line);
        }

        // Get directory from filename
        std::string currentDir = getDirectory(filename);
        if (currentDir.empty()) {
            currentDir = baseDirectory;
        }

        // Process the lines
        return processLines(lines, filename, currentDir);
    } catch (const std::exception& e) {
        errorReporter.reportError(1, 1, "Preprocessor error: " + std::string(e.what()));
        return "";
    }
}

// === File Processing ===

std::string Preprocessor::processFile(const std::string& filename, int depth, const std::string& currentDir) {
    // Check include depth
    if (depth > MAX_INCLUDE_DEPTH) {
        errorReporter.reportError(1, 1, "Include depth exceeded (possible circular include)");
        return "";
    }

    // Check for circular includes
    std::string resolvedPath = fs::absolute(filename).string();
    if (includedFiles.count(resolvedPath) > 0) {
        // Already included, skip silently (prevent circular includes)
        return "";
    }
    includedFiles.insert(resolvedPath);

    // If this is a source string (not a file), process it directly
    if (filename == "<input>" || filename.empty()) {
        std::vector<std::string> lines;
        std::istringstream iss(filename == "<input>" ? "" : filename);
        std::string line;
        // This case handles when we're processing source directly
        // The actual source comes through differently
        return "";
    }

    // Try to read the file
    std::ifstream file(filename);
    if (!file.is_open()) {
        // This might be inline source code passed through process()
        // In that case, we process it as lines directly
        return filename;  // Return as-is if can't open
    }

    // Read all lines from file
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    return processLines(lines, filename, currentDir);
}

std::string Preprocessor::processLines(const std::vector<std::string>& lines,
                                       const std::string& filename,
                                       const std::string& currentDir) {
    std::ostringstream output;
    uint32_t processedLineNum = 1;

    for (size_t i = 0; i < lines.size(); ++i) {
        size_t lineNum = i + 1;
        const std::string& line = lines[i];

        // Process the line
        std::string processedLine = processLine(line, lineNum, filename);

        // If the line should be included in output
        if (shouldProcessLine()) {
            if (!processedLine.empty()) {
                output << processedLine << "\n";
                lineMapping.push_back({processedLineNum, static_cast<uint32_t>(lineNum), filename});
                processedLineNum++;
            }
        }
    }

    return output.str();
}

std::string Preprocessor::processLine(const std::string& line, size_t lineNum,
                                     const std::string& filename) {
    std::string trimmedLine = trim(line);

    // Check if this is a preprocessor directive
    if (isPreprocessorDirective(trimmedLine)) {
        auto [directive, args] = parseDirectiveLine(trimmedLine);

        // Handle directives
        if (directive == "DEFINE") {
            handleDefine(args, lineNum, filename);
            return "";  // Directives don't appear in output
        } else if (directive == "UNDEF") {
            handleUndef(args, lineNum);
            return "";
        } else if (directive == "IFDEF") {
            handleIfdef(args, lineNum);
            return "";
        } else if (directive == "IFNDEF") {
            handleIfndef(args, lineNum);
            return "";
        } else if (directive == "IF") {
            handleIf(args, lineNum);
            return "";
        } else if (directive == "ELIF") {
            handleElif(args, lineNum);
            return "";
        } else if (directive == "ELSE") {
            handleElse(lineNum);
            return "";
        } else if (directive == "ENDIF") {
            handleEndif(lineNum);
            return "";
        } else if (directive == "INCLUDE") {
            handleInclude(args, lineNum, filename, getDirectory(filename));
            return "";
        } else if (directive == "ERROR") {
            handleError(args, lineNum);
            return "";
        } else if (directive == "WARNING") {
            handleWarning(args, lineNum);
            return "";
        } else if (directive == "LINE") {
            handleLine(args, lineNum);
            return "";
        }
    }

    // Not a directive - expand macros in the line
    if (shouldProcessLine()) {
        return expandMacros(line, lineNum);
    }

    return "";  // Skip line if not in active conditional block
}

// === Directive Handlers ===

bool Preprocessor::isPreprocessorDirective(const std::string& line) const {
    if (line.empty() || line[0] != '#') {
        return false;
    }
    return true;
}

std::pair<std::string, std::string> Preprocessor::parseDirectiveLine(const std::string& line) const {
    // Line should start with #
    if (line.empty() || line[0] != '#') {
        return {"", ""};
    }

    // Skip the # and any whitespace
    size_t pos = 1;
    while (pos < line.length() && isWhitespace(line[pos])) {
        pos++;
    }

    // Extract directive name
    size_t end = pos;
    while (end < line.length() && (std::isalnum(line[end]) || line[end] == '_')) {
        end++;
    }

    std::string directive = line.substr(pos, end - pos);
    std::string args = "";

    // Get arguments (everything after the directive)
    if (end < line.length()) {
        args = trim(line.substr(end));
    }

    // Uppercase the directive
    std::transform(directive.begin(), directive.end(), directive.begin(), ::toupper);

    return {directive, args};
}

void Preprocessor::handleDefine(const std::string& args, size_t lineNum, const std::string& filename) {
    if (args.empty()) {
        errorReporter.reportError(lineNum, 1, "#define requires a name");
        return;
    }

    // Parse: #define NAME [value] or #define NAME(params) replacement
    std::istringstream iss(args);
    std::string name;
    iss >> name;

    if (name.empty()) {
        errorReporter.reportError(lineNum, 1, "#define requires a name");
        return;
    }

    // Check if function-like macro: NAME(params)
    size_t parenPos = name.find('(');
    PreprocessorDefine define;
    define.name = name;
    define.definitionLine = lineNum;
    define.definitionFile = filename;
    define.isFunctionLike = false;
    define.isVariadic = false;

    if (parenPos != std::string::npos) {
        // Function-like macro: #define NAME(params) replacement
        define.name = name.substr(0, parenPos);
        define.isFunctionLike = true;

        // Extract parameter list
        size_t closeParenPos = name.find(')', parenPos);
        if (closeParenPos == std::string::npos) {
            errorReporter.reportError(lineNum, 1, "Missing closing parenthesis in macro definition");
            return;
        }

        std::string paramStr = name.substr(parenPos + 1, closeParenPos - parenPos - 1);

        // Parse parameters
        std::istringstream paramIss(paramStr);
        std::string param;
        while (std::getline(paramIss, param, ',')) {
            param = trim(param);
            if (!param.empty()) {
                if (param == "...") {
                    define.isVariadic = true;
                } else {
                    define.parameters.push_back(param);
                }
            }
        }

        // Get replacement text (skip past the macro definition)
        size_t replacementStart = args.find(')', parenPos);
        if (replacementStart != std::string::npos && replacementStart + 1 < args.length()) {
            define.replacement = trim(args.substr(replacementStart + 1));
        }
    } else {
        // Simple macro: #define NAME value
        define.replacement = args.substr(name.length());
        define.replacement = trim(define.replacement);
    }

    // Store the define
    defines[toUpper(define.name)] = define;
}

void Preprocessor::handleUndef(const std::string& args, size_t lineNum) {
    if (args.empty()) {
        errorReporter.reportError(lineNum, 1, "#undef requires a symbol name");
        return;
    }

    std::string name = trim(args);
    auto it = defines.find(toUpper(name));
    if (it != defines.end()) {
        defines.erase(it);
    }
}

void Preprocessor::handleIfdef(const std::string& args, size_t lineNum) {
    // Phase 2 - stub for now
    if (args.empty()) {
        errorReporter.reportError(lineNum, 1, "#ifdef requires a symbol name");
        return;
    }

    ConditionalBlock block;
    block.type = ConditionalBlock::IFDEF_TYPE;
    block.symbol = trim(args);
    block.conditionMet = isDefined(block.symbol);
    block.anyBranchTaken = block.conditionMet;
    block.isActive = block.conditionMet;
    block.startLine = lineNum;
    block.startFile = "";

    conditionalStack.push_back(block);
}

void Preprocessor::handleIfndef(const std::string& args, size_t lineNum) {
    // Phase 2 - stub for now
    if (args.empty()) {
        errorReporter.reportError(lineNum, 1, "#ifndef requires a symbol name");
        return;
    }

    ConditionalBlock block;
    block.type = ConditionalBlock::IFNDEF_TYPE;
    block.symbol = trim(args);
    block.conditionMet = !isDefined(block.symbol);
    block.anyBranchTaken = block.conditionMet;
    block.isActive = block.conditionMet;
    block.startLine = lineNum;
    block.startFile = "";

    conditionalStack.push_back(block);
}

void Preprocessor::handleIf(const std::string& args, size_t lineNum) {
    // Phase 3 - Evaluate #if expression
    if (args.empty()) {
        errorReporter.reportError(lineNum, 1, "#if requires an expression");
        return;
    }

    // Create a symbol table for the expression evaluator
    // Map preprocessor defines to a numeric value (1 if defined, 0 if not)
    std::map<std::string, uint32_t> symbols;
    for (const auto& [name, define] : defines) {
        // Try to parse the replacement text as a number
        try {
            ExpressionEvaluator eval;
            uint32_t value = eval.evaluate(define.replacement);
            symbols[name] = value;
        } catch (...) {
            // If not a number, treat as true (1) if defined
            symbols[name] = 1;
        }
    }

    // Evaluate the #if expression
    bool conditionMet = false;
    try {
        ExpressionEvaluator evaluator(&symbols);
        uint32_t result = evaluator.evaluate(args);
        conditionMet = (result != 0);
    } catch (const std::exception& e) {
        errorReporter.reportError(lineNum, 1, "#if expression error: " + std::string(e.what()));
        conditionMet = false;
    }

    ConditionalBlock block;
    block.type = ConditionalBlock::IF_TYPE;
    block.condition = args;
    block.conditionMet = conditionMet;
    block.anyBranchTaken = conditionMet;
    block.isActive = conditionMet;
    block.startLine = lineNum;
    block.startFile = "";

    conditionalStack.push_back(block);
}

void Preprocessor::handleElif(const std::string& args, size_t lineNum) {
    // Phase 3 - Evaluate #elif expression
    if (conditionalStack.empty()) {
        errorReporter.reportError(lineNum, 1, "#elif without matching #if");
        return;
    }

    auto& topBlock = conditionalStack.back();

    // #elif can only follow #if, not #ifdef/#ifndef
    if (topBlock.type != ConditionalBlock::IF_TYPE &&
        topBlock.type != ConditionalBlock::ELIF_TYPE) {
        errorReporter.reportError(lineNum, 1, "#elif can only follow #if");
        return;
    }

    // If a branch has already been taken, deactivate this block
    if (topBlock.anyBranchTaken) {
        topBlock.isActive = false;
        return;
    }

    // Evaluate the elif condition
    bool conditionMet = false;
    try {
        // Create symbol table for expression evaluation
        std::map<std::string, uint32_t> symbols;
        for (const auto& [name, define] : defines) {
            try {
                ExpressionEvaluator eval;
                uint32_t value = eval.evaluate(define.replacement);
                symbols[name] = value;
            } catch (...) {
                symbols[name] = 1;
            }
        }

        ExpressionEvaluator evaluator(&symbols);
        uint32_t result = evaluator.evaluate(args);
        conditionMet = (result != 0);
    } catch (const std::exception& e) {
        errorReporter.reportError(lineNum, 1, "#elif expression error: " + std::string(e.what()));
        conditionMet = false;
    }

    // Update block type and state
    topBlock.type = ConditionalBlock::ELIF_TYPE;
    topBlock.condition = args;
    topBlock.conditionMet = conditionMet;
    topBlock.isActive = conditionMet;
    if (conditionMet) {
        topBlock.anyBranchTaken = true;
    }
}

void Preprocessor::handleElse(size_t lineNum) {
    // Phase 2 - handle else
    if (conditionalStack.empty()) {
        errorReporter.reportError(lineNum, 1, "#else without matching #if");
        return;
    }

    auto& topBlock = conditionalStack.back();
    if (!topBlock.anyBranchTaken) {
        topBlock.isActive = true;
        topBlock.anyBranchTaken = true;
    } else {
        topBlock.isActive = false;
    }
}

void Preprocessor::handleEndif(size_t lineNum) {
    // Phase 2 - handle endif
    if (conditionalStack.empty()) {
        errorReporter.reportError(lineNum, 1, "#endif without matching #if");
        return;
    }

    conditionalStack.pop_back();
}

void Preprocessor::handleInclude(const std::string& args, size_t lineNum,
                                const std::string& currentFile, const std::string& currentDir) {
    // Phase 4 - stub for now
    if (args.empty()) {
        errorReporter.reportError(lineNum, 1, "#include requires a filename");
        return;
    }

    errorReporter.reportWarning(lineNum, 1, "#include not yet implemented");
}

void Preprocessor::handleError(const std::string& args, size_t lineNum) {
    // Phase 5 - stub for now
    if (!args.empty()) {
        errorReporter.reportError(lineNum, 1, "#error: " + args);
    } else {
        errorReporter.reportError(lineNum, 1, "#error directive encountered");
    }
}

void Preprocessor::handleWarning(const std::string& args, size_t lineNum) {
    // Phase 5 - stub for now
    if (!args.empty()) {
        errorReporter.reportWarning(lineNum, 1, "#warning: " + args);
    } else {
        errorReporter.reportWarning(lineNum, 1, "#warning directive encountered");
    }
}

void Preprocessor::handleLine(const std::string& args, size_t lineNum) {
    // Phase 5 - stub for now
    errorReporter.reportWarning(lineNum, 1, "#line not yet implemented");
}

// === Macro Expansion ===

bool Preprocessor::isDefined(const std::string& name) const {
    return defines.find(toUpper(name)) != defines.end();
}

std::string Preprocessor::expandMacros(const std::string& text, size_t lineNum) {
    std::string result = text;

    // Repeatedly expand macros until no more expansions occur
    bool expanded = true;
    int iterations = 0;
    const int MAX_ITERATIONS = 100;  // Prevent infinite loops

    while (expanded && iterations < MAX_ITERATIONS) {
        expanded = false;
        iterations++;
        std::string newResult = result;

        // Find potential macro invocations
        size_t pos = 0;
        while (pos < newResult.length()) {
            // Look for identifiers that might be macros
            if (std::isalpha(newResult[pos]) || newResult[pos] == '_') {
                size_t start = pos;
                while (pos < newResult.length() && (std::isalnum(newResult[pos]) || newResult[pos] == '_')) {
                    pos++;
                }

                std::string potential = newResult.substr(start, pos - start);
                std::string potentialUpper = toUpper(potential);

                // Check if this is a defined macro
                if (defines.find(potentialUpper) != defines.end()) {
                    const auto& define = defines.at(potentialUpper);

                    // Check if it's a function-like macro that needs arguments
                    std::vector<std::string> arguments;
                    size_t expandEnd = pos;

                    if (define.isFunctionLike) {
                        // Look for opening paren
                        if (pos < newResult.length() && newResult[pos] == '(') {
                            pos++;  // Skip the (

                            // Parse arguments
                            int parenDepth = 1;
                            size_t argStart = pos;
                            while (pos < newResult.length() && parenDepth > 0) {
                                if (newResult[pos] == '(') parenDepth++;
                                else if (newResult[pos] == ')') parenDepth--;

                                if (parenDepth > 0 && newResult[pos] == ',') {
                                    arguments.push_back(trim(newResult.substr(argStart, pos - argStart)));
                                    argStart = pos + 1;
                                }

                                pos++;
                            }

                            if (parenDepth == 0 && argStart < pos - 1) {
                                arguments.push_back(trim(newResult.substr(argStart, pos - argStart - 1)));
                            }

                            expandEnd = pos;
                        } else {
                            // Not a function call - don't expand
                            continue;
                        }
                    }

                    // Expand the macro
                    std::string expansion = expandMacro(potential, arguments, lineNum);
                    newResult = newResult.substr(0, start) + expansion + newResult.substr(expandEnd);
                    pos = start + expansion.length();
                    expanded = true;
                }
            } else {
                pos++;
            }
        }

        result = newResult;
    }

    if (iterations >= MAX_ITERATIONS) {
        errorReporter.reportWarning(lineNum, 1, "Macro expansion limit exceeded (possible recursive macro)");
    }

    return result;
}

std::string Preprocessor::expandMacro(const std::string& macroName,
                                     const std::vector<std::string>& arguments,
                                     size_t lineNum) {
    auto it = defines.find(toUpper(macroName));
    if (it == defines.end()) {
        return macroName;  // Not defined - return as-is
    }

    const auto& define = it->second;

    // Validate argument count for function-like macros
    if (define.isFunctionLike) {
        int expectedArgs = define.parameters.size();
        int actualArgs = arguments.size();

        if (!define.isVariadic && actualArgs != expectedArgs) {
            errorReporter.reportError(lineNum, 1,
                "Macro '" + macroName + "' expects " + std::to_string(expectedArgs) +
                " arguments, got " + std::to_string(actualArgs));
            return macroName;
        }
    }

    // For simple macros, return the replacement
    if (!define.isFunctionLike) {
        return define.replacement;
    }

    // For function-like macros, substitute parameters
    return substituteParameters(define.replacement, define.parameters, arguments);
}

std::string Preprocessor::substituteParameters(const std::string& text,
                                              const std::vector<std::string>& parameters,
                                              const std::vector<std::string>& arguments) {
    std::string result = text;

    for (size_t i = 0; i < parameters.size() && i < arguments.size(); ++i) {
        const std::string& param = parameters[i];
        const std::string& arg = arguments[i];

        // Simple text replacement of parameter names
        size_t pos = 0;
        while ((pos = result.find(param, pos)) != std::string::npos) {
            // Check if this is a whole word (not part of a larger identifier)
            bool validStart = (pos == 0) || !std::isalnum(result[pos - 1]);
            bool validEnd = (pos + param.length() >= result.length()) || !std::isalnum(result[pos + param.length()]);

            if (validStart && validEnd) {
                result.replace(pos, param.length(), arg);
                pos += arg.length();
            } else {
                pos += param.length();
            }
        }
    }

    return result;
}

// === Utility Methods ===

bool Preprocessor::shouldProcessLine() const {
    // If conditional stack is empty, process all lines
    if (conditionalStack.empty()) {
        return true;
    }

    // Check the top of the conditional stack
    return conditionalStack.back().isActive;
}

std::string Preprocessor::getDirectory(const std::string& filepath) const {
    size_t lastSlash = filepath.find_last_of("/\\");
    if (lastSlash != std::string::npos) {
        return filepath.substr(0, lastSlash);
    }
    return "";
}

std::string Preprocessor::resolveIncludePath(const std::string& includeFile,
                                            const std::string& currentDir,
                                            bool isSystemInclude) const {
    // Phase 4 - stub
    return includeFile;
}

std::vector<std::string> Preprocessor::splitLine(const std::string& line, char delimiter) const {
    std::vector<std::string> result;
    std::string current;
    bool inQuotes = false;

    for (char c : line) {
        if (c == '"') {
            inQuotes = !inQuotes;
            current += c;
        } else if (c == delimiter && !inQuotes) {
            if (!current.empty()) {
                result.push_back(current);
                current.clear();
            }
        } else {
            current += c;
        }
    }

    if (!current.empty()) {
        result.push_back(current);
    }

    return result;
}

std::string Preprocessor::trim(const std::string& str) const {
    size_t first = 0;
    while (first < str.length() && isWhitespace(str[first])) {
        first++;
    }

    if (first == str.length()) {
        return "";
    }

    size_t last = str.length() - 1;
    while (last > first && isWhitespace(str[last])) {
        last--;
    }

    return str.substr(first, last - first + 1);
}

std::string Preprocessor::toUpper(const std::string& str) const {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// === Symbol Management ===

void Preprocessor::defineSymbol(const std::string& name, const std::string& value) {
    PreprocessorDefine define;
    define.name = name;
    define.replacement = value;
    define.isFunctionLike = false;
    define.isVariadic = false;
    define.definitionLine = 0;
    define.definitionFile = "<builtin>";

    defines[toUpper(name)] = define;
}

void Preprocessor::undefineSymbol(const std::string& name) {
    auto it = defines.find(toUpper(name));
    if (it != defines.end()) {
        defines.erase(it);
    }
}

bool Preprocessor::isSymbolDefined(const std::string& name) const {
    return defines.find(toUpper(name)) != defines.end();
}

std::string Preprocessor::getSymbolValue(const std::string& name) const {
    auto it = defines.find(toUpper(name));
    if (it != defines.end()) {
        return it->second.replacement;
    }
    return "";
}
