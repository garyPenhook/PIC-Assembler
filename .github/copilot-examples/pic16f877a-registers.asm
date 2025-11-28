; ============================================
; PIC16F877A Register Definitions
; Architecture: PIC16 (14-bit instructions)
; Assemble with: gnsasm file.asm -a pic16
; ============================================
; THE classic PIC16 microcontroller - extremely popular
; 40-pin DIP, 8KB Flash, 368 bytes RAM, 256 bytes EEPROM

; ============================================
; Core Registers (Bank 0)
; ============================================
INDF        EQU 0x00    ; Indirect addressing
TMR0        EQU 0x01    ; Timer 0
PCL         EQU 0x02    ; Program counter low
STATUS      EQU 0x03    ; Status register
FSR         EQU 0x04    ; File select register
PORTA       EQU 0x05    ; Port A (6 bits: RA0-RA5)
PORTB       EQU 0x06    ; Port B (8 bits: RB0-RB7)
PORTC       EQU 0x07    ; Port C (8 bits: RC0-RC7)
PORTD       EQU 0x08    ; Port D (8 bits: RD0-RD7)
PORTE       EQU 0x09    ; Port E (3 bits: RE0-RE2)
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
RP0         EQU 5       ; Register bank select bit 0
RP1         EQU 6       ; Register bank select bit 1
IRP         EQU 7       ; Indirect addressing bank select

; ============================================
; Bank 1 Registers (Set RP0)
; ============================================
OPTION_REG  EQU 0x81    ; Option register
TRISA       EQU 0x85    ; Port A tri-state (1=input, 0=output)
TRISB       EQU 0x86    ; Port B tri-state
TRISC       EQU 0x87    ; Port C tri-state
TRISD       EQU 0x88    ; Port D tri-state
TRISE       EQU 0x89    ; Port E tri-state
PIE1        EQU 0x8C    ; Peripheral interrupt enable 1
PIE2        EQU 0x8D    ; Peripheral interrupt enable 2
PCON        EQU 0x8E    ; Power control

; ============================================
; Bank 0 Peripheral Registers
; ============================================
PIR1        EQU 0x0C    ; Peripheral interrupt request 1
PIR2        EQU 0x0D    ; Peripheral interrupt request 2
TMR1L       EQU 0x0E    ; Timer 1 low byte
TMR1H       EQU 0x0F    ; Timer 1 high byte
T1CON       EQU 0x10    ; Timer 1 control
TMR2        EQU 0x11    ; Timer 2
T2CON       EQU 0x12    ; Timer 2 control
SSPBUF      EQU 0x13    ; SSP buffer (SPI/I2C)
SSPCON      EQU 0x14    ; SSP control
CCPR1L      EQU 0x15    ; Capture/Compare/PWM 1 low
CCPR1H      EQU 0x16    ; Capture/Compare/PWM 1 high
CCP1CON     EQU 0x17    ; CCP1 control
RCSTA       EQU 0x18    ; USART receive status
TXREG       EQU 0x19    ; USART transmit register
RCREG       EQU 0x1A    ; USART receive register
CCPR2L      EQU 0x1B    ; Capture/Compare/PWM 2 low
CCPR2H      EQU 0x1C    ; Capture/Compare/PWM 2 high
CCP2CON     EQU 0x1D    ; CCP2 control
ADRESH      EQU 0x1E    ; ADC result high
ADCON0      EQU 0x1F    ; ADC control 0

; ============================================
; Bank 1 Peripheral Registers
; ============================================
PR2         EQU 0x92    ; Timer 2 period register
SSPADD      EQU 0x93    ; SSP address
SSPSTAT     EQU 0x94    ; SSP status
TXSTA       EQU 0x98    ; USART transmit status
SPBRG       EQU 0x99    ; USART baud rate generator
ADRESL      EQU 0x9E    ; ADC result low
ADCON1      EQU 0x9F    ; ADC control 1

; ============================================
; Bank 2/3 - EEPROM and Other
; ============================================
EEDATA      EQU 0x10C   ; EEPROM data (Bank 2)
EEADR       EQU 0x10D   ; EEPROM address (Bank 2)
EEDATH      EQU 0x10E   ; EEPROM data high (Bank 2)
EEADRH      EQU 0x10F   ; EEPROM address high (Bank 2)
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
; Bank 1: 0xA0-0xFF (96 bytes)
; Bank 2: 0x110-0x16F (96 bytes)
; Bank 3: 0x190-0x1EF (96 bytes)
VAR_START   EQU 0x20    ; Start of general purpose RAM
COUNTER     EQU 0x20    ; Example: 8-bit counter
TEMP        EQU 0x21    ; Example: temporary storage
FLAGS       EQU 0x22    ; Example: flag byte
DELAY_L     EQU 0x23    ; Example: delay counter low
DELAY_H     EQU 0x24    ; Example: delay counter high

; ============================================
; Example Usage Patterns for PIC16F877A
; ============================================

; Initialize all ports as outputs
;       BSF STATUS, RP0      ; Select Bank 1
;       CLRF TRISA           ; Port A all outputs
;       CLRF TRISB           ; Port B all outputs
;       CLRF TRISC           ; Port C all outputs
;       CLRF TRISD           ; Port D all outputs
;       CLRF TRISE           ; Port E all outputs
;       BCF STATUS, RP0      ; Back to Bank 0

; Configure PORTA as input, others as output
;       BSF STATUS, RP0      ; Bank 1
;       MOVLW 0xFF           ; All inputs
;       MOVWF TRISA
;       CLRF TRISB           ; All outputs
;       CLRF TRISC
;       CLRF TRISD
;       CLRF TRISE
;       BCF STATUS, RP0      ; Bank 0

; Write to multiple ports
;       MOVLW 0xFF
;       MOVWF PORTB          ; Turn on all PORTB LEDs
;       CLRF PORTD           ; Turn off all PORTD LEDs

; Read Port B and output to Port D
;       MOVF PORTB, 0        ; Read PORTB to W
;       MOVWF PORTD          ; Write to PORTD

; Configure ADC (10-bit, AN0, Vdd/Vss reference)
;       BSF STATUS, RP0      ; Bank 1
;       MOVLW 0x0E           ; AN0 analog, rest digital
;       MOVWF ADCON1
;       BCF STATUS, RP0      ; Bank 0
;       MOVLW 0x41           ; ADC on, channel 0, Fosc/8
;       MOVWF ADCON0

; Start ADC conversion
;       BSF ADCON0, 2        ; Start conversion (GO/DONE bit)
; wait: BTFSC ADCON0, 2      ; Wait for completion
;       GOTO wait
;       ; Result in ADRESH:ADRESL (right-justified)

; Configure USART (9600 baud @ 4MHz)
;       BSF STATUS, RP0      ; Bank 1
;       MOVLW 0x19           ; 9600 baud @ 4MHz
;       MOVWF SPBRG
;       MOVLW 0x24           ; Enable transmit, high speed
;       MOVWF TXSTA
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

; Configure PWM on CCP1 (RC2)
;       BSF STATUS, RP0      ; Bank 1
;       BCF TRISC, 2         ; RC2 as output (CCP1)
;       MOVLW 0xFF           ; PWM period
;       MOVWF PR2            ; Set period
;       BCF STATUS, RP0      ; Bank 0
;       MOVLW 0x7F           ; 50% duty cycle
;       MOVWF CCPR1L
;       MOVLW 0x0C           ; PWM mode
;       MOVWF CCP1CON
;       MOVLW 0x05           ; TMR2 on, prescaler 1:4
;       MOVWF T2CON

; ============================================
; PIC16F877A Features Summary
; ============================================
; - 5 Ports (A:6-bit, B:8-bit, C:8-bit, D:8-bit, E:3-bit)
; - 8KB Flash program memory
; - 368 bytes RAM
; - 256 bytes EEPROM
; - 3 Timers (Timer0, Timer1, Timer2)
; - 2 CCP modules (Capture/Compare/PWM)
; - USART (RS-232 serial)
; - SSP (SPI/I2C)
; - 8 channels 10-bit ADC
; - Brown-out reset
; - Watchdog timer
; - In-circuit programming
