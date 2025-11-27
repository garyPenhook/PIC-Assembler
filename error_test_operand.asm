; Test: Invalid operand
        MOVWF 256       ; File register out of range (0-255)
        BCF 0x20, 9     ; Bit position out of range (0-7)
        NOP
        END
