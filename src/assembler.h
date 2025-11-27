#pragma once

#include <string>
#include <vector>
#include <map>
#include <cstdint>
#include "instruction.h"

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

    // Generate statistics
    void printStatistics() const;

private:
    std::vector<AssembledCode> generatedCode;
    std::string lastError;
    bool successful;
    Architecture targetArch;

    // Helper for error handling
    void setError(const std::string& error);
};
