; ============================================
; PIC16F18076 Register Definitions
; Architecture: PIC16 (14-bit instructions)
; Assemble with: gnsasm file.asm -a pic16
; ============================================
; Use this file as reference when writing PIC16F18076 assembly code
; Define commonly-used registers with EQU at the start of your program

; ============================================
; Core Registers (Bank 0)
; ============================================
INDF        EQU 0x00    ; Indirect addressing
TMR0        EQU 0x01    ; Timer 0 counter
PCL         EQU 0x02    ; Program counter low byte
STATUS      EQU 0x03    ; Status register
FSR         EQU 0x04    ; File select register
PORTA       EQU 0x05    ; Port A data
PORTB       EQU 0x06    ; Port B data
PORTC       EQU 0x07    ; Port C data
PORTD       EQU 0x08    ; Port D data
PORTE       EQU 0x09    ; Port E data
PCLATH      EQU 0x0A    ; Program counter latch high

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
IRP         EQU 7       ; Indirect addressing bit

; ============================================
; Bank 1 Registers (Set RP0 in STATUS)
; ============================================
OPTION_REG  EQU 0x81    ; Option register
TRISA       EQU 0x85    ; Port A tri-state control
TRISB       EQU 0x86    ; Port B tri-state control
TRISC       EQU 0x87    ; Port C tri-state control
TRISD       EQU 0x88    ; Port D tri-state control
TRISE       EQU 0x89    ; Port E tri-state control

; ============================================
; Interrupt Registers
; ============================================
INTCON      EQU 0x0B    ; Interrupt control (Bank 0)
PIR1        EQU 0x0C    ; Peripheral interrupt flags 1
PIR2        EQU 0x0D    ; Peripheral interrupt flags 2
PIE1        EQU 0x8C    ; Peripheral interrupt enable 1 (Bank 1)
PIE2        EQU 0x8D    ; Peripheral interrupt enable 2 (Bank 1)

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
; Common User Variables Area
; ============================================
; Use addresses 0x20-0x7F for your variables
VAR_START   EQU 0x20    ; Start of general purpose RAM
COUNTER     EQU 0x20    ; Example: 8-bit counter
TEMP        EQU 0x21    ; Example: temporary storage
FLAGS       EQU 0x22    ; Example: flag byte
DELAY_L     EQU 0x23    ; Example: delay counter low
DELAY_H     EQU 0x24    ; Example: delay counter high

; ============================================
; Example Usage Patterns
; ============================================

; Initialize ports (switch to Bank 1)
;       BSF STATUS, RP0      ; Select Bank 1
;       MOVLW 0x00           ; All outputs
;       MOVWF TRISA          ; Configure Port A
;       BCF STATUS, RP0      ; Back to Bank 0

; Write to port
;       MOVLW 0xFF           ; All high
;       MOVWF PORTA          ; Output to Port A

; Set/clear individual bits
;       BSF PORTA, 0         ; Set bit 0 of Port A
;       BCF PORTA, 1         ; Clear bit 1 of Port A

; Test bit and branch
;       BTFSC STATUS, Z      ; Test Zero flag, skip if clear
;       GOTO zero_handler    ; Jump if zero

; Increment counter
;       INCF COUNTER, 1      ; Increment counter in place

; Simple delay
;       MOVLW 0xFF
;       MOVWF DELAY_L
; loop: DECFSZ DELAY_L, 1
;       GOTO loop
