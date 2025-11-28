; Test #if, #elif, #else preprocessor directives with expressions
    PROCESSOR PIC16F18076

#define VERSION 2
#define DEBUG_LEVEL 3
#define OPTIMIZATION 1

    ORG 0x0000

; Test #if with numeric comparison
#if VERSION == 2
    MOVLW 0x20          ; VERSION is 2 (should appear)
    MOVWF 0x20
#endif

    NOP

; Test #if with arithmetic
#if DEBUG_LEVEL > 2
    MOVLW 0x30          ; DEBUG_LEVEL > 2 is true (should appear)
    MOVWF 0x21
#endif

    NOP

; Test #if/#elif/#else chain
#if VERSION == 1
    MOVLW 0x01          ; VERSION == 1 (should NOT appear)
#elif VERSION == 2
    MOVLW 0x02          ; VERSION == 2 (should appear)
    MOVWF 0x22
#else
    MOVLW 0x99          ; Should NOT appear
#endif

    NOP

; Test #if with logical operators
#if DEBUG_LEVEL > 0 && OPTIMIZATION == 1
    MOVLW 0x40          ; Both conditions true (should appear)
    MOVWF 0x23
#endif

    END
