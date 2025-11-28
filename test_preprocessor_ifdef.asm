; Test #ifdef, #ifndef, and #endif preprocessor directives
    PROCESSOR PIC16F18076

; Define some symbols
#define DEBUG 1
#define RELEASE 0

    ORG 0x0000

; Test #ifdef - code should be included if DEBUG is defined
#ifdef DEBUG
    MOVLW 0x01          ; Debug version
    MOVWF 0x20
#endif

; Test #ifndef - code should be included if symbol is NOT defined
#ifndef NDEBUG
    NOP                 ; Debug enabled (no NDEBUG defined)
#endif

; Test #ifdef with undefined symbol - code should NOT be included
#ifdef UNDEFINED_SYMBOL
    MOVLW 0xFF          ; This should NOT appear in output
    MOVWF 0x21
#endif

; Test basic conditional nesting
#ifdef DEBUG
    MOVLW 0x42
#ifndef RELEASE
    MOVWF 0x22          ; Should appear (DEBUG is defined AND RELEASE is not)
#endif
#endif

; Test #ifdef block exclusion
#ifdef ANOTHER_UNDEFINED
    MOVLW 0xAA          ; Should NOT appear
    MOVWF 0x23
    NOP
#endif

    NOP
    END
