; ============================================
; PIC16F88 Register Definitions
; Architecture: PIC16 (14-bit instructions)
; Assemble with: gnsasm file.asm -a pic16
; ============================================
; Popular 18-pin PIC16 - upgrade path from PIC16F84
; 4KB Flash, 368 bytes RAM, 256 bytes EEPROM

; ============================================
; Core Registers (Bank 0)
; ============================================
INDF        EQU 0x00    ; Indirect addressing
TMR0        EQU 0x01    ; Timer 0
PCL         EQU 0x02    ; Program counter low
STATUS      EQU 0x03    ; Status register
FSR         EQU 0x04    ; File select register
PORTA       EQU 0x05    ; Port A (8 bits: RA0-RA7)
PORTB       EQU 0x06    ; Port B (8 bits: RB0-RB7)
PCLATH      EQU 0x0A    ; Program counter latch high
INTCON      EQU 0x0B    ; Interrupt control
PIR1        EQU 0x0C    ; Peripheral interrupt request 1
PIR2        EQU 0x0D    ; Peripheral interrupt request 2

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
TRISA       EQU 0x85    ; Port A tri-state (1=input, 0=output)
TRISB       EQU 0x86    ; Port B tri-state
PIE1        EQU 0x8C    ; Peripheral interrupt enable 1
PIE2        EQU 0x8D    ; Peripheral interrupt enable 2
PCON        EQU 0x8E    ; Power control
OSCCON      EQU 0x8F    ; Oscillator control

; ============================================
; GPIO Pin Definitions
; ============================================
; Port A (8 bits)
RA0         EQU 0       ; Pin 17
RA1         EQU 1       ; Pin 18
RA2         EQU 2       ; Pin 1
RA3         EQU 3       ; Pin 2
RA4         EQU 4       ; Pin 3
RA5         EQU 5       ; Pin 4
RA6         EQU 6       ; Pin 15
RA7         EQU 7       ; Pin 16

; Port B (8 bits)
RB0         EQU 0       ; Pin 6
RB1         EQU 1       ; Pin 7
RB2         EQU 2       ; Pin 8
RB3         EQU 3       ; Pin 9
RB4         EQU 4       ; Pin 10
RB5         EQU 5       ; Pin 11
RB6         EQU 6       ; Pin 12
RB7         EQU 7       ; Pin 13

; ============================================
; Timer Registers
; ============================================
TMR1L       EQU 0x0E    ; Timer 1 low byte
TMR1H       EQU 0x0F    ; Timer 1 high byte
T1CON       EQU 0x10    ; Timer 1 control
TMR2        EQU 0x11    ; Timer 2
T2CON       EQU 0x12    ; Timer 2 control
PR2         EQU 0x92    ; Timer 2 period register (Bank 1)

; ============================================
; CCP (Capture/Compare/PWM) Registers
; ============================================
CCPR1L      EQU 0x15    ; CCP1 register low
CCPR1H      EQU 0x16    ; CCP1 register high
CCP1CON     EQU 0x17    ; CCP1 control

; ============================================
; USART Registers
; ============================================
RCSTA       EQU 0x18    ; USART receive status and control
TXREG       EQU 0x19    ; USART transmit register
RCREG       EQU 0x1A    ; USART receive register
TXSTA       EQU 0x98    ; USART transmit status (Bank 1)
SPBRG       EQU 0x99    ; USART baud rate generator (Bank 1)

; ============================================
; Comparator Registers
; ============================================
CMCON       EQU 0x9C    ; Comparator control (Bank 1)
CVRCON      EQU 0x9D    ; Comparator voltage reference (Bank 1)

; ============================================
; ADC Registers (Not available on PIC16F88)
; ============================================
; PIC16F88 does not have an ADC module
; Use comparator for analog input

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
RBIF        EQU 0       ; RB port change interrupt flag
INTF        EQU 1       ; INT external interrupt flag
T0IF        EQU 2       ; TMR0 overflow interrupt flag
RBIE        EQU 3       ; RB port change interrupt enable
INTE        EQU 4       ; INT external interrupt enable
T0IE        EQU 5       ; TMR0 overflow interrupt enable
PEIE        EQU 6       ; Peripheral interrupt enable
GIE         EQU 7       ; Global interrupt enable

; ============================================
; Common User Variables Area
; ============================================
; Bank 0: 0x20-0x7F (96 bytes)
; Bank 1: 0xA0-0xEF (80 bytes)
; Bank 2: 0x110-0x16F (96 bytes)
; Bank 3: 0x190-0x1EF (96 bytes)
VAR_START   EQU 0x20    ; Start of general purpose RAM
COUNTER     EQU 0x20    ; Example: 8-bit counter
TEMP        EQU 0x21    ; Example: temporary storage
FLAGS       EQU 0x22    ; Example: flag byte
DELAY_L     EQU 0x23    ; Example: delay counter low
DELAY_H     EQU 0x24    ; Example: delay counter high

; ============================================
; Example Usage Patterns for PIC16F88
; ============================================

; Initialize ports (all outputs)
;       BSF STATUS, RP0      ; Select Bank 1
;       CLRF TRISA           ; Port A all outputs
;       CLRF TRISB           ; Port B all outputs
;       BCF STATUS, RP0      ; Back to Bank 0

; Disable comparators for digital I/O
;       BSF STATUS, RP0      ; Bank 1
;       MOVLW 0x07           ; Comparators off
;       MOVWF CMCON
;       BCF STATUS, RP0      ; Bank 0

; Configure internal oscillator (8MHz)
;       BSF STATUS, RP0      ; Bank 1
;       MOVLW 0x70           ; 8MHz internal oscillator
;       MOVWF OSCCON
;       BCF STATUS, RP0      ; Bank 0

; Blink LED on RB0
;       BSF PORTB, 0         ; LED on
;       CALL delay
;       BCF PORTB, 0         ; LED off
;       CALL delay

; Read button on RA0 (with pull-up)
;       BSF STATUS, RP0      ; Bank 1
;       BSF TRISA, 0         ; RA0 as input
;       BCF OPTION_REG, 7    ; Enable weak pull-ups
;       BCF STATUS, RP0      ; Bank 0
;       BTFSC PORTA, 0       ; Test RA0, skip if low (pressed)
;       GOTO not_pressed

; Configure USART (9600 baud @ 8MHz)
;       BSF STATUS, RP0      ; Bank 1
;       MOVLW 0x33           ; 9600 baud @ 8MHz
;       MOVWF SPBRG
;       MOVLW 0x24           ; Enable transmit, high speed
;       MOVWF TXSTA
;       BCF TRISB, 2         ; RB2/TX as output
;       BSF TRISB, 1         ; RB1/RX as input
;       BCF STATUS, RP0      ; Bank 0
;       MOVLW 0x90           ; Serial port enable, receive enable
;       MOVWF RCSTA

; Send byte via USART
;       MOVWF TXREG          ; Send W to USART
; wait_tx:
;       BSF STATUS, RP0      ; Bank 1
;       BTFSS TXSTA, 1       ; Check TRMT flag
;       GOTO wait_tx
;       BCF STATUS, RP0      ; Bank 0

; Receive byte via USART
; wait_rx:
;       BTFSS PIR1, 5        ; Check RCIF flag
;       GOTO wait_rx
;       MOVF RCREG, 0        ; Read received byte to W

; Configure PWM on CCP1 (RB3)
;       BSF STATUS, RP0      ; Bank 1
;       BCF TRISB, 3         ; RB3 as output (CCP1)
;       MOVLW 0xFF           ; PWM period
;       MOVWF PR2
;       BCF STATUS, RP0      ; Bank 0
;       MOVLW 0x7F           ; 50% duty cycle
;       MOVWF CCPR1L
;       MOVLW 0x0C           ; PWM mode
;       MOVWF CCP1CON
;       MOVLW 0x05           ; TMR2 on, prescaler 1:4
;       MOVWF T2CON

; Configure comparator
;       BSF STATUS, RP0      ; Bank 1
;       MOVLW 0x02           ; Comparator mode
;       MOVWF CMCON
;       MOVLW 0xA0           ; CVref enabled, 2.5V
;       MOVWF CVRCON
;       BCF STATUS, RP0      ; Bank 0

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

; Interrupt-on-change for Port B
;       BSF INTCON, 3        ; Enable RBIE
;       BSF INTCON, 7        ; Enable GIE

; ============================================
; PIC16F88 Pinout (18-pin DIP)
; ============================================
; Pin 1:  RA2/AN2/VREF
; Pin 2:  RA3/AN3/CMP1
; Pin 3:  RA4/T0CKI/CMP2
; Pin 4:  RA5/MCLR/VPP
; Pin 5:  VSS (Ground)
; Pin 6:  RB0/INT
; Pin 7:  RB1/RX/DT
; Pin 8:  RB2/TX/CK
; Pin 9:  RB3/CCP1
; Pin 10: RB4/PGM
; Pin 11: RB5
; Pin 12: RB6/T1OSO/T1CKI/PGC
; Pin 13: RB7/T1OSI/PGD
; Pin 14: VDD (+5V)
; Pin 15: RA6/OSC2/CLKOUT
; Pin 16: RA7/OSC1/CLKIN
; Pin 17: RA0/AN0
; Pin 18: RA1/AN1

; ============================================
; Key Features of PIC16F88
; ============================================
; - 18-pin package with 16 I/O pins
; - 4096 words Flash program memory
; - 368 bytes RAM (largest in PIC16 mid-range)
; - 256 bytes EEPROM
; - 8MHz internal oscillator
; - No ADC (use comparator instead)
; - 2 analog comparators with voltage reference
; - USART for serial communication
; - Timer0, Timer1, Timer2
; - Capture/Compare/PWM module
; - Interrupt-on-change on Port B
; - In-circuit programming
; - Popular upgrade from PIC16F84A
; - Wide operating voltage (2.0V to 5.5V)
