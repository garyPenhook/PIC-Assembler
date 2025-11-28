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
                if (archStr == "pic12" || archStr == "PIC12") {
                    options.architecture = Architecture::PIC12;
                } else if (archStr == "pic16" || archStr == "PIC16") {
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
        } else if (arg == "--devices") {
            options.showDevices = true;
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
gnsasm PIC Assembler v1.2
Microchip PIC Assembler with MPASM-compatible syntax

Usage: gnsasm [options] input.asm

Options:
  -a, --arch ARCH      Target architecture: pic16 or pic18 (default: pic16)
  -o, --output FILE    Output file (default: input.hex)
  -l, --listing        Generate listing file
  --verbose            Show detailed assembly information
  --devices            List all supported device configurations
  -h, --help           Display this help message
  -v, --version        Display version information

Supported Architectures:
  pic12    PIC12 baseline microcontrollers (12-bit instructions)
  pic16    PIC16 and PIC16F microcontrollers (14-bit instructions)
  pic18    PIC18 and PIC18-Q40 microcontrollers (16-bit instructions)

Examples:
  gnsasm program.asm
  gnsasm program.asm -a pic18
  gnsasm program.asm -o program.hex
  gnsasm program.asm -a pic18 -o program.hex --listing
  gnsasm --devices

)";
}

void CommandLineInterface::printVersion() {
    std::cout << "gnsasm PIC Assembler v1.2\n";
    std::cout << "Supports: PIC12, PIC16, and PIC18 architectures\n";
}

void CommandLineInterface::printDevices() {
    std::cout << R"(
Supported Device Configurations
================================

PIC12 Architecture (12-bit instructions, -a pic12):
  PIC12F508    512 words Flash, 25 bytes RAM, 6 I/O pins
  PIC12F509    1K words Flash, 41 bytes RAM, 6 I/O pins
  PIC12F510    1K words Flash, 38 bytes RAM, 6 I/O pins
  PIC12F675    1K words Flash, 64 bytes RAM, 6 I/O pins, 4-ch ADC
  PIC12F683    2K words Flash, 128 bytes RAM, 6 I/O pins, 4-ch ADC

PIC16 Architecture (14-bit instructions, -a pic16):
  PIC16F84A    1K words Flash, 68 bytes RAM, 13 I/O pins (classic)
  PIC16F628A   2K words Flash, 224 bytes RAM, 16 I/O pins, USART
  PIC16F88     4K words Flash, 368 bytes RAM, 16 I/O pins, USART
  PIC16F684    2K words Flash, 128 bytes RAM, 12 I/O pins, ADC
  PIC16F690    4K words Flash, 256 bytes RAM, 18 I/O pins, ADC, EUSART
  PIC16F877A   8K words Flash, 368 bytes RAM, 33 I/O pins, ADC, USART (popular)
  PIC16F1827   4K words Flash, 384 bytes RAM, 16 I/O pins, enhanced, EUSART
  PIC16F1847   8K words Flash, 1024 bytes RAM, 16 I/O pins, enhanced
  PIC16F18076  28K words Flash, 4096 bytes RAM, 25 I/O pins, modern

Enhanced Mid-Range (14-bit enhanced, -a pic16):
  PIC12F1840   4K words Flash, 256 bytes RAM, 6 I/O pins, 32MHz, EUSART
  PIC16F1827   4K words Flash, 384 bytes RAM, 16 I/O pins, 32MHz, I2C, EUSART
  PIC16F1847   8K words Flash, 1024 bytes RAM, 16 I/O pins, 32MHz

PIC18 Architecture (16-bit instructions, -a pic18):
  PIC18F14K50  16K bytes Flash, 768 bytes RAM, 18 I/O pins, USB
  PIC18F2550   32K bytes Flash, 2K bytes RAM, 24 I/O pins, USB
  PIC18F4550   32K bytes Flash, 2K bytes RAM, 35 I/O pins, USB
  PIC18F45K20  32K bytes Flash, 1536 bytes RAM, 35 I/O pins
  PIC18F-Q40   32K bytes Flash, 2K bytes RAM, modern Q-series

Notes:
  - All devices support standard instruction set for their architecture
  - Memory sizes are approximate; check datasheet for exact specifications
  - Enhanced mid-range devices have additional instructions and features
  - Use GitHub Copilot reference files in .github/copilot-examples/ for register definitions

For detailed register addresses and peripheral setup, see:
  .github/copilot-examples/pic<device>-registers.asm

Example usage:
  gnsasm program.asm -a pic16     # For PIC16F628A, PIC16F877A, etc.
  gnsasm program.asm -a pic18     # For PIC18F series
  gnsasm program.asm -a pic12     # For PIC12F series

)";
}

void CommandLineInterface::printError(const std::string& message) {
    std::cerr << "Error: " << message << "\n";
}
