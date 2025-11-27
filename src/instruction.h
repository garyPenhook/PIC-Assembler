#pragma once

#include <string>
#include <map>
#include <cstdint>

// Supported architecture
enum class Architecture {
    PIC12,  // PIC12 Baseline (12-bit instruction word)
    PIC16,  // PIC16 and PIC16F (14-bit instruction word)
    PIC18   // PIC18 and PIC18-Q40 (16-bit instruction word)
};

enum class InstructionType {
    // ========== ALL ARCHITECTURES SHARED ==========
    // Byte-Oriented Operations
    ADDWF, ANDWF, CLRF, CLRW, COMF, DECF, DECFSZ, INCF, INCFSZ,
    IORWF, MOVF, MOVWF, NOP, RLF, RRF, SUBWF, SWAPF, XORWF,

    // Bit-Oriented Operations
    BCF, BSF, BTFSC, BTFSS,

    // Literal and Control Operations (PIC16/PIC16E/PIC18)
    ADDLW, ANDLW, CALL, CLRWDT, GOTO, IORLW, MOVLW, RETFIE, RETLW, RETURN, SLEEP, SUBLW, XORLW,

    // ========== PIC12 BASELINE ONLY ==========
    // Special registers (PIC12 baseline only - not in PIC16/PIC18)
    OPTION, TRIS,

    // ========== PIC16 ENHANCED & PIC18 SHARED ==========
    // Carry variants (exist in both PIC16E and PIC18)
    ADDWFC,

    // ========== PIC16 ENHANCED MID-RANGE ONLY (cpu_mid_v10) ==========
    // Shift Instructions (PIC16 Enhanced only)
    LSLF, LSRF, ASRF,

    // Branch (PIC16 Enhanced only)
    BRW,

    // Indirect Addressing (PIC16 Enhanced only)
    MOVIW, MOVWI,

    // Literal Operations (PIC16 Enhanced only)
    MOVLP,

    // ========== PIC18 SPECIFIC ==========
    // Additional Byte-Oriented (PIC18 only)
    DCFSNZ, INFSNZ, MOVFF, MULWF, NEGF, RLCF, RLNCF, RRCF, RRNCF, SETF, SUBFWB, SUBWFB, TSTFSZ,

    // Additional Bit-Oriented (PIC18)
    BTG,

    // Compare & Skip (PIC18)
    CPFSEQ, CPFSGT, CPFSLT,

    // Conditional Branch (PIC18)
    BC, BN, BNC, BNN, BNOV, BNZ, BOV, BRA, BZ,

    // Additional Control (PIC18)
    CALLW, RCALL,

    // Inherent (PIC18)
    DAW, POP, PUSH, RESET,

    // Literal Operations (PIC18)
    ADDFSR, LFSR, MOVLB, MULLW, SUBFSR,

    // Table Operations (PIC18)
    TBLRD, TBLWT,

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

    // Set target architecture
    void setArchitecture(Architecture arch) { targetArch = arch; }
    Architecture getArchitecture() const { return targetArch; }

    // Get instruction type from mnemonic
    InstructionType getMnemonicType(const std::string& mnemonic) const;
    std::string getTypeName(InstructionType type) const;

    // Check if instruction is valid for current architecture
    bool isValidForArchitecture(InstructionType type) const;

    // Encode instruction with operands (returns opcode appropriate for architecture)
    uint16_t encodeInstruction(InstructionType type, uint8_t f_reg, uint8_t d_bit,
                              uint8_t b_bit, uint16_t k_value) const;

    // Get instruction word size in bits (14 for PIC16, 16 for PIC18)
    uint8_t getInstructionWordSize() const;

private:
    InstructionSet();

    Architecture targetArch = Architecture::PIC16;
    std::map<std::string, InstructionType> mnemonicMap;
    std::map<InstructionType, std::string> typeNameMap;

    void initializeMnemonics();

    // Architecture-specific encoders
    uint16_t encodePIC12Instruction(InstructionType type, uint8_t f_reg, uint8_t d_bit,
                                    uint8_t b_bit, uint16_t k_value) const;
    uint16_t encodePIC16Instruction(InstructionType type, uint8_t f_reg, uint8_t d_bit,
                                    uint8_t b_bit, uint16_t k_value) const;
    uint16_t encodePIC18Instruction(InstructionType type, uint8_t f_reg, uint8_t d_bit,
                                    uint8_t b_bit, uint16_t k_value) const;
};

// Opcode constants - PIC12 Baseline (12-bit values)
namespace Opcodes12 {
    // Byte-Oriented (format: 00ddaaffffffff where dd=dest, aa=opcode, fff=file reg)
    constexpr uint16_t ADDWF  = 0x0700;
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

    // Bit-Oriented (format: 01bbbffffffff where bbb=bit, fff=file reg)
    constexpr uint16_t BCF    = 0x1000;
    constexpr uint16_t BSF    = 0x1400;
    constexpr uint16_t BTFSC  = 0x1800;
    constexpr uint16_t BTFSS  = 0x1C00;

    // Literal and Control (format: xxxkkkkkkkkkk)
    constexpr uint16_t ADDLW  = 0x3E00;
    constexpr uint16_t ANDLW  = 0x3900;
    constexpr uint16_t CALL   = 0x2000;
    constexpr uint16_t CLRWDT = 0x0064;
    constexpr uint16_t GOTO   = 0x2800;
    constexpr uint16_t IORLW  = 0x3800;
    constexpr uint16_t MOVLW  = 0x3000;
    constexpr uint16_t RETLW  = 0x3400;
    constexpr uint16_t SLEEP  = 0x0063;
    constexpr uint16_t SUBLW  = 0x3C00;
    constexpr uint16_t XORLW  = 0x3A00;

    // PIC12 Baseline Special (12-bit)
    constexpr uint16_t OPTION = 0x0062;  // Load OPTION register
    constexpr uint16_t TRIS   = 0x0060;  // Load TRIS register (f=5,6,7 for ports)
}

// Opcode constants - PIC16 Classic Mid-Range (14-bit values)
namespace Opcodes16Classic {
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

// Opcode constants - PIC16 Enhanced Mid-Range (14-bit values, cpu_mid_v10)
namespace Opcodes16Enhanced {
    // Shift Instructions (14-bit, PIC16 Enhanced only)
    constexpr uint16_t LSLF   = 0x3600;  // Logical shift left file
    constexpr uint16_t LSRF   = 0x3E00;  // Logical shift right file
    constexpr uint16_t ASRF   = 0x3800;  // Arithmetic shift right file

    // Branch (14-bit, PIC16 Enhanced only)
    constexpr uint16_t BRW    = 0x000B;  // Branch using W

    // Indirect Addressing (14-bit, with mode bits, PIC16 Enhanced only)
    constexpr uint16_t MOVIW  = 0x0100;  // Move indirect to W
    constexpr uint16_t MOVWI  = 0x0900;  // Move W to indirect

    // Literal Operations (PIC16 Enhanced only)
    constexpr uint16_t MOVLP  = 0x3100;  // Move literal to PCLATH

    // Note: ADDWFC, MOVLB, SUBWFB, BRA, ADDFSR exist in both PIC16E and PIC18
    // but with different encodings - see their definitions above in Opcodes16Classic
}

// Opcode constants - PIC18 (16-bit values)
namespace Opcodes18 {
    // Byte-Oriented Operations
    constexpr uint16_t ADDWF   = 0x2400;
    constexpr uint16_t ADDWFC  = 0x2000;
    constexpr uint16_t ANDWF   = 0x0400;
    constexpr uint16_t CLRF    = 0x6A00;
    constexpr uint16_t COMF    = 0x1C00;
    constexpr uint16_t DECF    = 0x0400;
    constexpr uint16_t DCFSNZ  = 0x4B00;
    constexpr uint16_t INCF    = 0x2800;
    constexpr uint16_t INCFSZ  = 0x3C00;
    constexpr uint16_t INFSNZ  = 0x4A00;
    constexpr uint16_t IORWF   = 0x1000;
    constexpr uint16_t MOVF    = 0x5000;
    constexpr uint16_t MOVFF   = 0xC000;
    constexpr uint16_t MOVWF   = 0x6E00;
    constexpr uint16_t MULWF   = 0x0200;
    constexpr uint16_t NEGF    = 0x6C00;
    constexpr uint16_t RLCF    = 0x3400;
    constexpr uint16_t RLNCF   = 0x4400;
    constexpr uint16_t RRCF    = 0x3000;
    constexpr uint16_t RRNCF   = 0x4000;
    constexpr uint16_t SETF    = 0x6800;
    constexpr uint16_t SUBFWB  = 0x5400;
    constexpr uint16_t SUBWF   = 0x5C00;
    constexpr uint16_t SUBWFB  = 0x5800;
    constexpr uint16_t SWAPF   = 0x3800;
    constexpr uint16_t TSTFSZ  = 0x6600;
    constexpr uint16_t XORWF   = 0x0600;

    // Bit-Oriented
    constexpr uint16_t BCF     = 0x9000;
    constexpr uint16_t BSF     = 0x8000;
    constexpr uint16_t BTG     = 0x7000;
    constexpr uint16_t BTFSC   = 0xB000;
    constexpr uint16_t BTFSS   = 0xA000;

    // Compare and Skip
    constexpr uint16_t CPFSEQ  = 0x6200;
    constexpr uint16_t CPFSGT  = 0x6400;
    constexpr uint16_t CPFSLT  = 0x6000;

    // Conditional Branch
    constexpr uint16_t BC      = 0xE200;
    constexpr uint16_t BN      = 0xE600;
    constexpr uint16_t BNC     = 0xE300;
    constexpr uint16_t BNN     = 0xE700;
    constexpr uint16_t BNOV    = 0xE500;
    constexpr uint16_t BNZ     = 0xE100;
    constexpr uint16_t BOV     = 0xE400;
    constexpr uint16_t BRA     = 0xD000;
    constexpr uint16_t BZ      = 0xE000;

    // Control & Literal
    constexpr uint16_t CALL    = 0xEC00;
    constexpr uint16_t CALLW   = 0x0012;
    constexpr uint16_t CLRWDT  = 0x0004;
    constexpr uint16_t GOTO    = 0xEF00;
    constexpr uint16_t RCALL   = 0xD800;
    constexpr uint16_t RETFIE  = 0x0010;
    constexpr uint16_t RETLW   = 0x0C00;
    constexpr uint16_t RETURN  = 0x0012;
    constexpr uint16_t SLEEP   = 0x0003;

    // Literal Operations
    constexpr uint16_t ADDLW   = 0x0F00;
    constexpr uint16_t ANDLW   = 0x0B00;
    constexpr uint16_t IORLW   = 0x0900;
    constexpr uint16_t MOVLW   = 0x0E00;
    constexpr uint16_t SUBLW   = 0x0800;
    constexpr uint16_t XORLW   = 0x0A00;

    // Additional Literal Operations (PIC18)
    constexpr uint16_t ADDFSR  = 0xE800;
    constexpr uint16_t LFSR    = 0xEE00;
    constexpr uint16_t MOVLB   = 0x0100;
    constexpr uint16_t MULLW   = 0x0D00;
    constexpr uint16_t SUBFSR  = 0xE900;

    // Inherent/Special (PIC18)
    constexpr uint16_t DAW     = 0x0007;
    constexpr uint16_t POP     = 0x0006;
    constexpr uint16_t PUSH    = 0x0005;
    constexpr uint16_t RESET   = 0x00FF;

    // Table Operations (PIC18)
    constexpr uint16_t TBLRD   = 0x0800;
    constexpr uint16_t TBLWT   = 0x0C00;
}

