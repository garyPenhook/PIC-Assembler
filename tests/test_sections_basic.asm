; Test basic CODE and UDATA sections
    PROCESSOR PIC16F1847

; Test implicit CODE section (code before any section directive)
    MOVLW 0x00
    MOVWF 0x20

; Test explicit CODE section with address
RESET CODE 0x0000
    MOVLW 0x01
    MOVWF 0x21

; Test UDATA section with address
MY_VARS UDATA 0x20
counter RES 1
temp    RES 2
flags   RES 1

; Test CODE section continuation (switch back)
MAIN_CODE CODE
main:
    CLRF counter
    MOVLW 0x55
    MOVWF temp
    GOTO main

    END
