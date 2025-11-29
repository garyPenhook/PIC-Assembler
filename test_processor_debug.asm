; Test PIC18 processor detection via PROCESSOR directive - DEBUG version
.PROCESSOR 18F4520

        ORG 0x0000

; PIC18-specific instruction that would fail on PIC16
        MOVFF 0x00, 0x01    ; Move File to File (PIC18 only)

        END

