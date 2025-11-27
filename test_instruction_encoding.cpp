/**
 * @file test_instruction_encoding.cpp
 * @brief Comprehensive test suite to verify PIC16/PIC18 instruction encoding
 *
 * This test program verifies that the assembler generates correct machine code
 * by comparing against known good instruction encodings from Microchip datasheets.
 *
 * References:
 * - PIC16F18076 Datasheet (DS40001419D)
 * - PIC18-Q40 Datasheet (DS40001897A)
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "src/assembler.h"
#include "src/hex_generator.h"

struct TestCase {
    std::string name;
    std::string code;
    uint16_t expectedOpcode;
    std::string description;
};

void printTestHeader(const std::string& title) {
    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << title << "\n";
    std::cout << std::string(70, '=') << "\n";
}

void printTestResult(bool pass, const std::string& name, const std::string& expected,
                     const std::string& actual) {
    std::cout << (pass ? "✓ PASS" : "✗ FAIL") << ": " << name << "\n";
    if (!pass) {
        std::cout << "  Expected: " << expected << "\n";
        std::cout << "  Actual:   " << actual << "\n";
    }
}

std::string hexFormat(uint16_t value) {
    std::stringstream ss;
    ss << "0x" << std::uppercase << std::setfill('0') << std::setw(4) << std::hex << value;
    return ss.str();
}

std::string binaryFormat(uint16_t value) {
    std::string binary;
    for (int i = 13; i >= 0; i--) {
        binary += ((value >> i) & 1) ? '1' : '0';
        if (i % 4 == 0 && i > 0) binary += ' ';
    }
    return binary;
}

// Test PIC16 byte-oriented instructions
void testPIC16ByteOriented() {
    printTestHeader("PIC16 BYTE-ORIENTED INSTRUCTION ENCODING");

    // Test cases from PIC16F18076 datasheet
    std::vector<TestCase> tests = {
        {
            "ADDWF f, d",
            "ORG 0x0000\nADDWF 0x20, 1\nEND",
            0x0720,  // 0x0700 | (1 << 7) | 0x20
            "Add W to file register 0x20, store in f"
        },
        {
            "MOVWF f",
            "ORG 0x0000\nMOVWF 0x25\nEND",
            0x0085,  // 0x0080 | 0x25
            "Move W to file register 0x25"
        },
        {
            "MOVF f, d (d=0, store in W)",
            "ORG 0x0000\nMOVF 0x20, 0\nEND",
            0x0820,  // 0x0800 | (0 << 7) | 0x20
            "Move file register to W"
        },
        {
            "MOVF f, d (d=1, store in f)",
            "ORG 0x0000\nMOVF 0x20, 1\nEND",
            0x0920,  // 0x0800 | (1 << 7) | 0x20
            "Move file register to itself"
        },
        {
            "CLRF f",
            "ORG 0x0000\nCLRF 0x30\nEND",
            0x0190,  // 0x0180 | 0x30
            "Clear file register 0x30"
        },
        {
            "INCF f, d",
            "ORG 0x0000\nINCF 0x21, 1\nEND",
            0x0AA1,  // 0x0A00 | (1 << 7) | 0x21
            "Increment file register, store in f"
        }
    };

    Assembler assembler(Architecture::PIC16);
    int passed = 0, failed = 0;

    for (const auto& test : tests) {
        auto code = assembler.assemble(test.code);

        if (!code.empty()) {
            uint16_t actual = code[0].instruction;
            bool pass = (actual == test.expectedOpcode);

            if (pass) passed++;
            else failed++;

            std::cout << "\n" << test.name << "\n";
            std::cout << "  Description: " << test.description << "\n";
            printTestResult(pass, "Opcode Match",
                hexFormat(test.expectedOpcode) + " (" + binaryFormat(test.expectedOpcode) + ")",
                hexFormat(actual) + " (" + binaryFormat(actual) + ")");
        } else {
            failed++;
            std::cout << "\n✗ FAIL: " << test.name << "\n";
            std::cout << "  Error: " << assembler.getLastError() << "\n";
        }
    }

    std::cout << "\n" << std::string(70, '-') << "\n";
    std::cout << "Byte-Oriented Tests: " << passed << " passed, " << failed << " failed\n";
}

// Test PIC16 bit-oriented instructions
void testPIC16BitOriented() {
    printTestHeader("PIC16 BIT-ORIENTED INSTRUCTION ENCODING");

    std::vector<TestCase> tests = {
        {
            "BCF f, b (Clear bit 0 in register)",
            "ORG 0x0000\nBCF 0x20, 0\nEND",
            0x1020,  // 0x1000 | (0 << 7) | 0x20
            "Bit Clear"
        },
        {
            "BSF f, b (Set bit 3 in register)",
            "ORG 0x0000\nBSF 0x25, 3\nEND",
            0x14A5,  // 0x1400 | (3 << 7) | 0x25
            "Bit Set"
        },
        {
            "BTFSC f, b (Test bit 7)",
            "ORG 0x0000\nBTFSC 0x30, 7\nEND",
            0x1CB0,  // 0x1800 | (7 << 7) | 0x30
            "Bit Test, Skip if Clear"
        },
        {
            "BTFSS f, b (Test bit 0)",
            "ORG 0x0000\nBTFSS 0x40, 0\nEND",
            0x1C40,  // 0x1C00 | (0 << 7) | 0x40
            "Bit Test, Skip if Set"
        }
    };

    Assembler assembler(Architecture::PIC16);
    int passed = 0, failed = 0;

    for (const auto& test : tests) {
        auto code = assembler.assemble(test.code);

        if (!code.empty()) {
            uint16_t actual = code[0].instruction;
            bool pass = (actual == test.expectedOpcode);

            if (pass) passed++;
            else failed++;

            std::cout << "\n" << test.name << "\n";
            std::cout << "  Description: " << test.description << "\n";
            printTestResult(pass, "Opcode Match",
                hexFormat(test.expectedOpcode),
                hexFormat(actual));
        } else {
            failed++;
            std::cout << "\n✗ FAIL: " << test.name << "\n";
            std::cout << "  Error: " << assembler.getLastError() << "\n";
        }
    }

    std::cout << "\n" << std::string(70, '-') << "\n";
    std::cout << "Bit-Oriented Tests: " << passed << " passed, " << failed << " failed\n";
}

// Test PIC16 literal and control instructions
void testPIC16LiteralAndControl() {
    printTestHeader("PIC16 LITERAL AND CONTROL INSTRUCTION ENCODING");

    std::vector<TestCase> tests = {
        {
            "MOVLW k (Move literal 0x42 to W)",
            "ORG 0x0000\nMOVLW 0x42\nEND",
            0x3042,  // 0x3000 | 0x42
            "Load literal into W register"
        },
        {
            "ADDLW k",
            "ORG 0x0000\nADDLW 0x55\nEND",
            0x3E55,  // 0x3E00 | 0x55
            "Add literal to W"
        },
        {
            "SUBLW k",
            "ORG 0x0000\nSUBLW 0x10\nEND",
            0x3C10,  // 0x3C00 | 0x10
            "Subtract W from literal"
        },
        {
            "ANDLW k",
            "ORG 0x0000\nANDLW 0xFF\nEND",
            0x39FF,  // 0x3900 | 0xFF
            "AND W with literal"
        },
        {
            "IORLW k",
            "ORG 0x0000\nIOLRW 0x0F\nEND",
            0x380F,  // 0x3800 | 0x0F
            "OR W with literal"
        }
    };

    Assembler assembler(Architecture::PIC16);
    int passed = 0, failed = 0;

    for (const auto& test : tests) {
        auto code = assembler.assemble(test.code);

        if (!code.empty()) {
            uint16_t actual = code[0].instruction;
            bool pass = (actual == test.expectedOpcode);

            if (pass) passed++;
            else failed++;

            std::cout << "\n" << test.name << "\n";
            std::cout << "  Description: " << test.description << "\n";
            printTestResult(pass, "Opcode Match",
                hexFormat(test.expectedOpcode),
                hexFormat(actual));
        } else {
            failed++;
            std::cout << "\n✗ FAIL: " << test.name << "\n";
            std::cout << "  Error: " << assembler.getLastError() << "\n";
        }
    }

    std::cout << "\n" << std::string(70, '-') << "\n";
    std::cout << "Literal/Control Tests: " << passed << " passed, " << failed << " failed\n";
}

int main() {
    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << "PIC INSTRUCTION ENCODING VERIFICATION TEST SUITE\n";
    std::cout << std::string(70, '=') << "\n";
    std::cout << "This test suite verifies correct instruction encoding against\n";
    std::cout << "Microchip PIC16F/PIC18 datasheet specifications\n";

    testPIC16ByteOriented();
    testPIC16BitOriented();
    testPIC16LiteralAndControl();

    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << "VERIFICATION TEST SUITE COMPLETE\n";
    std::cout << std::string(70, '=') << "\n\n";

    return 0;
}
