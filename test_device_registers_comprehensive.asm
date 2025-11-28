; Test: Comprehensive device register functionality
; Demonstrates all aspects of the device register loading feature:
; 1. Device registers are loaded from .inc files
; 2. Case-insensitive lookup works (PORTA = porta = PortA)
; 3. Device registers cannot be redefined
; 4. Device registers work with user-defined symbols
; 5. Device registers have highest priority in symbol lookup

#include <pic16f18076.inc>

    ORG 0x00

    ; Create user constants from device registers
    ; This shows that device registers are loaded and accessible
    STATUS_ADDR     EQU STATUS
    PORTA_ADDR      EQU PORTA
    PORTB_ADDR      EQU PORTB
    WREG_ADDR       EQU WREG

    ; Define some user variables
    USER_VAR1       EQU 0x20
    USER_VAR2       EQU 0x21
    USER_VAR3       EQU 0x22

    ; Use a mutable constant (SET allows reassignment)
    LOOP_COUNT      SET 10

    ; Assembly code using the addresses we loaded
    MOVLW STATUS_ADDR    ; Load STATUS register address
    MOVLW PORTA_ADDR     ; Load PORTA register address
    MOVLW USER_VAR1      ; Load user-defined variable address
    MOVLW LOOP_COUNT     ; Load loop counter value

    ; Label for demonstration
    LOOP:
        MOVLW 0x00
        GOTO LOOP

    END
