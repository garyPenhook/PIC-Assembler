# PIC16/PIC18 Assembler

A modern, standards-compliant assembler for Microchip PIC microcontrollers with MPASM-compatible syntax. Supports both PIC16 (14-bit) and PIC18 (16-bit) instruction sets with helpful error messages and architecture validation.

**Latest Version:** 1.1
**Target Devices:** PIC16F18076, PIC18-Q40, and compatible microcontrollers

## Features

✨ **Dual-Architecture Support**
- PIC16 and PIC16F microcontrollers (14-bit instruction words)
- PIC18 and PIC18-Q40 microcontrollers (16-bit instruction words)
- Architecture-aware instruction validation and encoding

🎯 **Comprehensive Instruction Sets**
- PIC16: 35 instructions (byte-oriented, bit-oriented, literal/control)
- PIC18: 54+ instructions (includes conditional branches, compare/skip, table operations)

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
./pic-assembler --version
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
cmake -DCMAKE_INSTALL_PREFIX=/opt/pic-asm ..

# Specify build system
cmake -G "Unix Makefiles" ..                # Make (default)
cmake -G "Ninja" ..                         # Ninja
cmake -G "Visual Studio 16 2019" ..         # Visual Studio
```

## Quick Start

### Basic Usage
```bash
# Assemble for PIC16 (default)
pic-assembler program.asm

# Assemble for PIC18
pic-assembler program.asm -a pic18

# Specify output file
pic-assembler program.asm -o output.hex

# Verbose mode
pic-assembler program.asm --verbose
```

### Command-Line Options
```bash
pic-assembler [options] input.asm

Options:
  -a, --arch ARCH      Target architecture: pic16 or pic18 (default: pic16)
  -o, --output FILE    Output file (default: input.hex)
  -l, --listing        Generate listing file (planned)
  --verbose            Show detailed assembly information
  -h, --help          Display help message
  -v, --version       Display version information

Examples:
  pic-assembler program.asm
  pic-assembler program.asm -a pic18
  pic-assembler program.asm -o firmware.hex
  pic-assembler program.asm -a pic18 -o firmware.hex --verbose
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
pic-assembler counter.asm -o counter.hex
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
pic-assembler counter18.asm -a pic18 -o counter18.hex
```

### Working with Different Architectures

#### Detecting Architecture Errors
```bash
$ pic-assembler pic18_code.asm  # Using PIC18 code with PIC16 target
Error: Parsing failed with 1 error(s)
========================================
[error] Line 4, Column 1
  Instruction 'BRA' is not available in PIC16 architecture
  Hint: This instruction is specific to PIC18. Use '-a PIC18' to assemble for that architecture.
```

#### Fixing Architecture Issues
```bash
# Switch to correct architecture
pic-assembler pic18_code.asm -a pic18 -o output.hex
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

## Supported Instructions

### PIC16 Instructions (35 total)

**Byte-Oriented (18)**
ADDWF, ANDWF, CLRF, CLRW, COMF, DECF, DECFSZ, INCF, INCFSZ, IORWF, MOVF, MOVWF, NOP, RLF, RRF, SUBWF, SWAPF, XORWF

**Bit-Oriented (4)**
BCF, BSF, BTFSC, BTFSS

**Literal/Control (13)**
ADDLW, ANDLW, CALL, CLRWDT, GOTO, IORLW, MOVLW, RETFIE, RETLW, RETURN, SLEEP, SUBLW, XORLW

### PIC18 Instructions (54+ total)

**Includes all PIC16 instructions plus:**
- Conditional branches: BRA, BZ, BC, BN, BNC, BNN, BNOV, BNZ, BOV
- Compare/Skip: CPFSEQ, CPFSGT, CPFSLT
- Enhanced byte operations: ADDWFC, SETF, NEGF, RLCF, RLNCF, etc.
- Stack operations: PUSH, POP
- Table operations: TBLRD, TBLWT
- And more...

See `ARCHITECTURE.md` for complete instruction details.

## Advanced Usage

### Verbose Output
```bash
pic-assembler program.asm --verbose

# Output includes:
# - File being read
# - Target architecture
# - Assembly status
# - Code statistics
# - Error/warning counts
```

### Custom Output Directory
```bash
pic-assembler src/program.asm -o output/program.hex
```

### Batch Assembly
```bash
#!/bin/bash
for file in *.asm; do
    pic-assembler "$file" -o "${file%.asm}.hex"
    echo "Assembled: $file"
done
```

### Using with Make

Example Makefile:
```makefile
ASSEMBLER = pic-assembler
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
pic-assembler program.asm -a pic18
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
gdb ./pic-assembler
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

**v1.1 (Current)**
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
**Maintainer:** Gary Penhook
**Last Updated:** November 2025
