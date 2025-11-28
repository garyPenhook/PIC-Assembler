; Demonstration of listing file generation
; This file shows how the assembler can generate a .lst file

    ORG 0x00

    ; Initialize
START:
    MOVLW 0xFF
    MOVWF 0x20

    ; Main loop
LOOP:
    INCF 0x20
    DECF 0x21
    BTFSS 0x03, 2    ; Check STATUS Z bit
    GOTO LOOP

    ; Done
    GOTO START

    END
