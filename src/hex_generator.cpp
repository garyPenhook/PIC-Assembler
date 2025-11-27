#include "hex_generator.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

std::string HexGenerator::byteToHex(uint8_t value) const {
    std::stringstream ss;
    ss << std::uppercase << std::setfill('0') << std::setw(2) << std::hex << (int)value;
    return ss.str();
}

std::string HexGenerator::wordToHex(uint16_t value) const {
    std::stringstream ss;
    ss << std::uppercase << std::setfill('0') << std::setw(4) << std::hex << value;
    return ss.str();
}

uint8_t HexGenerator::calculateChecksum(const std::vector<uint8_t>& data) const {
    uint8_t sum = 0;
    for (uint8_t byte : data) {
        sum += byte;
    }
    return (~sum) + 1;  // Two's complement
}

std::string HexGenerator::createRecord(RecordType type, uint16_t address,
                                      const std::vector<uint8_t>& data) const {
    std::stringstream ss;

    // Start code
    ss << ":";

    // Byte count
    uint8_t byteCount = data.size();
    ss << byteToHex(byteCount);

    // Address (high byte, low byte)
    ss << byteToHex((address >> 8) & 0xFF);
    ss << byteToHex(address & 0xFF);

    // Record type
    ss << byteToHex(static_cast<uint8_t>(type));

    // Data
    std::vector<uint8_t> recordData;
    recordData.push_back(byteCount);
    recordData.push_back((address >> 8) & 0xFF);
    recordData.push_back(address & 0xFF);
    recordData.push_back(static_cast<uint8_t>(type));
    recordData.insert(recordData.end(), data.begin(), data.end());

    for (uint8_t byte : data) {
        ss << byteToHex(byte);
    }

    // Checksum
    uint8_t checksum = calculateChecksum(recordData);
    ss << byteToHex(checksum);

    return ss.str();
}

std::string HexGenerator::generateHex(const std::vector<AssembledCode>& code) {
    std::stringstream result;

    if (code.empty()) {
        lastError = "No code to generate HEX from";
        return "";
    }

    // Group instructions by address regions
    uint16_t currentAddress = 0;
    std::vector<uint8_t> currentData;

    for (const auto& item : code) {
        if (item.address != currentAddress && !currentData.empty()) {
            // Write current record
            std::string record = createRecord(RecordType::DATA, currentAddress, currentData);
            result << record << "\n";
            currentData.clear();
        }

        currentAddress = item.address;

        // For PIC16, each instruction is 14 bits, but stored as 16-bit words
        // Low byte first (little-endian)
        uint8_t lowByte = item.instruction & 0xFF;
        uint8_t highByte = (item.instruction >> 8) & 0xFF;

        currentData.push_back(lowByte);
        currentData.push_back(highByte);

        currentAddress++;
    }

    // Write remaining data
    if (!currentData.empty()) {
        std::string record = createRecord(RecordType::DATA, currentAddress - 1, currentData);
        result << record << "\n";
    }

    // End of file record
    std::vector<uint8_t> emptyData;
    result << createRecord(RecordType::END_OF_FILE, 0x0000, emptyData) << "\n";

    return result.str();
}

bool HexGenerator::writeToFile(const std::string& filename,
                               const std::vector<AssembledCode>& code) {
    try {
        std::string hexContent = generateHex(code);

        if (hexContent.empty()) {
            lastError = "Failed to generate HEX content";
            return false;
        }

        std::ofstream file(filename, std::ios::out);
        if (!file.is_open()) {
            lastError = "Cannot open file for writing: " + filename;
            return false;
        }

        file << hexContent;
        file.close();

        return true;

    } catch (const std::exception& e) {
        lastError = "Error writing HEX file: " + std::string(e.what());
        return false;
    }
}
