; Test program for PIC18-Q40
; Simple counter using PIC18-specific instructions

        ORG 0x0000

        MOVLW 0x00      ; Move 0 to W
        MOVWF 0x20      ; Store in file register 0x20

loop:   ADDWF 0x20,1    ; Add W to register 0x20
        MOVF 0x20,0     ; Move 0x20 to W
        CPFSEQ 0x0A     ; Compare with 10, skip if equal
        BRA loop        ; Branch back to loop (PIC18 instruction)

        NOP
        END
