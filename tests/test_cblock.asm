; Test CBLOCK/ENDC directives
    PROCESSOR PIC16F18076

; Basic CBLOCK
CBLOCK 0x20
    counter         ; = 0x20
    temp1           ; = 0x21
    temp2           ; = 0x22
ENDC

; CBLOCK with size specifiers
CBLOCK 0x30
    buffer:16       ; = 0x30-0x3F (16 bytes)
    flags           ; = 0x40
ENDC

; Continuing CBLOCK (starts from where last one left off)
CBLOCK
    status_save     ; = 0x41
    w_save          ; = 0x42
ENDC

; Use the defined constants in code
    ORG 0x0000
    MOVLW 0x00
    MOVWF counter
    MOVWF temp1
    INCF counter, 1      ; 1 = destination is file register (F)
    MOVF buffer, 0       ; 0 = destination is W
    MOVWF flags
    MOVWF status_save

    END
