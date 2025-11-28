# Microchip PIC Device Memory Specifications Report

## Executive Summary

This report documents the memory specifications extracted from three Microchip device packs for PIC microcontrollers. A total of **344 unique devices** were analyzed across PIC12, PIC16, and PIC18 families.

## Source Device Packs

1. **Microchip.PIC12-16F1xxx_DFP.1.8.254.atpack_FILES**
   - PIC12F1xxx and PIC16F1xxx enhanced mid-range devices
   - Release Date: 2025-03-27

2. **Microchip.PIC16Fxxx_DFP.1.7.162.atpack_FILES**
   - Classic PIC16F devices and baseline PIC12/16 devices
   - Includes legacy and widely-used devices

3. **Microchip.PIC18F-Q_DFP.1.28.451.atpack_FILES**
   - Modern PIC18F-Q series devices
   - High-performance 8-bit microcontrollers

## Requested Devices

### PIC18F-Q40 Series (FOUND)

All six PIC18F-Q40 variants were found in the PIC18F-Q device pack:

| Device Name | Program Memory | Data SRAM | EEPROM | Architecture | Instruction Set |
|-------------|----------------|-----------|--------|--------------|-----------------|
| PIC18F04Q40 | 16,384 bytes (16 KB) | 1,120 bytes | 512 bytes | 18xxxx | cpu_pic18f_v6 |
| PIC18F05Q40 | 32,768 bytes (32 KB) | 2,144 bytes | 512 bytes | 18xxxx | cpu_pic18f_v6 |
| PIC18F06Q40 | 65,536 bytes (64 KB) | 4,192 bytes | 512 bytes | 18xxxx | cpu_pic18f_v6 |
| PIC18F14Q40 | 16,384 bytes (16 KB) | 1,120 bytes | 512 bytes | 18xxxx | cpu_pic18f_v6 |
| PIC18F15Q40 | 32,768 bytes (32 KB) | 2,144 bytes | 512 bytes | 18xxxx | cpu_pic18f_v6 |
| PIC18F16Q40 | 65,536 bytes (64 KB) | 4,192 bytes | 512 bytes | 18xxxx | cpu_pic18f_v6 |

**Key Characteristics:**
- All Q40 devices use the **cpu_pic18f_v6** instruction set
- Consistent EEPROM size of **512 bytes** across all variants
- Memory scales: 16KB/32KB/64KB ROM variants available
- Modern architecture with linear addressing

### PIC16F18076 (NOT FOUND)

**Status:** PIC16F18076 was **not found** in any of the three device packs.

**Possible Reasons:**
1. The device may belong to a different device family pack (e.g., a newer PIC16F1xxxx_DFP pack)
2. The device may be a recent release not yet included in these packs (2025-03-27)
3. The device designation may be incorrect or refer to a variant not in these packs

**Note:** The PIC12-16F1xxx pack does contain PIC16F18xx devices (such as PIC16F1823, PIC16F1824, PIC16F1825, PIC16F1826, PIC16F1827, PIC16F1828, PIC16F1829, PIC16F1847), but these are **different** from PIC16F18076. The naming convention suggests PIC16F18076 would be a higher pin-count device in a potentially different sub-family.

## Instruction Set Analysis

The devices use five distinct instruction set architectures, which is critical for assembler implementation:

### 1. cpu_pic18f_v6 (PIC18 Enhanced)
- **Devices:** 55 devices (all modern PIC18F-Q series)
- **Instruction Width:** 16-bit
- **Base Instructions:** 83+ instructions
- **Key Features:**
  - Hardware 8x8 multiplier
  - Indexed addressing modes (PLUSW, PREINC, POSTINC, POSTDEC)
  - Extended instruction set support
  - Linear addressing (12-bit addresses)
  - 20-bit program counter for large memory
  - MOVFF instruction for direct register-to-register moves
  - CALL/GOTO with 20-bit addresses

### 2. cpu_mid_v10 (PIC16 Enhanced Mid-Range)
- **Devices:** 160 devices (PIC12F1xxx, PIC16F1xxx series)
- **Instruction Width:** 14-bit
- **Base Instructions:** 49 instructions
- **Key Features:**
  - Single accumulator (WREG)
  - Banked memory architecture (requires BSR management)
  - Hardware stack (15-16 levels)
  - Enhanced instruction set vs classic mid-range
  - ADDFSR, MOVIW, MOVWI for indirect addressing

### 3. pic16f77 (PIC16 Classic Mid-Range)
- **Devices:** 113 devices (classic PIC16F series)
- **Instruction Width:** 14-bit
- **Base Instructions:** 35 instructions
- **Key Features:**
  - Classic mid-range architecture
  - Bank switching required
  - Page switching for CALL/GOTO
  - Limited indirect addressing

### 4. pic12c5xx (PIC12/16 Baseline)
- **Devices:** 7 devices (PIC12F5xx, PIC16F5x series)
- **Instruction Width:** 12-bit
- **Base Instructions:** 33 instructions
- **Key Features:**
  - Very limited instruction set
  - 2-level hardware stack
  - No interrupts on some variants
  - Minimal addressing modes

### 5. egg (Extended Gigabit)
- **Devices:** 7 devices (some PIC18F-Q10 series: PIC18F24Q10, PIC18F25Q10, PIC18F26Q10, PIC18F27Q10, PIC18F45Q10, PIC18F46Q10, PIC18F47Q10)
- **Note:** This appears to be an early or alternative instruction set variant for some Q10 series devices

## Critical Differences for Assembler Implementation

### 1. Memory Addressing

**PIC18:**
- Linear addressing with 12-bit data addresses
- No bank switching required for most operations
- Access bank (0x00-0x5F) directly addressable
- Extended addressing for large programs

**PIC16 Enhanced Mid-Range:**
- Banked architecture requiring BSR (Bank Select Register)
- 128 bytes per bank
- Common bank (0x70-0x7F) accessible from any bank
- Linear indirect addressing available via FSR

**PIC16 Classic:**
- Banked architecture with RP0/RP1 bits in STATUS
- Page switching required for CALL/GOTO
- More complex memory management

### 2. Instruction Encoding

**PIC18 (16-bit):**
```
Format: [15:0] instruction bits
All 16 bits used
Byte-addressed in program memory
```

**PIC16 Enhanced/Classic (14-bit):**
```
Format: [13:0] instruction bits, [15:14] = 00
Stored as 16-bit words but only 14 bits significant
Word-addressed in program memory
```

**PIC16 Baseline (12-bit):**
```
Format: [11:0] instruction bits, [15:12] = 0000
Stored as 16-bit words but only 12 bits significant
Word-addressed in program memory
```

### 3. HEX File Format Differences

**PIC18:**
- Byte-addressed (address increments by 1 per byte)
- Extended Linear Address Record (type 04) may be used
- Data records contain actual bytes

**PIC16:**
- Word-addressed (address increments by 1 per word, which is 2 bytes)
- Each instruction is one word (2 bytes)
- Addresses in HEX file are word addresses, not byte addresses

### 4. Key Instruction Differences

**PIC18-only instructions:**
- `MOVFF src, dest` - Direct file-to-file move
- `LFSR f, k` - Load FSR with literal
- `ADDFSR f, k` - Add literal to FSR
- `ADDULNK k` - Add literal unsigned and link
- `CALLW` - Call using WREG
- `MOVSF`, `MOVSS` - Special function moves
- `PUSHL k` - Push literal

**PIC16 Enhanced-only instructions:**
- `ADDFSR FSRn, k` - Add to FSR
- `MOVIW`, `MOVWI` - Indexed indirect moves
- `LSLF`, `LSRF` - Logical shifts
- `ASRF` - Arithmetic right shift
- `BRA` - Branch (relative addressing)

**Common instructions (across most families):**
- `MOVLW`, `MOVWF`, `MOVF` - Data movement
- `ADDWF`, `SUBWF`, `ANDWF`, `IORWF`, `XORWF` - ALU operations
- `BCF`, `BSF`, `BTFSC`, `BTFSS` - Bit operations
- `CALL`, `GOTO`, `RETURN` - Control flow (different encoding)

### 5. Configuration and Special Memory

**Program Memory:**
- PIC18: Up to 128KB (131,072 bytes) in this dataset
- PIC16: Typically up to 8KB (8,192 bytes) in enhanced mid-range
- Configuration words stored at end of program memory

**EEPROM Availability:**
- PIC18F-Q40: All have 512 bytes
- PIC18F-Q other: 0-1024 bytes depending on variant
- PIC16F1xxx: 0-256 bytes (many have none)
- PIC16F classic: 0-256 bytes

**Data SRAM:**
- PIC18: Up to 12,896 bytes (PIC18F27Q83/84)
- PIC16: Typically 128-2544 bytes
- PIC12: Typically 96-752 bytes

## Device Family Summary

### Total Devices by Family
- **PIC12 Devices:** 15
- **PIC16 Devices:** 267
- **PIC18 Devices:** 62
- **Total:** 344 unique devices

### Representative Devices by Performance Tier

**High Performance (PIC18F-Q series):**
```
PIC18F27Q84
  ROM: 131,072 bytes (128 KB)
  SRAM: 12,896 bytes
  EEPROM: 1,024 bytes
  Instruction Set: cpu_pic18f_v6
```

**Mid Performance (PIC16F1xxx Enhanced):**
```
PIC16F1719
  ROM: 2,048 bytes (2 KB)
  SRAM: 2,544 bytes
  EEPROM: 0 bytes
  Instruction Set: cpu_mid_v10
```

**Classic Workhorse (PIC16F classic):**
```
PIC16F877A
  ROM: 2,048 bytes (2 KB)
  SRAM: 416 bytes
  EEPROM: 256 bytes
  Instruction Set: pic16f77
```

**Legacy/Low Cost (PIC16F baseline):**
```
PIC16F84A
  ROM: 1,024 bytes (1 KB)
  SRAM: 136 bytes
  EEPROM: 64 bytes
  Instruction Set: pic16f77
```

## Recommendations for Assembler Development

### 1. Architecture Detection
Implement device detection based on:
- Device name pattern matching
- Explicit device specification in source code
- Architecture directives (e.g., `.arch pic18`, `.processor pic16f877a`)

### 2. Instruction Set Selection
Create separate instruction tables for:
- PIC18 Enhanced (cpu_pic18f_v6)
- PIC16 Enhanced Mid-Range (cpu_mid_v10)
- PIC16 Classic Mid-Range (pic16f77)
- PIC16 Baseline (pic12c5xx, pic16f527)

### 3. Memory Validation
- Validate program addresses against device ROM size
- Check data memory access against SRAM size
- Warn about EEPROM usage on devices without EEPROM

### 4. Addressing Mode Handling
**For PIC18:**
- Support Access/Banked bit (a=0/1)
- Support Fast Call/Return bit (s=0/1)
- Handle extended addresses for large programs

**For PIC16:**
- Implement bank selection tracking/optimization
- Insert BANKSEL directives automatically
- Handle page boundaries for CALL/GOTO

### 5. HEX File Generation
- PIC18: Byte addressing, linear format
- PIC16: Word addressing, adjust addresses accordingly
- Include proper record types (00, 01, 04, 05)

## Files Generated

1. **device_memory_specifications.csv**
   - Complete spreadsheet with all 344 devices
   - Columns: device, arch, instruction_set, rom, sram, eeprom
   - Located at: `/home/w4gns/CLionProjects/PIC-Assembler/device_memory_specifications.csv`

2. **DEVICE_MEMORY_REPORT.md** (this file)
   - Comprehensive analysis and recommendations
   - Located at: `/home/w4gns/CLionProjects/PIC-Assembler/DEVICE_MEMORY_REPORT.md`

## Conclusion

The three device packs provide comprehensive specifications for 344 PIC devices across multiple architectures. The PIC18F-Q40 series devices are well-documented and use the modern cpu_pic18f_v6 instruction set. The PIC16F18076 device was not found in these packs and may require a different or newer device pack.

The key technical challenge for the assembler is handling the different instruction sets and memory architectures correctly:
- **Instruction encoding:** 12-bit vs 14-bit vs 16-bit
- **Memory addressing:** Linear vs banked
- **HEX file format:** Byte vs word addressing
- **Special instructions:** Architecture-specific opcodes

The complete device database in CSV format enables the assembler to validate device capabilities and memory constraints at assembly time.
