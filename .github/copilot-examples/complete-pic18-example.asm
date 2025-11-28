; ============================================
; Complete PIC18F-Q40 Example Program
; Blink LED with PWM brightness control
; Architecture: PIC18 (16-bit instructions)
; Assemble with: gnsasm blink.asm -a pic18 -o blink.hex
; ============================================

; ============================================
; Register Definitions
; ============================================
; Access Bank registers (always accessible, no bank switching)
STATUS      EQU 0x07    ; Status register
PORTA       EQU 0x20    ; Port A data
LATA        EQU 0x28    ; Port A latch (use for outputs)
TRISA       EQU 0x30    ; Port A direction
INTCON      EQU 0x0B    ; Interrupt control

; STATUS bits
C           EQU 0       ; Carry flag
Z           EQU 2       ; Zero flag
OV          EQU 3       ; Overflow flag
N           EQU 4       ; Negative flag

; User variables (0x70+ in Access Bank)
COUNTER     EQU 0x70    ; 8-bit counter
BRIGHTNESS  EQU 0x71    ; LED brightness (0-255)
DELAY_L     EQU 0x72    ; Delay counter low
DELAY_M     EQU 0x73    ; Delay counter mid
DELAY_H     EQU 0x74    ; Delay counter high
TEMP        EQU 0x75    ; Temporary storage
PWM_COUNT   EQU 0x76    ; PWM counter

; ============================================
; Reset Vector
; ============================================
        ORG 0x0000      ; Start at reset vector
        GOTO init       ; Jump to initialization

; ============================================
; Initialization
; ============================================
init:
        ; Clear status
        CLRF STATUS     ; Clear status register

        ; Configure Port A (no bank switching on PIC18!)
        SETF TRISA      ; All inputs initially (set all bits to 1)
        CLRF TRISA      ; Now all outputs (clear all bits to 0)

        ; Initialize variables
        CLRF COUNTER
        CLRF LATA       ; Clear Port A latch
        MOVLW 0x80      ; Start at 50% brightness
        MOVWF BRIGHTNESS

        ; Disable interrupts
        CLRF INTCON

        GOTO main       ; Jump to main

; ============================================
; Main Program Loop
; ============================================
main:
        ; Software PWM: LED brightness control
        CALL pwm_cycle

        ; Increment brightness
        INCF BRIGHTNESS, 1
        BTFSC STATUS, Z     ; Check if wrapped to zero
        GOTO reset_brightness

continue_main:
        ; Small delay between brightness updates
        CALL delay_short

        ; Check counter
        INCFSZ COUNTER, 1   ; Increment, skip if zero (PIC18 specific)
        BRA main            ; Continue (BRA is PIC18 relative branch)

        ; Counter wrapped, do something special
        CLRF COUNTER
        BRA main

reset_brightness:
        MOVLW 0x01      ; Reset to minimum brightness
        MOVWF BRIGHTNESS
        BRA continue_main

; ============================================
; PWM Cycle (Software PWM)
; ============================================
; Implements software PWM using brightness value
pwm_cycle:
        CLRF PWM_COUNT

pwm_loop:
        ; Turn LED on
        BSF LATA, 0     ; Set bit 0

        ; On-time delay proportional to brightness
        MOVF BRIGHTNESS, 0  ; Move brightness to W
        MOVWF TEMP
on_delay:
        DECFSZ TEMP, 1      ; Decrement on-time
        BRA on_delay        ; PIC18 relative branch

        ; Turn LED off
        BCF LATA, 0     ; Clear bit 0

        ; Off-time delay
        MOVLW 0xFF
        SUBWF BRIGHTNESS, 0 ; W = 255 - brightness
        MOVWF TEMP
off_delay:
        DECFSZ TEMP, 1
        BRA off_delay

        ; Continue PWM cycle
        INCF PWM_COUNT, 1
        MOVLW 0x10      ; 16 cycles per update
        CPFSEQ PWM_COUNT    ; Compare, skip if equal (PIC18)
        BRA pwm_loop

        RETURN

; ============================================
; Delay Subroutines
; ============================================

; Long delay using triple nested loop
delay_long:
        MOVLW 0xFF
        MOVWF DELAY_H
dl_outer:
        MOVLW 0xFF
        MOVWF DELAY_M
dl_middle:
        MOVLW 0xFF
        MOVWF DELAY_L
dl_inner:
        DECFSZ DELAY_L, 1
        BRA dl_inner        ; PIC18 branch
        DECFSZ DELAY_M, 1
        BRA dl_middle
        DECFSZ DELAY_H, 1
        BRA dl_outer
        RETURN

; Short delay
delay_short:
        MOVLW 0xFF
        MOVWF DELAY_L
ds_loop:
        DECFSZ DELAY_L, 1
        BRA ds_loop         ; PIC18 branch
        RETURN

; ============================================
; PIC18-Specific Examples
; ============================================

; Example: 16-bit addition
add_16bit:
        ; Add 0x1234 to a 16-bit number at 0x78:0x77
        MOVLW 0x34          ; Low byte
        ADDWF 0x77, 1       ; Add to low byte
        MOVLW 0x12          ; High byte
        ADDWFC 0x78, 1      ; Add with carry (PIC18 specific!)
        RETURN

; Example: Conditional branches (PIC18 specific)
test_conditions:
        MOVF COUNTER, 0     ; Load counter (affects flags)

        BZ is_zero          ; Branch if zero
        BN is_negative      ; Branch if negative
        BC carry_set        ; Branch if carry
        BOV overflow_set    ; Branch if overflow

        ; None of the above
        BRA default_case

is_zero:
        ; Handle zero case
        BRA test_done

is_negative:
        ; Handle negative case
        BRA test_done

carry_set:
        ; Handle carry case
        BRA test_done

overflow_set:
        ; Handle overflow case
        BRA test_done

default_case:
        ; Default case
        NOP

test_done:
        RETURN

; Example: Compare and skip (PIC18 specific)
compare_example:
        MOVLW 0x55          ; Load comparison value

        CPFSEQ COUNTER      ; Compare with COUNTER, skip if equal
        BRA not_equal

        ; Equal case
        BSF LATA, 1
        BRA cmp_done

not_equal:
        ; Not equal case
        CPFSGT COUNTER      ; Compare, skip if COUNTER > W
        BRA less_or_equal

        ; Greater case
        BSF LATA, 2
        BRA cmp_done

less_or_equal:
        ; Less than or equal case
        BCF LATA, 2

cmp_done:
        RETURN

; Example: Bit toggle (PIC18 specific)
toggle_bits:
        BTG LATA, 0         ; Toggle bit 0 (PIC18 only!)
        BTG LATA, 1         ; Toggle bit 1
        BTG LATA, 2         ; Toggle bit 2
        RETURN

; Example: Set all bits (PIC18 specific)
set_all_bits:
        SETF LATA           ; Set all bits to 1 (PIC18 only!)
        RETURN

; Example: Negate value (PIC18 specific)
negate_example:
        MOVF COUNTER, 0     ; Load counter
        NEGF COUNTER        ; Negate it (two's complement, PIC18!)
        RETURN

        END                 ; End of program
