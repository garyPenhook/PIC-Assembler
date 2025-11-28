; Test EQU directive
PORTA   EQU 0x05
TRISA   EQU 0x85

        ORG 0x0000
start:  MOVLW 0xFF
        MOVWF PORTA     ; Should use 0x05
        GOTO start
        END
