#pragma once

#include <cstdint>
#include <string>
#include <optional>
#include "instruction.h"

struct DeviceSpec {
    std::string name;
    uint32_t programMemoryBytes;  // ROM size in bytes
    uint32_t dataMemoryBytes;     // SRAM size in bytes
    uint32_t eepromBytes;         // EEPROM size in bytes
    Architecture architecture;
};

class DeviceSpecs {
public:
    // Get device spec by architecture (default device)
    static DeviceSpec getDeviceSpec(Architecture arch);

    // Get device spec by exact device name
    static std::optional<DeviceSpec> getDeviceSpecByName(const std::string& deviceName);

    // Get default device name for architecture
    static const char* getDefaultDeviceName(Architecture arch);

private:
    // PIC16F506 (Baseline): 512 bytes program memory, 96 bytes data SRAM, 0 bytes EEPROM
    static constexpr DeviceSpec PIC16F506_SPEC{
        "PIC16F506",
        512,     // 512 bytes program memory
        96,      // 96 bytes data SRAM
        0,       // 0 bytes EEPROM
        Architecture::PIC12
    };

    // PIC16F1847: 2 KB program memory, 1.5 KB data SRAM, 256 bytes EEPROM
    static constexpr DeviceSpec PIC16F1847_SPEC{
        "PIC16F1847",
        2048,    // 2KB program memory
        1520,    // 1.5KB data SRAM
        256,     // 256 bytes EEPROM
        Architecture::PIC16
    };

    // PIC18F04Q40: 16 KB program memory, 1.12 KB data SRAM, 512 bytes EEPROM
    static constexpr DeviceSpec PIC18F04Q40_SPEC{
        "PIC18F04Q40",
        16384,   // 16KB program memory
        1120,    // 1.12KB data SRAM
        512,     // 512 bytes EEPROM
        Architecture::PIC18
    };

    // PIC18F05Q40: 32 KB program memory, 2.1 KB data SRAM, 512 bytes EEPROM
    static constexpr DeviceSpec PIC18F05Q40_SPEC{
        "PIC18F05Q40",
        32768,   // 32KB program memory
        2144,    // 2.1KB data SRAM
        512,     // 512 bytes EEPROM
        Architecture::PIC18
    };

    // PIC18F06Q40: 64 KB program memory, 4.1 KB data SRAM, 512 bytes EEPROM
    static constexpr DeviceSpec PIC18F06Q40_SPEC{
        "PIC18F06Q40",
        65536,   // 64KB program memory
        4192,    // 4.1KB data SRAM
        512,     // 512 bytes EEPROM
        Architecture::PIC18
    };

    // PIC18F14Q40: 16 KB program memory, 1.12 KB data SRAM, 512 bytes EEPROM
    static constexpr DeviceSpec PIC18F14Q40_SPEC{
        "PIC18F14Q40",
        16384,   // 16KB program memory
        1120,    // 1.12KB data SRAM
        512,     // 512 bytes EEPROM
        Architecture::PIC18
    };

    // PIC18F15Q40: 32 KB program memory, 2.1 KB data SRAM, 512 bytes EEPROM
    static constexpr DeviceSpec PIC18F15Q40_SPEC{
        "PIC18F15Q40",
        32768,   // 32KB program memory
        2144,    // 2.1KB data SRAM
        512,     // 512 bytes EEPROM
        Architecture::PIC18
    };

    // PIC18F16Q40: 64 KB program memory, 4.1 KB data SRAM, 512 bytes EEPROM
    static constexpr DeviceSpec PIC18F16Q40_SPEC{
        "PIC18F16Q40",
        65536,   // 64KB program memory
        4192,    // 4.1KB data SRAM
        512,     // 512 bytes EEPROM
        Architecture::PIC18
    };
};
