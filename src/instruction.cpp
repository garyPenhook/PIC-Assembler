#include "instruction.h"
#include <algorithm>

InstructionSet::InstructionSet() {
    initializeMnemonics();
}

InstructionSet& InstructionSet::getInstance() {
    static InstructionSet instance;
    return instance;
}

void InstructionSet::initializeMnemonics() {
    // Byte-Oriented Operations
    mnemonicMap["ADDWF"] = InstructionType::ADDWF;
    mnemonicMap["ANDWF"] = InstructionType::ANDWF;
    mnemonicMap["CLRF"] = InstructionType::CLRF;
    mnemonicMap["CLRW"] = InstructionType::CLRW;
    mnemonicMap["COMF"] = InstructionType::COMF;
    mnemonicMap["DECF"] = InstructionType::DECF;
    mnemonicMap["DECFSZ"] = InstructionType::DECFSZ;
    mnemonicMap["INCF"] = InstructionType::INCF;
    mnemonicMap["INCFSZ"] = InstructionType::INCFSZ;
    mnemonicMap["IORWF"] = InstructionType::IORWF;
    mnemonicMap["MOVF"] = InstructionType::MOVF;
    mnemonicMap["MOVWF"] = InstructionType::MOVWF;
    mnemonicMap["NOP"] = InstructionType::NOP;
    mnemonicMap["RLF"] = InstructionType::RLF;
    mnemonicMap["RRF"] = InstructionType::RRF;
    mnemonicMap["SUBWF"] = InstructionType::SUBWF;
    mnemonicMap["SWAPF"] = InstructionType::SWAPF;
    mnemonicMap["XORWF"] = InstructionType::XORWF;

    // Bit-Oriented Operations
    mnemonicMap["BCF"] = InstructionType::BCF;
    mnemonicMap["BSF"] = InstructionType::BSF;
    mnemonicMap["BTFSC"] = InstructionType::BTFSC;
    mnemonicMap["BTFSS"] = InstructionType::BTFSS;

    // Literal and Control Operations
    mnemonicMap["ADDLW"] = InstructionType::ADDLW;
    mnemonicMap["ANDLW"] = InstructionType::ANDLW;
    mnemonicMap["CALL"] = InstructionType::CALL;
    mnemonicMap["CLRWDT"] = InstructionType::CLRWDT;
    mnemonicMap["GOTO"] = InstructionType::GOTO;
    mnemonicMap["IORLW"] = InstructionType::IORLW;
    mnemonicMap["MOVLW"] = InstructionType::MOVLW;
    mnemonicMap["RETFIE"] = InstructionType::RETFIE;
    mnemonicMap["RETLW"] = InstructionType::RETLW;
    mnemonicMap["RETURN"] = InstructionType::RETURN;
    mnemonicMap["SLEEP"] = InstructionType::SLEEP;
    mnemonicMap["SUBLW"] = InstructionType::SUBLW;
    mnemonicMap["XORLW"] = InstructionType::XORLW;

    // Build reverse map for type names
    for (const auto& [mnemonic, type] : mnemonicMap) {
        typeNameMap[type] = mnemonic;
    }
}

InstructionType InstructionSet::getMnemonicType(const std::string& mnemonic) const {
    std::string upper = mnemonic;
    std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);

    auto it = mnemonicMap.find(upper);
    if (it != mnemonicMap.end()) {
        return it->second;
    }
    return InstructionType::INVALID;
}

std::string InstructionSet::getTypeName(InstructionType type) const {
    auto it = typeNameMap.find(type);
    if (it != typeNameMap.end()) {
        return it->second;
    }
    return "INVALID";
}

uint16_t InstructionSet::encodeInstruction(InstructionType type, uint8_t f_reg,
                                          uint8_t d_bit, uint8_t b_bit,
                                          uint16_t k_value) const {
    uint16_t opcode = 0;

    switch (type) {
        // Byte-Oriented Operations: 11ddaaffffffff
        case InstructionType::ADDWF:
            opcode = Opcodes::ADDWF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::ANDWF:
            opcode = Opcodes::ANDWF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::CLRF:
            opcode = Opcodes::CLRF | f_reg;
            break;
        case InstructionType::CLRW:
            opcode = Opcodes::CLRW;
            break;
        case InstructionType::COMF:
            opcode = Opcodes::COMF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::DECF:
            opcode = Opcodes::DECF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::DECFSZ:
            opcode = Opcodes::DECFSZ | (d_bit << 7) | f_reg;
            break;
        case InstructionType::INCF:
            opcode = Opcodes::INCF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::INCFSZ:
            opcode = Opcodes::INCFSZ | (d_bit << 7) | f_reg;
            break;
        case InstructionType::IORWF:
            opcode = Opcodes::IORWF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::MOVF:
            opcode = Opcodes::MOVF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::MOVWF:
            opcode = Opcodes::MOVWF | f_reg;
            break;
        case InstructionType::NOP:
            opcode = Opcodes::NOP;
            break;
        case InstructionType::RLF:
            opcode = Opcodes::RLF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::RRF:
            opcode = Opcodes::RRF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::SUBWF:
            opcode = Opcodes::SUBWF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::SWAPF:
            opcode = Opcodes::SWAPF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::XORWF:
            opcode = Opcodes::XORWF | (d_bit << 7) | f_reg;
            break;

        // Bit-Oriented Operations: 10bbbffffffff
        case InstructionType::BCF:
            opcode = Opcodes::BCF | (b_bit << 7) | f_reg;
            break;
        case InstructionType::BSF:
            opcode = Opcodes::BSF | (b_bit << 7) | f_reg;
            break;
        case InstructionType::BTFSC:
            opcode = Opcodes::BTFSC | (b_bit << 7) | f_reg;
            break;
        case InstructionType::BTFSS:
            opcode = Opcodes::BTFSS | (b_bit << 7) | f_reg;
            break;

        // Literal and Control Operations: xxxkkkkkkkkkkkk
        case InstructionType::ADDLW:
            opcode = Opcodes::ADDLW | (k_value & 0xFF);
            break;
        case InstructionType::ANDLW:
            opcode = Opcodes::ANDLW | (k_value & 0xFF);
            break;
        case InstructionType::CALL:
            opcode = Opcodes::CALL | (k_value & 0x7FF);
            break;
        case InstructionType::CLRWDT:
            opcode = Opcodes::CLRWDT;
            break;
        case InstructionType::GOTO:
            opcode = Opcodes::GOTO | (k_value & 0x7FF);
            break;
        case InstructionType::IORLW:
            opcode = Opcodes::IORLW | (k_value & 0xFF);
            break;
        case InstructionType::MOVLW:
            opcode = Opcodes::MOVLW | (k_value & 0xFF);
            break;
        case InstructionType::RETFIE:
            opcode = Opcodes::RETFIE;
            break;
        case InstructionType::RETLW:
            opcode = Opcodes::RETLW | (k_value & 0xFF);
            break;
        case InstructionType::RETURN:
            opcode = Opcodes::RETURN;
            break;
        case InstructionType::SLEEP:
            opcode = Opcodes::SLEEP;
            break;
        case InstructionType::SUBLW:
            opcode = Opcodes::SUBLW | (k_value & 0xFF);
            break;
        case InstructionType::XORLW:
            opcode = Opcodes::XORLW | (k_value & 0xFF);
            break;

        default:
            return 0;
    }

    return opcode;
}
