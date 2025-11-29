/**
 * Extract Device Specifications from Microchip Device Packs
 *
 * This tool parses .PIC files from Microchip device packs to extract
 * accurate memory specifications for each PIC microcontroller.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

struct DeviceMemorySpec {
    std::string name;
    uint32_t programMemoryWords;   // Program memory in words
    uint32_t programMemoryBytes;   // Program memory in bytes
    uint32_t dataMemoryBytes;      // Data RAM in bytes
    uint32_t eepromBytes;          // EEPROM in bytes
    std::string architecture;      // PIC12, PIC16, or PIC18
    bool found;
};

// Parse a .PIC file to extract memory specifications
DeviceMemorySpec parsePICFile(const std::string& filePath) {
    DeviceMemorySpec spec;
    spec.found = false;
    spec.programMemoryWords = 0;
    spec.programMemoryBytes = 0;
    spec.dataMemoryBytes = 0;
    spec.eepromBytes = 0;

    std::ifstream file(filePath);
    if (!file.is_open()) {
        return spec;
    }

    std::string line;
    std::string deviceName;

    // Extract device name from filename
    fs::path p(filePath);
    deviceName = p.stem().string();
    std::transform(deviceName.begin(), deviceName.end(), deviceName.begin(), ::toupper);

    while (std::getline(file, line)) {
        // Look for memory specifications in the .PIC file
        // Format varies but typically includes:
        // - ProgramMemory
        // - DataMemory
        // - EEPROMMemory

        if (line.find("ProgramMemory") != std::string::npos) {
            // Extract program memory size
            std::regex numRegex(R"(\d+)");
            std::smatch match;
            if (std::regex_search(line, match, numRegex)) {
                spec.programMemoryWords = std::stoul(match[0].str());
                spec.programMemoryBytes = spec.programMemoryWords * 2; // Words to bytes
            }
        }

        if (line.find("DataMemory") != std::string::npos || line.find("GPRMemory") != std::string::npos) {
            std::regex numRegex(R"(\d+)");
            std::smatch match;
            if (std::regex_search(line, match, numRegex)) {
                spec.dataMemoryBytes = std::stoul(match[0].str());
            }
        }

        if (line.find("EEPROMMemory") != std::string::npos || line.find("EEPROM") != std::string::npos) {
            std::regex numRegex(R"(\d+)");
            std::smatch match;
            if (std::regex_search(line, match, numRegex)) {
                spec.eepromBytes = std::stoul(match[0].str());
            }
        }
    }

    spec.name = deviceName;
    spec.found = (spec.programMemoryBytes > 0);

    // Infer architecture from device name
    if (deviceName.find("PIC18") == 0) {
        spec.architecture = "PIC18";
    } else if (deviceName.find("PIC16") == 0) {
        spec.architecture = "PIC16";
    } else if (deviceName.find("PIC12") == 0 || deviceName.find("PIC10") == 0) {
        spec.architecture = "PIC12";
    } else {
        spec.architecture = "PIC16"; // Default
    }

    return spec;
}

// Generate C++ header file with device specifications
void generateHeaderFile(const std::map<std::string, DeviceMemorySpec>& specs, const std::string& outputFile) {
    std::ofstream out(outputFile);
    if (!out.is_open()) {
        std::cerr << "Error: Cannot create output file: " << outputFile << std::endl;
        return;
    }

    out << "// Auto-generated device specifications\n";
    out << "// Generated from Microchip Device Packs\n";
    out << "#pragma once\n\n";
    out << "#include \"device_specs.h\"\n\n";
    out << "namespace DeviceSpecs {\n\n";

    for (const auto& [name, spec] : specs) {
        if (!spec.found) continue;

        out << "    static constexpr DeviceSpec " << spec.name << "_SPEC{\n";
        out << "        \"" << spec.name << "\",\n";
        out << "        " << spec.programMemoryBytes << ",      // program memory ("
            << spec.programMemoryWords << " words)\n";
        out << "        " << spec.dataMemoryBytes << ",       // data memory\n";
        out << "        " << spec.eepromBytes << ",     // EEPROM\n";
        out << "        Architecture::" << spec.architecture << "\n";
        out << "    };\n\n";
    }

    out << "}\n";
    out.close();

    std::cout << "Generated " << specs.size() << " device specifications\n";
    std::cout << "Output: " << outputFile << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <device_pack_directory> [output_file]\n";
        std::cerr << "Example: " << argv[0] << " /path/to/device/packs device_specs_generated.h\n";
        return 1;
    }

    std::string packDir = argv[1];
    std::string outputFile = (argc >= 3) ? argv[2] : "device_specs_generated.h";

    if (!fs::exists(packDir)) {
        std::cerr << "Error: Directory not found: " << packDir << std::endl;
        return 1;
    }

    std::map<std::string, DeviceMemorySpec> specs;
    int filesProcessed = 0;

    // Recursively search for .PIC files
    for (const auto& entry : fs::recursive_directory_iterator(packDir)) {
        if (entry.is_regular_file() && entry.path().extension() == ".PIC") {
            DeviceMemorySpec spec = parsePICFile(entry.path().string());
            if (spec.found) {
                specs[spec.name] = spec;
                filesProcessed++;
                if (filesProcessed % 100 == 0) {
                    std::cout << "Processed " << filesProcessed << " devices...\n";
                }
            }
        }
    }

    std::cout << "\nProcessed " << filesProcessed << " .PIC files\n";
    std::cout << "Found specifications for " << specs.size() << " devices\n";

    if (specs.empty()) {
        std::cerr << "Warning: No device specifications found\n";
        std::cerr << "Make sure the directory contains .PIC files from Microchip device packs\n";
        return 1;
    }

    generateHeaderFile(specs, outputFile);

    return 0;
}

