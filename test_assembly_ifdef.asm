    ; Test assembly-time IFDEF/IFNDEF directives
    PROCESSOR PIC16F18076

    ; Define a symbol
    DEBUG EQU 1
    VERSION SET 2

    ORG 0x0000

    ; Basic IFDEF test - symbol exists
    IFDEF DEBUG
        MOVLW 0x01
        MOVWF 0x20
    ENDIF

    ; IFNDEF test - symbol doesn't exist
    IFNDEF RELEASE
        MOVLW 0x02
        MOVWF 0x21
    ENDIF

    ; IFDEF with ELSE - symbol exists, so ELSE is not taken
    IFDEF VERSION
        MOVLW 0x03
        MOVWF 0x22
    ELSE
        MOVLW 0xFF
        MOVWF 0x23
    ENDIF

    ; IFNDEF with ELSE - symbol exists, so ELSE is taken
    IFNDEF DEBUG
        MOVLW 0xFF
        MOVWF 0x24
    ELSE
        MOVLW 0x04
        MOVWF 0x24
    ENDIF

    END
