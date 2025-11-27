#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <ostream>
#include <cstdint>

enum class ErrorSeverity {
    WARNING,
    ERROR,
    FATAL
};

struct ErrorLocation {
    uint32_t line;
    uint32_t column;
    std::string sourceLine;
};

struct ErrorMessage {
    ErrorSeverity severity;
    std::string message;
    std::string hint;
    ErrorLocation location;
};

class ErrorReporter {
public:
    // Report an error with context
    void reportError(uint32_t line, uint32_t column, const std::string& message,
                    const std::string& hint = "", const std::string& sourceLine = "");

    // Report a warning
    void reportWarning(uint32_t line, uint32_t column, const std::string& message,
                      const std::string& hint = "", const std::string& sourceLine = "");

    // Architecture validation error
    void reportArchitectureError(uint32_t line, const std::string& instruction,
                                const std::string& currentArch, const std::string& requiredArch,
                                const std::string& sourceLine = "");

    // Syntax error with suggestions
    void reportSyntaxError(uint32_t line, const std::string& message,
                          const std::vector<std::string>& suggestions,
                          const std::string& sourceLine = "");

    // Operand error
    void reportOperandError(uint32_t line, const std::string& operand,
                           const std::string& expected, const std::string& got,
                           const std::string& sourceLine = "");

    // Undefined symbol error
    void reportUndefinedSymbol(uint32_t line, const std::string& symbol,
                              const std::vector<std::string>& similarSymbols,
                              const std::string& sourceLine = "");

    // Get all errors
    const std::vector<ErrorMessage>& getErrors() const { return errors; }

    // Get all warnings
    const std::vector<ErrorMessage>& getWarnings() const { return warnings; }

    // Check if there are errors
    bool hasErrors() const { return !errors.empty(); }

    // Check if there are warnings
    bool hasWarnings() const { return !warnings.empty(); }

    // Clear all messages
    void clear();

    // Print formatted error report
    void printReport(std::ostream& out = std::cout) const;

    // Get error count
    uint32_t getErrorCount() const { return errors.size(); }
    uint32_t getWarningCount() const { return warnings.size(); }

private:
    std::vector<ErrorMessage> errors;
    std::vector<ErrorMessage> warnings;

    // Helper to format error output
    std::string formatError(const ErrorMessage& error) const;
    std::string createPointer(uint32_t column) const;
};
