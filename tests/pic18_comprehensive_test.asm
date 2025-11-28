; PIC18 Comprehensive Instruction Set Test
; Tests all major PIC18-specific instruction categories

        ORG 0x0000

; === Additional Byte-Oriented Operations ===
start:  DCFSNZ 0x20,1   ; Decrement, Skip if Not Zero
        INFSNZ 0x21,1   ; Increment, Skip if Not Zero
        RLCF   0x22,1   ; Rotate Left through Carry
        RLNCF  0x23,1   ; Rotate Left No Carry
        RRCF   0x24,1   ; Rotate Right through Carry
        RRNCF  0x25,1   ; Rotate Right No Carry
        SUBFWB 0x26,1   ; Subtract W from F, Borrow
        SUBWFB 0x27,1   ; Subtract F from W, Borrow
        TSTFSZ 0x28     ; Test F, Skip if Zero

; === Compare & Skip ===
        CPFSEQ 0x29     ; Compare F with W, Skip if Equal
        CPFSGT 0x2A     ; Compare F with W, Skip if Greater
        CPFSLT 0x2B     ; Compare F with W, Skip if Less

; === Conditional Branches ===
        BC  start       ; Branch if Carry
        BZ  start       ; Branch if Zero
        BN  start       ; Branch if Negative
        BOV start       ; Branch if Overflow
        BNC start       ; Branch if Not Carry
        BNZ start       ; Branch if Not Zero
        BNN start       ; Branch if Not Negative
        BNOV start      ; Branch if Not Overflow
        BRA start       ; Unconditional Branch

; === Stack & Control Operations ===
        PUSH            ; Push Top of Stack
        POP             ; Pop Stack
        CALLW           ; Call using W register

; === FSR Operations ===
        MOVLB 0x01      ; Move Literal to BSR (Bank Select Register)
        LFSR 0, 0x0100  ; Load FSR (File Select Register)
        ADDFSR 0, 0x10  ; Add to FSR
        SUBFSR 0, 0x05  ; Subtract from FSR

; === Multiplication ===
        MULLW 0x55      ; Multiply Literal with W

; === Table Operations ===
        TBLRD *+        ; Table Read (post-increment)
        TBLWT *         ; Table Write

; === Other Inherent ===
        DAW             ; Decimal Adjust W

        END
