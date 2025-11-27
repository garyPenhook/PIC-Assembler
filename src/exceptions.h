#pragma once

#include <stdexcept>
#include <string>
#include <sstream>

/**
 * @file exceptions.h
 * @brief Comprehensive exception hierarchy for the PIC assembler
 *
 * Defines custom exceptions for different error categories:
 * - I/O errors (file reading/writing)
 * - Lexical analysis errors
 * - Parsing errors
 * - Semantic/validation errors
 * - Code generation errors
 * - Expression evaluation errors
 * - System/resource errors
 */

// Base exception class for all assembler-specific exceptions
class AssemblerException : public std::runtime_error {
public:
    explicit AssemblerException(const std::string& message)
        : std::runtime_error("Assembler Error: " + message) {}
    virtual ~AssemblerException() = default;
};

// ============================================================================
// I/O and File Handling Exceptions
// ============================================================================

class FileException : public AssemblerException {
public:
    explicit FileException(const std::string& message)
        : AssemblerException("File Error: " + message) {}
};

class FileNotFoundException : public FileException {
public:
    explicit FileNotFoundException(const std::string& filename)
        : FileException("File not found: '" + filename + "'") {}
};

class FileReadException : public FileException {
public:
    explicit FileReadException(const std::string& filename, const std::string& reason)
        : FileException("Failed to read file '" + filename + "': " + reason) {}
};

class FileWriteException : public FileException {
public:
    explicit FileWriteException(const std::string& filename, const std::string& reason)
        : FileException("Failed to write file '" + filename + "': " + reason) {}
};

class InvalidPathException : public FileException {
public:
    explicit InvalidPathException(const std::string& path)
        : FileException("Invalid file path: '" + path + "'") {}
};

// ============================================================================
// Lexical Analysis Exceptions
// ============================================================================

class LexerException : public AssemblerException {
public:
    LexerException(int line, int column, const std::string& message)
        : AssemblerException(formatMessage(line, column, message)),
          line_(line), column_(column) {}

    int getLine() const { return line_; }
    int getColumn() const { return column_; }

private:
    int line_;
    int column_;

    static std::string formatMessage(int line, int column, const std::string& msg) {
        std::stringstream ss;
        ss << "Lexer Error at Line " << line << ", Column " << column << ": " << msg;
        return ss.str();
    }
};

class InvalidTokenException : public LexerException {
public:
    InvalidTokenException(int line, int column, const std::string& token)
        : LexerException(line, column, "Invalid token: '" + token + "'") {}
};

class UnterminatedStringException : public LexerException {
public:
    UnterminatedStringException(int line, int column)
        : LexerException(line, column, "Unterminated string literal") {}
};

class UnterminatedCommentException : public LexerException {
public:
    UnterminatedCommentException(int line, int column)
        : LexerException(line, column, "Unterminated comment block") {}
};

// ============================================================================
// Parsing and Syntax Exceptions
// ============================================================================

class ParseException : public AssemblerException {
public:
    ParseException(int line, int column, const std::string& message)
        : AssemblerException(formatMessage(line, column, message)),
          line_(line), column_(column) {}

    int getLine() const { return line_; }
    int getColumn() const { return column_; }

private:
    int line_;
    int column_;

    static std::string formatMessage(int line, int column, const std::string& msg) {
        std::stringstream ss;
        ss << "Parse Error at Line " << line << ", Column " << column << ": " << msg;
        return ss.str();
    }
};

class SyntaxException : public ParseException {
public:
    SyntaxException(int line, int column, const std::string& expected, const std::string& found)
        : ParseException(line, column, "Expected " + expected + " but found '" + found + "'") {}
};

class UnexpectedTokenException : public ParseException {
public:
    UnexpectedTokenException(int line, int column, const std::string& token)
        : ParseException(line, column, "Unexpected token: '" + token + "'") {}
};

class MissingTokenException : public ParseException {
public:
    MissingTokenException(int line, int column, const std::string& token)
        : ParseException(line, column, "Missing required token: '" + token + "'") {}
};

// ============================================================================
// Semantic and Validation Exceptions
// ============================================================================

class ValidationException : public AssemblerException {
public:
    ValidationException(int line, const std::string& message)
        : AssemblerException("Validation Error at Line " + std::to_string(line) + ": " + message),
          line_(line) {}

    int getLine() const { return line_; }

private:
    int line_;
};

class InvalidOperandException : public ValidationException {
public:
    InvalidOperandException(int line, const std::string& operand, const std::string& reason)
        : ValidationException(line, "Invalid operand '" + operand + "': " + reason) {}
};

class OperandOutOfRangeException : public ValidationException {
public:
    OperandOutOfRangeException(int line, const std::string& operand,
                              int actual, int minVal, int maxVal)
        : ValidationException(line, "Operand '" + operand + "' value " + std::to_string(actual) +
                            " out of range [" + std::to_string(minVal) + ".." + std::to_string(maxVal) + "]") {}
};

class InvalidInstructionException : public ValidationException {
public:
    InvalidInstructionException(int line, const std::string& mnemonic, const std::string& reason)
        : ValidationException(line, "Invalid instruction '" + mnemonic + "': " + reason) {}
};

class ArchitectureException : public ValidationException {
public:
    ArchitectureException(int line, const std::string& instruction, const std::string& architecture)
        : ValidationException(line, "Instruction '" + instruction + "' is not available in " + architecture) {}
};

class DuplicateLabelException : public ValidationException {
public:
    DuplicateLabelException(int line, const std::string& label)
        : ValidationException(line, "Duplicate label definition: '" + label + "'") {}
};

class UndefinedLabelException : public ValidationException {
public:
    UndefinedLabelException(int line, const std::string& label)
        : ValidationException(line, "Undefined label: '" + label + "'") {}
};

class InvalidMemoryAddressException : public ValidationException {
public:
    InvalidMemoryAddressException(int line, const std::string& address, const std::string& device)
        : ValidationException(line, "Invalid memory address " + address + " for device " + device) {}
};

// ============================================================================
// Expression Evaluation Exceptions
// ============================================================================

class ExpressionException : public AssemblerException {
public:
    ExpressionException(const std::string& expression, const std::string& message)
        : AssemblerException("Expression Error in '" + expression + "': " + message) {}
};

class DivisionByZeroException : public ExpressionException {
public:
    DivisionByZeroException(const std::string& expression)
        : ExpressionException(expression, "Division by zero") {}
};

class InvalidExpressionException : public ExpressionException {
public:
    InvalidExpressionException(const std::string& expression, const std::string& reason)
        : ExpressionException(expression, reason) {}
};

class UndefinedSymbolException : public ExpressionException {
public:
    UndefinedSymbolException(const std::string& expression, const std::string& symbol)
        : ExpressionException(expression, "Undefined symbol: '" + symbol + "'") {}
};

class InvalidNumberFormatException : public ExpressionException {
public:
    InvalidNumberFormatException(const std::string& expression, const std::string& number)
        : ExpressionException(expression, "Invalid number format: '" + number + "'") {}
};

// ============================================================================
// Code Generation Exceptions
// ============================================================================

class CodeGenerationException : public AssemblerException {
public:
    CodeGenerationException(int line, const std::string& message)
        : AssemblerException("Code Generation Error at Line " + std::to_string(line) + ": " + message),
          line_(line) {}

    int getLine() const { return line_; }

private:
    int line_;
};

class InstructionEncodingException : public CodeGenerationException {
public:
    InstructionEncodingException(int line, const std::string& mnemonic, const std::string& reason)
        : CodeGenerationException(line, "Failed to encode instruction '" + mnemonic + "': " + reason) {}
};

class RegisterAllocationException : public CodeGenerationException {
public:
    RegisterAllocationException(int line, const std::string& reason)
        : CodeGenerationException(line, "Register allocation error: " + reason) {}
};

class MemoryAllocationException : public CodeGenerationException {
public:
    MemoryAllocationException(int line, const std::string& section, uint32_t required, uint32_t available)
        : CodeGenerationException(line, "Memory allocation error in " + section + ": "
                                  "required " + std::to_string(required) + " bytes but only " +
                                  std::to_string(available) + " available") {}
};

// ============================================================================
// Output Format Exceptions
// ============================================================================

class OutputException : public AssemblerException {
public:
    explicit OutputException(const std::string& message)
        : AssemblerException("Output Error: " + message) {}
};

class HexGenerationException : public OutputException {
public:
    explicit HexGenerationException(const std::string& reason)
        : OutputException("Failed to generate HEX file: " + reason) {}
};

class InvalidChecksumException : public OutputException {
public:
    InvalidChecksumException(const std::string& line)
        : OutputException("Invalid checksum in HEX line: " + line) {}
};

class HexRecordException : public OutputException {
public:
    HexRecordException(int line, const std::string& reason)
        : OutputException("Invalid HEX record at line " + std::to_string(line) + ": " + reason) {}
};

// ============================================================================
// Device and Configuration Exceptions
// ============================================================================

class DeviceException : public AssemblerException {
public:
    explicit DeviceException(const std::string& message)
        : AssemblerException("Device Error: " + message) {}
};

class UnknownDeviceException : public DeviceException {
public:
    explicit UnknownDeviceException(const std::string& device)
        : DeviceException("Unknown device: '" + device + "'") {}
};

class UnsupportedArchitectureException : public DeviceException {
public:
    explicit UnsupportedArchitectureException(const std::string& architecture)
        : DeviceException("Unsupported architecture: '" + architecture + "'") {}
};

class InvalidConfigurationException : public DeviceException {
public:
    explicit InvalidConfigurationException(const std::string& reason)
        : DeviceException("Invalid configuration: " + reason) {}
};

// ============================================================================
// System and Resource Exceptions
// ============================================================================

class SystemException : public AssemblerException {
public:
    explicit SystemException(const std::string& message)
        : AssemblerException("System Error: " + message) {}
};

class MemoryException : public SystemException {
public:
    explicit MemoryException(const std::string& reason)
        : SystemException("Memory error: " + reason) {}
};

class OutOfMemoryException : public MemoryException {
public:
    explicit OutOfMemoryException(size_t requested)
        : MemoryException("Failed to allocate " + std::to_string(requested) + " bytes") {}
};

class BufferOverflowException : public SystemException {
public:
    explicit BufferOverflowException(const std::string& buffer)
        : SystemException("Buffer overflow in: " + buffer) {}
};

class TimeoutException : public SystemException {
public:
    explicit TimeoutException(const std::string& operation)
        : SystemException("Operation timed out: " + operation) {}
};

// ============================================================================
// Assembly Process Exceptions
// ============================================================================

class AssemblyException : public AssemblerException {
public:
    explicit AssemblyException(const std::string& message)
        : AssemblerException("Assembly Error: " + message) {}
};

class IncompleteAssemblyException : public AssemblyException {
public:
    explicit IncompleteAssemblyException(const std::string& reason)
        : AssemblyException("Assembly incomplete: " + reason) {}
};

class CircularDependencyException : public AssemblyException {
public:
    explicit CircularDependencyException(const std::string& chain)
        : AssemblyException("Circular dependency detected: " + chain) {}
};

class ContextException : public AssemblyException {
public:
    explicit ContextException(const std::string& expected, const std::string& actual)
        : AssemblyException("Invalid context: expected '" + expected + "' but in '" + actual + "'") {}
};
