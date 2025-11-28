; Test dot-prefixed directives
.NOLIST
.LIST

        ORG 0x0000

start:  MOVLW 0x00
        MOVWF 0x20

loop:   INCF 0x20,1
        GOTO loop

        END
