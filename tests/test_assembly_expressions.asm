    ; Test assembly-time conditional expressions
    PROCESSOR PIC16F18076

    ORG 0x0000

    ; Test arithmetic expressions
    IF 5+3==8
        MOVLW 0x01
        MOVWF 0x20
    ENDIF

    IF 10-3!=4
        MOVLW 0x02
        MOVWF 0x21
    ENDIF

    IF 4*2==8
        MOVLW 0x03
        MOVWF 0x22
    ENDIF

    IF 16/4==4
        MOVLW 0x04
        MOVWF 0x23
    ENDIF

    ; Test bitwise XOR
    IF 0x05^0x03==0x06
        MOVLW 0x05
        MOVWF 0x24
    ENDIF

    ; Test bitwise OR
    IF 0x08|0x04==0x0C
        MOVLW 0x06
        MOVWF 0x25
    ENDIF

    ; Test bitwise AND
    IF 0x0F&0x03==0x03
        MOVLW 0x07
        MOVWF 0x26
    ENDIF

    ; Test modulo
    IF 17%10==7
        MOVLW 0x08
        MOVWF 0x27
    ENDIF

    END
