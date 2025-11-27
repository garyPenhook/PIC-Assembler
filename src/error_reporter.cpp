#include "error_reporter.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

void ErrorReporter::reportError(uint32_t line, uint32_t column, const std::string& message,
                               const std::string& hint, const std::string& sourceLine) {
    ErrorMessage err{};
    err.severity = ErrorSeverity::ERROR;
    err.message = message;
    err.hint = hint;
    err.location.line = line;
    err.location.column = column;
    err.location.sourceLine = sourceLine;
    errors.push_back(err);
}

void ErrorReporter::reportWarning(uint32_t line, uint32_t column, const std::string& message,
                                 const std::string& hint, const std::string& sourceLine) {
    ErrorMessage warn{};
    warn.severity = ErrorSeverity::WARNING;
    warn.message = message;
    warn.hint = hint;
    warn.location.line = line;
    warn.location.column = column;
    warn.location.sourceLine = sourceLine;
    warnings.push_back(warn);
}

void ErrorReporter::reportArchitectureError(uint32_t line, const std::string& instruction,
                                           const std::string& currentArch,
                                           const std::string& requiredArch,
                                           const std::string& sourceLine) {
    std::string message = "Instruction '" + instruction + "' is not available in " +
                         currentArch + " architecture";
    std::string hint = "This instruction is specific to " + requiredArch + ". " +
                      "Use '-a " + requiredArch + "' to assemble for that architecture.";
    reportError(line, 1, message, hint, sourceLine);
}

void ErrorReporter::reportSyntaxError(uint32_t line, const std::string& message,
                                     const std::vector<std::string>& suggestions,
                                     const std::string& sourceLine) {
    std::string hint = "Possible corrections:\n";
    for (size_t i = 0; i < suggestions.size() && i < 3; ++i) {
        hint += "  - " + suggestions[i] + "\n";
    }
    reportError(line, 1, message, hint, sourceLine);
}

void ErrorReporter::reportOperandError(uint32_t line, const std::string& operand,
                                      const std::string& expected, const std::string& got,
                                      const std::string& sourceLine) {
    std::string message = "Invalid operand '" + got + "'";
    std::string hint = "Expected: " + expected + "\n  Got: " + got;
    reportError(line, 1, message, hint, sourceLine);
}

void ErrorReporter::reportUndefinedSymbol(uint32_t line, const std::string& symbol,
                                         const std::vector<std::string>& similarSymbols,
                                         const std::string& sourceLine) {
    std::string message = "Undefined symbol: '" + symbol + "'";
    std::string hint;

    if (!similarSymbols.empty()) {
        hint = "Did you mean one of these?\n";
        for (size_t i = 0; i < similarSymbols.size() && i < 3; ++i) {
            hint += "  - " + similarSymbols[i] + "\n";
        }
    } else {
        hint = "This label or constant has not been defined.";
    }
    reportError(line, 1, message, hint, sourceLine);
}

std::string ErrorReporter::createPointer(uint32_t column) const {
    std::string pointer;
    for (uint32_t i = 1; i < column; ++i) {
        pointer += " ";
    }
    pointer += "^";
    return pointer;
}

std::string ErrorReporter::formatError(const ErrorMessage& error) const {
    std::stringstream ss;
    const char* severityStr = (error.severity == ErrorSeverity::ERROR) ? "error" : "warning";
    const char* severityColor = (error.severity == ErrorSeverity::ERROR) ? "\x1b[31m" : "\x1b[33m";
    const char* reset = "\x1b[0m";

    // Header line with location
    ss << severityColor << "[" << severityStr << "] " << reset;
    ss << "Line " << error.location.line;
    if (error.location.column > 0) {
        ss << ", Column " << error.location.column;
    }
    ss << "\n";

    // Source line context
    if (!error.location.sourceLine.empty()) {
        ss << "  " << error.location.sourceLine << "\n";
        if (error.location.column > 0) {
            ss << "  " << createPointer(error.location.column) << "\n";
        }
    }

    // Error message
    ss << severityColor << "  " << error.message << reset << "\n";

    // Hint/suggestion
    if (!error.hint.empty()) {
        ss << "  \x1b[36mHint:\x1b[0m " << error.hint << "\n";
    }

    ss << "\n";
    return ss.str();
}

void ErrorReporter::printReport(std::ostream& out) const {
    if (!hasErrors() && !hasWarnings()) {
        return;
    }

    out << "========================================\n";
    out << "  ASSEMBLY REPORT\n";
    out << "========================================\n\n";

    // Print errors
    for (const auto& error : errors) {
        out << formatError(error);
    }

    // Print warnings
    for (const auto& warning : warnings) {
        out << formatError(warning);
    }

    // Summary
    out << "========================================\n";
    if (!errors.empty()) {
        out << "\x1b[31m" << errors.size() << " error(s)\x1b[0m";
    }
    if (!warnings.empty()) {
        if (!errors.empty()) out << ", ";
        out << "\x1b[33m" << warnings.size() << " warning(s)\x1b[0m";
    }
    out << "\n";
    out << "========================================\n\n";
}

void ErrorReporter::clear() {
    errors.clear();
    warnings.clear();
}
