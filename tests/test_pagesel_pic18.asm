    ; Test PAGESEL directive for PIC18
    PROCESSOR PIC18F57Q43

    ORG 0x0000

    ; Call a routine in page 0
    PAGESEL ROUTINE_PAGE0
    CALL ROUTINE_PAGE0
    NOP

    ; Call a routine in page 1 (address > 0x800)
    PAGESEL ROUTINE_PAGE1
    CALL ROUTINE_PAGE1
    NOP

    ; Routine in page 0
    ORG 0x0100
    ROUTINE_PAGE0:
        MOVLW 0x10
        RETURN

    ; Routine in page 1 (beyond 2KB boundary)
    ORG 0x0900
    ROUTINE_PAGE1:
        MOVLW 0x20
        RETURN

    END
