; Test #define and #undef preprocessor directives
    PROCESSOR PIC16F18076

; Define some constants
#define VALUE1 42
#define VALUE2 0xFF
#define MESSAGE "Hello"

; Use the defines
    ORG 0x0000
    MOVLW VALUE1        ; Should expand to MOVLW 42
    MOVWF 0x20

    MOVLW VALUE2        ; Should expand to MOVLW 0xFF
    MOVWF 0x21

    ; Define a register name
#define REG_A 0x20
#define REG_B 0x21

    MOVF REG_A, W       ; Should expand to MOVF 0x20, W
    ADDWF REG_B, W      ; Should expand to ADDWF 0x21, W

    ; Undefine VALUE1 and redefine with new value
#undef VALUE1
#define VALUE1 100

    MOVLW VALUE1        ; Should expand to MOVLW 100
    MOVWF 0x22

    ; Test multiple expansions on one line
    MOVF REG_A, W
    SUBWF REG_B, W

    NOP
    END
