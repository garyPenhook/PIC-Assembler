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

    // Literal and Control Operations (PIC16/PIC16E)
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

    // ========== PIC16 ENHANCED MID-RANGE ONLY ==========
    // Shift Instructions
    mnemonicMap["LSLF"] = InstructionType::LSLF;
    mnemonicMap["LSRF"] = InstructionType::LSRF;
    mnemonicMap["ASRF"] = InstructionType::ASRF;

    // Branch
    mnemonicMap["BRW"] = InstructionType::BRW;

    // Indirect Addressing
    mnemonicMap["MOVIW"] = InstructionType::MOVIW;
    mnemonicMap["MOVWI"] = InstructionType::MOVWI;

    // Literal Operations
    mnemonicMap["MOVLP"] = InstructionType::MOVLP;

    // ========== PIC12 BASELINE ONLY ==========
    mnemonicMap["OPTION"] = InstructionType::OPTION;
    mnemonicMap["TRIS"] = InstructionType::TRIS;

    // ========== PIC16 ENHANCED & PIC18 SHARED ==========
    mnemonicMap["ADDWFC"] = InstructionType::ADDWFC;

    // ========== PIC18 SPECIFIC ==========
    // Additional Byte-Oriented (PIC18)
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
    if (targetArch == Architecture::PIC12) {
        return encodePIC12Instruction(type, f_reg, d_bit, b_bit, k_value);
    } else if (targetArch == Architecture::PIC16) {
        return encodePIC16Instruction(type, f_reg, d_bit, b_bit, k_value);
    } else {
        return encodePIC18Instruction(type, f_reg, d_bit, b_bit, k_value);
    }
}

uint16_t InstructionSet::encodePIC12Instruction(InstructionType type, uint8_t f_reg,
                                                uint8_t d_bit, uint8_t b_bit,
                                                uint16_t k_value) const {
    uint16_t opcode = 0;

    // Byte-Oriented Operations
    if (type == InstructionType::ADDWF) opcode = Opcodes12::ADDWF | (d_bit << 7) | f_reg;
    else if (type == InstructionType::ANDWF) opcode = Opcodes12::ANDWF | (d_bit << 7) | f_reg;
    else if (type == InstructionType::CLRF) opcode = Opcodes12::CLRF | f_reg;
    else if (type == InstructionType::CLRW) opcode = Opcodes12::CLRW;
    else if (type == InstructionType::COMF) opcode = Opcodes12::COMF | (d_bit << 7) | f_reg;
    else if (type == InstructionType::DECF) opcode = Opcodes12::DECF | (d_bit << 7) | f_reg;
    else if (type == InstructionType::DECFSZ) opcode = Opcodes12::DECFSZ | (d_bit << 7) | f_reg;
    else if (type == InstructionType::INCF) opcode = Opcodes12::INCF | (d_bit << 7) | f_reg;
    else if (type == InstructionType::INCFSZ) opcode = Opcodes12::INCFSZ | (d_bit << 7) | f_reg;
    else if (type == InstructionType::IORWF) opcode = Opcodes12::IORWF | (d_bit << 7) | f_reg;
    else if (type == InstructionType::MOVF) opcode = Opcodes12::MOVF | (d_bit << 7) | f_reg;
    else if (type == InstructionType::MOVWF) opcode = Opcodes12::MOVWF | f_reg;
    else if (type == InstructionType::NOP) opcode = Opcodes12::NOP;
    else if (type == InstructionType::RLF) opcode = Opcodes12::RLF | (d_bit << 7) | f_reg;
    else if (type == InstructionType::RRF) opcode = Opcodes12::RRF | (d_bit << 7) | f_reg;
    else if (type == InstructionType::SUBWF) opcode = Opcodes12::SUBWF | (d_bit << 7) | f_reg;
    else if (type == InstructionType::SWAPF) opcode = Opcodes12::SWAPF | (d_bit << 7) | f_reg;
    else if (type == InstructionType::XORWF) opcode = Opcodes12::XORWF | (d_bit << 7) | f_reg;

    // Bit-Oriented Operations: Bit position in bits 8-6 for PIC12 (9-bit instruction word)
    else if (type == InstructionType::BCF) opcode = Opcodes12::BCF | (b_bit << 7) | f_reg;
    else if (type == InstructionType::BSF) opcode = Opcodes12::BSF | (b_bit << 7) | f_reg;
    else if (type == InstructionType::BTFSC) opcode = Opcodes12::BTFSC | (b_bit << 7) | f_reg;
    else if (type == InstructionType::BTFSS) opcode = Opcodes12::BTFSS | (b_bit << 7) | f_reg;

    // Literal and Control
    else if (type == InstructionType::ADDLW) opcode = Opcodes12::ADDLW | (k_value & 0xFF);
    else if (type == InstructionType::ANDLW) opcode = Opcodes12::ANDLW | (k_value & 0xFF);
    else if (type == InstructionType::CALL) opcode = Opcodes12::CALL | (k_value & 0x3FF);
    else if (type == InstructionType::CLRWDT) opcode = Opcodes12::CLRWDT;
    else if (type == InstructionType::GOTO) opcode = Opcodes12::GOTO | (k_value & 0x3FF);
    else if (type == InstructionType::IORLW) opcode = Opcodes12::IORLW | (k_value & 0xFF);
    else if (type == InstructionType::MOVLW) opcode = Opcodes12::MOVLW | (k_value & 0xFF);
    else if (type == InstructionType::RETLW) opcode = Opcodes12::RETLW | (k_value & 0xFF);
    else if (type == InstructionType::SLEEP) opcode = Opcodes12::SLEEP;
    else if (type == InstructionType::SUBLW) opcode = Opcodes12::SUBLW | (k_value & 0xFF);
    else if (type == InstructionType::XORLW) opcode = Opcodes12::XORLW | (k_value & 0xFF);

    // PIC12 Baseline Special
    else if (type == InstructionType::OPTION) opcode = Opcodes12::OPTION;
    else if (type == InstructionType::TRIS) opcode = Opcodes12::TRIS | f_reg;

    return opcode;
}

uint16_t InstructionSet::encodePIC16Instruction(InstructionType type, uint8_t f_reg,
                                                uint8_t d_bit, uint8_t b_bit,
                                                uint16_t k_value) const {
    uint16_t opcode = 0;

    switch (type) {
        // Byte-Oriented Operations: 11ddaaffffffff
        case InstructionType::ADDWF:
            opcode = Opcodes16Classic::ADDWF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::ANDWF:
            opcode = Opcodes16Classic::ANDWF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::CLRF:
            opcode = Opcodes16Classic::CLRF | f_reg;
            break;
        case InstructionType::CLRW:
            opcode = Opcodes16Classic::CLRW;
            break;
        case InstructionType::COMF:
            opcode = Opcodes16Classic::COMF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::DECF:
            opcode = Opcodes16Classic::DECF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::DECFSZ:
            opcode = Opcodes16Classic::DECFSZ | (d_bit << 7) | f_reg;
            break;
        case InstructionType::INCF:
            opcode = Opcodes16Classic::INCF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::INCFSZ:
            opcode = Opcodes16Classic::INCFSZ | (d_bit << 7) | f_reg;
            break;
        case InstructionType::IORWF:
            opcode = Opcodes16Classic::IORWF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::MOVF:
            opcode = Opcodes16Classic::MOVF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::MOVWF:
            opcode = Opcodes16Classic::MOVWF | f_reg;
            break;
        case InstructionType::NOP:
            opcode = Opcodes16Classic::NOP;
            break;
        case InstructionType::RLF:
            opcode = Opcodes16Classic::RLF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::RRF:
            opcode = Opcodes16Classic::RRF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::SUBWF:
            opcode = Opcodes16Classic::SUBWF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::SWAPF:
            opcode = Opcodes16Classic::SWAPF | (d_bit << 7) | f_reg;
            break;
        case InstructionType::XORWF:
            opcode = Opcodes16Classic::XORWF | (d_bit << 7) | f_reg;
            break;

        // Bit-Oriented Operations: 10bbbffffffff
        // Bit position (bbb) is in bits 11-9, not bits 8-6
        case InstructionType::BCF:
            opcode = Opcodes16Classic::BCF | (b_bit << 9) | f_reg;
            break;
        case InstructionType::BSF:
            opcode = Opcodes16Classic::BSF | (b_bit << 9) | f_reg;
            break;
        case InstructionType::BTFSC:
            opcode = Opcodes16Classic::BTFSC | (b_bit << 9) | f_reg;
            break;
        case InstructionType::BTFSS:
            opcode = Opcodes16Classic::BTFSS | (b_bit << 9) | f_reg;
            break;

        // Literal and Control Operations: xxxkkkkkkkkkkkk
        case InstructionType::ADDLW:
            opcode = Opcodes16Classic::ADDLW | (k_value & 0xFF);
            break;
        case InstructionType::ANDLW:
            opcode = Opcodes16Classic::ANDLW | (k_value & 0xFF);
            break;
        case InstructionType::CALL:
            opcode = Opcodes16Classic::CALL | (k_value & 0x7FF);
            break;
        case InstructionType::CLRWDT:
            opcode = Opcodes16Classic::CLRWDT;
            break;
        case InstructionType::GOTO:
            opcode = Opcodes16Classic::GOTO | (k_value & 0x7FF);
            break;
        case InstructionType::IORLW:
            opcode = Opcodes16Classic::IORLW | (k_value & 0xFF);
            break;
        case InstructionType::MOVLW:
            opcode = Opcodes16Classic::MOVLW | (k_value & 0xFF);
            break;
        case InstructionType::RETFIE:
            opcode = Opcodes16Classic::RETFIE;
            break;
        case InstructionType::RETLW:
            opcode = Opcodes16Classic::RETLW | (k_value & 0xFF);
            break;
        case InstructionType::RETURN:
            opcode = Opcodes16Classic::RETURN;
            break;
        case InstructionType::SLEEP:
            opcode = Opcodes16Classic::SLEEP;
            break;
        case InstructionType::SUBLW:
            opcode = Opcodes16Classic::SUBLW | (k_value & 0xFF);
            break;
        case InstructionType::XORLW:
            opcode = Opcodes16Classic::XORLW | (k_value & 0xFF);
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

        // Additional Byte-Oriented (PIC18)
        case InstructionType::DCFSNZ:
            opcode = Opcodes18::DCFSNZ | (d_bit << 8) | f_reg;
            break;
        case InstructionType::INFSNZ:
            opcode = Opcodes18::INFSNZ | (d_bit << 8) | f_reg;
            break;
        case InstructionType::MOVFF:
            // MOVFF has two file register operands (source and destination)
            // Using f_reg as source, k_value bits as destination
            opcode = Opcodes18::MOVFF | (k_value & 0x0FFF);
            break;
        case InstructionType::RLCF:
            opcode = Opcodes18::RLCF | (d_bit << 8) | f_reg;
            break;
        case InstructionType::RLNCF:
            opcode = Opcodes18::RLNCF | (d_bit << 8) | f_reg;
            break;
        case InstructionType::RRCF:
            opcode = Opcodes18::RRCF | (d_bit << 8) | f_reg;
            break;
        case InstructionType::RRNCF:
            opcode = Opcodes18::RRNCF | (d_bit << 8) | f_reg;
            break;
        case InstructionType::SUBFWB:
            opcode = Opcodes18::SUBFWB | (d_bit << 8) | f_reg;
            break;
        case InstructionType::SUBWFB:
            opcode = Opcodes18::SUBWFB | (d_bit << 8) | f_reg;
            break;
        case InstructionType::TSTFSZ:
            opcode = Opcodes18::TSTFSZ | f_reg;
            break;

        // Compare & Skip (PIC18)
        case InstructionType::CPFSEQ:
            opcode = Opcodes18::CPFSEQ | f_reg;
            break;
        case InstructionType::CPFSGT:
            opcode = Opcodes18::CPFSGT | f_reg;
            break;
        case InstructionType::CPFSLT:
            opcode = Opcodes18::CPFSLT | f_reg;
            break;

        // Conditional Branch (PIC18)
        case InstructionType::BC:
            opcode = Opcodes18::BC | (k_value & 0xFF);
            break;
        case InstructionType::BN:
            opcode = Opcodes18::BN | (k_value & 0xFF);
            break;
        case InstructionType::BNC:
            opcode = Opcodes18::BNC | (k_value & 0xFF);
            break;
        case InstructionType::BNN:
            opcode = Opcodes18::BNN | (k_value & 0xFF);
            break;
        case InstructionType::BNOV:
            opcode = Opcodes18::BNOV | (k_value & 0xFF);
            break;
        case InstructionType::BNZ:
            opcode = Opcodes18::BNZ | (k_value & 0xFF);
            break;
        case InstructionType::BOV:
            opcode = Opcodes18::BOV | (k_value & 0xFF);
            break;
        case InstructionType::BRA:
            opcode = Opcodes18::BRA | (k_value & 0x7FF);
            break;
        case InstructionType::BZ:
            opcode = Opcodes18::BZ | (k_value & 0xFF);
            break;

        // Additional Control (PIC18)
        case InstructionType::CALLW:
            opcode = Opcodes18::CALLW;
            break;
        case InstructionType::DAW:
            opcode = Opcodes18::DAW;
            break;
        case InstructionType::POP:
            opcode = Opcodes18::POP;
            break;
        case InstructionType::PUSH:
            opcode = Opcodes18::PUSH;
            break;
        case InstructionType::RCALL:
            opcode = Opcodes18::RCALL | (k_value & 0x7FF);
            break;
        case InstructionType::RESET:
            opcode = Opcodes18::RESET;
            break;

        // Literal Operations (PIC18)
        case InstructionType::ADDFSR:
            // ADDFSR f, k: f is FSR number (0-2), k is 8-bit
            opcode = Opcodes18::ADDFSR | ((f_reg & 0x03) << 8) | (k_value & 0xFF);
            break;
        case InstructionType::LFSR:
            // LFSR f, k: f is FSR number (0-2), k is 12-bit
            opcode = Opcodes18::LFSR | ((f_reg & 0x03) << 12) | (k_value & 0xFFF);
            break;
        case InstructionType::MOVLB:
            opcode = Opcodes18::MOVLB | (k_value & 0xFF);
            break;
        case InstructionType::MULLW:
            opcode = Opcodes18::MULLW | (k_value & 0xFF);
            break;
        case InstructionType::SUBFSR:
            // SUBFSR f, k: f is FSR number (0-2), k is 8-bit
            opcode = Opcodes18::SUBFSR | ((f_reg & 0x03) << 8) | (k_value & 0xFF);
            break;

        // Table Operations (PIC18)
        case InstructionType::TBLRD:
            // TBLRD instruction with mode in lower bits
            opcode = Opcodes18::TBLRD | (b_bit & 0x03);
            break;
        case InstructionType::TBLWT:
            // TBLWT instruction with mode in lower bits
            opcode = Opcodes18::TBLWT | (b_bit & 0x03);
            break;

        // Inherent
        case InstructionType::NOP:
            opcode = 0x0000;
            break;

        default:
            return 0;
    }

    return opcode;
}
