; ============================================
; PIC16F690 Register Definitions
; Architecture: PIC16 (14-bit instructions)
; Assemble with: gnsasm file.asm -a pic16
; ============================================
; Feature-rich 20-pin PIC16 with enhanced peripherals
; 4KB Flash, 256 bytes RAM, 256 bytes EEPROM
; NOTE: Despite being 20-pin, this is included for its popularity

; ============================================
; Core Registers (Bank 0)
; ============================================
INDF        EQU 0x00    ; Indirect addressing
TMR0        EQU 0x01    ; Timer 0
PCL         EQU 0x02    ; Program counter low
STATUS      EQU 0x03    ; Status register
FSR         EQU 0x04    ; File select register
PORTA       EQU 0x05    ; Port A (6 bits: RA0-RA5)
PORTB       EQU 0x06    ; Port B (8 bits: RB4-RB7)
PORTC       EQU 0x07    ; Port C (8 bits: RC0-RC7)
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
TRISA       EQU 0x85    ; Port A tri-state
TRISB       EQU 0x86    ; Port B tri-state
TRISC       EQU 0x87    ; Port C tri-state
PIE1        EQU 0x8C    ; Peripheral interrupt enable 1
PIE2        EQU 0x8D    ; Peripheral interrupt enable 2
PCON        EQU 0x8E    ; Power control
OSCCON      EQU 0x8F    ; Oscillator control

; ============================================
; GPIO Pin Definitions
; ============================================
; Port A (6 bits)
RA0         EQU 0       ; Pin 19
RA1         EQU 1       ; Pin 18
RA2         EQU 2       ; Pin 17
RA3         EQU 3       ; Pin 4 (input only, MCLR)
RA4         EQU 4       ; Pin 3
RA5         EQU 5       ; Pin 2

; Port B (4 bits: RB4-RB7)
RB4         EQU 4       ; Pin 13
RB5         EQU 5       ; Pin 12
RB6         EQU 6       ; Pin 11
RB7         EQU 7       ; Pin 10

; Port C (8 bits)
RC0         EQU 0       ; Pin 16
RC1         EQU 1       ; Pin 15
RC2         EQU 2       ; Pin 14
RC3         EQU 3       ; Pin 7
RC4         EQU 4       ; Pin 6
RC5         EQU 5       ; Pin 5
RC6         EQU 6       ; Pin 8
RC7         EQU 7       ; Pin 9

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
CCPR1L      EQU 0x13    ; CCP1 register low
CCPR1H      EQU 0x14    ; CCP1 register high
CCP1CON     EQU 0x15    ; CCP1 control

; ============================================
; EUSART Registers
; ============================================
BAUDCTL     EQU 0x9B    ; Baud rate control (Bank 1)
SPBRGH      EQU 0x9A    ; USART baud rate generator high (Bank 1)
SPBRG       EQU 0x99    ; USART baud rate generator (Bank 1)
RCREG       EQU 0x1A    ; USART receive register
TXREG       EQU 0x19    ; USART transmit register
TXSTA       EQU 0x98    ; USART transmit status (Bank 1)
RCSTA       EQU 0x18    ; USART receive status

; ============================================
; Comparator Registers
; ============================================
CM1CON0     EQU 0x107   ; Comparator C1 control (Bank 2)
CM2CON0     EQU 0x108   ; Comparator C2 control (Bank 2)
CM2CON1     EQU 0x109   ; Comparator C2 control 1 (Bank 2)
VRCON       EQU 0x97    ; Voltage reference control (Bank 1)
SRCON       EQU 0x185   ; SR latch control (Bank 3)

; ============================================
; ADC Registers
; ============================================
ADRESH      EQU 0x1E    ; ADC result high byte
ADCON0      EQU 0x1F    ; ADC control 0
ADRESL      EQU 0x9E    ; ADC result low byte (Bank 1)
ANSEL       EQU 0x188   ; Analog select (Bank 3)
ANSELH      EQU 0x189   ; Analog select high (Bank 3)

; ============================================
; EEPROM Registers (Bank 2)
; ============================================
EEDAT       EQU 0x10C   ; EEPROM data (Bank 2)
EEADR       EQU 0x10D   ; EEPROM address (Bank 2)
EEDATH      EQU 0x10E   ; EEPROM data high (Bank 2)
EEADRH      EQU 0x10F   ; EEPROM address high (Bank 2)

; ============================================
; EEPROM Control (Bank 3)
; ============================================
EECON1      EQU 0x18C   ; EEPROM control 1 (Bank 3)
EECON2      EQU 0x18D   ; EEPROM control 2 (Bank 3)

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
VAR_START   EQU 0x20    ; Start of general purpose RAM
COUNTER     EQU 0x20    ; Example: 8-bit counter
TEMP        EQU 0x21    ; Example: temporary storage
FLAGS       EQU 0x22    ; Example: flag byte
DELAY_L     EQU 0x23    ; Example: delay counter low
DELAY_H     EQU 0x24    ; Example: delay counter high

; ============================================
; Example Usage Patterns for PIC16F690
; ============================================

; Initialize all ports as outputs
;       BSF STATUS, RP0      ; Select Bank 1
;       CLRF TRISA           ; Port A all outputs (RA3 always input)
;       CLRF TRISB           ; Port B all outputs
;       CLRF TRISC           ; Port C all outputs
;       BCF STATUS, RP0      ; Back to Bank 0

; Disable analog inputs (all digital)
;       BSF STATUS, RP0      ; Bank 1
;       BSF STATUS, RP1      ; Select Bank 3
;       CLRF ANSEL           ; All digital I/O
;       CLRF ANSELH
;       BCF STATUS, RP1      ; Back to Bank 1
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

; Read button on RB4 (with pull-up)
;       BSF STATUS, RP0      ; Bank 1
;       BSF TRISB, 4         ; RB4 as input
;       BCF OPTION_REG, 7    ; Enable weak pull-ups
;       BCF STATUS, RP0      ; Bank 0
;       BTFSC PORTB, 4       ; Test RB4, skip if low (pressed)
;       GOTO not_pressed

; Configure ADC (10-bit, AN0)
;       BSF STATUS, RP0      ; Bank 1
;       BSF STATUS, RP1      ; Select Bank 3
;       BSF ANSEL, 0         ; AN0 as analog input
;       BCF STATUS, RP1      ; Back to Bank 1
;       BCF STATUS, RP0      ; Bank 0
;       MOVLW 0x81           ; ADC on, channel AN0
;       MOVWF ADCON0

; Start ADC conversion
;       BSF ADCON0, 1        ; Start conversion (GO/DONE bit)
; wait: BTFSC ADCON0, 1      ; Wait for completion
;       GOTO wait
;       ; Result in ADRESH:ADRESL

; Configure EUSART (9600 baud @ 8MHz)
;       BSF STATUS, RP0      ; Bank 1
;       MOVLW 0x33           ; 9600 baud @ 8MHz
;       MOVWF SPBRG
;       MOVLW 0x24           ; Enable transmit, high speed
;       MOVWF TXSTA
;       BCF TRISC, 6         ; TX pin as output
;       BSF TRISC, 7         ; RX pin as input
;       BCF STATUS, RP0      ; Bank 0
;       MOVLW 0x90           ; Serial port enable, receive enable
;       MOVWF RCSTA

; Send byte via EUSART
;       MOVWF TXREG          ; Send W to USART
; wait_tx:
;       BSF STATUS, RP0      ; Bank 1
;       BTFSS TXSTA, 1       ; Check TRMT flag
;       GOTO wait_tx
;       BCF STATUS, RP0      ; Bank 0

; Receive byte via EUSART
; wait_rx:
;       BTFSS PIR1, 5        ; Check RCIF flag
;       GOTO wait_rx
;       MOVF RCREG, 0        ; Read received byte to W

; Configure PWM on CCP1 (RC5)
;       BSF STATUS, RP0      ; Bank 1
;       BCF TRISC, 5         ; RC5 as output (CCP1)
;       MOVLW 0xFF           ; PWM period
;       MOVWF PR2
;       BCF STATUS, RP0      ; Bank 0
;       MOVLW 0x7F           ; 50% duty cycle
;       MOVWF CCPR1L
;       MOVLW 0x0C           ; PWM mode
;       MOVWF CCP1CON
;       MOVLW 0x05           ; TMR2 on, prescaler 1:4
;       MOVWF T2CON

; Read EEPROM
;       BSF STATUS, RP0      ; Bank 1
;       BSF STATUS, RP1      ; Select Bank 2
;       MOVLW 0x00           ; Address to read
;       MOVWF EEADR
;       BSF STATUS, RP1      ; Select Bank 3 for EECON1
;       BSF EECON1, 0        ; Initiate read (RD bit)
;       BCF STATUS, RP1      ; Back to Bank 2
;       MOVF EEDAT, 0        ; Read data to W
;       BCF STATUS, RP0      ; Bank 0

; ============================================
; PIC16F690 Pinout (20-pin DIP)
; ============================================
; Pin 1:  VDD (+5V or 3.3V)
; Pin 2:  RA5/T1CKI/OSC1/CLKIN
; Pin 3:  RA4/AN3/T1G/OSC2/CLKOUT
; Pin 4:  RA3/MCLR/VPP (input only)
; Pin 5:  RC5/CCP1
; Pin 6:  RC4/C2OUT/SRQ
; Pin 7:  RC3/AN7/P1B/C12IN3-
; Pin 8:  RC6/AN8/SS
; Pin 9:  RC7/AN9/SDO
; Pin 10: RB7/TX/CK
; Pin 11: RB6/SCK/SCL
; Pin 12: RB5/AN11/RX/DT
; Pin 13: RB4/AN10/SDI/SDA
; Pin 14: RC2/AN6/P1D/C12IN2-
; Pin 15: RC1/AN5/C12IN1-
; Pin 16: RC0/AN4/C2IN+
; Pin 17: RA2/AN2/T0CKI/INT/C1OUT
; Pin 18: RA1/AN1/C12IN0-/VREF/ICSPCLK
; Pin 19: RA0/AN0/C1IN+/ICSPDAT/ULPWU
; Pin 20: VSS (Ground)

; ============================================
; Key Features of PIC16F690
; ============================================
; - 20-pin package with 18 I/O pins
; - 4096 words Flash program memory
; - 256 bytes RAM
; - 256 bytes EEPROM
; - 8MHz internal oscillator
; - 12 channels 10-bit ADC
; - 2 analog comparators with SR latch
; - Enhanced USART
; - SPI/I2C (Master mode)
; - Timer0, Timer1, Timer2
; - Enhanced Capture/Compare/PWM
; - Interrupt-on-change on all ports
; - Ultra low-power wake-up
; - Wide operating voltage (2.0V to 5.5V)
