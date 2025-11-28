; Test DT directive - Define Table
    PROCESSOR PIC16F18076
    ORG 0x0000

; String table with null terminator
message_table:
    DT "Hello", 0x00

; Simple byte table
lookup_table:
    DT 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80

; Mixed hex/decimal
config_table:
    DT H'AA', H'BB', 100, 200

    END
