; Test error handling in listing file
; This file has an intentional error

    ORG 0x00

    MOVLW 0xFF
    UNKNOWN_INSTRUCTION_HERE    ; This will cause an error
    NOP

    END
