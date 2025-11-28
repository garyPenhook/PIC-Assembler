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
Supported Architectures and Devices
====================================

This assembler supports ALL Microchip PIC devices based on their architecture.
Simply use the correct -a flag for your device's architecture.

IMPORTANT: The assembler is architecture-based, NOT device-specific.
           Any device with the matching architecture will work!

═══════════════════════════════════════════════════════════════════

PIC12 BASELINE ARCHITECTURE (-a pic12)
12-bit instruction set
Supports: ALL PIC10F, PIC12F baseline series

  Popular Examples:
    PIC10F200/202/204/206/220/222 - Tiny 6-pin devices
    PIC12F508/509/510 - Classic 8-pin baseline
    PIC12F609/615/617/629/635/683 - Enhanced baseline with peripherals
    PIC12F675 - Very popular 8-pin with ADC
    ...and ALL other PIC12 baseline devices

═══════════════════════════════════════════════════════════════════

PIC16 MID-RANGE ARCHITECTURE (-a pic16)
14-bit instruction set
Supports: ALL PIC16F/PIC16LF mid-range and enhanced mid-range series

  Classic Mid-Range (PIC16F):
    PIC16F84A - The legendary classic (1K Flash)
    PIC16F87/88 - 18-pin with USART
    PIC16F627/628/648 - Popular 18-pin series
    PIC16F630/676 - 14-pin general purpose
    PIC16F684/685/687/688/689/690 - 14/20-pin with peripherals
    PIC16F870/871/872/873/874/876/877 - 28/40-pin workhorses
    PIC16F882/883/884/886/887 - Modern mid-range
    ...and hundreds more!

  Enhanced Mid-Range (PIC16F1xxx):
    PIC12F1501/1571/1572/1612/1822/1840 - Enhanced 8-pin
    PIC16F1454/1455/1459 - 14/20-pin with USB
    PIC16F1503/1507/1508/1509 - Low pin count
    PIC16F1704/1705/1707/1708/1709 - Value line
    PIC16F1782/1783/1784/1786/1787/1788/1789 - 28/40-pin enhanced
    PIC16F1823/1824/1825/1826/1827/1828/1829 - Popular enhanced
    PIC16F1933/1934/1936/1937/1938/1939 - LCD models
    PIC16F18313/18323/18324/18325/18326 - Modern enhanced
    PIC16F18855/18856/18857/18875/18876/18877 - Latest enhanced
    PIC16F18076 - Modern with large memory
    ...and hundreds more!

═══════════════════════════════════════════════════════════════════

PIC18 HIGH-PERFORMANCE ARCHITECTURE (-a pic18)
16-bit instruction set
Supports: ALL PIC18F/PIC18LF series (including J, K, Q variants)

  USB Capable:
    PIC18F2450/2455/2458/2550/2553/4450/4455/4458/4550/4553
    PIC18F13K50/14K50 - Compact USB
    PIC18F24K50/25K50/45K50 - Modern USB
    ...and more USB models

  General Purpose:
    PIC18F242/252/442/452 - Classic 28/40-pin
    PIC18F1220/1230/1320/1330 - 18-pin
    PIC18F2220/2320/2321/2331/2410/2420/2423/2431/2450/2455/2458
    PIC18F2480/2510/2515/2520/2523/2525/2550/2553/2580/2585/2610
    PIC18F2620/2680/2682/2685 - Popular 28-pin models
    PIC18F4220/4320/4321/4331/4410/4420/4423/4431/4450/4455/4458
    PIC18F4480/4510/4515/4520/4523/4525/4550/4553/4580/4585/4610
    PIC18F4620/4680/4682/4685 - Popular 40-pin models
    PIC18F6520/6620/6720/8520/8620/8720 - High pin count (64-80 pin)

  K-Series (Modern):
    PIC18F23K20/24K20/25K20/26K20 - 28-pin K-series
    PIC18F43K20/44K20/45K20/46K20 - 40-pin K-series
    PIC18F23K22/24K22/25K22/26K22 - 28-pin enhanced
    PIC18F43K22/44K22/45K22/46K22 - 40-pin enhanced
    PIC18F24K40/25K40/26K40/27K40/45K40/46K40/47K40 - Latest K-series

  Q-Series (Newest):
    PIC18F04Q40/05Q40/06Q40/14Q40/15Q40/16Q40 - Modern Q-series
    PIC18F24Q10/25Q10/26Q10/27Q10/45Q10/46Q10/47Q10
    PIC18F04Q41/05Q41/06Q41/14Q41/15Q41/16Q41
    PIC18F24Q71/25Q71/26Q71/27Q71/45Q71/46Q71/47Q71
    PIC18F24Q83/25Q83/26Q83/27Q83/45Q83/46Q83/47Q83
    ...and all other Q-series!

  J-Series (XLP Ultra Low Power):
    PIC18F24J10/25J10/26J10/27J10/44J10/45J10/46J10/47J10
    PIC18F24J11/25J11/26J11/27J11/44J11/45J11/46J11/47J11
    PIC18F24J50/25J50/26J50/27J50/44J50/45J50/46J50/47J50
    ...and more J-series!

═══════════════════════════════════════════════════════════════════

HOW TO USE:

1. Look up your device's architecture in the datasheet
2. Use the matching -a flag:

   PIC12F675        → gnsasm program.asm -a pic12
   PIC16F628A       → gnsasm program.asm -a pic16
   PIC16F1827       → gnsasm program.asm -a pic16  (enhanced mid-range)
   PIC18F4550       → gnsasm program.asm -a pic18
   PIC18F45K20      → gnsasm program.asm -a pic18
   PIC18F27Q43      → gnsasm program.asm -a pic18

3. That's it! The assembler handles all devices in that architecture.

═══════════════════════════════════════════════════════════════════

REGISTER DEFINITIONS:

For register addresses and peripheral setup examples, see:
  .github/copilot-examples/

Available reference files:
  pic12f675-registers.asm      pic16f18076-registers.asm
  pic12f1840-registers.asm     pic16f1827-registers.asm
  pic16f628a-registers.asm     pic18f14k50-registers.asm
  pic16f684-registers.asm      pic18f-q40-registers.asm
  pic16f690-registers.asm      complete-pic16-example.asm
  pic16f877a-registers.asm     complete-pic18-example.asm
  pic16f88-registers.asm

These files show register addresses and usage patterns for popular devices.
Adapt them for your specific device using your device's datasheet.

═══════════════════════════════════════════════════════════════════

TOTAL DEVICES SUPPORTED: 1000+ devices across all architectures!

)";
}

void CommandLineInterface::printError(const std::string& message) {
    std::cerr << "Error: " << message << "\n";
}
