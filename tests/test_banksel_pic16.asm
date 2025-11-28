    ; Test BANKSEL directive for PIC16
    PROCESSOR PIC16F18076

    ; Define some symbols in different banks
    BANK0_VAR EQU 0x20    ; Bank 0 (0x00-0x7F)
    BANK1_VAR EQU 0xA0    ; Bank 1 (0x80-0xFF)
    BANK2_VAR EQU 0x120   ; Bank 2 (0x100-0x17F)

    ORG 0x0000

    ; Access Bank 0 variable
    BANKSEL BANK0_VAR
    MOVLW 0x10
    MOVWF BANK0_VAR

    ; Access Bank 1 variable
    BANKSEL BANK1_VAR
    MOVLW 0x20
    MOVWF BANK1_VAR

    ; Access Bank 2 variable
    BANKSEL BANK2_VAR
    MOVLW 0x30
    MOVWF BANK2_VAR

    ; Back to Bank 0
    BANKSEL BANK0_VAR
    MOVF BANK0_VAR, 0

    END
