#pragma once

#include <string>
#include <vector>
#include <map>
#include <cstdint>
#include <memory>
#include "instruction.h"
#include "error_reporter.h"
#include "device_specs.h"
#include "exceptions.h"
#include "preprocessor.h"

// Forward declaration for SectionType (defined in parser.h)
enum class SectionType;

struct AssembledCode {
    uint16_t address;
    uint16_t instruction;
    std::string sourceCode;
    int lineNumber;
    std::string sectionName;     // Which section this belongs to
    SectionType sectionType;     // Type of section (cast from SectionType enum)
};

struct DataDefinition {
    uint16_t address;
    std::vector<uint8_t> bytes;
    std::string sourceCode;
    int lineNumber;
    std::string sectionName;     // Which section this belongs to
    SectionType sectionType;     // Type of section
    bool isInitialized;          // IDATA vs UDATA
};

struct ConfigWord {
    uint32_t address;      // Configuration word address (0x2007 for PIC16, 0x300000+ for PIC18)
    uint16_t value;        // Configuration bits value
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

    // Get generated data definitions
    const std::vector<DataDefinition>& getDataDefinitions() const { return generatedData; }

    // Get configuration words
    const std::vector<ConfigWord>& getConfigWords() const { return configWords; }

    // Get target architecture
    Architecture getArchitecture() const { return targetArch; }

    // Get errors from compilation
    std::shared_ptr<const ErrorReporter> getErrors() const { return lastErrors; }

    // Generate statistics
    void printStatistics() const;

    // Generate list file (.lst) with source code and generated code
    bool generateListFile(const std::string& filename, const std::string& sourceCode) const;

    // Memory usage queries
    uint32_t getProgramMemoryUsed() const;
    uint32_t getProgramMemoryTotal() const;
    uint32_t getDataMemoryUsed() const;
    uint32_t getDataMemoryTotal() const;
    uint32_t getEEPROMTotal() const;
    double getProgramMemoryPercentage() const;
    double getDataMemoryPercentage() const;

    // Get current device spec
    const DeviceSpec& getDeviceSpec() const { return currentDeviceSpec; }

private:
    std::vector<AssembledCode> generatedCode;
    std::vector<DataDefinition> generatedData;
    std::vector<ConfigWord> configWords;
    std::string lastError;
    bool successful;
    Architecture targetArch;
    DeviceSpec currentDeviceSpec;  // Track current device specifications
    std::shared_ptr<ErrorReporter> lastErrors;

    // Helper for error handling
    void setError(const std::string& error);
};
