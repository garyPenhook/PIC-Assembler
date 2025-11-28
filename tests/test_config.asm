; Test CONFIG directive for PIC16
; Simple program with configuration bits

        __CONFIG 0x3F72

        ORG 0x0000
start:  MOVLW 0x00
        MOVWF 0x05      ; Clear PORTA
        GOTO start

        END
