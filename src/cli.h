#pragma once

#include <string>
#include <vector>
#include "instruction.h"

struct CLIOptions {
    std::string inputFile;
    std::string outputFile;
    Architecture architecture = Architecture::PIC16;
    bool verbose = false;
    bool generateListing = false;
    bool showHelp = false;
    bool showVersion = false;
};

class CommandLineInterface {
public:
    // Parse command line arguments
    CLIOptions parseArguments(int argc, const char* argv[]);

    // Display help message
    static void printHelp();

    // Display version
    static void printVersion();

    // Display error message
    static void printError(const std::string& message);

private:
    CLIOptions options;

    // Helper for parsing
    bool parseOption(const std::string& arg, const std::string& nextArg);
};
