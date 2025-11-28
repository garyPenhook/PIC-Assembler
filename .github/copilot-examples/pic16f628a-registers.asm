; ============================================
; PIC16F628A Register Definitions
; Architecture: PIC16 (14-bit instructions)
; Assemble with: gnsasm file.asm -a pic16
; ============================================
; Popular beginner PIC16 - 18-pin DIP package
; 2KB Flash, 224 bytes RAM, 128 bytes EEPROM

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
PIE1        EQU 0x8C    ; Peripheral interrupt enable 1
PCON        EQU 0x8E    ; Power control
OSCCON      EQU 0x8F    ; Oscillator control

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
; Comparator Registers
; ============================================
CMCON       EQU 0x1F    ; Comparator control
VRCON       EQU 0x9F    ; Voltage reference control (Bank 1)

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
; EEPROM Registers (Bank 2/3)
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
VAR_START   EQU 0x20    ; Start of general purpose RAM
COUNTER     EQU 0x20    ; Example: 8-bit counter
TEMP        EQU 0x21    ; Example: temporary storage
FLAGS       EQU 0x22    ; Example: flag byte
DELAY_L     EQU 0x23    ; Example: delay counter low
DELAY_H     EQU 0x24    ; Example: delay counter high

; ============================================
; Example Usage Patterns for PIC16F628A
; ============================================

; Initialize ports (all outputs)
;       BSF STATUS, RP0      ; Select Bank 1
;       CLRF TRISA           ; Port A all outputs
;       CLRF TRISB           ; Port B all outputs
;       BCF STATUS, RP0      ; Back to Bank 0

; Disable comparators (for digital I/O)
;       MOVLW 0x07           ; Comparators off
;       MOVWF CMCON

; Configure internal oscillator (4MHz)
;       BSF STATUS, RP0      ; Bank 1
;       MOVLW 0x60           ; 4MHz internal oscillator
;       MOVWF OSCCON
;       BCF STATUS, RP0      ; Bank 0

; Write to Port A
;       MOVLW 0xFF           ; All high
;       MOVWF PORTA

; Blink LED on RA0
;       BSF PORTA, 0         ; LED on
;       CALL delay
;       BCF PORTA, 0         ; LED off
;       CALL delay

; Read button on RB0 (with pull-up)
;       BSF STATUS, RP0      ; Bank 1
;       BSF TRISB, 0         ; RB0 as input
;       BCF OPTION_REG, 7    ; Enable weak pull-ups
;       BCF STATUS, RP0      ; Bank 0
;       BTFSC PORTB, 0       ; Test RB0, skip if low (pressed)
;       GOTO not_pressed

; Configure USART (9600 baud @ 4MHz)
;       BSF STATUS, RP0      ; Bank 1
;       MOVLW 0x19           ; 9600 baud @ 4MHz
;       MOVWF SPBRG
;       MOVLW 0x24           ; TXEN=1, BRGH=1
;       MOVWF TXSTA
;       BCF TRISB, 2         ; RB2/TX as output
;       BSF TRISB, 1         ; RB1/RX as input
;       BCF STATUS, RP0      ; Bank 0
;       MOVLW 0x90           ; SPEN=1, CREN=1
;       MOVWF RCSTA

; Send byte via USART
;       MOVWF TXREG          ; Send byte in W
; wait_tx:
;       BSF STATUS, RP0      ; Bank 1
;       BTFSS TXSTA, 1       ; Check TRMT flag
;       GOTO wait_tx
;       BCF STATUS, RP0      ; Bank 0

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
; PIC16F628A Pinout Reference (18-pin DIP)
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
; Important Notes for PIC16F628A
; ============================================
; 1. Comparators are ON by default - disable with CMCON = 0x07
; 2. Internal oscillator available (4MHz default)
; 3. 224 bytes RAM total
; 4. 2048 words program memory
; 5. No ADC module (use comparator for analog input)
; 6. Has USART for serial communication
; 7. Has one CCP module for PWM/Capture/Compare
; 8. 128 bytes EEPROM data memory
