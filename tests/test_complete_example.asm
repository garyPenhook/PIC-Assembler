; Complete example using EQU and CONFIG
; PIC16F628A - Blink LED on PORTA

; Configuration bits
_FOSC_INTRC EQU 0x3FFC
_WDTE_OFF   EQU 0x3FFB
_PWRTE_ON   EQU 0x3FF7
_MCLRE_OFF  EQU 0x3FDF

__CONFIG _FOSC_INTRC & _WDTE_OFF & _PWRTE_ON & _MCLRE_OFF

; Register definitions
PORTA       EQU 0x05
TRISA       EQU 0x85
STATUS      EQU 0x03
RP0         EQU 5

; Constants
ALL_OUTPUT  EQU 0x00
LED_ON      EQU 0xFF
LED_OFF     EQU 0x00

        ORG 0x0000

; Initialize
init:
        BSF     STATUS, RP0     ; Bank 1
        MOVLW   ALL_OUTPUT
        MOVWF   TRISA           ; PORTA as output
        BCF     STATUS, RP0     ; Bank 0

; Main loop
loop:
        MOVLW   LED_ON
        MOVWF   PORTA
        CALL    delay

        MOVLW   LED_OFF
        MOVWF   PORTA
        CALL    delay

        GOTO    loop

; Delay subroutine
delay:
        MOVLW   0xFF
        MOVWF   0x20
delay_loop:
        DECFSZ  0x20, 1
        GOTO    delay_loop
        RETURN

        END
