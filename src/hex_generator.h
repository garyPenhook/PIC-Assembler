#pragma once

#include "assembler.h"
#include "instruction.h"
#include "exceptions.h"
#include <string>
#include <vector>

class HexGenerator {
public:
    // Constructor with architecture
    explicit HexGenerator(Architecture arch = Architecture::PIC16);

    // Generate Intel HEX format from assembled code and data
    std::string generateHex(const std::vector<AssembledCode>& code,
                          const std::vector<DataDefinition>& data = {});

    // Write hex to file
    bool writeToFile(const std::string& filename, const std::vector<AssembledCode>& code,
                     const std::vector<DataDefinition>& data = {});

    // Get last error
    const std::string& getLastError() const { return lastError; }

private:
    std::string lastError;
    Architecture targetArch;

    // Helper functions for HEX generation
    uint8_t calculateChecksum(const std::vector<uint8_t>& data) const;
    std::string byteToHex(uint8_t value) const;
    std::string wordToHex(uint16_t value) const;

    // Intel HEX record types
    enum class RecordType : uint8_t {
        DATA = 0x00,
        END_OF_FILE = 0x01,
        EXTENDED_LINEAR_ADDRESS = 0x04
    };

    std::string createRecord(RecordType type, uint16_t address,
                           const std::vector<uint8_t>& data) const;
};
