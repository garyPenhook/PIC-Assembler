    ; Test mixed assembly-time conditionals with real code
    PROCESSOR PIC16F18076

    ; Feature flags
    HAVE_UART EQU 1
    HAVE_TIMER EQU 0
    OPTIMIZE_SIZE EQU 1

    ORG 0x0000

    ; Setup routine
    IFDEF HAVE_UART
        ; Initialize UART
        MOVLW 0x80
        MOVWF 0x25        ; UART control register
    ENDIF

    IFDEF HAVE_TIMER
        MOVLW 0x40
        MOVWF 0x26        ; Timer control register
    ELSE
        ; If no timer, use delay routine
        MOVLW 0x00
        MOVWF 0x26
    ENDIF

    ; Conditional code optimization
    IF 1!=0
        ; Use compact form
        MOVLW 0x55
        MOVWF 0x20
        MOVWF 0x21
        MOVWF 0x22
    ELSE
        ; Unroll for speed
        MOVLW 0x55
        MOVWF 0x20
        MOVLW 0x55
        MOVWF 0x21
        MOVLW 0x55
        MOVWF 0x22
    ENDIF

    ; Main loop placeholder
    MAIN:
        INCF 0x20
        GOTO MAIN

    END
