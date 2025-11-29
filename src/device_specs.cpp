#include "device_specs.h"
#include <algorithm>
#include <cctype>

DeviceSpec DeviceSpecs::getDeviceSpec(Architecture arch) {
    switch (arch) {
        case Architecture::PIC12:
            return PIC16F506_SPEC;
        case Architecture::PIC16:
            return PIC16F1847_SPEC;
        case Architecture::PIC18:
            return PIC18F06Q40_SPEC;  // Use largest Q40 variant as default
    }
    return PIC16F1847_SPEC;  // Default fallback
}

std::optional<DeviceSpec> DeviceSpecs::getDeviceSpecByName(const std::string& deviceName) {
    // PIC12 devices
    if (deviceName == "PIC16F506") return PIC16F506_SPEC;
    if (deviceName == "PIC12F629") return PIC12F629_SPEC;
    if (deviceName == "PIC12F683") return PIC12F683_SPEC;

    // PIC16 devices
    if (deviceName == "PIC16F1840") return PIC16F1840_SPEC;
    if (deviceName == "PIC16F1847") return PIC16F1847_SPEC;
    if (deviceName == "PIC16F18076") return PIC16F18076_SPEC;
    if (deviceName == "PIC16F877A") return PIC16F877A_SPEC;

    // PIC18 devices
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
        case Architecture::PIC12:
            return "PIC16F506";
        case Architecture::PIC16:
            return "PIC16F1847";
        case Architecture::PIC18:
            return "PIC18F06Q40";
    }
    return "Unknown";
}

std::string DeviceSpecs::extractDeviceNameFromIncFile(const std::string& filename) {
    // Extract device name from filename like "pic16f1840.cgen.inc" or "16f1840.inc"
    // Returns uppercase device name like "PIC16F1840"

    std::string name = filename;

    // Remove .cgen.inc or .inc extension
    size_t pos = name.find_last_of('.');
    while (pos != std::string::npos) {
        name = name.substr(0, pos);
        pos = name.find_last_of('.');
    }

    // Convert to uppercase and add PIC prefix if missing
    for (char& c : name) {
        c = std::toupper(static_cast<unsigned char>(c));
    }

    // Add PIC prefix if not present
    if (name.find("PIC") != 0) {
        name = "PIC" + name;
    }

    return name;
}

std::optional<Architecture> DeviceSpecs::inferArchitectureFromDeviceName(const std::string& deviceName) {
    // Infer architecture from device name
    // PIC12: starts with "PIC1" (except PIC16/PIC18)
    // PIC16: starts with "PIC16"
    // PIC18: starts with "PIC18"

    if (deviceName.find("PIC18") == 0) {
        return Architecture::PIC18;
    } else if (deviceName.find("PIC16") == 0) {
        return Architecture::PIC16;
    } else if (deviceName.find("PIC10") == 0 || deviceName.find("PIC12") == 0) {
        return Architecture::PIC12;
    }

    return std::nullopt;
}
