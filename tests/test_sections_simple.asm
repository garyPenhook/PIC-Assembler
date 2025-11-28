; Test basic CODE and UDATA sections
    PROCESSOR PIC16F1847

; Test implicit CODE section
    MOVLW 0x00
    MOVWF 0x20

; Test explicit CODE section with address
RESET_ADDR CODE 0x0000
    MOVLW 0x01

; Test UDATA section
MY_VARS UDATA 0x20

; Switch back to CODE
CODE
    MOVLW 0x55
    GOTO RESET_ADDR

    END
