; Test RADIX directive

        ORG 0x0000

; Default is decimal
        MOVLW 255           ; Decimal 255

; Switch to hexadecimal
        RADIX HEX
        MOVLW FF            ; Hex FF (255 decimal)
        MOVLW AB            ; Hex AB (171 decimal)

; Switch to octal
        RADIX OCT
        MOVLW 377           ; Octal 377 (255 decimal)
        MOVLW 253           ; Octal 253 (171 decimal)

; Switch back to decimal
        RADIX DEC
        MOVLW 255           ; Decimal 255
        MOVLW 171           ; Decimal 171

; Prefixed numbers still work regardless of RADIX
        RADIX HEX
        MOVLW 0xFF          ; Explicit hex prefix
        MOVLW 0o377         ; Explicit octal prefix
        MOVLW 0b11111111    ; Explicit binary prefix
        MOVLW 255           ; Bare number in current radix (hex) = 0x255

        RADIX DEC
        END
