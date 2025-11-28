; Test function-like macros with parameters and operators
    PROCESSOR PIC16F18076

; Define a simple function-like macro
#define MAX(a, b) ((a) > (b) ? (a) : (b))

; Define a macro that uses ## concatenation
#define REG_READ(reg) read_##reg

; Define a macro that uses # stringification
#define MSG(msg) "Message: " msg

; Define a simple parameterized macro
#define SET_REG(reg, val) MOVLW val ; MOVWF reg

    ORG 0x0000

; Test simple function-like macro
#define SWAP(a, b) \
    MOVF a, W ; \
    XORWF b, F ; \
    XORWF a, F ; \
    XORWF b, F

    SWAP(0x20, 0x21)      ; Expand the macro with register arguments

    NOP
    END
