# BANKSEL/PAGESEL Implementation Plan

## Overview
BANKSEL and PAGESEL are directives that automatically manage memory bank and page selection for PIC microcontrollers.

## Architecture-Specific Details

### PIC16 - BANKSEL
**Purpose:** Automatically select memory bank for accessing registers/variables

**Banking Structure:**
- Multiple banks (typically 4 banks of 128 bytes each)
- Banks: 0x00-0x7F, 0x80-0xFF, 0x100-0x17F, 0x180-0x1FF
- Bank selection via STATUS register bits: RP1:RP0
  - 00 = Bank 0
  - 01 = Bank 1
  - 10 = Bank 2
  - 11 = Bank 3

**Generated Code:** Sets RP1:RP0 bits appropriately
```asm
BANKSEL PORTB    ; If PORTB is in Bank 1
; Generates:
; BCF STATUS, RP1    ; Clear RP1
; BSF STATUS, RP0    ; Set RP0
```

**Implementation:**
1. Get symbol address from symbol table
2. Calculate bank number: bank = address / 128
3. Generate BCF/BSF instructions to set RP0, RP1 appropriately

### PIC18 - PAGESEL
**Purpose:** Automatically set page for CALL/GOTO instructions

**Paging Structure:**
- Program memory is divided into 2KB pages
- PCLATH[7:3] selects the page
- Instruction address = PCLATH[7:3] + PCL

**Generated Code:** Moves page number to PCLATH
```asm
PAGESEL MY_ROUTINE    ; If MY_ROUTINE is in page 2
; Generates:
; MOVLW 0x04          ; Page 2 (2 * 0x800 >> 8 = 0x04)
; MOVWF PCLATH
```

**Implementation:**
1. Get symbol address from symbol table
2. Calculate page: page = (address >> 11) & 0xFF  ; 2KB = 2048 = 0x800
3. Generate MOVLW/MOVWF to set PCLATH

### PIC18 - BANKISEL (Indirect Addressing)
**Purpose:** Select bank for indirect addressing (FSR0H:FSR0L)

**Bank Structure:**
- BSR[3:0] selects RAM bank
- Used with INDF0, POSTINC0, etc. for indirect access

**Generated Code:** Moves bank number to BSR
```asm
BANKISEL MY_VAR
; Generates:
; MOVLW bank_number
; MOVWF BSR
```

## Implementation Steps

1. **Add BANKSEL/PAGESEL/BANKISEL routing to parseDirective()**
   - Check for directive name
   - Extract symbol/label argument
   - Call appropriate handler

2. **Implement handleBANKSEL() - PIC16 only**
   - Look up symbol address
   - Calculate bank number
   - Generate BCF/BSF instructions

3. **Implement handlePAGESEL() - PIC18 only**
   - Look up symbol address
   - Calculate page number
   - Generate MOVLW/MOVWF instructions

4. **Implement handleBANKISEL() - PIC18 only**
   - Look up symbol address
   - Calculate indirect bank number
   - Generate MOVLW/MOVWF instructions

5. **Create test files**
   - PIC16: BANKSEL with various symbols
   - PIC18: PAGESEL with various labels
   - PIC18: BANKISEL with indirect register access

6. **Verify correct instruction generation**
   - Check hex output
   - Verify correct STATUS bits set
   - Verify PCLATH/BSR values

## Edge Cases to Handle

- Symbol not found in symbol table (error)
- BANKSEL used in PIC18 (warning or error)
- PAGESEL used in PIC16 (warning or error)
- BANKISEL used in PIC16 (error)
- Symbol in bank 0 / page 0 (might generate unnecessary code)
- Very high memory addresses (overflow checks)

## Testing Strategy

Create test files for each architecture:
- `test_banksel_basic.asm` - Simple BANKSEL usage
- `test_banksel_multiple.asm` - Multiple banks
- `test_pagesel_basic.asm` - Simple PAGESEL usage
- `test_pagesel_multiple.asm` - Multiple pages
- `test_bankisel_basic.asm` - BANKISEL with indirect addressing

Verify:
- Correct instructions generated
- Correct address/bank/page calculations
- Proper error handling
