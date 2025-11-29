#include "assembler.h"
#include "lexer.h"
#include "parser.h"
#include "instruction.h"
#include "device_specs.h"
#include <iostream>
#include <memory>
#include <iomanip>
#include <regex>
#include <fstream>
#include <sstream>
#include <map>

Assembler::Assembler(Architecture arch)
    : successful(false), targetArch(arch), lastErrors(std::make_shared<ErrorReporter>()) {
    // Set the architecture in the instruction set
    InstructionSet::getInstance().setArchitecture(arch);
    // Initialize with default device spec for the architecture
    currentDeviceSpec = DeviceSpecs::getDeviceSpec(arch);
}

std::vector<AssembledCode> Assembler::assemble(const std::string& source) {
    generatedCode.clear();
    generatedData.clear();
    configWords.clear();
    successful = false;

    try {
        // Validate input
        if (source.empty()) {
            throw AssemblyException("Source code is empty");
        }

        try {
            // Preprocessing stage - process #define, #ifdef, #include, etc.
            Preprocessor preprocessor(".");
            std::string preprocessedSource = preprocessor.process(source, "assembly.asm");

            // Check for preprocessing errors
            if (!preprocessor.wasSuccessful()) {
                lastErrors = std::make_shared<ErrorReporter>(preprocessor.getErrors());
                setError("Preprocessing failed with " + std::to_string(preprocessor.getErrors().getErrorCount()) + " error(s)");
                return {};
            }

            // Lexical analysis
            Lexer lexer(preprocessedSource);
            std::vector<Token> tokens = lexer.tokenize();

            if (tokens.empty()) {
                throw LexerException(1, 1, "No tokens generated from source");
            }

            // Pre-load device registers from included .inc files
            // Scan original source for #include directives (both <*.inc> and "*.inc" formats)
            // This is done BEFORE creating the parser so we can pass the detected device to it
            std::regex includeRegex(R"(#include\s*[<"]([^>"]+\.inc)[>"])", std::regex_constants::icase);
            std::smatch match;
            std::string searchSource = source;
            while (std::regex_search(searchSource, match, includeRegex)) {
                std::string incFile = match[1].str();

                // Extract device name from include filename and auto-detect device
                std::string deviceName = DeviceSpecs::extractDeviceNameFromIncFile(incFile);
                auto deviceSpec = DeviceSpecs::getDeviceSpecByName(deviceName);
                if (deviceSpec) {
                    // Update current device spec based on #include
                    currentDeviceSpec = deviceSpec.value();
                    // Also update target architecture if inferred from device name
                    auto inferredArch = DeviceSpecs::inferArchitectureFromDeviceName(deviceName);
                    if (inferredArch) {
                        targetArch = inferredArch.value();
                        InstructionSet::getInstance().setArchitecture(targetArch);
                    }
                }

                searchSource = match.suffix().str();
            }

            // Parsing
            Parser parser(tokens, targetArch);
            // Sync the auto-detected device spec to the parser
            parser.setDeviceSpec(currentDeviceSpec);

            // Now load device registers from included .inc files
            searchSource = source;
            while (std::regex_search(searchSource, match, includeRegex)) {
                std::string incFile = match[1].str();
                parser.loadDeviceRegistersFromFile("device_includes/" + incFile);
                searchSource = match.suffix().str();
            }

            std::vector<ParsedInstruction> instructions = parser.parse();

            // Capture parser errors
            lastErrors = std::make_shared<ErrorReporter>(parser.getErrorReporter());

            // Check for parser errors
            if (parser.getErrorReporter().hasErrors()) {
                setError("Parsing failed with " + std::to_string(parser.getErrorReporter().getErrorCount()) + " error(s)");
                return {};
            }

            // Sync device spec from parser (may have been updated by PROCESSOR directive)
            currentDeviceSpec = parser.getDeviceSpec();

            // Sync architecture from parser (may have been updated by PROCESSOR directive)
            Architecture parserArch = parser.getArchitecture();
            if (parserArch != targetArch) {
                targetArch = parserArch;
                InstructionSet::getInstance().setArchitecture(targetArch);
            }

            // Store data definitions from parser
            generatedData = parser.getDataDefinitions();

            // Store configuration words from parser
            configWords = parser.getConfigWords();

            // Code generation
            InstructionSet& iset = InstructionSet::getInstance();

            // Reserve capacity to avoid reallocations
            generatedCode.reserve(instructions.size());

            for (const auto& parsed : instructions) {
                try {
                    uint16_t opcode = iset.encodeInstruction(parsed.type, parsed.f_reg,
                                                             parsed.d_bit, parsed.b_bit,
                                                             parsed.k_value);

                    AssembledCode code{};
                    code.address = parsed.address;
                    code.instruction = opcode;
                    code.sourceCode = parsed.mnemonic + " " + parsed.mnemonic;
                    code.lineNumber = parsed.line_number;

                    generatedCode.push_back(code);
                } catch (const InstructionEncodingException&) {
                    throw;  // Re-throw
                } catch (const std::exception& e) {
                    throw CodeGenerationException(parsed.line_number,
                        "Failed to encode instruction '" + parsed.mnemonic + "': " + std::string(e.what()));
                }
            }

            successful = true;
            return generatedCode;

        } catch (const LexerException& e) {
            setError(e.what());
            return {};
        } catch (const ParseException& e) {
            setError(e.what());
            return {};
        } catch (const ValidationException& e) {
            setError(e.what());
            return {};
        } catch (const CodeGenerationException& e) {
            setError(e.what());
            return {};
        }

    } catch (const AssemblerException& e) {
        setError(e.what());
        return {};
    } catch (const std::bad_alloc&) {
        setError("Out of memory during assembly");
        return {};
    } catch (const std::exception& e) {
        std::string errorMsg = std::string("Unexpected error during assembly: ") + e.what();
        setError(errorMsg);
        return {};
    } catch (...) {
        setError("Unknown fatal error during assembly");
        return {};
    }
}

void Assembler::setError(const std::string& error) {
    lastError = error;
    successful = false;
}

void Assembler::printStatistics() const {
    if (!successful) {
        std::cout << "Assembly Statistics:\n";
        std::cout << "  Status: FAILED\n";
        std::cout << "  Error: " << lastError << "\n";
        return;
    }

    // Use the current device spec that may have been set by PROCESSOR or auto-detected
    const DeviceSpec& spec = currentDeviceSpec;
    uint32_t progMemUsed = getProgramMemoryUsed();
    uint32_t progMemTotal = getProgramMemoryTotal();
    double progMemPercent = (progMemTotal > 0) ? (progMemUsed * 100.0) / progMemTotal : 0.0;

    std::cout << "Assembly Statistics:\n";
    std::cout << "  Device: " << spec.name << "\n";
    std::cout << "  Total instructions: " << generatedCode.size() << "\n";
    if (!generatedCode.empty()) {
        std::cout << "  Address range: 0x" << std::hex << generatedCode.front().address
                  << " - 0x" << generatedCode.back().address << std::dec << "\n";
    }
    std::cout << "  Program Memory: " << progMemUsed << " bytes / " << progMemTotal
              << " bytes (" << std::fixed << std::setprecision(2) << progMemPercent << "%)\n";
    std::cout << "  Data Memory: 0 bytes / " << spec.dataMemoryBytes << " bytes (0.00%)\n";
    if (spec.eepromBytes > 0) {
        std::cout << "  EEPROM: 0 bytes / " << spec.eepromBytes << " bytes (0.00%)\n";
    }
    std::cout << "  Status: SUCCESS\n";
}

uint32_t Assembler::getProgramMemoryUsed() const {
    if (generatedCode.empty()) {
        return 0;
    }

    // Each instruction is 1 word (14-bit for PIC16, 16-bit for PIC18)
    // Calculate bytes based on instruction count
    // For PIC16: each instruction is 2 bytes (14-bit instruction in 14-bit word)
    // For PIC18: each instruction is 2 bytes (16-bit instruction in 16-bit word)
    return generatedCode.size() * 2;
}

uint32_t Assembler::getProgramMemoryTotal() const {
    return currentDeviceSpec.programMemoryBytes;
}

uint32_t Assembler::getDataMemoryUsed() const {
    // Current version doesn't track data memory usage
    return 0;
}

uint32_t Assembler::getDataMemoryTotal() const {
    return currentDeviceSpec.dataMemoryBytes;
}

uint32_t Assembler::getEEPROMTotal() const {
    return currentDeviceSpec.eepromBytes;
}

double Assembler::getProgramMemoryPercentage() const {
    uint32_t total = getProgramMemoryTotal();
    if (total == 0) return 0.0;
    return (getProgramMemoryUsed() * 100.0) / total;
}

double Assembler::getDataMemoryPercentage() const {
    uint32_t total = getDataMemoryTotal();
    if (total == 0) return 0.0;
    return (getDataMemoryUsed() * 100.0) / total;
}

bool Assembler::generateListFile(const std::string& filename, const std::string& sourceCode) const {
    try {
        std::ofstream file(filename);
        if (!file.is_open()) {
            return false;
        }

        // Split source code into lines for cross-reference with assembled code
        std::vector<std::string> sourceLines;
        std::istringstream iss(sourceCode);
        std::string line;
        while (std::getline(iss, line)) {
            sourceLines.push_back(line);
        }

        // Use the current device spec that may have been set by PROCESSOR or auto-detected
        const DeviceSpec& spec = currentDeviceSpec;

        // Header
        file << "================================================================================\n";
        file << "GNSASM PIC Assembler Listing File\n";
        file << "================================================================================\n\n";
        file << "Device: " << spec.name << "\n";
        file << "Architecture: ";
        if (targetArch == Architecture::PIC12) {
            file << "PIC12 (12-bit instructions)\n";
        } else if (targetArch == Architecture::PIC16) {
            file << "PIC16 (14-bit instructions)\n";
        } else {
            file << "PIC18 (16-bit instructions)\n";
        }
        file << "\n";

        // Assembly listing with source code
        file << "================================================================================\n";
        file << "ASSEMBLY LISTING\n";
        file << "================================================================================\n";
        file << "  Addr  |  Hex Code  | Source Code\n";
        file << "--------+----------+------------------------------------------------------------\n";

        // Create a map of line numbers to generated instructions for quick lookup
        std::map<int, const AssembledCode*> lineToCode;
        for (const auto& code : generatedCode) {
            lineToCode[code.lineNumber] = &code;
        }

        // Print all source lines with their corresponding generated code
        for (size_t i = 0; i < sourceLines.size(); ++i) {
            int lineNum = static_cast<int>(i + 1);

            // Check if this line has generated code
            auto it = lineToCode.find(lineNum);
            if (it != lineToCode.end()) {
                const AssembledCode& code = *it->second;
                file << std::hex << std::setfill('0');
                file << "  0x" << std::setw(4) << code.address << "  | ";
                file << "0x" << std::setw(4) << code.instruction << "   | ";
                file << std::dec << std::setfill(' ');
            } else {
                file << "        |           | ";
            }

            // Print source code
            file << sourceLines[i] << "\n";
        }

        file << "\n";

        // Symbol Table
        file << "================================================================================\n";
        file << "SYMBOL TABLE\n";
        file << "================================================================================\n";

        // Get symbol table from parser - we need to access it through the generated code
        // For now, we'll create a simple symbol listing from addresses in the code
        std::map<std::string, uint16_t> symbolMap;

        for (const auto& code : generatedCode) {
            if (!code.sourceCode.empty()) {
                // Try to extract label from source code
                std::string src = code.sourceCode;
                size_t colonPos = src.find(':');
                if (colonPos != std::string::npos) {
                    std::string label = src.substr(0, colonPos);
                    // Trim whitespace
                    label.erase(0, label.find_first_not_of(" \t"));
                    label.erase(label.find_last_not_of(" \t") + 1);
                    if (!label.empty()) {
                        symbolMap[label] = code.address;
                    }
                }
            }
        }

        if (!symbolMap.empty()) {
            file << "Name                          | Address  |  Value\n";
            file << "---------------------------+----------+--------\n";
            for (const auto& [name, addr] : symbolMap) {
                file << std::left << std::setw(30) << name << "| 0x"
                     << std::hex << std::setfill('0') << std::setw(6) << addr << "   | ";
                file << "0x" << std::setw(4) << addr << "\n";
                file << std::setfill(' ');
            }
        } else {
            file << "(No symbols defined)\n";
        }

        file << "\n";

        // Memory Usage Summary
        file << "================================================================================\n";
        file << "MEMORY USAGE\n";
        file << "================================================================================\n";
        file << "Program Memory: " << getProgramMemoryUsed() << " bytes / "
             << spec.programMemoryBytes << " bytes ("
             << std::fixed << std::setprecision(2) << getProgramMemoryPercentage() << "%)\n";
        file << "Data Memory:    " << getDataMemoryUsed() << " bytes / "
             << spec.dataMemoryBytes << " bytes ("
             << std::fixed << std::setprecision(2) << getDataMemoryPercentage() << "%)\n";
        if (spec.eepromBytes > 0) {
            file << "EEPROM:         0 bytes / " << spec.eepromBytes << " bytes (0.00%)\n";
        }
        file << "\n";

        // Statistics
        file << "================================================================================\n";
        file << "ASSEMBLY STATISTICS\n";
        file << "================================================================================\n";
        file << "Total Instructions: " << generatedCode.size() << "\n";
        if (!generatedCode.empty()) {
            file << "Address Range:      0x" << std::hex << std::setfill('0')
                 << std::setw(4) << generatedCode.front().address << " - 0x"
                 << std::setw(4) << generatedCode.back().address << "\n";
        }
        file << "Total Data Items:   " << generatedData.size() << "\n";
        file << "Config Words:       " << configWords.size() << "\n";
        file << "\n";

        if (!successful) {
            file << "Assembly Status: FAILED\n";
            if (!lastError.empty()) {
                file << "Error: " << lastError << "\n";
            }
        } else {
            file << "Assembly Status: SUCCESS\n";
        }

        file << "\n================================================================================\n";
        file << "End of Listing\n";
        file << "================================================================================\n";

        file.close();
        return true;

    } catch (const std::exception& e) {
        std::cerr << "Error generating list file: " << e.what() << "\n";
        return false;
    }
}
