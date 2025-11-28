# Comprehensive Error Analysis for PIC Assembler

## Overview
This document outlines all potential error categories and failure modes that should be tested in the GnSasm assembler. After discovering critical encoding bugs, we need systematic validation across all components.

---

## 1. INSTRUCTION ENCODING ERRORS (Critical - Already Found Some)

### 1.1 Bit Position Errors
- [ ] Byte-oriented operand bit widths (d-bit position)
- [ ] Bit-oriented operand bit widths (b-bit, must be bits 11-9)
- [ ] Literal operand widths (k-bit field sizing)
- [ ] Sign bit handling for signed operands
- [ ] Bit ordering (little-endian vs big-endian in instruction word)

### 1.2 Operand Range Validation
- [ ] File register bounds (0-255 for PIC16/18, 0-127 for PIC12)
- [ ] Bit position bounds (0-7)
- [ ] Literal value bounds (varies by instruction: 8-bit, 11-bit, 12-bit)
- [ ] Jump address bounds (11-bit for PIC16 CALL/GOTO)
- [ ] Operand overflow handling
- [ ] Negative number handling in literals

### 1.3 Architecture-Specific Encoding
- [ ] PIC12 (12-bit instruction word) encoding correctness
- [ ] PIC16 (14-bit instruction word) encoding correctness
- [ ] PIC18 (16-bit instruction word) encoding correctness
- [ ] Format differences between architectures
- [ ] Opcode value verification for each architecture

### 1.4 Instruction-Specific Issues
- [ ] CALL instruction address field width (11-bit vs 12-bit)
- [ ] GOTO instruction addressing
- [ ] MOVFF special 2-word format (PIC18)
- [ ] TBLRD/TBLWT mode bits
- [ ] Conditional branch distances (signed vs unsigned)
- [ ] FSR operations with mode bits

---

## 2. OPERAND PARSING ERRORS

### 2.1 Number Format Parsing
- [ ] Hexadecimal (0xFF, 0xAB, 0x00)
- [ ] Decimal (255, 0, 1)
- [ ] Binary (0b11111111, 0B1010)
- [ ] Octal (0o377 if supported)
- [ ] MPASM styles (0FFh, 0FFH, 11111111B)
- [ ] Edge case: 0x0, 0b0, etc.
- [ ] Invalid formats (0x, 0b without digits) - should error
- [ ] Number overflow (values > 65535)
- [ ] Negative numbers (-1, -255)

### 2.2 Operand Type Matching
- [ ] File register expected but got literal
- [ ] Literal expected but got file register
- [ ] Bit position out of range
- [ ] Destination bit (0 or 1 only)
- [ ] Register + destination combinations
- [ ] Missing required operands
- [ ] Extra operands provided

### 2.3 Expression Evaluation
- [ ] Arithmetic in operands (MOVLW 0xFF - 1)
- [ ] Symbol references
- [ ] Constant definitions (EQU)
- [ ] Division by zero errors
- [ ] Operator precedence
- [ ] Parenthesis matching
- [ ] Function calls (HIGH, LOW, etc.)
- [ ] Program counter reference ($)

---

## 3. LABEL AND SYMBOL ERRORS

### 3.1 Label Resolution
- [ ] Forward references (using label before definition)
- [ ] Backward references (using label after definition)
- [ ] Undefined labels (used but never defined)
- [ ] Duplicate label definitions
- [ ] Label scope and visibility
- [ ] Label at address boundaries
- [ ] Empty labels

### 3.2 Symbol Table Issues
- [ ] Case sensitivity (Label vs label vs LABEL)
- [ ] Reserved word conflicts
- [ ] Symbol name validation
- [ ] Special characters in names
- [ ] Very long symbol names
- [ ] Circular references (EQU A=B, EQU B=A)
- [ ] Symbol type confusion (label vs constant)

### 3.3 Address Calculation
- [ ] Correct program counter advancement
- [ ] Address for each instruction type
- [ ] Label addresses after ORG directives
- [ ] Address overflow in memory
- [ ] Word address vs byte address confusion (PIC16: word-addressed)

---

## 4. DIRECTIVE ERRORS

### 4.1 ORG Directive
- [ ] ORG sets program counter correctly
- [ ] ORG with invalid addresses
- [ ] ORG past memory limits
- [ ] Multiple ORG directives
- [ ] ORG with expressions

### 4.2 EQU Directive
- [ ] EQU value assignment
- [ ] EQU with expressions
- [ ] EQU forward references
- [ ] EQU circular definitions
- [ ] EQU case sensitivity

### 4.3 DB/DW Directive
- [ ] DB (byte) data packing
- [ ] DW (word) data packing
- [ ] Data alignment
- [ ] Data type mixing
- [ ] Data at specific addresses
- [ ] Multiple data values
- [ ] Data size limits

### 4.4 Other Directives
- [ ] END directive handling
- [ ] CONFIG/PROCESSOR directives
- [ ] BANKSEL/PAGESEL (if supported)
- [ ] UDATA/CODE sections (if supported)

---

## 5. MEMORY AND ADDRESSING ERRORS

### 5.1 Memory Model Issues
- [ ] Word-addressed vs byte-addressed (PIC16 vs PIC18)
- [ ] Program memory limits per device
- [ ] Data memory limits
- [ ] EEPROM limits
- [ ] Address wrapping behavior
- [ ] Program memory gaps

### 5.2 Address Calculations
- [ ] HEX output address calculation
- [ ] Address for CALL/GOTO targets
- [ ] Data placement addresses
- [ ] Instruction placement addresses
- [ ] Address alignment requirements

### 5.3 Cross-Memory Operations
- [ ] Mixing program and data memory
- [ ] MOVFF between banks (PIC18)
- [ ] Indirect addressing bounds

---

## 6. HEX OUTPUT FORMAT ERRORS

### 6.1 Intel HEX Format Compliance
- [ ] Correct record format (`:LLAAAATTDD...CC`)
- [ ] Byte count (LL) accuracy
- [ ] Address field (AAAA) correctness
- [ ] Record type (TT) values
- [ ] Data field (DD...) content
- [ ] Checksum (CC) calculation

### 6.2 Record Types
- [ ] Data records (0x00)
- [ ] End-of-file record (0x01) - must be present
- [ ] Extended linear address record (0x04) - for > 64KB
- [ ] Start address record (0x05) - if used
- [ ] Record ordering

### 6.3 Address Handling
- [ ] Address continuity
- [ ] Extended addressing for large programs
- [ ] Address wrapping in 16-bit space
- [ ] Gaps in address space handling

### 6.4 Data Packing
- [ ] Byte ordering (little-endian for PIC16)
- [ ] Word boundary alignment
- [ ] Record size limits (typically 16-32 bytes)
- [ ] Consecutive data merging

---

## 7. ARCHITECTURE-SPECIFIC ERRORS

### 7.1 PIC12 Issues
- [ ] 12-bit instruction word encoding
- [ ] Smaller address space (512-2048 words)
- [ ] Limited instruction set
- [ ] OPTION and TRIS instructions
- [ ] Page boundaries

### 7.2 PIC16 Issues
- [ ] 14-bit instruction word encoding
- [ ] Word addressing (multiply address by 2)
- [ ] Bank switching (if applicable)
- [ ] Page boundaries for CALL/GOTO
- [ ] FSR indirect addressing (if supported)

### 7.3 PIC18 Issues
- [ ] 16-bit instruction word encoding
- [ ] Byte addressing (different from PIC16)
- [ ] Extended instruction set
- [ ] MOVFF 2-word format
- [ ] Table read/write operations
- [ ] Multiple banks and access bits
- [ ] Conditional branch relative addressing

---

## 8. EDGE CASES AND BOUNDARY CONDITIONS

### 8.1 Empty/Minimal Programs
- [ ] Empty source file
- [ ] Only comments
- [ ] Only directives (ORG, END)
- [ ] Single instruction
- [ ] No END directive

### 8.2 Extreme Values
- [ ] Maximum file register (255)
- [ ] Maximum literal (65535 or per-instruction limit)
- [ ] Maximum program counter value
- [ ] Maximum label count
- [ ] Very long assembly files

### 8.3 Special Operand Combinations
- [ ] Same register as source and destination
- [ ] Bit position 7 (highest bit)
- [ ] Register 0 (special case: FSR, STATUS, etc.)
- [ ] All-zeros operands
- [ ] All-ones operands

### 8.4 Syntax Edge Cases
- [ ] Lowercase vs uppercase mnemonics
- [ ] Extra whitespace
- [ ] Multiple spaces between operands
- [ ] Tabs vs spaces
- [ ] Comment characters in strings
- [ ] Escaped characters

---

## 9. CODE GENERATION ERRORS

### 9.1 Instruction Sequence Issues
- [ ] Correct instruction order in output
- [ ] Address assignment correctness
- [ ] Program counter updates
- [ ] Instruction interleaving with data

### 9.2 Generated Code Validity
- [ ] Each instruction produces valid opcode
- [ ] No corrupted instructions
- [ ] No missing instructions
- [ ] No duplicate instructions

### 9.3 Data Generation
- [ ] Data values preserved correctly
- [ ] Data types (byte vs word) correct
- [ ] Data endianness

---

## 10. ERROR REPORTING ERRORS

### 10.1 Error Detection
- [ ] All syntax errors caught
- [ ] All semantic errors caught
- [ ] Error messages descriptive
- [ ] Line numbers correct
- [ ] Column numbers accurate

### 10.2 Error Recovery
- [ ] Assembly continues after errors
- [ ] Multiple errors reported
- [ ] Error count correct
- [ ] Fatal vs non-fatal errors distinguished

---

## 11. FILE I/O ERRORS

### 11.1 Input File Handling
- [ ] File existence check
- [ ] File readability
- [ ] File permissions
- [ ] Large file handling
- [ ] Character encoding (ASCII, UTF-8)
- [ ] Line ending handling (CRLF vs LF)

### 11.2 Output File Handling
- [ ] HEX file creation
- [ ] File overwrite handling
- [ ] Write permissions
- [ ] Directory creation
- [ ] Path validation
- [ ] File format correctness

---

## 12. COMPATIBILITY ERRORS

### 12.1 MPASM Compatibility
- [ ] MPASM syntax compliance
- [ ] MPASM number formats
- [ ] MPASM directive support
- [ ] MPASM error behavior

### 12.2 Microchip Datasheet Compliance
- [ ] Instruction encodings per datasheet
- [ ] Memory model per datasheet
- [ ] Device-specific limits

---

## Testing Strategy

### Priority 1 (CRITICAL)
- Instruction encoding verification (already started)
- Operand range validation
- Label resolution
- Memory addressing

### Priority 2 (HIGH)
- Number format parsing
- Directive handling
- HEX output format
- Architecture-specific issues

### Priority 3 (MEDIUM)
- Edge cases and boundary conditions
- Error reporting
- File I/O
- Compatibility

### Priority 4 (LOW)
- Optimization and performance
- Nice-to-have features
- Documentation

---

## Recommended Testing Approach

1. **Unit Tests**: Test individual components (lexer, parser, encoder)
2. **Integration Tests**: Test full assembly pipeline
3. **Regression Tests**: Prevent fixes from breaking other features
4. **Fuzzing**: Random input generation to find edge cases
5. **Hardware Validation**: Program actual devices and verify execution
6. **Comparison Testing**: Compare output with MPLAB/MPASM

---

## Known Issues Already Found

1. ❌ Bit-oriented instruction encoding (bits 11-9 positioning)
2. ❌ Byte-oriented instruction encoding (d-bit positioning)
3. ⚠️  Data directive duplication (fixed in previous commits)
4. ⚠️  Address calculation in HEX output (fixed in previous commits)

---

## Verification Checklist

- [ ] Run instruction encoding test suite
- [ ] Verify all operand ranges
- [ ] Test label resolution edge cases
- [ ] Validate HEX output format
- [ ] Check architecture-specific behavior
- [ ] Test all directives
- [ ] Verify error messages
- [ ] Test file I/O error handling
- [ ] Program actual hardware with output
- [ ] Compare against MPLAB output

