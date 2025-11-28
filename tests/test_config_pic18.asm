; Test CONFIG for PIC18
; PIC18F configuration example

        __CONFIG 0x25

        ORG 0x0000
start:  MOVLW 0x00
        MOVWF 0x05, 0
        BRA start

        END
