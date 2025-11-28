# GnSasm - PIC®16/PIC®18 Assembler

A modern, standards-compliant assembler for Microchip® PIC® microcontrollers with MPASM®-compatible syntax. Supports both PIC®16 (14-bit) and PIC®18 (16-bit) instruction sets with helpful error messages and architecture validation.

**Latest Version:** 1.2
**Command:** `gnsasm`
**Target Devices:** PIC16F18076, PIC18-Q40, and compatible microcontrollers

## Features

✨ **Dual-Architecture Support**
- PIC®16 and PIC®16F microcontrollers (14-bit instruction words)
- PIC®18 and PIC®18-Q40 microcontrollers (16-bit instruction words)
- Architecture-aware instruction validation and encoding

🎯 **Complete Instruction Set Coverage**
- **PIC®16:** 35 instructions (100% coverage)
  - Byte-oriented, bit-oriented, literal/control operations
- **PIC®18:** 54+ instructions (100% coverage)
  - All byte-oriented, bit-oriented, conditional branches
  - Compare/skip, table operations, FSR operations
  - Stack operations, multiplication, and more

🔍 **Intelligent Error Reporting**
- Helpful error messages with line/column information
- Suggestions for common typos and mistakes
- Architecture validation with guidance
- Operand range checking
- Color-coded output for better readability

📝 **MPASM® Compatible**
- MPASM®-like syntax and directives (ORG, END, EQU)
- Support for decimal, hexadecimal (0xFF), and binary (0b1010) number formats
- Label support with colon notation
- Semicolon comments

⚡ **Performance**
- Compiled with C++23 standard
- -O3 optimization for fast assembly
- Two-pass assembly with forward label support

🔧 **Multiple Development Workflows**
- Command-line assembly for quick prototyping
- Makefile integration for larger projects
- IDE integration (MPLAB X, VS Code, CLion)
- Simulation and debugging support
- Hardware programmer compatibility (MPLAB-IPE, pk3cmd, etc.)
- Batch processing and CI/CD automation
- Cross-architecture development support
- Embedded project integration

## Device Register Names and Include Files

GnSasm now supports **optional symbolic device register names** from Microchip device include files (`.inc` files), providing full compatibility with MPASM-style assembly code. However, **include files are not required** - you can use numeric addresses directly.

### Two Approaches to PIC Assembly

**Approach 1: Direct Numeric Addresses (Recommended for Simplicity)**

No include files needed - reference registers by their hex addresses:

```asm
        ORG 0x0000

        MOVLW 0xFF
        MOVWF 0x0C      ; 0x0C = PORTA address
        BSF   0x03, 2   ; 0x03 = STATUS address, bit 2 = Z flag
        INCF  0x20, 1   ; 0x20 = general purpose RAM
```

**Approach 2: Symbolic Register Names (MPASM-Compatible)**

Use device include files for symbolic names:

```asm
#include <pic16f18076.inc>

        ORG 0x0000

        ; Use symbolic names from the include file
        MOVLW 0xFF
        MOVWF PORTA         ; PORTA = 0x0C (loaded from .inc)
        BSF   STATUS, Z     ; STATUS = 0x03 (loaded from .inc)
        INCF  buffer, F     ; buffer = user-defined variable
```

### When to Use Include Files

**Use direct addresses if:**
- You want the simplest, most portable code
- You don't want external dependencies
- You know the register addresses from your datasheet
- You prefer minimal overhead

**Use include files if:**
- You want MPASM-compatible symbolic names
- Your code is long and readability matters
- You want to avoid address typos
- You're porting code from MPASM

### How Include Files Work

1. **Load register definitions:** `#include <device.inc>` loads register name definitions
2. **Case-insensitive:** Register names work in any case: `PORTA = porta = PortA`
3. **Protected:** Device registers cannot be redefined with EQU or SET directives
4. **Priority:** Device registers have highest priority in symbol resolution

### Supported Devices

The assembler itself supports **all PIC® microcontroller families** including:
- **PIC12** baseline series (12-bit instructions)
- **PIC16/PIC16F** mid-range and enhanced mid-range (14-bit instructions)
- **PIC18/PIC18-Q40** high-performance (16-bit instructions)

Device include files are available from Microchip for **2,903+ devices**. See "Getting Device Include Files" above for how to obtain them.

### Getting Device Include Files

Device include files (`.inc`) are **optional** for basic assembly. They provide symbolic register names but are not required.

**Option 1: Use without device files (Simplest)**
- Use numeric addresses directly (see Approach 1 above)
- No additional setup needed
- Fully portable and self-contained

**Option 2: Add device files (MPASM-compatible)**

Device include files are provided by Microchip and can be extracted from their official device family packs (DFP). To use them:

1. **Download from Microchip:**
   - Visit [Microchip Device Family Packs](https://packs.download.microchip.com/)
   - Download the DFP for your device family (e.g., `pic16f1xxx_DFP`)

2. **Extract the files:**
   ```bash
   # The .inc files are usually in: content/device_files/pic16f1xxx/
   # Copy them to: ./device_includes/
   mkdir -p device_includes
   cp path/to/pic16f*.inc device_includes/
   ```

3. **Use in your assembly code:**
   ```asm
   #include <pic16f18076.inc>
   ; Now you can use symbolic names like PORTA, STATUS, etc.
   ```

Microchip's device include files are copyrighted and should be obtained directly from Microchip's official sources. They are not included in this repository to comply with licensing requirements.

### Define Your Own Constants

Create your own symbol definitions using the `EQU` directive:

```asm
; Define your own constants
MY_DELAY    EQU 10
BUFFER_SIZE EQU 256
MY_PORT     EQU 0x0C    ; Define custom names for addresses
MY_STATUS   EQU 0x03

; Use them in code
    MOVLW MY_DELAY
    MOVWF MY_PORT
    BSF   MY_STATUS, 2
```

### Finding Include File Names

Device include files use the device model number in lowercase with the `.inc` extension:
- `pic16f18076.inc` for PIC16F18076
- `pic18f14k50.inc` for PIC18F14K50
- `pic16f628a.inc` for PIC16F628A
- etc.

If you've downloaded device files from Microchip, place them in the `device_includes/` directory. The assembler will automatically find and use them. You can verify available files by checking the `device_includes/` folder after extraction.

## Supported Operating Systems

| OS | Support | Notes |
|---|---------|-------|
| **Linux** | ✅ Full | GCC 11+, Clang 13+ |
| **macOS** | ✅ Full | Apple Clang 13+, GCC 11+ |
| **Windows** | ✅ Full | MinGW-w64, MSVC 2019+, WSL |
| **BSD** | ✅ Full | Clang 13+ |

## Requirements

### System Requirements
- **CMake:** 3.20 or later
- **C++ Compiler:** Supporting C++23 standard
  - GCC 11.0 or later
  - Clang 13.0 or later
  - MSVC 2019 or later
  - Apple Clang 13.0 or later
- **RAM:** 256 MB minimum (512 MB recommended)
- **Disk Space:** 50 MB for build directory

### Build Requirements
```
CMake >= 3.20
C++ compiler with C++23 support
make or ninja build tool
git (for repository access)
```

## Installation

### Prerequisites Installation

#### Linux (Ubuntu/Debian)
```bash
sudo apt-get update
sudo apt-get install build-essential cmake git
sudo apt-get install gcc g++  # or clang for Clang compiler
```

#### Linux (Fedora/RHEL)
```bash
sudo dnf install gcc g++ cmake git make
```

#### Linux (Arch)
```bash
sudo pacman -S base-devel cmake git
```

#### macOS
```bash
# Using Homebrew
brew install cmake git gcc

# Or use Xcode Command Line Tools
xcode-select --install
```

#### Windows
1. **MinGW-w64:**
   - Download from [mingw-w64.org](https://www.mingw-w64.org/)
   - Add to PATH

2. **CMake:**
   - Download from [cmake.org](https://cmake.org/download/)
   - Enable "Add CMake to system PATH" during installation

3. **Git:**
   - Download from [git-scm.com](https://git-scm.com/)

### Building from Source

#### Clone Repository
```bash
git clone https://github.com/garyPenhook/PIC-Assembler.git
cd PIC-Assembler
```

> **Note:** PIC®, PIC®16, PIC®18, MPASM®, and Microchip® are registered trademarks of Microchip Technology Inc.

#### Configure and Build
```bash
# Create build directory
mkdir cmake-build-release
cd cmake-build-release

# Configure with CMake
cmake -DCMAKE_BUILD_TYPE=Release ..

# Build
cmake --build . -j$(nproc)

# Verify installation
./gnsasm --version
```

#### Install (Optional)
```bash
# Install to system location (Linux/macOS)
sudo cmake --install .

# Or install to custom location
cmake --install . --prefix /usr/local
```

### Build Configuration Options

```bash
# Standard release build (default)
cmake -DCMAKE_BUILD_TYPE=Release ..

# Debug build with symbols
cmake -DCMAKE_BUILD_TYPE=Debug ..

# Specify compiler
cmake -DCMAKE_CXX_COMPILER=g++ ..           # GCC
cmake -DCMAKE_CXX_COMPILER=clang++ ..       # Clang
cmake -DCMAKE_CXX_COMPILER=icpc ..          # Intel C++

# Custom installation prefix
cmake -DCMAKE_INSTALL_PREFIX=/usr/local ..

# Specify build system
cmake -G "Unix Makefiles" ..                # Make (default)
cmake -G "Ninja" ..                         # Ninja
cmake -G "Visual Studio 16 2019" ..         # Visual Studio
```

## Quick Start

### Basic Usage
```bash
# Assemble for PIC16 (default)
gnsasm program.asm

# Assemble for PIC18
gnsasm program.asm -a pic18

# Specify output file
gnsasm program.asm -o output.hex

# Verbose mode
gnsasm program.asm --verbose
```

### Command-Line Options
```bash
gnsasm [options] input.asm

Options:
  -a, --arch ARCH      Target architecture: pic16 or pic18 (default: pic16)
  -o, --output FILE    Output file (default: input.hex)
  -l, --listing        Generate listing file (.lst)
  --verbose            Show detailed assembly information
  -h, --help          Display help message
  -v, --version       Display version information

Examples:
  gnsasm program.asm
  gnsasm program.asm -a pic18
  gnsasm program.asm -o firmware.hex
  gnsasm program.asm --listing
  gnsasm program.asm -a pic18 -o firmware.hex --listing --verbose
```

## Development Workflows and Options

GnSasm supports multiple development approaches for programming PIC microcontrollers. This section explains each workflow and how to integrate GnSasm into your development pipeline.

### 1. **Command-Line Development**

The simplest approach: write assembly, assemble, and program.

#### Workflow:
```bash
# Write your assembly code
vi program.asm

# Assemble to HEX
gnsasm program.asm -a pic16 -o firmware.hex

# Program using external tool (MPLAB-IPE, pickit, etc.)
# Example with pickit command-line tool:
pk3cmd -P firmware.hex -F
```

#### Best For:
- Simple programs
- Quick prototyping
- Direct hardware programming
- CI/CD pipelines

### 2. **Make-Based Build System**

Integrate GnSasm into a Makefile for automated assembly and programming.

#### Example Makefile:
```makefile
# Assembler and programmer settings
ASSEMBLER = gnsasm
ARCH = pic16
PROGRAMMER = pk3cmd
DEVICE = PIC16F18076

# Source and output files
SOURCES = main.asm
OBJECTS = $(SOURCES:.asm=.hex)
TARGETS = $(SOURCES:.asm=.hex)

.PHONY: all clean program

all: $(TARGETS)

# Assemble rule
%.hex: %.asm
	$(ASSEMBLER) $< -a $(ARCH) -o $@

# Program device
program: $(TARGETS)
	$(PROGRAMMER) -P $< -F

clean:
	rm -f $(TARGETS)
```

#### Usage:
```bash
make                    # Assemble all files
make program            # Assemble and program device
make clean              # Clean build artifacts
```

#### Best For:
- Larger projects
- Reproducible builds
- One-command compilation and programming
- Version control friendly

### 3. **IDE Integration (MPLAB X / CLion / VS Code)**

Use GnSasm as a custom tool within your IDE.

#### MPLAB X Integration:
1. **Create a new project** (File → New Project)
2. **Configure custom toolchain:**
   - Tools → Options → Build Tools
   - Create new tool: `gnsasm -a pic16 -o ${OUTPUT_FILE} ${INPUT_FILE}`
3. **Set GnSasm as assembler** in Project Properties

#### VS Code Integration:

Create `.vscode/tasks.json`:
```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Assemble PIC16",
      "type": "shell",
      "command": "gnsasm",
      "args": [
        "${file}",
        "-a", "pic16",
        "-o", "${fileDirname}/${fileBasenameNoExtension}.hex",
        "--verbose"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "problemMatcher": {
        "owner": "gnsasm",
        "fileLocation": ["relative", "${workspaceFolder}"],
        "pattern": {
          "regexp": "^\\[(error|warning)\\]\\s+Line\\s+(\\d+).*$",
          "file": 1,
          "line": 2
        }
      }
    }
  ]
}
```

#### Best For:
- Professional development
- Real-time error feedback
- Integration with IDE debugging tools
- Team projects

### 4. **Simulation and Debugging**

Use GnSasm output with PIC simulators for testing before hardware programming.

#### Simulation Workflow:
```bash
# 1. Assemble program
gnsasm program.asm -a pic16 -o firmware.hex

# 2. Load into MPLAB SIM simulator
#    File → Open → firmware.hex
#    Debug → Run
```

#### Supported Simulators:
- **MPLAB SIM** - Free simulator included with MPLAB X
- **Proteus** - Hardware simulation with PIC models
- **PICsim Plus** - Specialized PIC simulator
- **Custom Simulators** - Any tool supporting Intel HEX format

#### Debugging Tips:
- Use labels to track execution flow
- Set breakpoints at critical sections
- Verify register contents at each step
- Test edge cases before hardware

#### Best For:
- Algorithm validation
- Debugging complex logic
- Testing without hardware
- Education and learning

### 5. **Hardware Programming**

Use GnSasm output with PIC programmers.

#### Compatible Programmers:
- **MPLAB-IPE** (Integrated Programming Environment)
  ```bash
  gnsasm program.asm -o firmware.hex
  # Then use MPLAB-IPE GUI or CLI
  ```

- **pk3cmd** (MPLAB PICkit 3)
  ```bash
  gnsasm program.asm -a pic16 -o firmware.hex
  pk3cmd -P firmware.hex -F
  ```

- **picprogrammer** (Universal programmer support)
  ```bash
  gnsasm program.asm -o firmware.hex
  picprogrammer -d PIC16F18076 -f firmware.hex
  ```

- **Custom/DIY Programmers** - Any tool supporting Intel HEX format

#### Workflow:
```bash
# 1. Assemble program
gnsasm program.asm -a pic16 -o firmware.hex --verbose

# 2. Verify output
hexdump -C firmware.hex | head -20

# 3. Program device
# Using your preferred programmer...
```

#### Best For:
- Final deployment
- Production programming
- Hardware testing
- Device validation

### 6. **Batch Processing and CI/CD**

Automate assembly for multiple files or continuous integration.

#### Batch Assembly Script:
```bash
#!/bin/bash
# batch_assemble.sh

ARCH="${1:-pic16}"
OUTPUT_DIR="build"

mkdir -p "$OUTPUT_DIR"

for asm_file in *.asm; do
    hex_file="$OUTPUT_DIR/${asm_file%.asm}.hex"
    echo "Assembling: $asm_file → $hex_file"

    if gnsasm "$asm_file" -a "$ARCH" -o "$hex_file" --verbose; then
        echo "✓ Success: $asm_file"
    else
        echo "✗ Failed: $asm_file"
        exit 1
    fi
done

echo "All files assembled successfully!"
```

#### GitHub Actions Example:
```yaml
name: PIC Assembly Build

on: [push, pull_request]

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v2

      - name: Install GnSasm
        run: |
          git clone https://github.com/garyPenhook/PIC-Assembler.git
          cd PIC-Assembler
          cmake -B build
          cmake --build build
          sudo cp build/gnsasm /usr/local/bin/

      - name: Assemble programs
        run: |
          for file in *.asm; do
            gnsasm "$file" -a pic16 -o "${file%.asm}.hex" --verbose
          done

      - name: Upload artifacts
        uses: actions/upload-artifact@v2
        with:
          name: hex-files
          path: "*.hex"
```

#### Best For:
- Large projects with multiple files
- Automated testing pipelines
- Version control integration
- Team development

### 7. **Cross-Architecture Development**

Develop and test code for multiple PIC families.

#### Multi-Target Build:
```bash
#!/bin/bash

PROGRAM="firmware.asm"
ARCHITECTURES=("pic12" "pic16" "pic18")

for arch in "${ARCHITECTURES[@]}"; do
    output="${arch}/${PROGRAM%.asm}.hex"
    mkdir -p "$arch"

    echo "Building for $arch..."
    if gnsasm "$PROGRAM" -a "$arch" -o "$output" 2>/dev/null; then
        echo "✓ $arch build successful"
    else
        echo "✗ $arch build failed"
    fi
done
```

#### Best For:
- Portable code
- Product lines spanning multiple architectures
- Testing architecture compatibility

### 8. **Embedded Project Management**

Use GnSasm within larger embedded projects with mixed languages.

#### Example Project Structure:
```
project/
├── Makefile
├── CMakeLists.txt
├── firmware/
│   ├── startup.asm          # GnSasm (startup code)
│   ├── bootloader.asm       # GnSasm (bootloader)
│   ├── drivers/
│   │   ├── uart.c           # C code (optional)
│   │   └── spi.c            # C code (optional)
│   └── main/
│       └── application.asm   # GnSasm (main app)
├── scripts/
│   ├── assemble.sh          # Assembly automation
│   └── program.sh           # Device programming
└── docs/
    └── architecture.md
```

#### Makefile Integration:
```makefile
# Mixed C and Assembly project
ASM_FILES = firmware/startup.asm firmware/bootloader.asm
ASM_OBJS = $(ASM_FILES:.asm=.hex)
C_FILES = firmware/drivers/*.c
C_OBJS = $(C_FILES:.c=.o)

firmware.hex: $(ASM_OBJS) $(C_OBJS)
	# Link everything together
	arm-none-eabi-gcc -o firmware.elf $(C_OBJS) $(ASM_OBJS)
	arm-none-eabi-objcopy -O ihex firmware.elf firmware.hex

%.hex: %.asm
	gnsasm $< -a pic16 -o $@
```

#### Best For:
- Complex embedded systems
- Mixed language projects
- Large teams
- Professional products

## Usage Guide

### Assembly Language Syntax

#### Comments
```asm
; This is a comment
MOVLW 0x00      ; Inline comment
```

#### Labels
```asm
start:          ; Label at beginning of line
    MOVLW 0x00

loop:           ; Another label
    INCF 0x20,1
    GOTO loop
```

#### Directives
```asm
        ORG 0x0000          ; Set program origin
PORTA   EQU 0x05            ; Define constant (cannot change)
counter SET 0               ; Define variable (can reassign)
        RADIX HEX           ; Set default number base to hex
        __CONFIG 0x3F72     ; Set configuration bits
        DB 0x01, 0x02       ; Define bytes
        DW 0x1234           ; Define word
        END                 ; End of program
```

**Define Constants (`EQU`):**

The `EQU` directive assigns a constant value to a symbol, making your code more readable and maintainable.

```asm
; Define register addresses
PORTA       EQU 0x05        ; Port A data register
STATUS      EQU 0x03        ; Status register

; Define bit positions
Z_FLAG      EQU 2           ; Zero flag bit position

; Define constant values
LED_ON      EQU 0xFF
LED_OFF     EQU 0x00

; Symbol references
OUTPUT_PORT EQU PORTA       ; Alias to another symbol

; Use in your code
        MOVLW LED_ON
        MOVWF PORTA         ; Uses the defined constant
        BSF   STATUS, Z_FLAG
```

**Benefits of EQU:**
- Makes code self-documenting (`MOVWF PORTA` vs `MOVWF 0x05`)
- Change hardware mappings in one place
- Prevents typos in numeric addresses
- See `.github/copilot-examples/using-equ-directive.asm` for comprehensive examples

**Define Variables (`SET`):**

The `SET` directive is like `EQU` but allows reassignment (XC8/MPASM compatibility):

```asm
; SET allows reassignment (useful for counters, offsets)
counter SET 0           ; Initialize
counter SET 1           ; Reassign to 1
counter SET 2           ; Reassign to 2

offset SET 0x100
offset SET 0x200        ; Can change value

; EQU does NOT allow reassignment
CONST EQU 0x10          ; Locked value
; CONST EQU 0x20        ; ERROR: cannot reassign EQU
```

**Key Differences:**
- `EQU` = Constant (cannot change) - like `#define` in C
- `SET` = Variable (can reassign) - useful for computed values

**Change Default Number Base (`RADIX`):**

The `RADIX` directive changes how bare numbers (without prefixes) are interpreted:

```asm
; Default is RADIX DEC (decimal)
        MOVLW 255       ; Decimal 255

; Switch to hexadecimal
        RADIX HEX
        MOVLW FF        ; Now interpreted as hex FF (255 decimal)
        MOVLW AB        ; Hex AB (171 decimal)

; Switch to octal
        RADIX OCT
        MOVLW 377       ; Octal 377 (255 decimal)

; Switch to binary
        RADIX BIN
        MOVLW 11111111  ; Binary (255 decimal)

; Prefixed numbers always work regardless of RADIX
        RADIX HEX
        MOVLW 0xFF      ; Explicit prefix still works
        MOVLW 255       ; Bare number in HEX = 0x255 (597 decimal)
```

**Supported RADIX values:**
- `DEC` or `DECIMAL` - Base 10 (default)
- `HEX` or `HEXADECIMAL` - Base 16
- `OCT` or `OCTAL` - Base 8
- `BIN` or `BINARY` - Base 2

**Configuration Bits (`__CONFIG` / `CONFIG`):**

The `__CONFIG` directive sets the PIC microcontroller's configuration fuses. These control critical settings like oscillator type, watchdog timer, brown-out reset, and more.

```asm
; Direct hex value
__CONFIG 0x3F72

; Using symbolic names (define with EQU first)
_FOSC_INTRC    EQU 0x3FFC   ; Internal RC oscillator
_WDTE_OFF      EQU 0x3FFB   ; Watchdog Timer disabled
_PWRTE_ON      EQU 0x3FF7   ; Power-up Timer enabled
_MCLRE_OFF     EQU 0x3FDF   ; MCLR pin is digital I/O

__CONFIG _FOSC_INTRC & _WDTE_OFF & _PWRTE_ON & _MCLRE_OFF
```

**Configuration Word Addresses:**
- **PIC12/PIC16:** CONFIG stored at address `0x2007` (14-bit word)
- **PIC18:** CONFIG starts at address `0x300000` (8-bit bytes, multiple CONFIG registers)

**Important Notes:**
- Configuration bits are **NOT** optional - every real PIC program needs them
- Without CONFIG, the device may not start correctly (wrong oscillator, watchdog resets, etc.)
- Consult your device datasheet for specific CONFIG bit definitions
- See `.github/copilot-examples/pic16-config-bits.asm` for common PIC16 CONFIG definitions
- See `.github/copilot-examples/pic18-config-bits.asm` for common PIC18 CONFIG definitions

#### Number Formats

**Decimal:**
```asm
MOVLW 255       ; Decimal number
COUNT EQU 100   ; Decimal constant
```

**Hexadecimal (3 styles):**
```asm
MOVLW 0xFF      ; 0x prefix (C-style)
MOVLW FFh       ; h suffix (MPASM-style)
MOVLW H'FF'     ; H'...' quoted (MPASM-style)
```

**Octal (3 styles):**
```asm
MOVLW 0o377     ; 0o prefix (modern style)
MOVLW 377o      ; o suffix (MPASM-style)
MOVLW O'377'    ; O'...' quoted (MPASM-style)
```

**Binary (3 styles):**
```asm
MOVLW 0b11110000    ; 0b prefix (C-style)
MOVLW 11111111b     ; b suffix (MPASM-style)
MOVLW B'11111111'   ; B'...' quoted (MPASM-style)
```

**All formats that equal 255:**
```asm
        ; Decimal
        MOVLW 255           ; Plain decimal
        MOVLW D'255'        ; D'...' quoted (MPASM)

        ; Hexadecimal
        MOVLW 0xFF          ; 0x prefix
        MOVLW FFh           ; h suffix
        MOVLW H'FF'         ; H'...' quoted

        ; Octal
        MOVLW 0o377         ; 0o prefix
        MOVLW 377o          ; o suffix
        MOVLW O'377'        ; O'...' quoted

        ; Binary
        MOVLW 0b11111111    ; 0b prefix
        MOVLW 11111111b     ; b suffix
        MOVLW B'11111111'   ; B'...' quoted
```

### PIC®16 Example Program

```asm
; PIC®16F18076 - Simple Counter
; Increments register 0x20 and compares with 10

        ORG 0x0000

start:  MOVLW 0x00      ; Initialize W
        MOVWF 0x20      ; Store in file register 0x20

loop:   INCF 0x20,1     ; Increment register
        MOVF 0x20,0     ; Move to W
        SUBLW 0x0A      ; Subtract 10 from W
        BTFSS 0x03,2    ; Skip if zero flag set
        GOTO loop       ; Jump back to loop

        GOTO loop       ; Infinite loop
        END
```

Assemble with:
```bash
gnsasm counter.asm -o counter.hex
```

### PIC®18 Example Program

```asm
; PIC®18-Q40 - Advanced Counter with Conditional Branch
; Uses PIC18-specific BRA and CPFSEQ instructions

        ORG 0x0000

start:  MOVLW 0x55      ; Load pattern 0x55
        MOVWF 0x20      ; Store in register

        ; Test PIC18-specific instructions
        ADDWFC 0x20,1   ; Add with Carry (PIC18)
        SETF 0x21       ; Set all bits (PIC18)

loop:   MOVLW 0x00
        CPFSEQ 0x20     ; Compare, skip if equal (PIC18)
        BRA loop        ; Unconditional branch (PIC18)

        NOP
        END
```

Assemble with:
```bash
gnsasm counter18.asm -a pic18 -o counter18.hex
```

### Working with Different Architectures

#### Detecting Architecture Errors
```bash
$ gnsasm pic18_code.asm  # Using PIC18 code with PIC16 target
Error: Parsing failed with 1 error(s)
========================================
[error] Line 4, Column 1
  Instruction 'BRA' is not available in PIC16 architecture
  Hint: This instruction is specific to PIC18. Use '-a PIC18' to assemble for that architecture.
```

#### Fixing Architecture Issues
```bash
# Switch to correct architecture
gnsasm pic18_code.asm -a pic18 -o output.hex
```

## Supported Instructions

### PIC®16 Instructions (35 total - 100% coverage)

#### Byte-Oriented Operations (18)
```
ADDWF   - Add W to file register
ANDWF   - AND W with file register
CLRF    - Clear file register
CLRW    - Clear W register
COMF    - Complement file register
DECF    - Decrement file register
DECFSZ  - Decrement file register, skip if zero
INCF    - Increment file register
INCFSZ  - Increment file register, skip if zero
IORWF   - Inclusive OR W with file register
MOVF    - Move file register to W
MOVWF   - Move W to file register
NOP     - No operation
RLF     - Rotate left file register through carry
RRF     - Rotate right file register through carry
SUBWF   - Subtract W from file register
SWAPF   - Swap nibbles in file register
XORWF   - Exclusive OR W with file register
```

#### Bit-Oriented Operations (4)
```
BCF     - Clear bit in file register
BSF     - Set bit in file register
BTFSC   - Bit test skip if clear
BTFSS   - Bit test skip if set
```

#### Literal and Control Operations (13)
```
ADDLW   - Add literal to W
ANDLW   - AND literal with W
CALL    - Call subroutine
CLRWDT  - Clear watchdog timer
GOTO    - Jump to address
IORLW   - Inclusive OR literal with W
MOVLW   - Move literal to W
RETFIE  - Return from interrupt
RETLW   - Return with literal in W
RETURN  - Return from subroutine
SLEEP   - Enter sleep mode
SUBLW   - Subtract W from literal
XORLW   - Exclusive OR literal with W
```

### PIC®18 Instructions (54+ total - 100% coverage)

#### Shared Instructions (35)
All PIC16 instructions listed above, plus:

#### Additional Byte-Oriented Operations (11)
```
ADDWFC  - Add W to file register with carry
DCFSNZ  - Decrement file register, skip if not zero
INFSNZ  - Increment file register, skip if not zero
MOVFF   - Move file register to file register
MULWF   - Multiply W with file register
NEGF    - Negate file register
RLCF    - Rotate left file register through carry
RLNCF   - Rotate left file register, no carry
RRCF    - Rotate right file register through carry
RRNCF   - Rotate right file register, no carry
TSTFSZ  - Test file register, skip if zero
SUBFWB  - Subtract W from file register with borrow
SUBWFB  - Subtract file register from W with borrow
```

#### Additional Bit-Oriented Operations (1)
```
BTG     - Bit toggle
```

#### Compare and Skip Operations (3)
```
CPFSEQ  - Compare file register with W, skip if equal
CPFSGT  - Compare file register with W, skip if greater
CPFSLT  - Compare file register with W, skip if less
```

#### Conditional Branch Operations (9)
```
BC      - Branch if carry
BN      - Branch if negative
BNC     - Branch if not carry
BNN     - Branch if not negative
BNOV    - Branch if not overflow
BNZ     - Branch if not zero
BOV     - Branch if overflow
BRA     - Unconditional branch
BZ      - Branch if zero
```

#### Stack and Control Operations (6)
```
CALLW   - Call using W register
DAW     - Decimal adjust W
POP     - Pop stack
PUSH    - Push top of stack
RCALL   - Relative call
RESET   - Reset processor
```

#### File Select Register Operations (5)
```
ADDFSR  - Add to file select register
LFSR    - Load file select register
MOVLB   - Move literal to BSR (bank select register)
MULLW   - Multiply literal with W
SUBFSR  - Subtract from file select register
```

#### Table Operations (2)
```
TBLRD   - Table read
TBLWT   - Table write
```

## Error Messages and Diagnostics

### Understanding Error Messages

The assembler provides helpful error messages to guide you:

#### Example 1: Instruction Typo
```
[error] Line 2, Column 1
  Unknown instruction 'MOVWX'
  Hint: Possible corrections:
  - MOVF - Move file register to W
  - MOVWF - Move W to file register
  - MOVLW - Move literal to W
```

**Solution:** Use one of the suggested instructions.

#### Example 2: Architecture Mismatch
```
[error] Line 3, Column 1
  Instruction 'BTG' is not available in PIC16 architecture
  Hint: This instruction is specific to PIC18. Use '-a PIC18' to assemble for that architecture.
```

**Solution:** Either switch to PIC18 architecture or use PIC16-compatible instruction.

#### Example 3: Invalid Operand
```
[error] Line 5, Column 1
  Invalid operand 'f=256'
  Hint: Expected: 0-255
  Got: 256
```

**Solution:** Ensure file register is in valid range (0-255).

## Output Format

The assembler generates Intel HEX format files (.hex) compatible with standard PIC programmers:

```
:0E0006000030A000A00A20080A3C031D0028BC
:00000001FF
```

### Output Details
- **Line format:** Intel HEX standard
- **Checksums:** Included for data integrity
- **Address format:** 16-bit addresses
- **Data encoding:** Hexadecimal

## Advanced Usage

### Listing File Generation

Generate detailed assembly listings with source-to-code cross-reference:

```bash
# Generate listing file (input.asm → input.lst)
gnsasm program.asm --listing

# With all options
gnsasm program.asm -a pic18 --listing --verbose
```

**Listing file contents:**
- Assembly listing with source code and generated machine code (hex)
- Addresses of each instruction
- Symbol table with label addresses
- Memory usage statistics (program, data, EEPROM)
- Assembly statistics (instruction count, address ranges)
- Assembly status (SUCCESS/FAILED)

**Example listing file output:**
```
================================================================================
GNSASM PIC Assembler Listing File
================================================================================

Device: PIC16F1847
Architecture: PIC16 (14-bit instructions)

================================================================================
ASSEMBLY LISTING
================================================================================
  Addr  |  Hex Code  | Source Code
--------+----------+------------------------------------------------------------
  0x0000  | 0x30ff   |     MOVLW 0xFF
  0x0002  | 0x00a0   |     MOVWF 0x20
  0x0004  | 0x1c03   |     INCF 0x20

... [memory usage and statistics] ...

================================================================================
ASSEMBLY STATISTICS
================================================================================
Total Instructions: 3
Address Range:      0x0000 - 0x0004
Total Data Items:   0
Config Words:       0

Assembly Status: SUCCESS
```

### Verbose Output
```bash
gnsasm program.asm --verbose

# Output includes:
# - File being read
# - Target architecture
# - Assembly status
# - Code statistics
# - Error/warning counts
```

### Custom Output Directory
```bash
gnsasm src/program.asm -o output/program.hex
```

### Batch Assembly
```bash
#!/bin/bash
for file in *.asm; do
    gnsasm "$file" -o "${file%.asm}.hex"
    echo "Assembled: $file"
done
```

### Using with Make

Example Makefile:
```makefile
ASSEMBLER = gnsasm
ARCH = pic16

.PHONY: all clean

all: firmware.hex

%.hex: %.asm
	$(ASSEMBLER) $< -a $(ARCH) -o $@

clean:
	rm -f *.hex
```

## Troubleshooting

### Build Issues

**Problem:** CMake not found
```bash
# Solution: Install CMake
sudo apt-get install cmake          # Ubuntu/Debian
brew install cmake                   # macOS
choco install cmake                  # Windows (with Chocolatey)
```

**Problem:** C++ compiler not found
```bash
# Solution: Install compiler
sudo apt-get install build-essential # Ubuntu/Debian
brew install gcc                     # macOS
# Windows: Use Visual Studio installer
```

**Problem:** C++23 not supported
```bash
# Solution: Update compiler
# GCC: Update to version 11 or later
# Clang: Update to version 13 or later
```

### Assembly Issues

**Problem:** File not found
```bash
# Verify file path and current directory
ls -la program.asm
pwd
```

**Problem:** Unknown instruction errors
```bash
# Check for typos
# Verify architecture selection matches your device
gnsasm program.asm -a pic18
```

**Problem:** Invalid operand range
```bash
# File registers: 0-255
# Bit positions: 0-7
# Verify all operands are in valid ranges
```

## Performance Tips

1. **Release Build:** Always use Release mode for production
   ```bash
   cmake -DCMAKE_BUILD_TYPE=Release ..
   ```

2. **Parallel Build:** Use multiple cores
   ```bash
   cmake --build . -j$(nproc)
   ```

3. **Large Projects:** Assembly is fast; performance rarely an issue

## File Structure

```
PIC-Assembler/
├── README.md                 # This file
├── docs/                    # Documentation files
│   ├── ARCHITECTURE.md      # Technical architecture
│   ├── TUTORIAL.md          # Beginner's guide
│   ├── PROGRAMMING.md       # Programming guide
│   └── *.md                 # Other documentation
├── CMakeLists.txt           # Build configuration
├── main.cpp                 # Entry point
├── src/                     # Source code
│   ├── lexer.*             # Tokenizer
│   ├── parser.*            # Parser
│   ├── instruction.*       # Instruction definitions
│   ├── assembler.*         # Main assembler logic
│   ├── hex_generator.*     # HEX output
│   ├── symbol_table.*      # Symbol management
│   ├── error_reporter.*    # Error reporting
│   └── cli.*               # Command-line interface
└── *.asm                   # Example/test programs
```

## Development

### Building with Different Compilers

**GCC:**
```bash
cmake -DCMAKE_CXX_COMPILER=g++ ..
cmake --build .
```

**Clang:**
```bash
cmake -DCMAKE_CXX_COMPILER=clang++ ..
cmake --build .
```

**MSVC (Windows):**
```bash
cmake -G "Visual Studio 16 2019" ..
cmake --build . --config Release
```

### Debugging

Enable debug build for debugging:
```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
gdb ./gnsasm
```

## Recently Completed Features

Recent releases have added:
- ✅ **Symbolic device register names** - Load and use register names from device include files
- ✅ **Listing file generation** - Generate `.lst` files with assembly listing, symbol table, and statistics
- ✅ **Macro support** - Full macro system with parameters, LOCAL labels, and EXITM
- ✅ **Conditional assembly** - #ifdef, #ifndef, #endif, #if/#elif/#else directives
- ✅ **Banking/Paging directives** - BANKSEL, PAGESEL, BANKISEL for automatic register management
- ✅ **Preprocessor directives** - Complete #define, #include, #undef support with function-like macros
- ✅ **Assembly-time conditionals** - IF/IFDEF/IFNDEF/ELIF/ELSE/ENDIF with expression evaluation

## Future Enhancements

Planned features for future releases:
- [ ] Symbol export for debugging (ELF format)
- [ ] Extended instruction sets (PIC24, dsPIC)
- [ ] C preprocessor integration
- [ ] IDE integration plugins (Visual Studio Code, CLion)
- [ ] Advanced data directives (align, fill, reserve)
- [ ] Section support (.text, .data, .bss with linking)
- [ ] Linker script support for memory layout control
- [ ] Multi-file project support (GLOBAL/EXTERN directives)

## Legal Disclaimer

GnSasm is an independent project and is not affiliated with, endorsed by, or connected to Microchip Technology Inc.

**Trademark Acknowledgments:**
- PIC®, PIC®16, PIC®16F, PIC®18, PIC®18-Q40, MPASM®, and Microchip® are registered trademarks of Microchip Technology Inc.
- This project provides an alternative implementation of PIC microcontroller assembly language tooling.
- All references to PIC®, MPASM®, and Microchip® products in this documentation are for identification purposes only.
- The use of these trademarks is for compatibility and informational purposes, and does not imply endorsement.

**Compliance Note:**
This assembler implements assembly language syntax and instruction sets that are compatible with Microchip® PIC® microcontrollers. Use of this tool is subject to the terms of the MIT License included in this repository.

## License

GnSasm is provided under the **MIT License** - See LICENSE file for details.

### Third-Party Components

**Device Include Files (`.inc` files)**

Device include files are provided by **Microchip Technology** and are subject to Microchip's licensing terms. These files are:
- Copyrighted by Microchip Technology Incorporated
- Available for download from [Microchip Device Family Packs](https://packs.download.microchip.com/)
- **Not included in this repository** to comply with licensing requirements
- Users should obtain them directly from Microchip's official sources

The assembler works perfectly without device include files by using numeric register addresses. Device files are strictly optional and provided only for users who want MPASM-compatible symbolic register names.

## Contributing

Contributions are welcome! Please:
1. Fork the repository
2. Create a feature branch
3. Submit a pull request with description

## Support

For issues, questions, or suggestions:
- Create an issue on GitHub
- Check existing documentation in [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md)
- Review example assembly files

## Documentation

📚 **Complete Documentation Available:**

- **[TUTORIAL.md](docs/TUTORIAL.md)** - Complete beginner's guide to PIC assembly programming
  - Your first program (LED blink)
  - Understanding the code line-by-line
  - Assembling and programming workflow
  - Common patterns and examples
  - Troubleshooting guide

- **[PROGRAMMING.md](docs/PROGRAMMING.md)** - Programming PICs with ipecmd
  - Using Microchip's command-line programmer
  - Installation and setup
  - Makefile integration
  - Complete workflow examples
  - Advanced features and troubleshooting
  - **ipecmd is the PIC equivalent of avrdude**

- **[ARCHITECTURE.md](docs/ARCHITECTURE.md)** - Technical internals
  - How the assembler works
  - Two-pass assembly process
  - Instruction encoding details
  - Intel HEX format generation

- **[.github/copilot-examples/](.github/copilot-examples/)** - Device-specific register definitions
  - Register addresses for popular PICs
  - Complete working examples
  - GitHub Copilot training files

## Version History

**v1.2+ (Current - In Development)**
- ✅ **Symbolic device register names** - Support for Microchip device include files
  - 1,748 bundled device files covering 2,903 devices
  - Case-insensitive register name resolution
  - Redefinition protection for device registers
  - Priority handling in symbol lookup
- ✅ **Listing file generation** - Generate `.lst` files with detailed assembly information
  - Assembly listing with source-to-machine-code cross-reference
  - Symbol table display
  - Memory usage statistics
  - Assembly statistics and summary
- ✅ Fixed DB/DW data directive output in HEX files
  - Resolved data duplication in two-pass assembly
  - Fixed address calculation for merged HEX records
  - Verified program counter advancement for mixed data types
- ✅ Added PIC12 baseline instruction set support (12-bit encoding)
- ✅ Implemented two-pass assembly for forward label references
- Support for 8 different development workflows (CLI, Make, IDE, Simulation, etc.)
- Comprehensive documentation for PIC programming options

**v1.2**
- Renamed executable to `gnsasm`
- Complete PIC18 instruction set implementation (54+ instructions)
- All instructions fully encoded and tested
- Intel HEX output generation with proper checksums
- Memory usage statistics display

**v1.1**
- Added PIC®18-Q40 support
- Comprehensive error reporting system
- Architecture validation
- MPASM®-compatible directives (ORG, EQU, END)

**v1.0**
- Initial release
- PIC®16F18076 support
- MPASM®-compatible syntax
- 35 PIC16 instructions fully supported

## Credits

Developed as a modern replacement for MPASM® with enhanced error messages and multi-architecture support.

---

**Website:** https://github.com/garyPenhook/PIC-Assembler
**Command:** `gnsasm`
**Maintainer:** Gary Penhook
**Last Updated:** November 28, 2025
**Latest Features:** Symbolic device register names (1,748 device files), Listing file generation

---

*PIC®, PIC®16, PIC®18, MPASM®, and Microchip® are registered trademarks of Microchip Technology Inc.*
*This project is not affiliated with or endorsed by Microchip Technology Inc.*
