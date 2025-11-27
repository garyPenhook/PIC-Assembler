; Test program counter advancement with mixed DB/DW
    ORG 0x0100
    
    ; Single byte - should advance by 1 word (rounding up)
    DB 0x11
    
    ; Two bytes - should advance by 1 word
    DB 0x22, 0x23
    
    ; Three bytes - should advance by 2 words (rounding up)
    DB 0x31, 0x32, 0x33
    
    ; Four bytes - should advance by 2 words
    DB 0x41, 0x42, 0x43, 0x44
    
    ; Two word data - should advance by 2 words
    DW 0x5051, 0x5253
    
    END
