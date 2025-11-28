; Test MACRO/ENDM directives
    PROCESSOR PIC16F18076

; Basic macro with parameters
DELAY MACRO cycles
    MOVLW cycles
    MOVWF 0x20
    CALL delay_routine
ENDM

; Macro with LOCAL labels
COMPARE MACRO reg1, reg2
    LOCAL not_equal, done
    MOVF reg1, 0       ; Move to W
    SUBWF reg2, 1      ; Subtract W from reg2
    BTFSS 0x03, 2      ; Test Zero flag
    GOTO not_equal
    ; equal code
    GOTO done
not_equal:
    ; not equal code
done:
    NOP
ENDM

; Simple nested macro
INIT_REG MACRO reg
    MOVLW 0x00
    MOVWF reg
ENDM

CLEAR_ALL MACRO r1, r2, r3
    INIT_REG r1
    INIT_REG r2
    INIT_REG r3
ENDM

; Test usage
    ORG 0x0000
    DELAY 10
    COMPARE 0x20, 0x21
    CLEAR_ALL 0x30, 0x31, 0x32

delay_routine:
    RETURN

    END
