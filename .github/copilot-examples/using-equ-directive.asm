; ============================================
; Using the EQU Directive
; ============================================
; The EQU directive assigns a constant value to a label
; Syntax: LABEL EQU value
;
; Assemble with: gnsasm program.asm -a pic16
; ============================================

; === Defining Register Addresses ===
; Instead of using numeric addresses, define meaningful names

PORTA       EQU 0x05    ; Port A data register
PORTB       EQU 0x06    ; Port B data register
TRISA       EQU 0x85    ; Port A direction register (Bank 1)
TRISB       EQU 0x86    ; Port B direction register (Bank 1)
STATUS      EQU 0x03    ; Status register

; === Defining Bit Positions ===
C           EQU 0       ; Carry flag bit
Z           EQU 2       ; Zero flag bit
RP0         EQU 5       ; Bank select bit 0

; === Defining Constant Values ===
LED_ON      EQU 0xFF    ; All bits high
LED_OFF     EQU 0x00    ; All bits low
BLINK_COUNT EQU 10      ; Counter value

; === Binary and Hex Values ===
PATTERN1    EQU 0b10101010  ; Binary pattern
PATTERN2    EQU 0xAA        ; Same as above in hex

; === Symbolic References ===
; You can reference other EQU symbols
OUTPUT_PORT EQU PORTA       ; Alias for PORTA
INPUT_PORT  EQU PORTB       ; Alias for PORTB

; === Configuration Bits ===
; EQU is commonly used to define CONFIG bits
_FOSC_INTRC EQU 0x3FFC      ; Internal RC oscillator
_WDTE_OFF   EQU 0x3FFB      ; Watchdog Timer disabled
_PWRTE_ON   EQU 0x3FF7      ; Power-up Timer enabled
_MCLRE_OFF  EQU 0x3FDF      ; MCLR pin is digital I/O

; Apply configuration
__CONFIG _FOSC_INTRC & _WDTE_OFF & _PWRTE_ON & _MCLRE_OFF

; ============================================
; Main Program Using EQU Symbols
; ============================================

        ORG 0x0000

; Initialize - Set PORTA as output, PORTB as input
init:
        ; Bank 1 - Configure port directions
        BSF     STATUS, RP0     ; Select Bank 1
        MOVLW   LED_OFF         ; All outputs
        MOVWF   TRISA           ; Set PORTA as output
        MOVLW   LED_ON          ; All inputs
        MOVWF   TRISB           ; Set PORTB as input
        BCF     STATUS, RP0     ; Back to Bank 0

        ; Bank 0 - Set initial values
        MOVLW   LED_OFF
        MOVWF   OUTPUT_PORT     ; Turn off LEDs on PORTA

; Main loop - Blink LED pattern
loop:
        ; Turn on LEDs with pattern
        MOVLW   PATTERN1
        MOVWF   OUTPUT_PORT

        ; Simple delay
        CALL    delay

        ; Turn off LEDs
        MOVLW   LED_OFF
        MOVWF   OUTPUT_PORT

        ; Another delay
        CALL    delay

        GOTO    loop

; Simple delay subroutine
delay:
        MOVLW   BLINK_COUNT
        MOVWF   0x20            ; Counter variable
delay_loop:
        DECFSZ  0x20, 1         ; Decrement counter
        GOTO    delay_loop
        RETURN

        END

; ============================================
; Benefits of Using EQU
; ============================================
;
; 1. READABILITY
;    MOVWF PORTA      is clearer than    MOVWF 0x05
;
; 2. MAINTAINABILITY
;    If you change hardware, update EQU definitions in one place
;    instead of searching through all your code
;
; 3. SELF-DOCUMENTING
;    BSF STATUS, Z    is clearer than    BSF 0x03, 2
;
; 4. PORTABLE
;    Same code can work with different devices by changing EQU values
;
; 5. REDUCE ERRORS
;    Typo in "PORTA" gives error, typo in "0x05" might go unnoticed
;
; ============================================
; Common Patterns
; ============================================
;
; Register definitions:
;   REGISTER_NAME EQU 0xADDRESS
;
; Bit positions:
;   BIT_NAME EQU bit_number
;
; Constants:
;   CONSTANT_NAME EQU value
;
; Aliases:
;   NEW_NAME EQU EXISTING_NAME
;
; Config bits:
;   _CONFIG_OPTION EQU 0xVALUE
;   __CONFIG _OPT1 & _OPT2 & _OPT3
;
