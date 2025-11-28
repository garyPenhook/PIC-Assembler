; Included header file with common definitions
#define REG_A 0x20
#define REG_B 0x21
#define REG_C 0x22

; Define a common macro pattern
#define SET_BANK(bank_num) MOVLW bank_num
