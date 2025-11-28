; PIC16F18076 - Simple Counter
; Increments register 0x20 and compares with 10
.NOLIST
#include <PIC1847.inc>
.LIST
        ORG 0x0000

start:  MOVLW 0x00      ; Initialize W
        MOVWF 0x20      ; Store in file register 0x20
        MOVLW 0x01      ; Load immediate value

loop:   INCF 0x20,1     ; Increment register
        MOVF 0x20,0     ; Move to W
        SUBLW 0x0A      ; Subtract 10 from W
        BTFSS 0x03,2    ; Skip if zero flag set
        GOTO loop       ; Jump back to loop

        GOTO loop       ; Infinite loop
        END
