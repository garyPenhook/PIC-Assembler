; Test CONFIG with symbolic names
; PIC16F628A example

; Define common config bits
_FOSC_INTRC    EQU 0x3FFC   ; Internal RC oscillator
_WDTE_OFF      EQU 0x3FFB   ; Watchdog Timer disabled
_PWRTE_ON      EQU 0x3FF7   ; Power-up Timer enabled
_MCLRE_OFF     EQU 0x3FDF   ; MCLR pin is digital I/O

        __CONFIG _FOSC_INTRC & _WDTE_OFF & _PWRTE_ON & _MCLRE_OFF

        ORG 0x0000
start:  MOVLW 0xFF
        MOVWF 0x05      ; Set PORTA
        GOTO start

        END
