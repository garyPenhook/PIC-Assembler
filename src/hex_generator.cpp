#include "hex_generator.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

HexGenerator::HexGenerator(Architecture arch)
    : targetArch(arch) {
}

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

std::string HexGenerator::generateHex(const std::vector<AssembledCode>& code,
                                       const std::vector<DataDefinition>& data,
                                       const std::vector<ConfigWord>& config) {
    std::stringstream result;

    if (code.empty() && data.empty() && config.empty()) {
        lastError = "No code, data, or config to generate HEX from";
        return "";
    }

    // Create a combined list of all items sorted by address
    std::vector<std::pair<uint32_t, std::vector<uint8_t>>> items;

    // Add instructions
    for (const auto& item : code) {
        // Convert word address to byte address for PIC16
        // PIC16: word-addressed (each word = 2 bytes)
        // PIC18: byte-addressed (each byte = 1 address unit)
        uint32_t byteAddress = (targetArch == Architecture::PIC16)
            ? item.address * 2
            : item.address;

        // For PIC16, each instruction is 14 bits, but stored as 16-bit words
        // Low byte first (little-endian)
        uint8_t lowByte = item.instruction & 0xFF;
        uint8_t highByte = (item.instruction >> 8) & 0xFF;

        std::vector<uint8_t> instrData{lowByte, highByte};
        items.push_back({byteAddress, instrData});
    }

    // Add data definitions
    for (const auto& dataDef : data) {
        uint32_t byteAddress = (targetArch == Architecture::PIC16)
            ? dataDef.address * 2
            : dataDef.address;
        items.push_back({byteAddress, dataDef.bytes});
    }

    // Add configuration words
    for (const auto& configWord : config) {
        // CONFIG words are stored at their absolute addresses
        // PIC16/PIC12: 0x2007 (word address) -> 0x400E (byte address = 0x2007 * 2)
        // PIC18: 0x300000 (byte address)
        uint32_t byteAddress;
        if (targetArch == Architecture::PIC16 || targetArch == Architecture::PIC12) {
            // For PIC16/PIC12, config address is a word address
            byteAddress = configWord.address * 2;
        } else {
            // For PIC18, config address is already a byte address
            byteAddress = configWord.address;
        }

        // CONFIG word is 14-bit for PIC16, 8-bit for PIC18
        // Store as little-endian bytes
        uint8_t lowByte = configWord.value & 0xFF;
        uint8_t highByte = (configWord.value >> 8) & 0xFF;

        std::vector<uint8_t> configData{lowByte, highByte};
        items.push_back({byteAddress, configData});
    }

    // Sort items by address
    std::sort(items.begin(), items.end(),
              [](const auto& a, const auto& b) { return a.first < b.first; });

    // Write items to HEX format
    uint32_t currentAddress = 0;
    std::vector<uint8_t> currentData;

    for (const auto& item : items) {
        uint32_t byteAddress = item.first;

        if (byteAddress != currentAddress && !currentData.empty()) {
            // Write current record at the START address of accumulated data
            uint32_t recordAddress = currentAddress - currentData.size();
            std::string record = createRecord(RecordType::DATA, recordAddress & 0xFFFF, currentData);
            result << record << "\n";
            currentData.clear();
        }

        currentAddress = byteAddress;

        // Add data bytes
        for (uint8_t byte : item.second) {
            currentData.push_back(byte);
        }

        currentAddress += item.second.size();
    }

    // Write remaining data
    if (!currentData.empty()) {
        std::string record = createRecord(RecordType::DATA, (currentAddress - currentData.size()) & 0xFFFF, currentData);
        result << record << "\n";
    }

    // End of file record
    std::vector<uint8_t> emptyData;
    result << createRecord(RecordType::END_OF_FILE, 0x0000, emptyData) << "\n";

    return result.str();
}

bool HexGenerator::writeToFile(const std::string& filename,
                               const std::vector<AssembledCode>& code,
                               const std::vector<DataDefinition>& data,
                               const std::vector<ConfigWord>& config) {
    try {
        // Validate filename
        if (filename.empty()) {
            throw InvalidPathException("<empty filename>");
        }

        try {
            // Generate HEX content
            std::string hexContent = generateHex(code, data, config);

            if (hexContent.empty()) {
                throw HexGenerationException("No HEX content was generated from input code and data");
            }

            // Attempt to open file for writing
            std::ofstream file(filename, std::ios::out);
            if (!file.is_open()) {
                throw FileWriteException(filename, "file could not be opened for writing");
            }

            // Write content to file
            try {
                file << hexContent;
                if (!file.good()) {
                    throw FileWriteException(filename, "write operation failed");
                }
            } catch (const std::ios_base::failure& e) {
                throw FileWriteException(filename, std::string(e.what()));
            }

            // Close file and check for errors
            file.close();
            if (file.fail()) {
                throw FileWriteException(filename, "close operation failed");
            }

            return true;

        } catch (const FileException& e) {
            lastError = e.what();
            return false;
        } catch (const HexGenerationException& e) {
            lastError = e.what();
            return false;
        }

    } catch (const FileException& e) {
        lastError = e.what();
        return false;
    } catch (const AssemblerException& e) {
        lastError = std::string(e.what());
        return false;
    } catch (const std::bad_alloc&) {
        lastError = "Out of memory while writing HEX file";
        return false;
    } catch (const std::exception& e) {
        lastError = "Error writing HEX file: " + std::string(e.what());
        return false;
    } catch (...) {
        lastError = "Unknown error occurred while writing HEX file";
        return false;
    }
}
