/**
 * Parse Microchip .PIC files to extract ALL device specifications
 *
 * This tool parses XML .PIC files from Microchip DFP (Device Family Pack) files
 * and extracts memory specifications for ALL supported PIC devices.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <filesystem>
#include <regex>
#include <algorithm>

namespace fs = std::filesystem;

struct DeviceMemory {
    std::string name;
    uint32_t programWords;     // Program memory in WORDS
    uint32_t dataBytes;         // Data RAM in bytes
    uint32_t eepromBytes;       // EEPROM in bytes
    std::string architecture;   // PIC12, PIC16, or PIC18
    bool found = false;
};

std::string extractAttribute(const std::string& line, const std::string& attr) {
    std::regex attrRegex(attr + "=\"([^\"]+)\"");
    std::smatch match;
    if (std::regex_search(line, match, attrRegex)) {
        return match[1].str();
    }
    return "";
}

uint32_t parseHex(const std::string& hexStr) {
    if (hexStr.empty()) return 0;
    try {
        return std::stoul(hexStr, nullptr, 16);
    } catch (...) {
        return 0;
    }
}

std::string inferArchitecture(const std::string& arch, const std::string& deviceName) {
    // Check architecture string
    if (arch.find("18") != std::string::npos) return "PIC18";
    if (arch.find("16") != std::string::npos) return "PIC16";
    if (arch.find("12") != std::string::npos) return "PIC12";

    // Check device name
    if (deviceName.find("PIC18") == 0) return "PIC18";
    if (deviceName.find("PIC16") == 0) return "PIC16";
    if (deviceName.find("PIC12") == 0 || deviceName.find("PIC10") == 0) return "PIC12";

    return "PIC16"; // Default
}

DeviceMemory parsePICFile(const std::string& filePath) {
    DeviceMemory dev;

    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Cannot open: " << filePath << std::endl;
        return dev;
    }

    std::string line;
    std::string archStr;
    uint32_t codeBegin = 0, codeEnd = 0;
    uint32_t dataEnd = 0;
    bool hasEEData = false;

    while (std::getline(file, line)) {
        // Extract device name from <edc:PIC> tag
        if (line.find("<edc:PIC") != std::string::npos) {
            dev.name = extractAttribute(line, "edc:name");
            archStr = extractAttribute(line, "edc:arch");
        }

        // Extract program memory from CodeSector
        if (line.find("<edc:CodeSector") != std::string::npos) {
            std::string beginStr = extractAttribute(line, "edc:beginaddr");
            std::string endStr = extractAttribute(line, "edc:endaddr");

            if (!beginStr.empty() && !endStr.empty()) {
                codeBegin = parseHex(beginStr);
                codeEnd = parseHex(endStr);

                // Calculate program memory in WORDS
                // For PIC16: addresses are in words, so difference is word count
                // For PIC18: addresses are in bytes, so divide by 2
                if (archStr.find("18") != std::string::npos) {
                    dev.programWords = (codeEnd - codeBegin) / 2;
                } else {
                    dev.programWords = codeEnd - codeBegin;
                }
            }
        }

        // Extract data memory from DataSpace
        if (line.find("<edc:DataSpace") != std::string::npos) {
            std::string endStr = extractAttribute(line, "edc:endaddr");
            if (!endStr.empty()) {
                dataEnd = parseHex(endStr);
                // Data space end address gives us RAM size
                // This includes SFRs, so actual GPR is less, but this is total
                dev.dataBytes = dataEnd;
                if (dev.dataBytes > 16384) dev.dataBytes = 4096; // Sanity check
            }
        }

        // Check for EEPROM
        if (line.find("<edc:EEDataSector") != std::string::npos ||
            line.find("eeprom") != std::string::npos ||
            line.find("EEPROM") != std::string::npos) {
            hasEEData = true;
        }
    }

    // Estimate EEPROM based on device family if we detected it exists
    if (hasEEData) {
        if (dev.name.find("PIC18") == 0) {
            dev.eepromBytes = 256; // Most PIC18 have 256 bytes
            if (dev.programWords > 16384) dev.eepromBytes = 1024;
        } else if (dev.name.find("PIC16") == 0) {
            dev.eepromBytes = 256; // Most PIC16 have 256 bytes
            if (dev.programWords < 2048) dev.eepromBytes = 128;
        } else {
            dev.eepromBytes = 0; // PIC12 mostly don't have EEPROM
        }
    } else {
        dev.eepromBytes = 0;
    }

    dev.architecture = inferArchitecture(archStr, dev.name);
    dev.found = !dev.name.empty() && dev.programWords > 0;

    return dev;
}

int main(int argc, char* argv[]) {
    std::string baseDir = ".";
    std::string outputFile = "device_memory_specs_complete.txt";

    if (argc >= 2) baseDir = argv[1];
    if (argc >= 3) outputFile = argv[2];

    std::cout << "Scanning for Microchip DFP directories..." << std::endl;

    std::vector<DeviceMemory> devices;
    int filesProcessed = 0;

    // Find all .PIC files in DFP directories
    try {
        for (const auto& entry : fs::recursive_directory_iterator(baseDir)) {
            if (entry.is_regular_file() && entry.path().extension() == ".PIC") {
                DeviceMemory dev = parsePICFile(entry.path().string());
                if (dev.found) {
                    devices.push_back(dev);
                    filesProcessed++;
                    if (filesProcessed % 100 == 0) {
                        std::cout << "Processed " << filesProcessed << " devices..." << std::endl;
                    }
                }
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\nTotal devices found: " << devices.size() << std::endl;

    // Sort by name
    std::sort(devices.begin(), devices.end(),
        [](const DeviceMemory& a, const DeviceMemory& b) {
            return a.name < b.name;
        });

    // Write output file
    std::ofstream out(outputFile);
    if (!out.is_open()) {
        std::cerr << "Cannot create output file: " << outputFile << std::endl;
        return 1;
    }

    out << "# PIC Device Memory Specifications - Auto-generated from Microchip DFP files\n";
    out << "# Format: DEVICE_NAME, PROGRAM_MEMORY_WORDS, DATA_MEMORY_BYTES, EEPROM_BYTES, ARCHITECTURE\n";
    out << "#\n";
    out << "# Program memory is specified in WORDS (14-bit for PIC16, 16-bit for PIC18)\n";
    out << "# The assembler will convert words to bytes (words * 2)\n";
    out << "#\n";
    out << "# Generated from: Microchip Device Family Pack (DFP) .PIC files\n";
    out << "# Total devices: " << devices.size() << "\n\n";

    for (const auto& dev : devices) {
        out << dev.name << ", "
            << dev.programWords << ", "
            << dev.dataBytes << ", "
            << dev.eepromBytes << ", "
            << dev.architecture << "\n";
    }

    out.close();

    std::cout << "Generated " << outputFile << " with " << devices.size() << " devices" << std::endl;
    std::cout << "\nNext steps:" << std::endl;
    std::cout << "1. Review " << outputFile << " for accuracy" << std::endl;
    std::cout << "2. Copy to device_memory_specs.txt or merge with existing" << std::endl;
    std::cout << "3. Run: ./tools/generate_device_specs" << std::endl;
    std::cout << "4. Rebuild: cmake --build build --target gnsasm --config Release" << std::endl;

    return 0;
}

