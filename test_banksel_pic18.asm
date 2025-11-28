    ; Test BANKSEL directive for PIC18 (indirect addressing)
    PROCESSOR PIC18F57Q43

    ; Define some symbols in different banks
    BANK0_VAR EQU 0x20    ; Bank 0
    BANK1_VAR EQU 0x120   ; Bank 1
    BANK2_VAR EQU 0x220   ; Bank 2

    ORG 0x0000

    ; Access Bank 0 variable via BANKISEL
    BANKSEL BANK0_VAR
    MOVLW 0x10
    MOVWF 0x00       ; INDF0 register

    ; Access Bank 1 variable via BANKISEL
    BANKSEL BANK1_VAR
    MOVLW 0x20
    MOVWF 0x00       ; INDF0 register

    ; Access Bank 2 variable via BANKISEL
    BANKSEL BANK2_VAR
    MOVLW 0x30
    MOVWF 0x00       ; INDF0 register

    END
