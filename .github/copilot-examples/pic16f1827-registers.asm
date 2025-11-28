; ============================================
; PIC16F1827 Register Definitions
; Architecture: PIC16 (14-bit enhanced mid-range)
; Assemble with: gnsasm file.asm -a pic16
; ============================================
; Modern enhanced 18-pin PIC16 with advanced peripherals
; 4KB Flash, 384 bytes RAM, 256 bytes EEPROM

; ============================================
; Core Registers (Bank 0, Access anywhere)
; ============================================
INDF0       EQU 0x00    ; Indirect addressing 0
INDF1       EQU 0x01    ; Indirect addressing 1
PCL         EQU 0x02    ; Program counter low
STATUS      EQU 0x03    ; Status register
FSR0L       EQU 0x04    ; FSR0 low byte
FSR0H       EQU 0x05    ; FSR0 high byte
FSR1L       EQU 0x06    ; FSR1 low byte
FSR1H       EQU 0x07    ; FSR1 high byte
BSR         EQU 0x08    ; Bank select register
WREG        EQU 0x09    ; Working register
PCLATH      EQU 0x0A    ; Program counter latch high
INTCON      EQU 0x0B    ; Interrupt control

; ============================================
; STATUS Register Bit Definitions (0x03)
; ============================================
C           EQU 0       ; Carry/borrow flag
DC          EQU 1       ; Digit carry/borrow flag
Z           EQU 2       ; Zero flag
PD          EQU 3       ; Power-down flag
TO          EQU 4       ; Time-out flag

; ============================================
; GPIO Registers
; ============================================
; Port A
PORTA       EQU 0x0C    ; Port A data (8 bits: RA0-RA7)
LATA        EQU 0x10C   ; Port A latch (Bank 2)
TRISA       EQU 0x8C    ; Port A tri-state (Bank 1)
ANSELA      EQU 0x18C   ; Analog select (Bank 3)
WPUA        EQU 0x20C   ; Weak pull-ups (Bank 4)

; Port B
PORTB       EQU 0x0D    ; Port B data (8 bits: RB0-RB7)
LATB        EQU 0x10D   ; Port B latch (Bank 2)
TRISB       EQU 0x8D    ; Port B tri-state (Bank 1)
ANSELB      EQU 0x18D   ; Analog select (Bank 3)
WPUB        EQU 0x20D   ; Weak pull-ups (Bank 4)

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
; Timer 0
TMR0        EQU 0x15    ; Timer 0
OPTION_REG  EQU 0x95    ; Option register (Bank 1)

; Timer 1
TMR1L       EQU 0x16    ; Timer 1 low
TMR1H       EQU 0x17    ; Timer 1 high
T1CON       EQU 0x18    ; Timer 1 control
T1GCON      EQU 0x19    ; Timer 1 gate control

; Timer 2
TMR2        EQU 0x1A    ; Timer 2
PR2         EQU 0x1B    ; Timer 2 period
T2CON       EQU 0x1C    ; Timer 2 control

; Timer 4
TMR4        EQU 0x415   ; Timer 4 (Bank 8)
PR4         EQU 0x416   ; Timer 4 period (Bank 8)
T4CON       EQU 0x417   ; Timer 4 control (Bank 8)

; Timer 6
TMR6        EQU 0x41C   ; Timer 6 (Bank 8)
PR6         EQU 0x41D   ; Timer 6 period (Bank 8)
T6CON       EQU 0x41E   ; Timer 6 control (Bank 8)

; ============================================
; CCP/PWM Registers
; ============================================
; CCP1
CCPR1L      EQU 0x291   ; CCP1 register low (Bank 5)
CCPR1H      EQU 0x292   ; CCP1 register high (Bank 5)
CCP1CON     EQU 0x293   ; CCP1 control (Bank 5)

; CCP2
CCPR2L      EQU 0x298   ; CCP2 register low (Bank 5)
CCPR2H      EQU 0x299   ; CCP2 register high (Bank 5)
CCP2CON     EQU 0x29A   ; CCP2 control (Bank 5)

; PWM
PWM1DCL     EQU 0x614   ; PWM1 duty cycle low (Bank 12)
PWM1DCH     EQU 0x615   ; PWM1 duty cycle high (Bank 12)
PWM1CON     EQU 0x616   ; PWM1 control (Bank 12)

PWM2DCL     EQU 0x617   ; PWM2 duty cycle low (Bank 12)
PWM2DCH     EQU 0x618   ; PWM2 duty cycle high (Bank 12)
PWM2CON     EQU 0x619   ; PWM2 control (Bank 12)

; ============================================
; ADC Registers
; ============================================
ADRESL      EQU 0x9B    ; ADC result low (Bank 1)
ADRESH      EQU 0x9C    ; ADC result high (Bank 1)
ADCON0      EQU 0x9D    ; ADC control 0 (Bank 1)
ADCON1      EQU 0x9E    ; ADC control 1 (Bank 1)

; ============================================
; Comparator Registers
; ============================================
CM1CON0     EQU 0x111   ; Comparator 1 control 0 (Bank 2)
CM1CON1     EQU 0x112   ; Comparator 1 control 1 (Bank 2)
CM2CON0     EQU 0x113   ; Comparator 2 control 0 (Bank 2)
CM2CON1     EQU 0x114   ; Comparator 2 control 1 (Bank 2)
CMOUT       EQU 0x115   ; Comparator output (Bank 2)
BORCON      EQU 0x116   ; Brown-out reset control (Bank 2)
FVRCON      EQU 0x117   ; Fixed voltage reference (Bank 2)
DACCON0     EQU 0x118   ; DAC control 0 (Bank 2)
DACCON1     EQU 0x119   ; DAC control 1 (Bank 2)

; ============================================
; EUSART Registers
; ============================================
RCREG       EQU 0x199   ; Receive register (Bank 3)
TXREG       EQU 0x19A   ; Transmit register (Bank 3)
SPBRGL      EQU 0x19B   ; Baud rate generator low (Bank 3)
SPBRGH      EQU 0x19C   ; Baud rate generator high (Bank 3)
RCSTA       EQU 0x19D   ; Receive status (Bank 3)
TXSTA       EQU 0x19E   ; Transmit status (Bank 3)
BAUDCON     EQU 0x19F   ; Baud control (Bank 3)

; ============================================
; I2C/SPI (MSSP) Registers
; ============================================
SSP1BUF     EQU 0x211   ; SSP1 buffer (Bank 4)
SSP1ADD     EQU 0x212   ; SSP1 address (Bank 4)
SSP1MSK     EQU 0x213   ; SSP1 mask (Bank 4)
SSP1STAT    EQU 0x214   ; SSP1 status (Bank 4)
SSP1CON1    EQU 0x215   ; SSP1 control 1 (Bank 4)
SSP1CON2    EQU 0x216   ; SSP1 control 2 (Bank 4)
SSP1CON3    EQU 0x217   ; SSP1 control 3 (Bank 4)

; ============================================
; Interrupt Registers
; ============================================
PIR1        EQU 0x11    ; Peripheral interrupt request 1
PIR2        EQU 0x12    ; Peripheral interrupt request 2
PIE1        EQU 0x91    ; Peripheral interrupt enable 1 (Bank 1)
PIE2        EQU 0x92    ; Peripheral interrupt enable 2 (Bank 1)
IOCBP       EQU 0x394   ; Interrupt-on-change positive (Bank 7)
IOCBN       EQU 0x395   ; Interrupt-on-change negative (Bank 7)
IOCBF       EQU 0x396   ; Interrupt-on-change flag (Bank 7)

; ============================================
; Oscillator Control
; ============================================
OSCCON      EQU 0x99    ; Oscillator control (Bank 1)
OSCTUNE     EQU 0x98    ; Oscillator tuning (Bank 1)

; ============================================
; EEPROM Registers
; ============================================
EEADRL      EQU 0x191   ; EEPROM address low (Bank 3)
EEADRH      EQU 0x192   ; EEPROM address high (Bank 3)
EEDATL      EQU 0x193   ; EEPROM data low (Bank 3)
EEDATH      EQU 0x194   ; EEPROM data high (Bank 3)
EECON1      EQU 0x195   ; EEPROM control 1 (Bank 3)
EECON2      EQU 0x196   ; EEPROM control 2 (Bank 3)

; ============================================
; Common User Variables
; ============================================
; Linear memory: 0x20-0x6F (80 bytes, accessible from any bank)
VAR_START   EQU 0x20
COUNTER     EQU 0x20
TEMP        EQU 0x21
FLAGS       EQU 0x22
DELAY_L     EQU 0x23
DELAY_H     EQU 0x24

; ============================================
; Example Usage Patterns for PIC16F1827
; ============================================

; Initialize GPIO (no bank switching needed for basic ops)
;       BANKSEL TRISA        ; Select bank with TRISA
;       CLRF TRISA           ; All outputs
;       CLRF TRISB           ; All outputs
;       BANKSEL ANSELA
;       CLRF ANSELA          ; All digital I/O
;       CLRF ANSELB
;       BANKSEL PORTA
;       CLRF PORTA
;       CLRF PORTB

; Modern way using BANKSEL macro equivalent
;       MOVLW 0x00
;       BANKSEL TRISA
;       MOVWF TRISA
;       MOVWF TRISB

; Write to GPIO
;       BSF PORTA, 0         ; Set RA0 high
;       BCF PORTB, 1         ; Set RB1 low

; Configure internal oscillator (32MHz)
;       BANKSEL OSCCON
;       MOVLW 0xF0           ; 32MHz HFINTOSC with PLL
;       MOVWF OSCCON

; Configure weak pull-ups on RB0
;       BANKSEL WPUB
;       BSF WPUB, 0          ; Enable pull-up on RB0
;       BANKSEL OPTION_REG
;       BCF OPTION_REG, 7    ; Enable WPUEN (global pull-up enable)

; Configure ADC (10-bit, AN0)
;       BANKSEL ANSELA
;       BSF ANSELA, 0        ; RA0 as analog input
;       BANKSEL ADCON0
;       MOVLW 0x01           ; ADC on, channel AN0
;       MOVWF ADCON0
;       MOVLW 0x10           ; Left justified, Vdd/Vss ref
;       MOVWF ADCON1

; Start ADC conversion
;       BSF ADCON0, 1        ; Start (GO bit)
; wait: BTFSC ADCON0, 1      ; Wait for completion
;       GOTO wait
;       ; Result in ADRESH:ADRESL

; Configure EUSART (9600 @ 32MHz)
;       BANKSEL SPBRGL
;       MOVLW 0xCF           ; SPBRGH:SPBRGL = 0x0CF for 9600
;       MOVWF SPBRGL
;       MOVLW 0x24           ; BRGH=1, TXEN=1
;       MOVWF TXSTA
;       MOVLW 0x90           ; SPEN=1, CREN=1
;       MOVWF RCSTA

; Send byte via EUSART
;       BANKSEL TXREG
;       MOVWF TXREG
; wait_tx:
;       BTFSS TXSTA, 1       ; Check TRMT
;       GOTO wait_tx

; Configure PWM (RB3)
;       BANKSEL TRISB
;       BCF TRISB, 3         ; RB3 as output
;       MOVLW 0xFF           ; PWM period
;       MOVWF PR2
;       BANKSEL PWM1DCH
;       MOVLW 0x7F           ; 50% duty cycle
;       MOVWF PWM1DCH
;       MOVLW 0x80           ; PWM enabled
;       MOVWF PWM1CON
;       BANKSEL T2CON
;       MOVLW 0x04           ; TMR2 on
;       MOVWF T2CON

; Configure I2C Master (100kHz @ 32MHz)
;       BANKSEL SSP1ADD
;       MOVLW 0x4F           ; 100kHz @ 32MHz
;       MOVWF SSP1ADD
;       BANKSEL SSP1CON1
;       MOVLW 0x28           ; I2C Master mode
;       MOVWF SSP1CON1

; Interrupt-on-change (wake on RB1 change)
;       BANKSEL IOCBP
;       BSF IOCBP, 1         ; Enable positive edge
;       BSF IOCBN, 1         ; Enable negative edge
;       BSF INTCON, 3        ; Enable IOCIE
;       BSF INTCON, 7        ; Enable GIE

; ============================================
; PIC16F1827 Pinout (18-pin DIP)
; ============================================
; Pin 1:  RA2/AN2/VREF/CVREF/T0CKI/INT/C1IN2-
; Pin 2:  RA3/AN3/VREF+/C1IN3-
; Pin 3:  RA4/AN4/T1G/C1OUT
; Pin 4:  RA5/MCLR/VPP
; Pin 5:  VSS (Ground)
; Pin 6:  RB0/AN12/CCP1/P1A/SRI/C12IN0-
; Pin 7:  RB1/AN10/P1C/C12IN1-/UART_DT/SDA
; Pin 8:  RB2/AN8/P1B/SDA
; Pin 9:  RB3/AN9/CCP2/P2A/SRQ
; Pin 10: RB4/AN11/P1D/SDA/UART_DT
; Pin 11: RB5/AN13/P2B/T1G/SCL/UART_CK
; Pin 12: RB6/AN5/CCP3/P3A/PGC/SCL
; Pin 13: RB7/AN6/PGD
; Pin 14: VDD (+5V or 3.3V)
; Pin 15: RA6/OSC2/CLKOUT
; Pin 16: RA7/OSC1/CLKIN
; Pin 17: RA0/AN0/DACOUT/C1IN+/ICSPDAT/ULPWU
; Pin 18: RA1/AN1/VREF-/C1IN0-/ICSPCLK/ULPWU

; ============================================
; Key Features of PIC16F1827
; ============================================
; - Enhanced mid-range core (more instructions)
; - Linear memory (no bank switching for variables)
; - 32MHz internal oscillator with PLL
; - 12 channel 10-bit ADC
; - Enhanced USART
; - MSSP (I2C/SPI Master/Slave)
; - 3 CCP modules
; - 3 PWM modules
; - 2 Comparators with voltage reference
; - DAC output
; - 256 bytes EEPROM
; - Interrupt-on-change
; - Multiple timers (TMR0, TMR1, TMR2, TMR4, TMR6)
; - Multiple power saving modes
; - Wide operating voltage (1.8V to 5.5V)
