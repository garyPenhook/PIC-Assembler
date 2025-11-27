#include "device_specs.h"

DeviceSpec DeviceSpecs::getDeviceSpec(Architecture arch) {
    switch (arch) {
        case Architecture::PIC16:
            return PIC16F18076_SPEC;
        case Architecture::PIC18:
            return PIC18Q40_SPEC;
    }
    return PIC16F18076_SPEC;  // Default fallback
}

const char* DeviceSpecs::getDeviceName(Architecture arch) {
    switch (arch) {
        case Architecture::PIC16:
            return "PIC16F18076";
        case Architecture::PIC18:
            return "PIC18-Q40";
    }
    return "Unknown";
}
