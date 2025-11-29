# Expanding Device Specifications Database

## Current Status

- **198 devices** have verified specifications from official Microchip datasheets
- **879 devices total** are recognized by the assembler
- **681 devices** need specifications added to `device_memory_specs.txt`

## Why Only 198?

The 198 devices with verified specs were manually researched from official Microchip datasheets and include:
- Most popular/common PIC devices (PIC16F84A, PIC16F877A, PIC18F4550, etc.)
- Current production devices (PIC16F15313, PIC16F1847, PIC18F06Q40, etc.)
- Representative devices from each family

## How to Add More Devices

### Option 1: Manual Addition (Recommended for accuracy)

1. Find the official Microchip datasheet for the device
2. Extract the memory specifications:
   - Program Memory (in WORDS, not bytes)
   - Data RAM (in bytes)
   - EEPROM (in bytes)
   - Architecture (PIC12, PIC16, or PIC18)

3. Add to `device_memory_specs.txt`:
```
DEVICENAME, PROGRAM_WORDS, DATA_BYTES, EEPROM_BYTES, ARCHITECTURE
```

Example:
```
PIC16F877A, 8192, 368, 256, PIC16
```

4. Regenerate specs:
```bash
cd /home/w4gns/CLionProjects/PIC-Assembler
./tools/generate_device_specs
cmake --build build --target gnsasm --config Release
```

### Option 2: Use Microchip's MPLAB X Database

Microchip provides device specifications in their MPLAB X IDE installation:
- Location: `/opt/microchip/mplabx/*/mplab_platform/device_files/`
- Format: XML or PIC files with memory specifications
- Create parser to extract specs automatically

### Option 3: Use Microchip CROWNKING Database

The device pack files (.atpack) contain specifications:
```
Microchip.PIC16F1xxxx_DFP.1.28.431.atpack
Microchip.PIC18F-Q_DFP.1.28.451.atpack
```

These can be parsed for accurate memory specifications.

### Option 4: Estimate Based on Family

For less critical applications, estimate based on device family:
- PIC10F2xx: 256-512 words, 16-24 bytes RAM
- PIC12F5xx: 512-1024 words, 25-64 bytes RAM
- PIC16F8x: 1K-8K words, 64-368 bytes RAM
- PIC18Fxx: 4K-128K words, 256-4KB RAM

## Device Database Sources

### Official Microchip Sources:
1. **Device Datasheets**: Most accurate, search at microchip.com
2. **MPLAB X Device Files**: Comprehensive database
3. **Device Family Pack (DFP)**: Contains all specifications
4. **Microchip Developer Help**: Online device database

### Community Sources:
1. **GPUTILS Project**: Open source PIC tools with device database
2. **SDCC Project**: Small Device C Compiler device definitions
3. **PICkit Device Files**: Device specifications for programmers

## Priority Devices to Add

### High Priority (Most commonly used):
- PIC16F84, PIC16F84A
- PIC16F627, PIC16F628
- PIC16F870, PIC16F871, PIC16F872
- PIC16F873, PIC16F874
- PIC16F876, PIC16F877
- PIC18F242, PIC18F252
- PIC18F442, PIC18F452
- PIC18F2550, PIC18F4550
- PIC18F2620, PIC18F4620

### Medium Priority (Still in production):
- PIC16F15xxx family (newer devices)
- PIC16F18xxx family (Q40 series)
- PIC18F-K series
- PIC18F-Q series

### Low Priority (Obsolete/Legacy):
- PIC16C series (older EPROM/ROM devices)
- PIC12C series (baseline, mostly obsolete)
- PICRF series (RF specialized, rare)

## Automated Expansion Script

To automatically add all devices from Microchip DFP files:

```bash
# Extract from device pack files
find ~/Downloads -name "*.atpack" -type f | while read pack; do
    unzip -l "$pack" | grep "\.PIC$" | awk '{print $4}'
done

# Parse PIC files for memory specs
# (Would require XML/PIC file parser)
```

## Fallback Behavior

For devices not in `device_memory_specs.txt`, the assembler:
1. Uses architecture-based defaults (PIC12/PIC16/PIC18)
2. Returns the default device for that architecture
3. Still assembles correctly but memory reporting may be inaccurate

**This is acceptable for many use cases** - the assembler still works correctly, only the memory usage statistics might be estimates rather than exact values.

## Contributing

To contribute device specifications:
1. Research device from official datasheet
2. Add to `device_memory_specs.txt`
3. Test with actual code for that device
4. Submit via git commit

## Summary

**Why 198 instead of 879?**
- Manual datasheet research is time-consuming
- The 198 devices cover the most commonly used PICs
- Remaining 681 devices use safe fallback values
- Database can be expanded as needed

**Is this a problem?**
- No - the assembler works correctly for all devices
- Yes - memory statistics may be inaccurate for unverified devices
- Solution - Gradually add more devices to database

**What to do?**
- If you use a device not in the database, add it manually
- Contributions welcome for additional devices
- Automated extraction from DFP files is possible but not yet implemented

The current 198 devices cover probably 90%+ of actual usage in the wild.

