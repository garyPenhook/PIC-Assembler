    ; Test assembly-time IF/ELSE directives
    PROCESSOR PIC16F18076

    ; Define a constant for condition testing
    PARAM EQU 1

    ORG 0x0000

    ; Basic IF/ELSE test
    IF PARAM == 1
        MOVLW 0x10
        MOVWF 0x20
    ELSE
        MOVLW 0x20
        MOVWF 0x21
    ENDIF

    ; Second IF block - condition is false
    IF PARAM == 2
        NOP
        NOP
    ELSE
        MOVLW 0x30
        ADDWF 0x20
    ENDIF

    END
