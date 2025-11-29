# C++23 Optimization Plan for PIC Assembler

## Key Optimization Opportunities

### 1. Bitwise Operations
- **Instruction Encoding**: Use bitwise shifts and masks instead of arithmetic
- **Architecture Flags**: Use bit flags instead of enum comparisons
- **Opcode Manipulation**: Direct bit manipulation for opcode construction
- **Token Type Checking**: Use bitfields for fast token type identification

### 2. Pointer & Memory Optimizations
- **String View Usage**: Replace `const std::string&` with `std::string_view` (C++17/20/23)
- **Reserve Vector Capacity**: Pre-allocate vectors to avoid reallocations
- **Move Semantics**: Use `std::move` for large object transfers
- **Small String Optimization**: Use stack-allocated buffers for short strings
- **Span Usage**: Use `std::span` (C++20) for array/vector views

### 3. C++23 Specific Features
- **std::expected**: Replace exceptions with std::expected for performance
- **constexpr**: More compile-time evaluation
- **Multidimensional subscript operator**: For lookup tables
- **Deducing this**: Reduce code duplication in CRTP patterns

### 4. Specific Optimizations

#### A. Instruction Type Encoding (use bitfields)
```cpp
// Instead of enum, use bit flags
constexpr uint32_t INSTR_BYTE_ORIENTED = 0x0001;
constexpr uint32_t INSTR_BIT_ORIENTED  = 0x0002;
constexpr uint32_t INSTR_LITERAL       = 0x0004;
constexpr uint32_t ARCH_PIC12          = 0x0100;
constexpr uint32_t ARCH_PIC16          = 0x0200;
constexpr uint32_t ARCH_PIC18          = 0x0400;

// Fast architecture check
inline bool supportsArch(uint32_t instrFlags, Architecture arch) {
    return (instrFlags & (static_cast<uint32_t>(arch) << 8)) != 0;
}
```

#### B. Opcode Construction with Bitwise Ops
```cpp
// Build opcode using shifts and OR instead of arithmetic
inline uint16_t buildByteOriented(uint8_t opcode, uint8_t file, uint8_t dest) {
    return (static_cast<uint16_t>(opcode) << 8) | 
           (static_cast<uint16_t>(file) << 1) | 
           (dest & 0x01);
}

inline uint16_t buildBitOriented(uint8_t opcode, uint8_t file, uint8_t bit) {
    return (static_cast<uint16_t>(opcode) << 10) | 
           (static_cast<uint16_t>(bit & 0x07) << 7) | 
           (file & 0x7F);
}
```

#### C. String View for Zero-Copy
```cpp
// Change function signatures
std::optional<DeviceSpec> getDeviceSpecByName(std::string_view deviceName);
bool parseNumber(std::string_view text, uint32_t& result);
```

#### D. Reserve Vector Capacity
```cpp
tokens.reserve(estimated_token_count);  // Avoid reallocations
generatedCode.reserve(instruction_count_estimate);
```

#### E. Lookup Table Optimization
```cpp
// Use perfect hash or switch instead of std::map
constexpr auto mnemonicLookup(std::string_view mnemonic) -> InstructionType {
    // Use constexpr hash map or binary search
    switch (hash(mnemonic)) {
        case hash("ADDWF"): return InstructionType::ADDWF;
        case hash("ANDWF"): return InstructionType::ANDWF;
        // ...
    }
}
```

## Implementation Priority

1. **High Impact** (Implement First):
   - Bitwise opcode construction
   - String_view for parsing functions
   - Vector capacity reservation
   - Instruction flag bitfields

2. **Medium Impact**:
   - Replace std::map with faster alternatives
   - Move semantics in assembly pipeline
   - Constexpr lookup tables

3. **Low Impact** (Future):
   - std::expected for error handling
   - Memory pools for tokens
   - SIMD for bulk operations

## Expected Performance Gains

- **Opcode Construction**: 2-3x faster (bit ops vs arithmetic)
- **String Parsing**: 20-40% faster (string_view, no copies)
- **Vector Operations**: 30-50% faster (pre-allocation)
- **Lookup Tables**: 2-5x faster (bitfields vs map lookups)
- **Overall**: Estimated 40-60% faster assembly time

## Measurements

Before optimization (672KB executable):
- Assembly time: TBD
- Memory usage: TBD

Target after optimization:
- Assembly time: 40-60% reduction
- Memory usage: 20-30% reduction
- Executable size: Similar or smaller (constexpr evaluations)

