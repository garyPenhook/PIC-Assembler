; Test #ifdef with #else and #elif preprocessor directives
    PROCESSOR PIC16F18076

#define PRODUCTION 1

    ORG 0x0000

; Test #ifdef/#else
#ifdef PRODUCTION
    MOVLW 0x10          ; Production build
    MOVWF 0x20
#else
    MOVLW 0x99          ; Debug build (should NOT appear)
    MOVWF 0x20
#endif

    NOP

; Test #ifndef/#else
#ifndef DEBUG
    MOVLW 0x20          ; No debug (should appear)
    MOVWF 0x21
#else
    MOVLW 0x88          ; Debug mode (should NOT appear)
    MOVWF 0x21
#endif

    NOP
    END
