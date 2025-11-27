#include "cli.h"
#include <iostream>
#include <algorithm>

CLIOptions CommandLineInterface::parseArguments(int argc, const char* argv[]) {
    options = {};

    if (argc < 2) {
        options.showHelp = true;
        return options;
    }

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            options.showHelp = true;
        } else if (arg == "-v" || arg == "--version") {
            options.showVersion = true;
        } else if (arg == "-o" || arg == "--output") {
            if (i + 1 < argc) {
                options.outputFile = argv[++i];
            } else {
                printError("Option " + arg + " requires an argument");
            }
        } else if (arg == "-a" || arg == "--arch") {
            if (i + 1 < argc) {
                std::string archStr = argv[++i];
                if (archStr == "pic16" || archStr == "PIC16") {
                    options.architecture = Architecture::PIC16;
                } else if (archStr == "pic18" || archStr == "PIC18") {
                    options.architecture = Architecture::PIC18;
                } else {
                    printError("Unknown architecture: " + archStr);
                }
            } else {
                printError("Option " + arg + " requires an argument");
            }
        } else if (arg == "-l" || arg == "--listing") {
            options.generateListing = true;
        } else if (arg == "--verbose") {
            options.verbose = true;
        } else if (arg[0] == '-') {
            printError("Unknown option: " + arg);
        } else {
            // Input file
            if (options.inputFile.empty()) {
                options.inputFile = arg;
            } else {
                printError("Multiple input files not supported");
            }
        }
    }

    return options;
}

void CommandLineInterface::printHelp() {
    std::cout << R"(
PIC16/PIC18 Assembler v1.1
Microchip PIC Assembler with MPASM-compatible syntax

Usage: pic-assembler [options] input.asm

Options:
  -a, --arch ARCH      Target architecture: pic16 or pic18 (default: pic16)
  -o, --output FILE    Output file (default: input.hex)
  -l, --listing        Generate listing file
  --verbose            Show detailed assembly information
  -h, --help           Display this help message
  -v, --version        Display version information

Supported Architectures:
  pic16    PIC16 and PIC16F microcontrollers (14-bit instructions)
  pic18    PIC18 and PIC18-Q40 microcontrollers (16-bit instructions)

Examples:
  pic-assembler program.asm
  pic-assembler program.asm -a pic18
  pic-assembler program.asm -o program.hex
  pic-assembler program.asm -a pic18 -o program.hex --listing

)";
}

void CommandLineInterface::printVersion() {
    std::cout << "PIC16/PIC18 Assembler v1.0\n";
    std::cout << "Target: PIC16F18076 and compatible devices\n";
}

void CommandLineInterface::printError(const std::string& message) {
    std::cerr << "Error: " << message << "\n";
}
