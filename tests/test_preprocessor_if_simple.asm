; Test simple #if expressions
    PROCESSOR PIC16F18076

#define VERSION 2

    ORG 0x0000

; Test #if with simple literal comparison
#if 2 == 2
    MOVLW 0x10          ; 2 == 2 is true (should appear)
    MOVWF 0x20
#endif

    NOP

; Test #if with arithmetic
#if 3 > 2
    MOVLW 0x20          ; 3 > 2 is true (should appear)
    MOVWF 0x21
#endif

    NOP

; Test #if with logical operators
#if 1 && 1
    MOVLW 0x30          ; 1 && 1 is true (should appear)
    MOVWF 0x22
#endif

    END
