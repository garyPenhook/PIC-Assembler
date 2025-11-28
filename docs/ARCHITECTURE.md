# PIC16/PIC18 Assembler Architecture

## Overview
A modern assembler for Microchip PIC16 and PIC18 microcontrollers with MPASM-compatible syntax. Supports both PIC16F18076 and PIC18-Q40 families with selectable architecture target.

## Architecture Components

### 1. **Lexer (Tokenizer)**
- **Input**: Raw assembly source code
- **Output**: Stream of tokens
- **Responsibilities**:
  - Parse source text character by character
  - Recognize tokens: mnemonics, labels, directives, operands, numbers, strings
  - Handle comments (`;` to end of line)
  - Skip whitespace and tabs
  - Track line numbers for error reporting
- **Token Types**: MNEMONIC, LABEL, DIRECTIVE, NUMBER, IDENTIFIER, STRING, COMMA, COLON, EOL, EOF

### 2. **Parser**
- **Input**: Token stream from Lexer
- **Output**: Abstract Syntax Tree (AST) or parsed instructions
- **Responsibilities**:
  - Validate instruction syntax
  - Extract operands (file register, destination, bit position, literal value, address)
  - Match mnemonics to instruction formats
  - Handle directives (ORG, END, EQU, etc.)
  - Validate operand ranges and types
  - Build symbol table for labels
- **Error Handling**: Report line number and error description

### 3. **Instruction Encoder**
- **Input**: Parsed instruction with operands
- **Output**: 14-bit instruction word (PIC16) or 16-bit instruction word (PIC18)
- **Responsibilities**:
  - Architecture-aware encoding (selectable via CLI)
  - Map mnemonics to opcodes
  - Encode operands into instruction format
  - Handle addressing modes
  - Generate correct opcode bits for each instruction category:
    - Byte-Oriented Operations (ADDWF, MOVF, ADDWFC, SETF, etc.)
    - Bit-Oriented Operations (BSF, BCF, BTFSS, BTFSC, BTG, etc.)
    - Literal and Control Operations (MOVLW, GOTO, CALL, BRA, BZ, etc.)
    - PIC18-specific: Compare/Skip, Conditional Branches, Table operations

### 4. **Symbol Table & Code Generation**
- **Symbol Table**: Maps labels and constants to memory addresses
- **Code Generation**:
  - Track current program counter
  - Generate machine code for each instruction
  - Store compiled instructions with their addresses
  - Handle memory layout (program memory regions)

### 5. **Output Formatter (Hex Generator)**
- **Input**: Generated machine code
- **Output**: Intel HEX format (.hex file)
- **Responsibilities**:
  - Convert binary instructions to HEX format
  - Generate valid HEX file with checksums
  - Support various output formats

### 6. **CLI Interface**
- **Input**: Command-line arguments
- **Responsibilities**:
  - Accept source file path
  - Accept output file path
  - Select target architecture (PIC16 or PIC18)
  - Support options: verbose, debug output, listing file
- **Usage**: `pic-assembler [options] input.asm`
- **Architecture Selection**: `-a pic16` (default) or `-a pic18`

## Instruction Set Support

### PIC16 Instructions (35 total)

**Byte-Oriented (18 instructions)**
ADDWF, ANDWF, CLRF, CLRW, COMF, DECF, DECFSZ, INCF, INCFSZ, IORWF, MOVF, MOVWF, NOP, RLF, RRF, SUBWF, SWAPF, XORWF

**Bit-Oriented (4 instructions)**
BCF, BSF, BTFSC, BTFSS

**Literal and Control (13 instructions)**
ADDLW, ANDLW, CALL, CLRWDT, GOTO, IORLW, MOVLW, RETFIE, RETLW, RETURN, SLEEP, SUBLW, XORLW

### PIC18 Instructions (54+ total)

**Shared with PIC16** (35 instructions as above)

**Additional Byte-Oriented (14 new)**
ADDWFC, DCFSNZ, INFSNZ, MOVFF, MULWF, NEGF, RLCF, RLNCF, RRCF, RRNCF, SETF, SUBFWB, SUBWFB, TSTFSZ

**Additional Bit-Oriented (1 new)**
BTG

**Compare and Skip (3 new)**
CPFSEQ, CPFSGT, CPFSLT

**Conditional Branch (9 new)**
BC, BN, BNC, BNN, BNOV, BNZ, BOV, BRA, BZ

**Additional Control (2 new)**
CALLW, RCALL

**Inherent Operations (4 new)**
DAW, POP, PUSH, RESET

**Literal Operations (5 new)**
ADDFSR, LFSR, MOVLB, MULLW, SUBFSR

**Table Operations (2 new)**
TBLRD, TBLWT

## Opcode Encoding Format

### PIC16 (14-bit Instruction Format)
```
Byte-Oriented:   1 1 0 1 0 0 d f f f f f f f   (ADDWF example)
Bit-Oriented:    1 0 1 1 b b b f f f f f f f
Literal/Control: x x x x x x x x k k k k k k
```

### PIC18 (16-bit Instruction Format)
```
Byte-Oriented:   x x x x x x x x d f f f f f f f
Bit-Oriented:    x x x x x x x x b f f f f f f f
Branch/Control:  x x x x k k k k k k k k k k k k
Literal:         x x x x x x x x k k k k k k k k
```

## Data Flow
```
Source Code → Lexer → Tokens → Parser → AST → Encoder → Machine Code → Hex Generator → .hex File
                                           ↓
                                      Symbol Table
```

## File Structure
```
src/
  ├── lexer.h / lexer.cpp         # Tokenizer
  ├── parser.h / parser.cpp       # Parser & AST
  ├── instruction.h / instruction.cpp  # Instruction definitions & encoding
  ├── assembler.h / assembler.cpp # Main assembler logic
  ├── hex_generator.h / hex_generator.cpp  # HEX output
  ├── symbol_table.h / symbol_table.cpp  # Symbol management
  └── cli.h / cli.cpp             # Command-line interface
main.cpp                          # Entry point
```

## MPASM Compatibility
- Support MPASM-like directives: ORG, END, EQU, INCLUDE
- Maintain MPASM syntax for mnemonics and operands
- Support MPASM comment style (`;`)
- Support label syntax (labels followed by `:` or at line start)
- MPASM number format support (decimal, 0xHH hex, 0bBBBB binary)

## Supported Families
- **PIC16**: PIC16F, PIC16F18076, and compatible devices
- **PIC18**: PIC18-Q40 and compatible devices

## Future Enhancements
- Macro support
- Conditional assembly (#ifdef, #endif)
- Listing file generation (.lst)
- Symbol export for debugging
- Extended instruction set support (PIC24, dsPIC)
- C preprocessor integration
- Multi-pass assembly for forward references
