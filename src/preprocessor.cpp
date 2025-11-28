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

        // Check if this is an #include directive
        std::string trimmedLine = trim(line);
        if (!trimmedLine.empty() && trimmedLine[0] == '#') {
            auto [directive, args] = parseDirectiveLine(trimmedLine);
            if (directive == "INCLUDE") {
                // Handle include by recursively processing the file
                std::string includeFile = trim(args);
                bool isSystemInclude = false;

                if (includeFile.length() >= 2) {
                    if (includeFile[0] == '<' && includeFile[includeFile.length() - 1] == '>') {
                        isSystemInclude = true;
                        includeFile = includeFile.substr(1, includeFile.length() - 2);
                    } else if (includeFile[0] == '"' && includeFile[includeFile.length() - 1] == '"') {
                        isSystemInclude = false;
                        includeFile = includeFile.substr(1, includeFile.length() - 2);
                    }
                }

                if (!includeFile.empty()) {
                    std::string resolvedPath = resolveIncludePath(includeFile, currentDir, isSystemInclude);
                    if (!resolvedPath.empty()) {
                        std::string absolutePath = fs::absolute(resolvedPath).string();
                        if (includedFiles.find(absolutePath) == includedFiles.end()) {
                            includedFiles.insert(absolutePath);

                            // Read the included file
                            std::ifstream file(resolvedPath);
                            if (file.is_open()) {
                                std::vector<std::string> includedLines;
                                std::string includeLine;
                                while (std::getline(file, includeLine)) {
                                    includedLines.push_back(includeLine);
                                }
                                file.close();

                                // Check if this is a device include file (.inc)
                                // Device registers are loaded separately by the assembler
                                if (includeFile.length() >= 4 &&
                                    includeFile.substr(includeFile.length() - 4) == ".inc") {
                                    // Skip .inc file inclusion in preprocessor output
                                    // The assembler will load device registers directly from the file
                                    continue;
                                }

                                // Recursively process the included file
                                includeDepth++;
                                std::string includedContent = processLines(includedLines, resolvedPath,
                                                                          getDirectory(resolvedPath));
                                includeDepth--;

                                output << includedContent;
                                // Don't add to processed line count - already handled by recursive call
                                continue;
                            }
                        }
                    }
                }
                // If include failed, just skip the line
                continue;
            }
        }

        // Process the line normally
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

    std::string trimmedArgs = trim(args);

    // Find the macro name - everything before the first space or (
    size_t nameEnd = 0;
    while (nameEnd < trimmedArgs.length() &&
           trimmedArgs[nameEnd] != ' ' &&
           trimmedArgs[nameEnd] != '\t' &&
           trimmedArgs[nameEnd] != '(') {
        nameEnd++;
    }

    if (nameEnd == 0) {
        errorReporter.reportError(lineNum, 1, "#define requires a name");
        return;
    }

    std::string macroName = trimmedArgs.substr(0, nameEnd);
    PreprocessorDefine define;
    define.name = macroName;
    define.definitionLine = lineNum;
    define.definitionFile = filename;
    define.isFunctionLike = false;
    define.isVariadic = false;

    // Check if function-like macro: NAME(params)
    if (nameEnd < trimmedArgs.length() && trimmedArgs[nameEnd] == '(') {
        // Function-like macro: #define NAME(params) replacement
        define.isFunctionLike = true;

        // Find closing paren
        size_t closeParenPos = trimmedArgs.find(')', nameEnd + 1);
        if (closeParenPos == std::string::npos) {
            errorReporter.reportError(lineNum, 1, "Missing closing parenthesis in macro definition");
            return;
        }

        // Extract parameter list (between parentheses)
        std::string paramStr = trimmedArgs.substr(nameEnd + 1, closeParenPos - nameEnd - 1);

        // Parse parameters (comma-separated)
        size_t pos = 0;
        while (pos < paramStr.length()) {
            // Skip whitespace
            while (pos < paramStr.length() && isWhitespace(paramStr[pos])) {
                pos++;
            }

            // Extract parameter name
            size_t paramStart = pos;
            while (pos < paramStr.length() && (std::isalnum(paramStr[pos]) || paramStr[pos] == '_' || paramStr[pos] == '.')) {
                pos++;
            }

            if (pos > paramStart) {
                std::string param = paramStr.substr(paramStart, pos - paramStart);
                if (param == "...") {
                    define.isVariadic = true;
                } else if (!param.empty()) {
                    define.parameters.push_back(param);
                }
            }

            // Skip whitespace and comma
            while (pos < paramStr.length() && (isWhitespace(paramStr[pos]) || paramStr[pos] == ',')) {
                pos++;
            }
        }

        // Get replacement text (everything after the closing paren)
        if (closeParenPos + 1 < trimmedArgs.length()) {
            define.replacement = trim(trimmedArgs.substr(closeParenPos + 1));
        }
    } else {
        // Simple macro: #define NAME value
        if (nameEnd < trimmedArgs.length()) {
            define.replacement = trim(trimmedArgs.substr(nameEnd));
        }
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

    // First, expand any macro references in the expression
    std::string expandedExpr = expandMacros(args, lineNum);

    // Evaluate the #if expression
    bool conditionMet = false;
    try {
        ExpressionEvaluator evaluator;
        uint32_t result = evaluator.evaluate(expandedExpr);
        conditionMet = (result != 0);
    } catch (const std::exception& e) {
        errorReporter.reportError(lineNum, 1, "#if expression error: " + std::string(e.what()) +
                                 " (expanded: " + expandedExpr + ")");
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

    // Expand macros in the expression
    std::string expandedExpr = expandMacros(args, lineNum);

    // Evaluate the elif condition
    bool conditionMet = false;
    try {
        ExpressionEvaluator evaluator;
        uint32_t result = evaluator.evaluate(expandedExpr);
        conditionMet = (result != 0);
    } catch (const std::exception& e) {
        errorReporter.reportError(lineNum, 1, "#elif expression error: " + std::string(e.what()) +
                                 " (expanded: " + expandedExpr + ")");
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
    // Phase 4 - File inclusion
    if (args.empty()) {
        errorReporter.reportError(lineNum, 1, "#include requires a filename");
        return;
    }

    // Determine if this is a system include <...> or local include "..."
    bool isSystemInclude = false;
    std::string includeFile = trim(args);

    if (includeFile.length() >= 2) {
        if (includeFile[0] == '<' && includeFile[includeFile.length() - 1] == '>') {
            // System include: #include <filename>
            isSystemInclude = true;
            includeFile = includeFile.substr(1, includeFile.length() - 2);
        } else if (includeFile[0] == '"' && includeFile[includeFile.length() - 1] == '"') {
            // Local include: #include "filename"
            isSystemInclude = false;
            includeFile = includeFile.substr(1, includeFile.length() - 2);
        }
    }

    if (includeFile.empty()) {
        errorReporter.reportError(lineNum, 1, "#include filename cannot be empty");
        return;
    }

    // Resolve the include file path
    std::string resolvedPath = resolveIncludePath(includeFile, currentDir, isSystemInclude);

    if (resolvedPath.empty()) {
        errorReporter.reportError(lineNum, 1, "#include file not found: " + includeFile);
        return;
    }

    // Check include depth to prevent infinite recursion
    if (includeDepth >= MAX_INCLUDE_DEPTH) {
        errorReporter.reportError(lineNum, 1, "#include depth exceeded (possible circular include)");
        return;
    }

    // Check for circular includes
    std::string absolutePath = fs::absolute(resolvedPath).string();
    if (includedFiles.count(absolutePath) > 0) {
        // File already included - skip silently to prevent circular includes
        return;
    }
    includedFiles.insert(absolutePath);

    // Read and process the included file
    std::ifstream file(resolvedPath);
    if (!file.is_open()) {
        errorReporter.reportError(lineNum, 1, "#include cannot open file: " + resolvedPath);
        return;
    }

    // Read all lines from the included file
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    // Get the directory of the included file for nested includes
    std::string includeDir = getDirectory(resolvedPath);
    if (includeDir.empty()) {
        includeDir = currentDir;
    }

    // Process the included file's lines and add them to output
    // Note: This is a simplified implementation that processes included content
    // A full implementation would need to integrate this with the main processing loop
    includeDepth++;
    std::string includedContent = processLines(lines, resolvedPath, includeDir);
    includeDepth--;

    // This would need to be integrated into the main processing flow
    // For now, the included content is processed but not directly inserted
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

        // Handle # operator (stringify) - #param becomes "arg"
        size_t hashPos = 0;
        while ((hashPos = result.find("#" + param, hashPos)) != std::string::npos) {
            std::string replacement = "\"" + arg + "\"";
            result.replace(hashPos, 1 + param.length(), replacement);
            hashPos += replacement.length();
        }

        // Handle ## operator (concatenation) - param##something becomes argsomething
        size_t concatPos = 0;
        while ((concatPos = result.find(param + "##", concatPos)) != std::string::npos) {
            result.replace(concatPos, param.length(), arg);
            concatPos += arg.length();
            // Skip the ## operator
            if (concatPos < result.length() && result[concatPos] == '#' &&
                concatPos + 1 < result.length() && result[concatPos + 1] == '#') {
                result.erase(concatPos, 2);
            }
        }

        // Handle ## operator - something##param becomes somethingarg
        concatPos = 0;
        while ((concatPos = result.find("##" + param, concatPos)) != std::string::npos) {
            result.erase(concatPos, 2);  // Remove ##
            result.insert(concatPos, arg);
            concatPos += arg.length();
        }

        // Simple text replacement of parameter names (last, so ## and # are handled first)
        size_t pos = 0;
        while ((pos = result.find(param, pos)) != std::string::npos) {
            // Check if this is a whole word (not part of a larger identifier)
            bool validStart = (pos == 0) || !std::isalnum(result[pos - 1]) && result[pos - 1] != '_';
            bool validEnd = (pos + param.length() >= result.length()) ||
                           (!std::isalnum(result[pos + param.length()]) && result[pos + param.length()] != '_');

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
    // Phase 4 - Resolve include file path
    std::vector<std::string> searchPaths;

    if (!isSystemInclude) {
        // For local includes, first check relative to current file directory
        if (!currentDir.empty()) {
            searchPaths.push_back(currentDir);
        }
    }

    // Add base directory
    searchPaths.push_back(baseDirectory);

    // Add device includes directory for .inc files
    searchPaths.push_back("device_includes");

    // Add current directory as fallback
    searchPaths.push_back(".");

    // Try each search path
    for (const auto& path : searchPaths) {
        std::string fullPath;
        if (path.empty() || path == ".") {
            fullPath = includeFile;
        } else {
            fullPath = path + "/" + includeFile;
        }

        // Normalize path separators
        std::replace(fullPath.begin(), fullPath.end(), '\\', '/');

        if (fs::exists(fullPath)) {
            return fullPath;
        }

        // Try case-insensitive match for device_includes directory
        if (path == "device_includes" || path.find("device_includes") != std::string::npos) {
            try {
                std::string searchDir = path;
                if (searchDir.empty() || searchDir == ".") {
                    searchDir = ".";
                }

                for (const auto& entry : fs::directory_iterator(searchDir)) {
                    std::string entryPath = entry.path().string();
                    std::replace(entryPath.begin(), entryPath.end(), '\\', '/');

                    // Extract filename and compare case-insensitively
                    std::string entryFilename = entry.path().filename().string();
                    std::string includeFilename = includeFile;

                    // Convert to lowercase for comparison
                    std::string entryLower = entryFilename;
                    std::string includeLower = includeFilename;
                    std::transform(entryLower.begin(), entryLower.end(), entryLower.begin(), ::tolower);
                    std::transform(includeLower.begin(), includeLower.end(), includeLower.begin(), ::tolower);

                    if (entryLower == includeLower) {
                        return entryPath;
                    }
                }
            } catch (...) {
                // Directory doesn't exist or can't be read, continue
            }
        }
    }

    return "";  // File not found
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
