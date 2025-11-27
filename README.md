# GnSasm - PIC16/PIC18 Assembler

A modern, standards-compliant assembler for Microchip PIC microcontrollers with MPASM-compatible syntax. Supports both PIC16 (14-bit) and PIC18 (16-bit) instruction sets with helpful error messages and architecture validation.

**Latest Version:** 1.2
**Command:** `gnsasm`
**Target Devices:** PIC16F18076, PIC18-Q40, and compatible microcontrollers

## Features

✨ **Dual-Architecture Support**
- PIC16 and PIC16F microcontrollers (14-bit instruction words)
- PIC18 and PIC18-Q40 microcontrollers (16-bit instruction words)
- Architecture-aware instruction validation and encoding

🎯 **Complete Instruction Set Coverage**
- **PIC16:** 35 instructions (100% coverage)
  - Byte-oriented, bit-oriented, literal/control operations
- **PIC18:** 54+ instructions (100% coverage)
  - All byte-oriented, bit-oriented, conditional branches
  - Compare/skip, table operations, FSR operations
  - Stack operations, multiplication, and more

🔍 **Intelligent Error Reporting**
- Helpful error messages with line/column information
- Suggestions for common typos and mistakes
- Architecture validation with guidance
- Operand range checking
- Color-coded output for better readability

📝 **MPASM Compatible**
- MPASM-like syntax and directives (ORG, END, EQU)
- Support for decimal, hexadecimal (0xFF), and binary (0b1010) number formats
- Label support with colon notation
- Semicolon comments

⚡ **Performance**
- Compiled with C++23 standard
- -O3 optimization for fast assembly
- Single-pass assembly

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
  -l, --listing        Generate listing file (planned)
  --verbose            Show detailed assembly information
  -h, --help          Display help message
  -v, --version       Display version information

Examples:
  gnsasm program.asm
  gnsasm program.asm -a pic18
  gnsasm program.asm -o firmware.hex
  gnsasm program.asm -a pic18 -o firmware.hex --verbose
```

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
ORG 0x0000      ; Set program origin
EQU CONST=0x20  ; Define constant
END             ; End of program
```

#### Number Formats
```asm
MOVLW 255       ; Decimal
MOVLW 0xFF      ; Hexadecimal (C-style)
MOVLW 0xAB      ; Hex with uppercase
MOVLW 0b11110000; Binary
```

### PIC16 Example Program

```asm
; PIC16F18076 - Simple Counter
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

### PIC18 Example Program

```asm
; PIC18-Q40 - Advanced Counter with Conditional Branch
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

### PIC16 Instructions (35 total - 100% coverage)

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

### PIC18 Instructions (54+ total - 100% coverage)

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
├── ARCHITECTURE.md           # Technical architecture documentation
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

## Future Enhancements

Planned features for future releases:
- [ ] Macro support
- [ ] Conditional assembly (#ifdef, #endif)
- [ ] Listing file generation (.lst)
- [ ] Symbol export for debugging
- [ ] Extended instruction sets (PIC24, dsPIC)
- [ ] C preprocessor integration
- [ ] Multi-pass assembly for forward references
- [ ] IDE integration plugins

## License

MIT License - See LICENSE file for details

## Contributing

Contributions are welcome! Please:
1. Fork the repository
2. Create a feature branch
3. Submit a pull request with description

## Support

For issues, questions, or suggestions:
- Create an issue on GitHub
- Check existing documentation in ARCHITECTURE.md
- Review example assembly files

## Version History

**v1.2 (Current)**
- Renamed executable to `gnsasm`
- Complete PIC18 instruction set implementation (54+ instructions)
- All instructions fully encoded and tested

**v1.1**
- Added PIC18-Q40 support
- Comprehensive error reporting system
- Architecture validation

**v1.0**
- Initial release
- PIC16F18076 support
- MPASM-compatible syntax

## Credits

Developed as a modern replacement for MPASM with enhanced error messages and multi-architecture support.

---

**Website:** https://github.com/garyPenhook/PIC-Assembler
**Command:** `gnsasm`
**Maintainer:** Gary Penhook
**Last Updated:** November 2025
