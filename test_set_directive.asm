; Test SET directive (reassignable constants)

; EQU creates constants (cannot be changed)
CONST_VAL EQU 0x10

; SET creates variables (can be reassigned)
counter SET 0           ; Initialize to 0
counter SET 1           ; Reassign to 1
counter SET 2           ; Reassign to 2
counter SET 3           ; Reassign to 3

; Use in code
        ORG 0x0000
        MOVLW counter       ; Should be 3
        MOVWF 0x20

; Test multiple reassignments
offset SET 0x100
offset SET 0x110        ; Reassign
offset SET 0x120        ; Reassign again

        MOVLW 0x01          ; High byte manually
        MOVWF 0x21

; Comparison: EQU vs SET
; CONST_VAL EQU 0x20    ; This would error if we tried to reassign
var SET 0x30            ; Can be assigned
var SET 0x40            ; Can be reassigned (this is the difference!)

        MOVLW var
        MOVWF 0x22

        END
