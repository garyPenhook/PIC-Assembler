# GnSasm Comprehensive Test Plan

## Test Suite Organization

### Phase 1: Critical Fixes (Required before any use)
- [ ] Fix bit-oriented instruction encoding
- [ ] Fix byte-oriented instruction encoding
- [ ] Pass all 16 existing instruction encoding tests (100%)

### Phase 2: Operand Validation Testing
**Goal**: Ensure operand bounds are correctly enforced

#### Operand Range Tests
```
Test: File register bounds for MOVWF
- Valid: MOVWF 0, MOVWF 127, MOVWF 255
- Invalid: MOVWF 256, MOVWF -1, MOVWF 999
- Expected: Only valid range accepted, others error

Test: Bit position bounds for BSF
- Valid: BSF 0x20, 0 through BSF 0x20, 7
- Invalid: BSF 0x20, 8, BSF 0x20, -1
- Expected: Only 0-7 accepted

Test: Literal bounds for MOVLW
- Valid: MOVLW 0, MOVLW 255, MOVLW 0xFF
- Invalid: MOVLW 256, MOVLW -1
- Expected: Only 0-255 accepted

Test: CALL/GOTO address bounds (11-bit)
- Valid: GOTO 0, GOTO 0x7FF, CALL 0x400
- Invalid: GOTO 0x800, CALL 0xFFF
- Expected: Only 11-bit addresses accepted
```

### Phase 3: Number Format Testing
**Goal**: Verify all number format parsing works correctly

#### Number Format Tests
```
Test: Hexadecimal formats
- 0xFF, 0x00, 0xAB, 0xFFH (MPASM style)
- Edge: 0x0, 0x1, 0xFFF (4-digit)
- Invalid: 0x, 0xGG, 0xZZ
- Expected: All valid formats parse, invalid formats error

Test: Decimal formats
- 0, 1, 255, 65535
- Edge: 00000, 000001
- Invalid: -1, 99999999
- Expected: Correct value parsed

Test: Binary formats
- 0b0, 0b1, 0b11111111, 0B1010
- Edge: 0b0000, 0b1111
- Invalid: 0b, 0b2, 0b111111111 (>8 bits)
- Expected: Correct value parsed

Test: Octal formats (if supported)
- 0o377, 0o0, 0o77
- Invalid: 0o, 0o888
- Expected: Correct parsing

Test: MPASM styles
- Decimal: 255D, 0D
- Hex: 0FFh, 0ABH
- Binary: 11111111B, 0b1010
- Expected: All styles parse identically
```

### Phase 4: Label and Symbol Testing
**Goal**: Verify label resolution and symbol handling

#### Label Resolution Tests
```
Test: Forward references
Code:
  GOTO target
  NOP
target:
  MOVLW 0x42
Expected: GOTO encodes with correct target address

Test: Undefined labels
Code:
  GOTO undefined_label
Expected: Assembly fails with "undefined label" error

Test: Duplicate labels
Code:
  start:
    NOP
  start:
    NOP
Expected: Assembly fails with "duplicate label" error

Test: Label at memory boundaries
Code:
  ORG 0x7FF
label:
Expected: Label at maximum address handled correctly

Test: Case sensitivity
Code:
  GOTO LABEL
label:
  NOP
Expected: Error if case-sensitive, or works if case-insensitive (consistent)
```

#### Symbol Table Tests
```
Test: EQU constants
Code:
  CONST EQU 0x20
  MOVWF CONST
Expected: MOVWF 0x20 generated

Test: EQU expressions
Code:
  MAX EQU 255
  VAL EQU MAX - 1
  MOVLW VAL
Expected: MOVLW 254 generated

Test: EQU forward references
Code:
  MOVLW FUTURE
  FUTURE EQU 42
Expected: Works correctly with forward reference
```

### Phase 5: Directive Testing
**Goal**: Verify all directives work correctly

#### ORG Directive Tests
```
Test: ORG sets address correctly
Code:
  ORG 0x0100
  MOVLW 0x42
Expected: Instruction at address 0x0100 in HEX

Test: Multiple ORG directives
Code:
  ORG 0x0000
  NOP
  ORG 0x0100
  NOP
Expected: Both instructions at correct addresses

Test: ORG with expressions
Code:
  ORG 0xFF + 1
  NOP
Expected: Instruction at address 0x100
```

#### Data Directive Tests
```
Test: DB (byte) data
Code:
  ORG 0x0100
  DB 0x11, 0x22, 0x33
Expected: Three bytes at address 0x0100 in HEX

Test: DW (word) data
Code:
  ORG 0x0100
  DW 0x1122, 0x3344
Expected: Four bytes (2 words) at address 0x0100, little-endian

Test: DB/DW mixing
Code:
  DB 0x11
  DW 0x2233
  DB 0x44
Expected: All data at correct addresses, proper alignment

Test: Data at specific addresses
Code:
  DB 0x11, 0x22
  ORG 0x0200
  DB 0x33, 0x44
Expected: Data at both locations correctly merged in HEX
```

### Phase 6: HEX Output Validation
**Goal**: Verify HEX file format correctness

#### HEX Format Tests
```
Test: Record format compliance
Code:
  ORG 0x0000
  MOVLW 0x42
Expected: HEX record `:020000004230XX` (where XX is checksum)

Test: Checksum calculation
For each record, verify:
- Sum of (byte_count + addr_high + addr_low + record_type + all_data_bytes)
- Result should make total sum = 0 (mod 256)
Expected: All checksums correct

Test: Record type values
Expected values:
- Data records: 00
- End-of-file: 01
- Extended linear address: 04
Expected: Only these types in output

Test: Address field correctness
Code:
  ORG 0x0100
  NOP
  ORG 0x0200
  NOP
Expected: HEX records show correct addresses

Test: Data field integrity
Code:
  ORG 0x0000
  DB 0x11, 0x22, 0x33, 0x44
Expected: Exact byte sequence in HEX data field
```

### Phase 7: Architecture-Specific Testing
**Goal**: Verify PIC12/PIC16/PIC18 differences

#### PIC16 vs PIC18 Addressing
```
Test: Word-addressed (PIC16) vs byte-addressed (PIC18)
Code:
  ORG 0x0100
  NOP
  DB 0x11
PIC16: Instruction at address 0x0200 (0x0100 * 2)
PIC18: Instruction at address 0x0100 (byte-addressed)

Test: Instruction word size
PIC16: 14-bit instructions (bits 15-14 unused or zero)
PIC18: 16-bit instructions (all bits used)
```

#### Architecture-Specific Instructions
```
Test: PIC12 TRIS instruction
Code:
  TRIS 0x05
Expected: Opcode 0065 with file register 5

Test: PIC18 MOVFF instruction (2-word)
Code:
  MOVFF 0x00, 0x01
Expected: 2 words generated

Test: PIC18 TBLRD instruction with mode
Code:
  TBLRD (TBLPTR post-increment)
Expected: Mode bits set correctly
```

### Phase 8: Error Handling Testing
**Goal**: Verify error messages and recovery

#### Syntax Error Tests
```
Test: Missing operands
Code:
  MOVWF
Expected: Error with line number and suggestion

Test: Invalid operands
Code:
  MOVWF ABC (not a number or valid label)
Expected: Error describing invalid operand

Test: Unknown instruction
Code:
  UNKNOWN 0x20
Expected: Error suggesting similar instructions

Test: Duplicate directives
Code:
  END
  END
Expected: Warning or error about duplicate END
```

#### Semantic Error Tests
```
Test: Architecture mismatch
Code (with PIC16):
  MOVFF 0x00, 0x01  (PIC18 only)
Expected: Error "instruction not available in PIC16"

Test: Register out of bounds
Code:
  MOVWF 256
Expected: Error "register out of range"

Test: Symbol table error
Code:
  MOVLW UNDEF
Expected: Error "undefined symbol"
```

### Phase 9: Edge Cases
**Goal**: Test boundary conditions and unusual inputs

#### Boundary Tests
```
Test: Program at maximum address
Code (PIC16):
  ORG 0x7FF
  NOP
Expected: Works at max address

Test: Program past maximum address
Code (PIC16):
  ORG 0x800
  NOP
Expected: Error or warning

Test: Maximum file register
Code:
  MOVWF 255
Expected: Works

Test: Minimum values
Code:
  ORG 0x0000
  MOVLW 0x00
  BCF 0x00, 0
Expected: All work correctly
```

#### Whitespace and Syntax Tests
```
Test: Lowercase mnemonics
Code:
  movlw 0x42
Expected: Works (case-insensitive)

Test: Extra whitespace
Code:
  MOVLW    0x42
  MOVWF  0x20
Expected: Works with any whitespace

Test: Tabs instead of spaces
Code:
  [TAB]MOVLW[TAB]0x42
Expected: Works

Test: No spaces in operands
Code:
  ADDWF0x20,1
Expected: Error (should require comma separation) or parses correctly
```

### Phase 10: Regression Testing
**Goal**: Ensure fixes don't break working features

```
After EACH fix, re-run:
1. All 16 instruction encoding tests (target: 100%)
2. Sample programs from examples
3. Previous working test cases
4. Error handling tests
```

---

## Test Execution Checklist

### Automated Tests
- [ ] Compile test suite
- [ ] Run instruction encoding tests
- [ ] Run operand validation tests
- [ ] Run number format tests
- [ ] Run directive tests
- [ ] Run HEX format tests

### Manual Tests
- [ ] Assemble provided examples
- [ ] Generate HEX files
- [ ] Verify HEX content manually
- [ ] Compare with MPLAB output (if available)

### Hardware Validation
- [ ] Program actual PIC device
- [ ] Execute and verify behavior
- [ ] Compare with MPASM-generated code

### Compatibility Tests
- [ ] Test against MPASM examples
- [ ] Test against Microchip datasheets
- [ ] Test against online simulators

---

## Success Criteria

### Must Have (Blocking)
- ✓ All instruction encoding tests pass (16/16)
- ✓ Operand range validation correct
- ✓ Label resolution works
- ✓ HEX output format valid
- ✓ No silent failures

### Should Have (Important)
- ✓ All directives work
- ✓ Error messages clear and helpful
- ✓ Architecture selection honored
- ✓ Large files handled

### Nice to Have (Polish)
- ✓ Performance optimizations
- ✓ Extended documentation
- ✓ IDE integration

---

## Known Gaps

**NOT YET TESTED**:
1. PIC18 instruction encoding
2. PIC12 instruction encoding
3. Multi-word instructions (MOVFF)
4. Extended addressing (> 64KB)
5. Conditional branch distance calculation
6. All error message wording
7. Performance with very large files
8. Unicode/special characters in comments

**NEEDS HARDWARE**:
1. Actual device programming
2. Instruction execution verification
3. Interrupt handling
4. Timing-sensitive code

---

## Test Priority Matrix

| Test Type | Priority | Effort | Impact | Status |
|-----------|----------|--------|--------|--------|
| Instruction Encoding | CRITICAL | High | Very High | 🔴 In Progress |
| Operand Validation | CRITICAL | Medium | Very High | ⏳ Pending |
| Label Resolution | CRITICAL | Medium | High | ⏳ Pending |
| HEX Format | HIGH | Medium | High | ⏳ Pending |
| Directives | HIGH | Medium | High | ⏳ Pending |
| Architecture Specific | HIGH | High | High | ⏳ Pending |
| Error Handling | MEDIUM | Medium | Medium | ⏳ Pending |
| Edge Cases | MEDIUM | High | Low | ⏳ Pending |
| Performance | LOW | High | Low | ⏳ Pending |

