; Test program with only instructions
    ORG 0x0100

    MOVLW 0x42
    MOVWF 0x20
    GOTO 0x0100

    END
