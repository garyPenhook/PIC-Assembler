#pragma once

#include <string>
#include <map>
#include <cstdint>

enum class InstructionType {
    // Byte-Oriented Operations
    ADDWF, ANDWF, CLRF, CLRW, COMF, DECF, DECFSZ, INCF, INCFSZ,
    IORWF, MOVF, MOVWF, NOP, RLF, RRF, SUBWF, SWAPF, XORWF,

    // Bit-Oriented Operations
    BCF, BSF, BTFSC, BTFSS,

    // Literal and Control Operations
    ADDLW, ANDLW, CALL, CLRWDT, GOTO, IORLW, MOVLW, RETFIE, RETLW, RETURN, SLEEP, SUBLW, XORLW,

    // Invalid/Unknown
    INVALID
};

struct Instruction {
    InstructionType type;
    uint16_t opcode;  // 14-bit opcode
    std::string mnemonic;
    std::string operands;  // Raw operand string
    uint16_t address;  // Program memory address
    int line_number;
};

class InstructionSet {
public:
    static InstructionSet& getInstance();

    // Get instruction type from mnemonic
    InstructionType getMnemonicType(const std::string& mnemonic) const;
    std::string getTypeName(InstructionType type) const;

    // Encode instruction with operands
    uint16_t encodeInstruction(InstructionType type, uint8_t f_reg, uint8_t d_bit,
                              uint8_t b_bit, uint16_t k_value) const;

private:
    InstructionSet();

    std::map<std::string, InstructionType> mnemonicMap;
    std::map<InstructionType, std::string> typeNameMap;

    void initializeMnemonics();
};

// Opcode constants (14-bit values)
namespace Opcodes {
    // Byte-Oriented (format: 11ddaaffffffff where dd=dest, aa=opcode, ffffff=file reg)
    constexpr uint16_t ADDWF  = 0x0700;  // 11 0100 ff ffff ff
    constexpr uint16_t ANDWF  = 0x0500;
    constexpr uint16_t CLRF   = 0x0180;
    constexpr uint16_t CLRW   = 0x0100;
    constexpr uint16_t COMF   = 0x0900;
    constexpr uint16_t DECF   = 0x0300;
    constexpr uint16_t DECFSZ = 0x0B00;
    constexpr uint16_t INCF   = 0x0A00;
    constexpr uint16_t INCFSZ = 0x0F00;
    constexpr uint16_t IORWF  = 0x0400;
    constexpr uint16_t MOVF   = 0x0800;
    constexpr uint16_t MOVWF  = 0x0080;
    constexpr uint16_t NOP    = 0x0000;
    constexpr uint16_t RLF    = 0x0D00;
    constexpr uint16_t RRF    = 0x0C00;
    constexpr uint16_t SUBWF  = 0x0200;
    constexpr uint16_t SWAPF  = 0x0E00;
    constexpr uint16_t XORWF  = 0x0600;

    // Bit-Oriented (format: 10bbbffffffff where bbb=bit, ffffff=file reg)
    constexpr uint16_t BCF    = 0x1000;
    constexpr uint16_t BSF    = 0x1400;
    constexpr uint16_t BTFSC  = 0x1800;
    constexpr uint16_t BTFSS  = 0x1C00;

    // Literal and Control (format: xxxkkkkkkkkkkkk)
    constexpr uint16_t ADDLW  = 0x3E00;
    constexpr uint16_t ANDLW  = 0x3900;
    constexpr uint16_t CALL   = 0x2000;
    constexpr uint16_t CLRWDT = 0x0064;
    constexpr uint16_t GOTO   = 0x2800;
    constexpr uint16_t IORLW  = 0x3800;
    constexpr uint16_t MOVLW  = 0x3000;
    constexpr uint16_t RETFIE = 0x0009;
    constexpr uint16_t RETLW  = 0x3400;
    constexpr uint16_t RETURN = 0x0008;
    constexpr uint16_t SLEEP  = 0x0063;
    constexpr uint16_t SUBLW  = 0x3C00;
    constexpr uint16_t XORLW  = 0x3A00;
}

