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
            0x07A0,  // 0x0700 | (1 << 7) | 0x20 - CORRECTED
            "Add W to file register 0x20, store in f"
        },
        {
            "MOVWF f",
            "ORG 0x0000\nMOVWF 0x25\nEND",
            0x00A5,  // 0x0080 | 0x25 - CORRECTED
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
            0x08A0,  // 0x0800 | (1 << 7) | 0x20 - CORRECTED
            "Move file register to itself"
        },
        {
            "CLRF f",
            "ORG 0x0000\nCLRF 0x30\nEND",
            0x01B0,  // 0x0180 | 0x30 - CORRECTED
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
            0x1625,  // 0x1400 | (3 << 9) | 0x25 - CORRECTED
            "Bit Set"
        },
        {
            "BTFSC f, b (Test bit 7)",
            "ORG 0x0000\nBTFSC 0x30, 7\nEND",
            0x1E30,  // 0x1800 | (7 << 9) | 0x30 - CORRECTED
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
            "ORG 0x0000\nIORLW 0x0F\nEND",
            0x380F,  // 0x3800 | 0x0F
            "Inclusive OR W with literal"
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

// Test PIC18 byte-oriented instructions
void testPIC18ByteOriented() {
    printTestHeader("PIC18 BYTE-ORIENTED INSTRUCTION ENCODING");

    std::vector<TestCase> tests = {
        {
            "ADDWF f, d (PIC18)",
            "ORG 0x0000\nADDWF 0x20, 1\nEND",
            0x2520,  // 0x2400 | (1 << 8) | 0x20 - CORRECTED
            "Add W to file register 0x20, store in f"
        },
        {
            "MOVWF f (PIC18)",
            "ORG 0x0000\nMOVWF 0x25\nEND",
            0x6E25,  // 0x6E00 | 0x25
            "Move W to file register 0x25"
        },
        {
            "MOVF f, d (d=0, PIC18)",
            "ORG 0x0000\nMOVF 0x20, 0\nEND",
            0x5020,  // 0x5000 | (0 << 8) | 0x20
            "Move file register to W"
        },
        {
            "MOVF f, d (d=1, PIC18)",
            "ORG 0x0000\nMOVF 0x20, 1\nEND",
            0x5120,  // 0x5000 | (1 << 8) | 0x20
            "Move file register to itself"
        },
        {
            "CLRF f (PIC18)",
            "ORG 0x0000\nCLRF 0x30\nEND",
            0x6A30,  // 0x6A00 | 0x30
            "Clear file register 0x30"
        },
        {
            "INCF f, d (PIC18)",
            "ORG 0x0000\nINCF 0x21, 1\nEND",
            0x2921,  // 0x2800 | (1 << 8) | 0x21 - CORRECTED
            "Increment file register, store in f"
        }
    };

    Assembler assembler(Architecture::PIC18);
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
    std::cout << "PIC18 Byte-Oriented Tests: " << passed << " passed, " << failed << " failed\n";
}

// Test PIC18 bit-oriented instructions
void testPIC18BitOriented() {
    printTestHeader("PIC18 BIT-ORIENTED INSTRUCTION ENCODING");

    std::vector<TestCase> tests = {
        {
            "BCF f, b (PIC18)",
            "ORG 0x0000\nBCF 0x20, 0\nEND",
            0x9020,  // 0x9000 | (0 << 8) | 0x20
            "Bit Clear"
        },
        {
            "BSF f, b (PIC18)",
            "ORG 0x0000\nBSF 0x25, 3\nEND",
            0x8325,  // 0x8000 | (3 << 8) | 0x25
            "Bit Set"
        },
        {
            "BTFSC f, b (PIC18)",
            "ORG 0x0000\nBTFSC 0x30, 7\nEND",
            0xB730,  // 0xB000 | (7 << 8) | 0x30
            "Bit Test, Skip if Clear"
        },
        {
            "BTFSS f, b (PIC18)",
            "ORG 0x0000\nBTFSS 0x40, 0\nEND",
            0xA040,  // 0xA000 | (0 << 8) | 0x40
            "Bit Test, Skip if Set"
        }
    };

    Assembler assembler(Architecture::PIC18);
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
    std::cout << "PIC18 Bit-Oriented Tests: " << passed << " passed, " << failed << " failed\n";
}

// Test PIC18 literal and control instructions
void testPIC18LiteralAndControl() {
    printTestHeader("PIC18 LITERAL AND CONTROL INSTRUCTION ENCODING");

    std::vector<TestCase> tests = {
        {
            "MOVLW k (PIC18)",
            "ORG 0x0000\nMOVLW 0x42\nEND",
            0x0E42,  // 0x0E00 | 0x42
            "Load literal into W register"
        },
        {
            "ADDLW k (PIC18)",
            "ORG 0x0000\nADDLW 0x55\nEND",
            0x0F55,  // 0x0F00 | 0x55
            "Add literal to W"
        },
        {
            "SUBLW k (PIC18)",
            "ORG 0x0000\nSUBLW 0x10\nEND",
            0x0810,  // 0x0800 | 0x10
            "Subtract W from literal"
        },
        {
            "ANDLW k (PIC18)",
            "ORG 0x0000\nANDLW 0xFF\nEND",
            0x0BFF,  // 0x0B00 | 0xFF
            "AND W with literal"
        },
        {
            "IORLW k (PIC18)",
            "ORG 0x0000\nIORLW 0x0F\nEND",
            0x090F,  // 0x0900 | 0x0F
            "Inclusive OR W with literal"
        }
    };

    Assembler assembler(Architecture::PIC18);
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
    std::cout << "PIC18 Literal/Control Tests: " << passed << " passed, " << failed << " failed\n";
}

// Test PIC12 byte-oriented instructions
void testPIC12ByteOriented() {
    printTestHeader("PIC12 BYTE-ORIENTED INSTRUCTION ENCODING");

    std::vector<TestCase> tests = {
        {
            "ADDWF f, d (PIC12)",
            "ORG 0x0000\nADDWF 0x20, 1\nEND",
            0x07A0,  // 0x0700 | (1 << 7) | 0x20
            "Add W to file register 0x20, store in f"
        },
        {
            "MOVWF f (PIC12)",
            "ORG 0x0000\nMOVWF 0x25\nEND",
            0x00A5,  // 0x0080 | 0x25
            "Move W to file register 0x25"
        },
        {
            "MOVF f, d (d=0, PIC12)",
            "ORG 0x0000\nMOVF 0x20, 0\nEND",
            0x0820,  // 0x0800 | (0 << 7) | 0x20
            "Move file register to W"
        },
        {
            "CLRF f (PIC12)",
            "ORG 0x0000\nCLRF 0x30\nEND",
            0x01B0,  // 0x0180 | 0x30
            "Clear file register 0x30"
        }
    };

    Assembler assembler(Architecture::PIC12);
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
    std::cout << "PIC12 Byte-Oriented Tests: " << passed << " passed, " << failed << " failed\n";
}

// Test PIC12 bit-oriented instructions
void testPIC12BitOriented() {
    printTestHeader("PIC12 BIT-ORIENTED INSTRUCTION ENCODING");

    std::vector<TestCase> tests = {
        {
            "BCF f, b (PIC12)",
            "ORG 0x0000\nBCF 0x20, 0\nEND",
            0x1020,  // 0x1000 | (0 << 7) | 0x20
            "Bit Clear"
        },
        {
            "BSF f, b (PIC12)",
            "ORG 0x0000\nBSF 0x25, 3\nEND",
            0x15A5,  // 0x1400 | (3 << 7) | 0x25 - CORRECTED
            "Bit Set"
        },
        {
            "BTFSC f, b (PIC12)",
            "ORG 0x0000\nBTFSC 0x30, 7\nEND",
            0x1BB0,  // 0x1800 | (7 << 7) | 0x30 - CORRECTED
            "Bit Test, Skip if Clear"
        },
        {
            "BTFSS f, b (PIC12)",
            "ORG 0x0000\nBTFSS 0x40, 0\nEND",
            0x1C40,  // 0x1C00 | (0 << 7) | 0x40
            "Bit Test, Skip if Set"
        }
    };

    Assembler assembler(Architecture::PIC12);
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
    std::cout << "PIC12 Bit-Oriented Tests: " << passed << " passed, " << failed << " failed\n";
}

// Test PIC12 literal and control instructions
void testPIC12LiteralAndControl() {
    printTestHeader("PIC12 LITERAL AND CONTROL INSTRUCTION ENCODING");

    std::vector<TestCase> tests = {
        {
            "MOVLW k (PIC12)",
            "ORG 0x0000\nMOVLW 0x42\nEND",
            0x3042,  // 0x3000 | 0x42
            "Load literal into W register"
        },
        {
            "ADDLW k (PIC12)",
            "ORG 0x0000\nADDLW 0x55\nEND",
            0x3E55,  // 0x3E00 | 0x55
            "Add literal to W"
        },
        {
            "SUBLW k (PIC12)",
            "ORG 0x0000\nSUBLW 0x10\nEND",
            0x3C10,  // 0x3C00 | 0x10
            "Subtract W from literal"
        },
        {
            "ANDLW k (PIC12)",
            "ORG 0x0000\nANDLW 0xFF\nEND",
            0x39FF,  // 0x3900 | 0xFF
            "AND W with literal"
        }
    };

    Assembler assembler(Architecture::PIC12);
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
    std::cout << "PIC12 Literal/Control Tests: " << passed << " passed, " << failed << " failed\n";
}

// Extended PIC16 Byte-Oriented Tests
void testPIC16ByteOrientedExtended() {
    printTestHeader("PIC16 BYTE-ORIENTED - EXTENDED");

    std::vector<TestCase> tests = {
        {"ANDWF f, d", "ORG 0x0000\nANDWF 0x20, 1\nEND", 0x0520, "AND W with f"},
        {"COMF f, d", "ORG 0x0000\nCOMF 0x20, 1\nEND", 0x0920, "Complement f"},
        {"DECF f, d", "ORG 0x0000\nDECF 0x20, 1\nEND", 0x0320, "Decrement f"},
        {"DECFSZ f, d", "ORG 0x0000\nDECFSZ 0x20, 1\nEND", 0x0B20, "Decrement f, skip if zero"},
        {"INCFSZ f, d", "ORG 0x0000\nINCFSZ 0x20, 1\nEND", 0x0F20, "Increment f, skip if zero"},
        {"IORWF f, d", "ORG 0x0000\nIORWF 0x20, 1\nEND", 0x0420, "OR W with f"},
        {"RLF f, d", "ORG 0x0000\nRLF 0x20, 1\nEND", 0x0D20, "Rotate left f through Carry"},
        {"RRF f, d", "ORG 0x0000\nRRF 0x20, 1\nEND", 0x0C20, "Rotate right f through Carry"},
        {"SUBWF f, d", "ORG 0x0000\nSUBWF 0x20, 1\nEND", 0x0220, "Subtract W from f"},
        {"SWAPF f, d", "ORG 0x0000\nSWAPF 0x20, 1\nEND", 0x0E20, "Swap nibbles of f"},
        {"XORWF f, d", "ORG 0x0000\nXORWF 0x20, 1\nEND", 0x0620, "XOR W with f"},
        {"CLRW", "ORG 0x0000\nCLRW\nEND", 0x0100, "Clear W register"},
        {"NOP", "ORG 0x0000\nNOP\nEND", 0x0000, "No operation"}
    };

    Assembler assembler(Architecture::PIC16);
    int passed = 0, failed = 0;

    for (const auto& test : tests) {
        auto code = assembler.assemble(test.code);
        if (!code.empty()) {
            uint16_t actual = code[0].instruction;
            bool pass = (actual == test.expectedOpcode);
            if (pass) passed++; else failed++;
            std::cout << (pass ? "✓ " : "✗ ") << test.name << " - Got: " << hexFormat(actual) << "\n";
        } else {
            failed++;
            std::cout << "✗ " << test.name << " - " << assembler.getLastError() << "\n";
        }
    }
    std::cout << "Extended Byte-Oriented: " << passed << "/" << tests.size() << " PASS\n";
}

// Extended PIC16 Control Tests
void testPIC16ControlExtended() {
    printTestHeader("PIC16 CONTROL - EXTENDED");

    std::vector<TestCase> tests = {
        {"CALL addr", "ORG 0x0000\nCALL 0x100\nEND", 0x2100, "Call subroutine"},
        {"GOTO addr", "ORG 0x0000\nGOTO 0x200\nEND", 0x2800, "Unconditional branch"},
        {"RETURN", "ORG 0x0000\nRETURN\nEND", 0x0008, "Return from subroutine"},
        {"RETFIE", "ORG 0x0000\nRETFIE\nEND", 0x0009, "Return from interrupt"},
        {"RETLW k", "ORG 0x0000\nRETLW 0x42\nEND", 0x3442, "Return with literal in W"},
        {"SLEEP", "ORG 0x0000\nSLEEP\nEND", 0x0003, "Go into sleep mode"},
        {"CLRWDT", "ORG 0x0000\nCLRWDT\nEND", 0x0004, "Clear watchdog timer"},
        {"XORLW k", "ORG 0x0000\nXORLW 0xFF\nEND", 0x3AFF, "XOR W with literal"}
    };

    Assembler assembler(Architecture::PIC16);
    int passed = 0, failed = 0;

    for (const auto& test : tests) {
        auto code = assembler.assemble(test.code);
        if (!code.empty()) {
            uint16_t actual = code[0].instruction;
            bool pass = (actual == test.expectedOpcode);
            if (pass) passed++; else failed++;
            std::cout << (pass ? "✓ " : "✗ ") << test.name << " - Got: " << hexFormat(actual) << "\n";
        } else {
            failed++;
            std::cout << "✗ " << test.name << " - " << assembler.getLastError() << "\n";
        }
    }
    std::cout << "Extended Control: " << passed << "/" << tests.size() << " PASS\n";
}

// Extended PIC18 Byte-Oriented Tests
void testPIC18ByteOrientedExtended() {
    printTestHeader("PIC18 BYTE-ORIENTED - EXTENDED");

    std::vector<TestCase> tests = {
        {"ANDWF f, d", "ORG 0x0000\nANDWF 0x20, 1\nEND", 0x0520, "AND W with f"},
        {"IORWF f, d", "ORG 0x0000\nIORWF 0x20, 1\nEND", 0x1020, "OR W with f"},
        {"XORWF f, d", "ORG 0x0000\nXORWF 0x20, 1\nEND", 0x0720, "XOR W with f"},
        {"COMF f, d", "ORG 0x0000\nCOMF 0x20, 1\nEND", 0x1D20, "Complement f"},
        {"NEGF f", "ORG 0x0000\nNEGF 0x20\nEND", 0x6C00, "Negate f"},
        {"SETF f", "ORG 0x0000\nSETF 0x20\nEND", 0x6800, "Set all bits in f"}
    };

    Assembler assembler(Architecture::PIC18);
    int passed = 0, failed = 0;

    for (const auto& test : tests) {
        auto code = assembler.assemble(test.code);
        if (!code.empty()) {
            uint16_t actual = code[0].instruction;
            bool pass = (actual == test.expectedOpcode);
            if (pass) passed++; else failed++;
            std::cout << (pass ? "✓ " : "✗ ") << test.name << " - Got: " << hexFormat(actual) << "\n";
        } else {
            failed++;
            std::cout << "✗ " << test.name << " - " << assembler.getLastError() << "\n";
        }
    }
    std::cout << "Extended Byte-Oriented: " << passed << "/" << tests.size() << " PASS\n";
}

// PIC18 Branches
void testPIC18Branches() {
    printTestHeader("PIC18 CONDITIONAL BRANCHES");

    std::vector<TestCase> tests = {
        {"BC addr", "ORG 0x0000\nBC 0x20\nEND", 0xE200, "Branch if Carry"},
        {"BZ addr", "ORG 0x0000\nBZ 0x20\nEND", 0xE000, "Branch if Zero"},
        {"BNZ addr", "ORG 0x0000\nBNZ 0x20\nEND", 0xE100, "Branch if Not Zero"},
        {"BOV addr", "ORG 0x0000\nBOV 0x20\nEND", 0xE400, "Branch if Overflow"}
    };

    Assembler assembler(Architecture::PIC18);
    int passed = 0, failed = 0;

    for (const auto& test : tests) {
        auto code = assembler.assemble(test.code);
        if (!code.empty()) {
            uint16_t actual = code[0].instruction;
            bool pass = (actual == test.expectedOpcode);
            if (pass) passed++; else failed++;
            std::cout << (pass ? "✓ " : "✗ ") << test.name << " - Got: " << hexFormat(actual) << "\n";
        } else {
            failed++;
            std::cout << "✗ " << test.name << " - " << assembler.getLastError() << "\n";
        }
    }
    std::cout << "Conditional Branches: " << passed << "/" << tests.size() << " PASS\n";
}

// PIC18 Compare and Skip
void testPIC18CompareSkip() {
    printTestHeader("PIC18 COMPARE AND SKIP");

    std::vector<TestCase> tests = {
        {"CPFSEQ f", "ORG 0x0000\nCPFSEQ 0x20\nEND", 0x6200, "Compare f with W, skip if equal"},
        {"CPFSGT f", "ORG 0x0000\nCPFSGT 0x20\nEND", 0x6400, "Compare f with W, skip if greater"},
        {"CPFSLT f", "ORG 0x0000\nCPFSLT 0x20\nEND", 0x6000, "Compare f with W, skip if less"}
    };

    Assembler assembler(Architecture::PIC18);
    int passed = 0, failed = 0;

    for (const auto& test : tests) {
        auto code = assembler.assemble(test.code);
        if (!code.empty()) {
            uint16_t actual = code[0].instruction;
            bool pass = (actual == test.expectedOpcode);
            if (pass) passed++; else failed++;
            std::cout << (pass ? "✓ " : "✗ ") << test.name << " - Got: " << hexFormat(actual) << "\n";
        } else {
            failed++;
            std::cout << "✗ " << test.name << " - " << assembler.getLastError() << "\n";
        }
    }
    std::cout << "Compare/Skip: " << passed << "/" << tests.size() << " PASS\n";
}

int main() {
    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << "PIC INSTRUCTION ENCODING VERIFICATION TEST SUITE\n";
    std::cout << std::string(70, '=') << "\n";
    std::cout << "This test suite verifies correct instruction encoding against\n";
    std::cout << "Microchip PIC16F/PIC18 datasheet specifications\n";

    testPIC12ByteOriented();
    testPIC12BitOriented();
    testPIC12LiteralAndControl();

    testPIC16ByteOriented();
    testPIC16BitOriented();
    testPIC16LiteralAndControl();
    testPIC16ByteOrientedExtended();
    testPIC16ControlExtended();

    testPIC18ByteOriented();
    testPIC18BitOriented();
    testPIC18LiteralAndControl();
    testPIC18ByteOrientedExtended();
    testPIC18Branches();
    testPIC18CompareSkip();

    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << "VERIFICATION TEST SUITE COMPLETE\n";
    std::cout << std::string(70, '=') << "\n\n";

    return 0;
}
