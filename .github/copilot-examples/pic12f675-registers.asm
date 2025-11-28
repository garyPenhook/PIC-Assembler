; ============================================
; PIC12F675 Register Definitions
; Architecture: PIC12 (12-bit baseline instructions)
; Assemble with: gnsasm file.asm -a pic12
; ============================================
; One of the most popular PIC12 baseline devices
; 8-pin microcontroller with 1KB program memory

; ============================================
; Core Registers
; ============================================
INDF        EQU 0x00    ; Indirect addressing
TMR0        EQU 0x01    ; Timer 0 counter
PCL         EQU 0x02    ; Program counter low byte
STATUS      EQU 0x03    ; Status register
FSR         EQU 0x04    ; File select register for indirect addressing
GPIO        EQU 0x05    ; General purpose I/O (6 bits: GP0-GP5)
PCLATH      EQU 0x0A    ; Program counter latch high

; Bank 1 registers (access via BSF STATUS, RP0)
OPTION_REG  EQU 0x81    ; Option register
TRISIO      EQU 0x85    ; GPIO tri-state control (1=input, 0=output)

; ============================================
; STATUS Register Bit Definitions (0x03)
; ============================================
C           EQU 0       ; Carry/borrow flag
DC          EQU 1       ; Digit carry/borrow flag
Z           EQU 2       ; Zero flag
PD          EQU 3       ; Power-down flag
TO          EQU 4       ; Time-out flag
RP0         EQU 5       ; Register bank select bit
GPWUF       EQU 7       ; GPIO wakeup flag

; ============================================
; GPIO Pin Definitions
; ============================================
; PIC12F675 has 6 I/O pins (GP0-GP5)
GP0         EQU 0       ; GPIO bit 0 (pin 7)
GP1         EQU 1       ; GPIO bit 1 (pin 6)
GP2         EQU 2       ; GPIO bit 2 (pin 5)
GP3         EQU 3       ; GPIO bit 3 (pin 4, input only)
GP4         EQU 4       ; GPIO bit 4 (pin 3)
GP5         EQU 5       ; GPIO bit 5 (pin 2)

; ============================================
; Peripheral Registers
; ============================================
; Comparator module
CMCON       EQU 0x19    ; Comparator control
VRCON       EQU 0x99    ; Voltage reference control (Bank 1)

; Analog to Digital (ADC)
ADRESH      EQU 0x1E    ; ADC result high byte
ADRESL      EQU 0x9E    ; ADC result low byte (Bank 1)
ANSEL       EQU 0x9F    ; Analog select register (Bank 1)
ADCON0      EQU 0x1F    ; ADC control register 0

; Interrupts
INTCON      EQU 0x0B    ; Interrupt control
PIR1        EQU 0x0C    ; Peripheral interrupt flags
PIE1        EQU 0x8C    ; Peripheral interrupt enable (Bank 1)

; EEPROM Data Memory
EEDATA      EQU 0x9A    ; EEPROM data register (Bank 1)
EEADR       EQU 0x9B    ; EEPROM address register (Bank 1)
EECON1      EQU 0x9C    ; EEPROM control register 1 (Bank 1)
EECON2      EQU 0x9D    ; EEPROM control register 2 (Bank 1)

; ============================================
; Common User Variables Area
; ============================================
; General purpose RAM: 0x20-0x5F (64 bytes)
VAR_START   EQU 0x20    ; Start of general purpose RAM
COUNTER     EQU 0x20    ; Example: 8-bit counter
TEMP        EQU 0x21    ; Example: temporary storage
FLAGS       EQU 0x22    ; Example: flag byte
DELAY_L     EQU 0x23    ; Example: delay counter low
DELAY_H     EQU 0x24    ; Example: delay counter high

; ============================================
; Example Usage Patterns for PIC12F675
; ============================================

; Initialize GPIO (switch to Bank 1)
;       BSF STATUS, RP0      ; Select Bank 1
;       MOVLW 0x07           ; Disable comparators (all digital I/O)
;       MOVWF CMCON^0x80     ; CMCON is at 0x19, in bank 1 it's 0x99
;       MOVLW 0x00           ; All outputs (GP3 is always input)
;       MOVWF TRISIO         ; Configure GPIO direction
;       BCF STATUS, RP0      ; Back to Bank 0

; Write to GPIO
;       MOVLW 0x01           ; Turn on GP0
;       MOVWF GPIO           ; Output to GPIO

; Set/clear individual GPIO bits
;       BSF GPIO, GP0        ; Set GP0 high (pin 7)
;       BCF GPIO, GP1        ; Clear GP1 low (pin 6)

; Toggle GPIO bit
;       MOVLW 1<<GP0         ; Bit 0 mask
;       XORWF GPIO, 1        ; Toggle GP0

; Read input (GP3 is input-only)
;       BTFSC GPIO, GP3      ; Test GP3, skip if clear
;       GOTO input_high      ; GP3 is high

; Simple delay (12-bit instruction PIC12)
;       MOVLW 0xFF
;       MOVWF DELAY_L
; loop: DECFSZ DELAY_L, 1
;       GOTO loop

; Disable comparators for digital I/O (IMPORTANT!)
;       BSF STATUS, RP0      ; Bank 1
;       MOVLW 0x07           ; CM2:CM0 = 111 (comparators off)
;       MOVWF CMCON^0x80     ; CMCON in bank 1
;       BCF STATUS, RP0      ; Bank 0

; Configure ADC
;       BSF STATUS, RP0      ; Bank 1
;       MOVLW 0x01           ; AN0 is analog, rest digital
;       MOVWF ANSEL          ; Configure analog inputs
;       BCF STATUS, RP0      ; Bank 0
;       MOVLW 0x81           ; Turn on ADC, select AN0
;       MOVWF ADCON0

; Start ADC conversion
;       BSF ADCON0, 1        ; Start conversion (GO bit)
; wait: BTFSC ADCON0, 1      ; Wait for completion
;       GOTO wait
;       ; Result in ADRESH:ADRESL

; ============================================
; PIC12F675 Pinout Reference
; ============================================
; Pin 1: VDD (+5V)
; Pin 2: GP5/T1CKI/OSC1/CLKIN
; Pin 3: GP4/AN3/T1G/OSC2/CLKOUT
; Pin 4: GP3/MCLR/VPP (input only)
; Pin 5: GP2/AN2/T0CKI/INT/COUT
; Pin 6: GP1/AN1/CIN-/VREF/ICSPCLK
; Pin 7: GP0/AN0/CIN+/ICSPDAT
; Pin 8: VSS (Ground)

; ============================================
; Important Notes for PIC12F675
; ============================================
; 1. GP3 is INPUT ONLY - cannot be configured as output
; 2. Comparators are ON by default - disable with CMCON = 0x07
; 3. Some pins have analog functions - disable with ANSEL = 0x00
; 4. Only 64 bytes of RAM (0x20-0x5F)
; 5. 1024 words of program memory (0x000-0x3FF)
; 6. Internal 4MHz oscillator available
