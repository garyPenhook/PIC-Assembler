#pragma once

#include "assembler.h"
#include <string>
#include <vector>

class HexGenerator {
public:
    // Generate Intel HEX format from assembled code
    std::string generateHex(const std::vector<AssembledCode>& code);

    // Write hex to file
    bool writeToFile(const std::string& filename, const std::vector<AssembledCode>& code);

    // Get last error
    const std::string& getLastError() const { return lastError; }

private:
    std::string lastError;

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
