#include "src/cli.h"
#include "src/assembler.h"
#include "src/hex_generator.h"
#include "src/exceptions.h"
#include <iostream>
#include <fstream>
#include <sstream>

/**
 * Read assembly source file
 * @param filename Path to the file to read
 * @return File contents as string
 * @throws FileNotFoundException if file doesn't exist
 * @throws FileReadException if read operation fails
 */
std::string readFile(const std::string& filename) {
    if (filename.empty()) {
        throw InvalidPathException("<empty filename>");
    }

    try {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw FileNotFoundException(filename);
        }

        std::stringstream buffer;
        try {
            buffer << file.rdbuf();
            if (!buffer.good() && file.fail()) {
                throw FileReadException(filename, "failed to read file contents");
            }
        } catch (const std::ios_base::failure& e) {
            throw FileReadException(filename, std::string(e.what()));
        }

        return buffer.str();
    } catch (const FileException&) {
        throw;  // Re-throw our exceptions
    } catch (const std::exception& e) {
        throw FileReadException(filename, std::string(e.what()));
    }
}

int main(int argc, const char* argv[]) {
    try {
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
                std::string archName = (options.architecture == Architecture::PIC12) ? "PIC12" :
                                       (options.architecture == Architecture::PIC16) ? "PIC16" : "PIC18";
                std::cout << "Target: " << archName << "\n";
            }

            std::string source;
            try {
                source = readFile(options.inputFile);
            } catch (const FileNotFoundException& e) {
                cli.printError(e.what());
                return 1;
            } catch (const FileReadException& e) {
                cli.printError(e.what());
                return 1;
            } catch (const FileException& e) {
                cli.printError(e.what());
                return 1;
            }

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

            try {
                HexGenerator hexGen(options.architecture);
                if (!hexGen.writeToFile(outputFile, code, assembler.getDataDefinitions())) {
                    cli.printError(hexGen.getLastError());
                    return 1;
                }
            } catch (const FileException& e) {
                cli.printError(e.what());
                return 1;
            } catch (const HexGenerationException& e) {
                cli.printError(e.what());
                return 1;
            }

            // Print statistics on successful assembly
            assembler.printStatistics();
            std::cout << "\n";

            return 0;

        } catch (const AssemblerException& e) {
            cli.printError(e.what());
            return 1;
        } catch (const std::bad_alloc&) {
            cli.printError("Fatal Error: Out of memory");
            return 1;
        } catch (const std::exception& e) {
            cli.printError(std::string("Unexpected error: ") + e.what());
            return 1;
        }

    } catch (const std::bad_alloc&) {
        std::cerr << "FATAL: Out of memory\n";
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "FATAL: " << e.what() << "\n";
        return 1;
    } catch (...) {
        std::cerr << "FATAL: Unknown error occurred\n";
        return 1;
    }
}
