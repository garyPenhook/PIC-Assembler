; ============================================
; PIC16F628A Configuration Bits
; ============================================
; Common configuration bit definitions for PIC16 mid-range devices
; Use these with __CONFIG directive
;
; Example: __CONFIG _FOSC_INTRC & _WDTE_OFF & _PWRTE_ON & _MCLRE_OFF
;
; Assemble with: gnsasm program.asm -a pic16
; ============================================

; === Oscillator Selection ===
_FOSC_LP       EQU 0x3FFC   ; LP oscillator
_FOSC_XT       EQU 0x3FFD   ; XT oscillator
_FOSC_HS       EQU 0x3FFE   ; HS oscillator
_FOSC_INTRC    EQU 0x3FFF   ; Internal RC oscillator (most common)

; === Watchdog Timer ===
_WDTE_OFF      EQU 0x3FFB   ; Watchdog Timer disabled (common for development)
_WDTE_ON       EQU 0x3FFF   ; Watchdog Timer enabled

; === Power-up Timer ===
_PWRTE_ON      EQU 0x3FF7   ; Power-up Timer enabled (recommended)
_PWRTE_OFF     EQU 0x3FFF   ; Power-up Timer disabled

; === MCLR Pin Function ===
_MCLRE_OFF     EQU 0x3FDF   ; MCLR pin is digital I/O (RA5)
_MCLRE_ON      EQU 0x3FFF   ; MCLR pin is MCLR (reset input)

; === Brown-out Reset ===
_BOREN_OFF     EQU 0x3FBF   ; Brown-out Reset disabled
_BOREN_ON      EQU 0x3FFF   ; Brown-out Reset enabled

; === Low-Voltage Programming ===
_LVP_OFF       EQU 0x3F7F   ; Low-voltage programming disabled (recommended)
_LVP_ON        EQU 0x3FFF   ; Low-voltage programming enabled

; === Code Protection ===
_CP_OFF        EQU 0x3FFF   ; Code protection OFF (for development)
_CP_ON         EQU 0x1FFF   ; Code protection ON

; === Data EEPROM Code Protection ===
_CPD_OFF       EQU 0x3FFF   ; Data memory code protection OFF
_CPD_ON        EQU 0x2FFF   ; Data memory code protection ON

; ============================================
; Common Configuration Examples
; ============================================

; Example 1: Internal oscillator, no watchdog, power-up timer, MCLR disabled
; __CONFIG _FOSC_INTRC & _WDTE_OFF & _PWRTE_ON & _MCLRE_OFF

; Example 2: HS oscillator (external crystal), watchdog enabled, MCLR enabled
; __CONFIG _FOSC_HS & _WDTE_ON & _PWRTE_ON & _MCLRE_ON

; Example 3: Internal oscillator, development settings
; __CONFIG _FOSC_INTRC & _WDTE_OFF & _PWRTE_ON & _MCLRE_OFF & _LVP_OFF & _CP_OFF

; Example 4: Using hex value directly
; __CONFIG 0x3F72

; ============================================
; Usage in Your Program
; ============================================
;       INCLUDE "pic16-config-bits.asm"
;       __CONFIG _FOSC_INTRC & _WDTE_OFF & _PWRTE_ON & _MCLRE_OFF
;
;       ORG 0x0000
; start:
;       MOVLW 0xFF
;       MOVWF PORTA
;       GOTO start
;       END
