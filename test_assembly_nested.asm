    ; Test nested assembly-time conditionals
    PROCESSOR PIC16F18076

    ENABLE EQU 1
    LEVEL EQU 2

    ORG 0x0000

    ; Nested IF blocks
    IF ENABLE == 1
        MOVLW 0x10
        MOVWF 0x20

        IF LEVEL == 1
            MOVLW 0x01
            MOVWF 0x21
        ELIF LEVEL == 2
            MOVLW 0x02
            MOVWF 0x21
        ELSE
            MOVLW 0x03
            MOVWF 0x21
        ENDIF

        NOP
    ELSE
        MOVLW 0xFF
        MOVWF 0x20
    ENDIF

    ; Nested IFDEF blocks
    IFDEF ENABLE
        IFDEF LEVEL
            MOVLW 0x04
            MOVWF 0x22
        ENDIF
    ENDIF

    END
