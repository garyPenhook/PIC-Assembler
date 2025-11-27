#include "assembler.h"
#include "lexer.h"
#include "parser.h"
#include "instruction.h"
#include "device_specs.h"
#include <iostream>
#include <memory>
#include <iomanip>

Assembler::Assembler(Architecture arch)
    : successful(false), targetArch(arch), lastErrors(std::make_shared<ErrorReporter>()) {
    // Set the architecture in the instruction set
    InstructionSet::getInstance().setArchitecture(arch);
}

std::vector<AssembledCode> Assembler::assemble(const std::string& source) {
    generatedCode.clear();
    generatedData.clear();
    successful = false;

    try {
        // Validate input
        if (source.empty()) {
            throw AssemblyException("Source code is empty");
        }

        try {
            // Lexical analysis
            Lexer lexer(source);
            std::vector<Token> tokens = lexer.tokenize();

            if (tokens.empty()) {
                throw LexerException(1, 1, "No tokens generated from source");
            }

            // Parsing
            Parser parser(tokens, targetArch);
            std::vector<ParsedInstruction> instructions = parser.parse();

            // Capture parser errors
            lastErrors = std::make_shared<ErrorReporter>(parser.getErrorReporter());

            // Check for parser errors
            if (parser.getErrorReporter().hasErrors()) {
                setError("Parsing failed with " + std::to_string(parser.getErrorReporter().getErrorCount()) + " error(s)");
                return {};
            }

            // Store data definitions from parser
            generatedData = parser.getDataDefinitions();

            // Code generation
            InstructionSet& iset = InstructionSet::getInstance();

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

    DeviceSpec spec = DeviceSpecs::getDeviceSpec(targetArch);
    uint32_t progMemUsed = getProgramMemoryUsed();
    double progMemPercent = getProgramMemoryPercentage();

    std::cout << "Assembly Statistics:\n";
    std::cout << "  Device: " << spec.name << "\n";
    std::cout << "  Total instructions: " << generatedCode.size() << "\n";
    if (generatedCode.size() > 0) {
        std::cout << "  Address range: 0x" << std::hex << generatedCode.front().address
                  << " - 0x" << generatedCode.back().address << std::dec << "\n";
    }
    std::cout << "  Program Memory: " << progMemUsed << " bytes / " << spec.programMemoryBytes
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
    return DeviceSpecs::getDeviceSpec(targetArch).programMemoryBytes;
}

uint32_t Assembler::getDataMemoryUsed() const {
    // Current version doesn't track data memory usage
    return 0;
}

uint32_t Assembler::getDataMemoryTotal() const {
    return DeviceSpecs::getDeviceSpec(targetArch).dataMemoryBytes;
}

uint32_t Assembler::getEEPROMTotal() const {
    return DeviceSpecs::getDeviceSpec(targetArch).eepromBytes;
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
