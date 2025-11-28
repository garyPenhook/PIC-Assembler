; Test: Mixed device registers and user-defined symbols
; Tests that device registers work alongside user-defined constants and variables

#include <pic16f18076.inc>

    ORG 0x00

    ; Define user constants (should work with device registers)
    TEMP_VAR    EQU 0x20        ; User-defined variable address
    COUNTER     EQU 0x21        ; Another user-defined address
    DELAY_MS    SET 100         ; Changeable constant

    ; Create constants from device registers
    DEV_WREG    EQU WREG        ; Copy device register address
    DEV_STATUS  EQU STATUS      ; Copy device register address
    DEV_PORTA   EQU PORTA       ; Copy device register address

    ; Use the constants we created
    MOVLW TEMP_VAR
    MOVLW COUNTER
    MOVLW DEV_WREG
    MOVLW DEV_STATUS
    MOVLW DEV_PORTA
    MOVLW DELAY_MS

    ; Device registers have priority - cannot override them
    ; WREG    EQU 0x50          ; This would error if uncommented

    END
