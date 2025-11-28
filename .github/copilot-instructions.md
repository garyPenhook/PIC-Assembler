# GitHub Copilot Instructions for PIC Assembly Development

## Project Context

This is the GnSasm assembler project for Microchip PIC microcontrollers. When suggesting code completions for `.asm` files, follow these guidelines:

## Assembly Syntax Rules

### Architecture-Specific Code

This assembler supports three architectures:
- **PIC12**: 12-bit baseline (12-bit instruction words)
- **PIC16**: Mid-range (14-bit instruction words)
- **PIC18**: Enhanced (16-bit instruction words)

### Numeric Addressing Philosophy

**IMPORTANT**: This assembler does NOT use symbolic register names from `.inc` files. All register references must use numeric addresses.

**Do NOT suggest:**
```asm
MOVWF PORTA
BSF STATUS, Z
CLRF TRISA
```

**DO suggest:**
```asm
MOVWF 0x0C     ; PORTA for PIC16F18076
BSF 0x03, 2    ; STATUS register, Zero flag
CLRF 0x8C      ; TRISA
```

### Comment Style

Always include comments explaining what numeric addresses represent:

```asm
MOVWF 0x0C     ; Write to PORTA (0x0C)
BSF 0x03, 2    ; Set Zero flag in STATUS (0x03, bit 2)
INCF 0x20, 1   ; Increment counter in file register 0x20
```

### Directive Format

Supported directives:
- `ORG <address>` - Set origin address
- `END` - End of program
- `EQU` - Define constant (name=value)
- `DB` - Define byte data
- `DW` - Define word data

Example:
```asm
        ORG 0x0000

; Define constants for readability
COUNTER EQU 0x20
PORTA   EQU 0x0C
STATUS  EQU 0x03

start:  MOVLW 0x00
        MOVWF COUNTER
        END
```

### Number Formats

Support these formats:
- Decimal: `255`, `10`, `0`
- Hexadecimal: `0xFF`, `0x0A`, `0x00`
- Binary: `0b11111111`, `0b00001010`

### Label Format

Labels must end with colon:
```asm
start:          ; Good
loop:           ; Good
delay_loop:     ; Good
```

### Instruction Format

Pattern: `MNEMONIC operand1, operand2 ; comment`

**PIC16 byte-oriented:**
```asm
ADDWF 0x20, 1   ; Add W to file 0x20, store in file (d=1)
MOVF 0x21, 0    ; Move file 0x21 to W (d=0)
INCF 0x22, 1    ; Increment file 0x22
```

**PIC16 bit-oriented:**
```asm
BCF 0x03, 0     ; Clear bit 0 in STATUS register
BSF 0x0C, 5     ; Set bit 5 in PORTA
BTFSC 0x03, 2   ; Test bit 2 in STATUS, skip if clear
```

**PIC16 literal/control:**
```asm
MOVLW 0x55      ; Move literal 0x55 to W
ADDLW 0x10      ; Add literal 0x10 to W
GOTO start      ; Jump to label
CALL subroutine ; Call subroutine
```

**PIC18-specific instructions:**
```asm
ADDWFC 0x20, 1  ; Add W to file with carry (PIC18 only)
BRA loop        ; Branch relative (PIC18 only)
CPFSEQ 0x21     ; Compare file with W, skip if equal (PIC18)
SETF 0x22       ; Set all bits in file (PIC18)
```

## Device-Specific Guidelines

### PIC16F18076 (PIC16 Architecture)

Common register addresses:
```asm
; Core registers
INDF    EQU 0x00
TMR0    EQU 0x01
PCL     EQU 0x02
STATUS  EQU 0x03
FSR     EQU 0x04
PORTA   EQU 0x0C
PORTB   EQU 0x0D
PORTC   EQU 0x0E

; Bank 1 (access via BSF STATUS, 5)
TRISA   EQU 0x8C
TRISB   EQU 0x8D
TRISC   EQU 0x8E
```

**STATUS register bits:**
```asm
; STATUS (0x03) bit positions
C       EQU 0   ; Carry/borrow
DC      EQU 1   ; Digit carry/borrow
Z       EQU 2   ; Zero flag
PD      EQU 3   ; Power-down
TO      EQU 4   ; Time-out
RP0     EQU 5   ; Register bank select 0
RP1     EQU 6   ; Register bank select 1
IRP     EQU 7   ; Indirect addressing
```

Typical PIC16F18076 initialization:
```asm
        ORG 0x0000

init:   CLRF 0x03       ; Clear STATUS
        BSF 0x03, 5     ; Select bank 1
        MOVLW 0x00      ; All outputs
        MOVWF 0x8C      ; Write to TRISA
        BCF 0x03, 5     ; Select bank 0
```

### PIC18F-Q40 (PIC18 Architecture)

Common register addresses:
```asm
; Access Bank (always accessible)
WREG    EQU 0x00
FSR0L   EQU 0x01
FSR0H   EQU 0x02
STATUS  EQU 0x03
PORTA   EQU 0x0C
LATA    EQU 0x10
TRISA   EQU 0x14
```

**STATUS register bits:**
```asm
; STATUS (0x03) bit positions
C       EQU 0   ; Carry/borrow
DC      EQU 1   ; Digit carry/borrow
Z       EQU 2   ; Zero flag
OV      EQU 3   ; Overflow
N       EQU 4   ; Negative
```

Typical PIC18-Q40 initialization:
```asm
        ORG 0x0000

init:   CLRF 0x03       ; Clear STATUS
        SETF 0x14       ; Set TRISA (all inputs)
        CLRF 0x10       ; Clear LATA
        MOVLW 0x00
        MOVWF 0x14      ; TRISA = 0 (all outputs)
```

## Code Patterns to Suggest

### Delay Loop Pattern (PIC16)
```asm
delay:  MOVLW 0xFF      ; Load delay count
        MOVWF 0x20      ; Store in counter register
loop:   DECFSZ 0x20, 1  ; Decrement, skip if zero
        GOTO loop       ; Continue loop
        RETURN          ; Return when done
```

### Port Manipulation Pattern
```asm
; Set specific bits
        BSF 0x0C, 0     ; Set PORTA bit 0 high
        BSF 0x0C, 1     ; Set PORTA bit 1 high

; Clear specific bits
        BCF 0x0C, 2     ; Clear PORTA bit 2

; Toggle pattern
        MOVLW 0xFF      ; All high
        XORWF 0x0C, 1   ; Toggle all PORTA bits
```

### Conditional Execution Pattern
```asm
; Check if zero
        MOVF 0x20, 0    ; Move file to W (sets Z flag)
        BTFSC 0x03, 2   ; Test Zero flag, skip if clear
        GOTO is_zero    ; Execute if zero

; Check if bit set
        BTFSS 0x0C, 3   ; Test PORTA bit 3, skip if set
        GOTO bit_clear  ; Execute if clear
```

### Subroutine Pattern
```asm
main:   CALL init_ports
        CALL main_loop

init_ports:
        BSF 0x03, 5     ; Bank 1
        MOVLW 0x00
        MOVWF 0x8C      ; TRISA = 0 (outputs)
        BCF 0x03, 5     ; Bank 0
        RETURN
```

## What NOT to Suggest

1. **Symbolic register names without definitions:**
   ```asm
   MOVWF PORTA    ; ❌ NO - PORTA not defined
   ```

2. **Include directives:**
   ```asm
   #include <p16f18076.inc>  ; ❌ NO - Not supported
   ```

3. **Preprocessor directives:**
   ```asm
   #ifdef DEBUG    ; ❌ NO - Not supported
   #define PORTA 0x0C  ; ❌ NO - Use EQU instead
   ```

4. **Architecture-incompatible instructions:**
   ```asm
   ; For PIC16 file, don't suggest PIC18 instructions:
   BRA loop        ; ❌ NO for PIC16
   ADDWFC 0x20, 1  ; ❌ NO for PIC16
   ```

## Best Practices

1. **Always comment numeric addresses:**
   ```asm
   MOVWF 0x20      ; Write to counter variable
   BSF 0x03, 2     ; Set Zero flag in STATUS
   ```

2. **Use EQU for frequently-used addresses:**
   ```asm
   COUNTER EQU 0x20
   TEMP    EQU 0x21

   MOVWF COUNTER   ; Now this is clear and portable
   ```

3. **Organize code with clear sections:**
   ```asm
   ; ============================================
   ; Constants and Variables
   ; ============================================
   COUNTER EQU 0x20
   STATUS  EQU 0x03

   ; ============================================
   ; Main Program
   ; ============================================
           ORG 0x0000
   start:  ; Your code here
   ```

4. **Include architecture in file header:**
   ```asm
   ; ============================================
   ; PIC16F18076 Main Program
   ; Target: PIC16 (-a pic16)
   ; ============================================
   ```

## Summary

When providing code completions:
- Use numeric addresses, not symbolic names
- Include helpful comments explaining what addresses represent
- Respect the target architecture (PIC12/PIC16/PIC18)
- Follow the directive syntax (ORG, END, EQU, DB, DW)
- Suggest EQU definitions for commonly-used addresses
- Use proper label format (name:)
- Match the coding style shown in these examples
