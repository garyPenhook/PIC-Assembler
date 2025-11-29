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
    static std::optional<DeviceSpec> getDeviceSpecByName(std::string_view deviceName);

    // Get default device name for architecture
    static const char* getDefaultDeviceName(Architecture arch);

    // Extract device name from #include filename (e.g., "pic16f1840.inc" → "PIC16F1840")
    static std::string extractDeviceNameFromIncFile(std::string_view filename);

    // Infer architecture from device name (e.g., "PIC16F1840" → PIC16)
    static std::optional<Architecture> inferArchitectureFromDeviceName(std::string_view deviceName);

private:
    // ===== AUTO-GENERATED DEVICE SPECIFICATIONS =====
    // This section contains all supported PIC microcontroller devices
    // Device specifications are in device_specs_generated.h
    // Total: 874 devices (PIC12, PIC16, PIC18)
    // DO NOT EDIT - specs are generated from official Microchip data

#include "../device_specs_generated.h"

};
