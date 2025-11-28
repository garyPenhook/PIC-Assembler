# Complete Beginner's Tutorial: Writing PIC Assembly with gnsasm

This tutorial will teach you how to write working PIC assembly code from scratch, even if you've never programmed a microcontroller before.

## Table of Contents
1. [What You Need](#what-you-need)
2. [Your First Program - Blink an LED](#your-first-program---blink-an-led)
3. [Understanding the Code](#understanding-the-code)
4. [Assembling Your Code](#assembling-your-code)
5. [Understanding the Output](#understanding-the-output)
6. [Programming Your PIC](#programming-your-pic)
7. [Common Patterns and Examples](#common-patterns-and-examples)
8. [Troubleshooting](#troubleshooting)
9. [Next Steps](#next-steps)

---

## What You Need

### Hardware
- A PIC microcontroller (this tutorial uses **PIC16F628A** - a popular beginner chip)
- A PIC programmer (PICkit 3, PICkit 4, or clone)
- A breadboard
- An LED and 330Ω resistor
- 5V power supply

### Software
- **gnsasm** - This assembler (already built)
- **MPLAB IPE** - For programming the PIC (free from Microchip)
- A text editor (VS Code, Notepad++, or any plain text editor)

### Check Your Installation

Open a terminal and run:
```bash
./gnsasm --version
```

You should see:
```
gnsasm PIC Assembler v1.2
```

---

## Your First Program - Blink an LED

Let's start with the classic "Hello World" of microcontrollers: blinking an LED.

### The Circuit

```
PIC16F628A Connections:
- Pin 5 (VSS) → Ground
- Pin 14 (VDD) → +5V
- Pin 6 (RB0) → LED → 330Ω resistor → Ground
- Pin 4 (RA5/MCLR) → +5V (through 10kΩ resistor)
```

### The Code

Create a new file called `blink.asm`:

```asm
; ============================================
; LED Blink Program for PIC16F628A
; Target: PIC16F628A
; Architecture: PIC16 (14-bit instructions)
; LED connected to RB0 (Pin 6)
; ============================================

; ============================================
; Register Definitions
; ============================================
; These are the memory addresses of important registers
STATUS      EQU 0x03    ; Status register (controls bank switching)
PORTA       EQU 0x05    ; Port A data
PORTB       EQU 0x06    ; Port B data
INTCON      EQU 0x0B    ; Interrupt control
CMCON       EQU 0x1F    ; Comparator control

; Bank 1 registers (need to switch banks to access)
OPTION_REG  EQU 0x81    ; Option register
TRISA       EQU 0x85    ; Port A direction (1=input, 0=output)
TRISB       EQU 0x86    ; Port B direction

; STATUS register bits
RP0         EQU 5       ; Bank select bit

; Variables (our own RAM storage)
DELAY_COUNT1 EQU 0x20   ; Delay counter 1
DELAY_COUNT2 EQU 0x21   ; Delay counter 2

; ============================================
; Program Start
; ============================================
        ORG 0x0000          ; Start of program memory
        GOTO main           ; Jump to main program

; ============================================
; Main Program
; ============================================
main:
        ; Step 1: Disable comparators (needed for digital I/O)
        MOVLW 0x07          ; Load 7 into W register
        MOVWF CMCON         ; Write to comparator control (turns off comparators)

        ; Step 2: Configure ports
        BSF STATUS, RP0     ; Set RP0 = 1 (switch to Bank 1)
        CLRF TRISA          ; All Port A pins as outputs
        CLRF TRISB          ; All Port B pins as outputs
        BCF STATUS, RP0     ; Clear RP0 = 0 (back to Bank 0)

        ; Step 3: Clear ports
        CLRF PORTA          ; Turn off all Port A pins
        CLRF PORTB          ; Turn off all Port B pins

; ============================================
; Main Loop - Blink Forever
; ============================================
loop:
        ; Turn LED ON
        BSF PORTB, 0        ; Set bit 0 of Port B (RB0) HIGH
        CALL delay          ; Wait

        ; Turn LED OFF
        BCF PORTB, 0        ; Clear bit 0 of Port B (RB0) LOW
        CALL delay          ; Wait

        GOTO loop           ; Repeat forever

; ============================================
; Delay Subroutine
; ============================================
; Creates approximately 500ms delay at 4MHz
delay:
        MOVLW 0xFF          ; Load 255 into W
        MOVWF DELAY_COUNT1  ; Store in counter 1
delay_outer:
        MOVLW 0xFF          ; Load 255 into W
        MOVWF DELAY_COUNT2  ; Store in counter 2
delay_inner:
        DECFSZ DELAY_COUNT2, 1  ; Decrement counter 2, skip next if zero
        GOTO delay_inner        ; Not zero, keep looping

        DECFSZ DELAY_COUNT1, 1  ; Decrement counter 1, skip next if zero
        GOTO delay_outer        ; Not zero, keep looping

        RETURN              ; Return from subroutine

; ============================================
; End of Program
; ============================================
        END
```

---

## Understanding the Code

Let's break down what each part does:

### 1. Comments and Headers
```asm
; ============================================
; LED Blink Program for PIC16F628A
; ============================================
```
Lines starting with `;` are **comments** - they're ignored by the assembler but help you understand your code.

### 2. Register Definitions (EQU Directives)
```asm
STATUS      EQU 0x03    ; Status register
PORTB       EQU 0x06    ; Port B data
```
**EQU** means "equals". This tells the assembler that whenever you write `STATUS`, it should use the address `0x03`.

**Why?** Instead of writing:
```asm
BSF 0x03, 5         ; What does this mean?
```

You can write:
```asm
BSF STATUS, RP0     ; Much clearer!
```

### 3. ORG - Where Code Goes
```asm
        ORG 0x0000          ; Start at address 0
        GOTO main           ; Jump to main
```
**ORG** sets where the code goes in memory. PICs start executing at address `0x0000` when powered on.

### 4. Initialization
```asm
main:
        MOVLW 0x07          ; Move Literal to W register
        MOVWF CMCON         ; Move W to File register
```
**MOVLW** = Move Literal to W (working register)
**MOVWF** = Move W to File (memory location)

This loads the value `0x07` into the `CMCON` register to disable the comparators.

### 5. Bank Switching
```asm
        BSF STATUS, RP0     ; Switch to Bank 1
        CLRF TRISB          ; Configure Port B
        BCF STATUS, RP0     ; Back to Bank 0
```
PIC16 memory is divided into **banks**. Some registers (like `TRISB`) are in Bank 1.

**BSF** = Bit Set File (set bit to 1)
**BCF** = Bit Clear File (clear bit to 0)
**CLRF** = Clear File (set all bits to 0)

### 6. Main Loop
```asm
loop:
        BSF PORTB, 0        ; Turn on bit 0
        CALL delay          ; Call delay subroutine
        BCF PORTB, 0        ; Turn off bit 0
        CALL delay
        GOTO loop           ; Jump back to loop
```
This runs forever, turning the LED on and off.

**CALL** = Call subroutine (jump to delay, then come back)
**GOTO** = Jump to label (don't come back)

### 7. Delay Subroutine
```asm
delay:
        MOVLW 0xFF
        MOVWF DELAY_COUNT1
delay_outer:
        MOVLW 0xFF
        MOVWF DELAY_COUNT2
delay_inner:
        DECFSZ DELAY_COUNT2, 1
        GOTO delay_inner
        DECFSZ DELAY_COUNT1, 1
        GOTO delay_outer
        RETURN
```
**DECFSZ** = Decrement File, Skip if Zero
**RETURN** = Return from subroutine

This creates nested loops: 255 × 255 = 65,025 cycles ≈ 500ms at 4MHz.

---

## Assembling Your Code

Now let's turn your assembly code into a HEX file the PIC can understand.

### Step 1: Save Your Code
Save the code above as `blink.asm`

### Step 2: Run the Assembler
```bash
./gnsasm blink.asm -a pic16 -o blink.hex --verbose
```

**What this means:**
- `./gnsasm` - Run the assembler
- `blink.asm` - Input file
- `-a pic16` - Architecture (PIC16 for PIC16F628A)
- `-o blink.hex` - Output file name
- `--verbose` - Show detailed information

### Step 3: Check for Success
You should see:
```
[PASS 1] Reading source file and building symbol table...
[PASS 2] Generating machine code...
Assembly successful!
Output written to: blink.hex

Statistics:
  Total instructions: 23
  Program words: 23
  Data memory used: 2 bytes
  Code size: 46 bytes (1.1% of 2KB)
```

✅ **Success!** You now have `blink.hex` ready to program!

### Common Assembly Errors

**Error: Undefined label**
```
Error at line 15: Undefined label 'main'
```
**Fix:** Make sure you defined the label with `main:`

**Error: Invalid operand**
```
Error at line 20: Invalid operand for BSF
```
**Fix:** Check that you're using the right format: `BSF PORTB, 0`

**Error: Value out of range**
```
Error at line 25: Literal value 0x300 out of range
```
**Fix:** PIC16 literals must be 0x00-0xFF (0-255)

---

## Understanding the Output

Let's look at the HEX file that was created:

```bash
cat blink.hex
```

You'll see something like:
```
:020000040000FA
:1000000000288A0186018A018701050186010608C5
:0E00100007302000FF30210FFF302208092883
:02001E00FD2807
:02400E00F13F7C
:00000001FF
```

### What is this?

This is **Intel HEX format** - a standard way to represent binary data.

**Structure of a HEX line:**
```
:10 0000 00 0028 8A01 8601 8A01 8701 0501 8601 0608 C5
 ↑   ↑   ↑  ↑                                          ↑
 │   │   │  └─ Data (machine code)                    └─ Checksum
 │   │   └─ Record type (00 = data)
 │   └─ Address (where this goes in memory)
 └─ Byte count (how many data bytes)
```

**You don't need to understand this!** The programmer software reads it automatically.

### Viewing Disassembly

To see what instructions were generated:
```bash
./gnsasm blink.asm -a pic16 -o blink.hex --verbose
```

Look for output like:
```
0x0000: GOTO 0x0005     ; Jump to main
0x0005: MOVLW 0x07      ; Disable comparators
0x0006: MOVWF 0x1F      ; Write to CMCON
```

---

## Programming Your PIC

### Step 1: Connect Your Programmer
Connect your PICkit to the PIC:
- **Pin 1 (MCLR)** → PIC Pin 4
- **Pin 2 (VDD)** → PIC Pin 14 (+5V)
- **Pin 3 (VSS)** → PIC Pin 5 (Ground)
- **Pin 4 (PGD)** → PIC Pin 13 (RB7)
- **Pin 5 (PGC)** → PIC Pin 12 (RB6)

### Step 2: Open MPLAB IPE
1. Launch **MPLAB IPE** (Integrated Programming Environment)
2. Select **Device**: PIC16F628A
3. Select **Tool**: Your PICkit
4. Click **Connect**

### Step 3: Load HEX File
1. Click **Browse** next to "Hex File"
2. Select your `blink.hex` file
3. Click **Program**

### Step 4: Watch the Magic!
The LED should start blinking! 🎉

---

## Common Patterns and Examples

### Pattern 1: Reading a Button

```asm
; Button on RB1 (Pin 7), LED on RB0 (Pin 6)

; Setup (in main):
        BSF STATUS, RP0     ; Bank 1
        BCF TRISB, 0        ; RB0 output (LED)
        BSF TRISB, 1        ; RB1 input (button)
        BCF OPTION_REG, 7   ; Enable pull-ups
        BCF STATUS, RP0     ; Bank 0

; Check button (in loop):
check_button:
        BTFSC PORTB, 1      ; Test bit 1, skip if clear (button pressed)
        GOTO button_up      ; Button not pressed

        ; Button is pressed
        BSF PORTB, 0        ; Turn LED on
        GOTO check_button

button_up:
        BCF PORTB, 0        ; Turn LED off
        GOTO check_button
```

**How it works:**
- **BTFSC** = Bit Test File, Skip if Clear
- Button not pressed = high (1), pressed = low (0)
- When pressed (0), BTFSC doesn't skip, LED turns on

### Pattern 2: Multiple Outputs

```asm
; Traffic light on RB0 (Red), RB1 (Yellow), RB2 (Green)

traffic_light:
        ; Green light
        BSF PORTB, 2        ; Green ON
        BCF PORTB, 1        ; Yellow OFF
        BCF PORTB, 0        ; Red OFF
        CALL long_delay

        ; Yellow light
        BCF PORTB, 2        ; Green OFF
        BSF PORTB, 1        ; Yellow ON
        BCF PORTB, 0        ; Red OFF
        CALL short_delay

        ; Red light
        BCF PORTB, 2        ; Green OFF
        BCF PORTB, 1        ; Yellow OFF
        BSF PORTB, 0        ; Red ON
        CALL long_delay

        GOTO traffic_light  ; Repeat
```

### Pattern 3: Using Variables

```asm
; Count how many times button was pressed

; Variables
BUTTON_COUNT EQU 0x20

; Initialization
        CLRF BUTTON_COUNT   ; Set counter to 0

; Main loop
main_loop:
        BTFSC PORTB, 1      ; Check button
        GOTO main_loop      ; Not pressed, keep checking

        ; Button pressed - increment counter
        INCF BUTTON_COUNT, 1    ; Increment counter

        ; Wait for button release
wait_release:
        BTFSS PORTB, 1      ; Skip if button released
        GOTO wait_release

        ; Display count on LEDs (Port A)
        MOVF BUTTON_COUNT, 0    ; Read counter to W
        MOVWF PORTA             ; Display on Port A

        GOTO main_loop
```

**New instructions:**
- **INCF** = Increment File (add 1)
- **BTFSS** = Bit Test File, Skip if Set
- **MOVF** = Move File to W

### Pattern 4: Creating Timing

```asm
; Different delay lengths

; Short delay (~100ms at 4MHz)
short_delay:
        MOVLW 0x64          ; 100 decimal
        MOVWF DELAY_COUNT1
short_loop:
        DECFSZ DELAY_COUNT1, 1
        GOTO short_loop
        RETURN

; Medium delay (~250ms at 4MHz)
medium_delay:
        MOVLW 0xFA          ; 250 decimal
        MOVWF DELAY_COUNT1
medium_outer:
        MOVLW 0xFA
        MOVWF DELAY_COUNT2
medium_inner:
        DECFSZ DELAY_COUNT2, 1
        GOTO medium_inner
        DECFSZ DELAY_COUNT1, 1
        GOTO medium_outer
        RETURN

; Long delay (~1 second at 4MHz)
long_delay:
        MOVLW 0xFF
        MOVWF DELAY_COUNT1
long_outer:
        MOVLW 0xFF
        MOVWF DELAY_COUNT2
long_middle:
        MOVLW 0x05
        MOVWF DELAY_COUNT3
long_inner:
        DECFSZ DELAY_COUNT3, 1
        GOTO long_inner
        DECFSZ DELAY_COUNT2, 1
        GOTO long_middle
        DECFSZ DELAY_COUNT1, 1
        GOTO long_outer
        RETURN
```

### Pattern 5: Math Operations

```asm
; Add two 8-bit numbers

NUM1        EQU 0x20
NUM2        EQU 0x21
RESULT      EQU 0x22

; Store 50 + 75 in RESULT
        MOVLW 0x32          ; 50 in hex
        MOVWF NUM1
        MOVLW 0x4B          ; 75 in hex
        MOVWF NUM2

        MOVF NUM1, 0        ; Load NUM1 into W
        ADDWF NUM2, 0       ; Add NUM2 to W
        MOVWF RESULT        ; Store in RESULT

; Subtract
        MOVF NUM2, 0        ; Load NUM2 into W
        SUBWF NUM1, 0       ; Subtract W from NUM1
        MOVWF RESULT        ; Result = NUM1 - NUM2
```

**New instructions:**
- **ADDWF** = Add W to File
- **SUBWF** = Subtract W from File

---

## Troubleshooting

### Problem: LED doesn't blink

**Check:**
1. **Wiring** - Is the LED connected correctly? (Long leg to PIC, short leg to resistor to ground)
2. **Polarity** - LED backwards? Try flipping it.
3. **Power** - Is VDD (Pin 14) at 5V? Is VSS (Pin 5) at ground?
4. **MCLR** - Pin 4 must be connected to +5V (with 10kΩ resistor)
5. **Fuses** - In MPLAB IPE, check Configuration Bits:
   - FOSC = INTOSCIO (internal oscillator)
   - WDTE = OFF (watchdog timer off)
   - PWRTE = ON (power-up timer on)
   - MCLRE = ON (MCLR pin enabled)
   - BOREN = ON (brown-out reset on)
   - LVP = OFF (low voltage programming off)
   - CPD = OFF (data code protection off)
   - CP = OFF (code protection off)

### Problem: Assembly fails with "unknown instruction"

**Check:**
1. Are you using the right architecture? PIC16F628A needs `-a pic16`
2. Did you spell the instruction correctly? `MOVFW` should be `MOVF`, etc.
3. Some instructions only work on certain PICs (check datasheet)

### Problem: "Undefined label" error

**Common causes:**
```asm
; WRONG - forgot the colon
main
        MOVLW 0x00

; CORRECT
main:
        MOVLW 0x00
```

```asm
; WRONG - jumped to undefined label
        GOTO my_loop

; CORRECT - define the label first
my_loop:
        BSF PORTB, 0
        GOTO my_loop
```

### Problem: Code does weird things

**Check your bank switching!** This is the #1 beginner mistake:

```asm
; WRONG - writing to TRISB in Bank 0 (writes to wrong register!)
        MOVLW 0x00
        MOVWF TRISB         ; This doesn't work!

; CORRECT - switch to Bank 1 first
        BSF STATUS, RP0     ; Bank 1
        MOVLW 0x00
        MOVWF TRISB         ; Now it works
        BCF STATUS, RP0     ; Back to Bank 0
```

### Problem: Delay is wrong length

**Clock speed matters!** This assembler doesn't set the clock.

If using **internal oscillator** (most common):
- Default is usually **4MHz**
- Can be changed via OSCCON register (see datasheet)

To change clock in code:
```asm
        BSF STATUS, RP0     ; Bank 1
        MOVLW 0x60          ; 4MHz internal oscillator
        MOVWF OSCCON
        BCF STATUS, RP0     ; Bank 0
```

Values for OSCCON:
- `0x60` = 4MHz
- `0x70` = 8MHz
- `0x50` = 2MHz
- `0x40` = 1MHz

---

## Next Steps

### Learn More Instructions

**Essential PIC16 Instructions:**
```asm
MOVLW   n       ; Move literal to W
MOVWF   f       ; Move W to file
MOVF    f,d     ; Move file (d=0: to W, d=1: to f)
CLRF    f       ; Clear file
CLRW            ; Clear W
BSF     f,b     ; Bit set file
BCF     f,b     ; Bit clear file
BTFSC   f,b     ; Bit test, skip if clear
BTFSS   f,b     ; Bit test, skip if set
INCF    f,d     ; Increment file
DECF    f,d     ; Decrement file
DECFSZ  f,d     ; Decrement file, skip if zero
ADDWF   f,d     ; Add W to file
SUBWF   f,d     ; Subtract W from file
ANDWF   f,d     ; AND W with file
IORWF   f,d     ; OR W with file
XORWF   f,d     ; XOR W with file
RRF     f,d     ; Rotate right through carry
RLF     f,d     ; Rotate left through carry
SWAPF   f,d     ; Swap nibbles
COMF    f,d     ; Complement (invert) file
GOTO    label   ; Jump to label
CALL    label   ; Call subroutine
RETURN          ; Return from subroutine
RETLW   n       ; Return with literal in W
SLEEP           ; Enter sleep mode
CLRWDT          ; Clear watchdog timer
NOP             ; No operation
```

### Try These Projects

**Project 1: Knight Rider LED Scanner**
- 8 LEDs on Port B
- Light moves back and forth
- Hints: Use RLF/RRF to shift the pattern

**Project 2: Reaction Timer**
- Button on RB0, LED on RB1
- Press button when LED lights
- Display time on 7-segment display
- Hints: Use Timer0 for timing

**Project 3: Digital Thermometer**
- LM35 temperature sensor on AN0
- Use ADC to read voltage
- Display on LCD
- Hints: Check ADCON0/ADCON1 in datasheet

**Project 4: UART Communication**
- Send "Hello" via serial port
- Receive commands from PC
- Echo back characters
- Hints: See reference file pic16f628a-registers.asm for USART setup

### Understanding Your PIC

**Read the datasheet!** Every PIC has a datasheet with:
- Pin diagrams
- Register addresses
- Electrical specifications
- Example code

Download from: https://www.microchip.com/

For PIC16F628A: Search "PIC16F628A datasheet"

**Important sections:**
- **Section 2**: Memory Organization (find register addresses)
- **Section 3**: I/O Ports (how to use PORTA/PORTB)
- **Section 14**: Instruction Set (all available instructions)
- **Appendix**: Register summary tables

### Get More Examples

Check the `.github/copilot-examples/` directory in this project:
- `pic16f628a-registers.asm` - Full register definitions
- `complete-pic16-example.asm` - Complete working program
- Many other device examples

### Use GitHub Copilot

If you use VS Code with GitHub Copilot:
1. Open one of the reference files from `.github/copilot-examples/`
2. Start typing your code
3. Copilot will suggest completions based on the patterns it learned!

Example: Type `; Blink LED on RB0` and watch Copilot suggest the code!

---

## Quick Reference Card

### Common Register Addresses (PIC16F628A)
```
Bank 0:              Bank 1:
PORTA    = 0x05      TRISA     = 0x85
PORTB    = 0x06      TRISB     = 0x86
STATUS   = 0x03      OPTION_REG= 0x81
INTCON   = 0x0B      PIE1      = 0x8C
```

### Bank Switching
```asm
BSF STATUS, RP0     ; Go to Bank 1
BCF STATUS, RP0     ; Go to Bank 0
```

### Common Patterns
```asm
; Set pin as output
BSF STATUS, RP0
BCF TRISB, 0        ; RB0 output
BCF STATUS, RP0

; Set pin as input
BSF STATUS, RP0
BSF TRISB, 1        ; RB1 input
BCF STATUS, RP0

; Turn output HIGH
BSF PORTB, 0

; Turn output LOW
BCF PORTB, 0

; Toggle output
MOVLW 0x01
XORWF PORTB, 1

; Read input
BTFSC PORTB, 1      ; Skip if input is 0
GOTO input_high
```

### Number Formats
```asm
MOVLW 100           ; Decimal
MOVLW 0x64          ; Hexadecimal (same as 100)
MOVLW b'01100100'   ; Binary (same as 100)
MOVLW d'100'        ; Explicit decimal
```

---

## Congratulations! 🎉

You've learned:
- ✅ How to write PIC assembly code
- ✅ How to assemble it with gnsasm
- ✅ How to program a real PIC chip
- ✅ Common patterns and techniques
- ✅ How to debug problems

**You're now a PIC programmer!**

Keep experimenting, read datasheets, and build cool projects!

---

## Additional Resources

**Official Microchip Resources:**
- [Microchip Developer Help](https://onlinedocs.microchip.com/)
- [PIC16 Instruction Set](https://ww1.microchip.com/downloads/en/devicedoc/33014a.pdf)
- [MPLAB IPE User's Guide](https://www.microchip.com/mplab/mplab-integrated-programming-environment)

**Community Resources:**
- [PICList](http://www.piclist.com/) - Active PIC community
- [Microchip Forums](https://www.microchip.com/forums/) - Official support
- [EEVblog Forums](https://www.eevblog.com/forum/) - Electronics community

**This Project:**
- `README.md` - Assembler features and command-line options
- `ARCHITECTURE.md` - How the assembler works internally
- `.github/copilot-examples/` - Device-specific register definitions
- `.github/copilot-instructions.md` - Coding style guide

**Need Help?**
- Check the [GitHub Issues](https://github.com/garyPenhook/PIC-Assembler/issues)
- Read the PIC datasheet for your specific chip
- Use verbose mode: `./gnsasm yourfile.asm -a pic16 --verbose`

Happy coding! 🚀
