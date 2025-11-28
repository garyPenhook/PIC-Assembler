# Programming PICs with ipecmd

Complete guide to programming your assembled HEX files using Microchip's command-line tool.

## What is ipecmd?

**ipecmd** (IPE Command) is Microchip's official command-line programming tool for PIC microcontrollers. It's the PIC equivalent of `avrdude` for AVR chips.

**Features:**
- ✅ Command-line interface (perfect for Makefiles and scripts)
- ✅ Supports all PIC devices (PIC10, PIC12, PIC16, PIC18, PIC24, dsPIC, PIC32)
- ✅ Works with all modern programmers (PICkit 3, 4, 5, Snap, ICD)
- ✅ Free (comes bundled with MPLAB IPE)
- ✅ Cross-platform (Windows, Linux, macOS)

---

## Installation

### Step 1: Download MPLAB IPE

**ipecmd** comes bundled with MPLAB IPE (Integrated Programming Environment).

**Download from:**
```
https://www.microchip.com/mplab/mplab-integrated-programming-environment
```

Or search: "MPLAB IPE download"

### Step 2: Install MPLAB IPE

- **Windows:** Run the installer `.exe`
- **Linux:** Extract and run the installer script
- **macOS:** Run the `.dmg` installer

### Step 3: Locate ipecmd

After installation, ipecmd is located at:

**Linux:**
```bash
/opt/microchip/mplabx/v6.20/mplab_platform/mplab_ipe/ipecmd.sh
```

**Windows:**
```
C:\Program Files\Microchip\MPLABX\v6.20\mplab_platform\mplab_ipe\ipecmd.exe
```

**macOS:**
```bash
/Applications/microchip/mplabx/v6.20/mplab_platform/mplab_ipe/ipecmd.sh
```

**Note:** Version number (v6.20) will vary based on your installation.

### Step 4: Add to PATH (Optional but Recommended)

**Linux/macOS:**
```bash
# Add to ~/.bashrc or ~/.zshrc
export PATH="/opt/microchip/mplabx/v6.20/mplab_platform/mplab_ipe:$PATH"

# Or create a symlink
sudo ln -s /opt/microchip/mplabx/v6.20/mplab_platform/mplab_ipe/ipecmd.sh /usr/local/bin/ipecmd
```

**Windows:**
```
Add to PATH environment variable:
C:\Program Files\Microchip\MPLABX\v6.20\mplab_platform\mplab_ipe
```

---

## Basic Usage

### Command Syntax

```bash
ipecmd -TP<tool> -P<device> -F<hexfile> [options]
```

### Essential Options

| Option | Description | Example |
|--------|-------------|---------|
| `-TP<tool>` | Programmer type | `-TPPK4` (PICkit 4) |
| `-P<device>` | Target device | `-P16F628A` |
| `-F<file>` | HEX file to program | `-Fprogram.hex` |
| `-M` | Program the device | `-M` |
| `-OL` | Display operation log | `-OL` |
| `-E` | Erase device first | `-E` |
| `-Y` | Verify after programming | `-Y` |

### Programmer Codes

| Programmer | Code |
|------------|------|
| PICkit 3 | `PK3` |
| PICkit 4 | `PK4` |
| PICkit 5 | `PK5` |
| MPLAB Snap | `SN` |
| ICD 3 | `ICD3` |
| ICD 4 | `ICD4` |
| ICD 5 | `ICD5` |
| REAL ICE | `RI` |

---

## Examples

### Example 1: Basic Programming (PICkit 4)

```bash
# Assemble the code
gnsasm blink.asm -a pic16 -o blink.hex

# Program the PIC16F628A
ipecmd -TPPK4 -P16F628A -Fblink.hex -M
```

### Example 2: Full Programming Sequence

```bash
# Erase, program, and verify
ipecmd -TPPK4 -P16F628A -Fblink.hex -E -M -Y -OL
```

### Example 3: PIC18 Device

```bash
# Assemble for PIC18
gnsasm program.asm -a pic18 -o program.hex

# Program PIC18F4550 with PICkit 5
ipecmd -TPPK5 -P18F4550 -Fprogram.hex -M -OL
```

### Example 4: Check Programmer Connection

```bash
# List connected programmers
ipecmd -TP<tool>

# Example: Check if PICkit 4 is connected
ipecmd -TPPK4
```

### Example 5: Read Device Info

```bash
# Read device ID
ipecmd -TPPK4 -P16F628A -GF
```

---

## Complete Workflow Example

### 1. Write Your Assembly Code

**blink.asm:**
```asm
; LED Blink for PIC16F628A
STATUS      EQU 0x03
PORTB       EQU 0x06
TRISB       EQU 0x86
CMCON       EQU 0x1F

        ORG 0x0000
        GOTO main

main:
        MOVLW 0x07
        MOVWF CMCON         ; Disable comparators
        BSF STATUS, 5       ; Bank 1
        CLRF TRISB          ; Port B outputs
        BCF STATUS, 5       ; Bank 0

loop:
        BSF PORTB, 0        ; LED on
        CALL delay
        BCF PORTB, 0        ; LED off
        CALL delay
        GOTO loop

delay:
        MOVLW 0xFF
        MOVWF 0x20
outer:
        MOVLW 0xFF
        MOVWF 0x21
inner:
        DECFSZ 0x21, 1
        GOTO inner
        DECFSZ 0x20, 1
        GOTO outer
        RETURN

        END
```

### 2. Assemble

```bash
gnsasm blink.asm -a pic16 -o blink.hex --verbose
```

**Output:**
```
Reading: blink.asm
Target: PIC16
Assembling...

Assembly successful!
Output written to: blink.hex

Statistics:
  Total instructions: 23
  Program words: 23
  Code size: 46 bytes (2.2% of 2KB)
```

### 3. Program the Device

```bash
ipecmd -TPPK4 -P16F628A -Fblink.hex -M -OL
```

**Expected Output:**
```
*****************************************************

Connecting to MPLAB PICkit 4...

Currently loaded versions:
Application version............01.07.15
Boot version...................01.01.03
Script version.................00.06.79
Script build number............0

Target voltage detected
Target device PIC16F628A found.
Device ID Revision = 5

Erasing...
Programming...
Verifying...

Program succeeded.
```

### 4. Test Your Hardware

Power up your PIC - the LED should blink! 🎉

---

## Makefile Integration

Create a `Makefile` for automated build and programming:

```makefile
# PIC Project Makefile
# Uses gnsasm and ipecmd

# Configuration
IPECMD = ipecmd
DEVICE = 16F628A
PROGRAMMER = PK4
ARCH = pic16

# Source files
SRC = blink.asm
HEX = $(SRC:.asm=.hex)

# Default target
.PHONY: all
all: $(HEX)

# Assemble
%.hex: %.asm
	@echo "Assembling $<..."
	gnsasm $< -a $(ARCH) -o $@ --verbose

# Program device
.PHONY: program flash
program flash: $(HEX)
	@echo "Programming $(DEVICE)..."
	$(IPECMD) -TP$(PROGRAMMER) -P$(DEVICE) -F$(HEX) -E -M -Y -OL

# Erase device
.PHONY: erase
erase:
	@echo "Erasing $(DEVICE)..."
	$(IPECMD) -TP$(PROGRAMMER) -P$(DEVICE) -E -OL

# Verify
.PHONY: verify
verify: $(HEX)
	@echo "Verifying $(DEVICE)..."
	$(IPECMD) -TP$(PROGRAMMER) -P$(DEVICE) -F$(HEX) -Y -OL

# Clean build artifacts
.PHONY: clean
clean:
	rm -f *.hex

# Help
.PHONY: help
help:
	@echo "PIC Build System"
	@echo ""
	@echo "Targets:"
	@echo "  make          - Assemble source code"
	@echo "  make program  - Program device"
	@echo "  make erase    - Erase device"
	@echo "  make verify   - Verify programming"
	@echo "  make clean    - Remove build files"
	@echo ""
	@echo "Configuration:"
	@echo "  Device:      $(DEVICE)"
	@echo "  Programmer:  $(PROGRAMMER)"
	@echo "  Architecture: $(ARCH)"
```

**Usage:**
```bash
# Build and program in one command
make && make program

# Or just
make program   # Automatically builds first

# Erase the device
make erase

# Clean up
make clean
```

---

## Advanced Options

### Set Configuration Bits

```bash
# Load configuration from file
ipecmd -TPPK4 -P16F628A -Fblink.hex -M -LC

# Manually set configuration
ipecmd -TPPK4 -P16F628A -Fblink.hex -M -CFCONFIG,0x3F71
```

### Power Target from Programmer

```bash
# Supply 5V to target
ipecmd -TPPK4 -P16F628A -Fblink.hex -M -W5

# Supply 3.3V to target
ipecmd -TPPK4 -P16F628A -Fblink.hex -M -W3.3
```

### Programming Speed

```bash
# Set programming speed (default is 0 = fastest)
ipecmd -TPPK4 -P16F628A -Fblink.hex -M -S1
```

### Batch Mode (Silent)

```bash
# Suppress output
ipecmd -TPPK4 -P16F628A -Fblink.hex -M -Q
```

### Production Programming

```bash
# Erase + Program + Verify + Lock Code Protection
ipecmd -TPPK4 -P16F628A -Fblink.hex -E -M -Y -CFCONFIG,CP_ON -OL
```

---

## Troubleshooting

### Problem: "ipecmd: command not found"

**Solution:** ipecmd is not in your PATH.

Use full path:
```bash
/opt/microchip/mplabx/v6.20/mplab_platform/mplab_ipe/ipecmd.sh -TPPK4 ...
```

Or add to PATH (see Installation section).

---

### Problem: "No tool connected"

**Solutions:**
1. Check USB cable connection
2. Try a different USB port
3. Check programmer LED (should be solid or blinking)
4. Run with sudo/administrator on Linux:
   ```bash
   sudo ipecmd -TPPK4 -P16F628A -Fblink.hex -M
   ```
5. Check USB permissions (Linux):
   ```bash
   # Add yourself to dialout group
   sudo usermod -a -G dialout $USER
   # Log out and back in
   ```

---

### Problem: "Device not found"

**Solutions:**
1. Check MCLR connection (must be pulled high or connected to programmer)
2. Check power supply (VDD and VSS)
3. Check PGC/PGD connections
4. Verify device name spelling:
   ```bash
   # Correct
   ipecmd -TPPK4 -P16F628A ...

   # Wrong
   ipecmd -TPPK4 -PPIC16F628A ...  # Don't add "PIC" prefix
   ```

---

### Problem: "Programming failed"

**Solutions:**
1. Try erasing first: `-E` option
2. Lower programming speed: `-S1`
3. Check target voltage (should be 3.3V or 5V)
4. Verify HEX file is valid:
   ```bash
   cat blink.hex  # Should show Intel HEX format
   ```

---

### Problem: "Verification failed"

**Solutions:**
1. Erase device first: `-E`
2. Check power supply stability
3. Check for loose connections
4. Try programming without verify, then verify separately:
   ```bash
   ipecmd -TPPK4 -P16F628A -Fblink.hex -E -M
   ipecmd -TPPK4 -P16F628A -Fblink.hex -Y
   ```

---

## Tips and Best Practices

### 1. Always Use Erase Flag
```bash
# Good practice
ipecmd -TPPK4 -P16F628A -Fblink.hex -E -M
```
Ensures clean programming, especially when updating code.

### 2. Verify After Programming
```bash
# Add -Y flag
ipecmd -TPPK4 -P16F628A -Fblink.hex -E -M -Y
```
Catches programming errors early.

### 3. Use Operation Log
```bash
# Add -OL flag for debugging
ipecmd -TPPK4 -P16F628A -Fblink.hex -E -M -Y -OL
```
Shows detailed information about what's happening.

### 4. Power from Programmer During Development
```bash
# Supply power from programmer (no external supply needed)
ipecmd -TPPK4 -P16F628A -Fblink.hex -M -W5
```
Convenient during prototyping.

### 5. Create Wrapper Scripts
```bash
#!/bin/bash
# prog.sh - Quick programming script

DEVICE=$1
HEXFILE=$2

if [ -z "$DEVICE" ] || [ -z "$HEXFILE" ]; then
    echo "Usage: prog.sh <device> <hexfile>"
    echo "Example: prog.sh 16F628A blink.hex"
    exit 1
fi

ipecmd -TPPK4 -P$DEVICE -F$HEXFILE -E -M -Y -OL
```

**Usage:**
```bash
chmod +x prog.sh
./prog.sh 16F628A blink.hex
```

---

## Complete Command Reference

### Display Help
```bash
ipecmd -?
ipecmd --help
```

### Common Command Patterns

**Basic programming:**
```bash
ipecmd -TP<tool> -P<device> -F<hex> -M
```

**Erase + Program:**
```bash
ipecmd -TP<tool> -P<device> -F<hex> -E -M
```

**Erase + Program + Verify:**
```bash
ipecmd -TP<tool> -P<device> -F<hex> -E -M -Y
```

**Full production programming:**
```bash
ipecmd -TP<tool> -P<device> -F<hex> -E -M -Y -OL -W5
```

### Exit Codes

| Code | Meaning |
|------|---------|
| 0 | Success |
| 1 | Error (see log) |
| 2 | Device not found |
| 3 | Tool not found |
| 4 | Programming failed |
| 5 | Verification failed |

**Use in scripts:**
```bash
#!/bin/bash
if ipecmd -TPPK4 -P16F628A -Fblink.hex -M; then
    echo "Programming successful!"
else
    echo "Programming failed!"
    exit 1
fi
```

---

## Comparison: ipecmd vs GUI Tools

| Feature | ipecmd | MPLAB IPE (GUI) |
|---------|--------|-----------------|
| Interface | Command-line | Graphical |
| Automation | ✅ Excellent | ❌ Manual only |
| Makefiles | ✅ Perfect | ❌ Not suitable |
| CI/CD | ✅ Yes | ❌ No |
| Batch programming | ✅ Easy | ⚠️ Tedious |
| Beginner-friendly | ⚠️ Learning curve | ✅ Very easy |
| Configuration bits | ⚠️ Manual | ✅ GUI editor |
| Speed | ✅ Fast | ⚠️ Slower |

**Recommendation:**
- **Learning/Testing:** Use MPLAB IPE (GUI)
- **Development/Production:** Use ipecmd (CLI)

---

## Integration with Development Tools

### VS Code Task

Create `.vscode/tasks.json`:
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Assemble",
            "type": "shell",
            "command": "gnsasm",
            "args": [
                "${file}",
                "-a",
                "pic16",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}.hex"
            ],
            "group": "build",
            "presentation": {
                "reveal": "always",
                "panel": "new"
            }
        },
        {
            "label": "Program PIC",
            "type": "shell",
            "command": "ipecmd",
            "args": [
                "-TPPK4",
                "-P16F628A",
                "-F${fileDirname}/${fileBasenameNoExtension}.hex",
                "-E",
                "-M",
                "-Y",
                "-OL"
            ],
            "dependsOn": ["Assemble"],
            "group": "test"
        }
    ]
}
```

**Usage:** Press `Ctrl+Shift+B` → Select "Program PIC"

---

## Quick Reference Card

**One-liner for common workflow:**
```bash
gnsasm program.asm -a pic16 -o program.hex && ipecmd -TPPK4 -P16F628A -Fprogram.hex -E -M -Y -OL
```

**Essential flags to remember:**
- `-E` = Erase first
- `-M` = Program/flash
- `-Y` = Verify
- `-OL` = Show log

**Device naming:**
- PIC**16F**628A → `-P16F628A`
- PIC**18F**4550 → `-P18F4550`
- PIC**12F**675 → `-P12F675`

(Drop "PIC" prefix, keep the rest)

---

## Additional Resources

**Official Documentation:**
- MPLAB IPE User's Guide: https://www.microchip.com/mplab/mplab-integrated-programming-environment
- ipecmd Manual: Installed with MPLAB IPE at `docs/` folder

**Community:**
- Microchip Forums: https://www.microchip.com/forums/
- PICList: http://www.piclist.com/

**Related Tools:**
- **gnsasm**: This assembler (you're using it!)
- **MPLAB IPE**: GUI version of ipecmd
- **MPLAB X IDE**: Full development environment

---

**Happy Programming! 🚀**

Use gnsasm to assemble, ipecmd to program, and enjoy your PIC projects!
