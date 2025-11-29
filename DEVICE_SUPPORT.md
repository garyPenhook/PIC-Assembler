# Device Support Documentation

## Overview

The GnSasm assembler now supports **1,031 PIC microcontroller devices** across all major architectures:

- **PIC10** (Baseline - 12-bit): 10 devices
- **PIC12** (Baseline - 12-bit): 55 devices
- **PIC16** (Mid-Range - 14-bit): 531 devices  
- **PIC18** (Enhanced - 16-bit): 405 devices
- **PICRF** (RF-enabled): 30 devices

## How to Specify a Processor

Use the `.PROCESSOR` directive at the beginning of your assembly file:

```asm
; Test program for PIC16F15313
.PROCESSOR PIC16F15313

        ORG 0x0000
        MOVLW 0x55
        MOVWF 0x20
        END
```

### Processor Directive Syntax

```asm
.PROCESSOR <device_name>
```

Where `<device_name>` is the exact PIC device model (case-insensitive):
- PIC16F15313
- PIC16F1847
- PIC18F06Q40
- PIC12F683
- etc.

## Supported Device Families

### PIC12 (Baseline Architecture)
**Memory: 512-2048 words program, 24-96 bytes data**

Examples:
- PIC10Fxxx series
- PIC12Cxxx series
- PIC12Fxxx series
- PIC12Lxxx series

### PIC16 (Mid-Range Architecture)
**Memory: 512-16384 words program, 64-1920 bytes data**

Examples:
- PIC16C5xx/6xx/7xx/8xx (Classic)
- PIC16F5xx/6xx/7xx/8xx (Enhanced)
- PIC16F1xxx series (Modern)
- PIC16Lxxx variants (Low power)

### PIC18 (Enhanced Architecture)
**Memory: 4096-65536 words program, 256-4192 bytes data**

Examples:
- PIC18Fxxx (Classic enhanced)
- PIC18Fxxxx (4-digit variants)
- PIC18Fxxxxx (5-digit variants)
- PIC18Qxx (Q-series)
- PIC18Lxxx (Low power variants)
- PIC18RF/PICRF (RF variants)

## Auto-Detection

If no `.PROCESSOR` directive is specified, the assembler uses a default device:
- **PIC12**: PIC10F200
- **PIC16**: PIC16F1847
- **PIC18**: PIC18F06Q40

The default architecture can still be specified via the `-a` command-line flag:

```bash
./gnsasm -a pic16 program.asm -o program.hex
```

## Device Memory Specifications

Each device automatically includes:
- **Program Memory**: Total instruction words available
- **Data RAM**: General-purpose file registers
- **EEPROM**: Non-volatile data storage (if available)

These are automatically reported in the assembly statistics:

```
Assembly Statistics:
  Device: PIC16F15313
  Total instructions: 2
  Address range: 0x0 - 0x2
  Program Memory: 4 bytes / 4096 bytes (0.10%)
  Data Memory: 0 bytes / 1536 bytes (0.00%)
  EEPROM: 0 bytes / 256 bytes (0.00%)
  Status: SUCCESS
```

## Device Name Resolution

Device names are resolved automatically from the `.PROCESSOR` directive:
- Handles mixed case: `pic16f1847` = `PIC16F1847` = `PIC16F1847`
- Automatically infers architecture from device name
- Validates device existence (fails with error if unsupported)

## List of All Supported Devices

A complete list of 874+ devices is maintained in the code. To see devices in each family:

### PIC12 Devices (Baseline)
```
PIC10F200, PIC10F202, PIC10F204, PIC10F206
PIC10F220, PIC10F222, PIC10F320, PIC10F322
PIC12C508, PIC12C509, PIC12C671, PIC12C672
PIC12F629, PIC12F683, PIC12F752
... and 100+ more variants
```

### PIC16 Devices (Mid-Range)
```
PIC16F1454, PIC16F1455, PIC16F1459
PIC16F1503, PIC16F1507, PIC16F1508, PIC16F1509
PIC16F1512, PIC16F1513, PIC16F1516, PIC16F1517, PIC16F1518, PIC16F1519
PIC16F15213, PIC16F15214, PIC16F15223, PIC16F15224, PIC16F15225
PIC16F15243, PIC16F15244, PIC16F15245, PIC16F15254, PIC16F15255, PIC16F15256
PIC16F15313, PIC16F15323, PIC16F15324, PIC16F15325
... and 400+ more variants (including F1xxx, F5xx, Fxxx, LF variants)
```

### PIC18 Devices (Enhanced)
```
PIC18F04Q20, PIC18F04Q40, PIC18F04Q41
PIC18F05Q20, PIC18F05Q40, PIC18F05Q41
PIC18F06Q20, PIC18F06Q40, PIC18F06Q41
PIC18F13K22, PIC18F13K50, PIC18F14K22, PIC18F14K50
PIC18F14Q20, PIC18F14Q40, PIC18F14Q41
PIC18F24J10, PIC18F24J11, PIC18F24J50, PIC18F24K20, PIC18F24K22, PIC18F24K40, PIC18F24K42, PIC18F24K50
... and 370+ more variants (K-series, J-series, Q-series, Q20, Q40, Q41, L-variants)
```

## Adding New Devices

To add support for new devices:

1. Ensure the device has a `.cgen.inc` file in `device_includes/`
2. Run the device generation script:
   ```bash
   python3 generate_device_specs.py
   ```
3. Rebuild the assembler:
   ```bash
   make -C build clean gnsasm
   ```

The new device will automatically be available in `.PROCESSOR` directives.

## Architecture Inference

The assembler automatically determines the architecture from the device name:

| Pattern | Architecture |
|---------|--------------|
| PIC10xxx, PIC12xxx | PIC12 |
| PIC16xxx | PIC16 |
| PIC18xxx, PICRFxxx | PIC18 |

This ensures the correct instruction set is used for the device.

## Troubleshooting

### "Device not found" error
- Check device name spelling (case-insensitive)
- Verify device has a corresponding `.cgen.inc` file in `device_includes/`

### Incorrect memory reported
- Device specs are estimated from device naming patterns
- Use `.PROCESSOR` directive to explicitly specify device

### Architecture mismatch
- Ensure PIC12 instructions are not used with PIC18 devices
- Use appropriate instruction set for target device

## Technical Details

Device specifications are stored as constexpr structures with:
- Device name (string)
- Program memory size (bytes)
- Data memory size (bytes)
- EEPROM size (bytes)
- Architecture enum (PIC12, PIC16, or PIC18)

All 874 device specifications are compiled directly into the assembler binary for O(1) lookup performance.

## Implementation Files

- `src/device_specs.h` - Device specifications (7000+ lines, auto-generated)
- `src/device_specs.cpp` - Device lookup functions (948 lines)
- `device_includes/*.cgen.inc` - Source device definitions (874 files)

---

**Last Updated**: 2025-11-29
**Total Devices**: 874

