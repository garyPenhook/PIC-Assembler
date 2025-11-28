    ; Test assembly-time ELIF directives
    PROCESSOR PIC16F18076

    MODE EQU 3

    ORG 0x0000

    ; ELIF chain test
    IF MODE == 1
        MOVLW 0x01
        MOVWF 0x20
    ELIF MODE == 2
        MOVLW 0x02
        MOVWF 0x20
    ELIF MODE == 3
        MOVLW 0x03
        MOVWF 0x20
    ELIF MODE == 4
        MOVLW 0x04
        MOVWF 0x20
    ELSE
        MOVLW 0xFF
        MOVWF 0x20
    ENDIF

    ; Another test with different initial condition
    MODE2 SET 1

    IF MODE2 == 0
        INCF 0x20
    ELIF MODE2 == 1
        NOP
    ELIF MODE2 == 2
        NOP
    ENDIF

    END
