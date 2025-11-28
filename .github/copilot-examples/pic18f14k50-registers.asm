; ============================================
; PIC18F14K50 Register Definitions
; Architecture: PIC18 (16-bit instructions)
; Assemble with: gnsasm file.asm -a pic18
; ============================================
; Compact 20-pin PIC18 with USB capability
; 16KB Flash, 768 bytes RAM, 256 bytes EEPROM

; ============================================
; Core Registers (Access Bank, always accessible)
; ============================================
TOSU        EQU 0xFFF    ; Top of stack upper
TOSH        EQU 0xFFE    ; Top of stack high
TOSL        EQU 0xFFD    ; Top of stack low
STKPTR      EQU 0xFFC    ; Stack pointer
PCLATU      EQU 0xFFB    ; Program counter latch upper
PCLATH      EQU 0xFFA    ; Program counter latch high
PCL         EQU 0xFF9    ; Program counter low
TBLPTRU     EQU 0xFF8    ; Table pointer upper
TBLPTRH     EQU 0xFF7    ; Table pointer high
TBLPTRL     EQU 0xFF6    ; Table pointer low
TABLAT      EQU 0xFF5    ; Table latch
PRODH       EQU 0xFF4    ; Product high
PRODL       EQU 0xFF3    ; Product low
INTCON      EQU 0xFF2    ; Interrupt control
INTCON2     EQU 0xFF1    ; Interrupt control 2
INTCON3     EQU 0xFF0    ; Interrupt control 3
INDF0       EQU 0xFEF    ; Indirect file register 0
POSTINC0    EQU 0xFEE    ; Post-increment FSR0
POSTDEC0    EQU 0xFED    ; Post-decrement FSR0
PREINC0     EQU 0xFEC    ; Pre-increment FSR0
PLUSW0      EQU 0xFEB    ; FSR0 + WREG
FSR0H       EQU 0xFEA    ; File select register 0 high
FSR0L       EQU 0xFE9    ; File select register 0 low
WREG        EQU 0xFE8    ; Working register
INDF1       EQU 0xFE7    ; Indirect file register 1
POSTINC1    EQU 0xFE6    ; Post-increment FSR1
POSTDEC1    EQU 0xFE5    ; Post-decrement FSR1
PREINC1     EQU 0xFE4    ; Pre-increment FSR1
PLUSW1      EQU 0xFE3    ; FSR1 + WREG
FSR1H       EQU 0xFE2    ; File select register 1 high
FSR1L       EQU 0xFE1    ; File select register 1 low
BSR         EQU 0xFE0    ; Bank select register

; ============================================
; STATUS Register (Access Bank)
; ============================================
STATUS      EQU 0xFD8    ; Status register
; STATUS bits
C           EQU 0        ; Carry/borrow flag
DC          EQU 1        ; Digit carry/borrow flag
Z           EQU 2        ; Zero flag
OV          EQU 3        ; Overflow flag
N           EQU 4        ; Negative flag

; ============================================
; GPIO Registers (Access Bank)
; ============================================
; Port A
PORTA       EQU 0xF80    ; Port A data (8 bits: RA0-RA7)
LATA        EQU 0xF89    ; Port A latch
TRISA       EQU 0xF92    ; Port A tri-state
ANSEL       EQU 0xF7E    ; Analog select for RA0-RA7
ANSELH      EQU 0xF7F    ; Analog select for RB4-RB7

; Port B
PORTB       EQU 0xF81    ; Port B data (8 bits: RB4-RB7)
LATB        EQU 0xF8A    ; Port B latch
TRISB       EQU 0xF93    ; Port B tri-state
WPUB        EQU 0xF77    ; Weak pull-ups Port B

; Port C
PORTC       EQU 0xF82    ; Port C data (8 bits: RC0-RC7)
LATC        EQU 0xF8B    ; Port C latch
TRISC       EQU 0xF94    ; Port C tri-state

; ============================================
; GPIO Pin Definitions
; ============================================
; Port A (8 bits)
RA0         EQU 0        ; Pin 19
RA1         EQU 1        ; Pin 18
RA2         EQU 2        ; Pin 1
RA3         EQU 3        ; Pin 2
RA4         EQU 4        ; Pin 3
RA5         EQU 5        ; Pin 4
RA6         EQU 6        ; Pin 15 (OSC2)
RA7         EQU 7        ; Pin 16 (OSC1)

; Port B (4 bits: RB4-RB7)
RB4         EQU 4        ; Pin 13
RB5         EQU 5        ; Pin 12
RB6         EQU 6        ; Pin 11
RB7         EQU 7        ; Pin 10

; Port C (8 bits)
RC0         EQU 0        ; Pin 17
RC1         EQU 1        ; Pin 9
RC2         EQU 2        ; Pin 8
RC3         EQU 3        ; Pin 7 (SCL/SCK)
RC4         EQU 4        ; Pin 6 (USB D-)
RC5         EQU 5        ; Pin 5 (USB D+)
RC6         EQU 6        ; Pin 8 (TX)
RC7         EQU 7        ; Pin 9 (RX)

; ============================================
; Timer Registers
; ============================================
; Timer 0 (16-bit)
TMR0L       EQU 0xFD6    ; Timer 0 low byte
TMR0H       EQU 0xFD7    ; Timer 0 high byte
T0CON       EQU 0xFD5    ; Timer 0 control

; Timer 1 (16-bit)
TMR1L       EQU 0xFCE    ; Timer 1 low byte
TMR1H       EQU 0xFCF    ; Timer 1 high byte
T1CON       EQU 0xFCD    ; Timer 1 control

; Timer 2 (8-bit)
TMR2        EQU 0xFBC    ; Timer 2
PR2         EQU 0xFBB    ; Timer 2 period register
T2CON       EQU 0xFBA    ; Timer 2 control

; Timer 3 (16-bit)
TMR3L       EQU 0xFB3    ; Timer 3 low byte
TMR3H       EQU 0xFB4    ; Timer 3 high byte
T3CON       EQU 0xFB1    ; Timer 3 control

; ============================================
; CCP/PWM Registers
; ============================================
; ECCP1 (Enhanced CCP)
CCPR1L      EQU 0xFBE    ; CCP1 register low
CCPR1H      EQU 0xFBF    ; CCP1 register high
CCP1CON     EQU 0xFBD    ; CCP1 control
ECCP1AS     EQU 0xFB6    ; ECCP1 auto-shutdown
PWM1CON     EQU 0xFB7    ; PWM1 control
PSTRCON     EQU 0xFB9    ; PWM steering control

; ============================================
; ADC Registers
; ============================================
ADRESH      EQU 0xFC4    ; ADC result high
ADRESL      EQU 0xFC3    ; ADC result low
ADCON0      EQU 0xFC2    ; ADC control 0
ADCON1      EQU 0xFC1    ; ADC control 1
ADCON2      EQU 0xFC0    ; ADC control 2

; ============================================
; Comparator Registers
; ============================================
CM1CON0     EQU 0xF6B    ; Comparator 1 control 0
CM2CON0     EQU 0xF6C    ; Comparator 2 control 0
CM2CON1     EQU 0xF6D    ; Comparator 2 control 1

; ============================================
; Voltage Reference
; ============================================
VREFCON0    EQU 0xF75    ; Voltage reference control 0
VREFCON1    EQU 0xF76    ; Voltage reference control 1
VREFCON2    EQU 0xF77    ; Voltage reference control 2

; ============================================
; EUSART Registers
; ============================================
RCREG       EQU 0xFAE    ; USART receive register
TXREG       EQU 0xFAD    ; USART transmit register
TXSTA       EQU 0xFAC    ; USART transmit status
RCSTA       EQU 0xFAB    ; USART receive status
SPBRG       EQU 0xFAF    ; Baud rate generator low
SPBRGH      EQU 0xFB0    ; Baud rate generator high
BAUDCON     EQU 0xFB8    ; Baud control

; ============================================
; I2C/SPI (MSSP) Registers
; ============================================
SSPBUF      EQU 0xFC9    ; SSP buffer
SSPADD      EQU 0xFC8    ; SSP address
SSPSTAT     EQU 0xFC7    ; SSP status
SSPCON1     EQU 0xFC6    ; SSP control 1
SSPCON2     EQU 0xFC5    ; SSP control 2

; ============================================
; USB Registers
; ============================================
UIR         EQU 0xF6A    ; USB interrupt request
UIE         EQU 0xF69    ; USB interrupt enable
UEIR        EQU 0xF68    ; USB error interrupt request
UEIE        EQU 0xF67    ; USB error interrupt enable
USTAT       EQU 0xF66    ; USB status
UCON        EQU 0xF64    ; USB control
UCFG        EQU 0xF65    ; USB configuration
UADDR       EQU 0xF63    ; USB address
UEP0        EQU 0xF53    ; USB endpoint 0 control
UEP1        EQU 0xF54    ; USB endpoint 1 control
UEP2        EQU 0xF55    ; USB endpoint 2 control
UEP3        EQU 0xF56    ; USB endpoint 3 control
UEP4        EQU 0xF57    ; USB endpoint 4 control
UEP5        EQU 0xF58    ; USB endpoint 5 control
UEP6        EQU 0xF59    ; USB endpoint 6 control
UEP7        EQU 0xF5A    ; USB endpoint 7 control

; ============================================
; Interrupt Registers
; ============================================
PIR1        EQU 0xF9E    ; Peripheral interrupt request 1
PIR2        EQU 0xF9F    ; Peripheral interrupt request 2
PIE1        EQU 0xF9D    ; Peripheral interrupt enable 1
PIE2        EQU 0xFA0    ; Peripheral interrupt enable 2
IPR1        EQU 0xF9C    ; Peripheral interrupt priority 1
IPR2        EQU 0xFA1    ; Peripheral interrupt priority 2

; Interrupt-on-change
IOCB        EQU 0xF62    ; Interrupt-on-change Port B
WPUB        EQU 0xF77    ; Weak pull-ups Port B
INTCON2     EQU 0xFF1    ; Interrupt control 2

; ============================================
; Oscillator Control
; ============================================
OSCCON      EQU 0xFD3    ; Oscillator control
OSCCON2     EQU 0xFD2    ; Oscillator control 2
OSCTUNE     EQU 0xF9B    ; Oscillator tuning

; ============================================
; EEPROM Registers
; ============================================
EECON2      EQU 0xF7E    ; EEPROM control 2
EECON1      EQU 0xF7D    ; EEPROM control 1
EEDATA      EQU 0xF7C    ; EEPROM data
EEADR       EQU 0xF7B    ; EEPROM address

; ============================================
; Common User Variables
; ============================================
; Access RAM: 0x000-0x05F (96 bytes, fast access)
VAR_START   EQU 0x000
COUNTER     EQU 0x000
TEMP        EQU 0x001
FLAGS       EQU 0x002
DELAY_L     EQU 0x003
DELAY_H     EQU 0x004

; ============================================
; Example Usage Patterns for PIC18F14K50
; ============================================

; Initialize GPIO (PIC18 - no bank switching!)
;       CLRF PORTA           ; Clear Port A
;       CLRF PORTB           ; Clear Port B
;       CLRF PORTC           ; Clear Port C
;       CLRF TRISA           ; All outputs
;       CLRF TRISB           ; All outputs
;       CLRF TRISC           ; All outputs
;       CLRF ANSEL           ; All digital I/O
;       CLRF ANSELH

; Write to GPIO (using PIC18 instructions)
;       BSF PORTA, 0, ACCESS ; Set RA0 high
;       BCF PORTB, 1, ACCESS ; Set RB1 low
;       BTG PORTC, 2, ACCESS ; Toggle RC2

; Configure internal oscillator (48MHz for USB)
;       MOVLW 0x70           ; 16MHz internal oscillator
;       MOVWF OSCCON, ACCESS
;       BSF OSCCON2, 7, ACCESS ; Enable PLL (16MHz * 3 = 48MHz)

; Configure weak pull-ups on RB4
;       BSF WPUB, 4, ACCESS  ; Enable pull-up on RB4
;       BCF INTCON2, 7, ACCESS ; Enable RBPU

; Configure ADC (10-bit, AN0)
;       BSF ANSEL, 0, ACCESS ; RA0 as analog input
;       MOVLW 0x01           ; ADC on, channel AN0
;       MOVWF ADCON0, ACCESS
;       MOVLW 0x0E           ; Left justified, Vdd/Vss ref
;       MOVWF ADCON1, ACCESS
;       MOVLW 0xA9           ; Fosc/8, 12 TAD
;       MOVWF ADCON2, ACCESS

; Start ADC conversion (PIC18 way)
;       BSF ADCON0, 1, ACCESS ; Start (GO bit)
; wait: BTFSC ADCON0, 1, ACCESS ; Wait for completion
;       BRA wait
;       ; Result in ADRESH:ADRESL

; Configure EUSART (9600 @ 48MHz)
;       MOVLW 0x4E           ; Low byte
;       MOVWF SPBRG, ACCESS
;       MOVLW 0x03           ; High byte (0x034E for 9600)
;       MOVWF SPBRGH, ACCESS
;       MOVLW 0x24           ; BRGH=1, TXEN=1
;       MOVWF TXSTA, ACCESS
;       MOVLW 0x90           ; SPEN=1, CREN=1
;       MOVWF RCSTA, ACCESS

; Send byte via EUSART (PIC18 way)
;       MOVWF TXREG, ACCESS
; wait_tx:
;       BTFSS TXSTA, 1, ACCESS ; Check TRMT
;       BRA wait_tx

; Receive byte via EUSART
; wait_rx:
;       BTFSS PIR1, 5, ACCESS ; Check RCIF
;       BRA wait_rx
;       MOVF RCREG, W, ACCESS ; Read to WREG

; Configure PWM on RC2 (CCP1)
;       BCF TRISC, 2, ACCESS ; RC2 as output
;       MOVLW 0xFF           ; PWM period
;       MOVWF PR2, ACCESS
;       MOVLW 0x7F           ; 50% duty cycle
;       MOVWF CCPR1L, ACCESS
;       MOVLW 0x0C           ; PWM mode
;       MOVWF CCP1CON, ACCESS
;       MOVLW 0x04           ; TMR2 on
;       MOVWF T2CON, ACCESS

; Configure I2C Master (100kHz @ 48MHz)
;       MOVLW 0x77           ; 100kHz @ 48MHz
;       MOVWF SSPADD, ACCESS
;       MOVLW 0x28           ; I2C Master mode
;       MOVWF SSPCON1, ACCESS

; Configure USB (basic setup)
;       BSF UCFG, 3, ACCESS  ; Internal transceiver
;       BSF UCFG, 4, ACCESS  ; Internal pull-up
;       BSF UCON, 0, ACCESS  ; USB on

; Interrupt-on-change for RB4
;       BSF IOCB, 4, ACCESS  ; Enable IOC on RB4
;       BSF INTCON, 3, ACCESS ; Enable RBIE
;       BSF INTCON, 7, ACCESS ; Enable GIE

; PIC18 conditional branches (no GOTO needed!)
;       MOVLW 0x42
;       CPFSEQ COUNTER, ACCESS ; Compare, skip if equal
;       BRA not_equal
;       ; Equal code here
; not_equal:

; 16-bit addition with carry
;       MOVF NUM1_L, W, ACCESS
;       ADDWF NUM2_L, W, ACCESS
;       MOVWF RESULT_L, ACCESS
;       MOVF NUM1_H, W, ACCESS
;       ADDWFC NUM2_H, W, ACCESS ; Add with carry
;       MOVWF RESULT_H, ACCESS

; ============================================
; PIC18F14K50 Pinout (20-pin DIP)
; ============================================
; Pin 1:  RA2/AN2/VREF-/CVREF
; Pin 2:  RA3/AN3/VREF+
; Pin 3:  RA4/AN4/T0CKI/C1OUT
; Pin 4:  RA5/MCLR/VPP
; Pin 5:  VSS (Ground)
; Pin 6:  RB0/AN12/INT0/FLT0/SDI/SDA (USB D+)
; Pin 7:  RB1/AN10/INT1/SCK/SCL (USB D-)
; Pin 8:  RB2/AN8/INT2/VMO/RX
; Pin 9:  RB3/AN9/CCP2/VPO/TX
; Pin 10: RB4/AN11/KBI0/CSSPP
; Pin 11: RB5/KBI1/T1CKI/T3CKI/PGM
; Pin 12: RB6/KBI2/PGC
; Pin 13: RB7/KBI3/PGD
; Pin 14: VDD (+5V or 3.3V)
; Pin 15: RA6/OSC2/CLKOUT
; Pin 16: RA7/OSC1/CLKIN
; Pin 17: RA0/AN0/ICSPDAT/ULPWU
; Pin 18: RA1/AN1/ICSPCLK
; Pin 19: RC0/T1OSO/T13CKI
; Pin 20: RC1/T1OSI/CCP2/UOE

; ============================================
; Key Features of PIC18F14K50
; ============================================
; - PIC18 architecture (16-bit instructions)
; - No bank switching needed (Access RAM)
; - 16KB Flash program memory
; - 768 bytes RAM
; - 256 bytes EEPROM
; - 48MHz operation with PLL (16MHz * 3)
; - Full-speed USB 2.0 interface
; - 11 channels 10-bit ADC
; - Enhanced USART
; - MSSP (I2C/SPI Master/Slave)
; - Enhanced CCP with PWM steering
; - 2 Comparators with voltage reference
; - 4 Timers (TMR0, TMR1, TMR2, TMR3)
; - Interrupt-on-change on Port B
; - Priority interrupts
; - Wide operating voltage (2.0V to 5.5V)
; - Compact 20-pin package with USB
