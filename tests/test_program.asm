; Test program for PIC16F18076 Assembler
; Simple counter program

        ORG 0x0000

        MOVLW 0x00      ; Move 0 to W
        MOVWF 0x20      ; Store in file register 0x20

loop:   INCF 0x20,1     ; Increment register 0x20
        MOVF 0x20,0     ; Move to W
        SUBLW 0x0A      ; Subtract 10 from W
        BTFSS 0x03,2    ; Skip if zero flag set
        GOTO loop        ; Jump back to loop

        GOTO loop        ; End loop

        END
