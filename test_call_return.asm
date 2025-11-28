; Test CALL and RETURN
        ORG 0x0000
start:
        CALL delay
        GOTO start

delay:
        NOP
        RETURN
        END
