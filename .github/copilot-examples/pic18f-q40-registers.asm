; ============================================
; PIC18F-Q40 Register Definitions
; Architecture: PIC18 (16-bit instructions)
; Assemble with: gnsasm file.asm -a pic18
; ============================================
; Use this file as reference when writing PIC18-Q40 assembly code
; Define commonly-used registers with EQU at the start of your program

; ============================================
; Access Bank Registers (Always accessible)
; ============================================
; Low Access RAM (0x00-0x5F)
WREG        EQU 0x00    ; Working register (implicit in many instructions)
FSR0L       EQU 0x01    ; FSR0 low byte
FSR0H       EQU 0x02    ; FSR0 high byte
FSR1L       EQU 0x03    ; FSR1 low byte
FSR1H       EQU 0x04    ; FSR1 high byte
FSR2L       EQU 0x05    ; FSR2 low byte
FSR2H       EQU 0x06    ; FSR2 high byte
STATUS      EQU 0x07    ; Status register
TMR0L       EQU 0x08    ; Timer 0 low byte
TMR0H       EQU 0x09    ; Timer 0 high byte
T0CON       EQU 0x0A    ; Timer 0 control
INTCON      EQU 0x0B    ; Interrupt control
INTCON2     EQU 0x0C    ; Interrupt control 2
INTCON3     EQU 0x0D    ; Interrupt control 3
PCL         EQU 0x0E    ; Program counter low
PCLATH      EQU 0x0F    ; Program counter latch high
PCLATU      EQU 0x10    ; Program counter latch upper

; ============================================
; STATUS Register Bit Definitions (0x07)
; ============================================
C           EQU 0       ; Carry/borrow flag
DC          EQU 1       ; Digit carry/borrow flag
Z           EQU 2       ; Zero flag
OV          EQU 3       ; Overflow flag
N           EQU 4       ; Negative flag (bit 7 of result)

; ============================================
; Port Registers
; ============================================
PORTA       EQU 0x20    ; Port A data register
PORTB       EQU 0x21    ; Port B data register
PORTC       EQU 0x22    ; Port C data register
PORTD       EQU 0x23    ; Port D data register
PORTE       EQU 0x24    ; Port E data register

LATA        EQU 0x28    ; Port A latch
LATB        EQU 0x29    ; Port B latch
LATC        EQU 0x2A    ; Port C latch
LATD        EQU 0x2B    ; Port D latch
LATE        EQU 0x2C    ; Port E latch

TRISA       EQU 0x30    ; Port A direction control (1=input, 0=output)
TRISB       EQU 0x31    ; Port B direction control
TRISC       EQU 0x32    ; Port C direction control
TRISD       EQU 0x33    ; Port D direction control
TRISE       EQU 0x34    ; Port E direction control

; ============================================
; Timer Registers
; ============================================
TMR1L       EQU 0x40    ; Timer 1 low byte
TMR1H       EQU 0x41    ; Timer 1 high byte
T1CON       EQU 0x42    ; Timer 1 control
TMR2        EQU 0x44    ; Timer 2
PR2         EQU 0x45    ; Timer 2 period register
T2CON       EQU 0x46    ; Timer 2 control

; ============================================
; ADC Registers
; ============================================
ADCON0      EQU 0x48    ; ADC control 0
ADCON1      EQU 0x49    ; ADC control 1
ADRESL      EQU 0x4A    ; ADC result low
ADRESH      EQU 0x4B    ; ADC result high

; ============================================
; Interrupt Registers
; ============================================
PIR1        EQU 0x50    ; Peripheral interrupt request 1
PIR2        EQU 0x51    ; Peripheral interrupt request 2
PIR3        EQU 0x52    ; Peripheral interrupt request 3
PIE1        EQU 0x58    ; Peripheral interrupt enable 1
PIE2        EQU 0x59    ; Peripheral interrupt enable 2
PIE3        EQU 0x5A    ; Peripheral interrupt enable 3
IPR1        EQU 0x60    ; Peripheral interrupt priority 1
IPR2        EQU 0x61    ; Peripheral interrupt priority 2
IPR3        EQU 0x62    ; Peripheral interrupt priority 3

; ============================================
; Common User Variables Area
; ============================================
; Use addresses 0x70-0xFF for your variables in Access Bank
VAR_START   EQU 0x70    ; Start of user variables
COUNTER     EQU 0x70    ; Example: 8-bit counter
TEMP        EQU 0x71    ; Example: temporary storage
FLAGS       EQU 0x72    ; Example: flag byte
DELAY_L     EQU 0x73    ; Example: delay counter low
DELAY_M     EQU 0x74    ; Example: delay counter mid
DELAY_H     EQU 0x75    ; Example: delay counter high
RESULT_L    EQU 0x76    ; Example: 16-bit result low
RESULT_H    EQU 0x77    ; Example: 16-bit result high

; ============================================
; Example Usage Patterns for PIC18
; ============================================

; Initialize ports (no bank switching needed)
;       SETF TRISA          ; All inputs (set all bits to 1)
;       CLRF TRISA          ; All outputs (clear all bits to 0)
;       MOVLW 0x0F          ; Lower 4 bits input, upper 4 output
;       MOVWF TRISA

; Write to port (use LATA for read-modify-write safety)
;       MOVLW 0xFF          ; All high
;       MOVWF LATA          ; Write to Port A latch

; Set/clear individual bits
;       BSF LATA, 0         ; Set bit 0 of Port A latch
;       BCF LATA, 1         ; Clear bit 1 of Port A latch
;       BTG LATA, 2         ; Toggle bit 2 (PIC18 only!)

; Test bit and branch (PIC18 style)
;       BTFSC STATUS, Z     ; Test Zero flag, skip if clear
;       BRA zero_handler    ; Branch if zero (PIC18 relative branch)

; Compare and skip (PIC18 specific)
;       MOVLW 0x55          ; Load comparison value
;       CPFSEQ COUNTER      ; Compare with COUNTER, skip if equal
;       BRA not_equal       ; Branch if not equal

; Increment with skip
;       INCFSZ COUNTER, 1   ; Increment, skip if zero
;       BRA continue        ; Not zero, continue
;       ; Handle overflow here

; Add with carry (PIC18 specific)
;       MOVLW 0x01
;       ADDWFC COUNTER, 1   ; Add W + Carry to COUNTER

; Conditional branches (PIC18 specific)
;       BC carry_set        ; Branch if carry set
;       BZ is_zero          ; Branch if zero
;       BN is_negative      ; Branch if negative
;       BOV overflow        ; Branch if overflow

; 16-bit operations example
;       ; Add 0x1234 to 16-bit result
;       MOVLW 0x34          ; Low byte
;       ADDWF RESULT_L, 1   ; Add to low byte
;       MOVLW 0x12          ; High byte
;       ADDWFC RESULT_H, 1  ; Add to high byte with carry

; Simple delay (PIC18 style)
;       MOVLW 0xFF
;       MOVWF DELAY_L
; loop: DECFSZ DELAY_L, 1
;       BRA loop            ; Use BRA instead of GOTO
