; ============================================
; PIC18F Configuration Bits
; ============================================
; Common configuration bit definitions for PIC18 devices
; Use these with __CONFIG directive
;
; Example: __CONFIG 0x25
;
; Assemble with: gnsasm program.asm -a pic18
; ============================================

; === PIC18F Configuration ===
; PIC18 devices typically use direct hex values or individual CONFIG registers
; Configuration words start at address 0x300000

; === Common PIC18F4550 CONFIG1L (0x300000) ===
_PLLDIV_1      EQU 0xF8     ; No prescale (4 MHz oscillator input drives PLL directly)
_PLLDIV_2      EQU 0xF9     ; Divide by 2 (8 MHz oscillator input)
_PLLDIV_5      EQU 0xFC     ; Divide by 5 (20 MHz oscillator input)

_CPUDIV_OSC1   EQU 0xE7     ; [Primary Oscillator Src: /1][96 MHz PLL Src: /2]
_CPUDIV_OSC2   EQU 0xEF     ; [Primary Oscillator Src: /2][96 MHz PLL Src: /3]

_USBDIV_1      EQU 0xDF     ; USB clock source comes directly from primary oscillator
_USBDIV_2      EQU 0xFF     ; USB clock source comes from 96 MHz PLL divided by 2

; === Common PIC18F4550 CONFIG1H (0x300001) ===
_FOSC_HS       EQU 0xFC     ; HS oscillator (HS)
_FOSC_HSPLL    EQU 0xFE     ; HS oscillator, PLL enabled (HSPLL)
_FOSC_INTOSCIO EQU 0xF8     ; Internal oscillator

_FCMEN_OFF     EQU 0xBF     ; Fail-Safe Clock Monitor disabled
_FCMEN_ON      EQU 0xFF     ; Fail-Safe Clock Monitor enabled

_IESO_OFF      EQU 0x7F     ; Oscillator Switchover mode disabled
_IESO_ON       EQU 0xFF     ; Oscillator Switchover mode enabled

; === CONFIG2L (0x300002) ===
_PWRT_ON       EQU 0xFE     ; PWRT enabled
_PWRT_OFF      EQU 0xFF     ; PWRT disabled

_BOR_OFF       EQU 0xF9     ; Brown-out Reset disabled
_BOR_ON        EQU 0xFF     ; Brown-out Reset enabled

_BORV_45       EQU 0xF3     ; 4.5V
_BORV_42       EQU 0xF7     ; 4.2V
_BORV_28       EQU 0xFB     ; 2.8V
_BORV_20       EQU 0xFF     ; 2.0V

; === CONFIG2H (0x300003) ===
_WDT_OFF       EQU 0xFE     ; Watchdog Timer disabled
_WDT_ON        EQU 0xFF     ; Watchdog Timer enabled

_WDTPS_1       EQU 0xE1     ; 1:1
_WDTPS_128     EQU 0xF1     ; 1:128
_WDTPS_32768   EQU 0xFF     ; 1:32768

; === CONFIG3H (0x300005) ===
_PBADEN_OFF    EQU 0xFD     ; PORTB<4:0> pins are configured as digital I/O on Reset
_PBADEN_ON     EQU 0xFF     ; PORTB<4:0> pins are configured as analog input on Reset

_LPT1OSC_OFF   EQU 0xFB     ; Timer1 configured for higher power operation
_LPT1OSC_ON    EQU 0xFF     ; Timer1 configured for low-power operation

_MCLRE_OFF     EQU 0x7F     ; RE3 input pin enabled; MCLR disabled
_MCLRE_ON      EQU 0xFF     ; MCLR pin enabled; RE3 input pin disabled

; === CONFIG4L (0x300006) ===
_LVP_OFF       EQU 0xFB     ; Single-Supply ICSP disabled
_LVP_ON        EQU 0xFF     ; Single-Supply ICSP enabled

_DEBUG_ON      EQU 0x7F     ; Background debugger enabled, RB6 and RB7 are dedicated
_DEBUG_OFF     EQU 0xFF     ; Background debugger disabled

; === CONFIG5L/H - Code Protection ===
_CP0_ON        EQU 0xFE     ; Block 0 code-protected
_CP0_OFF       EQU 0xFF     ; Block 0 not code-protected

; ============================================
; Typical Configuration Examples
; ============================================

; Example 1: Basic PIC18F4550 USB configuration
; __CONFIG 0xFC     ; CONFIG1L: PLLDIV_5, CPUDIV_OSC1, USBDIV_2
; (Note: Multiple CONFIG words require multiple __CONFIG directives)

; Example 2: Simple internal oscillator configuration
; __CONFIG 0x25

; Example 3: HS oscillator with PLL
; __CONFIG 0x3E

; ============================================
; Usage in Your Program
; ============================================
;       __CONFIG 0x25
;
;       ORG 0x0000
; start:
;       MOVLW 0x00
;       MOVWF PORTB, 0
;       BRA start
;       END
;
; NOTE: For complete PIC18 configuration, you typically need to set
; multiple CONFIG registers. Each requires a separate __CONFIG directive
; or use device-specific include files from Microchip.
