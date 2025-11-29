#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdint>
#include <memory>
#include "error_reporter.h"

/**
 * SourceLocation - Maps preprocessed line numbers back to original source
 */
struct SourceLocation {
    uint32_t preprocessedLine;   // Line number in preprocessed output
    uint32_t originalLine;       // Line number in original source
    std::string originalFile;    // Original source filename
};

/**
 * PreprocessorDefine - Stores #define macro definition
 */
struct PreprocessorDefine {
    std::string name;                      // Macro name
    std::vector<std::string> parameters;   // Parameter names (empty for simple defines)
    std::string replacement;               // Replacement text
    bool isFunctionLike;                   // true if #define NAME(params) ...
    bool isVariadic;                       // true if has ...
    int definitionLine;                    // Line where macro was defined
    std::string definitionFile;            // File where macro was defined
};

/**
 * ConditionalBlock - Tracks #if/#ifdef/#ifndef state
 */
struct ConditionalBlock {
    enum Type {
        IF_TYPE,
        IFDEF_TYPE,
        IFNDEF_TYPE,
        ELIF_TYPE,
        ELSE_TYPE
    };

    Type type;
    std::string condition;       // For #if: the expression to evaluate
    std::string symbol;          // For #ifdef/#ifndef: the symbol name
    bool conditionMet;           // Was this condition true?
    bool anyBranchTaken;         // Has any branch of this if/elif/else been taken?
    bool isActive;               // Should we process lines in this block?
    uint32_t startLine;          // Where this block started
    std::string startFile;       // Which file it started in
};

/**
 * Preprocessor - Handles preprocessor directives (#define, #ifdef, #include, etc.)
 *
 * The preprocessor runs BEFORE the lexer, processing the source text and producing
 * preprocessed text without any preprocessor directives.
 *
 * Flow: Source Text → Preprocessor → Preprocessed Text → Lexer → Tokens → Parser
 */
class Preprocessor {
public:
    /**
     * Constructor
     * @param baseDir Base directory for resolving include paths (default: current directory)
     */
    explicit Preprocessor(const std::string& baseDir = ".");

    /**
     * Main preprocessing entry point
     * @param source Source code to preprocess
     * @param filename Name of the source file (for error reporting)
     * @return Preprocessed source code
     */
    std::string process(const std::string& source, const std::string& filename = "<input>");

    /**
     * Get the error reporter
     */
    const ErrorReporter& getErrors() const { return errorReporter; }
    ErrorReporter& getErrors() { return errorReporter; }

    /**
     * Check if preprocessing was successful (no errors)
     */
    bool wasSuccessful() const { return !errorReporter.hasErrors(); }

    /**
     * Get line mapping for error reporting
     * Maps preprocessed line numbers back to original source locations
     */
    const std::vector<SourceLocation>& getLineMapping() const {
        return lineMapping;
    }

    /**
     * Define a symbol (can be called before processing)
     * @param name Symbol name
     * @param value Symbol value (default "1")
     */
    void defineSymbol(const std::string& name, const std::string& value = "1");

    /**
     * Undefine a symbol
     * @param name Symbol name
     */
    void undefineSymbol(const std::string& name);

    /**
     * Check if a symbol is defined
     * @param name Symbol name
     * @return true if symbol is defined
     */
    bool isSymbolDefined(const std::string& name) const;

    /**
     * Get symbol value
     * @param name Symbol name
     * @return Symbol value or empty string if not defined
     */
    std::string getSymbolValue(const std::string& name) const;

    /**
     * Get the set of included files (after processing)
     * @return Set of absolute paths to included files
     */
    const std::set<std::string>& getIncludedFiles() const { return includedFiles; }

private:
    // State
    std::map<std::string, PreprocessorDefine> defines;        // #define table
    std::vector<ConditionalBlock> conditionalStack;            // #if/#ifdef nesting stack
    std::set<std::string> includedFiles;                       // Track included files (circular detection)
    std::vector<SourceLocation> lineMapping;                   // Line number mapping
    ErrorReporter errorReporter;                               // Error/warning reporting
    std::string baseDirectory;                                 // Base directory for includes
    int includeDepth;                                          // Prevent infinite include recursion
    static constexpr int MAX_INCLUDE_DEPTH = 100;

    // === Core Processing ===

    /**
     * Process a file (recursive for #include)
     */
    std::string processFile(const std::string& filename, int depth, const std::string& currentDir);

    /**
     * Split source into lines and process them
     */
    std::string processLines(const std::vector<std::string>& lines,
                            const std::string& filename,
                            const std::string& currentDir);

    /**
     * Process a single line
     * @param line Input line
     * @param lineNum Line number in file
     * @param filename Source filename
     * @return Processed line(s) or empty string if line should be skipped
     */
    std::string processLine(const std::string& line, size_t lineNum,
                           const std::string& filename);

    // === Directive Handlers ===

    /**
     * Check if a line is a preprocessor directive
     */
    bool isPreprocessorDirective(const std::string& line) const;

    /**
     * Extract directive name and arguments from a line
     * @return pair of (directive, arguments)
     */
    std::pair<std::string, std::string> parseDirectiveLine(const std::string& line) const;

    /**
     * Handle #define directive
     */
    void handleDefine(const std::string& args, size_t lineNum, const std::string& filename);

    /**
     * Handle #undef directive
     */
    void handleUndef(const std::string& args, size_t lineNum);

    /**
     * Handle #ifdef directive
     */
    void handleIfdef(const std::string& args, size_t lineNum);

    /**
     * Handle #ifndef directive
     */
    void handleIfndef(const std::string& args, size_t lineNum);

    /**
     * Handle #if directive (expression-based - Phase 3)
     */
    void handleIf(const std::string& args, size_t lineNum);

    /**
     * Handle #elif directive
     */
    void handleElif(const std::string& args, size_t lineNum);

    /**
     * Handle #else directive
     */
    void handleElse(size_t lineNum);

    /**
     * Handle #endif directive
     */
    void handleEndif(size_t lineNum);

    /**
     * Handle #include directive
     */
    void handleInclude(const std::string& args, size_t lineNum,
                      const std::string& currentFile, const std::string& currentDir);

    /**
     * Handle #error directive (Phase 5)
     */
    void handleError(const std::string& args, size_t lineNum);

    /**
     * Handle #warning directive (Phase 5)
     */
    void handleWarning(const std::string& args, size_t lineNum);

    /**
     * Handle #line directive (Phase 5)
     */
    void handleLine(const std::string& args, size_t lineNum);

    // === Macro Expansion ===

    /**
     * Check if a symbol is defined (case-insensitive)
     */
    bool isDefined(const std::string& name) const;

    /**
     * Expand macros in a line of text
     * @param text Text to expand macros in
     * @param lineNum Line number for error reporting
     * @return Expanded text
     */
    std::string expandMacros(const std::string& text, size_t lineNum);

    /**
     * Expand a single macro
     * @param macroName Name of macro to expand
     * @param arguments Arguments to macro (for function-like macros)
     * @param lineNum Line number for error reporting
     * @return Expanded text
     */
    std::string expandMacro(const std::string& macroName,
                           const std::vector<std::string>& arguments,
                           size_t lineNum);

    /**
     * Replace macro parameters in text
     */
    std::string substituteParameters(const std::string& text,
                                    const std::vector<std::string>& parameters,
                                    const std::vector<std::string>& arguments);

    // === Utility Methods ===

    /**
     * Check if we should process the current line based on conditional stack
     */
    bool shouldProcessLine() const;

    /**
     * Get current directory from filename path
     */
    std::string getDirectory(const std::string& filepath) const;

    /**
     * Resolve include file path
     */
    std::string resolveIncludePath(const std::string& includeFile,
                                  const std::string& currentDir,
                                  bool isSystemInclude) const;

    /**
     * Split a line by delimiter (handling quoted strings)
     */
    std::vector<std::string> splitLine(const std::string& line, char delimiter = ' ') const;

    /**
     * Trim whitespace from string
     */
    std::string trim(const std::string& str) const;

    /**
     * Check if character is whitespace
     */
    bool isWhitespace(char c) const {
        return c == ' ' || c == '\t' || c == '\r' || c == '\n';
    }

    /**
     * Convert string to uppercase (case-insensitive comparison)
     */
    std::string toUpper(const std::string& str) const;
};
