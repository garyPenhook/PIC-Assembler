#include "device_specs.h"
#include <algorithm>
#include <cctype>
DeviceSpec DeviceSpecs::getDeviceSpec(Architecture arch) {
    switch (arch) {
        case Architecture::PIC12:
            return PIC10F200_SPEC;
        case Architecture::PIC16:
            return PIC16F1847_SPEC;
        case Architecture::PIC18:
            return PIC18F06Q40_SPEC;
    }
    return PIC16F1847_SPEC;
}
std::optional<DeviceSpec> DeviceSpecs::getDeviceSpecByName(std::string_view deviceName) {
    // Minimal device lookup - only essential devices
    // TODO: Regenerate from device packs for full device support
    if (deviceName == "PIC10F200") return PIC10F200_SPEC;
    if (deviceName == "PIC16F15313") return PIC16F15313_SPEC;
    if (deviceName == "PIC16F15323") return PIC16F15323_SPEC;
    if (deviceName == "PIC16F1847") return PIC16F1847_SPEC;
    if (deviceName == "PIC18F06Q40") return PIC18F06Q40_SPEC;
    return std::nullopt;  // Device not found
}
const char* DeviceSpecs::getDefaultDeviceName(Architecture arch) {
    switch (arch) {
        case Architecture::PIC12:
            return "PIC10F200";
        case Architecture::PIC16:
            return "PIC16F1847";
        case Architecture::PIC18:
            return "PIC18F06Q40";
    }
    return "PIC16F1847";
}
std::string DeviceSpecs::extractDeviceNameFromIncFile(std::string_view filename) {
    std::string name(filename);
    // Remove .inc extension
    if (name.size() > 4 && name.substr(name.size() - 4) == ".inc") {
        name = name.substr(0, name.size() - 4);
    }
    // Convert to uppercase
    std::transform(name.begin(), name.end(), name.begin(), ::toupper);
    return name;
}
std::optional<Architecture> DeviceSpecs::inferArchitectureFromDeviceName(std::string_view deviceName) {
    if (deviceName.empty()) {
        return std::nullopt;
    }
    // Check prefix
    if (deviceName.size() >= 5) {
        std::string prefix(deviceName.substr(0, 5));
        std::transform(prefix.begin(), prefix.end(), prefix.begin(), ::toupper);
        if (prefix == "PIC18") {
            return Architecture::PIC18;
        } else if (prefix == "PIC16") {
            return Architecture::PIC16;
        } else if (prefix == "PIC12" || prefix == "PIC10") {
            return Architecture::PIC12;
        }
    }
    return std::nullopt;
}
