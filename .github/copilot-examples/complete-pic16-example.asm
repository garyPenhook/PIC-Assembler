; ============================================
; Complete PIC16F18076 Example Program
; Blink LED on Port A, bit 0
; Architecture: PIC16 (14-bit instructions)
; Assemble with: gnsasm blink.asm -a pic16 -o blink.hex
; ============================================

; ============================================
; Register Definitions
; ============================================
; Define commonly-used registers for clarity
STATUS      EQU 0x03    ; Status register
PORTA       EQU 0x05    ; Port A data
TRISA       EQU 0x85    ; Port A direction (Bank 1)
INTCON      EQU 0x0B    ; Interrupt control

; STATUS bits
C           EQU 0       ; Carry flag
Z           EQU 2       ; Zero flag
RP0         EQU 5       ; Bank select bit

; User variables (0x20-0x7F are general purpose RAM)
COUNTER     EQU 0x20    ; 8-bit counter
DELAY_L     EQU 0x21    ; Delay counter low byte
DELAY_H     EQU 0x22    ; Delay counter high byte

; ============================================
; Reset Vector
; ============================================
        ORG 0x0000      ; Start at reset vector
        GOTO init       ; Jump to initialization

; ============================================
; Initialization
; ============================================
init:
        ; Clear all registers
        CLRF STATUS     ; Clear status register

        ; Configure Port A (Bank 1)
        BSF STATUS, RP0 ; Select Bank 1
        MOVLW 0x00      ; All bits as outputs
        MOVWF TRISA     ; Configure TRISA
        BCF STATUS, RP0 ; Back to Bank 0

        ; Initialize variables
        CLRF COUNTER    ; Clear counter
        CLRF PORTA      ; Clear Port A output

        ; Disable interrupts (optional)
        CLRF INTCON     ; Disable all interrupts

        GOTO main       ; Jump to main program

; ============================================
; Main Program Loop
; ============================================
main:
        ; Turn LED on (set bit 0 of Port A)
        BSF PORTA, 0    ; LED on

        ; Delay
        CALL delay_long

        ; Turn LED off (clear bit 0 of Port A)
        BCF PORTA, 0    ; LED off

        ; Delay
        CALL delay_long

        ; Increment counter
        INCF COUNTER, 1 ; Increment counter

        ; Check if counter reached 10
        MOVF COUNTER, 0 ; Move counter to W (sets Z flag)
        SUBLW 0x0A      ; Subtract 10 from W
        BTFSS STATUS, Z ; Test if zero (counter == 10)
        GOTO main       ; Not 10 yet, continue

        ; Counter reached 10, reset it
        CLRF COUNTER
        GOTO main       ; Continue forever

; ============================================
; Delay Subroutine (Long)
; ============================================
; Uses nested loops for longer delay
delay_long:
        MOVLW 0xFF      ; Load outer loop counter
        MOVWF DELAY_H

delay_outer:
        MOVLW 0xFF      ; Load inner loop counter
        MOVWF DELAY_L

delay_inner:
        DECFSZ DELAY_L, 1   ; Decrement inner counter, skip if zero
        GOTO delay_inner    ; Continue inner loop

        DECFSZ DELAY_H, 1   ; Decrement outer counter, skip if zero
        GOTO delay_outer    ; Continue outer loop

        RETURN          ; Return from subroutine

; ============================================
; Delay Subroutine (Short)
; ============================================
; Single loop for shorter delay
delay_short:
        MOVLW 0xFF      ; Load delay value
        MOVWF DELAY_L

delay_loop:
        DECFSZ DELAY_L, 1   ; Decrement and skip if zero
        GOTO delay_loop     ; Continue loop
        RETURN

; ============================================
; Utility Subroutines
; ============================================

; Set all Port A bits high
porta_all_high:
        MOVLW 0xFF      ; All bits high
        MOVWF PORTA
        RETURN

; Set all Port A bits low
porta_all_low:
        CLRF PORTA      ; All bits low
        RETURN

; Toggle Port A bit 0
toggle_led:
        MOVLW 0x01      ; Bit 0 mask
        XORWF PORTA, 1  ; XOR with Port A (toggles bit 0)
        RETURN

; Check if button pressed (assumes button on bit 1, active low)
check_button:
        BTFSS PORTA, 1  ; Test bit 1, skip if set (not pressed)
        GOTO button_pressed
        RETURN          ; Button not pressed

button_pressed:
        ; Handle button press here
        BSF PORTA, 0    ; Turn on LED
        RETURN

        END             ; End of program
