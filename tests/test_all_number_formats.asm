; Test ALL supported number formats
; All should equal 255 decimal (0xFF)

        ORG 0x0000

; === DECIMAL ===
        MOVLW 255           ; Plain decimal
        MOVLW D'255'        ; MPASM-style quoted decimal

; === HEXADECIMAL ===
        MOVLW 0xFF          ; 0x prefix (C-style)
        MOVLW FFh           ; h suffix (MPASM-style)
        MOVLW H'FF'         ; MPASM-style quoted hex

; === OCTAL ===
        MOVLW 0o377         ; 0o prefix (modern)
        MOVLW 377o          ; o suffix (MPASM-style)
        MOVLW O'377'        ; MPASM-style quoted octal

; === BINARY ===
        MOVLW 0b11111111    ; 0b prefix (C-style)
        MOVLW 11111111b     ; b suffix (MPASM-style)
        MOVLW B'11111111'   ; MPASM-style quoted binary

; Test with EQU
DEC_EQU    EQU D'100'
HEX_EQU    EQU H'64'
OCT_EQU    EQU O'144'
BIN_EQU    EQU B'01100100'

        MOVLW DEC_EQU       ; All should be 100 (0x64)
        MOVLW HEX_EQU
        MOVLW OCT_EQU
        MOVLW BIN_EQU

        END
