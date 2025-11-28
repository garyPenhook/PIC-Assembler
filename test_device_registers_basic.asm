; Test: Basic device register resolution from .inc file
; Tests that device registers can be used by their symbolic names after #include

#include <pic16f18076.inc>

    ORG 0x00

    ; Define user variables using device register values
    ; This demonstrates that device registers have been loaded and are accessible
    MY_WREG_ADDR    EQU WREG    ; Should be 0x09
    MY_STATUS_ADDR  EQU STATUS  ; Should be 0x03
    MY_PORTA_ADDR   EQU PORTA   ; Should be 0x0C
    MY_PORTB_ADDR   EQU PORTB   ; Should be 0x0D

    ; Use the constants we just created
    MOVLW MY_WREG_ADDR
    MOVLW MY_STATUS_ADDR
    MOVLW MY_PORTA_ADDR
    MOVLW MY_PORTB_ADDR

    END
