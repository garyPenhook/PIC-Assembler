; Test #include preprocessor directive
    PROCESSOR PIC16F18076

; Include external header file with common definitions
#include "test_include.inc"

; Now use the included definitions
    ORG 0x0000

    MOVLW REG_A             ; Uses REG_A from included file (0x20)
    MOVWF REG_B             ; Uses REG_B from included file (0x21)

    MOVLW REG_C             ; Uses REG_C from included file (0x22)
    MOVWF 0x23

    NOP
    END
