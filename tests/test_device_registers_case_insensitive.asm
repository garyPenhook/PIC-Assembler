; Test: Case-insensitive device register name resolution
; Tests that register names work regardless of case (PORTA = porta = PortA)

#include <pic16f18076.inc>

    ORG 0x00

    ; Define constants using different case variations of device register names
    ; All should resolve to the same value
    VAR1    EQU WREG        ; Uppercase
    VAR2    EQU wreg        ; Lowercase
    VAR3    EQU Wreg        ; Mixed case

    VAR4    EQU STATUS      ; Uppercase
    VAR5    EQU status      ; Lowercase
    VAR6    EQU StAtUs      ; Mixed case

    VAR7    EQU PORTA       ; Uppercase
    VAR8    EQU porta       ; Lowercase
    VAR9    EQU PoRtA       ; Mixed case

    ; Use the variables we created
    MOVLW VAR1
    MOVLW VAR2
    MOVLW VAR3

    END
