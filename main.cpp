#include "src/cli.h"
#include "src/assembler.h"
#include "src/hex_generator.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, const char* argv[]) {
    CommandLineInterface cli;
    CLIOptions options = cli.parseArguments(argc, argv);

    if (options.showHelp) {
        cli.printHelp();
        return 0;
    }

    if (options.showVersion) {
        cli.printVersion();
        return 0;
    }

    if (options.inputFile.empty()) {
        cli.printError("No input file specified");
        cli.printHelp();
        return 1;
    }

    try {
        // Read source file
        if (options.verbose) {
            std::cout << "Reading: " << options.inputFile << "\n";
            std::cout << "Target: " << (options.architecture == Architecture::PIC16 ? "PIC16" : "PIC18") << "\n";
        }
        std::string source = readFile(options.inputFile);

        // Assemble
        if (options.verbose) {
            std::cout << "Assembling...\n";
        }
        Assembler assembler(options.architecture);
        std::vector<AssembledCode> code = assembler.assemble(source);

        if (!assembler.wasSuccessful()) {
            cli.printError(assembler.getLastError());

            // Display detailed error report
            if (auto errors = assembler.getErrors()) {
                errors->printReport(std::cerr);
            }
            return 1;
        }

        // Determine output filename
        std::string outputFile = options.outputFile;
        if (outputFile.empty()) {
            outputFile = options.inputFile;
            size_t dotPos = outputFile.find_last_of('.');
            if (dotPos != std::string::npos) {
                outputFile = outputFile.substr(0, dotPos);
            }
            outputFile += ".hex";
        }

        // Generate HEX file
        if (options.verbose) {
            std::cout << "Generating HEX: " << outputFile << "\n";
        }
        HexGenerator hexGen;
        if (!hexGen.writeToFile(outputFile, code)) {
            cli.printError(hexGen.getLastError());
            return 1;
        }

        // Print statistics on successful assembly
        assembler.printStatistics();
        std::cout << "\n";

        return 0;

    } catch (const std::exception& e) {
        cli.printError(e.what());
        return 1;
    }
}
