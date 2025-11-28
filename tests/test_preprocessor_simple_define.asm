; Test simple #define preprocessor directives - literal values only
    PROCESSOR PIC16F18076

; Define some literal constants
#define VAL1 42
#define VAL2 0xFF
#define VAL3 100

; Use the defines with explicit literals
    ORG 0x0000
    MOVLW VAL1          ; Should expand to MOVLW 42
    NOP
    MOVLW VAL2          ; Should expand to MOVLW 0xFF
    NOP
    MOVLW VAL3          ; Should expand to MOVLW 100
    NOP

    ; Test with mathematical expressions
#define OFFSET 10
    MOVLW OFFSET
    NOP

    ; Undefine and redefine
#undef VAL1
#define VAL1 200

    MOVLW VAL1          ; Should expand to MOVLW 200
    NOP

    END
