; Test all supported number formats

; Decimal (255)
DEC_VAL     EQU 255

; Hexadecimal (255)
HEX_PREFIX  EQU 0xFF        ; 0x prefix
HEX_SUFFIX  EQU FFh         ; h suffix (MPASM style)

; Octal (377 = 255 decimal)
OCT_PREFIX  EQU 0o377       ; 0o prefix
OCT_SUFFIX  EQU 377o        ; o suffix (MPASM style)

; Binary (11111111 = 255 decimal)
BIN_PREFIX  EQU 0b11111111  ; 0b prefix
BIN_SUFFIX  EQU 11111111b   ; b suffix (MPASM style)

        ORG 0x0000

; Test decimal
        MOVLW 255
        MOVLW DEC_VAL

; Test hexadecimal
        MOVLW 0xFF          ; 0x prefix style
        MOVLW FFh           ; h suffix style
        MOVLW HEX_PREFIX
        MOVLW HEX_SUFFIX

; Test octal
        MOVLW 0o377         ; 0o prefix style
        MOVLW 377o          ; o suffix style
        MOVLW OCT_PREFIX
        MOVLW OCT_SUFFIX

; Test binary
        MOVLW 0b11111111    ; 0b prefix style
        MOVLW 11111111b     ; b suffix style
        MOVLW BIN_PREFIX
        MOVLW BIN_SUFFIX

        END
