; Advanced PIC18-Q40 test program
; Demonstrates PIC18-specific instructions

        ORG 0x0000

        ; Initialize registers
        MOVLW 0x55      ; Load pattern
        MOVWF 0x20      ; Store in file register

        ; Test PIC18-specific byte operations
        ADDWFC 0x20,1   ; Add with Carry
        SETF 0x21       ; Set all bits in file register
        NEGF 0x22       ; Negate file register

        ; Test PIC18-specific bit operations
        BTG 0x20,3      ; Toggle bit (PIC18 specific)
        CPFSEQ 0x20     ; Compare file with W, skip if equal
        CPFSGT 0x21     ; Compare file greater than W

        ; Test conditional branches (PIC18 specific)
loop:   MOVLW 0x00
        BZ end          ; Branch if Zero
        BRA loop        ; Unconditional relative branch

end:    NOP
        END
