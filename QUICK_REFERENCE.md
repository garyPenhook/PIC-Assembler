# Quick Reference: .PROCESSOR Directive

## The Simplest Way to Use It

Add this one line at the top of your assembly file:

```asm
.PROCESSOR PIC16F15313

        ORG 0x0000
        ; your code here
```

That's it! The assembler automatically:
- ✓ Recognizes the device
- ✓ Sets the correct architecture (PIC12/PIC16/PIC18)
- ✓ Uses correct memory sizes
- ✓ Validates instructions for that device

## Common Examples

### PIC12 (Baseline)
```asm
.PROCESSOR PIC12F683
```

### PIC16 (Mid-Range) - Most Popular
```asm
.PROCESSOR PIC16F1847      ; Classic choice
.PROCESSOR PIC16F18076     ; Modern choice
.PROCESSOR PIC16F15313     ; Very recent
```

### PIC18 (Enhanced) - Powerful
```asm
.PROCESSOR PIC18F04Q40     ; Small Q40
.PROCESSOR PIC18F06Q40     ; Large Q40
.PROCESSOR PIC18F45K22     ; Classic K-series
```

## What Devices Are Supported?

**1,031 total devices** from these families:

- **PIC10Fxxx** - Baseline 12-bit (10 devices)
- **PIC12Fxxx** - Baseline 12-bit (55 devices)
- **PIC12Lxxx** - Low-power 12-bit (included in 55)
- **PIC16Fxxx** - Mid-range 14-bit (531 devices - all series)
- **PIC16Lxxx** - Low-power mid-range (included in 531)
- **PIC18Fxxx** - Enhanced 16-bit (405 devices - all series)
- **PIC18Lxxx** - Low-power enhanced (included in 405)
- **PICRFxxx** - RF-enabled (30 devices)

## Device Name Format

Use the exact device name from Microchip documentation:
- `PIC16F1847` ✓ Correct
- `pic16f1847` ✓ Also works (case-insensitive)
- `PIC16F` ✗ Too generic
- `16F1847` ✗ Missing PIC prefix

## Checking Memory

The assembler shows memory info after assembly:

```
Assembly Statistics:
  Device: PIC16F15313
  Program Memory: 4 bytes / 2048 bytes (0.20%)
  Data Memory: 0 bytes / 1024 bytes (0.00%)
  EEPROM: 0 bytes / 256 bytes (0.00%)
```

## If You Don't Specify

Without `.PROCESSOR`, the assembler uses:
- `-a pic12` → Defaults to PIC10F200
- `-a pic16` → Defaults to PIC16F1847
- `-a pic18` → Defaults to PIC18F06Q40

But you should always specify the exact device for your project!

## Need More Info?

- See `DEVICE_SUPPORT.md` for comprehensive device list
- See `README_DEVICES.md` for full documentation
- See `IMPLEMENTATION_SUMMARY.md` for technical details

---

**Total Devices Supported**: 1,031

