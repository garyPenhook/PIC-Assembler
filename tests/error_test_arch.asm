; Test: Architecture mismatch
; This file uses PIC18-specific BRA instruction with PIC16 (default)
        MOVLW 0x00
        BRA label       ; BRA is PIC18 only!
        NOP
        END
