#include "assembler.h"
#include "lexer.h"
#include "parser.h"
#include "instruction.h"
#include <iostream>
#include <memory>

Assembler::Assembler(Architecture arch)
    : successful(false), targetArch(arch), lastErrors(std::make_shared<ErrorReporter>()) {
    // Set the architecture in the instruction set
    InstructionSet::getInstance().setArchitecture(arch);
}

std::vector<AssembledCode> Assembler::assemble(const std::string& source) {
    generatedCode.clear();
    successful = false;

    try {
        // Lexical analysis
        Lexer lexer(source);
        std::vector<Token> tokens = lexer.tokenize();

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

        // Code generation
        InstructionSet& iset = InstructionSet::getInstance();

        for (const auto& parsed : instructions) {
            uint16_t opcode = iset.encodeInstruction(parsed.type, parsed.f_reg,
                                                     parsed.d_bit, parsed.b_bit,
                                                     parsed.k_value);

            AssembledCode code{};
            code.address = parsed.address;
            code.instruction = opcode;
            code.sourceCode = parsed.mnemonic + " " + parsed.mnemonic;
            code.lineNumber = parsed.line_number;

            generatedCode.push_back(code);
        }

        successful = true;
        return generatedCode;

    } catch (const ParseError& e) {
        setError("Parse Error at line " + std::to_string(e.getLine()) + ": " + e.getMessage());
        return {};
    } catch (const std::exception& e) {
        std::string errorMsg = e.what();
        setError("Assembly Error: " + errorMsg);
        return {};
    }
}

void Assembler::setError(const std::string& error) {
    lastError = error;
    successful = false;
}

void Assembler::printStatistics() const {
    std::cout << "Assembly Statistics:\n";
    std::cout << "  Total instructions: " << generatedCode.size() << "\n";
    if (generatedCode.size() > 0) {
        std::cout << "  Address range: 0x" << std::hex << generatedCode.front().address
                  << " - 0x" << generatedCode.back().address << std::dec << "\n";
    }
    if (!successful) {
        std::cout << "  Status: FAILED\n";
        std::cout << "  Error: " << lastError << "\n";
    } else {
        std::cout << "  Status: SUCCESS\n";
    }
}
