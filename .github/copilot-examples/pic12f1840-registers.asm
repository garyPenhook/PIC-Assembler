; ============================================
; PIC12F1840 Register Definitions
; Architecture: PIC16 (14-bit enhanced mid-range)
; Assemble with: gnsasm file.asm -a pic16
; ============================================
; Modern enhanced 8-pin PIC with advanced peripherals
; 4KB Flash, 256 bytes RAM, 256 bytes EEPROM

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
; GPIO (Port A) - Bank 0
; ============================================
PORTA       EQU 0x0C    ; Port A data (6 bits: RA0-RA5)
LATA        EQU 0x10C   ; Port A latch (Bank 2)
TRISA       EQU 0x8C    ; Port A tri-state (Bank 1)
ANSELA      EQU 0x18C   ; Analog select (Bank 3)
WPUA        EQU 0x20C   ; Weak pull-ups (Bank 4)

; ============================================
; GPIO Pin Definitions
; ============================================
; PIC12F1840 has 6 I/O pins
RA0         EQU 0       ; Pin 7
RA1         EQU 1       ; Pin 6
RA2         EQU 2       ; Pin 5
RA3         EQU 3       ; Pin 4 (input only, MCLR)
RA4         EQU 4       ; Pin 3
RA5         EQU 5       ; Pin 2

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

; ============================================
; PWM/CCP Registers
; ============================================
PWM1DCL     EQU 0x614   ; PWM1 duty cycle low (Bank 12)
PWM1DCH     EQU 0x615   ; PWM1 duty cycle high (Bank 12)
PWM1CON     EQU 0x616   ; PWM1 control (Bank 12)

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
; Interrupt Registers
; ============================================
PIR1        EQU 0x11    ; Peripheral interrupt request 1
PIR2        EQU 0x12    ; Peripheral interrupt request 2
PIE1        EQU 0x91    ; Peripheral interrupt enable 1 (Bank 1)
PIE2        EQU 0x92    ; Peripheral interrupt enable 2 (Bank 1)
IOCAP       EQU 0x391   ; Interrupt-on-change positive (Bank 7)
IOCAN       EQU 0x392   ; Interrupt-on-change negative (Bank 7)
IOCAF       EQU 0x393   ; Interrupt-on-change flag (Bank 7)

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
; Example Usage Patterns for PIC12F1840
; ============================================

; Initialize GPIO (no bank switching needed for basic ops)
;       BANKSEL TRISA        ; Select bank with TRISA
;       CLRF TRISA           ; All outputs (RA3 always input)
;       BANKSEL ANSELA
;       CLRF ANSELA          ; All digital I/O
;       BANKSEL PORTA
;       CLRF PORTA

; Modern way using BANKSEL macro equivalent
;       MOVLW 0x00
;       MOVWF TRISA          ; If in same bank
;       MOVWF ANSELA         ; If in same bank

; Write to GPIO
;       BSF PORTA, 0         ; Set RA0 high
;       BCF PORTA, 1         ; Set RA1 low

; Configure internal oscillator (32MHz)
;       MOVLW 0xF0           ; 32MHz HFINTOSC
;       MOVWF OSCCON

; Configure weak pull-ups on RA0
;       BSF WPUA, 0          ; Enable pull-up on RA0
;       BCF OPTION_REG, 7    ; Enable WPUEN (global pull-up enable)

; Configure ADC (10-bit, AN0)
;       BSF ANSELA, 0        ; RA0 as analog input
;       MOVLW 0x01           ; ADC on, channel AN0
;       MOVWF ADCON0
;       MOVLW 0x10           ; Left justified, Vdd/Vss ref
;       MOVWF ADCON1

; Start ADC conversion
;       BSF ADCON0, 1        ; Start (GO bit)
; wait: BTFSC ADCON0, 1      ; Wait for completion
;       GOTO wait
;       ; Result in ADRESH:ADRESL

; Configure PWM (RA5)
;       BCF TRISA, 5         ; RA5 as output
;       MOVLW 0xFF           ; PWM period
;       MOVWF PR2
;       MOVLW 0x7F           ; 50% duty cycle
;       MOVWF PWM1DCH
;       MOVLW 0x80           ; PWM enabled
;       MOVWF PWM1CON
;       MOVLW 0x04           ; TMR2 on
;       MOVWF T2CON

; Configure EUSART (9600 @ 32MHz)
;       MOVLW 0xCF           ; SPBRGH:SPBRGL = 0xCF for 9600
;       MOVWF SPBRGL
;       MOVLW 0x24           ; BRGH=1, TXEN=1
;       MOVWF TXSTA
;       MOVLW 0x90           ; SPEN=1, CREN=1
;       MOVWF RCSTA

; Send byte via EUSART
;       MOVWF TXREG
; wait_tx:
;       BTFSS TXSTA, 1       ; Check TRMT
;       GOTO wait_tx

; Interrupt-on-change (wake on RA1 change)
;       BSF IOCAP, 1         ; Enable positive edge
;       BSF IOCAN, 1         ; Enable negative edge
;       BSF INTCON, 3        ; Enable IOCIE
;       BSF INTCON, 7        ; Enable GIE

; ============================================
; PIC12F1840 Pinout (8-pin DIP)
; ============================================
; Pin 1: VDD (+5V or 3.3V)
; Pin 2: RA5/T1CKI/OSC1/CLKIN
; Pin 3: RA4/AN3/T1G/OSC2/CLKOUT
; Pin 4: RA3/MCLR/VPP (input only)
; Pin 5: RA2/AN2/T0CKI/INT/COUT
; Pin 6: RA1/AN1/VREF/ICSPCLK
; Pin 7: RA0/AN0/ICSPDAT
; Pin 8: VSS (Ground)

; ============================================
; Key Features of PIC12F1840
; ============================================
; - Enhanced mid-range core (more instructions)
; - Linear memory (no bank switching for variables)
; - 32MHz internal oscillator
; - 4 channel 10-bit ADC
; - Enhanced USART
; - Enhanced PWM module
; - Comparator with voltage reference
; - 256 bytes EEPROM
; - Interrupt-on-change
; - Multiple power saving modes
