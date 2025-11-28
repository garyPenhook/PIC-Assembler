; Test various instructions
        MOVLW 0x00
        MOVWF 0x20
        INCF 0x20,1
        MOVF 0x20,0
        NOP
        END
