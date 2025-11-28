; Comprehensive EQU test
; Test various EQU features

; Define constants
PORTA       EQU 0x05
PORTB       EQU 0x06
TRISA       EQU 0x85
STATUS      EQU 0x03
Z_FLAG      EQU 2

; Constants referencing other constants
PORT_COPY   EQU PORTA     ; Reference to another EQU

; Hex values
LED_ON      EQU 0xFF
LED_OFF     EQU 0x00

; Binary values
PATTERN     EQU 0b10101010

        ORG 0x0000
start:
        ; Use EQU constants in instructions
        MOVLW LED_ON
        MOVWF PORTA
        MOVWF PORTB

        ; Use in bit operations
        BSF   STATUS, Z_FLAG
        BCF   STATUS, Z_FLAG

        ; Test with PATTERN
        MOVLW PATTERN
        MOVWF PORT_COPY

        GOTO start
        END
