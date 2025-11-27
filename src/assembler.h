#pragma once

#include <string>
#include <vector>
#include <map>
#include <cstdint>
#include <memory>
#include "instruction.h"
#include "error_reporter.h"
#include "device_specs.h"

struct AssembledCode {
    uint16_t address;
    uint16_t instruction;
    std::string sourceCode;
    int lineNumber;
};

class Assembler {
public:
    // Constructor with architecture parameter
    explicit Assembler(Architecture arch = Architecture::PIC16);

    // Assemble source code and return generated instructions
    std::vector<AssembledCode> assemble(const std::string& source);

    // Get last error message
    const std::string& getLastError() const { return lastError; }

    // Check if assembly was successful
    bool wasSuccessful() const { return successful; }

    // Get generated machine code
    const std::vector<AssembledCode>& getCode() const { return generatedCode; }

    // Get target architecture
    Architecture getArchitecture() const { return targetArch; }

    // Get errors from compilation
    std::shared_ptr<const ErrorReporter> getErrors() const { return lastErrors; }

    // Generate statistics
    void printStatistics() const;

    // Memory usage queries
    uint32_t getProgramMemoryUsed() const;
    uint32_t getProgramMemoryTotal() const;
    uint32_t getDataMemoryUsed() const;
    uint32_t getDataMemoryTotal() const;
    uint32_t getEEPROMTotal() const;
    double getProgramMemoryPercentage() const;
    double getDataMemoryPercentage() const;

private:
    std::vector<AssembledCode> generatedCode;
    std::string lastError;
    bool successful;
    Architecture targetArch;
    std::shared_ptr<ErrorReporter> lastErrors;

    // Helper for error handling
    void setError(const std::string& error);
};
