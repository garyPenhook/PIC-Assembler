; Simple EQU test
PORTA   EQU 0x05
STATUS  EQU 0x03
RP0     EQU 5

        ORG 0x0000
start:
        MOVLW 0xFF
        MOVWF PORTA
        BSF   STATUS, RP0
        GOTO  start
        END
