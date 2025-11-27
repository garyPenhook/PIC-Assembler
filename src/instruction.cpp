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
    // ========== SHARED PIC16/PIC18 ==========
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

    // Literal and Control Operations (PIC16)
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

    // ========== PIC18 SPECIFIC ==========
    // Additional Byte-Oriented (PIC18)
    mnemonicMap["ADDWFC"] = InstructionType::ADDWFC;
    mnemonicMap["DCFSNZ"] = InstructionType::DCFSNZ;
    mnemonicMap["INFSNZ"] = InstructionType::INFSNZ;
    mnemonicMap["MOVFF"] = InstructionType::MOVFF;
    mnemonicMap["MULWF"] = InstructionType::MULWF;
    mnemonicMap["NEGF"] = InstructionType::NEGF;
    mnemonicMap["RLCF"] = InstructionType::RLCF;
    mnemonicMap["RLNCF"] = InstructionType::RLNCF;
    mnemonicMap["RRCF"] = InstructionType::RRCF;
    mnemonicMap["RRNCF"] = InstructionType::RRNCF;
    mnemonicMap["SETF"] = InstructionType::SETF;
    mnemonicMap["SUBFWB"] = InstructionType::SUBFWB;
    mnemonicMap["SUBWFB"] = InstructionType::SUBWFB;
    mnemonicMap["TSTFSZ"] = InstructionType::TSTFSZ;

    // Additional Bit-Oriented (PIC18)
    mnemonicMap["BTG"] = InstructionType::BTG;

    // Compare & Skip (PIC18)
    mnemonicMap["CPFSEQ"] = InstructionType::CPFSEQ;
    mnemonicMap["CPFSGT"] = InstructionType::CPFSGT;
    mnemonicMap["CPFSLT"] = InstructionType::CPFSLT;

    // Conditional Branch (PIC18)
    mnemonicMap["BC"] = InstructionType::BC;
    mnemonicMap["BN"] = InstructionType::BN;
    mnemonicMap["BNC"] = InstructionType::BNC;
    mnemonicMap["BNN"] = InstructionType::BNN;
    mnemonicMap["BNOV"] = InstructionType::BNOV;
    mnemonicMap["BNZ"] = InstructionType::BNZ;
    mnemonicMap["BOV"] = InstructionType::BOV;
    mnemonicMap["BRA"] = InstructionType::BRA;
    mnemonicMap["BZ"] = InstructionType::BZ;

    // Additional Control (PIC18)
    mnemonicMap["CALLW"] = InstructionType::CALLW;
    mnemonicMap["RCALL"] = InstructionType::RCALL;

    // Inherent (PIC18)
    mnemonicMap["DAW"] = InstructionType::DAW;
    mnemonicMap["POP"] = InstructionType::POP;
    mnemonicMap["PUSH"] = InstructionType::PUSH;
    mnemonicMap["RESET"] = InstructionType::RESET;

    // Literal Operations (PIC18)
    mnemonicMap["ADDFSR"] = InstructionType::ADDFSR;
    mnemonicMap["LFSR"] = InstructionType::LFSR;
    mnemonicMap["MOVLB"] = InstructionType::MOVLB;
    mnemonicMap["MULLW"] = InstructionType::MULLW;
    mnemonicMap["SUBFSR"] = InstructionType::SUBFSR;

    // Table Operations (PIC18)
    mnemonicMap["TBLRD"] = InstructionType::TBLRD;
    mnemonicMap["TBLWT"] = InstructionType::TBLWT;

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

bool InstructionSet::isValidForArchitecture(InstructionType type) const {
    if (targetArch == Architecture::PIC16) {
        // PIC16 supports instructions up to XORLW and basic shared operations
        // Reject PIC18-only instructions
        return !(type >= InstructionType::ADDWFC && type <= InstructionType::TBLWT);
    } else {
        // PIC18 supports all instructions
        return type != InstructionType::INVALID;
    }
}

uint8_t InstructionSet::getInstructionWordSize() const {
    return (targetArch == Architecture::PIC16) ? 14 : 16;
}

uint16_t InstructionSet::encodeInstruction(InstructionType type, uint8_t f_reg,
                                          uint8_t d_bit, uint8_t b_bit,
                                          uint16_t k_value) const {
    if (targetArch == Architecture::PIC16) {
        return encodePIC16Instruction(type, f_reg, d_bit, b_bit, k_value);
    } else {
        return encodePIC18Instruction(type, f_reg, d_bit, b_bit, k_value);
    }
}

uint16_t InstructionSet::encodePIC16Instruction(InstructionType type, uint8_t f_reg,
                                                uint8_t d_bit, uint8_t b_bit,
                                                uint16_t k_value) const {
    uint16_t opcode = 0;

    switch (type) {
        // Byte-Oriented Operations: 11ddaaffffffff
        case InstructionType::ADDWF:
            opcode = Opcodes16::ADDWF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::ANDWF:
            opcode = Opcodes16::ANDWF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::CLRF:
            opcode = Opcodes16::CLRF | f_reg;
            break;
        case InstructionType::CLRW:
            opcode = Opcodes16::CLRW;
            break;
        case InstructionType::COMF:
            opcode = Opcodes16::COMF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::DECF:
            opcode = Opcodes16::DECF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::DECFSZ:
            opcode = Opcodes16::DECFSZ | (d_bit << 7) | f_reg;
            break;
        case InstructionType::INCF:
            opcode = Opcodes16::INCF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::INCFSZ:
            opcode = Opcodes16::INCFSZ | (d_bit << 7) | f_reg;
            break;
        case InstructionType::IORWF:
            opcode = Opcodes16::IORWF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::MOVF:
            opcode = Opcodes16::MOVF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::MOVWF:
            opcode = Opcodes16::MOVWF | f_reg;
            break;
        case InstructionType::NOP:
            opcode = Opcodes16::NOP;
            break;
        case InstructionType::RLF:
            opcode = Opcodes16::RLF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::RRF:
            opcode = Opcodes16::RRF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::SUBWF:
            opcode = Opcodes16::SUBWF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::SWAPF:
            opcode = Opcodes16::SWAPF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::XORWF:
            opcode = Opcodes16::XORWF | (d_bit << 7) | f_reg;
            break;

        // Bit-Oriented Operations: 10bbbffffffff
        case InstructionType::BCF:
            opcode = Opcodes16::BCF | (b_bit << 7) | f_reg;
            break;
        case InstructionType::BSF:
            opcode = Opcodes16::BSF | (b_bit << 7) | f_reg;
            break;
        case InstructionType::BTFSC:
            opcode = Opcodes16::BTFSC | (b_bit << 7) | f_reg;
            break;
        case InstructionType::BTFSS:
            opcode = Opcodes16::BTFSS | (b_bit << 7) | f_reg;
            break;

        // Literal and Control Operations: xxxkkkkkkkkkkkk
        case InstructionType::ADDLW:
            opcode = Opcodes16::ADDLW | (k_value & 0xFF);
            break;
        case InstructionType::ANDLW:
            opcode = Opcodes16::ANDLW | (k_value & 0xFF);
            break;
        case InstructionType::CALL:
            opcode = Opcodes16::CALL | (k_value & 0x7FF);
            break;
        case InstructionType::CLRWDT:
            opcode = Opcodes16::CLRWDT;
            break;
        case InstructionType::GOTO:
            opcode = Opcodes16::GOTO | (k_value & 0x7FF);
            break;
        case InstructionType::IORLW:
            opcode = Opcodes16::IORLW | (k_value & 0xFF);
            break;
        case InstructionType::MOVLW:
            opcode = Opcodes16::MOVLW | (k_value & 0xFF);
            break;
        case InstructionType::RETFIE:
            opcode = Opcodes16::RETFIE;
            break;
        case InstructionType::RETLW:
            opcode = Opcodes16::RETLW | (k_value & 0xFF);
            break;
        case InstructionType::RETURN:
            opcode = Opcodes16::RETURN;
            break;
        case InstructionType::SLEEP:
            opcode = Opcodes16::SLEEP;
            break;
        case InstructionType::SUBLW:
            opcode = Opcodes16::SUBLW | (k_value & 0xFF);
            break;
        case InstructionType::XORLW:
            opcode = Opcodes16::XORLW | (k_value & 0xFF);
            break;

        default:
            return 0;
    }

    return opcode;
}

uint16_t InstructionSet::encodePIC18Instruction(InstructionType type, uint8_t f_reg,
                                                uint8_t d_bit, uint8_t b_bit,
                                                uint16_t k_value) const {
    uint16_t opcode = 0;

    switch (type) {
        // Byte-Oriented Operations
        case InstructionType::ADDWF:
            opcode = Opcodes18::ADDWF | (d_bit << 8) | f_reg;
            break;
        case InstructionType::ADDWFC:
            opcode = Opcodes18::ADDWFC | (d_bit << 8) | f_reg;
            break;
        case InstructionType::ANDWF:
            opcode = Opcodes18::ANDWF | (d_bit << 8) | f_reg;
            break;
        case InstructionType::CLRF:
            opcode = Opcodes18::CLRF | f_reg;
            break;
        case InstructionType::COMF:
            opcode = Opcodes18::COMF | (d_bit << 8) | f_reg;
            break;
        case InstructionType::DECF:
            opcode = Opcodes18::DECF | (d_bit << 8) | f_reg;
            break;
        case InstructionType::INCF:
            opcode = Opcodes18::INCF | (d_bit << 8) | f_reg;
            break;
        case InstructionType::MOVF:
            opcode = Opcodes18::MOVF | (d_bit << 8) | f_reg;
            break;
        case InstructionType::MOVWF:
            opcode = Opcodes18::MOVWF | f_reg;
            break;
        case InstructionType::MULWF:
            opcode = Opcodes18::MULWF | f_reg;
            break;
        case InstructionType::NEGF:
            opcode = Opcodes18::NEGF | f_reg;
            break;
        case InstructionType::SETF:
            opcode = Opcodes18::SETF | f_reg;
            break;
        case InstructionType::SWAPF:
            opcode = Opcodes18::SWAPF | (d_bit << 8) | f_reg;
            break;
        case InstructionType::XORWF:
            opcode = Opcodes18::XORWF | (d_bit << 8) | f_reg;
            break;

        // Bit-Oriented
        case InstructionType::BCF:
            opcode = Opcodes18::BCF | (b_bit << 8) | f_reg;
            break;
        case InstructionType::BSF:
            opcode = Opcodes18::BSF | (b_bit << 8) | f_reg;
            break;
        case InstructionType::BTG:
            opcode = Opcodes18::BTG | (b_bit << 8) | f_reg;
            break;
        case InstructionType::BTFSC:
            opcode = Opcodes18::BTFSC | (b_bit << 8) | f_reg;
            break;
        case InstructionType::BTFSS:
            opcode = Opcodes18::BTFSS | (b_bit << 8) | f_reg;
            break;

        // Control & Literal
        case InstructionType::ADDLW:
            opcode = Opcodes18::ADDLW | (k_value & 0xFF);
            break;
        case InstructionType::ANDLW:
            opcode = Opcodes18::ANDLW | (k_value & 0xFF);
            break;
        case InstructionType::CALL:
            opcode = Opcodes18::CALL | (k_value & 0xFFFF);
            break;
        case InstructionType::CLRWDT:
            opcode = Opcodes18::CLRWDT;
            break;
        case InstructionType::GOTO:
            opcode = Opcodes18::GOTO | (k_value & 0xFFFF);
            break;
        case InstructionType::IORLW:
            opcode = Opcodes18::IORLW | (k_value & 0xFF);
            break;
        case InstructionType::MOVLW:
            opcode = Opcodes18::MOVLW | (k_value & 0xFF);
            break;
        case InstructionType::RETFIE:
            opcode = Opcodes18::RETFIE;
            break;
        case InstructionType::RETLW:
            opcode = Opcodes18::RETLW | (k_value & 0xFF);
            break;
        case InstructionType::RETURN:
            opcode = Opcodes18::RETURN;
            break;
        case InstructionType::SLEEP:
            opcode = Opcodes18::SLEEP;
            break;
        case InstructionType::SUBLW:
            opcode = Opcodes18::SUBLW | (k_value & 0xFF);
            break;
        case InstructionType::XORLW:
            opcode = Opcodes18::XORLW | (k_value & 0xFF);
            break;

        // Additional PIC18 instructions (simplified encoding)
        case InstructionType::NOP:
            opcode = 0x0000;
            break;

        default:
            return 0;
    }

    return opcode;
}
