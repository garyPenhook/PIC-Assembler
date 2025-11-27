#include "device_specs.h"

DeviceSpec DeviceSpecs::getDeviceSpec(Architecture arch) {
    switch (arch) {
        case Architecture::PIC16:
            return PIC16F1847_SPEC;
        case Architecture::PIC18:
            return PIC18F06Q40_SPEC;  // Use largest Q40 variant as default
    }
    return PIC16F1847_SPEC;  // Default fallback
}

std::optional<DeviceSpec> DeviceSpecs::getDeviceSpecByName(const std::string& deviceName) {
    if (deviceName == "PIC16F1847") return PIC16F1847_SPEC;

    if (deviceName == "PIC18F04Q40") return PIC18F04Q40_SPEC;
    if (deviceName == "PIC18F05Q40") return PIC18F05Q40_SPEC;
    if (deviceName == "PIC18F06Q40") return PIC18F06Q40_SPEC;
    if (deviceName == "PIC18F14Q40") return PIC18F14Q40_SPEC;
    if (deviceName == "PIC18F15Q40") return PIC18F15Q40_SPEC;
    if (deviceName == "PIC18F16Q40") return PIC18F16Q40_SPEC;

    // Handle legacy generic names
    if (deviceName == "PIC18-Q40" || deviceName == "PIC18F-Q40") {
        return PIC18F06Q40_SPEC;  // Default to largest variant
    }

    return std::nullopt;
}

const char* DeviceSpecs::getDefaultDeviceName(Architecture arch) {
    switch (arch) {
        case Architecture::PIC16:
            return "PIC16F1847";
        case Architecture::PIC18:
            return "PIC18F06Q40";
    }
    return "Unknown";
}
