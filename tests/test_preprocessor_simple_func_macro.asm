; Test simple function-like macros with parameter substitution
    PROCESSOR PIC16F18076

; Define a simple parameterized macro with straightforward substitution
#define LOAD(val) MOVLW val
#define STORE(reg) MOVWF reg
#define OP(a, b) ADDWF b

    ORG 0x0000

    ; Use the function-like macros
    LOAD(0x42)          ; Expands to MOVLW 0x42
    STORE(0x20)         ; Expands to MOVWF 0x20

    LOAD(0x10)
    STORE(0x21)

    NOP
    END
