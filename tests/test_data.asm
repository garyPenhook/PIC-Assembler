; Test program with DB/DW data directives
    ORG 0x0000

    ; Simple instructions
    MOVLW 0x42
    MOVWF 0x20

    ; Data definitions
    ORG 0x0010
    DB 0xAA, 0xBB, 0xCC, 0xDD

    ; Word data
    DW 0x1234, 0x5678

    END
