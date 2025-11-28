; Test: Redefinition protection for device registers
; Tests that attempting to redefine device registers with EQU or SET produces an error

#include <pic16f18076.inc>

    ORG 0x00

    ; These should cause errors - attempting to redefine device registers
    WREG        EQU 0x20        ; ERROR: Cannot redefine device register WREG

    NOP

    END
