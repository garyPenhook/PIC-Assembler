# gnsasm Development TODO List

## ✅ Recently Completed Features

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
- [ ] BANKSEL - automatic bank selection
- [ ] PAGESEL - automatic page selection
- [ ] BANKISEL - bank selection for indirect addressing

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
- [ ] PROCESSOR - set target processor
- [ ] VARIABLE - create variable (similar to SET)
- [ ] CONSTANT - create constant (similar to EQU)

### Expression Enhancements
- [x] Arithmetic operators: +, -, *, /, %
- [x] Bitwise operators: &, |, ^, ~, <<, >>
- [x] Logical operators: &&, ||, !
- [x] Comparison operators: ==, !=, <, >, <=, >=
- [x] HIGH/LOW/UPPER operators for address manipulation
- [ ] String expressions and concatenation

### PIC18-Specific Instructions
- [ ] Verify all PIC18 extended instruction encodings
- [ ] Extended instruction set support (ADDFSR, ADDULNK, etc.)
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
1. **BANKSEL/PAGESEL** - Automatic banking (high value for users)
2. **UDATA/CODE sections** - Proper section and memory management
3. **#error/#warning directives** - Preprocessor error/warning messages
4. **Device validation** - Check that used instructions/registers exist for selected device
5. **Multi-file project support** - GLOBAL/EXTERN directives for symbol export/import

**Medium Priority:**
6. **Listing directives** - TITLE, LIST/NOLIST, PAGE, MESSG
7. **Banking scenarios** - BSR register management
8. **Error recovery** - Better developer experience with error recovery

**Lower Priority:**
9. **PIC18 extended instructions** - Verify all extended instruction encodings
10. **Comprehensive testing** - Integration tests with real-world PIC programs
11. **Documentation** - Examples, migration guide from MPASM, troubleshooting

## 📝 Completion Summary

### Latest Session Accomplishments:
- ✅ **CBLOCK/ENDC** - Sequential constant block allocation with optional size specifiers
- ✅ **DT (Define Table)** - RETLW-based lookup tables supporting strings and numeric values
- ✅ **MACRO/ENDM** - Full macro support with parameters, LOCAL labels, and EXITM
- ✅ **Preprocessor Phase 1-5** - Complete text-level preprocessing (#define, #ifdef/#ifndef/#endif, #if/#elif/#else, #include with circular detection, function-like macros with # and ## operators)
- ✅ **Assembly-Time Conditionals** - IF/IFDEF/IFNDEF/ELIF/ELSE/ENDIF with expression evaluation and full nesting support
- ✅ **Device Pack Manager** - Python utility to scan, extract, and catalog Microchip device packs (1,748 .inc files extracted from 9 device packs covering 2,903 devices)
- ✅ **Symbol Table Enhancement** - Added getAllSymbols() method for expression evaluation support
- ✅ **Test Coverage** - Created comprehensive test files for all features (5 test files for conditionals)
- ✅ **Documentation** - Updated TODO.md with detailed feature status

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
2. **Banking/Paging helpers** - BANKSEL, PAGESEL directives for automatic register management
3. **Multi-file linking** - GLOBAL/EXTERN for symbol export/import across object files
4. **Device validation** - Verify selected device supports all used instructions/registers
5. **Preprocessor error/warning** - #error and #warning directives
