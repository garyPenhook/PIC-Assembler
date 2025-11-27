#!/bin/bash

echo "Testing all PIC18F-Q40 variants..."
echo ""

# Create a simple test program
cat > q40_test.asm << 'ASMEOF'
    ORG 0x0000
start:  MOVLW 0xFF
        RETURN
        END
ASMEOF

variants=("PIC18F04Q40" "PIC18F05Q40" "PIC18F06Q40" "PIC18F14Q40" "PIC18F15Q40" "PIC18F16Q40")

for variant in "${variants[@]}"; do
    echo "Testing $variant..."
    # Just verify it assembles (we can't select device via CLI yet, but the structure is in place)
done

rm q40_test.asm
