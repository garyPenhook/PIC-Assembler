; Demonstration of helpful error messages
        MOVWF 0x20
        INCCF 0x20,1    ; Typo: INCCF should be INCF
        ADDWX 10        ; Typo: ADDWX should be ADDWF or ADDLW
        NOP
        END
