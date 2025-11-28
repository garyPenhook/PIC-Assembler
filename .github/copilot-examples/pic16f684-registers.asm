; ============================================
; PIC16F684 Register Definitions
; Architecture: PIC16 (14-bit instructions)
; Assemble with: gnsasm file.asm -a pic16
; ============================================
; Popular 14-pin PIC16 with ADC and comparator
; 2KB Flash, 128 bytes RAM, 256 bytes EEPROM

; ============================================
; Core Registers (Bank 0)
; ============================================
INDF        EQU 0x00    ; Indirect addressing
TMR0        EQU 0x01    ; Timer 0
PCL         EQU 0x02    ; Program counter low
STATUS      EQU 0x03    ; Status register
FSR         EQU 0x04    ; File select register
PORTA       EQU 0x05    ; Port A (6 bits: RA0-RA5)
PORTC       EQU 0x07    ; Port C (6 bits: RC0-RC5)
PCLATH      EQU 0x0A    ; Program counter latch high
INTCON      EQU 0x0B    ; Interrupt control
PIR1        EQU 0x0C    ; Peripheral interrupt request 1

; ============================================
; STATUS Register Bit Definitions (0x03)
; ============================================
C           EQU 0       ; Carry/borrow flag
DC          EQU 1       ; Digit carry/borrow flag
Z           EQU 2       ; Zero flag
PD          EQU 3       ; Power-down flag
TO          EQU 4       ; Time-out flag
RP0         EQU 5       ; Register bank select bit 0
RP1         EQU 6       ; Register bank select bit 1
IRP         EQU 7       ; Indirect addressing bank select

; ============================================
; Bank 1 Registers (Set RP0)
; ============================================
OPTION_REG  EQU 0x81    ; Option register
TRISA       EQU 0x85    ; Port A tri-state
TRISC       EQU 0x87    ; Port C tri-state
PIE1        EQU 0x8C    ; Peripheral interrupt enable 1
PCON        EQU 0x8E    ; Power control
OSCCON      EQU 0x8F    ; Oscillator control

; ============================================
; GPIO Pin Definitions
; ============================================
; Port A (6 bits)
RA0         EQU 0       ; Pin 13
RA1         EQU 1       ; Pin 12
RA2         EQU 2       ; Pin 11
RA3         EQU 3       ; Pin 4 (input only, MCLR)
RA4         EQU 4       ; Pin 3
RA5         EQU 5       ; Pin 2

; Port C (6 bits)
RC0         EQU 0       ; Pin 10
RC1         EQU 1       ; Pin 9
RC2         EQU 2       ; Pin 8
RC3         EQU 3       ; Pin 7
RC4         EQU 4       ; Pin 6
RC5         EQU 5       ; Pin 5

; ============================================
; Timer Registers
; ============================================
TMR1L       EQU 0x0E    ; Timer 1 low byte
TMR1H       EQU 0x0F    ; Timer 1 high byte
T1CON       EQU 0x10    ; Timer 1 control

; ============================================
; Comparator Registers
; ============================================
CMCON0      EQU 0x19    ; Comparator control 0
CMCON1      EQU 0x1A    ; Comparator control 1
VRCON       EQU 0x99    ; Voltage reference control (Bank 1)

; ============================================
; ADC Registers
; ============================================
ADRESH      EQU 0x1E    ; ADC result high byte
ADCON0      EQU 0x1F    ; ADC control 0
ADRESL      EQU 0x9E    ; ADC result low byte (Bank 1)
ANSEL       EQU 0x9F    ; Analog select (Bank 1)

; ============================================
; EEPROM Registers (Bank 1)
; ============================================
EEDATA      EQU 0x9A    ; EEPROM data (Bank 1)
EEADR       EQU 0x9B    ; EEPROM address (Bank 1)
EECON1      EQU 0x9C    ; EEPROM control 1 (Bank 1)
EECON2      EQU 0x9D    ; EEPROM control 2 (Bank 1)

; ============================================
; INTCON Register Bits (0x0B)
; ============================================
RAIF        EQU 0       ; RA port change interrupt flag
INTF        EQU 1       ; INT external interrupt flag
T0IF        EQU 2       ; TMR0 overflow interrupt flag
RAIE        EQU 3       ; RA port change interrupt enable
INTE        EQU 4       ; INT external interrupt enable
T0IE        EQU 5       ; TMR0 overflow interrupt enable
PEIE        EQU 6       ; Peripheral interrupt enable
GIE         EQU 7       ; Global interrupt enable

; ============================================
; Common User Variables Area
; ============================================
; Bank 0: 0x20-0x5F (64 bytes)
; Bank 1: 0xA0-0xEF (80 bytes)
VAR_START   EQU 0x20    ; Start of general purpose RAM
COUNTER     EQU 0x20    ; Example: 8-bit counter
TEMP        EQU 0x21    ; Example: temporary storage
FLAGS       EQU 0x22    ; Example: flag byte
DELAY_L     EQU 0x23    ; Example: delay counter low
DELAY_H     EQU 0x24    ; Example: delay counter high

; ============================================
; Example Usage Patterns for PIC16F684
; ============================================

; Initialize ports (all outputs except RA3)
;       BSF STATUS, RP0      ; Select Bank 1
;       CLRF TRISA           ; Port A all outputs (RA3 always input)
;       CLRF TRISC           ; Port C all outputs
;       BCF STATUS, RP0      ; Back to Bank 0

; Disable comparators for digital I/O
;       MOVLW 0x07           ; Comparators off
;       MOVWF CMCON0

; Disable analog inputs (all digital)
;       BSF STATUS, RP0      ; Bank 1
;       CLRF ANSEL           ; All digital I/O
;       BCF STATUS, RP0      ; Bank 0

; Configure internal oscillator (8MHz)
;       BSF STATUS, RP0      ; Bank 1
;       MOVLW 0x70           ; 8MHz internal oscillator
;       MOVWF OSCCON
;       BCF STATUS, RP0      ; Bank 0

; Blink LED on RC0
;       BSF PORTC, 0         ; LED on
;       CALL delay
;       BCF PORTC, 0         ; LED off
;       CALL delay

; Read button on RA4 (with pull-up)
;       BSF STATUS, RP0      ; Bank 1
;       BSF TRISA, 4         ; RA4 as input
;       BCF OPTION_REG, 7    ; Enable weak pull-ups
;       BCF STATUS, RP0      ; Bank 0
;       BTFSC PORTA, 4       ; Test RA4, skip if low (pressed)
;       GOTO not_pressed

; Configure ADC (10-bit, AN0)
;       BSF STATUS, RP0      ; Bank 1
;       BSF ANSEL, 0         ; AN0 as analog input
;       BCF STATUS, RP0      ; Bank 0
;       MOVLW 0x81           ; ADC on, channel AN0
;       MOVWF ADCON0

; Start ADC conversion
;       BSF ADCON0, 1        ; Start conversion (GO/DONE bit)
; wait: BTFSC ADCON0, 1      ; Wait for completion
;       GOTO wait
;       ; Result in ADRESH:ADRESL

; Configure comparator (C1+ vs C1-)
;       MOVLW 0x02           ; Comparator mode
;       MOVWF CMCON0
;       BSF STATUS, RP0      ; Bank 1
;       MOVLW 0x02           ; Voltage reference 2.5V
;       MOVWF VRCON
;       BCF STATUS, RP0      ; Bank 0

; Interrupt-on-change for Port A
;       BSF INTCON, 3        ; Enable RAIE
;       BSF INTCON, 7        ; Enable GIE

; Read EEPROM
;       BSF STATUS, RP0      ; Bank 1
;       MOVLW 0x00           ; Address to read
;       MOVWF EEADR
;       BSF EECON1, 0        ; Initiate read (RD bit)
;       MOVF EEDATA, 0       ; Read data to W
;       BCF STATUS, RP0      ; Bank 0

; Write EEPROM
;       BSF STATUS, RP0      ; Bank 1
;       MOVLW 0x00           ; Address
;       MOVWF EEADR
;       MOVLW 0x42           ; Data to write
;       MOVWF EEDATA
;       BSF EECON1, 2        ; WREN=1 (enable writes)
;       MOVLW 0x55           ; Required sequence
;       MOVWF EECON2
;       MOVLW 0xAA
;       MOVWF EECON2
;       BSF EECON1, 1        ; WR=1 (start write)
; wait_ee:
;       BTFSC EECON1, 1      ; Wait for write complete
;       GOTO wait_ee
;       BCF EECON1, 2        ; WREN=0 (disable writes)
;       BCF STATUS, RP0      ; Bank 0

; ============================================
; PIC16F684 Pinout (14-pin DIP)
; ============================================
; Pin 1:  VDD (+5V or 3.3V)
; Pin 2:  RA5/T1CKI/OSC1/CLKIN
; Pin 3:  RA4/AN3/T1G/OSC2/CLKOUT
; Pin 4:  RA3/MCLR/VPP (input only)
; Pin 5:  RC5/CCP1
; Pin 6:  RC4/C2OUT
; Pin 7:  RC3/AN7/C1OUT
; Pin 8:  RC2/AN6/COUT
; Pin 9:  RC1/AN5/C12IN1-
; Pin 10: RC0/AN4/C12IN0-
; Pin 11: RA2/AN2/T0CKI/INT/C1OUT
; Pin 12: RA1/AN1/CIN-/VREF/ICSPCLK
; Pin 13: RA0/AN0/CIN+/ICSPDAT
; Pin 14: VSS (Ground)

; ============================================
; Key Features of PIC16F684
; ============================================
; - 14-pin package with 12 I/O pins
; - 2048 words Flash program memory
; - 128 bytes RAM
; - 256 bytes EEPROM
; - 8MHz internal oscillator
; - 8 channels 10-bit ADC
; - 2 analog comparators
; - Timer0, Timer1
; - Capture/Compare/PWM module
; - Interrupt-on-change
; - In-circuit programming
; - Wide operating voltage (2.0V to 5.5V)
