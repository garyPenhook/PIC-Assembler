#pragma once

#include <cstdint>
#include <string>
#include "instruction.h"

struct DeviceSpec {
    std::string name;
    uint32_t programMemoryBytes;  // ROM size in bytes
    uint32_t dataMemoryBytes;     // RAM size in bytes
    Architecture architecture;
};

class DeviceSpecs {
public:
    static DeviceSpec getDeviceSpec(Architecture arch);
    static const char* getDeviceName(Architecture arch);

private:
    // PIC16F18076: 28 KB program memory, 2 KB data SRAM
    static constexpr DeviceSpec PIC16F18076_SPEC{
        "PIC16F18076",
        28672,   // 28KB program memory
        2048,    // 2KB data SRAM
        Architecture::PIC16
    };

    // PIC18-Q40: 64K program memory, 4K RAM
    static constexpr DeviceSpec PIC18Q40_SPEC{
        "PIC18-Q40",
        65536,   // 64KB program memory
        4096,    // 4KB data memory
        Architecture::PIC18
    };
};
