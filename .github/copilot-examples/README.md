# GitHub Copilot Reference Files for PIC Assembly

This directory contains reference files to help GitHub Copilot provide better code completions when writing PIC assembly code.

## How These Files Help Copilot

GitHub Copilot uses files in your repository as context when suggesting code. By keeping these reference files in your project, Copilot will:

1. **Learn the register addresses** for your target PIC device
2. **Understand the numeric addressing style** (no symbolic names from .inc files)
3. **Suggest architecture-appropriate instructions** (PIC16 vs PIC18)
4. **Follow coding conventions** shown in the examples
5. **Provide helpful comments** explaining what numeric addresses mean

## Files in This Directory

### Register Reference Files

**`pic16f18076-registers.asm`**
- Complete register definitions for PIC16F18076
- STATUS register bit definitions
- Common usage patterns
- Bank switching examples
- Use this when writing code for PIC16 devices

**`pic18f-q40-registers.asm`**
- Complete register definitions for PIC18F-Q40 series
- Access Bank organization
- PIC18-specific features (no bank switching needed)
- Advanced instruction examples
- Use this when writing code for PIC18 devices

### Complete Example Programs

**`complete-pic16-example.asm`**
- Full working program for PIC16F18076
- LED blink with delays
- Subroutine examples
- Shows proper structure and commenting
- Demonstrates bank switching
- Use as template for PIC16 projects

**`complete-pic18-example.asm`**
- Full working program for PIC18-Q40
- Software PWM for LED brightness control
- PIC18-specific instructions (BRA, ADDWFC, CPFSEQ, etc.)
- Conditional branch examples
- 16-bit arithmetic examples
- Use as template for PIC18 projects

## How to Use These Files

### Starting a New Assembly File

1. **Determine your target device and architecture**
   - PIC16F18076 → use PIC16 examples
   - PIC18F-Q40 → use PIC18 examples

2. **Copy register definitions to your file**
   ```asm
   ; Copy the register EQU section from the appropriate reference file
   STATUS    EQU 0x03
   PORTA     EQU 0x05
   TRISA     EQU 0x85
   ; etc.
   ```

3. **Let Copilot help with the rest**
   - As you type, Copilot will suggest completions based on the patterns in these files
   - It will use the correct numeric addresses
   - It will suggest appropriate instructions for your architecture

### Example Workflow

When you type:
```asm
; Initialize Port A as output
```

Copilot will suggest something like:
```asm
        BSF STATUS, RP0    ; Select Bank 1
        MOVLW 0x00         ; All outputs
        MOVWF TRISA        ; Configure Port A
        BCF STATUS, RP0    ; Back to Bank 0
```

This is because it learned from the examples that:
- Bank switching is needed for TRISA access on PIC16
- Numeric addresses are used (STATUS = 0x03, TRISA = 0x85)
- Comments explain what each instruction does

## Tips for Better Copilot Suggestions

### 1. Open Reference Files While Coding

Keep the relevant reference file open in another tab. Copilot uses open files as stronger context.

```bash
# Example: Working on PIC16 project
code main.asm                           # Your file
code .github/copilot-examples/pic16f18076-registers.asm  # Reference
```

### 2. Start with Comments

Write what you want to do in a comment, then let Copilot suggest the implementation:

```asm
; Turn on LED on Port A bit 0
```

Copilot will suggest:
```asm
        BSF PORTA, 0    ; Set bit 0 high
```

### 3. Copy Structure from Examples

Use the example files as templates:
- Copy the register definitions section
- Copy the ORG/GOTO structure
- Copy subroutine patterns
- Copilot will adapt them to your needs

### 4. Be Specific in Comments

More specific comments get better suggestions:

❌ Less helpful:
```asm
; Delay
```

✅ More helpful:
```asm
; Long delay using nested loops, outer=0xFF inner=0xFF
```

### 5. Indicate Architecture in File Header

Add this to the top of your file:
```asm
; ============================================
; Target: PIC16F18076
; Architecture: PIC16 (14-bit instructions)
; Assemble: gnsasm main.asm -a pic16
; ============================================
```

Copilot will use this to suggest PIC16-appropriate code.

## Common Patterns Copilot Learns

From these reference files, Copilot learns:

### Port Initialization
```asm
BSF STATUS, RP0     ; Select Bank 1 (PIC16)
MOVLW 0x00          ; All outputs
MOVWF TRISA         ; Configure direction
BCF STATUS, RP0     ; Back to Bank 0
```

### Delay Loops
```asm
MOVLW 0xFF
MOVWF DELAY_L
loop:
    DECFSZ DELAY_L, 1
    GOTO loop
```

### Bit Manipulation
```asm
BSF PORTA, 0        ; Set bit
BCF PORTA, 1        ; Clear bit
BTFSC STATUS, Z     ; Test bit, skip if clear
```

### Subroutine Structure
```asm
subroutine_name:
    ; Do something
    RETURN
```

## Architecture-Specific Differences

Copilot learns these key differences:

### PIC16 vs PIC18

| Feature | PIC16 | PIC18 |
|---------|-------|-------|
| Bank switching | Required (BSF STATUS, RP0) | Not needed |
| Relative branch | GOTO only | BRA available |
| Add with carry | Not available | ADDWFC |
| Bit toggle | Not available | BTG |
| Compare & skip | Not available | CPFSEQ, CPFSGT, CPFSLT |
| Set all bits | MOVLW 0xFF; MOVWF | SETF |
| Conditional branch | Use BTFSC/BTFSS + GOTO | BC, BZ, BN, etc. |

## Customizing for Your Device

If you're using a different PIC device:

1. **Copy one of the register files**
   ```bash
   cp pic16f18076-registers.asm pic16f877a-registers.asm
   ```

2. **Update register addresses from your datasheet**
   - Find "Memory Organization" section
   - Update PORTA, PORTB, etc. addresses
   - Update TRISA, TRISB, etc. addresses

3. **Add device-specific registers**
   ```asm
   ; Device-specific peripherals
   UART_TX   EQU 0x??
   UART_RX   EQU 0x??
   ```

4. **Keep the file open while coding**
   - Copilot will learn your custom definitions

## Troubleshooting

### Copilot suggests symbolic names (PORTA) instead of addresses (0x05)

**Solution:** Make sure you have EQU definitions at the top of your file:
```asm
PORTA EQU 0x05
```

Then Copilot will suggest `MOVWF PORTA` which expands to the address.

### Copilot suggests PIC18 instructions for PIC16 code

**Solution:** Add architecture comment at the top:
```asm
; Architecture: PIC16 (14-bit instructions)
```

And avoid having PIC18 example files open.

### Copilot suggests #include directives

**Solution:** Copilot learned from other projects. The instructions in `copilot-instructions.md` tell it not to suggest includes. If it persists, add this comment:
```asm
; NOTE: This assembler does not support #include directives
; Use EQU to define register addresses instead
```

## Further Reading

- See `../.github/copilot-instructions.md` for detailed Copilot guidelines
- Consult your device datasheet for register addresses
- See main `README.md` for assembler usage and limitations

## Contributing New Device Templates

To add a new device template:

1. Create new file: `pic[device]-registers.asm`
2. Follow the format of existing files
3. Include register definitions, bit definitions, and examples
4. Add device name and architecture to file header
5. Submit pull request

Example filename: `pic18f4550-registers.asm`
