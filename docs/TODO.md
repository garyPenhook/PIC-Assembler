# gnsasm Development TODO List

## ✅ Recently Completed Features

### Device Auto-Detection & PROCESSOR Directive (Latest Session)
- [x] Auto-detection of device from #include directives
  - Extract device name from `#include <pic16f18076.inc>` filename
  - Automatically set device memory specifications (program/data/EEPROM)
  - Infer architecture (PIC12/16/18) from device name
- [x] PROCESSOR directive implementation
  - `PROCESSOR deviceName` to explicitly set target device
  - Device memory specs automatically configured
  - Priority: PROCESSOR takes precedence over #include if both specified
  - Works with built-in device database (11 devices: PIC16F506, PIC12F629, PIC12F683, PIC16F1840, PIC16F1847, PIC16F18076, PIC16F877A, PIC18F04Q40, PIC18F05Q40, PIC18F06Q40, PIC18F14Q40, PIC18F15Q40, PIC18F16Q40)
- [x] Device memory specification tracking
  - Added currentDeviceSpec tracking to Assembler and Parser
  - Memory stats reflect actual selected device, not just architecture
  - Proper display of device name in assembly statistics

### Device Register Names & Listing Files
- [x] Symbolic device register names from .inc files
  - Load register definitions from Microchip device include files
  - Case-insensitive register name resolution (PORTA = porta = PortA)
  - Redefinition protection: device registers cannot be overridden
  - Device registers have highest priority in symbol lookup
  - Support for 1,748 device include files covering 2,903 devices
- [x] Listing file generation (`.lst` files)
  - Command-line option: `-l` / `--listing`
  - Assembly listing with source code and generated machine code
  - Symbol table with addresses
  - Memory usage statistics (program, data, EEPROM)
  - Assembly statistics (instruction count, address range)
  - Cross-reference between source and generated code

### Configuration Support
- [x] CONFIG directive parsing (numeric and symbolic values)
- [x] CONFIG word storage and management
- [x] Intel HEX output for CONFIG words at correct addresses
  - PIC12/16: 0x2007 (word address, 0x400E byte address)
  - PIC18: 0x300000 (byte address)
- [x] Symbolic CONFIG bit names (e.g., `_FOSC_INTOSC`)

### Number Format Support (11 Total Variations)
- [x] Decimal: `255`, `D'255'`
- [x] Hexadecimal: `0xFF`, `FFh`, `H'FF'`
- [x] Octal: `0o377`, `377o`, `O'377'`
- [x] Binary: `0b11111111`, `11111111b`, `B'11111111'`

### Symbol Table & Directives
- [x] EQU directive (fixed - was completely non-functional)
- [x] SET directive (reassignable constants)
- [x] RADIX directive (DEC/HEX/OCT/BIN base switching)
- [x] Symbol resolution in expressions
- [x] Separate storage for constants (EQU) vs variables (SET)

### Command-Line Interface
- [x] --devices option showing comprehensive device list
- [x] --verbose output mode
- [x] --help with detailed usage information
- [x] Architecture selection (-a pic16/pic18)

## 🔨 High Priority - Core Functionality

### Data Definition Directives
- [x] DB (Define Byte) - byte data in program memory
- [x] DW (Define Word) - word data in program memory
- [x] DA (Define ASCII) - ASCII string data
- [x] DT (Define Table) - retlw-based lookup tables
- [x] CBLOCK/ENDC - sequential constant block definitions
  ```asm
  CBLOCK 0x20
      var1        ; = 0x20
      var2        ; = 0x21
      var3:2      ; = 0x22-0x23 (reserve 2 bytes)
  ENDC
  ```

### Preprocessor Directives (#-directives from Microchip Standard)
- [x] #include - file inclusion with circular detection and path resolution
- [x] #define - text substitution macros (preprocessor-level)
- [x] #ifdef / #ifndef / #endif - conditional assembly
- [x] #if / #else / #elif - expression-based conditionals with macro expansion
- [x] #undef - remove macro definitions
- [x] Macro operators: # (stringify), ## (concatenation)
- [x] Variable argument lists: ... and __VA_ARGS__
- [ ] #line - specify source line numbers
- [ ] #error - generate error messages
- [ ] #warning - generate warning messages

### Code Organization (Assembly-Time Macros)
- [x] MACRO/ENDM - assembly-time macros with parameters
  ```asm
  DELAY MACRO cycles
      MOVLW cycles
      CALL delay_routine
  ENDM
  ```
- [x] LOCAL - local labels within macros
- [x] EXITM - exit from macro expansion

### Conditional Assembly (Assembly-Time)
- [x] IF / ELIF / ELSE / ENDIF - Expression-based conditionals
- [x] IFDEF / IFNDEF / ENDIF - Symbol-based conditionals
- [x] Full nesting support for conditional blocks
- [x] Conditional expression evaluation with symbol resolution

### Banking/Paging Support
- [x] BANKSEL - automatic bank selection (PIC16 via RP1:RP0, PIC18 via BSR)
- [x] PAGESEL - automatic page selection (PIC18 via PCLATH)
- [x] BANKISEL - bank selection for indirect addressing (PIC18 via BSR)

## 📋 Medium Priority - MPASM Compatibility

### Section Management
- [ ] UDATA - uninitialized data section
- [ ] UDATA_ACS - access RAM section (PIC18)
- [ ] UDATA_OVR - overlaid data section
- [ ] CODE - code section
- [ ] IDATA - initialized data section

### Multi-File Project Support
- [ ] GLOBAL - export symbols
- [ ] EXTERN - import symbols
- [ ] Linker script generation
- [ ] Relocatable object file output (.o)

### Listing & Documentation
- [ ] TITLE - set listing title
- [ ] SUBTITLE - set listing subtitle
- [ ] LIST/NOLIST - enable/disable listing output
- [ ] PAGE - force page break in listing
- [ ] SPACE - insert blank lines in listing
- [ ] MESSG - print message during assembly
- [ ] ERROR - generate assembly error
- [ ] WARNING - generate assembly warning

## 🎯 Low Priority - Advanced Features

### Additional Directives
- [ ] FILL - fill memory with pattern
- [ ] RES - reserve memory space
- [ ] \_\_IDLOCS - set ID locations
- [ ] \_\_MAXRAM/\_\_BADRAM - memory range definitions
- [x] PROCESSOR - set target processor (✅ Implemented!)
- [ ] VARIABLE - create variable (similar to SET)
- [ ] CONSTANT - create constant (similar to EQU)

### Expression Enhancements
- [x] Arithmetic operators: +, -, *, /, %
- [x] Bitwise operators: &, |, ^, ~, <<, >>
- [x] Logical operators: &&, ||, !
- [x] Comparison operators: ==, !=, <, >, <=, >=
- [x] HIGH/LOW/UPPER operators for address manipulation
- [ ] String expressions and concatenation

### Instruction Set Coverage Analysis

**Current Implementation Status:**
- **PIC10/12/16 Baseline:** 33 instructions ✅ (100% coverage)
- **PIC16 Enhanced Mid-range (F1xxx):** 35 of 49 instructions (71% coverage)
  - **Missing 14 instructions:** LSLF, LSRF, ASRF, ROTF, MOVIW, MOVWI, SWAPF enhancements, and others
- **PIC18 Base Instruction Set:** 75 instructions ✅ (100% coverage)
- **PIC18 Extended Instructions:** 83 instructions (8 additional optimization instructions not supported)
  - **Missing 8 instructions:** ADDFSR, ADDULNK, MOVLB enhancements, SUBFSR, and table operation extensions

**Microchip Instruction Set Sizes (Reference):**
| Architecture | Type | Count | Status |
|-------------|------|-------|--------|
| PIC10/12/16 | Baseline RISC | 33 | ✅ Complete |
| PIC16F1xxx | Enhanced Mid-range | 49 | ⚠️ Partial (35/49) |
| PIC18 | Base Set | 75 | ✅ Complete |
| PIC18 | Extended Set | 83 | ⚠️ Partial (75/83) |

### PIC18-Specific Instructions (Extended Set)
- [ ] Verify all PIC18 extended instruction encodings
- [ ] Complete PIC18 extended instruction support (8 remaining instructions)
- [ ] Add missing PIC16 enhanced mode instructions (14 remaining)
- [ ] Access RAM vs banked RAM handling

## 🐛 Known Issues & Improvements

### Parser Improvements
- [ ] Better error messages with context
- [ ] Error recovery (continue after first error)
- [ ] Multi-line instruction support (backslash continuation)
- [ ] Case sensitivity option (MPASM is case-insensitive)

### Symbol Table Enhancements
- [ ] Forward reference detection and warning
- [ ] Circular reference detection in EQU/SET
- [ ] Symbol redefinition warnings
- [ ] Symbol export/import for multi-file projects

### Code Quality
- [ ] Add comprehensive unit tests for all directives
- [ ] Add integration tests with real-world PIC programs
- [ ] Memory leak checking with valgrind
- [ ] Static analysis with clang-tidy

### Documentation
- [ ] Add examples for each directive
- [ ] Migration guide from MPASM
- [ ] Troubleshooting guide
- [ ] Performance benchmarks vs MPASM/gpasm

## 📊 Testing Coverage Gaps

### Current Test Files
- test_config.asm - CONFIG directive
- test_equ.asm - EQU directive
- test_set_directive.asm - SET directive
- test_radix_directive.asm - RADIX directive
- test_all_number_formats.asm - All 11 number formats

### Needed Test Coverage
- [ ] All PIC16 instruction encodings
- [ ] All PIC18 instruction encodings
- [ ] Banking scenarios (BSR manipulation)
- [ ] Paging scenarios (PCLATH manipulation)
- [ ] Symbol forward references
- [ ] Expression evaluation edge cases
- [ ] Error condition handling
- [ ] Large programs (>8KB flash)

## 🎓 Reference Documentation

### MPASM Directive Coverage
Currently supporting approximately **25+ of 50+ MPASM directives** (~50%)

**Implemented:**
- Symbol/Constants: ORG, END, EQU, SET, RADIX
- Configuration: CONFIG
- Data Definition: DB, DW, DA, DT, CBLOCK/ENDC
- Code Organization: MACRO/ENDM, LOCAL, EXITM
- File Handling: INCLUDE (partial)
- Directives: PROCESSOR (recognized but not validated)

**Not Implemented:**
- Preprocessor: #error, #warning, #line
- Conditionals (Assembly-Time): IF, IFDEF, IFNDEF, ELSE, ENDIF
- Sections: UDATA, UDATA_ACS, UDATA_OVR, CODE, IDATA
- Banking: BANKSEL, PAGESEL, BANKISEL
- Listing: LIST, NOLIST, TITLE, SUBTITLE, PAGE, SPACE, MESSG
- Linking: GLOBAL, EXTERN
- Memory Management: FILL, RES, __IDLOCS, __MAXRAM, __BADRAM

### External Resources
- [MPASM Assembler User's Guide](https://ww1.microchip.com/downloads/en/DeviceDoc/33014K.pdf)
- [PIC16F18076 Datasheet](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/PIC16-L-F18076-77-Data-Sheet-DS40002204.pdf)
- [PIC18 Instruction Set](https://onlinedocs.microchip.com/oxy/GUID-69213373-C79D-417B-BC91-9F27190FFCE4-en-US-12/GUID-D6E52EDF-DE99-4B2C-8C2A-3F899DE20E8A.html)

## 🚀 Next Steps (Recommended Priority Order)

**Recently Completed:**
- ✅ DB/DW/DA/DT directives
- ✅ CBLOCK/ENDC blocks
- ✅ MACRO/ENDM with LOCAL labels
- ✅ Expression evaluation (full arithmetic/logical operations)
- ✅ All preprocessor directives (#define, #ifdef/#ifndef/#endif, #if/#elif/#else, #include, #undef, function-like macros, macro operators)
- ✅ Assembly-time conditional directives (IF/IFDEF/IFNDEF/ELSE/ELIF/ENDIF with full nesting and expression evaluation)
- ✅ Device pack manager utility for extracting and managing Microchip device packs

**High Priority:**
1. **UDATA/CODE sections** - Proper section and memory management
2. **#error/#warning directives** - Preprocessor error/warning messages
3. **Device validation** - Check that used instructions/registers exist for selected device
4. **Multi-file project support** - GLOBAL/EXTERN directives for symbol export/import

**Medium Priority:**
6. **Listing directives** - TITLE, LIST/NOLIST, PAGE, MESSG
7. **Banking scenarios** - BSR register management
8. **Error recovery** - Better developer experience with error recovery

**Lower Priority:**
9. **Complete PIC16 enhanced instruction set** - Add missing 14 instructions for PIC16F1xxx
   - Missing: LSLF, LSRF, ASRF, ROTF, MOVIW, MOVWI, and 8 others
   - Currently: 35/49 instructions (71% coverage)

10. **Complete PIC18 extended instruction set** - Add missing 8 extended optimization instructions
    - Missing: ADDULNK, SUBFSR, and extended table operations
    - Currently: 75/83 instructions (90% coverage)
    - Note: These are mostly for C compiler optimization, rarely used in hand-written assembly

11. **Comprehensive testing** - Integration tests with real-world PIC programs

12. **Documentation** - Examples, migration guide from MPASM, troubleshooting

## 📝 Completion Summary

### Latest Session Accomplishments:

**This Session:**
- ✅ **Symbolic Device Register Names** - Load and use register names from .inc files
  - Implemented 6-phase feature: symbol table enhancement, preprocessor search paths, .inc parser, redefinition checks, case-insensitive lookup, test suite
  - Added device register category to symbol table with case-insensitive matching
  - Parser method: `loadDeviceRegistersFromFile()` for parsing .inc files with regex
  - Assembler pre-loading: scans source for #include directives before parsing
  - Preprocessor filtering: skips .inc files from output, directs assembler to handle them
  - Error protection: prevents redefinition of device registers via EQU/SET
  - Comprehensive test coverage: basic usage, case-insensitivity, redefinition errors, mixed symbols
- ✅ **Listing File Generation** - Generate detailed `.lst` files for assembly
  - Command-line option: `-l` or `--listing`
  - Assembly listing section: source code cross-referenced with machine code and addresses
  - Symbol table: labels with their memory addresses
  - Memory usage: program/data/EEPROM statistics with percentages
  - Assembly statistics: instruction count, address ranges, data items
  - Automatic filename: input.asm → input.lst
  - Integrated with existing build pipeline
- ✅ **Test Files** - Created comprehensive test suite for device registers
  - test_device_registers_basic.asm - Basic register loading
  - test_device_registers_case_insensitive.asm - Case variations
  - test_device_registers_redefinition_error.asm - Error handling
  - test_device_registers_mixed_symbols.asm - Integration with user symbols
  - test_device_registers_comprehensive.asm - All features combined
  - test_listing_demo.asm - Listing file demonstration

**Previous Sessions:**
- ✅ **CBLOCK/ENDC** - Sequential constant block allocation with optional size specifiers
- ✅ **DT (Define Table)** - RETLW-based lookup tables supporting strings and numeric values
- ✅ **MACRO/ENDM** - Full macro support with parameters, LOCAL labels, and EXITM
- ✅ **Preprocessor Phase 1-5** - Complete text-level preprocessing (#define, #ifdef/#ifndef/#endif, #if/#elif/#else, #include with circular detection, function-like macros with # and ## operators)
- ✅ **Assembly-Time Conditionals** - IF/IFDEF/IFNDEF/ELIF/ELSE/ENDIF with expression evaluation and full nesting support
- ✅ **Device Pack Manager** - Python utility to scan, extract, and catalog Microchip device packs (1,748 .inc files extracted from 9 device packs covering 2,903 devices)
- ✅ **Symbol Table Enhancement** - Added getAllSymbols() method for expression evaluation support
- ✅ **BANKSEL/PAGESEL/BANKISEL** - Automatic banking and paging directives:
  - PIC16 BANKSEL: Generates BCF/BSF instructions to set RP1:RP0 bits in STATUS register
  - PIC18 BANKSEL: Generates MOVLW/MOVWF instructions to set BSR register
  - PIC18 PAGESEL: Generates MOVLW/MOVWF instructions to set PCLATH register
  - Forward reference handling for multi-pass assembly
- ✅ **Test Coverage** - Created comprehensive test files (test_banksel_pic16.asm, test_banksel_pic18.asm, test_pagesel_pic18.asm)
- ✅ **Documentation** - Updated TODO.md with completed BANKSEL/PAGESEL status

### Implementation Details:
- All data definition directives now fully functional (DB, DW, DA, DT)
- Macro system supports nested expansion with 100-level depth limit
- LOCAL labels auto-generated with ??L format and auto-incrementing counter
- Two-pass assembly correctly handles all macro expansion scenarios
- Expression evaluation supports all standard operators
- Preprocessor runs as text-level transformation before lexer with macro expansion in conditionals
- File inclusion with circular reference detection using absolute path tracking
- Macro operators (stringify # and concatenation ##) fully functional

### Feature Gap Analysis:
The main gaps preventing 100% MPASM compatibility are:
1. **Section management** - UDATA, CODE, IDATA sections for proper memory layout
2. **Multi-file linking** - GLOBAL/EXTERN for symbol export/import across object files
3. **Device validation** - Verify selected device supports all used instructions/registers
4. **Preprocessor error/warning** - #error and #warning directives
5. **Advanced listing directives** - TITLE, LIST/NOLIST, PAGE, MESSG for listing control

### Completed Features (Last 2 Sessions):
- ✅ **Symbolic register names** - Support for device register names from .inc files
- ✅ **Listing file generation** - Detailed assembly listings with cross-references
- ✅ **Banking/Paging helpers** - BANKSEL, PAGESEL, BANKISEL directives implemented
