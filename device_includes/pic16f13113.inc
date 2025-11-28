// Generated 30/10/2025 GMT

/*
 * Copyright (c) 2025 Microchip Technology Inc. and its subsidiaries.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _PIC16F13113_INC_
#define _PIC16F13113_INC_

/*
 * Assembly Header file for the Microchip PIC Microcontroller
 * PIC16F13113
 */

/*
 * Device Registers
 */

// Register: INDF0
#define INDF0 INDF0
INDF0                                    equ 0000h
// bitfield definitions
INDF0_INDF0_POSN                         equ 0000h
INDF0_INDF0_POSITION                     equ 0000h
INDF0_INDF0_SIZE                         equ 0008h
INDF0_INDF0_LENGTH                       equ 0008h
INDF0_INDF0_MASK                         equ 00FFh

// Register: INDF1
#define INDF1 INDF1
INDF1                                    equ 0001h
// bitfield definitions
INDF1_INDF1_POSN                         equ 0000h
INDF1_INDF1_POSITION                     equ 0000h
INDF1_INDF1_SIZE                         equ 0008h
INDF1_INDF1_LENGTH                       equ 0008h
INDF1_INDF1_MASK                         equ 00FFh

// Register: PCL
#define PCL PCL
PCL                                      equ 0002h
// bitfield definitions
PCL_PCL_POSN                             equ 0000h
PCL_PCL_POSITION                         equ 0000h
PCL_PCL_SIZE                             equ 0008h
PCL_PCL_LENGTH                           equ 0008h
PCL_PCL_MASK                             equ 00FFh

// Register: STATUS
#define STATUS STATUS
STATUS                                   equ 0003h
// bitfield definitions
STATUS_C_POSN                            equ 0000h
STATUS_C_POSITION                        equ 0000h
STATUS_C_SIZE                            equ 0001h
STATUS_C_LENGTH                          equ 0001h
STATUS_C_MASK                            equ 0001h
STATUS_DC_POSN                           equ 0001h
STATUS_DC_POSITION                       equ 0001h
STATUS_DC_SIZE                           equ 0001h
STATUS_DC_LENGTH                         equ 0001h
STATUS_DC_MASK                           equ 0002h
STATUS_Z_POSN                            equ 0002h
STATUS_Z_POSITION                        equ 0002h
STATUS_Z_SIZE                            equ 0001h
STATUS_Z_LENGTH                          equ 0001h
STATUS_Z_MASK                            equ 0004h
STATUS_nPD_POSN                          equ 0003h
STATUS_nPD_POSITION                      equ 0003h
STATUS_nPD_SIZE                          equ 0001h
STATUS_nPD_LENGTH                        equ 0001h
STATUS_nPD_MASK                          equ 0008h
STATUS_nTO_POSN                          equ 0004h
STATUS_nTO_POSITION                      equ 0004h
STATUS_nTO_SIZE                          equ 0001h
STATUS_nTO_LENGTH                        equ 0001h
STATUS_nTO_MASK                          equ 0010h
STATUS_CARRY_POSN                        equ 0000h
STATUS_CARRY_POSITION                    equ 0000h
STATUS_CARRY_SIZE                        equ 0001h
STATUS_CARRY_LENGTH                      equ 0001h
STATUS_CARRY_MASK                        equ 0001h
STATUS_ZERO_POSN                         equ 0002h
STATUS_ZERO_POSITION                     equ 0002h
STATUS_ZERO_SIZE                         equ 0001h
STATUS_ZERO_LENGTH                       equ 0001h
STATUS_ZERO_MASK                         equ 0004h

// Register: FSR0L
#define FSR0L FSR0L
FSR0L                                    equ 0004h
// bitfield definitions
FSR0L_FSR0L_POSN                         equ 0000h
FSR0L_FSR0L_POSITION                     equ 0000h
FSR0L_FSR0L_SIZE                         equ 0008h
FSR0L_FSR0L_LENGTH                       equ 0008h
FSR0L_FSR0L_MASK                         equ 00FFh

// Register: FSR0H
#define FSR0H FSR0H
FSR0H                                    equ 0005h
// bitfield definitions
FSR0H_FSR0H_POSN                         equ 0000h
FSR0H_FSR0H_POSITION                     equ 0000h
FSR0H_FSR0H_SIZE                         equ 0008h
FSR0H_FSR0H_LENGTH                       equ 0008h
FSR0H_FSR0H_MASK                         equ 00FFh

// Register: FSR1L
#define FSR1L FSR1L
FSR1L                                    equ 0006h
// bitfield definitions
FSR1L_FSR1L_POSN                         equ 0000h
FSR1L_FSR1L_POSITION                     equ 0000h
FSR1L_FSR1L_SIZE                         equ 0008h
FSR1L_FSR1L_LENGTH                       equ 0008h
FSR1L_FSR1L_MASK                         equ 00FFh

// Register: FSR1H
#define FSR1H FSR1H
FSR1H                                    equ 0007h
// bitfield definitions
FSR1H_FSR1H_POSN                         equ 0000h
FSR1H_FSR1H_POSITION                     equ 0000h
FSR1H_FSR1H_SIZE                         equ 0008h
FSR1H_FSR1H_LENGTH                       equ 0008h
FSR1H_FSR1H_MASK                         equ 00FFh

// Register: BSR
#define BSR BSR
BSR                                      equ 0008h
// bitfield definitions
BSR_BSR_POSN                             equ 0000h
BSR_BSR_POSITION                         equ 0000h
BSR_BSR_SIZE                             equ 0006h
BSR_BSR_LENGTH                           equ 0006h
BSR_BSR_MASK                             equ 003Fh
BSR_BSR0_POSN                            equ 0000h
BSR_BSR0_POSITION                        equ 0000h
BSR_BSR0_SIZE                            equ 0001h
BSR_BSR0_LENGTH                          equ 0001h
BSR_BSR0_MASK                            equ 0001h
BSR_BSR1_POSN                            equ 0001h
BSR_BSR1_POSITION                        equ 0001h
BSR_BSR1_SIZE                            equ 0001h
BSR_BSR1_LENGTH                          equ 0001h
BSR_BSR1_MASK                            equ 0002h
BSR_BSR2_POSN                            equ 0002h
BSR_BSR2_POSITION                        equ 0002h
BSR_BSR2_SIZE                            equ 0001h
BSR_BSR2_LENGTH                          equ 0001h
BSR_BSR2_MASK                            equ 0004h
BSR_BSR3_POSN                            equ 0003h
BSR_BSR3_POSITION                        equ 0003h
BSR_BSR3_SIZE                            equ 0001h
BSR_BSR3_LENGTH                          equ 0001h
BSR_BSR3_MASK                            equ 0008h
BSR_BSR4_POSN                            equ 0004h
BSR_BSR4_POSITION                        equ 0004h
BSR_BSR4_SIZE                            equ 0001h
BSR_BSR4_LENGTH                          equ 0001h
BSR_BSR4_MASK                            equ 0010h
BSR_BSR5_POSN                            equ 0005h
BSR_BSR5_POSITION                        equ 0005h
BSR_BSR5_SIZE                            equ 0001h
BSR_BSR5_LENGTH                          equ 0001h
BSR_BSR5_MASK                            equ 0020h

// Register: WREG
#define WREG WREG
WREG                                     equ 0009h
// bitfield definitions
WREG_WREG0_POSN                          equ 0000h
WREG_WREG0_POSITION                      equ 0000h
WREG_WREG0_SIZE                          equ 0008h
WREG_WREG0_LENGTH                        equ 0008h
WREG_WREG0_MASK                          equ 00FFh

// Register: PCLATH
#define PCLATH PCLATH
PCLATH                                   equ 000Ah
// bitfield definitions
PCLATH_PCLATH_POSN                       equ 0000h
PCLATH_PCLATH_POSITION                   equ 0000h
PCLATH_PCLATH_SIZE                       equ 0007h
PCLATH_PCLATH_LENGTH                     equ 0007h
PCLATH_PCLATH_MASK                       equ 007Fh

// Register: INTCON
#define INTCON INTCON
INTCON                                   equ 000Bh
// bitfield definitions
INTCON_INTEDG_POSN                       equ 0000h
INTCON_INTEDG_POSITION                   equ 0000h
INTCON_INTEDG_SIZE                       equ 0001h
INTCON_INTEDG_LENGTH                     equ 0001h
INTCON_INTEDG_MASK                       equ 0001h
INTCON_PEIE_POSN                         equ 0006h
INTCON_PEIE_POSITION                     equ 0006h
INTCON_PEIE_SIZE                         equ 0001h
INTCON_PEIE_LENGTH                       equ 0001h
INTCON_PEIE_MASK                         equ 0040h
INTCON_GIE_POSN                          equ 0007h
INTCON_GIE_POSITION                      equ 0007h
INTCON_GIE_SIZE                          equ 0001h
INTCON_GIE_LENGTH                        equ 0001h
INTCON_GIE_MASK                          equ 0080h

// Register: PORTA
#define PORTA PORTA
PORTA                                    equ 000Ch
// bitfield definitions
PORTA_RA0_POSN                           equ 0000h
PORTA_RA0_POSITION                       equ 0000h
PORTA_RA0_SIZE                           equ 0001h
PORTA_RA0_LENGTH                         equ 0001h
PORTA_RA0_MASK                           equ 0001h
PORTA_RA1_POSN                           equ 0001h
PORTA_RA1_POSITION                       equ 0001h
PORTA_RA1_SIZE                           equ 0001h
PORTA_RA1_LENGTH                         equ 0001h
PORTA_RA1_MASK                           equ 0002h
PORTA_RA2_POSN                           equ 0002h
PORTA_RA2_POSITION                       equ 0002h
PORTA_RA2_SIZE                           equ 0001h
PORTA_RA2_LENGTH                         equ 0001h
PORTA_RA2_MASK                           equ 0004h
PORTA_RA3_POSN                           equ 0003h
PORTA_RA3_POSITION                       equ 0003h
PORTA_RA3_SIZE                           equ 0001h
PORTA_RA3_LENGTH                         equ 0001h
PORTA_RA3_MASK                           equ 0008h
PORTA_RA4_POSN                           equ 0004h
PORTA_RA4_POSITION                       equ 0004h
PORTA_RA4_SIZE                           equ 0001h
PORTA_RA4_LENGTH                         equ 0001h
PORTA_RA4_MASK                           equ 0010h
PORTA_RA5_POSN                           equ 0005h
PORTA_RA5_POSITION                       equ 0005h
PORTA_RA5_SIZE                           equ 0001h
PORTA_RA5_LENGTH                         equ 0001h
PORTA_RA5_MASK                           equ 0020h

// Register: TRISA
#define TRISA TRISA
TRISA                                    equ 0012h
// bitfield definitions
TRISA_TRISA0_POSN                        equ 0000h
TRISA_TRISA0_POSITION                    equ 0000h
TRISA_TRISA0_SIZE                        equ 0001h
TRISA_TRISA0_LENGTH                      equ 0001h
TRISA_TRISA0_MASK                        equ 0001h
TRISA_TRISA1_POSN                        equ 0001h
TRISA_TRISA1_POSITION                    equ 0001h
TRISA_TRISA1_SIZE                        equ 0001h
TRISA_TRISA1_LENGTH                      equ 0001h
TRISA_TRISA1_MASK                        equ 0002h
TRISA_TRISA2_POSN                        equ 0002h
TRISA_TRISA2_POSITION                    equ 0002h
TRISA_TRISA2_SIZE                        equ 0001h
TRISA_TRISA2_LENGTH                      equ 0001h
TRISA_TRISA2_MASK                        equ 0004h
TRISA_TRISA4_POSN                        equ 0004h
TRISA_TRISA4_POSITION                    equ 0004h
TRISA_TRISA4_SIZE                        equ 0001h
TRISA_TRISA4_LENGTH                      equ 0001h
TRISA_TRISA4_MASK                        equ 0010h
TRISA_TRISA5_POSN                        equ 0005h
TRISA_TRISA5_POSITION                    equ 0005h
TRISA_TRISA5_SIZE                        equ 0001h
TRISA_TRISA5_LENGTH                      equ 0001h
TRISA_TRISA5_MASK                        equ 0020h

// Register: LATA
#define LATA LATA
LATA                                     equ 0018h
// bitfield definitions
LATA_LATA0_POSN                          equ 0000h
LATA_LATA0_POSITION                      equ 0000h
LATA_LATA0_SIZE                          equ 0001h
LATA_LATA0_LENGTH                        equ 0001h
LATA_LATA0_MASK                          equ 0001h
LATA_LATA1_POSN                          equ 0001h
LATA_LATA1_POSITION                      equ 0001h
LATA_LATA1_SIZE                          equ 0001h
LATA_LATA1_LENGTH                        equ 0001h
LATA_LATA1_MASK                          equ 0002h
LATA_LATA2_POSN                          equ 0002h
LATA_LATA2_POSITION                      equ 0002h
LATA_LATA2_SIZE                          equ 0001h
LATA_LATA2_LENGTH                        equ 0001h
LATA_LATA2_MASK                          equ 0004h
LATA_LATA4_POSN                          equ 0004h
LATA_LATA4_POSITION                      equ 0004h
LATA_LATA4_SIZE                          equ 0001h
LATA_LATA4_LENGTH                        equ 0001h
LATA_LATA4_MASK                          equ 0010h
LATA_LATA5_POSN                          equ 0005h
LATA_LATA5_POSITION                      equ 0005h
LATA_LATA5_SIZE                          equ 0001h
LATA_LATA5_LENGTH                        equ 0001h
LATA_LATA5_MASK                          equ 0020h

// Register: PIR0
#define PIR0 PIR0
PIR0                                     equ 008Ch
// bitfield definitions
PIR0_INTF_POSN                           equ 0000h
PIR0_INTF_POSITION                       equ 0000h
PIR0_INTF_SIZE                           equ 0001h
PIR0_INTF_LENGTH                         equ 0001h
PIR0_INTF_MASK                           equ 0001h
PIR0_IOCIF_POSN                          equ 0004h
PIR0_IOCIF_POSITION                      equ 0004h
PIR0_IOCIF_SIZE                          equ 0001h
PIR0_IOCIF_LENGTH                        equ 0001h
PIR0_IOCIF_MASK                          equ 0010h
PIR0_TMR0IF_POSN                         equ 0005h
PIR0_TMR0IF_POSITION                     equ 0005h
PIR0_TMR0IF_SIZE                         equ 0001h
PIR0_TMR0IF_LENGTH                       equ 0001h
PIR0_TMR0IF_MASK                         equ 0020h

// Register: PIR1
#define PIR1 PIR1
PIR1                                     equ 008Dh
// bitfield definitions
PIR1_NVMIF_POSN                          equ 0000h
PIR1_NVMIF_POSITION                      equ 0000h
PIR1_NVMIF_SIZE                          equ 0001h
PIR1_NVMIF_LENGTH                        equ 0001h
PIR1_NVMIF_MASK                          equ 0001h
PIR1_CRCIF_POSN                          equ 0001h
PIR1_CRCIF_POSITION                      equ 0001h
PIR1_CRCIF_SIZE                          equ 0001h
PIR1_CRCIF_LENGTH                        equ 0001h
PIR1_CRCIF_MASK                          equ 0002h
PIR1_SCANIF_POSN                         equ 0002h
PIR1_SCANIF_POSITION                     equ 0002h
PIR1_SCANIF_SIZE                         equ 0001h
PIR1_SCANIF_LENGTH                       equ 0001h
PIR1_SCANIF_MASK                         equ 0004h
PIR1_CSWIF_POSN                          equ 0004h
PIR1_CSWIF_POSITION                      equ 0004h
PIR1_CSWIF_SIZE                          equ 0001h
PIR1_CSWIF_LENGTH                        equ 0001h
PIR1_CSWIF_MASK                          equ 0010h
PIR1_OSFIF_POSN                          equ 0005h
PIR1_OSFIF_POSITION                      equ 0005h
PIR1_OSFIF_SIZE                          equ 0001h
PIR1_OSFIF_LENGTH                        equ 0001h
PIR1_OSFIF_MASK                          equ 0020h
PIR1_TMR1IF_POSN                         equ 0006h
PIR1_TMR1IF_POSITION                     equ 0006h
PIR1_TMR1IF_SIZE                         equ 0001h
PIR1_TMR1IF_LENGTH                       equ 0001h
PIR1_TMR1IF_MASK                         equ 0040h
PIR1_TMR1GIF_POSN                        equ 0007h
PIR1_TMR1GIF_POSITION                    equ 0007h
PIR1_TMR1GIF_SIZE                        equ 0001h
PIR1_TMR1GIF_LENGTH                      equ 0001h
PIR1_TMR1GIF_MASK                        equ 0080h

// Register: PIR2
#define PIR2 PIR2
PIR2                                     equ 008Eh
// bitfield definitions
PIR2_TMR2IF_POSN                         equ 0002h
PIR2_TMR2IF_POSITION                     equ 0002h
PIR2_TMR2IF_SIZE                         equ 0001h
PIR2_TMR2IF_LENGTH                       equ 0001h
PIR2_TMR2IF_MASK                         equ 0004h
PIR2_CCP1IF_POSN                         equ 0005h
PIR2_CCP1IF_POSITION                     equ 0005h
PIR2_CCP1IF_SIZE                         equ 0001h
PIR2_CCP1IF_LENGTH                       equ 0001h
PIR2_CCP1IF_MASK                         equ 0020h
PIR2_CCP2IF_POSN                         equ 0006h
PIR2_CCP2IF_POSITION                     equ 0006h
PIR2_CCP2IF_SIZE                         equ 0001h
PIR2_CCP2IF_LENGTH                       equ 0001h
PIR2_CCP2IF_MASK                         equ 0040h

// Register: PIR3
#define PIR3 PIR3
PIR3                                     equ 008Fh

// Register: PIR4
#define PIR4 PIR4
PIR4                                     equ 0090h
// bitfield definitions
PIR4_CLC1IF_POSN                         equ 0002h
PIR4_CLC1IF_POSITION                     equ 0002h
PIR4_CLC1IF_SIZE                         equ 0001h
PIR4_CLC1IF_LENGTH                       equ 0001h
PIR4_CLC1IF_MASK                         equ 0004h
PIR4_CLC2IF_POSN                         equ 0003h
PIR4_CLC2IF_POSITION                     equ 0003h
PIR4_CLC2IF_SIZE                         equ 0001h
PIR4_CLC2IF_LENGTH                       equ 0001h
PIR4_CLC2IF_MASK                         equ 0008h
PIR4_CLC3IF_POSN                         equ 0004h
PIR4_CLC3IF_POSITION                     equ 0004h
PIR4_CLC3IF_SIZE                         equ 0001h
PIR4_CLC3IF_LENGTH                       equ 0001h
PIR4_CLC3IF_MASK                         equ 0010h
PIR4_CLC4IF_POSN                         equ 0005h
PIR4_CLC4IF_POSITION                     equ 0005h
PIR4_CLC4IF_SIZE                         equ 0001h
PIR4_CLC4IF_LENGTH                       equ 0001h
PIR4_CLC4IF_MASK                         equ 0020h
PIR4_TX1IF_POSN                          equ 0006h
PIR4_TX1IF_POSITION                      equ 0006h
PIR4_TX1IF_SIZE                          equ 0001h
PIR4_TX1IF_LENGTH                        equ 0001h
PIR4_TX1IF_MASK                          equ 0040h
PIR4_RC1IF_POSN                          equ 0007h
PIR4_RC1IF_POSITION                      equ 0007h
PIR4_RC1IF_SIZE                          equ 0001h
PIR4_RC1IF_LENGTH                        equ 0001h
PIR4_RC1IF_MASK                          equ 0080h

// Register: PIR5
#define PIR5 PIR5
PIR5                                     equ 0091h
// bitfield definitions
PIR5_SSP1IF_POSN                         equ 0002h
PIR5_SSP1IF_POSITION                     equ 0002h
PIR5_SSP1IF_SIZE                         equ 0001h
PIR5_SSP1IF_LENGTH                       equ 0001h
PIR5_SSP1IF_MASK                         equ 0004h
PIR5_BCL1IF_POSN                         equ 0003h
PIR5_BCL1IF_POSITION                     equ 0003h
PIR5_BCL1IF_SIZE                         equ 0001h
PIR5_BCL1IF_LENGTH                       equ 0001h
PIR5_BCL1IF_MASK                         equ 0008h
PIR5_CM1IF_POSN                          equ 0006h
PIR5_CM1IF_POSITION                      equ 0006h
PIR5_CM1IF_SIZE                          equ 0001h
PIR5_CM1IF_LENGTH                        equ 0001h
PIR5_CM1IF_MASK                          equ 0040h
PIR5_CM2IF_POSN                          equ 0007h
PIR5_CM2IF_POSITION                      equ 0007h
PIR5_CM2IF_SIZE                          equ 0001h
PIR5_CM2IF_LENGTH                        equ 0001h
PIR5_CM2IF_MASK                          equ 0080h

// Register: PIR6
#define PIR6 PIR6
PIR6                                     equ 0092h
// bitfield definitions
PIR6_ADIF_POSN                           equ 0000h
PIR6_ADIF_POSITION                       equ 0000h
PIR6_ADIF_SIZE                           equ 0001h
PIR6_ADIF_LENGTH                         equ 0001h
PIR6_ADIF_MASK                           equ 0001h
PIR6_ADTIF_POSN                          equ 0001h
PIR6_ADTIF_POSITION                      equ 0001h
PIR6_ADTIF_SIZE                          equ 0001h
PIR6_ADTIF_LENGTH                        equ 0001h
PIR6_ADTIF_MASK                          equ 0002h

// Register: PIR7
#define PIR7 PIR7
PIR7                                     equ 0093h
// bitfield definitions
PIR7_CLB1IF0_POSN                        equ 0000h
PIR7_CLB1IF0_POSITION                    equ 0000h
PIR7_CLB1IF0_SIZE                        equ 0001h
PIR7_CLB1IF0_LENGTH                      equ 0001h
PIR7_CLB1IF0_MASK                        equ 0001h
PIR7_CLB1IF1_POSN                        equ 0001h
PIR7_CLB1IF1_POSITION                    equ 0001h
PIR7_CLB1IF1_SIZE                        equ 0001h
PIR7_CLB1IF1_LENGTH                      equ 0001h
PIR7_CLB1IF1_MASK                        equ 0002h
PIR7_CLB1IF2_POSN                        equ 0002h
PIR7_CLB1IF2_POSITION                    equ 0002h
PIR7_CLB1IF2_SIZE                        equ 0001h
PIR7_CLB1IF2_LENGTH                      equ 0001h
PIR7_CLB1IF2_MASK                        equ 0004h
PIR7_CLB1IF3_POSN                        equ 0003h
PIR7_CLB1IF3_POSITION                    equ 0003h
PIR7_CLB1IF3_SIZE                        equ 0001h
PIR7_CLB1IF3_LENGTH                      equ 0001h
PIR7_CLB1IF3_MASK                        equ 0008h

// Register: PIE0
#define PIE0 PIE0
PIE0                                     equ 0096h
// bitfield definitions
PIE0_INTE_POSN                           equ 0000h
PIE0_INTE_POSITION                       equ 0000h
PIE0_INTE_SIZE                           equ 0001h
PIE0_INTE_LENGTH                         equ 0001h
PIE0_INTE_MASK                           equ 0001h
PIE0_IOCIE_POSN                          equ 0004h
PIE0_IOCIE_POSITION                      equ 0004h
PIE0_IOCIE_SIZE                          equ 0001h
PIE0_IOCIE_LENGTH                        equ 0001h
PIE0_IOCIE_MASK                          equ 0010h
PIE0_TMR0IE_POSN                         equ 0005h
PIE0_TMR0IE_POSITION                     equ 0005h
PIE0_TMR0IE_SIZE                         equ 0001h
PIE0_TMR0IE_LENGTH                       equ 0001h
PIE0_TMR0IE_MASK                         equ 0020h

// Register: PIE1
#define PIE1 PIE1
PIE1                                     equ 0097h
// bitfield definitions
PIE1_NVMIE_POSN                          equ 0000h
PIE1_NVMIE_POSITION                      equ 0000h
PIE1_NVMIE_SIZE                          equ 0001h
PIE1_NVMIE_LENGTH                        equ 0001h
PIE1_NVMIE_MASK                          equ 0001h
PIE1_CRCIE_POSN                          equ 0001h
PIE1_CRCIE_POSITION                      equ 0001h
PIE1_CRCIE_SIZE                          equ 0001h
PIE1_CRCIE_LENGTH                        equ 0001h
PIE1_CRCIE_MASK                          equ 0002h
PIE1_SCANIE_POSN                         equ 0002h
PIE1_SCANIE_POSITION                     equ 0002h
PIE1_SCANIE_SIZE                         equ 0001h
PIE1_SCANIE_LENGTH                       equ 0001h
PIE1_SCANIE_MASK                         equ 0004h
PIE1_CSWIE_POSN                          equ 0004h
PIE1_CSWIE_POSITION                      equ 0004h
PIE1_CSWIE_SIZE                          equ 0001h
PIE1_CSWIE_LENGTH                        equ 0001h
PIE1_CSWIE_MASK                          equ 0010h
PIE1_OSFIE_POSN                          equ 0005h
PIE1_OSFIE_POSITION                      equ 0005h
PIE1_OSFIE_SIZE                          equ 0001h
PIE1_OSFIE_LENGTH                        equ 0001h
PIE1_OSFIE_MASK                          equ 0020h
PIE1_TMR1IE_POSN                         equ 0006h
PIE1_TMR1IE_POSITION                     equ 0006h
PIE1_TMR1IE_SIZE                         equ 0001h
PIE1_TMR1IE_LENGTH                       equ 0001h
PIE1_TMR1IE_MASK                         equ 0040h
PIE1_TMR1GIE_POSN                        equ 0007h
PIE1_TMR1GIE_POSITION                    equ 0007h
PIE1_TMR1GIE_SIZE                        equ 0001h
PIE1_TMR1GIE_LENGTH                      equ 0001h
PIE1_TMR1GIE_MASK                        equ 0080h

// Register: PIE2
#define PIE2 PIE2
PIE2                                     equ 0098h
// bitfield definitions
PIE2_TMR2IE_POSN                         equ 0002h
PIE2_TMR2IE_POSITION                     equ 0002h
PIE2_TMR2IE_SIZE                         equ 0001h
PIE2_TMR2IE_LENGTH                       equ 0001h
PIE2_TMR2IE_MASK                         equ 0004h
PIE2_CCP1IE_POSN                         equ 0005h
PIE2_CCP1IE_POSITION                     equ 0005h
PIE2_CCP1IE_SIZE                         equ 0001h
PIE2_CCP1IE_LENGTH                       equ 0001h
PIE2_CCP1IE_MASK                         equ 0020h
PIE2_CCP2IE_POSN                         equ 0006h
PIE2_CCP2IE_POSITION                     equ 0006h
PIE2_CCP2IE_SIZE                         equ 0001h
PIE2_CCP2IE_LENGTH                       equ 0001h
PIE2_CCP2IE_MASK                         equ 0040h

// Register: PIE3
#define PIE3 PIE3
PIE3                                     equ 0099h

// Register: PIE4
#define PIE4 PIE4
PIE4                                     equ 009Ah
// bitfield definitions
PIE4_CLC1IE_POSN                         equ 0002h
PIE4_CLC1IE_POSITION                     equ 0002h
PIE4_CLC1IE_SIZE                         equ 0001h
PIE4_CLC1IE_LENGTH                       equ 0001h
PIE4_CLC1IE_MASK                         equ 0004h
PIE4_CLC2IE_POSN                         equ 0003h
PIE4_CLC2IE_POSITION                     equ 0003h
PIE4_CLC2IE_SIZE                         equ 0001h
PIE4_CLC2IE_LENGTH                       equ 0001h
PIE4_CLC2IE_MASK                         equ 0008h
PIE4_CLC3IE_POSN                         equ 0004h
PIE4_CLC3IE_POSITION                     equ 0004h
PIE4_CLC3IE_SIZE                         equ 0001h
PIE4_CLC3IE_LENGTH                       equ 0001h
PIE4_CLC3IE_MASK                         equ 0010h
PIE4_CLC4IE_POSN                         equ 0005h
PIE4_CLC4IE_POSITION                     equ 0005h
PIE4_CLC4IE_SIZE                         equ 0001h
PIE4_CLC4IE_LENGTH                       equ 0001h
PIE4_CLC4IE_MASK                         equ 0020h
PIE4_TX1IE_POSN                          equ 0006h
PIE4_TX1IE_POSITION                      equ 0006h
PIE4_TX1IE_SIZE                          equ 0001h
PIE4_TX1IE_LENGTH                        equ 0001h
PIE4_TX1IE_MASK                          equ 0040h
PIE4_RC1IE_POSN                          equ 0007h
PIE4_RC1IE_POSITION                      equ 0007h
PIE4_RC1IE_SIZE                          equ 0001h
PIE4_RC1IE_LENGTH                        equ 0001h
PIE4_RC1IE_MASK                          equ 0080h

// Register: PIE5
#define PIE5 PIE5
PIE5                                     equ 009Bh
// bitfield definitions
PIE5_SSP1IE_POSN                         equ 0002h
PIE5_SSP1IE_POSITION                     equ 0002h
PIE5_SSP1IE_SIZE                         equ 0001h
PIE5_SSP1IE_LENGTH                       equ 0001h
PIE5_SSP1IE_MASK                         equ 0004h
PIE5_BCL1IE_POSN                         equ 0003h
PIE5_BCL1IE_POSITION                     equ 0003h
PIE5_BCL1IE_SIZE                         equ 0001h
PIE5_BCL1IE_LENGTH                       equ 0001h
PIE5_BCL1IE_MASK                         equ 0008h
PIE5_CM1IE_POSN                          equ 0006h
PIE5_CM1IE_POSITION                      equ 0006h
PIE5_CM1IE_SIZE                          equ 0001h
PIE5_CM1IE_LENGTH                        equ 0001h
PIE5_CM1IE_MASK                          equ 0040h
PIE5_CM2IE_POSN                          equ 0007h
PIE5_CM2IE_POSITION                      equ 0007h
PIE5_CM2IE_SIZE                          equ 0001h
PIE5_CM2IE_LENGTH                        equ 0001h
PIE5_CM2IE_MASK                          equ 0080h

// Register: PIE6
#define PIE6 PIE6
PIE6                                     equ 009Ch
// bitfield definitions
PIE6_ADIE_POSN                           equ 0000h
PIE6_ADIE_POSITION                       equ 0000h
PIE6_ADIE_SIZE                           equ 0001h
PIE6_ADIE_LENGTH                         equ 0001h
PIE6_ADIE_MASK                           equ 0001h
PIE6_ADTIE_POSN                          equ 0001h
PIE6_ADTIE_POSITION                      equ 0001h
PIE6_ADTIE_SIZE                          equ 0001h
PIE6_ADTIE_LENGTH                        equ 0001h
PIE6_ADTIE_MASK                          equ 0002h

// Register: PIE7
#define PIE7 PIE7
PIE7                                     equ 009Dh
// bitfield definitions
PIE7_CLB1IE0_POSN                        equ 0000h
PIE7_CLB1IE0_POSITION                    equ 0000h
PIE7_CLB1IE0_SIZE                        equ 0001h
PIE7_CLB1IE0_LENGTH                      equ 0001h
PIE7_CLB1IE0_MASK                        equ 0001h
PIE7_CLB1IE1_POSN                        equ 0001h
PIE7_CLB1IE1_POSITION                    equ 0001h
PIE7_CLB1IE1_SIZE                        equ 0001h
PIE7_CLB1IE1_LENGTH                      equ 0001h
PIE7_CLB1IE1_MASK                        equ 0002h
PIE7_CLB1IE2_POSN                        equ 0002h
PIE7_CLB1IE2_POSITION                    equ 0002h
PIE7_CLB1IE2_SIZE                        equ 0001h
PIE7_CLB1IE2_LENGTH                      equ 0001h
PIE7_CLB1IE2_MASK                        equ 0004h
PIE7_CLB1IE3_POSN                        equ 0003h
PIE7_CLB1IE3_POSITION                    equ 0003h
PIE7_CLB1IE3_SIZE                        equ 0001h
PIE7_CLB1IE3_LENGTH                      equ 0001h
PIE7_CLB1IE3_MASK                        equ 0008h

// Register: PMD0
#define PMD0 PMD0
PMD0                                     equ 010Ch
// bitfield definitions
PMD0_NVMMD_POSN                          equ 0000h
PMD0_NVMMD_POSITION                      equ 0000h
PMD0_NVMMD_SIZE                          equ 0001h
PMD0_NVMMD_LENGTH                        equ 0001h
PMD0_NVMMD_MASK                          equ 0001h
PMD0_CRCMD_POSN                          equ 0001h
PMD0_CRCMD_POSITION                      equ 0001h
PMD0_CRCMD_SIZE                          equ 0001h
PMD0_CRCMD_LENGTH                        equ 0001h
PMD0_CRCMD_MASK                          equ 0002h
PMD0_SCANMD_POSN                         equ 0002h
PMD0_SCANMD_POSITION                     equ 0002h
PMD0_SCANMD_SIZE                         equ 0001h
PMD0_SCANMD_LENGTH                       equ 0001h
PMD0_SCANMD_MASK                         equ 0004h
PMD0_SYSCMD_POSN                         equ 0003h
PMD0_SYSCMD_POSITION                     equ 0003h
PMD0_SYSCMD_SIZE                         equ 0001h
PMD0_SYSCMD_LENGTH                       equ 0001h
PMD0_SYSCMD_MASK                         equ 0008h
PMD0_IOCMD_POSN                          equ 0005h
PMD0_IOCMD_POSITION                      equ 0005h
PMD0_IOCMD_SIZE                          equ 0001h
PMD0_IOCMD_LENGTH                        equ 0001h
PMD0_IOCMD_MASK                          equ 0020h
PMD0_TMR0MD_POSN                         equ 0007h
PMD0_TMR0MD_POSITION                     equ 0007h
PMD0_TMR0MD_SIZE                         equ 0001h
PMD0_TMR0MD_LENGTH                       equ 0001h
PMD0_TMR0MD_MASK                         equ 0080h

// Register: PMD1
#define PMD1 PMD1
PMD1                                     equ 010Dh
// bitfield definitions
PMD1_TMR1MD_POSN                         equ 0000h
PMD1_TMR1MD_POSITION                     equ 0000h
PMD1_TMR1MD_SIZE                         equ 0001h
PMD1_TMR1MD_LENGTH                       equ 0001h
PMD1_TMR1MD_MASK                         equ 0001h
PMD1_TMR2MD_POSN                         equ 0002h
PMD1_TMR2MD_POSITION                     equ 0002h
PMD1_TMR2MD_SIZE                         equ 0001h
PMD1_TMR2MD_LENGTH                       equ 0001h
PMD1_TMR2MD_MASK                         equ 0004h
PMD1_CCP1MD_POSN                         equ 0005h
PMD1_CCP1MD_POSITION                     equ 0005h
PMD1_CCP1MD_SIZE                         equ 0001h
PMD1_CCP1MD_LENGTH                       equ 0001h
PMD1_CCP1MD_MASK                         equ 0020h
PMD1_CCP2MD_POSN                         equ 0006h
PMD1_CCP2MD_POSITION                     equ 0006h
PMD1_CCP2MD_SIZE                         equ 0001h
PMD1_CCP2MD_LENGTH                       equ 0001h
PMD1_CCP2MD_MASK                         equ 0040h

// Register: PMD2
#define PMD2 PMD2
PMD2                                     equ 010Eh
// bitfield definitions
PMD2_CLC1MD_POSN                         equ 0005h
PMD2_CLC1MD_POSITION                     equ 0005h
PMD2_CLC1MD_SIZE                         equ 0001h
PMD2_CLC1MD_LENGTH                       equ 0001h
PMD2_CLC1MD_MASK                         equ 0020h
PMD2_CLC2MD_POSN                         equ 0006h
PMD2_CLC2MD_POSITION                     equ 0006h
PMD2_CLC2MD_SIZE                         equ 0001h
PMD2_CLC2MD_LENGTH                       equ 0001h
PMD2_CLC2MD_MASK                         equ 0040h
PMD2_CLC3MD_POSN                         equ 0007h
PMD2_CLC3MD_POSITION                     equ 0007h
PMD2_CLC3MD_SIZE                         equ 0001h
PMD2_CLC3MD_LENGTH                       equ 0001h
PMD2_CLC3MD_MASK                         equ 0080h

// Register: PMD3
#define PMD3 PMD3
PMD3                                     equ 010Fh
// bitfield definitions
PMD3_CLC4MD_POSN                         equ 0000h
PMD3_CLC4MD_POSITION                     equ 0000h
PMD3_CLC4MD_SIZE                         equ 0001h
PMD3_CLC4MD_LENGTH                       equ 0001h
PMD3_CLC4MD_MASK                         equ 0001h
PMD3_UART1MD_POSN                        equ 0001h
PMD3_UART1MD_POSITION                    equ 0001h
PMD3_UART1MD_SIZE                        equ 0001h
PMD3_UART1MD_LENGTH                      equ 0001h
PMD3_UART1MD_MASK                        equ 0002h
PMD3_MSSP1MD_POSN                        equ 0003h
PMD3_MSSP1MD_POSITION                    equ 0003h
PMD3_MSSP1MD_SIZE                        equ 0001h
PMD3_MSSP1MD_LENGTH                      equ 0001h
PMD3_MSSP1MD_MASK                        equ 0008h
PMD3_FVRMD_POSN                          equ 0005h
PMD3_FVRMD_POSITION                      equ 0005h
PMD3_FVRMD_SIZE                          equ 0001h
PMD3_FVRMD_LENGTH                        equ 0001h
PMD3_FVRMD_MASK                          equ 0020h
PMD3_CM1MD_POSN                          equ 0006h
PMD3_CM1MD_POSITION                      equ 0006h
PMD3_CM1MD_SIZE                          equ 0001h
PMD3_CM1MD_LENGTH                        equ 0001h
PMD3_CM1MD_MASK                          equ 0040h
PMD3_CM2MD_POSN                          equ 0007h
PMD3_CM2MD_POSITION                      equ 0007h
PMD3_CM2MD_SIZE                          equ 0001h
PMD3_CM2MD_LENGTH                        equ 0001h
PMD3_CM2MD_MASK                          equ 0080h

// Register: PMD4
#define PMD4 PMD4
PMD4                                     equ 0110h
// bitfield definitions
PMD4_ADCMD_POSN                          equ 0000h
PMD4_ADCMD_POSITION                      equ 0000h
PMD4_ADCMD_SIZE                          equ 0001h
PMD4_ADCMD_LENGTH                        equ 0001h
PMD4_ADCMD_MASK                          equ 0001h
PMD4_DAC1MD_POSN                         equ 0001h
PMD4_DAC1MD_POSITION                     equ 0001h
PMD4_DAC1MD_SIZE                         equ 0001h
PMD4_DAC1MD_LENGTH                       equ 0001h
PMD4_DAC1MD_MASK                         equ 0002h
PMD4_CLBMD_POSN                          equ 0007h
PMD4_CLBMD_POSITION                      equ 0007h
PMD4_CLBMD_SIZE                          equ 0001h
PMD4_CLBMD_LENGTH                        equ 0001h
PMD4_CLBMD_MASK                          equ 0080h

// Register: PMD5
#define PMD5 PMD5
PMD5                                     equ 0111h
// bitfield definitions
PMD5_PWM1MD_POSN                         equ 0000h
PMD5_PWM1MD_POSITION                     equ 0000h
PMD5_PWM1MD_SIZE                         equ 0001h
PMD5_PWM1MD_LENGTH                       equ 0001h
PMD5_PWM1MD_MASK                         equ 0001h
PMD5_PWM2MD_POSN                         equ 0001h
PMD5_PWM2MD_POSITION                     equ 0001h
PMD5_PWM2MD_SIZE                         equ 0001h
PMD5_PWM2MD_LENGTH                       equ 0001h
PMD5_PWM2MD_MASK                         equ 0002h

// Register: WDTCON0
#define WDTCON0 WDTCON0
WDTCON0                                  equ 018Ch
// bitfield definitions
WDTCON0_SEN_POSN                         equ 0000h
WDTCON0_SEN_POSITION                     equ 0000h
WDTCON0_SEN_SIZE                         equ 0001h
WDTCON0_SEN_LENGTH                       equ 0001h
WDTCON0_SEN_MASK                         equ 0001h
WDTCON0_PS_POSN                          equ 0001h
WDTCON0_PS_POSITION                      equ 0001h
WDTCON0_PS_SIZE                          equ 0005h
WDTCON0_PS_LENGTH                        equ 0005h
WDTCON0_PS_MASK                          equ 003Eh
WDTCON0_SWDTEN_POSN                      equ 0000h
WDTCON0_SWDTEN_POSITION                  equ 0000h
WDTCON0_SWDTEN_SIZE                      equ 0001h
WDTCON0_SWDTEN_LENGTH                    equ 0001h
WDTCON0_SWDTEN_MASK                      equ 0001h
WDTCON0_WDTPS_POSN                       equ 0001h
WDTCON0_WDTPS_POSITION                   equ 0001h
WDTCON0_WDTPS_SIZE                       equ 0005h
WDTCON0_WDTPS_LENGTH                     equ 0005h
WDTCON0_WDTPS_MASK                       equ 003Eh
WDTCON0_WDTSEN_POSN                      equ 0000h
WDTCON0_WDTSEN_POSITION                  equ 0000h
WDTCON0_WDTSEN_SIZE                      equ 0001h
WDTCON0_WDTSEN_LENGTH                    equ 0001h
WDTCON0_WDTSEN_MASK                      equ 0001h
WDTCON0_PS0_POSN                         equ 0001h
WDTCON0_PS0_POSITION                     equ 0001h
WDTCON0_PS0_SIZE                         equ 0001h
WDTCON0_PS0_LENGTH                       equ 0001h
WDTCON0_PS0_MASK                         equ 0002h
WDTCON0_PS1_POSN                         equ 0002h
WDTCON0_PS1_POSITION                     equ 0002h
WDTCON0_PS1_SIZE                         equ 0001h
WDTCON0_PS1_LENGTH                       equ 0001h
WDTCON0_PS1_MASK                         equ 0004h
WDTCON0_PS2_POSN                         equ 0003h
WDTCON0_PS2_POSITION                     equ 0003h
WDTCON0_PS2_SIZE                         equ 0001h
WDTCON0_PS2_LENGTH                       equ 0001h
WDTCON0_PS2_MASK                         equ 0008h
WDTCON0_PS3_POSN                         equ 0004h
WDTCON0_PS3_POSITION                     equ 0004h
WDTCON0_PS3_SIZE                         equ 0001h
WDTCON0_PS3_LENGTH                       equ 0001h
WDTCON0_PS3_MASK                         equ 0010h
WDTCON0_PS4_POSN                         equ 0005h
WDTCON0_PS4_POSITION                     equ 0005h
WDTCON0_PS4_SIZE                         equ 0001h
WDTCON0_PS4_LENGTH                       equ 0001h
WDTCON0_PS4_MASK                         equ 0020h
WDTCON0_WDTPS0_POSN                      equ 0001h
WDTCON0_WDTPS0_POSITION                  equ 0001h
WDTCON0_WDTPS0_SIZE                      equ 0001h
WDTCON0_WDTPS0_LENGTH                    equ 0001h
WDTCON0_WDTPS0_MASK                      equ 0002h
WDTCON0_WDTPS1_POSN                      equ 0002h
WDTCON0_WDTPS1_POSITION                  equ 0002h
WDTCON0_WDTPS1_SIZE                      equ 0001h
WDTCON0_WDTPS1_LENGTH                    equ 0001h
WDTCON0_WDTPS1_MASK                      equ 0004h
WDTCON0_WDTPS2_POSN                      equ 0003h
WDTCON0_WDTPS2_POSITION                  equ 0003h
WDTCON0_WDTPS2_SIZE                      equ 0001h
WDTCON0_WDTPS2_LENGTH                    equ 0001h
WDTCON0_WDTPS2_MASK                      equ 0008h
WDTCON0_WDTPS3_POSN                      equ 0004h
WDTCON0_WDTPS3_POSITION                  equ 0004h
WDTCON0_WDTPS3_SIZE                      equ 0001h
WDTCON0_WDTPS3_LENGTH                    equ 0001h
WDTCON0_WDTPS3_MASK                      equ 0010h
WDTCON0_WDTPS4_POSN                      equ 0005h
WDTCON0_WDTPS4_POSITION                  equ 0005h
WDTCON0_WDTPS4_SIZE                      equ 0001h
WDTCON0_WDTPS4_LENGTH                    equ 0001h
WDTCON0_WDTPS4_MASK                      equ 0020h

// Register: WDTCON1
#define WDTCON1 WDTCON1
WDTCON1                                  equ 018Dh
// bitfield definitions
WDTCON1_WINDOW_POSN                      equ 0000h
WDTCON1_WINDOW_POSITION                  equ 0000h
WDTCON1_WINDOW_SIZE                      equ 0003h
WDTCON1_WINDOW_LENGTH                    equ 0003h
WDTCON1_WINDOW_MASK                      equ 0007h
WDTCON1_CS_POSN                          equ 0004h
WDTCON1_CS_POSITION                      equ 0004h
WDTCON1_CS_SIZE                          equ 0003h
WDTCON1_CS_LENGTH                        equ 0003h
WDTCON1_CS_MASK                          equ 0070h
WDTCON1_WINDOW0_POSN                     equ 0000h
WDTCON1_WINDOW0_POSITION                 equ 0000h
WDTCON1_WINDOW0_SIZE                     equ 0001h
WDTCON1_WINDOW0_LENGTH                   equ 0001h
WDTCON1_WINDOW0_MASK                     equ 0001h
WDTCON1_WINDOW1_POSN                     equ 0001h
WDTCON1_WINDOW1_POSITION                 equ 0001h
WDTCON1_WINDOW1_SIZE                     equ 0001h
WDTCON1_WINDOW1_LENGTH                   equ 0001h
WDTCON1_WINDOW1_MASK                     equ 0002h
WDTCON1_WINDOW2_POSN                     equ 0002h
WDTCON1_WINDOW2_POSITION                 equ 0002h
WDTCON1_WINDOW2_SIZE                     equ 0001h
WDTCON1_WINDOW2_LENGTH                   equ 0001h
WDTCON1_WINDOW2_MASK                     equ 0004h
WDTCON1_WDTCS_POSN                       equ 0004h
WDTCON1_WDTCS_POSITION                   equ 0004h
WDTCON1_WDTCS_SIZE                       equ 0003h
WDTCON1_WDTCS_LENGTH                     equ 0003h
WDTCON1_WDTCS_MASK                       equ 0070h
WDTCON1_WDTWINDOW_POSN                   equ 0000h
WDTCON1_WDTWINDOW_POSITION               equ 0000h
WDTCON1_WDTWINDOW_SIZE                   equ 0003h
WDTCON1_WDTWINDOW_LENGTH                 equ 0003h
WDTCON1_WDTWINDOW_MASK                   equ 0007h
WDTCON1_CS0_POSN                         equ 0004h
WDTCON1_CS0_POSITION                     equ 0004h
WDTCON1_CS0_SIZE                         equ 0001h
WDTCON1_CS0_LENGTH                       equ 0001h
WDTCON1_CS0_MASK                         equ 0010h
WDTCON1_CS1_POSN                         equ 0005h
WDTCON1_CS1_POSITION                     equ 0005h
WDTCON1_CS1_SIZE                         equ 0001h
WDTCON1_CS1_LENGTH                       equ 0001h
WDTCON1_CS1_MASK                         equ 0020h
WDTCON1_CS2_POSN                         equ 0006h
WDTCON1_CS2_POSITION                     equ 0006h
WDTCON1_CS2_SIZE                         equ 0001h
WDTCON1_CS2_LENGTH                       equ 0001h
WDTCON1_CS2_MASK                         equ 0040h
WDTCON1_WDTWINDOW0_POSN                  equ 0000h
WDTCON1_WDTWINDOW0_POSITION              equ 0000h
WDTCON1_WDTWINDOW0_SIZE                  equ 0001h
WDTCON1_WDTWINDOW0_LENGTH                equ 0001h
WDTCON1_WDTWINDOW0_MASK                  equ 0001h
WDTCON1_WDTWINDOW1_POSN                  equ 0001h
WDTCON1_WDTWINDOW1_POSITION              equ 0001h
WDTCON1_WDTWINDOW1_SIZE                  equ 0001h
WDTCON1_WDTWINDOW1_LENGTH                equ 0001h
WDTCON1_WDTWINDOW1_MASK                  equ 0002h
WDTCON1_WDTWINDOW2_POSN                  equ 0002h
WDTCON1_WDTWINDOW2_POSITION              equ 0002h
WDTCON1_WDTWINDOW2_SIZE                  equ 0001h
WDTCON1_WDTWINDOW2_LENGTH                equ 0001h
WDTCON1_WDTWINDOW2_MASK                  equ 0004h
WDTCON1_WDTCS0_POSN                      equ 0004h
WDTCON1_WDTCS0_POSITION                  equ 0004h
WDTCON1_WDTCS0_SIZE                      equ 0001h
WDTCON1_WDTCS0_LENGTH                    equ 0001h
WDTCON1_WDTCS0_MASK                      equ 0010h
WDTCON1_WDTCS1_POSN                      equ 0005h
WDTCON1_WDTCS1_POSITION                  equ 0005h
WDTCON1_WDTCS1_SIZE                      equ 0001h
WDTCON1_WDTCS1_LENGTH                    equ 0001h
WDTCON1_WDTCS1_MASK                      equ 0020h
WDTCON1_WDTCS2_POSN                      equ 0006h
WDTCON1_WDTCS2_POSITION                  equ 0006h
WDTCON1_WDTCS2_SIZE                      equ 0001h
WDTCON1_WDTCS2_LENGTH                    equ 0001h
WDTCON1_WDTCS2_MASK                      equ 0040h

// Register: WDTPSL
#define WDTPSL WDTPSL
WDTPSL                                   equ 018Eh
// bitfield definitions
WDTPSL_PSCNTL_POSN                       equ 0000h
WDTPSL_PSCNTL_POSITION                   equ 0000h
WDTPSL_PSCNTL_SIZE                       equ 0008h
WDTPSL_PSCNTL_LENGTH                     equ 0008h
WDTPSL_PSCNTL_MASK                       equ 00FFh
WDTPSL_WDTPSCNTL_POSN                    equ 0000h
WDTPSL_WDTPSCNTL_POSITION                equ 0000h
WDTPSL_WDTPSCNTL_SIZE                    equ 0008h
WDTPSL_WDTPSCNTL_LENGTH                  equ 0008h
WDTPSL_WDTPSCNTL_MASK                    equ 00FFh
WDTPSL_PSCNT0_POSN                       equ 0000h
WDTPSL_PSCNT0_POSITION                   equ 0000h
WDTPSL_PSCNT0_SIZE                       equ 0001h
WDTPSL_PSCNT0_LENGTH                     equ 0001h
WDTPSL_PSCNT0_MASK                       equ 0001h
WDTPSL_PSCNT1_POSN                       equ 0001h
WDTPSL_PSCNT1_POSITION                   equ 0001h
WDTPSL_PSCNT1_SIZE                       equ 0001h
WDTPSL_PSCNT1_LENGTH                     equ 0001h
WDTPSL_PSCNT1_MASK                       equ 0002h
WDTPSL_PSCNT2_POSN                       equ 0002h
WDTPSL_PSCNT2_POSITION                   equ 0002h
WDTPSL_PSCNT2_SIZE                       equ 0001h
WDTPSL_PSCNT2_LENGTH                     equ 0001h
WDTPSL_PSCNT2_MASK                       equ 0004h
WDTPSL_PSCNT3_POSN                       equ 0003h
WDTPSL_PSCNT3_POSITION                   equ 0003h
WDTPSL_PSCNT3_SIZE                       equ 0001h
WDTPSL_PSCNT3_LENGTH                     equ 0001h
WDTPSL_PSCNT3_MASK                       equ 0008h
WDTPSL_PSCNT4_POSN                       equ 0004h
WDTPSL_PSCNT4_POSITION                   equ 0004h
WDTPSL_PSCNT4_SIZE                       equ 0001h
WDTPSL_PSCNT4_LENGTH                     equ 0001h
WDTPSL_PSCNT4_MASK                       equ 0010h
WDTPSL_PSCNT5_POSN                       equ 0005h
WDTPSL_PSCNT5_POSITION                   equ 0005h
WDTPSL_PSCNT5_SIZE                       equ 0001h
WDTPSL_PSCNT5_LENGTH                     equ 0001h
WDTPSL_PSCNT5_MASK                       equ 0020h
WDTPSL_PSCNT6_POSN                       equ 0006h
WDTPSL_PSCNT6_POSITION                   equ 0006h
WDTPSL_PSCNT6_SIZE                       equ 0001h
WDTPSL_PSCNT6_LENGTH                     equ 0001h
WDTPSL_PSCNT6_MASK                       equ 0040h
WDTPSL_PSCNT7_POSN                       equ 0007h
WDTPSL_PSCNT7_POSITION                   equ 0007h
WDTPSL_PSCNT7_SIZE                       equ 0001h
WDTPSL_PSCNT7_LENGTH                     equ 0001h
WDTPSL_PSCNT7_MASK                       equ 0080h

// Register: WDTPSH
#define WDTPSH WDTPSH
WDTPSH                                   equ 018Fh
// bitfield definitions
WDTPSH_PSCNTH_POSN                       equ 0000h
WDTPSH_PSCNTH_POSITION                   equ 0000h
WDTPSH_PSCNTH_SIZE                       equ 0008h
WDTPSH_PSCNTH_LENGTH                     equ 0008h
WDTPSH_PSCNTH_MASK                       equ 00FFh
WDTPSH_WDTPSCNTH_POSN                    equ 0000h
WDTPSH_WDTPSCNTH_POSITION                equ 0000h
WDTPSH_WDTPSCNTH_SIZE                    equ 0008h
WDTPSH_WDTPSCNTH_LENGTH                  equ 0008h
WDTPSH_WDTPSCNTH_MASK                    equ 00FFh
WDTPSH_PSCNT8_POSN                       equ 0000h
WDTPSH_PSCNT8_POSITION                   equ 0000h
WDTPSH_PSCNT8_SIZE                       equ 0001h
WDTPSH_PSCNT8_LENGTH                     equ 0001h
WDTPSH_PSCNT8_MASK                       equ 0001h
WDTPSH_PSCNT9_POSN                       equ 0001h
WDTPSH_PSCNT9_POSITION                   equ 0001h
WDTPSH_PSCNT9_SIZE                       equ 0001h
WDTPSH_PSCNT9_LENGTH                     equ 0001h
WDTPSH_PSCNT9_MASK                       equ 0002h
WDTPSH_PSCNT10_POSN                      equ 0002h
WDTPSH_PSCNT10_POSITION                  equ 0002h
WDTPSH_PSCNT10_SIZE                      equ 0001h
WDTPSH_PSCNT10_LENGTH                    equ 0001h
WDTPSH_PSCNT10_MASK                      equ 0004h
WDTPSH_PSCNT11_POSN                      equ 0003h
WDTPSH_PSCNT11_POSITION                  equ 0003h
WDTPSH_PSCNT11_SIZE                      equ 0001h
WDTPSH_PSCNT11_LENGTH                    equ 0001h
WDTPSH_PSCNT11_MASK                      equ 0008h
WDTPSH_PSCNT12_POSN                      equ 0004h
WDTPSH_PSCNT12_POSITION                  equ 0004h
WDTPSH_PSCNT12_SIZE                      equ 0001h
WDTPSH_PSCNT12_LENGTH                    equ 0001h
WDTPSH_PSCNT12_MASK                      equ 0010h
WDTPSH_PSCNT13_POSN                      equ 0005h
WDTPSH_PSCNT13_POSITION                  equ 0005h
WDTPSH_PSCNT13_SIZE                      equ 0001h
WDTPSH_PSCNT13_LENGTH                    equ 0001h
WDTPSH_PSCNT13_MASK                      equ 0020h
WDTPSH_PSCNT14_POSN                      equ 0006h
WDTPSH_PSCNT14_POSITION                  equ 0006h
WDTPSH_PSCNT14_SIZE                      equ 0001h
WDTPSH_PSCNT14_LENGTH                    equ 0001h
WDTPSH_PSCNT14_MASK                      equ 0040h
WDTPSH_PSCNT15_POSN                      equ 0007h
WDTPSH_PSCNT15_POSITION                  equ 0007h
WDTPSH_PSCNT15_SIZE                      equ 0001h
WDTPSH_PSCNT15_LENGTH                    equ 0001h
WDTPSH_PSCNT15_MASK                      equ 0080h

// Register: WDTTMR
#define WDTTMR WDTTMR
WDTTMR                                   equ 0190h
// bitfield definitions
WDTTMR_PSCNT16_POSN                      equ 0000h
WDTTMR_PSCNT16_POSITION                  equ 0000h
WDTTMR_PSCNT16_SIZE                      equ 0001h
WDTTMR_PSCNT16_LENGTH                    equ 0001h
WDTTMR_PSCNT16_MASK                      equ 0001h
WDTTMR_PSCNT17_POSN                      equ 0001h
WDTTMR_PSCNT17_POSITION                  equ 0001h
WDTTMR_PSCNT17_SIZE                      equ 0001h
WDTTMR_PSCNT17_LENGTH                    equ 0001h
WDTTMR_PSCNT17_MASK                      equ 0002h
WDTTMR_STATE_POSN                        equ 0002h
WDTTMR_STATE_POSITION                    equ 0002h
WDTTMR_STATE_SIZE                        equ 0001h
WDTTMR_STATE_LENGTH                      equ 0001h
WDTTMR_STATE_MASK                        equ 0004h
WDTTMR_TMR_POSN                          equ 0003h
WDTTMR_TMR_POSITION                      equ 0003h
WDTTMR_TMR_SIZE                          equ 0005h
WDTTMR_TMR_LENGTH                        equ 0005h
WDTTMR_TMR_MASK                          equ 00F8h
WDTTMR_WDTPSCNT16_POSN                   equ 0000h
WDTTMR_WDTPSCNT16_POSITION               equ 0000h
WDTTMR_WDTPSCNT16_SIZE                   equ 0001h
WDTTMR_WDTPSCNT16_LENGTH                 equ 0001h
WDTTMR_WDTPSCNT16_MASK                   equ 0001h
WDTTMR_WDTPSCNT17_POSN                   equ 0001h
WDTTMR_WDTPSCNT17_POSITION               equ 0001h
WDTTMR_WDTPSCNT17_SIZE                   equ 0001h
WDTTMR_WDTPSCNT17_LENGTH                 equ 0001h
WDTTMR_WDTPSCNT17_MASK                   equ 0002h
WDTTMR_WDTSTATE_POSN                     equ 0002h
WDTTMR_WDTSTATE_POSITION                 equ 0002h
WDTTMR_WDTSTATE_SIZE                     equ 0001h
WDTTMR_WDTSTATE_LENGTH                   equ 0001h
WDTTMR_WDTSTATE_MASK                     equ 0004h
WDTTMR_WDTTMR0_POSN                      equ 0003h
WDTTMR_WDTTMR0_POSITION                  equ 0003h
WDTTMR_WDTTMR0_SIZE                      equ 0001h
WDTTMR_WDTTMR0_LENGTH                    equ 0001h
WDTTMR_WDTTMR0_MASK                      equ 0008h
WDTTMR_WDTTMR1_POSN                      equ 0004h
WDTTMR_WDTTMR1_POSITION                  equ 0004h
WDTTMR_WDTTMR1_SIZE                      equ 0001h
WDTTMR_WDTTMR1_LENGTH                    equ 0001h
WDTTMR_WDTTMR1_MASK                      equ 0010h
WDTTMR_WDTTMR2_POSN                      equ 0005h
WDTTMR_WDTTMR2_POSITION                  equ 0005h
WDTTMR_WDTTMR2_SIZE                      equ 0001h
WDTTMR_WDTTMR2_LENGTH                    equ 0001h
WDTTMR_WDTTMR2_MASK                      equ 0020h
WDTTMR_WDTTMR3_POSN                      equ 0006h
WDTTMR_WDTTMR3_POSITION                  equ 0006h
WDTTMR_WDTTMR3_SIZE                      equ 0001h
WDTTMR_WDTTMR3_LENGTH                    equ 0001h
WDTTMR_WDTTMR3_MASK                      equ 0040h
WDTTMR_WDTTMR4_POSN                      equ 0007h
WDTTMR_WDTTMR4_POSITION                  equ 0007h
WDTTMR_WDTTMR4_SIZE                      equ 0001h
WDTTMR_WDTTMR4_LENGTH                    equ 0001h
WDTTMR_WDTTMR4_MASK                      equ 0080h
WDTTMR_WDTTMR_POSN                       equ 0003h
WDTTMR_WDTTMR_POSITION                   equ 0003h
WDTTMR_WDTTMR_SIZE                       equ 0005h
WDTTMR_WDTTMR_LENGTH                     equ 0005h
WDTTMR_WDTTMR_MASK                       equ 00F8h

// Register: BORCON
#define BORCON BORCON
BORCON                                   equ 0191h
// bitfield definitions
BORCON_BORRDY_POSN                       equ 0000h
BORCON_BORRDY_POSITION                   equ 0000h
BORCON_BORRDY_SIZE                       equ 0001h
BORCON_BORRDY_LENGTH                     equ 0001h
BORCON_BORRDY_MASK                       equ 0001h
BORCON_SBOREN_POSN                       equ 0007h
BORCON_SBOREN_POSITION                   equ 0007h
BORCON_SBOREN_SIZE                       equ 0001h
BORCON_SBOREN_LENGTH                     equ 0001h
BORCON_SBOREN_MASK                       equ 0080h

// Register: PCON0
#define PCON0 PCON0
PCON0                                    equ 0192h
// bitfield definitions
PCON0_nBOR_POSN                          equ 0000h
PCON0_nBOR_POSITION                      equ 0000h
PCON0_nBOR_SIZE                          equ 0001h
PCON0_nBOR_LENGTH                        equ 0001h
PCON0_nBOR_MASK                          equ 0001h
PCON0_nPOR_POSN                          equ 0001h
PCON0_nPOR_POSITION                      equ 0001h
PCON0_nPOR_SIZE                          equ 0001h
PCON0_nPOR_LENGTH                        equ 0001h
PCON0_nPOR_MASK                          equ 0002h
PCON0_nRI_POSN                           equ 0002h
PCON0_nRI_POSITION                       equ 0002h
PCON0_nRI_SIZE                           equ 0001h
PCON0_nRI_LENGTH                         equ 0001h
PCON0_nRI_MASK                           equ 0004h
PCON0_nRMCLR_POSN                        equ 0003h
PCON0_nRMCLR_POSITION                    equ 0003h
PCON0_nRMCLR_SIZE                        equ 0001h
PCON0_nRMCLR_LENGTH                      equ 0001h
PCON0_nRMCLR_MASK                        equ 0008h
PCON0_nRWDT_POSN                         equ 0004h
PCON0_nRWDT_POSITION                     equ 0004h
PCON0_nRWDT_SIZE                         equ 0001h
PCON0_nRWDT_LENGTH                       equ 0001h
PCON0_nRWDT_MASK                         equ 0010h
PCON0_nWDTWV_POSN                        equ 0005h
PCON0_nWDTWV_POSITION                    equ 0005h
PCON0_nWDTWV_SIZE                        equ 0001h
PCON0_nWDTWV_LENGTH                      equ 0001h
PCON0_nWDTWV_MASK                        equ 0020h
PCON0_STKUNF_POSN                        equ 0006h
PCON0_STKUNF_POSITION                    equ 0006h
PCON0_STKUNF_SIZE                        equ 0001h
PCON0_STKUNF_LENGTH                      equ 0001h
PCON0_STKUNF_MASK                        equ 0040h
PCON0_STKOVF_POSN                        equ 0007h
PCON0_STKOVF_POSITION                    equ 0007h
PCON0_STKOVF_SIZE                        equ 0001h
PCON0_STKOVF_LENGTH                      equ 0001h
PCON0_STKOVF_MASK                        equ 0080h

// Register: PCON1
#define PCON1 PCON1
PCON1                                    equ 0193h
// bitfield definitions
PCON1_nMEMV_POSN                         equ 0001h
PCON1_nMEMV_POSITION                     equ 0001h
PCON1_nMEMV_SIZE                         equ 0001h
PCON1_nMEMV_LENGTH                       equ 0001h
PCON1_nMEMV_MASK                         equ 0002h

// Register: TMR0L
#define TMR0L TMR0L
TMR0L                                    equ 019Ch
// bitfield definitions
TMR0L_TMR0L_POSN                         equ 0000h
TMR0L_TMR0L_POSITION                     equ 0000h
TMR0L_TMR0L_SIZE                         equ 0008h
TMR0L_TMR0L_LENGTH                       equ 0008h
TMR0L_TMR0L_MASK                         equ 00FFh
TMR0L_TMR0L0_POSN                        equ 0000h
TMR0L_TMR0L0_POSITION                    equ 0000h
TMR0L_TMR0L0_SIZE                        equ 0001h
TMR0L_TMR0L0_LENGTH                      equ 0001h
TMR0L_TMR0L0_MASK                        equ 0001h
TMR0L_TMR0L1_POSN                        equ 0001h
TMR0L_TMR0L1_POSITION                    equ 0001h
TMR0L_TMR0L1_SIZE                        equ 0001h
TMR0L_TMR0L1_LENGTH                      equ 0001h
TMR0L_TMR0L1_MASK                        equ 0002h
TMR0L_TMR0L2_POSN                        equ 0002h
TMR0L_TMR0L2_POSITION                    equ 0002h
TMR0L_TMR0L2_SIZE                        equ 0001h
TMR0L_TMR0L2_LENGTH                      equ 0001h
TMR0L_TMR0L2_MASK                        equ 0004h
TMR0L_TMR0L3_POSN                        equ 0003h
TMR0L_TMR0L3_POSITION                    equ 0003h
TMR0L_TMR0L3_SIZE                        equ 0001h
TMR0L_TMR0L3_LENGTH                      equ 0001h
TMR0L_TMR0L3_MASK                        equ 0008h
TMR0L_TMR0L4_POSN                        equ 0004h
TMR0L_TMR0L4_POSITION                    equ 0004h
TMR0L_TMR0L4_SIZE                        equ 0001h
TMR0L_TMR0L4_LENGTH                      equ 0001h
TMR0L_TMR0L4_MASK                        equ 0010h
TMR0L_TMR0L5_POSN                        equ 0005h
TMR0L_TMR0L5_POSITION                    equ 0005h
TMR0L_TMR0L5_SIZE                        equ 0001h
TMR0L_TMR0L5_LENGTH                      equ 0001h
TMR0L_TMR0L5_MASK                        equ 0020h
TMR0L_TMR0L6_POSN                        equ 0006h
TMR0L_TMR0L6_POSITION                    equ 0006h
TMR0L_TMR0L6_SIZE                        equ 0001h
TMR0L_TMR0L6_LENGTH                      equ 0001h
TMR0L_TMR0L6_MASK                        equ 0040h
TMR0L_TMR0L7_POSN                        equ 0007h
TMR0L_TMR0L7_POSITION                    equ 0007h
TMR0L_TMR0L7_SIZE                        equ 0001h
TMR0L_TMR0L7_LENGTH                      equ 0001h
TMR0L_TMR0L7_MASK                        equ 0080h

// Register: TMR0H
#define TMR0H TMR0H
TMR0H                                    equ 019Dh
// bitfield definitions
TMR0H_TMR0H_POSN                         equ 0000h
TMR0H_TMR0H_POSITION                     equ 0000h
TMR0H_TMR0H_SIZE                         equ 0008h
TMR0H_TMR0H_LENGTH                       equ 0008h
TMR0H_TMR0H_MASK                         equ 00FFh
TMR0H_TMR0H0_POSN                        equ 0000h
TMR0H_TMR0H0_POSITION                    equ 0000h
TMR0H_TMR0H0_SIZE                        equ 0001h
TMR0H_TMR0H0_LENGTH                      equ 0001h
TMR0H_TMR0H0_MASK                        equ 0001h
TMR0H_TMR0H1_POSN                        equ 0001h
TMR0H_TMR0H1_POSITION                    equ 0001h
TMR0H_TMR0H1_SIZE                        equ 0001h
TMR0H_TMR0H1_LENGTH                      equ 0001h
TMR0H_TMR0H1_MASK                        equ 0002h
TMR0H_TMR0H2_POSN                        equ 0002h
TMR0H_TMR0H2_POSITION                    equ 0002h
TMR0H_TMR0H2_SIZE                        equ 0001h
TMR0H_TMR0H2_LENGTH                      equ 0001h
TMR0H_TMR0H2_MASK                        equ 0004h
TMR0H_TMR0H3_POSN                        equ 0003h
TMR0H_TMR0H3_POSITION                    equ 0003h
TMR0H_TMR0H3_SIZE                        equ 0001h
TMR0H_TMR0H3_LENGTH                      equ 0001h
TMR0H_TMR0H3_MASK                        equ 0008h
TMR0H_TMR0H4_POSN                        equ 0004h
TMR0H_TMR0H4_POSITION                    equ 0004h
TMR0H_TMR0H4_SIZE                        equ 0001h
TMR0H_TMR0H4_LENGTH                      equ 0001h
TMR0H_TMR0H4_MASK                        equ 0010h
TMR0H_TMR0H5_POSN                        equ 0005h
TMR0H_TMR0H5_POSITION                    equ 0005h
TMR0H_TMR0H5_SIZE                        equ 0001h
TMR0H_TMR0H5_LENGTH                      equ 0001h
TMR0H_TMR0H5_MASK                        equ 0020h
TMR0H_TMR0H6_POSN                        equ 0006h
TMR0H_TMR0H6_POSITION                    equ 0006h
TMR0H_TMR0H6_SIZE                        equ 0001h
TMR0H_TMR0H6_LENGTH                      equ 0001h
TMR0H_TMR0H6_MASK                        equ 0040h
TMR0H_TMR0H7_POSN                        equ 0007h
TMR0H_TMR0H7_POSITION                    equ 0007h
TMR0H_TMR0H7_SIZE                        equ 0001h
TMR0H_TMR0H7_LENGTH                      equ 0001h
TMR0H_TMR0H7_MASK                        equ 0080h
TMR0H_T0PR0_POSN                         equ 0000h
TMR0H_T0PR0_POSITION                     equ 0000h
TMR0H_T0PR0_SIZE                         equ 0001h
TMR0H_T0PR0_LENGTH                       equ 0001h
TMR0H_T0PR0_MASK                         equ 0001h
TMR0H_T0PR1_POSN                         equ 0001h
TMR0H_T0PR1_POSITION                     equ 0001h
TMR0H_T0PR1_SIZE                         equ 0001h
TMR0H_T0PR1_LENGTH                       equ 0001h
TMR0H_T0PR1_MASK                         equ 0002h
TMR0H_T0PR2_POSN                         equ 0002h
TMR0H_T0PR2_POSITION                     equ 0002h
TMR0H_T0PR2_SIZE                         equ 0001h
TMR0H_T0PR2_LENGTH                       equ 0001h
TMR0H_T0PR2_MASK                         equ 0004h
TMR0H_T0PR3_POSN                         equ 0003h
TMR0H_T0PR3_POSITION                     equ 0003h
TMR0H_T0PR3_SIZE                         equ 0001h
TMR0H_T0PR3_LENGTH                       equ 0001h
TMR0H_T0PR3_MASK                         equ 0008h
TMR0H_T0PR4_POSN                         equ 0004h
TMR0H_T0PR4_POSITION                     equ 0004h
TMR0H_T0PR4_SIZE                         equ 0001h
TMR0H_T0PR4_LENGTH                       equ 0001h
TMR0H_T0PR4_MASK                         equ 0010h
TMR0H_T0PR5_POSN                         equ 0005h
TMR0H_T0PR5_POSITION                     equ 0005h
TMR0H_T0PR5_SIZE                         equ 0001h
TMR0H_T0PR5_LENGTH                       equ 0001h
TMR0H_T0PR5_MASK                         equ 0020h
TMR0H_T0PR6_POSN                         equ 0006h
TMR0H_T0PR6_POSITION                     equ 0006h
TMR0H_T0PR6_SIZE                         equ 0001h
TMR0H_T0PR6_LENGTH                       equ 0001h
TMR0H_T0PR6_MASK                         equ 0040h
TMR0H_T0PR7_POSN                         equ 0007h
TMR0H_T0PR7_POSITION                     equ 0007h
TMR0H_T0PR7_SIZE                         equ 0001h
TMR0H_T0PR7_LENGTH                       equ 0001h
TMR0H_T0PR7_MASK                         equ 0080h
TMR0H_T0PR_POSN                          equ 0000h
TMR0H_T0PR_POSITION                      equ 0000h
TMR0H_T0PR_SIZE                          equ 0008h
TMR0H_T0PR_LENGTH                        equ 0008h
TMR0H_T0PR_MASK                          equ 00FFh

// Register: T0CON0
#define T0CON0 T0CON0
T0CON0                                   equ 019Eh
// bitfield definitions
T0CON0_OUTPS_POSN                        equ 0000h
T0CON0_OUTPS_POSITION                    equ 0000h
T0CON0_OUTPS_SIZE                        equ 0004h
T0CON0_OUTPS_LENGTH                      equ 0004h
T0CON0_OUTPS_MASK                        equ 000Fh
T0CON0_MD16_POSN                         equ 0004h
T0CON0_MD16_POSITION                     equ 0004h
T0CON0_MD16_SIZE                         equ 0001h
T0CON0_MD16_LENGTH                       equ 0001h
T0CON0_MD16_MASK                         equ 0010h
T0CON0_OUT_POSN                          equ 0005h
T0CON0_OUT_POSITION                      equ 0005h
T0CON0_OUT_SIZE                          equ 0001h
T0CON0_OUT_LENGTH                        equ 0001h
T0CON0_OUT_MASK                          equ 0020h
T0CON0_EN_POSN                           equ 0007h
T0CON0_EN_POSITION                       equ 0007h
T0CON0_EN_SIZE                           equ 0001h
T0CON0_EN_LENGTH                         equ 0001h
T0CON0_EN_MASK                           equ 0080h
T0CON0_T0OUTPS_POSN                      equ 0000h
T0CON0_T0OUTPS_POSITION                  equ 0000h
T0CON0_T0OUTPS_SIZE                      equ 0004h
T0CON0_T0OUTPS_LENGTH                    equ 0004h
T0CON0_T0OUTPS_MASK                      equ 000Fh
T0CON0_T0MD16_POSN                       equ 0004h
T0CON0_T0MD16_POSITION                   equ 0004h
T0CON0_T0MD16_SIZE                       equ 0001h
T0CON0_T0MD16_LENGTH                     equ 0001h
T0CON0_T0MD16_MASK                       equ 0010h
T0CON0_T0OUT_POSN                        equ 0005h
T0CON0_T0OUT_POSITION                    equ 0005h
T0CON0_T0OUT_SIZE                        equ 0001h
T0CON0_T0OUT_LENGTH                      equ 0001h
T0CON0_T0OUT_MASK                        equ 0020h
T0CON0_T0EN_POSN                         equ 0007h
T0CON0_T0EN_POSITION                     equ 0007h
T0CON0_T0EN_SIZE                         equ 0001h
T0CON0_T0EN_LENGTH                       equ 0001h
T0CON0_T0EN_MASK                         equ 0080h
T0CON0_OUTPS0_POSN                       equ 0000h
T0CON0_OUTPS0_POSITION                   equ 0000h
T0CON0_OUTPS0_SIZE                       equ 0001h
T0CON0_OUTPS0_LENGTH                     equ 0001h
T0CON0_OUTPS0_MASK                       equ 0001h
T0CON0_OUTPS1_POSN                       equ 0001h
T0CON0_OUTPS1_POSITION                   equ 0001h
T0CON0_OUTPS1_SIZE                       equ 0001h
T0CON0_OUTPS1_LENGTH                     equ 0001h
T0CON0_OUTPS1_MASK                       equ 0002h
T0CON0_OUTPS2_POSN                       equ 0002h
T0CON0_OUTPS2_POSITION                   equ 0002h
T0CON0_OUTPS2_SIZE                       equ 0001h
T0CON0_OUTPS2_LENGTH                     equ 0001h
T0CON0_OUTPS2_MASK                       equ 0004h
T0CON0_OUTPS3_POSN                       equ 0003h
T0CON0_OUTPS3_POSITION                   equ 0003h
T0CON0_OUTPS3_SIZE                       equ 0001h
T0CON0_OUTPS3_LENGTH                     equ 0001h
T0CON0_OUTPS3_MASK                       equ 0008h
T0CON0_T016BIT_POSN                      equ 0004h
T0CON0_T016BIT_POSITION                  equ 0004h
T0CON0_T016BIT_SIZE                      equ 0001h
T0CON0_T016BIT_LENGTH                    equ 0001h
T0CON0_T016BIT_MASK                      equ 0010h
T0CON0_T0OUTPS0_POSN                     equ 0000h
T0CON0_T0OUTPS0_POSITION                 equ 0000h
T0CON0_T0OUTPS0_SIZE                     equ 0001h
T0CON0_T0OUTPS0_LENGTH                   equ 0001h
T0CON0_T0OUTPS0_MASK                     equ 0001h
T0CON0_T0OUTPS1_POSN                     equ 0001h
T0CON0_T0OUTPS1_POSITION                 equ 0001h
T0CON0_T0OUTPS1_SIZE                     equ 0001h
T0CON0_T0OUTPS1_LENGTH                   equ 0001h
T0CON0_T0OUTPS1_MASK                     equ 0002h
T0CON0_T0OUTPS2_POSN                     equ 0002h
T0CON0_T0OUTPS2_POSITION                 equ 0002h
T0CON0_T0OUTPS2_SIZE                     equ 0001h
T0CON0_T0OUTPS2_LENGTH                   equ 0001h
T0CON0_T0OUTPS2_MASK                     equ 0004h
T0CON0_T0OUTPS3_POSN                     equ 0003h
T0CON0_T0OUTPS3_POSITION                 equ 0003h
T0CON0_T0OUTPS3_SIZE                     equ 0001h
T0CON0_T0OUTPS3_LENGTH                   equ 0001h
T0CON0_T0OUTPS3_MASK                     equ 0008h

// Register: T0CON1
#define T0CON1 T0CON1
T0CON1                                   equ 019Fh
// bitfield definitions
T0CON1_CKPS_POSN                         equ 0000h
T0CON1_CKPS_POSITION                     equ 0000h
T0CON1_CKPS_SIZE                         equ 0004h
T0CON1_CKPS_LENGTH                       equ 0004h
T0CON1_CKPS_MASK                         equ 000Fh
T0CON1_ASYNC_POSN                        equ 0004h
T0CON1_ASYNC_POSITION                    equ 0004h
T0CON1_ASYNC_SIZE                        equ 0001h
T0CON1_ASYNC_LENGTH                      equ 0001h
T0CON1_ASYNC_MASK                        equ 0010h
T0CON1_CS_POSN                           equ 0005h
T0CON1_CS_POSITION                       equ 0005h
T0CON1_CS_SIZE                           equ 0003h
T0CON1_CS_LENGTH                         equ 0003h
T0CON1_CS_MASK                           equ 00E0h
T0CON1_CKPS0_POSN                        equ 0000h
T0CON1_CKPS0_POSITION                    equ 0000h
T0CON1_CKPS0_SIZE                        equ 0001h
T0CON1_CKPS0_LENGTH                      equ 0001h
T0CON1_CKPS0_MASK                        equ 0001h
T0CON1_CKPS1_POSN                        equ 0001h
T0CON1_CKPS1_POSITION                    equ 0001h
T0CON1_CKPS1_SIZE                        equ 0001h
T0CON1_CKPS1_LENGTH                      equ 0001h
T0CON1_CKPS1_MASK                        equ 0002h
T0CON1_CKPS2_POSN                        equ 0002h
T0CON1_CKPS2_POSITION                    equ 0002h
T0CON1_CKPS2_SIZE                        equ 0001h
T0CON1_CKPS2_LENGTH                      equ 0001h
T0CON1_CKPS2_MASK                        equ 0004h
T0CON1_CKPS3_POSN                        equ 0003h
T0CON1_CKPS3_POSITION                    equ 0003h
T0CON1_CKPS3_SIZE                        equ 0001h
T0CON1_CKPS3_LENGTH                      equ 0001h
T0CON1_CKPS3_MASK                        equ 0008h
T0CON1_T0ASYNC_POSN                      equ 0004h
T0CON1_T0ASYNC_POSITION                  equ 0004h
T0CON1_T0ASYNC_SIZE                      equ 0001h
T0CON1_T0ASYNC_LENGTH                    equ 0001h
T0CON1_T0ASYNC_MASK                      equ 0010h
T0CON1_CS0_POSN                          equ 0005h
T0CON1_CS0_POSITION                      equ 0005h
T0CON1_CS0_SIZE                          equ 0001h
T0CON1_CS0_LENGTH                        equ 0001h
T0CON1_CS0_MASK                          equ 0020h
T0CON1_CS1_POSN                          equ 0006h
T0CON1_CS1_POSITION                      equ 0006h
T0CON1_CS1_SIZE                          equ 0001h
T0CON1_CS1_LENGTH                        equ 0001h
T0CON1_CS1_MASK                          equ 0040h
T0CON1_CS2_POSN                          equ 0007h
T0CON1_CS2_POSITION                      equ 0007h
T0CON1_CS2_SIZE                          equ 0001h
T0CON1_CS2_LENGTH                        equ 0001h
T0CON1_CS2_MASK                          equ 0080h
T0CON1_T0CKPS_POSN                       equ 0000h
T0CON1_T0CKPS_POSITION                   equ 0000h
T0CON1_T0CKPS_SIZE                       equ 0004h
T0CON1_T0CKPS_LENGTH                     equ 0004h
T0CON1_T0CKPS_MASK                       equ 000Fh
T0CON1_T0CS_POSN                         equ 0005h
T0CON1_T0CS_POSITION                     equ 0005h
T0CON1_T0CS_SIZE                         equ 0003h
T0CON1_T0CS_LENGTH                       equ 0003h
T0CON1_T0CS_MASK                         equ 00E0h
T0CON1_T0CKPS0_POSN                      equ 0000h
T0CON1_T0CKPS0_POSITION                  equ 0000h
T0CON1_T0CKPS0_SIZE                      equ 0001h
T0CON1_T0CKPS0_LENGTH                    equ 0001h
T0CON1_T0CKPS0_MASK                      equ 0001h
T0CON1_T0CKPS1_POSN                      equ 0001h
T0CON1_T0CKPS1_POSITION                  equ 0001h
T0CON1_T0CKPS1_SIZE                      equ 0001h
T0CON1_T0CKPS1_LENGTH                    equ 0001h
T0CON1_T0CKPS1_MASK                      equ 0002h
T0CON1_T0CKPS2_POSN                      equ 0002h
T0CON1_T0CKPS2_POSITION                  equ 0002h
T0CON1_T0CKPS2_SIZE                      equ 0001h
T0CON1_T0CKPS2_LENGTH                    equ 0001h
T0CON1_T0CKPS2_MASK                      equ 0004h
T0CON1_T0CKPS3_POSN                      equ 0003h
T0CON1_T0CKPS3_POSITION                  equ 0003h
T0CON1_T0CKPS3_SIZE                      equ 0001h
T0CON1_T0CKPS3_LENGTH                    equ 0001h
T0CON1_T0CKPS3_MASK                      equ 0008h
T0CON1_T0CS0_POSN                        equ 0005h
T0CON1_T0CS0_POSITION                    equ 0005h
T0CON1_T0CS0_SIZE                        equ 0001h
T0CON1_T0CS0_LENGTH                      equ 0001h
T0CON1_T0CS0_MASK                        equ 0020h
T0CON1_T0CS1_POSN                        equ 0006h
T0CON1_T0CS1_POSITION                    equ 0006h
T0CON1_T0CS1_SIZE                        equ 0001h
T0CON1_T0CS1_LENGTH                      equ 0001h
T0CON1_T0CS1_MASK                        equ 0040h
T0CON1_T0CS2_POSN                        equ 0007h
T0CON1_T0CS2_POSITION                    equ 0007h
T0CON1_T0CS2_SIZE                        equ 0001h
T0CON1_T0CS2_LENGTH                      equ 0001h
T0CON1_T0CS2_MASK                        equ 0080h

// Register: FVRCON
#define FVRCON FVRCON
FVRCON                                   equ 020Ch
// bitfield definitions
FVRCON_ADFVR_POSN                        equ 0000h
FVRCON_ADFVR_POSITION                    equ 0000h
FVRCON_ADFVR_SIZE                        equ 0002h
FVRCON_ADFVR_LENGTH                      equ 0002h
FVRCON_ADFVR_MASK                        equ 0003h
FVRCON_CDAFVR_POSN                       equ 0002h
FVRCON_CDAFVR_POSITION                   equ 0002h
FVRCON_CDAFVR_SIZE                       equ 0002h
FVRCON_CDAFVR_LENGTH                     equ 0002h
FVRCON_CDAFVR_MASK                       equ 000Ch
FVRCON_TSRNG_POSN                        equ 0004h
FVRCON_TSRNG_POSITION                    equ 0004h
FVRCON_TSRNG_SIZE                        equ 0001h
FVRCON_TSRNG_LENGTH                      equ 0001h
FVRCON_TSRNG_MASK                        equ 0010h
FVRCON_TSEN_POSN                         equ 0005h
FVRCON_TSEN_POSITION                     equ 0005h
FVRCON_TSEN_SIZE                         equ 0001h
FVRCON_TSEN_LENGTH                       equ 0001h
FVRCON_TSEN_MASK                         equ 0020h
FVRCON_RDY_POSN                          equ 0006h
FVRCON_RDY_POSITION                      equ 0006h
FVRCON_RDY_SIZE                          equ 0001h
FVRCON_RDY_LENGTH                        equ 0001h
FVRCON_RDY_MASK                          equ 0040h
FVRCON_EN_POSN                           equ 0007h
FVRCON_EN_POSITION                       equ 0007h
FVRCON_EN_SIZE                           equ 0001h
FVRCON_EN_LENGTH                         equ 0001h
FVRCON_EN_MASK                           equ 0080h
FVRCON_ADFVR0_POSN                       equ 0000h
FVRCON_ADFVR0_POSITION                   equ 0000h
FVRCON_ADFVR0_SIZE                       equ 0001h
FVRCON_ADFVR0_LENGTH                     equ 0001h
FVRCON_ADFVR0_MASK                       equ 0001h
FVRCON_ADFVR1_POSN                       equ 0001h
FVRCON_ADFVR1_POSITION                   equ 0001h
FVRCON_ADFVR1_SIZE                       equ 0001h
FVRCON_ADFVR1_LENGTH                     equ 0001h
FVRCON_ADFVR1_MASK                       equ 0002h
FVRCON_CDAFVR0_POSN                      equ 0002h
FVRCON_CDAFVR0_POSITION                  equ 0002h
FVRCON_CDAFVR0_SIZE                      equ 0001h
FVRCON_CDAFVR0_LENGTH                    equ 0001h
FVRCON_CDAFVR0_MASK                      equ 0004h
FVRCON_CDAFVR1_POSN                      equ 0003h
FVRCON_CDAFVR1_POSITION                  equ 0003h
FVRCON_CDAFVR1_SIZE                      equ 0001h
FVRCON_CDAFVR1_LENGTH                    equ 0001h
FVRCON_CDAFVR1_MASK                      equ 0008h
FVRCON_FVRRDY_POSN                       equ 0006h
FVRCON_FVRRDY_POSITION                   equ 0006h
FVRCON_FVRRDY_SIZE                       equ 0001h
FVRCON_FVRRDY_LENGTH                     equ 0001h
FVRCON_FVRRDY_MASK                       equ 0040h
FVRCON_FVREN_POSN                        equ 0007h
FVRCON_FVREN_POSITION                    equ 0007h
FVRCON_FVREN_SIZE                        equ 0001h
FVRCON_FVREN_LENGTH                      equ 0001h
FVRCON_FVREN_MASK                        equ 0080h

// Register: CPCON
#define CPCON CPCON
CPCON                                    equ 020Dh
// bitfield definitions
CPCON_CPRDY_POSN                         equ 0000h
CPCON_CPRDY_POSITION                     equ 0000h
CPCON_CPRDY_SIZE                         equ 0001h
CPCON_CPRDY_LENGTH                       equ 0001h
CPCON_CPRDY_MASK                         equ 0001h
CPCON_CPT_POSN                           equ 0001h
CPCON_CPT_POSITION                       equ 0001h
CPCON_CPT_SIZE                           equ 0001h
CPCON_CPT_LENGTH                         equ 0001h
CPCON_CPT_MASK                           equ 0002h
CPCON_CPREQ_POSN                         equ 0002h
CPCON_CPREQ_POSITION                     equ 0002h
CPCON_CPREQ_SIZE                         equ 0001h
CPCON_CPREQ_LENGTH                       equ 0001h
CPCON_CPREQ_MASK                         equ 0004h
CPCON_CPOS_POSN                          equ 0005h
CPCON_CPOS_POSITION                      equ 0005h
CPCON_CPOS_SIZE                          equ 0001h
CPCON_CPOS_LENGTH                        equ 0001h
CPCON_CPOS_MASK                          equ 0020h
CPCON_CPON_POSN                          equ 0006h
CPCON_CPON_POSITION                      equ 0006h
CPCON_CPON_SIZE                          equ 0002h
CPCON_CPON_LENGTH                        equ 0002h
CPCON_CPON_MASK                          equ 00C0h

// Register: CPUDOZE
#define CPUDOZE CPUDOZE
CPUDOZE                                  equ 028Ch
// bitfield definitions
CPUDOZE_DOZE_POSN                        equ 0000h
CPUDOZE_DOZE_POSITION                    equ 0000h
CPUDOZE_DOZE_SIZE                        equ 0003h
CPUDOZE_DOZE_LENGTH                      equ 0003h
CPUDOZE_DOZE_MASK                        equ 0007h
CPUDOZE_DOE_POSN                         equ 0004h
CPUDOZE_DOE_POSITION                     equ 0004h
CPUDOZE_DOE_SIZE                         equ 0001h
CPUDOZE_DOE_LENGTH                       equ 0001h
CPUDOZE_DOE_MASK                         equ 0010h
CPUDOZE_ROI_POSN                         equ 0005h
CPUDOZE_ROI_POSITION                     equ 0005h
CPUDOZE_ROI_SIZE                         equ 0001h
CPUDOZE_ROI_LENGTH                       equ 0001h
CPUDOZE_ROI_MASK                         equ 0020h
CPUDOZE_DOZEN_POSN                       equ 0006h
CPUDOZE_DOZEN_POSITION                   equ 0006h
CPUDOZE_DOZEN_SIZE                       equ 0001h
CPUDOZE_DOZEN_LENGTH                     equ 0001h
CPUDOZE_DOZEN_MASK                       equ 0040h
CPUDOZE_IDLEN_POSN                       equ 0007h
CPUDOZE_IDLEN_POSITION                   equ 0007h
CPUDOZE_IDLEN_SIZE                       equ 0001h
CPUDOZE_IDLEN_LENGTH                     equ 0001h
CPUDOZE_IDLEN_MASK                       equ 0080h

// Register: OSCCON1
#define OSCCON1 OSCCON1
OSCCON1                                  equ 028Dh
// bitfield definitions
OSCCON1_NDIV_POSN                        equ 0000h
OSCCON1_NDIV_POSITION                    equ 0000h
OSCCON1_NDIV_SIZE                        equ 0004h
OSCCON1_NDIV_LENGTH                      equ 0004h
OSCCON1_NDIV_MASK                        equ 000Fh
OSCCON1_NOSC_POSN                        equ 0004h
OSCCON1_NOSC_POSITION                    equ 0004h
OSCCON1_NOSC_SIZE                        equ 0003h
OSCCON1_NOSC_LENGTH                      equ 0003h
OSCCON1_NOSC_MASK                        equ 0070h
OSCCON1_NDIV0_POSN                       equ 0000h
OSCCON1_NDIV0_POSITION                   equ 0000h
OSCCON1_NDIV0_SIZE                       equ 0001h
OSCCON1_NDIV0_LENGTH                     equ 0001h
OSCCON1_NDIV0_MASK                       equ 0001h
OSCCON1_NDIV1_POSN                       equ 0001h
OSCCON1_NDIV1_POSITION                   equ 0001h
OSCCON1_NDIV1_SIZE                       equ 0001h
OSCCON1_NDIV1_LENGTH                     equ 0001h
OSCCON1_NDIV1_MASK                       equ 0002h
OSCCON1_NDIV2_POSN                       equ 0002h
OSCCON1_NDIV2_POSITION                   equ 0002h
OSCCON1_NDIV2_SIZE                       equ 0001h
OSCCON1_NDIV2_LENGTH                     equ 0001h
OSCCON1_NDIV2_MASK                       equ 0004h
OSCCON1_NDIV3_POSN                       equ 0003h
OSCCON1_NDIV3_POSITION                   equ 0003h
OSCCON1_NDIV3_SIZE                       equ 0001h
OSCCON1_NDIV3_LENGTH                     equ 0001h
OSCCON1_NDIV3_MASK                       equ 0008h
OSCCON1_NOSC0_POSN                       equ 0004h
OSCCON1_NOSC0_POSITION                   equ 0004h
OSCCON1_NOSC0_SIZE                       equ 0001h
OSCCON1_NOSC0_LENGTH                     equ 0001h
OSCCON1_NOSC0_MASK                       equ 0010h
OSCCON1_NOSC1_POSN                       equ 0005h
OSCCON1_NOSC1_POSITION                   equ 0005h
OSCCON1_NOSC1_SIZE                       equ 0001h
OSCCON1_NOSC1_LENGTH                     equ 0001h
OSCCON1_NOSC1_MASK                       equ 0020h
OSCCON1_NOSC2_POSN                       equ 0006h
OSCCON1_NOSC2_POSITION                   equ 0006h
OSCCON1_NOSC2_SIZE                       equ 0001h
OSCCON1_NOSC2_LENGTH                     equ 0001h
OSCCON1_NOSC2_MASK                       equ 0040h

// Register: OSCCON2
#define OSCCON2 OSCCON2
OSCCON2                                  equ 028Eh
// bitfield definitions
OSCCON2_CDIV_POSN                        equ 0000h
OSCCON2_CDIV_POSITION                    equ 0000h
OSCCON2_CDIV_SIZE                        equ 0004h
OSCCON2_CDIV_LENGTH                      equ 0004h
OSCCON2_CDIV_MASK                        equ 000Fh
OSCCON2_COSC_POSN                        equ 0004h
OSCCON2_COSC_POSITION                    equ 0004h
OSCCON2_COSC_SIZE                        equ 0003h
OSCCON2_COSC_LENGTH                      equ 0003h
OSCCON2_COSC_MASK                        equ 0070h
OSCCON2_CDIV0_POSN                       equ 0000h
OSCCON2_CDIV0_POSITION                   equ 0000h
OSCCON2_CDIV0_SIZE                       equ 0001h
OSCCON2_CDIV0_LENGTH                     equ 0001h
OSCCON2_CDIV0_MASK                       equ 0001h
OSCCON2_CDIV1_POSN                       equ 0001h
OSCCON2_CDIV1_POSITION                   equ 0001h
OSCCON2_CDIV1_SIZE                       equ 0001h
OSCCON2_CDIV1_LENGTH                     equ 0001h
OSCCON2_CDIV1_MASK                       equ 0002h
OSCCON2_CDIV2_POSN                       equ 0002h
OSCCON2_CDIV2_POSITION                   equ 0002h
OSCCON2_CDIV2_SIZE                       equ 0001h
OSCCON2_CDIV2_LENGTH                     equ 0001h
OSCCON2_CDIV2_MASK                       equ 0004h
OSCCON2_CDIV3_POSN                       equ 0003h
OSCCON2_CDIV3_POSITION                   equ 0003h
OSCCON2_CDIV3_SIZE                       equ 0001h
OSCCON2_CDIV3_LENGTH                     equ 0001h
OSCCON2_CDIV3_MASK                       equ 0008h
OSCCON2_COSC0_POSN                       equ 0004h
OSCCON2_COSC0_POSITION                   equ 0004h
OSCCON2_COSC0_SIZE                       equ 0001h
OSCCON2_COSC0_LENGTH                     equ 0001h
OSCCON2_COSC0_MASK                       equ 0010h
OSCCON2_COSC1_POSN                       equ 0005h
OSCCON2_COSC1_POSITION                   equ 0005h
OSCCON2_COSC1_SIZE                       equ 0001h
OSCCON2_COSC1_LENGTH                     equ 0001h
OSCCON2_COSC1_MASK                       equ 0020h
OSCCON2_COSC2_POSN                       equ 0006h
OSCCON2_COSC2_POSITION                   equ 0006h
OSCCON2_COSC2_SIZE                       equ 0001h
OSCCON2_COSC2_LENGTH                     equ 0001h
OSCCON2_COSC2_MASK                       equ 0040h

// Register: OSCCON3
#define OSCCON3 OSCCON3
OSCCON3                                  equ 028Fh
// bitfield definitions
OSCCON3_NOSCR_POSN                       equ 0003h
OSCCON3_NOSCR_POSITION                   equ 0003h
OSCCON3_NOSCR_SIZE                       equ 0001h
OSCCON3_NOSCR_LENGTH                     equ 0001h
OSCCON3_NOSCR_MASK                       equ 0008h
OSCCON3_ORDY_POSN                        equ 0004h
OSCCON3_ORDY_POSITION                    equ 0004h
OSCCON3_ORDY_SIZE                        equ 0001h
OSCCON3_ORDY_LENGTH                      equ 0001h
OSCCON3_ORDY_MASK                        equ 0010h
OSCCON3_CSWHOLD_POSN                     equ 0007h
OSCCON3_CSWHOLD_POSITION                 equ 0007h
OSCCON3_CSWHOLD_SIZE                     equ 0001h
OSCCON3_CSWHOLD_LENGTH                   equ 0001h
OSCCON3_CSWHOLD_MASK                     equ 0080h

// Register: OSCSTAT
#define OSCSTAT OSCSTAT
OSCSTAT                                  equ 0290h
// bitfield definitions
OSCSTAT_PLLR_POSN                        equ 0000h
OSCSTAT_PLLR_POSITION                    equ 0000h
OSCSTAT_PLLR_SIZE                        equ 0001h
OSCSTAT_PLLR_LENGTH                      equ 0001h
OSCSTAT_PLLR_MASK                        equ 0001h
OSCSTAT_SFOR_POSN                        equ 0001h
OSCSTAT_SFOR_POSITION                    equ 0001h
OSCSTAT_SFOR_SIZE                        equ 0001h
OSCSTAT_SFOR_LENGTH                      equ 0001h
OSCSTAT_SFOR_MASK                        equ 0002h
OSCSTAT_ADOR_POSN                        equ 0002h
OSCSTAT_ADOR_POSITION                    equ 0002h
OSCSTAT_ADOR_SIZE                        equ 0001h
OSCSTAT_ADOR_LENGTH                      equ 0001h
OSCSTAT_ADOR_MASK                        equ 0004h
OSCSTAT_LFOR_POSN                        equ 0004h
OSCSTAT_LFOR_POSITION                    equ 0004h
OSCSTAT_LFOR_SIZE                        equ 0001h
OSCSTAT_LFOR_LENGTH                      equ 0001h
OSCSTAT_LFOR_MASK                        equ 0010h
OSCSTAT_MFOR_POSN                        equ 0005h
OSCSTAT_MFOR_POSITION                    equ 0005h
OSCSTAT_MFOR_SIZE                        equ 0001h
OSCSTAT_MFOR_LENGTH                      equ 0001h
OSCSTAT_MFOR_MASK                        equ 0020h
OSCSTAT_HFOR_POSN                        equ 0006h
OSCSTAT_HFOR_POSITION                    equ 0006h
OSCSTAT_HFOR_SIZE                        equ 0001h
OSCSTAT_HFOR_LENGTH                      equ 0001h
OSCSTAT_HFOR_MASK                        equ 0040h
OSCSTAT_EXTOR_POSN                       equ 0007h
OSCSTAT_EXTOR_POSITION                   equ 0007h
OSCSTAT_EXTOR_SIZE                       equ 0001h
OSCSTAT_EXTOR_LENGTH                     equ 0001h
OSCSTAT_EXTOR_MASK                       equ 0080h

// Register: OSCEN
#define OSCEN OSCEN
OSCEN                                    equ 0291h
// bitfield definitions
OSCEN_PLLEN_POSN                         equ 0000h
OSCEN_PLLEN_POSITION                     equ 0000h
OSCEN_PLLEN_SIZE                         equ 0001h
OSCEN_PLLEN_LENGTH                       equ 0001h
OSCEN_PLLEN_MASK                         equ 0001h
OSCEN_ADOEN_POSN                         equ 0002h
OSCEN_ADOEN_POSITION                     equ 0002h
OSCEN_ADOEN_SIZE                         equ 0001h
OSCEN_ADOEN_LENGTH                       equ 0001h
OSCEN_ADOEN_MASK                         equ 0004h
OSCEN_LFOEN_POSN                         equ 0004h
OSCEN_LFOEN_POSITION                     equ 0004h
OSCEN_LFOEN_SIZE                         equ 0001h
OSCEN_LFOEN_LENGTH                       equ 0001h
OSCEN_LFOEN_MASK                         equ 0010h
OSCEN_MFOEN_POSN                         equ 0005h
OSCEN_MFOEN_POSITION                     equ 0005h
OSCEN_MFOEN_SIZE                         equ 0001h
OSCEN_MFOEN_LENGTH                       equ 0001h
OSCEN_MFOEN_MASK                         equ 0020h
OSCEN_HFOEN_POSN                         equ 0006h
OSCEN_HFOEN_POSITION                     equ 0006h
OSCEN_HFOEN_SIZE                         equ 0001h
OSCEN_HFOEN_LENGTH                       equ 0001h
OSCEN_HFOEN_MASK                         equ 0040h
OSCEN_EXTOEN_POSN                        equ 0007h
OSCEN_EXTOEN_POSITION                    equ 0007h
OSCEN_EXTOEN_SIZE                        equ 0001h
OSCEN_EXTOEN_LENGTH                      equ 0001h
OSCEN_EXTOEN_MASK                        equ 0080h

// Register: OSCTUNE
#define OSCTUNE OSCTUNE
OSCTUNE                                  equ 0292h
// bitfield definitions
OSCTUNE_TUN_POSN                         equ 0000h
OSCTUNE_TUN_POSITION                     equ 0000h
OSCTUNE_TUN_SIZE                         equ 0006h
OSCTUNE_TUN_LENGTH                       equ 0006h
OSCTUNE_TUN_MASK                         equ 003Fh
OSCTUNE_TUN0_POSN                        equ 0000h
OSCTUNE_TUN0_POSITION                    equ 0000h
OSCTUNE_TUN0_SIZE                        equ 0001h
OSCTUNE_TUN0_LENGTH                      equ 0001h
OSCTUNE_TUN0_MASK                        equ 0001h
OSCTUNE_TUN1_POSN                        equ 0001h
OSCTUNE_TUN1_POSITION                    equ 0001h
OSCTUNE_TUN1_SIZE                        equ 0001h
OSCTUNE_TUN1_LENGTH                      equ 0001h
OSCTUNE_TUN1_MASK                        equ 0002h
OSCTUNE_TUN2_POSN                        equ 0002h
OSCTUNE_TUN2_POSITION                    equ 0002h
OSCTUNE_TUN2_SIZE                        equ 0001h
OSCTUNE_TUN2_LENGTH                      equ 0001h
OSCTUNE_TUN2_MASK                        equ 0004h
OSCTUNE_TUN3_POSN                        equ 0003h
OSCTUNE_TUN3_POSITION                    equ 0003h
OSCTUNE_TUN3_SIZE                        equ 0001h
OSCTUNE_TUN3_LENGTH                      equ 0001h
OSCTUNE_TUN3_MASK                        equ 0008h
OSCTUNE_TUN4_POSN                        equ 0004h
OSCTUNE_TUN4_POSITION                    equ 0004h
OSCTUNE_TUN4_SIZE                        equ 0001h
OSCTUNE_TUN4_LENGTH                      equ 0001h
OSCTUNE_TUN4_MASK                        equ 0010h
OSCTUNE_TUN5_POSN                        equ 0005h
OSCTUNE_TUN5_POSITION                    equ 0005h
OSCTUNE_TUN5_SIZE                        equ 0001h
OSCTUNE_TUN5_LENGTH                      equ 0001h
OSCTUNE_TUN5_MASK                        equ 0020h

// Register: OSCFRQ
#define OSCFRQ OSCFRQ
OSCFRQ                                   equ 0293h
// bitfield definitions
OSCFRQ_FRQ_POSN                          equ 0000h
OSCFRQ_FRQ_POSITION                      equ 0000h
OSCFRQ_FRQ_SIZE                          equ 0003h
OSCFRQ_FRQ_LENGTH                        equ 0003h
OSCFRQ_FRQ_MASK                          equ 0007h
OSCFRQ_FRQ0_POSN                         equ 0000h
OSCFRQ_FRQ0_POSITION                     equ 0000h
OSCFRQ_FRQ0_SIZE                         equ 0001h
OSCFRQ_FRQ0_LENGTH                       equ 0001h
OSCFRQ_FRQ0_MASK                         equ 0001h
OSCFRQ_FRQ1_POSN                         equ 0001h
OSCFRQ_FRQ1_POSITION                     equ 0001h
OSCFRQ_FRQ1_SIZE                         equ 0001h
OSCFRQ_FRQ1_LENGTH                       equ 0001h
OSCFRQ_FRQ1_MASK                         equ 0002h
OSCFRQ_FRQ2_POSN                         equ 0002h
OSCFRQ_FRQ2_POSITION                     equ 0002h
OSCFRQ_FRQ2_SIZE                         equ 0001h
OSCFRQ_FRQ2_LENGTH                       equ 0001h
OSCFRQ_FRQ2_MASK                         equ 0004h

// Register: TMR1L
#define TMR1L TMR1L
TMR1L                                    equ 030Ch
// bitfield definitions
TMR1L_TMR1L_POSN                         equ 0000h
TMR1L_TMR1L_POSITION                     equ 0000h
TMR1L_TMR1L_SIZE                         equ 0008h
TMR1L_TMR1L_LENGTH                       equ 0008h
TMR1L_TMR1L_MASK                         equ 00FFh
TMR1L_TMR1L0_POSN                        equ 0000h
TMR1L_TMR1L0_POSITION                    equ 0000h
TMR1L_TMR1L0_SIZE                        equ 0001h
TMR1L_TMR1L0_LENGTH                      equ 0001h
TMR1L_TMR1L0_MASK                        equ 0001h
TMR1L_TMR1L1_POSN                        equ 0001h
TMR1L_TMR1L1_POSITION                    equ 0001h
TMR1L_TMR1L1_SIZE                        equ 0001h
TMR1L_TMR1L1_LENGTH                      equ 0001h
TMR1L_TMR1L1_MASK                        equ 0002h
TMR1L_TMR1L2_POSN                        equ 0002h
TMR1L_TMR1L2_POSITION                    equ 0002h
TMR1L_TMR1L2_SIZE                        equ 0001h
TMR1L_TMR1L2_LENGTH                      equ 0001h
TMR1L_TMR1L2_MASK                        equ 0004h
TMR1L_TMR1L3_POSN                        equ 0003h
TMR1L_TMR1L3_POSITION                    equ 0003h
TMR1L_TMR1L3_SIZE                        equ 0001h
TMR1L_TMR1L3_LENGTH                      equ 0001h
TMR1L_TMR1L3_MASK                        equ 0008h
TMR1L_TMR1L4_POSN                        equ 0004h
TMR1L_TMR1L4_POSITION                    equ 0004h
TMR1L_TMR1L4_SIZE                        equ 0001h
TMR1L_TMR1L4_LENGTH                      equ 0001h
TMR1L_TMR1L4_MASK                        equ 0010h
TMR1L_TMR1L5_POSN                        equ 0005h
TMR1L_TMR1L5_POSITION                    equ 0005h
TMR1L_TMR1L5_SIZE                        equ 0001h
TMR1L_TMR1L5_LENGTH                      equ 0001h
TMR1L_TMR1L5_MASK                        equ 0020h
TMR1L_TMR1L6_POSN                        equ 0006h
TMR1L_TMR1L6_POSITION                    equ 0006h
TMR1L_TMR1L6_SIZE                        equ 0001h
TMR1L_TMR1L6_LENGTH                      equ 0001h
TMR1L_TMR1L6_MASK                        equ 0040h
TMR1L_TMR1L7_POSN                        equ 0007h
TMR1L_TMR1L7_POSITION                    equ 0007h
TMR1L_TMR1L7_SIZE                        equ 0001h
TMR1L_TMR1L7_LENGTH                      equ 0001h
TMR1L_TMR1L7_MASK                        equ 0080h
TMR1L_TMR10_POSN                         equ 0000h
TMR1L_TMR10_POSITION                     equ 0000h
TMR1L_TMR10_SIZE                         equ 0001h
TMR1L_TMR10_LENGTH                       equ 0001h
TMR1L_TMR10_MASK                         equ 0001h
TMR1L_TMR11_POSN                         equ 0001h
TMR1L_TMR11_POSITION                     equ 0001h
TMR1L_TMR11_SIZE                         equ 0001h
TMR1L_TMR11_LENGTH                       equ 0001h
TMR1L_TMR11_MASK                         equ 0002h
TMR1L_TMR12_POSN                         equ 0002h
TMR1L_TMR12_POSITION                     equ 0002h
TMR1L_TMR12_SIZE                         equ 0001h
TMR1L_TMR12_LENGTH                       equ 0001h
TMR1L_TMR12_MASK                         equ 0004h
TMR1L_TMR13_POSN                         equ 0003h
TMR1L_TMR13_POSITION                     equ 0003h
TMR1L_TMR13_SIZE                         equ 0001h
TMR1L_TMR13_LENGTH                       equ 0001h
TMR1L_TMR13_MASK                         equ 0008h
TMR1L_TMR14_POSN                         equ 0004h
TMR1L_TMR14_POSITION                     equ 0004h
TMR1L_TMR14_SIZE                         equ 0001h
TMR1L_TMR14_LENGTH                       equ 0001h
TMR1L_TMR14_MASK                         equ 0010h
TMR1L_TMR15_POSN                         equ 0005h
TMR1L_TMR15_POSITION                     equ 0005h
TMR1L_TMR15_SIZE                         equ 0001h
TMR1L_TMR15_LENGTH                       equ 0001h
TMR1L_TMR15_MASK                         equ 0020h
TMR1L_TMR16_POSN                         equ 0006h
TMR1L_TMR16_POSITION                     equ 0006h
TMR1L_TMR16_SIZE                         equ 0001h
TMR1L_TMR16_LENGTH                       equ 0001h
TMR1L_TMR16_MASK                         equ 0040h
TMR1L_TMR17_POSN                         equ 0007h
TMR1L_TMR17_POSITION                     equ 0007h
TMR1L_TMR17_SIZE                         equ 0001h
TMR1L_TMR17_LENGTH                       equ 0001h
TMR1L_TMR17_MASK                         equ 0080h
TMR1L_CAL01_POSN                         equ 0000h
TMR1L_CAL01_POSITION                     equ 0000h
TMR1L_CAL01_SIZE                         equ 0001h
TMR1L_CAL01_LENGTH                       equ 0001h
TMR1L_CAL01_MASK                         equ 0001h
TMR1L_CAL11_POSN                         equ 0001h
TMR1L_CAL11_POSITION                     equ 0001h
TMR1L_CAL11_SIZE                         equ 0001h
TMR1L_CAL11_LENGTH                       equ 0001h
TMR1L_CAL11_MASK                         equ 0002h
TMR1L_CAL21_POSN                         equ 0002h
TMR1L_CAL21_POSITION                     equ 0002h
TMR1L_CAL21_SIZE                         equ 0001h
TMR1L_CAL21_LENGTH                       equ 0001h
TMR1L_CAL21_MASK                         equ 0004h
TMR1L_CAL31_POSN                         equ 0003h
TMR1L_CAL31_POSITION                     equ 0003h
TMR1L_CAL31_SIZE                         equ 0001h
TMR1L_CAL31_LENGTH                       equ 0001h
TMR1L_CAL31_MASK                         equ 0008h
TMR1L_CAL41_POSN                         equ 0004h
TMR1L_CAL41_POSITION                     equ 0004h
TMR1L_CAL41_SIZE                         equ 0001h
TMR1L_CAL41_LENGTH                       equ 0001h
TMR1L_CAL41_MASK                         equ 0010h
TMR1L_CAL51_POSN                         equ 0005h
TMR1L_CAL51_POSITION                     equ 0005h
TMR1L_CAL51_SIZE                         equ 0001h
TMR1L_CAL51_LENGTH                       equ 0001h
TMR1L_CAL51_MASK                         equ 0020h
TMR1L_CAL61_POSN                         equ 0006h
TMR1L_CAL61_POSITION                     equ 0006h
TMR1L_CAL61_SIZE                         equ 0001h
TMR1L_CAL61_LENGTH                       equ 0001h
TMR1L_CAL61_MASK                         equ 0040h
TMR1L_CAL71_POSN                         equ 0007h
TMR1L_CAL71_POSITION                     equ 0007h
TMR1L_CAL71_SIZE                         equ 0001h
TMR1L_CAL71_LENGTH                       equ 0001h
TMR1L_CAL71_MASK                         equ 0080h

// Register: TMR1H
#define TMR1H TMR1H
TMR1H                                    equ 030Dh
// bitfield definitions
TMR1H_TMR1H_POSN                         equ 0000h
TMR1H_TMR1H_POSITION                     equ 0000h
TMR1H_TMR1H_SIZE                         equ 0008h
TMR1H_TMR1H_LENGTH                       equ 0008h
TMR1H_TMR1H_MASK                         equ 00FFh
TMR1H_TMR1H0_POSN                        equ 0000h
TMR1H_TMR1H0_POSITION                    equ 0000h
TMR1H_TMR1H0_SIZE                        equ 0001h
TMR1H_TMR1H0_LENGTH                      equ 0001h
TMR1H_TMR1H0_MASK                        equ 0001h
TMR1H_TMR1H1_POSN                        equ 0001h
TMR1H_TMR1H1_POSITION                    equ 0001h
TMR1H_TMR1H1_SIZE                        equ 0001h
TMR1H_TMR1H1_LENGTH                      equ 0001h
TMR1H_TMR1H1_MASK                        equ 0002h
TMR1H_TMR1H2_POSN                        equ 0002h
TMR1H_TMR1H2_POSITION                    equ 0002h
TMR1H_TMR1H2_SIZE                        equ 0001h
TMR1H_TMR1H2_LENGTH                      equ 0001h
TMR1H_TMR1H2_MASK                        equ 0004h
TMR1H_TMR1H3_POSN                        equ 0003h
TMR1H_TMR1H3_POSITION                    equ 0003h
TMR1H_TMR1H3_SIZE                        equ 0001h
TMR1H_TMR1H3_LENGTH                      equ 0001h
TMR1H_TMR1H3_MASK                        equ 0008h
TMR1H_TMR1H4_POSN                        equ 0004h
TMR1H_TMR1H4_POSITION                    equ 0004h
TMR1H_TMR1H4_SIZE                        equ 0001h
TMR1H_TMR1H4_LENGTH                      equ 0001h
TMR1H_TMR1H4_MASK                        equ 0010h
TMR1H_TMR1H5_POSN                        equ 0005h
TMR1H_TMR1H5_POSITION                    equ 0005h
TMR1H_TMR1H5_SIZE                        equ 0001h
TMR1H_TMR1H5_LENGTH                      equ 0001h
TMR1H_TMR1H5_MASK                        equ 0020h
TMR1H_TMR1H6_POSN                        equ 0006h
TMR1H_TMR1H6_POSITION                    equ 0006h
TMR1H_TMR1H6_SIZE                        equ 0001h
TMR1H_TMR1H6_LENGTH                      equ 0001h
TMR1H_TMR1H6_MASK                        equ 0040h
TMR1H_TMR1H7_POSN                        equ 0007h
TMR1H_TMR1H7_POSITION                    equ 0007h
TMR1H_TMR1H7_SIZE                        equ 0001h
TMR1H_TMR1H7_LENGTH                      equ 0001h
TMR1H_TMR1H7_MASK                        equ 0080h
TMR1H_TMR18_POSN                         equ 0000h
TMR1H_TMR18_POSITION                     equ 0000h
TMR1H_TMR18_SIZE                         equ 0001h
TMR1H_TMR18_LENGTH                       equ 0001h
TMR1H_TMR18_MASK                         equ 0001h
TMR1H_TMR19_POSN                         equ 0001h
TMR1H_TMR19_POSITION                     equ 0001h
TMR1H_TMR19_SIZE                         equ 0001h
TMR1H_TMR19_LENGTH                       equ 0001h
TMR1H_TMR19_MASK                         equ 0002h
TMR1H_TMR110_POSN                        equ 0002h
TMR1H_TMR110_POSITION                    equ 0002h
TMR1H_TMR110_SIZE                        equ 0001h
TMR1H_TMR110_LENGTH                      equ 0001h
TMR1H_TMR110_MASK                        equ 0004h
TMR1H_TMR111_POSN                        equ 0003h
TMR1H_TMR111_POSITION                    equ 0003h
TMR1H_TMR111_SIZE                        equ 0001h
TMR1H_TMR111_LENGTH                      equ 0001h
TMR1H_TMR111_MASK                        equ 0008h
TMR1H_TMR112_POSN                        equ 0004h
TMR1H_TMR112_POSITION                    equ 0004h
TMR1H_TMR112_SIZE                        equ 0001h
TMR1H_TMR112_LENGTH                      equ 0001h
TMR1H_TMR112_MASK                        equ 0010h
TMR1H_TMR113_POSN                        equ 0005h
TMR1H_TMR113_POSITION                    equ 0005h
TMR1H_TMR113_SIZE                        equ 0001h
TMR1H_TMR113_LENGTH                      equ 0001h
TMR1H_TMR113_MASK                        equ 0020h
TMR1H_TMR114_POSN                        equ 0006h
TMR1H_TMR114_POSITION                    equ 0006h
TMR1H_TMR114_SIZE                        equ 0001h
TMR1H_TMR114_LENGTH                      equ 0001h
TMR1H_TMR114_MASK                        equ 0040h
TMR1H_TMR115_POSN                        equ 0007h
TMR1H_TMR115_POSITION                    equ 0007h
TMR1H_TMR115_SIZE                        equ 0001h
TMR1H_TMR115_LENGTH                      equ 0001h
TMR1H_TMR115_MASK                        equ 0080h

// Register: T1CON
#define T1CON T1CON
T1CON                                    equ 030Eh
// bitfield definitions
T1CON_ON_POSN                            equ 0000h
T1CON_ON_POSITION                        equ 0000h
T1CON_ON_SIZE                            equ 0001h
T1CON_ON_LENGTH                          equ 0001h
T1CON_ON_MASK                            equ 0001h
T1CON_RD16_POSN                          equ 0001h
T1CON_RD16_POSITION                      equ 0001h
T1CON_RD16_SIZE                          equ 0001h
T1CON_RD16_LENGTH                        equ 0001h
T1CON_RD16_MASK                          equ 0002h
T1CON_nSYNC_POSN                         equ 0002h
T1CON_nSYNC_POSITION                     equ 0002h
T1CON_nSYNC_SIZE                         equ 0001h
T1CON_nSYNC_LENGTH                       equ 0001h
T1CON_nSYNC_MASK                         equ 0004h
T1CON_CKPS_POSN                          equ 0004h
T1CON_CKPS_POSITION                      equ 0004h
T1CON_CKPS_SIZE                          equ 0002h
T1CON_CKPS_LENGTH                        equ 0002h
T1CON_CKPS_MASK                          equ 0030h
T1CON_TMR1ON_POSN                        equ 0000h
T1CON_TMR1ON_POSITION                    equ 0000h
T1CON_TMR1ON_SIZE                        equ 0001h
T1CON_TMR1ON_LENGTH                      equ 0001h
T1CON_TMR1ON_MASK                        equ 0001h
T1CON_T1RD16_POSN                        equ 0001h
T1CON_T1RD16_POSITION                    equ 0001h
T1CON_T1RD16_SIZE                        equ 0001h
T1CON_T1RD16_LENGTH                      equ 0001h
T1CON_T1RD16_MASK                        equ 0002h
T1CON_nT1SYNC_POSN                       equ 0002h
T1CON_nT1SYNC_POSITION                   equ 0002h
T1CON_nT1SYNC_SIZE                       equ 0001h
T1CON_nT1SYNC_LENGTH                     equ 0001h
T1CON_nT1SYNC_MASK                       equ 0004h
T1CON_T1CKPS0_POSN                       equ 0004h
T1CON_T1CKPS0_POSITION                   equ 0004h
T1CON_T1CKPS0_SIZE                       equ 0001h
T1CON_T1CKPS0_LENGTH                     equ 0001h
T1CON_T1CKPS0_MASK                       equ 0010h
T1CON_T1CKPS1_POSN                       equ 0005h
T1CON_T1CKPS1_POSITION                   equ 0005h
T1CON_T1CKPS1_SIZE                       equ 0001h
T1CON_T1CKPS1_LENGTH                     equ 0001h
T1CON_T1CKPS1_MASK                       equ 0020h
T1CON_CKPS0_POSN                         equ 0004h
T1CON_CKPS0_POSITION                     equ 0004h
T1CON_CKPS0_SIZE                         equ 0001h
T1CON_CKPS0_LENGTH                       equ 0001h
T1CON_CKPS0_MASK                         equ 0010h
T1CON_CKPS1_POSN                         equ 0005h
T1CON_CKPS1_POSITION                     equ 0005h
T1CON_CKPS1_SIZE                         equ 0001h
T1CON_CKPS1_LENGTH                       equ 0001h
T1CON_CKPS1_MASK                         equ 0020h
T1CON_RD161_POSN                         equ 0001h
T1CON_RD161_POSITION                     equ 0001h
T1CON_RD161_SIZE                         equ 0001h
T1CON_RD161_LENGTH                       equ 0001h
T1CON_RD161_MASK                         equ 0002h

// Register: T1GCON
#define T1GCON T1GCON
T1GCON                                   equ 030Fh
// bitfield definitions
T1GCON_GVAL_POSN                         equ 0002h
T1GCON_GVAL_POSITION                     equ 0002h
T1GCON_GVAL_SIZE                         equ 0001h
T1GCON_GVAL_LENGTH                       equ 0001h
T1GCON_GVAL_MASK                         equ 0004h
T1GCON_GGO_nDONE_POSN                    equ 0003h
T1GCON_GGO_nDONE_POSITION                equ 0003h
T1GCON_GGO_nDONE_SIZE                    equ 0001h
T1GCON_GGO_nDONE_LENGTH                  equ 0001h
T1GCON_GGO_nDONE_MASK                    equ 0008h
T1GCON_GSPM_POSN                         equ 0004h
T1GCON_GSPM_POSITION                     equ 0004h
T1GCON_GSPM_SIZE                         equ 0001h
T1GCON_GSPM_LENGTH                       equ 0001h
T1GCON_GSPM_MASK                         equ 0010h
T1GCON_GTM_POSN                          equ 0005h
T1GCON_GTM_POSITION                      equ 0005h
T1GCON_GTM_SIZE                          equ 0001h
T1GCON_GTM_LENGTH                        equ 0001h
T1GCON_GTM_MASK                          equ 0020h
T1GCON_GPOL_POSN                         equ 0006h
T1GCON_GPOL_POSITION                     equ 0006h
T1GCON_GPOL_SIZE                         equ 0001h
T1GCON_GPOL_LENGTH                       equ 0001h
T1GCON_GPOL_MASK                         equ 0040h
T1GCON_GE_POSN                           equ 0007h
T1GCON_GE_POSITION                       equ 0007h
T1GCON_GE_SIZE                           equ 0001h
T1GCON_GE_LENGTH                         equ 0001h
T1GCON_GE_MASK                           equ 0080h
T1GCON_T1GVAL_POSN                       equ 0002h
T1GCON_T1GVAL_POSITION                   equ 0002h
T1GCON_T1GVAL_SIZE                       equ 0001h
T1GCON_T1GVAL_LENGTH                     equ 0001h
T1GCON_T1GVAL_MASK                       equ 0004h
T1GCON_T1GGO_nDONE_POSN                  equ 0003h
T1GCON_T1GGO_nDONE_POSITION              equ 0003h
T1GCON_T1GGO_nDONE_SIZE                  equ 0001h
T1GCON_T1GGO_nDONE_LENGTH                equ 0001h
T1GCON_T1GGO_nDONE_MASK                  equ 0008h
T1GCON_T1GSPM_POSN                       equ 0004h
T1GCON_T1GSPM_POSITION                   equ 0004h
T1GCON_T1GSPM_SIZE                       equ 0001h
T1GCON_T1GSPM_LENGTH                     equ 0001h
T1GCON_T1GSPM_MASK                       equ 0010h
T1GCON_T1GTM_POSN                        equ 0005h
T1GCON_T1GTM_POSITION                    equ 0005h
T1GCON_T1GTM_SIZE                        equ 0001h
T1GCON_T1GTM_LENGTH                      equ 0001h
T1GCON_T1GTM_MASK                        equ 0020h
T1GCON_T1GPOL_POSN                       equ 0006h
T1GCON_T1GPOL_POSITION                   equ 0006h
T1GCON_T1GPOL_SIZE                       equ 0001h
T1GCON_T1GPOL_LENGTH                     equ 0001h
T1GCON_T1GPOL_MASK                       equ 0040h
T1GCON_T1GE_POSN                         equ 0007h
T1GCON_T1GE_POSITION                     equ 0007h
T1GCON_T1GE_SIZE                         equ 0001h
T1GCON_T1GE_LENGTH                       equ 0001h
T1GCON_T1GE_MASK                         equ 0080h
T1GCON_T1GGO_POSN                        equ 0003h
T1GCON_T1GGO_POSITION                    equ 0003h
T1GCON_T1GGO_SIZE                        equ 0001h
T1GCON_T1GGO_LENGTH                      equ 0001h
T1GCON_T1GGO_MASK                        equ 0008h

// Register: T1GATE
#define T1GATE T1GATE
T1GATE                                   equ 0310h
// bitfield definitions
T1GATE_GSS_POSN                          equ 0000h
T1GATE_GSS_POSITION                      equ 0000h
T1GATE_GSS_SIZE                          equ 0005h
T1GATE_GSS_LENGTH                        equ 0005h
T1GATE_GSS_MASK                          equ 001Fh
T1GATE_GSS0_POSN                         equ 0000h
T1GATE_GSS0_POSITION                     equ 0000h
T1GATE_GSS0_SIZE                         equ 0001h
T1GATE_GSS0_LENGTH                       equ 0001h
T1GATE_GSS0_MASK                         equ 0001h
T1GATE_GSS1_POSN                         equ 0001h
T1GATE_GSS1_POSITION                     equ 0001h
T1GATE_GSS1_SIZE                         equ 0001h
T1GATE_GSS1_LENGTH                       equ 0001h
T1GATE_GSS1_MASK                         equ 0002h
T1GATE_GSS2_POSN                         equ 0002h
T1GATE_GSS2_POSITION                     equ 0002h
T1GATE_GSS2_SIZE                         equ 0001h
T1GATE_GSS2_LENGTH                       equ 0001h
T1GATE_GSS2_MASK                         equ 0004h
T1GATE_GSS3_POSN                         equ 0003h
T1GATE_GSS3_POSITION                     equ 0003h
T1GATE_GSS3_SIZE                         equ 0001h
T1GATE_GSS3_LENGTH                       equ 0001h
T1GATE_GSS3_MASK                         equ 0008h
T1GATE_GSS4_POSN                         equ 0004h
T1GATE_GSS4_POSITION                     equ 0004h
T1GATE_GSS4_SIZE                         equ 0001h
T1GATE_GSS4_LENGTH                       equ 0001h
T1GATE_GSS4_MASK                         equ 0010h
T1GATE_T1GSS0_POSN                       equ 0000h
T1GATE_T1GSS0_POSITION                   equ 0000h
T1GATE_T1GSS0_SIZE                       equ 0001h
T1GATE_T1GSS0_LENGTH                     equ 0001h
T1GATE_T1GSS0_MASK                       equ 0001h
T1GATE_T1GSS1_POSN                       equ 0001h
T1GATE_T1GSS1_POSITION                   equ 0001h
T1GATE_T1GSS1_SIZE                       equ 0001h
T1GATE_T1GSS1_LENGTH                     equ 0001h
T1GATE_T1GSS1_MASK                       equ 0002h
T1GATE_T1GSS2_POSN                       equ 0002h
T1GATE_T1GSS2_POSITION                   equ 0002h
T1GATE_T1GSS2_SIZE                       equ 0001h
T1GATE_T1GSS2_LENGTH                     equ 0001h
T1GATE_T1GSS2_MASK                       equ 0004h
T1GATE_T1GSS3_POSN                       equ 0003h
T1GATE_T1GSS3_POSITION                   equ 0003h
T1GATE_T1GSS3_SIZE                       equ 0001h
T1GATE_T1GSS3_LENGTH                     equ 0001h
T1GATE_T1GSS3_MASK                       equ 0008h
T1GATE_T1GSS4_POSN                       equ 0004h
T1GATE_T1GSS4_POSITION                   equ 0004h
T1GATE_T1GSS4_SIZE                       equ 0001h
T1GATE_T1GSS4_LENGTH                     equ 0001h
T1GATE_T1GSS4_MASK                       equ 0010h

// Register: T1CLK
#define T1CLK T1CLK
T1CLK                                    equ 0311h
// bitfield definitions
T1CLK_CS_POSN                            equ 0000h
T1CLK_CS_POSITION                        equ 0000h
T1CLK_CS_SIZE                            equ 0008h
T1CLK_CS_LENGTH                          equ 0008h
T1CLK_CS_MASK                            equ 00FFh
T1CLK_T1CS0_POSN                         equ 0000h
T1CLK_T1CS0_POSITION                     equ 0000h
T1CLK_T1CS0_SIZE                         equ 0001h
T1CLK_T1CS0_LENGTH                       equ 0001h
T1CLK_T1CS0_MASK                         equ 0001h
T1CLK_T1CS1_POSN                         equ 0001h
T1CLK_T1CS1_POSITION                     equ 0001h
T1CLK_T1CS1_SIZE                         equ 0001h
T1CLK_T1CS1_LENGTH                       equ 0001h
T1CLK_T1CS1_MASK                         equ 0002h
T1CLK_T1CS2_POSN                         equ 0002h
T1CLK_T1CS2_POSITION                     equ 0002h
T1CLK_T1CS2_SIZE                         equ 0001h
T1CLK_T1CS2_LENGTH                       equ 0001h
T1CLK_T1CS2_MASK                         equ 0004h
T1CLK_T1CS3_POSN                         equ 0003h
T1CLK_T1CS3_POSITION                     equ 0003h
T1CLK_T1CS3_SIZE                         equ 0001h
T1CLK_T1CS3_LENGTH                       equ 0001h
T1CLK_T1CS3_MASK                         equ 0008h
T1CLK_T1CS4_POSN                         equ 0004h
T1CLK_T1CS4_POSITION                     equ 0004h
T1CLK_T1CS4_SIZE                         equ 0001h
T1CLK_T1CS4_LENGTH                       equ 0001h
T1CLK_T1CS4_MASK                         equ 0010h
T1CLK_CS0_POSN                           equ 0000h
T1CLK_CS0_POSITION                       equ 0000h
T1CLK_CS0_SIZE                           equ 0001h
T1CLK_CS0_LENGTH                         equ 0001h
T1CLK_CS0_MASK                           equ 0001h
T1CLK_CS1_POSN                           equ 0001h
T1CLK_CS1_POSITION                       equ 0001h
T1CLK_CS1_SIZE                           equ 0001h
T1CLK_CS1_LENGTH                         equ 0001h
T1CLK_CS1_MASK                           equ 0002h
T1CLK_CS2_POSN                           equ 0002h
T1CLK_CS2_POSITION                       equ 0002h
T1CLK_CS2_SIZE                           equ 0001h
T1CLK_CS2_LENGTH                         equ 0001h
T1CLK_CS2_MASK                           equ 0004h
T1CLK_CS3_POSN                           equ 0003h
T1CLK_CS3_POSITION                       equ 0003h
T1CLK_CS3_SIZE                           equ 0001h
T1CLK_CS3_LENGTH                         equ 0001h
T1CLK_CS3_MASK                           equ 0008h
T1CLK_CS4_POSN                           equ 0004h
T1CLK_CS4_POSITION                       equ 0004h
T1CLK_CS4_SIZE                           equ 0001h
T1CLK_CS4_LENGTH                         equ 0001h
T1CLK_CS4_MASK                           equ 0010h

// Register: T2TMR
#define T2TMR T2TMR
T2TMR                                    equ 038Ch
// bitfield definitions
T2TMR_T2TMR_POSN                         equ 0000h
T2TMR_T2TMR_POSITION                     equ 0000h
T2TMR_T2TMR_SIZE                         equ 0008h
T2TMR_T2TMR_LENGTH                       equ 0008h
T2TMR_T2TMR_MASK                         equ 00FFh
T2TMR_TMR2_POSN                          equ 0000h
T2TMR_TMR2_POSITION                      equ 0000h
T2TMR_TMR2_SIZE                          equ 0008h
T2TMR_TMR2_LENGTH                        equ 0008h
T2TMR_TMR2_MASK                          equ 00FFh

// Register: T2PR
#define T2PR T2PR
T2PR                                     equ 038Dh
// bitfield definitions
T2PR_T2PR_POSN                           equ 0000h
T2PR_T2PR_POSITION                       equ 0000h
T2PR_T2PR_SIZE                           equ 0008h
T2PR_T2PR_LENGTH                         equ 0008h
T2PR_T2PR_MASK                           equ 00FFh
T2PR_PR2_POSN                            equ 0000h
T2PR_PR2_POSITION                        equ 0000h
T2PR_PR2_SIZE                            equ 0008h
T2PR_PR2_LENGTH                          equ 0008h
T2PR_PR2_MASK                            equ 00FFh

// Register: T2CON
#define T2CON T2CON
T2CON                                    equ 038Eh
// bitfield definitions
T2CON_OUTPS_POSN                         equ 0000h
T2CON_OUTPS_POSITION                     equ 0000h
T2CON_OUTPS_SIZE                         equ 0004h
T2CON_OUTPS_LENGTH                       equ 0004h
T2CON_OUTPS_MASK                         equ 000Fh
T2CON_CKPS_POSN                          equ 0004h
T2CON_CKPS_POSITION                      equ 0004h
T2CON_CKPS_SIZE                          equ 0003h
T2CON_CKPS_LENGTH                        equ 0003h
T2CON_CKPS_MASK                          equ 0070h
T2CON_ON_POSN                            equ 0007h
T2CON_ON_POSITION                        equ 0007h
T2CON_ON_SIZE                            equ 0001h
T2CON_ON_LENGTH                          equ 0001h
T2CON_ON_MASK                            equ 0080h
T2CON_T2OUTPS_POSN                       equ 0000h
T2CON_T2OUTPS_POSITION                   equ 0000h
T2CON_T2OUTPS_SIZE                       equ 0004h
T2CON_T2OUTPS_LENGTH                     equ 0004h
T2CON_T2OUTPS_MASK                       equ 000Fh
T2CON_T2CKPS_POSN                        equ 0004h
T2CON_T2CKPS_POSITION                    equ 0004h
T2CON_T2CKPS_SIZE                        equ 0003h
T2CON_T2CKPS_LENGTH                      equ 0003h
T2CON_T2CKPS_MASK                        equ 0070h
T2CON_T2ON_POSN                          equ 0007h
T2CON_T2ON_POSITION                      equ 0007h
T2CON_T2ON_SIZE                          equ 0001h
T2CON_T2ON_LENGTH                        equ 0001h
T2CON_T2ON_MASK                          equ 0080h
T2CON_T2OUTPS0_POSN                      equ 0000h
T2CON_T2OUTPS0_POSITION                  equ 0000h
T2CON_T2OUTPS0_SIZE                      equ 0001h
T2CON_T2OUTPS0_LENGTH                    equ 0001h
T2CON_T2OUTPS0_MASK                      equ 0001h
T2CON_T2OUTPS1_POSN                      equ 0001h
T2CON_T2OUTPS1_POSITION                  equ 0001h
T2CON_T2OUTPS1_SIZE                      equ 0001h
T2CON_T2OUTPS1_LENGTH                    equ 0001h
T2CON_T2OUTPS1_MASK                      equ 0002h
T2CON_T2OUTPS2_POSN                      equ 0002h
T2CON_T2OUTPS2_POSITION                  equ 0002h
T2CON_T2OUTPS2_SIZE                      equ 0001h
T2CON_T2OUTPS2_LENGTH                    equ 0001h
T2CON_T2OUTPS2_MASK                      equ 0004h
T2CON_T2OUTPS3_POSN                      equ 0003h
T2CON_T2OUTPS3_POSITION                  equ 0003h
T2CON_T2OUTPS3_SIZE                      equ 0001h
T2CON_T2OUTPS3_LENGTH                    equ 0001h
T2CON_T2OUTPS3_MASK                      equ 0008h
T2CON_T2CKPS0_POSN                       equ 0004h
T2CON_T2CKPS0_POSITION                   equ 0004h
T2CON_T2CKPS0_SIZE                       equ 0001h
T2CON_T2CKPS0_LENGTH                     equ 0001h
T2CON_T2CKPS0_MASK                       equ 0010h
T2CON_T2CKPS1_POSN                       equ 0005h
T2CON_T2CKPS1_POSITION                   equ 0005h
T2CON_T2CKPS1_SIZE                       equ 0001h
T2CON_T2CKPS1_LENGTH                     equ 0001h
T2CON_T2CKPS1_MASK                       equ 0020h
T2CON_T2CKPS2_POSN                       equ 0006h
T2CON_T2CKPS2_POSITION                   equ 0006h
T2CON_T2CKPS2_SIZE                       equ 0001h
T2CON_T2CKPS2_LENGTH                     equ 0001h
T2CON_T2CKPS2_MASK                       equ 0040h
T2CON_OUTPS0_POSN                        equ 0000h
T2CON_OUTPS0_POSITION                    equ 0000h
T2CON_OUTPS0_SIZE                        equ 0001h
T2CON_OUTPS0_LENGTH                      equ 0001h
T2CON_OUTPS0_MASK                        equ 0001h
T2CON_OUTPS1_POSN                        equ 0001h
T2CON_OUTPS1_POSITION                    equ 0001h
T2CON_OUTPS1_SIZE                        equ 0001h
T2CON_OUTPS1_LENGTH                      equ 0001h
T2CON_OUTPS1_MASK                        equ 0002h
T2CON_OUTPS2_POSN                        equ 0002h
T2CON_OUTPS2_POSITION                    equ 0002h
T2CON_OUTPS2_SIZE                        equ 0001h
T2CON_OUTPS2_LENGTH                      equ 0001h
T2CON_OUTPS2_MASK                        equ 0004h
T2CON_OUTPS3_POSN                        equ 0003h
T2CON_OUTPS3_POSITION                    equ 0003h
T2CON_OUTPS3_SIZE                        equ 0001h
T2CON_OUTPS3_LENGTH                      equ 0001h
T2CON_OUTPS3_MASK                        equ 0008h
T2CON_CKPS0_POSN                         equ 0004h
T2CON_CKPS0_POSITION                     equ 0004h
T2CON_CKPS0_SIZE                         equ 0001h
T2CON_CKPS0_LENGTH                       equ 0001h
T2CON_CKPS0_MASK                         equ 0010h
T2CON_CKPS1_POSN                         equ 0005h
T2CON_CKPS1_POSITION                     equ 0005h
T2CON_CKPS1_SIZE                         equ 0001h
T2CON_CKPS1_LENGTH                       equ 0001h
T2CON_CKPS1_MASK                         equ 0020h
T2CON_CKPS2_POSN                         equ 0006h
T2CON_CKPS2_POSITION                     equ 0006h
T2CON_CKPS2_SIZE                         equ 0001h
T2CON_CKPS2_LENGTH                       equ 0001h
T2CON_CKPS2_MASK                         equ 0040h
T2CON_TMR2ON_POSN                        equ 0007h
T2CON_TMR2ON_POSITION                    equ 0007h
T2CON_TMR2ON_SIZE                        equ 0001h
T2CON_TMR2ON_LENGTH                      equ 0001h
T2CON_TMR2ON_MASK                        equ 0080h

// Register: T2HLT
#define T2HLT T2HLT
T2HLT                                    equ 038Fh
// bitfield definitions
T2HLT_MODE_POSN                          equ 0000h
T2HLT_MODE_POSITION                      equ 0000h
T2HLT_MODE_SIZE                          equ 0005h
T2HLT_MODE_LENGTH                        equ 0005h
T2HLT_MODE_MASK                          equ 001Fh
T2HLT_CSYNC_POSN                         equ 0005h
T2HLT_CSYNC_POSITION                     equ 0005h
T2HLT_CSYNC_SIZE                         equ 0001h
T2HLT_CSYNC_LENGTH                       equ 0001h
T2HLT_CSYNC_MASK                         equ 0020h
T2HLT_CPOL_POSN                          equ 0006h
T2HLT_CPOL_POSITION                      equ 0006h
T2HLT_CPOL_SIZE                          equ 0001h
T2HLT_CPOL_LENGTH                        equ 0001h
T2HLT_CPOL_MASK                          equ 0040h
T2HLT_PSYNC_POSN                         equ 0007h
T2HLT_PSYNC_POSITION                     equ 0007h
T2HLT_PSYNC_SIZE                         equ 0001h
T2HLT_PSYNC_LENGTH                       equ 0001h
T2HLT_PSYNC_MASK                         equ 0080h
T2HLT_MODE0_POSN                         equ 0000h
T2HLT_MODE0_POSITION                     equ 0000h
T2HLT_MODE0_SIZE                         equ 0001h
T2HLT_MODE0_LENGTH                       equ 0001h
T2HLT_MODE0_MASK                         equ 0001h
T2HLT_MODE1_POSN                         equ 0001h
T2HLT_MODE1_POSITION                     equ 0001h
T2HLT_MODE1_SIZE                         equ 0001h
T2HLT_MODE1_LENGTH                       equ 0001h
T2HLT_MODE1_MASK                         equ 0002h
T2HLT_MODE2_POSN                         equ 0002h
T2HLT_MODE2_POSITION                     equ 0002h
T2HLT_MODE2_SIZE                         equ 0001h
T2HLT_MODE2_LENGTH                       equ 0001h
T2HLT_MODE2_MASK                         equ 0004h
T2HLT_MODE3_POSN                         equ 0003h
T2HLT_MODE3_POSITION                     equ 0003h
T2HLT_MODE3_SIZE                         equ 0001h
T2HLT_MODE3_LENGTH                       equ 0001h
T2HLT_MODE3_MASK                         equ 0008h
T2HLT_MODE4_POSN                         equ 0004h
T2HLT_MODE4_POSITION                     equ 0004h
T2HLT_MODE4_SIZE                         equ 0001h
T2HLT_MODE4_LENGTH                       equ 0001h
T2HLT_MODE4_MASK                         equ 0010h
T2HLT_CKSYNC_POSN                        equ 0005h
T2HLT_CKSYNC_POSITION                    equ 0005h
T2HLT_CKSYNC_SIZE                        equ 0001h
T2HLT_CKSYNC_LENGTH                      equ 0001h
T2HLT_CKSYNC_MASK                        equ 0020h
T2HLT_CKPOL_POSN                         equ 0006h
T2HLT_CKPOL_POSITION                     equ 0006h
T2HLT_CKPOL_SIZE                         equ 0001h
T2HLT_CKPOL_LENGTH                       equ 0001h
T2HLT_CKPOL_MASK                         equ 0040h
T2HLT_T2MODE_POSN                        equ 0000h
T2HLT_T2MODE_POSITION                    equ 0000h
T2HLT_T2MODE_SIZE                        equ 0005h
T2HLT_T2MODE_LENGTH                      equ 0005h
T2HLT_T2MODE_MASK                        equ 001Fh
T2HLT_T2CSYNC_POSN                       equ 0005h
T2HLT_T2CSYNC_POSITION                   equ 0005h
T2HLT_T2CSYNC_SIZE                       equ 0001h
T2HLT_T2CSYNC_LENGTH                     equ 0001h
T2HLT_T2CSYNC_MASK                       equ 0020h
T2HLT_T2CPOL_POSN                        equ 0006h
T2HLT_T2CPOL_POSITION                    equ 0006h
T2HLT_T2CPOL_SIZE                        equ 0001h
T2HLT_T2CPOL_LENGTH                      equ 0001h
T2HLT_T2CPOL_MASK                        equ 0040h
T2HLT_T2PSYNC_POSN                       equ 0007h
T2HLT_T2PSYNC_POSITION                   equ 0007h
T2HLT_T2PSYNC_SIZE                       equ 0001h
T2HLT_T2PSYNC_LENGTH                     equ 0001h
T2HLT_T2PSYNC_MASK                       equ 0080h
T2HLT_T2MODE0_POSN                       equ 0000h
T2HLT_T2MODE0_POSITION                   equ 0000h
T2HLT_T2MODE0_SIZE                       equ 0001h
T2HLT_T2MODE0_LENGTH                     equ 0001h
T2HLT_T2MODE0_MASK                       equ 0001h
T2HLT_T2MODE1_POSN                       equ 0001h
T2HLT_T2MODE1_POSITION                   equ 0001h
T2HLT_T2MODE1_SIZE                       equ 0001h
T2HLT_T2MODE1_LENGTH                     equ 0001h
T2HLT_T2MODE1_MASK                       equ 0002h
T2HLT_T2MODE2_POSN                       equ 0002h
T2HLT_T2MODE2_POSITION                   equ 0002h
T2HLT_T2MODE2_SIZE                       equ 0001h
T2HLT_T2MODE2_LENGTH                     equ 0001h
T2HLT_T2MODE2_MASK                       equ 0004h
T2HLT_T2MODE3_POSN                       equ 0003h
T2HLT_T2MODE3_POSITION                   equ 0003h
T2HLT_T2MODE3_SIZE                       equ 0001h
T2HLT_T2MODE3_LENGTH                     equ 0001h
T2HLT_T2MODE3_MASK                       equ 0008h
T2HLT_T2MODE4_POSN                       equ 0004h
T2HLT_T2MODE4_POSITION                   equ 0004h
T2HLT_T2MODE4_SIZE                       equ 0001h
T2HLT_T2MODE4_LENGTH                     equ 0001h
T2HLT_T2MODE4_MASK                       equ 0010h

// Register: T2CLKCON
#define T2CLKCON T2CLKCON
T2CLKCON                                 equ 0390h
// bitfield definitions
T2CLKCON_CS_POSN                         equ 0000h
T2CLKCON_CS_POSITION                     equ 0000h
T2CLKCON_CS_SIZE                         equ 0008h
T2CLKCON_CS_LENGTH                       equ 0008h
T2CLKCON_CS_MASK                         equ 00FFh
T2CLKCON_CS0_POSN                        equ 0000h
T2CLKCON_CS0_POSITION                    equ 0000h
T2CLKCON_CS0_SIZE                        equ 0001h
T2CLKCON_CS0_LENGTH                      equ 0001h
T2CLKCON_CS0_MASK                        equ 0001h
T2CLKCON_CS1_POSN                        equ 0001h
T2CLKCON_CS1_POSITION                    equ 0001h
T2CLKCON_CS1_SIZE                        equ 0001h
T2CLKCON_CS1_LENGTH                      equ 0001h
T2CLKCON_CS1_MASK                        equ 0002h
T2CLKCON_CS2_POSN                        equ 0002h
T2CLKCON_CS2_POSITION                    equ 0002h
T2CLKCON_CS2_SIZE                        equ 0001h
T2CLKCON_CS2_LENGTH                      equ 0001h
T2CLKCON_CS2_MASK                        equ 0004h
T2CLKCON_CS3_POSN                        equ 0003h
T2CLKCON_CS3_POSITION                    equ 0003h
T2CLKCON_CS3_SIZE                        equ 0001h
T2CLKCON_CS3_LENGTH                      equ 0001h
T2CLKCON_CS3_MASK                        equ 0008h
T2CLKCON_CS4_POSN                        equ 0004h
T2CLKCON_CS4_POSITION                    equ 0004h
T2CLKCON_CS4_SIZE                        equ 0001h
T2CLKCON_CS4_LENGTH                      equ 0001h
T2CLKCON_CS4_MASK                        equ 0010h
T2CLKCON_T2CS_POSN                       equ 0000h
T2CLKCON_T2CS_POSITION                   equ 0000h
T2CLKCON_T2CS_SIZE                       equ 0008h
T2CLKCON_T2CS_LENGTH                     equ 0008h
T2CLKCON_T2CS_MASK                       equ 00FFh
T2CLKCON_T2CS0_POSN                      equ 0000h
T2CLKCON_T2CS0_POSITION                  equ 0000h
T2CLKCON_T2CS0_SIZE                      equ 0001h
T2CLKCON_T2CS0_LENGTH                    equ 0001h
T2CLKCON_T2CS0_MASK                      equ 0001h
T2CLKCON_T2CS1_POSN                      equ 0001h
T2CLKCON_T2CS1_POSITION                  equ 0001h
T2CLKCON_T2CS1_SIZE                      equ 0001h
T2CLKCON_T2CS1_LENGTH                    equ 0001h
T2CLKCON_T2CS1_MASK                      equ 0002h
T2CLKCON_T2CS2_POSN                      equ 0002h
T2CLKCON_T2CS2_POSITION                  equ 0002h
T2CLKCON_T2CS2_SIZE                      equ 0001h
T2CLKCON_T2CS2_LENGTH                    equ 0001h
T2CLKCON_T2CS2_MASK                      equ 0004h
T2CLKCON_T2CS3_POSN                      equ 0003h
T2CLKCON_T2CS3_POSITION                  equ 0003h
T2CLKCON_T2CS3_SIZE                      equ 0001h
T2CLKCON_T2CS3_LENGTH                    equ 0001h
T2CLKCON_T2CS3_MASK                      equ 0008h
T2CLKCON_T2CS4_POSN                      equ 0004h
T2CLKCON_T2CS4_POSITION                  equ 0004h
T2CLKCON_T2CS4_SIZE                      equ 0001h
T2CLKCON_T2CS4_LENGTH                    equ 0001h
T2CLKCON_T2CS4_MASK                      equ 0010h

// Register: T2RST
#define T2RST T2RST
T2RST                                    equ 0391h
// bitfield definitions
T2RST_RSEL_POSN                          equ 0000h
T2RST_RSEL_POSITION                      equ 0000h
T2RST_RSEL_SIZE                          equ 0008h
T2RST_RSEL_LENGTH                        equ 0008h
T2RST_RSEL_MASK                          equ 00FFh
T2RST_RSEL0_POSN                         equ 0000h
T2RST_RSEL0_POSITION                     equ 0000h
T2RST_RSEL0_SIZE                         equ 0001h
T2RST_RSEL0_LENGTH                       equ 0001h
T2RST_RSEL0_MASK                         equ 0001h
T2RST_RSEL1_POSN                         equ 0001h
T2RST_RSEL1_POSITION                     equ 0001h
T2RST_RSEL1_SIZE                         equ 0001h
T2RST_RSEL1_LENGTH                       equ 0001h
T2RST_RSEL1_MASK                         equ 0002h
T2RST_RSEL2_POSN                         equ 0002h
T2RST_RSEL2_POSITION                     equ 0002h
T2RST_RSEL2_SIZE                         equ 0001h
T2RST_RSEL2_LENGTH                       equ 0001h
T2RST_RSEL2_MASK                         equ 0004h
T2RST_RSEL3_POSN                         equ 0003h
T2RST_RSEL3_POSITION                     equ 0003h
T2RST_RSEL3_SIZE                         equ 0001h
T2RST_RSEL3_LENGTH                       equ 0001h
T2RST_RSEL3_MASK                         equ 0008h
T2RST_RSEL4_POSN                         equ 0004h
T2RST_RSEL4_POSITION                     equ 0004h
T2RST_RSEL4_SIZE                         equ 0001h
T2RST_RSEL4_LENGTH                       equ 0001h
T2RST_RSEL4_MASK                         equ 0010h
T2RST_T2RSEL_POSN                        equ 0000h
T2RST_T2RSEL_POSITION                    equ 0000h
T2RST_T2RSEL_SIZE                        equ 0008h
T2RST_T2RSEL_LENGTH                      equ 0008h
T2RST_T2RSEL_MASK                        equ 00FFh
T2RST_T2RSEL0_POSN                       equ 0000h
T2RST_T2RSEL0_POSITION                   equ 0000h
T2RST_T2RSEL0_SIZE                       equ 0001h
T2RST_T2RSEL0_LENGTH                     equ 0001h
T2RST_T2RSEL0_MASK                       equ 0001h
T2RST_T2RSEL1_POSN                       equ 0001h
T2RST_T2RSEL1_POSITION                   equ 0001h
T2RST_T2RSEL1_SIZE                       equ 0001h
T2RST_T2RSEL1_LENGTH                     equ 0001h
T2RST_T2RSEL1_MASK                       equ 0002h
T2RST_T2RSEL2_POSN                       equ 0002h
T2RST_T2RSEL2_POSITION                   equ 0002h
T2RST_T2RSEL2_SIZE                       equ 0001h
T2RST_T2RSEL2_LENGTH                     equ 0001h
T2RST_T2RSEL2_MASK                       equ 0004h
T2RST_T2RSEL3_POSN                       equ 0003h
T2RST_T2RSEL3_POSITION                   equ 0003h
T2RST_T2RSEL3_SIZE                       equ 0001h
T2RST_T2RSEL3_LENGTH                     equ 0001h
T2RST_T2RSEL3_MASK                       equ 0008h
T2RST_T2RSEL4_POSN                       equ 0004h
T2RST_T2RSEL4_POSITION                   equ 0004h
T2RST_T2RSEL4_SIZE                       equ 0001h
T2RST_T2RSEL4_LENGTH                     equ 0001h
T2RST_T2RSEL4_MASK                       equ 0010h

// Register: CCPR1L
#define CCPR1L CCPR1L
CCPR1L                                   equ 040Ch
// bitfield definitions
CCPR1L_CCPRL_POSN                        equ 0000h
CCPR1L_CCPRL_POSITION                    equ 0000h
CCPR1L_CCPRL_SIZE                        equ 0008h
CCPR1L_CCPRL_LENGTH                      equ 0008h
CCPR1L_CCPRL_MASK                        equ 00FFh

// Register: CCPR1H
#define CCPR1H CCPR1H
CCPR1H                                   equ 040Dh
// bitfield definitions
CCPR1H_CCPRH_POSN                        equ 0000h
CCPR1H_CCPRH_POSITION                    equ 0000h
CCPR1H_CCPRH_SIZE                        equ 0008h
CCPR1H_CCPRH_LENGTH                      equ 0008h
CCPR1H_CCPRH_MASK                        equ 00FFh

// Register: CCP1CON
#define CCP1CON CCP1CON
CCP1CON                                  equ 040Eh
// bitfield definitions
CCP1CON_MODE_POSN                        equ 0000h
CCP1CON_MODE_POSITION                    equ 0000h
CCP1CON_MODE_SIZE                        equ 0004h
CCP1CON_MODE_LENGTH                      equ 0004h
CCP1CON_MODE_MASK                        equ 000Fh
CCP1CON_FMT_POSN                         equ 0004h
CCP1CON_FMT_POSITION                     equ 0004h
CCP1CON_FMT_SIZE                         equ 0001h
CCP1CON_FMT_LENGTH                       equ 0001h
CCP1CON_FMT_MASK                         equ 0010h
CCP1CON_OUT_POSN                         equ 0005h
CCP1CON_OUT_POSITION                     equ 0005h
CCP1CON_OUT_SIZE                         equ 0001h
CCP1CON_OUT_LENGTH                       equ 0001h
CCP1CON_OUT_MASK                         equ 0020h
CCP1CON_EN_POSN                          equ 0007h
CCP1CON_EN_POSITION                      equ 0007h
CCP1CON_EN_SIZE                          equ 0001h
CCP1CON_EN_LENGTH                        equ 0001h
CCP1CON_EN_MASK                          equ 0080h
CCP1CON_MODE0_POSN                       equ 0000h
CCP1CON_MODE0_POSITION                   equ 0000h
CCP1CON_MODE0_SIZE                       equ 0001h
CCP1CON_MODE0_LENGTH                     equ 0001h
CCP1CON_MODE0_MASK                       equ 0001h
CCP1CON_MODE1_POSN                       equ 0001h
CCP1CON_MODE1_POSITION                   equ 0001h
CCP1CON_MODE1_SIZE                       equ 0001h
CCP1CON_MODE1_LENGTH                     equ 0001h
CCP1CON_MODE1_MASK                       equ 0002h
CCP1CON_MODE2_POSN                       equ 0002h
CCP1CON_MODE2_POSITION                   equ 0002h
CCP1CON_MODE2_SIZE                       equ 0001h
CCP1CON_MODE2_LENGTH                     equ 0001h
CCP1CON_MODE2_MASK                       equ 0004h
CCP1CON_MODE3_POSN                       equ 0003h
CCP1CON_MODE3_POSITION                   equ 0003h
CCP1CON_MODE3_SIZE                       equ 0001h
CCP1CON_MODE3_LENGTH                     equ 0001h
CCP1CON_MODE3_MASK                       equ 0008h
CCP1CON_CCP1MODE_POSN                    equ 0000h
CCP1CON_CCP1MODE_POSITION                equ 0000h
CCP1CON_CCP1MODE_SIZE                    equ 0004h
CCP1CON_CCP1MODE_LENGTH                  equ 0004h
CCP1CON_CCP1MODE_MASK                    equ 000Fh
CCP1CON_CCP1FMT_POSN                     equ 0004h
CCP1CON_CCP1FMT_POSITION                 equ 0004h
CCP1CON_CCP1FMT_SIZE                     equ 0001h
CCP1CON_CCP1FMT_LENGTH                   equ 0001h
CCP1CON_CCP1FMT_MASK                     equ 0010h
CCP1CON_CCP1OUT_POSN                     equ 0005h
CCP1CON_CCP1OUT_POSITION                 equ 0005h
CCP1CON_CCP1OUT_SIZE                     equ 0001h
CCP1CON_CCP1OUT_LENGTH                   equ 0001h
CCP1CON_CCP1OUT_MASK                     equ 0020h
CCP1CON_CCP1EN_POSN                      equ 0007h
CCP1CON_CCP1EN_POSITION                  equ 0007h
CCP1CON_CCP1EN_SIZE                      equ 0001h
CCP1CON_CCP1EN_LENGTH                    equ 0001h
CCP1CON_CCP1EN_MASK                      equ 0080h
CCP1CON_CCP1MODE0_POSN                   equ 0000h
CCP1CON_CCP1MODE0_POSITION               equ 0000h
CCP1CON_CCP1MODE0_SIZE                   equ 0001h
CCP1CON_CCP1MODE0_LENGTH                 equ 0001h
CCP1CON_CCP1MODE0_MASK                   equ 0001h
CCP1CON_CCP1MODE1_POSN                   equ 0001h
CCP1CON_CCP1MODE1_POSITION               equ 0001h
CCP1CON_CCP1MODE1_SIZE                   equ 0001h
CCP1CON_CCP1MODE1_LENGTH                 equ 0001h
CCP1CON_CCP1MODE1_MASK                   equ 0002h
CCP1CON_CCP1MODE2_POSN                   equ 0002h
CCP1CON_CCP1MODE2_POSITION               equ 0002h
CCP1CON_CCP1MODE2_SIZE                   equ 0001h
CCP1CON_CCP1MODE2_LENGTH                 equ 0001h
CCP1CON_CCP1MODE2_MASK                   equ 0004h
CCP1CON_CCP1MODE3_POSN                   equ 0003h
CCP1CON_CCP1MODE3_POSITION               equ 0003h
CCP1CON_CCP1MODE3_SIZE                   equ 0001h
CCP1CON_CCP1MODE3_LENGTH                 equ 0001h
CCP1CON_CCP1MODE3_MASK                   equ 0008h
CCP1CON_P1M1_POSN                        equ 0007h
CCP1CON_P1M1_POSITION                    equ 0007h
CCP1CON_P1M1_SIZE                        equ 0001h
CCP1CON_P1M1_LENGTH                      equ 0001h
CCP1CON_P1M1_MASK                        equ 0080h

// Register: CCP1CAP
#define CCP1CAP CCP1CAP
CCP1CAP                                  equ 040Fh
// bitfield definitions
CCP1CAP_CTS_POSN                         equ 0000h
CCP1CAP_CTS_POSITION                     equ 0000h
CCP1CAP_CTS_SIZE                         equ 0006h
CCP1CAP_CTS_LENGTH                       equ 0006h
CCP1CAP_CTS_MASK                         equ 003Fh
CCP1CAP_CTS0_POSN                        equ 0000h
CCP1CAP_CTS0_POSITION                    equ 0000h
CCP1CAP_CTS0_SIZE                        equ 0001h
CCP1CAP_CTS0_LENGTH                      equ 0001h
CCP1CAP_CTS0_MASK                        equ 0001h
CCP1CAP_CTS1_POSN                        equ 0001h
CCP1CAP_CTS1_POSITION                    equ 0001h
CCP1CAP_CTS1_SIZE                        equ 0001h
CCP1CAP_CTS1_LENGTH                      equ 0001h
CCP1CAP_CTS1_MASK                        equ 0002h
CCP1CAP_CTS2_POSN                        equ 0002h
CCP1CAP_CTS2_POSITION                    equ 0002h
CCP1CAP_CTS2_SIZE                        equ 0001h
CCP1CAP_CTS2_LENGTH                      equ 0001h
CCP1CAP_CTS2_MASK                        equ 0004h
CCP1CAP_CTS3_POSN                        equ 0003h
CCP1CAP_CTS3_POSITION                    equ 0003h
CCP1CAP_CTS3_SIZE                        equ 0001h
CCP1CAP_CTS3_LENGTH                      equ 0001h
CCP1CAP_CTS3_MASK                        equ 0008h
CCP1CAP_CCP1CTS_POSN                     equ 0000h
CCP1CAP_CCP1CTS_POSITION                 equ 0000h
CCP1CAP_CCP1CTS_SIZE                     equ 0006h
CCP1CAP_CCP1CTS_LENGTH                   equ 0006h
CCP1CAP_CCP1CTS_MASK                     equ 003Fh
CCP1CAP_CCP1CTS0_POSN                    equ 0000h
CCP1CAP_CCP1CTS0_POSITION                equ 0000h
CCP1CAP_CCP1CTS0_SIZE                    equ 0001h
CCP1CAP_CCP1CTS0_LENGTH                  equ 0001h
CCP1CAP_CCP1CTS0_MASK                    equ 0001h
CCP1CAP_CCP1CTS1_POSN                    equ 0001h
CCP1CAP_CCP1CTS1_POSITION                equ 0001h
CCP1CAP_CCP1CTS1_SIZE                    equ 0001h
CCP1CAP_CCP1CTS1_LENGTH                  equ 0001h
CCP1CAP_CCP1CTS1_MASK                    equ 0002h
CCP1CAP_CCP1CTS2_POSN                    equ 0002h
CCP1CAP_CCP1CTS2_POSITION                equ 0002h
CCP1CAP_CCP1CTS2_SIZE                    equ 0001h
CCP1CAP_CCP1CTS2_LENGTH                  equ 0001h
CCP1CAP_CCP1CTS2_MASK                    equ 0004h
CCP1CAP_CCP1CTS3_POSN                    equ 0003h
CCP1CAP_CCP1CTS3_POSITION                equ 0003h
CCP1CAP_CCP1CTS3_SIZE                    equ 0001h
CCP1CAP_CCP1CTS3_LENGTH                  equ 0001h
CCP1CAP_CCP1CTS3_MASK                    equ 0008h

// Register: CCPR2L
#define CCPR2L CCPR2L
CCPR2L                                   equ 0410h
// bitfield definitions
CCPR2L_CCPRL_POSN                        equ 0000h
CCPR2L_CCPRL_POSITION                    equ 0000h
CCPR2L_CCPRL_SIZE                        equ 0008h
CCPR2L_CCPRL_LENGTH                      equ 0008h
CCPR2L_CCPRL_MASK                        equ 00FFh

// Register: CCPR2H
#define CCPR2H CCPR2H
CCPR2H                                   equ 0411h
// bitfield definitions
CCPR2H_CCPRH_POSN                        equ 0000h
CCPR2H_CCPRH_POSITION                    equ 0000h
CCPR2H_CCPRH_SIZE                        equ 0008h
CCPR2H_CCPRH_LENGTH                      equ 0008h
CCPR2H_CCPRH_MASK                        equ 00FFh

// Register: CCP2CON
#define CCP2CON CCP2CON
CCP2CON                                  equ 0412h
// bitfield definitions
CCP2CON_MODE_POSN                        equ 0000h
CCP2CON_MODE_POSITION                    equ 0000h
CCP2CON_MODE_SIZE                        equ 0004h
CCP2CON_MODE_LENGTH                      equ 0004h
CCP2CON_MODE_MASK                        equ 000Fh
CCP2CON_FMT_POSN                         equ 0004h
CCP2CON_FMT_POSITION                     equ 0004h
CCP2CON_FMT_SIZE                         equ 0001h
CCP2CON_FMT_LENGTH                       equ 0001h
CCP2CON_FMT_MASK                         equ 0010h
CCP2CON_OUT_POSN                         equ 0005h
CCP2CON_OUT_POSITION                     equ 0005h
CCP2CON_OUT_SIZE                         equ 0001h
CCP2CON_OUT_LENGTH                       equ 0001h
CCP2CON_OUT_MASK                         equ 0020h
CCP2CON_EN_POSN                          equ 0007h
CCP2CON_EN_POSITION                      equ 0007h
CCP2CON_EN_SIZE                          equ 0001h
CCP2CON_EN_LENGTH                        equ 0001h
CCP2CON_EN_MASK                          equ 0080h
CCP2CON_MODE0_POSN                       equ 0000h
CCP2CON_MODE0_POSITION                   equ 0000h
CCP2CON_MODE0_SIZE                       equ 0001h
CCP2CON_MODE0_LENGTH                     equ 0001h
CCP2CON_MODE0_MASK                       equ 0001h
CCP2CON_MODE1_POSN                       equ 0001h
CCP2CON_MODE1_POSITION                   equ 0001h
CCP2CON_MODE1_SIZE                       equ 0001h
CCP2CON_MODE1_LENGTH                     equ 0001h
CCP2CON_MODE1_MASK                       equ 0002h
CCP2CON_MODE2_POSN                       equ 0002h
CCP2CON_MODE2_POSITION                   equ 0002h
CCP2CON_MODE2_SIZE                       equ 0001h
CCP2CON_MODE2_LENGTH                     equ 0001h
CCP2CON_MODE2_MASK                       equ 0004h
CCP2CON_MODE3_POSN                       equ 0003h
CCP2CON_MODE3_POSITION                   equ 0003h
CCP2CON_MODE3_SIZE                       equ 0001h
CCP2CON_MODE3_LENGTH                     equ 0001h
CCP2CON_MODE3_MASK                       equ 0008h
CCP2CON_CCP2MODE_POSN                    equ 0000h
CCP2CON_CCP2MODE_POSITION                equ 0000h
CCP2CON_CCP2MODE_SIZE                    equ 0004h
CCP2CON_CCP2MODE_LENGTH                  equ 0004h
CCP2CON_CCP2MODE_MASK                    equ 000Fh
CCP2CON_CCP2FMT_POSN                     equ 0004h
CCP2CON_CCP2FMT_POSITION                 equ 0004h
CCP2CON_CCP2FMT_SIZE                     equ 0001h
CCP2CON_CCP2FMT_LENGTH                   equ 0001h
CCP2CON_CCP2FMT_MASK                     equ 0010h
CCP2CON_CCP2OUT_POSN                     equ 0005h
CCP2CON_CCP2OUT_POSITION                 equ 0005h
CCP2CON_CCP2OUT_SIZE                     equ 0001h
CCP2CON_CCP2OUT_LENGTH                   equ 0001h
CCP2CON_CCP2OUT_MASK                     equ 0020h
CCP2CON_CCP2EN_POSN                      equ 0007h
CCP2CON_CCP2EN_POSITION                  equ 0007h
CCP2CON_CCP2EN_SIZE                      equ 0001h
CCP2CON_CCP2EN_LENGTH                    equ 0001h
CCP2CON_CCP2EN_MASK                      equ 0080h
CCP2CON_CCP2MODE0_POSN                   equ 0000h
CCP2CON_CCP2MODE0_POSITION               equ 0000h
CCP2CON_CCP2MODE0_SIZE                   equ 0001h
CCP2CON_CCP2MODE0_LENGTH                 equ 0001h
CCP2CON_CCP2MODE0_MASK                   equ 0001h
CCP2CON_CCP2MODE1_POSN                   equ 0001h
CCP2CON_CCP2MODE1_POSITION               equ 0001h
CCP2CON_CCP2MODE1_SIZE                   equ 0001h
CCP2CON_CCP2MODE1_LENGTH                 equ 0001h
CCP2CON_CCP2MODE1_MASK                   equ 0002h
CCP2CON_CCP2MODE2_POSN                   equ 0002h
CCP2CON_CCP2MODE2_POSITION               equ 0002h
CCP2CON_CCP2MODE2_SIZE                   equ 0001h
CCP2CON_CCP2MODE2_LENGTH                 equ 0001h
CCP2CON_CCP2MODE2_MASK                   equ 0004h
CCP2CON_CCP2MODE3_POSN                   equ 0003h
CCP2CON_CCP2MODE3_POSITION               equ 0003h
CCP2CON_CCP2MODE3_SIZE                   equ 0001h
CCP2CON_CCP2MODE3_LENGTH                 equ 0001h
CCP2CON_CCP2MODE3_MASK                   equ 0008h
CCP2CON_P2M1_POSN                        equ 0007h
CCP2CON_P2M1_POSITION                    equ 0007h
CCP2CON_P2M1_SIZE                        equ 0001h
CCP2CON_P2M1_LENGTH                      equ 0001h
CCP2CON_P2M1_MASK                        equ 0080h

// Register: CCP2CAP
#define CCP2CAP CCP2CAP
CCP2CAP                                  equ 0413h
// bitfield definitions
CCP2CAP_CTS_POSN                         equ 0000h
CCP2CAP_CTS_POSITION                     equ 0000h
CCP2CAP_CTS_SIZE                         equ 0006h
CCP2CAP_CTS_LENGTH                       equ 0006h
CCP2CAP_CTS_MASK                         equ 003Fh
CCP2CAP_CTS0_POSN                        equ 0000h
CCP2CAP_CTS0_POSITION                    equ 0000h
CCP2CAP_CTS0_SIZE                        equ 0001h
CCP2CAP_CTS0_LENGTH                      equ 0001h
CCP2CAP_CTS0_MASK                        equ 0001h
CCP2CAP_CTS1_POSN                        equ 0001h
CCP2CAP_CTS1_POSITION                    equ 0001h
CCP2CAP_CTS1_SIZE                        equ 0001h
CCP2CAP_CTS1_LENGTH                      equ 0001h
CCP2CAP_CTS1_MASK                        equ 0002h
CCP2CAP_CTS2_POSN                        equ 0002h
CCP2CAP_CTS2_POSITION                    equ 0002h
CCP2CAP_CTS2_SIZE                        equ 0001h
CCP2CAP_CTS2_LENGTH                      equ 0001h
CCP2CAP_CTS2_MASK                        equ 0004h
CCP2CAP_CTS3_POSN                        equ 0003h
CCP2CAP_CTS3_POSITION                    equ 0003h
CCP2CAP_CTS3_SIZE                        equ 0001h
CCP2CAP_CTS3_LENGTH                      equ 0001h
CCP2CAP_CTS3_MASK                        equ 0008h
CCP2CAP_CCP2CTS_POSN                     equ 0000h
CCP2CAP_CCP2CTS_POSITION                 equ 0000h
CCP2CAP_CCP2CTS_SIZE                     equ 0006h
CCP2CAP_CCP2CTS_LENGTH                   equ 0006h
CCP2CAP_CCP2CTS_MASK                     equ 003Fh
CCP2CAP_CCP2CTS0_POSN                    equ 0000h
CCP2CAP_CCP2CTS0_POSITION                equ 0000h
CCP2CAP_CCP2CTS0_SIZE                    equ 0001h
CCP2CAP_CCP2CTS0_LENGTH                  equ 0001h
CCP2CAP_CCP2CTS0_MASK                    equ 0001h
CCP2CAP_CCP2CTS1_POSN                    equ 0001h
CCP2CAP_CCP2CTS1_POSITION                equ 0001h
CCP2CAP_CCP2CTS1_SIZE                    equ 0001h
CCP2CAP_CCP2CTS1_LENGTH                  equ 0001h
CCP2CAP_CCP2CTS1_MASK                    equ 0002h
CCP2CAP_CCP2CTS2_POSN                    equ 0002h
CCP2CAP_CCP2CTS2_POSITION                equ 0002h
CCP2CAP_CCP2CTS2_SIZE                    equ 0001h
CCP2CAP_CCP2CTS2_LENGTH                  equ 0001h
CCP2CAP_CCP2CTS2_MASK                    equ 0004h
CCP2CAP_CCP2CTS3_POSN                    equ 0003h
CCP2CAP_CCP2CTS3_POSITION                equ 0003h
CCP2CAP_CCP2CTS3_SIZE                    equ 0001h
CCP2CAP_CCP2CTS3_LENGTH                  equ 0001h
CCP2CAP_CCP2CTS3_MASK                    equ 0008h

// Register: CCPTMRS0
#define CCPTMRS0 CCPTMRS0
CCPTMRS0                                 equ 041Fh
// bitfield definitions
CCPTMRS0_C1TSEL_POSN                     equ 0000h
CCPTMRS0_C1TSEL_POSITION                 equ 0000h
CCPTMRS0_C1TSEL_SIZE                     equ 0002h
CCPTMRS0_C1TSEL_LENGTH                   equ 0002h
CCPTMRS0_C1TSEL_MASK                     equ 0003h
CCPTMRS0_C2TSEL_POSN                     equ 0002h
CCPTMRS0_C2TSEL_POSITION                 equ 0002h
CCPTMRS0_C2TSEL_SIZE                     equ 0002h
CCPTMRS0_C2TSEL_LENGTH                   equ 0002h
CCPTMRS0_C2TSEL_MASK                     equ 000Ch

// Register: CLBCON
#define CLBCON CLBCON
CLBCON                                   equ 050Ch
// bitfield definitions
CLBCON_BUSY_POSN                         equ 0000h
CLBCON_BUSY_POSITION                     equ 0000h
CLBCON_BUSY_SIZE                         equ 0001h
CLBCON_BUSY_LENGTH                       equ 0001h
CLBCON_BUSY_MASK                         equ 0001h
CLBCON_EN_POSN                           equ 0007h
CLBCON_EN_POSITION                       equ 0007h
CLBCON_EN_SIZE                           equ 0001h
CLBCON_EN_LENGTH                         equ 0001h
CLBCON_EN_MASK                           equ 0080h
CLBCON_CLBEN_POSN                        equ 0007h
CLBCON_CLBEN_POSITION                    equ 0007h
CLBCON_CLBEN_SIZE                        equ 0001h
CLBCON_CLBEN_LENGTH                      equ 0001h
CLBCON_CLBEN_MASK                        equ 0080h

// Register: CLBSWINU
#define CLBSWINU CLBSWINU
CLBSWINU                                 equ 050Dh
// bitfield definitions
CLBSWINU_CLBSWINU_POSN                   equ 0000h
CLBSWINU_CLBSWINU_POSITION               equ 0000h
CLBSWINU_CLBSWINU_SIZE                   equ 0008h
CLBSWINU_CLBSWINU_LENGTH                 equ 0008h
CLBSWINU_CLBSWINU_MASK                   equ 00FFh
CLBSWINU_CLBSWIN24_POSN                  equ 0000h
CLBSWINU_CLBSWIN24_POSITION              equ 0000h
CLBSWINU_CLBSWIN24_SIZE                  equ 0001h
CLBSWINU_CLBSWIN24_LENGTH                equ 0001h
CLBSWINU_CLBSWIN24_MASK                  equ 0001h
CLBSWINU_CLBSWIN25_POSN                  equ 0001h
CLBSWINU_CLBSWIN25_POSITION              equ 0001h
CLBSWINU_CLBSWIN25_SIZE                  equ 0001h
CLBSWINU_CLBSWIN25_LENGTH                equ 0001h
CLBSWINU_CLBSWIN25_MASK                  equ 0002h
CLBSWINU_CLBSWIN26_POSN                  equ 0002h
CLBSWINU_CLBSWIN26_POSITION              equ 0002h
CLBSWINU_CLBSWIN26_SIZE                  equ 0001h
CLBSWINU_CLBSWIN26_LENGTH                equ 0001h
CLBSWINU_CLBSWIN26_MASK                  equ 0004h
CLBSWINU_CLBSWIN27_POSN                  equ 0003h
CLBSWINU_CLBSWIN27_POSITION              equ 0003h
CLBSWINU_CLBSWIN27_SIZE                  equ 0001h
CLBSWINU_CLBSWIN27_LENGTH                equ 0001h
CLBSWINU_CLBSWIN27_MASK                  equ 0008h
CLBSWINU_CLBSWIN28_POSN                  equ 0004h
CLBSWINU_CLBSWIN28_POSITION              equ 0004h
CLBSWINU_CLBSWIN28_SIZE                  equ 0001h
CLBSWINU_CLBSWIN28_LENGTH                equ 0001h
CLBSWINU_CLBSWIN28_MASK                  equ 0010h
CLBSWINU_CLBSWIN29_POSN                  equ 0005h
CLBSWINU_CLBSWIN29_POSITION              equ 0005h
CLBSWINU_CLBSWIN29_SIZE                  equ 0001h
CLBSWINU_CLBSWIN29_LENGTH                equ 0001h
CLBSWINU_CLBSWIN29_MASK                  equ 0020h
CLBSWINU_CLBSWIN30_POSN                  equ 0006h
CLBSWINU_CLBSWIN30_POSITION              equ 0006h
CLBSWINU_CLBSWIN30_SIZE                  equ 0001h
CLBSWINU_CLBSWIN30_LENGTH                equ 0001h
CLBSWINU_CLBSWIN30_MASK                  equ 0040h
CLBSWINU_CLBSWIN31_POSN                  equ 0007h
CLBSWINU_CLBSWIN31_POSITION              equ 0007h
CLBSWINU_CLBSWIN31_SIZE                  equ 0001h
CLBSWINU_CLBSWIN31_LENGTH                equ 0001h
CLBSWINU_CLBSWIN31_MASK                  equ 0080h

// Register: CLBSWINH
#define CLBSWINH CLBSWINH
CLBSWINH                                 equ 050Eh
// bitfield definitions
CLBSWINH_CLBSWINH_POSN                   equ 0000h
CLBSWINH_CLBSWINH_POSITION               equ 0000h
CLBSWINH_CLBSWINH_SIZE                   equ 0008h
CLBSWINH_CLBSWINH_LENGTH                 equ 0008h
CLBSWINH_CLBSWINH_MASK                   equ 00FFh
CLBSWINH_CLBSWIN16_POSN                  equ 0000h
CLBSWINH_CLBSWIN16_POSITION              equ 0000h
CLBSWINH_CLBSWIN16_SIZE                  equ 0001h
CLBSWINH_CLBSWIN16_LENGTH                equ 0001h
CLBSWINH_CLBSWIN16_MASK                  equ 0001h
CLBSWINH_CLBSWIN17_POSN                  equ 0001h
CLBSWINH_CLBSWIN17_POSITION              equ 0001h
CLBSWINH_CLBSWIN17_SIZE                  equ 0001h
CLBSWINH_CLBSWIN17_LENGTH                equ 0001h
CLBSWINH_CLBSWIN17_MASK                  equ 0002h
CLBSWINH_CLBSWIN18_POSN                  equ 0002h
CLBSWINH_CLBSWIN18_POSITION              equ 0002h
CLBSWINH_CLBSWIN18_SIZE                  equ 0001h
CLBSWINH_CLBSWIN18_LENGTH                equ 0001h
CLBSWINH_CLBSWIN18_MASK                  equ 0004h
CLBSWINH_CLBSWIN19_POSN                  equ 0003h
CLBSWINH_CLBSWIN19_POSITION              equ 0003h
CLBSWINH_CLBSWIN19_SIZE                  equ 0001h
CLBSWINH_CLBSWIN19_LENGTH                equ 0001h
CLBSWINH_CLBSWIN19_MASK                  equ 0008h
CLBSWINH_CLBSWIN20_POSN                  equ 0004h
CLBSWINH_CLBSWIN20_POSITION              equ 0004h
CLBSWINH_CLBSWIN20_SIZE                  equ 0001h
CLBSWINH_CLBSWIN20_LENGTH                equ 0001h
CLBSWINH_CLBSWIN20_MASK                  equ 0010h
CLBSWINH_CLBSWIN21_POSN                  equ 0005h
CLBSWINH_CLBSWIN21_POSITION              equ 0005h
CLBSWINH_CLBSWIN21_SIZE                  equ 0001h
CLBSWINH_CLBSWIN21_LENGTH                equ 0001h
CLBSWINH_CLBSWIN21_MASK                  equ 0020h
CLBSWINH_CLBSWIN22_POSN                  equ 0006h
CLBSWINH_CLBSWIN22_POSITION              equ 0006h
CLBSWINH_CLBSWIN22_SIZE                  equ 0001h
CLBSWINH_CLBSWIN22_LENGTH                equ 0001h
CLBSWINH_CLBSWIN22_MASK                  equ 0040h
CLBSWINH_CLBSWIN23_POSN                  equ 0007h
CLBSWINH_CLBSWIN23_POSITION              equ 0007h
CLBSWINH_CLBSWIN23_SIZE                  equ 0001h
CLBSWINH_CLBSWIN23_LENGTH                equ 0001h
CLBSWINH_CLBSWIN23_MASK                  equ 0080h

// Register: CLBSWINM
#define CLBSWINM CLBSWINM
CLBSWINM                                 equ 050Fh
// bitfield definitions
CLBSWINM_CLBSWINM_POSN                   equ 0000h
CLBSWINM_CLBSWINM_POSITION               equ 0000h
CLBSWINM_CLBSWINM_SIZE                   equ 0008h
CLBSWINM_CLBSWINM_LENGTH                 equ 0008h
CLBSWINM_CLBSWINM_MASK                   equ 00FFh
CLBSWINM_CLBSWIN8_POSN                   equ 0000h
CLBSWINM_CLBSWIN8_POSITION               equ 0000h
CLBSWINM_CLBSWIN8_SIZE                   equ 0001h
CLBSWINM_CLBSWIN8_LENGTH                 equ 0001h
CLBSWINM_CLBSWIN8_MASK                   equ 0001h
CLBSWINM_CLBSWIN9_POSN                   equ 0001h
CLBSWINM_CLBSWIN9_POSITION               equ 0001h
CLBSWINM_CLBSWIN9_SIZE                   equ 0001h
CLBSWINM_CLBSWIN9_LENGTH                 equ 0001h
CLBSWINM_CLBSWIN9_MASK                   equ 0002h
CLBSWINM_CLBSWIN10_POSN                  equ 0002h
CLBSWINM_CLBSWIN10_POSITION              equ 0002h
CLBSWINM_CLBSWIN10_SIZE                  equ 0001h
CLBSWINM_CLBSWIN10_LENGTH                equ 0001h
CLBSWINM_CLBSWIN10_MASK                  equ 0004h
CLBSWINM_CLBSWIN11_POSN                  equ 0003h
CLBSWINM_CLBSWIN11_POSITION              equ 0003h
CLBSWINM_CLBSWIN11_SIZE                  equ 0001h
CLBSWINM_CLBSWIN11_LENGTH                equ 0001h
CLBSWINM_CLBSWIN11_MASK                  equ 0008h
CLBSWINM_CLBSWIN12_POSN                  equ 0004h
CLBSWINM_CLBSWIN12_POSITION              equ 0004h
CLBSWINM_CLBSWIN12_SIZE                  equ 0001h
CLBSWINM_CLBSWIN12_LENGTH                equ 0001h
CLBSWINM_CLBSWIN12_MASK                  equ 0010h
CLBSWINM_CLBSWIN13_POSN                  equ 0005h
CLBSWINM_CLBSWIN13_POSITION              equ 0005h
CLBSWINM_CLBSWIN13_SIZE                  equ 0001h
CLBSWINM_CLBSWIN13_LENGTH                equ 0001h
CLBSWINM_CLBSWIN13_MASK                  equ 0020h
CLBSWINM_CLBSWIN14_POSN                  equ 0006h
CLBSWINM_CLBSWIN14_POSITION              equ 0006h
CLBSWINM_CLBSWIN14_SIZE                  equ 0001h
CLBSWINM_CLBSWIN14_LENGTH                equ 0001h
CLBSWINM_CLBSWIN14_MASK                  equ 0040h
CLBSWINM_CLBSWIN15_POSN                  equ 0007h
CLBSWINM_CLBSWIN15_POSITION              equ 0007h
CLBSWINM_CLBSWIN15_SIZE                  equ 0001h
CLBSWINM_CLBSWIN15_LENGTH                equ 0001h
CLBSWINM_CLBSWIN15_MASK                  equ 0080h

// Register: CLBSWINL
#define CLBSWINL CLBSWINL
CLBSWINL                                 equ 0510h
// bitfield definitions
CLBSWINL_CLBSWINL_POSN                   equ 0000h
CLBSWINL_CLBSWINL_POSITION               equ 0000h
CLBSWINL_CLBSWINL_SIZE                   equ 0008h
CLBSWINL_CLBSWINL_LENGTH                 equ 0008h
CLBSWINL_CLBSWINL_MASK                   equ 00FFh
CLBSWINL_CLBSWIN0_POSN                   equ 0000h
CLBSWINL_CLBSWIN0_POSITION               equ 0000h
CLBSWINL_CLBSWIN0_SIZE                   equ 0001h
CLBSWINL_CLBSWIN0_LENGTH                 equ 0001h
CLBSWINL_CLBSWIN0_MASK                   equ 0001h
CLBSWINL_CLBSWIN1_POSN                   equ 0001h
CLBSWINL_CLBSWIN1_POSITION               equ 0001h
CLBSWINL_CLBSWIN1_SIZE                   equ 0001h
CLBSWINL_CLBSWIN1_LENGTH                 equ 0001h
CLBSWINL_CLBSWIN1_MASK                   equ 0002h
CLBSWINL_CLBSWIN2_POSN                   equ 0002h
CLBSWINL_CLBSWIN2_POSITION               equ 0002h
CLBSWINL_CLBSWIN2_SIZE                   equ 0001h
CLBSWINL_CLBSWIN2_LENGTH                 equ 0001h
CLBSWINL_CLBSWIN2_MASK                   equ 0004h
CLBSWINL_CLBSWIN3_POSN                   equ 0003h
CLBSWINL_CLBSWIN3_POSITION               equ 0003h
CLBSWINL_CLBSWIN3_SIZE                   equ 0001h
CLBSWINL_CLBSWIN3_LENGTH                 equ 0001h
CLBSWINL_CLBSWIN3_MASK                   equ 0008h
CLBSWINL_CLBSWIN4_POSN                   equ 0004h
CLBSWINL_CLBSWIN4_POSITION               equ 0004h
CLBSWINL_CLBSWIN4_SIZE                   equ 0001h
CLBSWINL_CLBSWIN4_LENGTH                 equ 0001h
CLBSWINL_CLBSWIN4_MASK                   equ 0010h
CLBSWINL_CLBSWIN5_POSN                   equ 0005h
CLBSWINL_CLBSWIN5_POSITION               equ 0005h
CLBSWINL_CLBSWIN5_SIZE                   equ 0001h
CLBSWINL_CLBSWIN5_LENGTH                 equ 0001h
CLBSWINL_CLBSWIN5_MASK                   equ 0020h
CLBSWINL_CLBSWIN6_POSN                   equ 0006h
CLBSWINL_CLBSWIN6_POSITION               equ 0006h
CLBSWINL_CLBSWIN6_SIZE                   equ 0001h
CLBSWINL_CLBSWIN6_LENGTH                 equ 0001h
CLBSWINL_CLBSWIN6_MASK                   equ 0040h
CLBSWINL_CLBSWIN7_POSN                   equ 0007h
CLBSWINL_CLBSWIN7_POSITION               equ 0007h
CLBSWINL_CLBSWIN7_SIZE                   equ 0001h
CLBSWINL_CLBSWIN7_LENGTH                 equ 0001h
CLBSWINL_CLBSWIN7_MASK                   equ 0080h

// Register: CLBCLK
#define CLBCLK CLBCLK
CLBCLK                                   equ 0515h
// bitfield definitions
CLBCLK_CLK_POSN                          equ 0000h
CLBCLK_CLK_POSITION                      equ 0000h
CLBCLK_CLK_SIZE                          equ 0004h
CLBCLK_CLK_LENGTH                        equ 0004h
CLBCLK_CLK_MASK                          equ 000Fh
CLBCLK_CLK0_POSN                         equ 0000h
CLBCLK_CLK0_POSITION                     equ 0000h
CLBCLK_CLK0_SIZE                         equ 0001h
CLBCLK_CLK0_LENGTH                       equ 0001h
CLBCLK_CLK0_MASK                         equ 0001h
CLBCLK_CLK1_POSN                         equ 0001h
CLBCLK_CLK1_POSITION                     equ 0001h
CLBCLK_CLK1_SIZE                         equ 0001h
CLBCLK_CLK1_LENGTH                       equ 0001h
CLBCLK_CLK1_MASK                         equ 0002h
CLBCLK_CLK2_POSN                         equ 0002h
CLBCLK_CLK2_POSITION                     equ 0002h
CLBCLK_CLK2_SIZE                         equ 0001h
CLBCLK_CLK2_LENGTH                       equ 0001h
CLBCLK_CLK2_MASK                         equ 0004h
CLBCLK_CLK3_POSN                         equ 0003h
CLBCLK_CLK3_POSITION                     equ 0003h
CLBCLK_CLK3_SIZE                         equ 0001h
CLBCLK_CLK3_LENGTH                       equ 0001h
CLBCLK_CLK3_MASK                         equ 0008h

// Register: CLBPPSCON4
#define CLBPPSCON4 CLBPPSCON4
CLBPPSCON4                               equ 0516h
// bitfield definitions
CLBPPSCON4_OESEL6_POSN                   equ 0000h
CLBPPSCON4_OESEL6_POSITION               equ 0000h
CLBPPSCON4_OESEL6_SIZE                   equ 0004h
CLBPPSCON4_OESEL6_LENGTH                 equ 0004h
CLBPPSCON4_OESEL6_MASK                   equ 000Fh
CLBPPSCON4_OESEL7_POSN                   equ 0004h
CLBPPSCON4_OESEL7_POSITION               equ 0004h
CLBPPSCON4_OESEL7_SIZE                   equ 0004h
CLBPPSCON4_OESEL7_LENGTH                 equ 0004h
CLBPPSCON4_OESEL7_MASK                   equ 00F0h

// Register: CLBPPSCON3
#define CLBPPSCON3 CLBPPSCON3
CLBPPSCON3                               equ 0517h
// bitfield definitions
CLBPPSCON3_OESEL4_POSN                   equ 0000h
CLBPPSCON3_OESEL4_POSITION               equ 0000h
CLBPPSCON3_OESEL4_SIZE                   equ 0004h
CLBPPSCON3_OESEL4_LENGTH                 equ 0004h
CLBPPSCON3_OESEL4_MASK                   equ 000Fh
CLBPPSCON3_OESEL5_POSN                   equ 0004h
CLBPPSCON3_OESEL5_POSITION               equ 0004h
CLBPPSCON3_OESEL5_SIZE                   equ 0004h
CLBPPSCON3_OESEL5_LENGTH                 equ 0004h
CLBPPSCON3_OESEL5_MASK                   equ 00F0h

// Register: CLBPPSCON2
#define CLBPPSCON2 CLBPPSCON2
CLBPPSCON2                               equ 0518h
// bitfield definitions
CLBPPSCON2_OESEL2_POSN                   equ 0000h
CLBPPSCON2_OESEL2_POSITION               equ 0000h
CLBPPSCON2_OESEL2_SIZE                   equ 0004h
CLBPPSCON2_OESEL2_LENGTH                 equ 0004h
CLBPPSCON2_OESEL2_MASK                   equ 000Fh
CLBPPSCON2_OESEL3_POSN                   equ 0004h
CLBPPSCON2_OESEL3_POSITION               equ 0004h
CLBPPSCON2_OESEL3_SIZE                   equ 0004h
CLBPPSCON2_OESEL3_LENGTH                 equ 0004h
CLBPPSCON2_OESEL3_MASK                   equ 00F0h

// Register: CLBPPSCON1
#define CLBPPSCON1 CLBPPSCON1
CLBPPSCON1                               equ 0519h
// bitfield definitions
CLBPPSCON1_OESEL0_POSN                   equ 0000h
CLBPPSCON1_OESEL0_POSITION               equ 0000h
CLBPPSCON1_OESEL0_SIZE                   equ 0004h
CLBPPSCON1_OESEL0_LENGTH                 equ 0004h
CLBPPSCON1_OESEL0_MASK                   equ 000Fh
CLBPPSCON1_OESEL1_POSN                   equ 0004h
CLBPPSCON1_OESEL1_POSITION               equ 0004h
CLBPPSCON1_OESEL1_SIZE                   equ 0004h
CLBPPSCON1_OESEL1_LENGTH                 equ 0004h
CLBPPSCON1_OESEL1_MASK                   equ 00F0h

// Register: CLCnCON
#define CLCnCON CLCnCON
CLCnCON                                  equ 068Ch
// bitfield definitions
CLCnCON_MODE_POSN                        equ 0000h
CLCnCON_MODE_POSITION                    equ 0000h
CLCnCON_MODE_SIZE                        equ 0003h
CLCnCON_MODE_LENGTH                      equ 0003h
CLCnCON_MODE_MASK                        equ 0007h
CLCnCON_INTN_POSN                        equ 0003h
CLCnCON_INTN_POSITION                    equ 0003h
CLCnCON_INTN_SIZE                        equ 0001h
CLCnCON_INTN_LENGTH                      equ 0001h
CLCnCON_INTN_MASK                        equ 0008h
CLCnCON_INTP_POSN                        equ 0004h
CLCnCON_INTP_POSITION                    equ 0004h
CLCnCON_INTP_SIZE                        equ 0001h
CLCnCON_INTP_LENGTH                      equ 0001h
CLCnCON_INTP_MASK                        equ 0010h
CLCnCON_OUT_POSN                         equ 0005h
CLCnCON_OUT_POSITION                     equ 0005h
CLCnCON_OUT_SIZE                         equ 0001h
CLCnCON_OUT_LENGTH                       equ 0001h
CLCnCON_OUT_MASK                         equ 0020h
CLCnCON_EN_POSN                          equ 0007h
CLCnCON_EN_POSITION                      equ 0007h
CLCnCON_EN_SIZE                          equ 0001h
CLCnCON_EN_LENGTH                        equ 0001h
CLCnCON_EN_MASK                          equ 0080h
CLCnCON_MODE0_POSN                       equ 0000h
CLCnCON_MODE0_POSITION                   equ 0000h
CLCnCON_MODE0_SIZE                       equ 0001h
CLCnCON_MODE0_LENGTH                     equ 0001h
CLCnCON_MODE0_MASK                       equ 0001h
CLCnCON_MODE1_POSN                       equ 0001h
CLCnCON_MODE1_POSITION                   equ 0001h
CLCnCON_MODE1_SIZE                       equ 0001h
CLCnCON_MODE1_LENGTH                     equ 0001h
CLCnCON_MODE1_MASK                       equ 0002h
CLCnCON_MODE2_POSN                       equ 0002h
CLCnCON_MODE2_POSITION                   equ 0002h
CLCnCON_MODE2_SIZE                       equ 0001h
CLCnCON_MODE2_LENGTH                     equ 0001h
CLCnCON_MODE2_MASK                       equ 0004h

// Register: CLCnPOL
#define CLCnPOL CLCnPOL
CLCnPOL                                  equ 068Dh
// bitfield definitions
CLCnPOL_G1POL_POSN                       equ 0000h
CLCnPOL_G1POL_POSITION                   equ 0000h
CLCnPOL_G1POL_SIZE                       equ 0001h
CLCnPOL_G1POL_LENGTH                     equ 0001h
CLCnPOL_G1POL_MASK                       equ 0001h
CLCnPOL_G2POL_POSN                       equ 0001h
CLCnPOL_G2POL_POSITION                   equ 0001h
CLCnPOL_G2POL_SIZE                       equ 0001h
CLCnPOL_G2POL_LENGTH                     equ 0001h
CLCnPOL_G2POL_MASK                       equ 0002h
CLCnPOL_G3POL_POSN                       equ 0002h
CLCnPOL_G3POL_POSITION                   equ 0002h
CLCnPOL_G3POL_SIZE                       equ 0001h
CLCnPOL_G3POL_LENGTH                     equ 0001h
CLCnPOL_G3POL_MASK                       equ 0004h
CLCnPOL_G4POL_POSN                       equ 0003h
CLCnPOL_G4POL_POSITION                   equ 0003h
CLCnPOL_G4POL_SIZE                       equ 0001h
CLCnPOL_G4POL_LENGTH                     equ 0001h
CLCnPOL_G4POL_MASK                       equ 0008h
CLCnPOL_POL_POSN                         equ 0007h
CLCnPOL_POL_POSITION                     equ 0007h
CLCnPOL_POL_SIZE                         equ 0001h
CLCnPOL_POL_LENGTH                       equ 0001h
CLCnPOL_POL_MASK                         equ 0080h

// Register: CLCnSEL0
#define CLCnSEL0 CLCnSEL0
CLCnSEL0                                 equ 068Eh
// bitfield definitions
CLCnSEL0_D1S_POSN                        equ 0000h
CLCnSEL0_D1S_POSITION                    equ 0000h
CLCnSEL0_D1S_SIZE                        equ 0008h
CLCnSEL0_D1S_LENGTH                      equ 0008h
CLCnSEL0_D1S_MASK                        equ 00FFh
CLCnSEL0_D1S0_POSN                       equ 0000h
CLCnSEL0_D1S0_POSITION                   equ 0000h
CLCnSEL0_D1S0_SIZE                       equ 0001h
CLCnSEL0_D1S0_LENGTH                     equ 0001h
CLCnSEL0_D1S0_MASK                       equ 0001h
CLCnSEL0_D1S1_POSN                       equ 0001h
CLCnSEL0_D1S1_POSITION                   equ 0001h
CLCnSEL0_D1S1_SIZE                       equ 0001h
CLCnSEL0_D1S1_LENGTH                     equ 0001h
CLCnSEL0_D1S1_MASK                       equ 0002h
CLCnSEL0_D1S2_POSN                       equ 0002h
CLCnSEL0_D1S2_POSITION                   equ 0002h
CLCnSEL0_D1S2_SIZE                       equ 0001h
CLCnSEL0_D1S2_LENGTH                     equ 0001h
CLCnSEL0_D1S2_MASK                       equ 0004h
CLCnSEL0_D1S3_POSN                       equ 0003h
CLCnSEL0_D1S3_POSITION                   equ 0003h
CLCnSEL0_D1S3_SIZE                       equ 0001h
CLCnSEL0_D1S3_LENGTH                     equ 0001h
CLCnSEL0_D1S3_MASK                       equ 0008h
CLCnSEL0_D1S4_POSN                       equ 0004h
CLCnSEL0_D1S4_POSITION                   equ 0004h
CLCnSEL0_D1S4_SIZE                       equ 0001h
CLCnSEL0_D1S4_LENGTH                     equ 0001h
CLCnSEL0_D1S4_MASK                       equ 0010h
CLCnSEL0_D1S5_POSN                       equ 0005h
CLCnSEL0_D1S5_POSITION                   equ 0005h
CLCnSEL0_D1S5_SIZE                       equ 0001h
CLCnSEL0_D1S5_LENGTH                     equ 0001h
CLCnSEL0_D1S5_MASK                       equ 0020h
CLCnSEL0_D1S6_POSN                       equ 0006h
CLCnSEL0_D1S6_POSITION                   equ 0006h
CLCnSEL0_D1S6_SIZE                       equ 0001h
CLCnSEL0_D1S6_LENGTH                     equ 0001h
CLCnSEL0_D1S6_MASK                       equ 0040h

// Register: CLCnSEL1
#define CLCnSEL1 CLCnSEL1
CLCnSEL1                                 equ 068Fh
// bitfield definitions
CLCnSEL1_D2S_POSN                        equ 0000h
CLCnSEL1_D2S_POSITION                    equ 0000h
CLCnSEL1_D2S_SIZE                        equ 0008h
CLCnSEL1_D2S_LENGTH                      equ 0008h
CLCnSEL1_D2S_MASK                        equ 00FFh
CLCnSEL1_D2S0_POSN                       equ 0000h
CLCnSEL1_D2S0_POSITION                   equ 0000h
CLCnSEL1_D2S0_SIZE                       equ 0001h
CLCnSEL1_D2S0_LENGTH                     equ 0001h
CLCnSEL1_D2S0_MASK                       equ 0001h
CLCnSEL1_D2S1_POSN                       equ 0001h
CLCnSEL1_D2S1_POSITION                   equ 0001h
CLCnSEL1_D2S1_SIZE                       equ 0001h
CLCnSEL1_D2S1_LENGTH                     equ 0001h
CLCnSEL1_D2S1_MASK                       equ 0002h
CLCnSEL1_D2S2_POSN                       equ 0002h
CLCnSEL1_D2S2_POSITION                   equ 0002h
CLCnSEL1_D2S2_SIZE                       equ 0001h
CLCnSEL1_D2S2_LENGTH                     equ 0001h
CLCnSEL1_D2S2_MASK                       equ 0004h
CLCnSEL1_D2S3_POSN                       equ 0003h
CLCnSEL1_D2S3_POSITION                   equ 0003h
CLCnSEL1_D2S3_SIZE                       equ 0001h
CLCnSEL1_D2S3_LENGTH                     equ 0001h
CLCnSEL1_D2S3_MASK                       equ 0008h
CLCnSEL1_D2S4_POSN                       equ 0004h
CLCnSEL1_D2S4_POSITION                   equ 0004h
CLCnSEL1_D2S4_SIZE                       equ 0001h
CLCnSEL1_D2S4_LENGTH                     equ 0001h
CLCnSEL1_D2S4_MASK                       equ 0010h
CLCnSEL1_D2S5_POSN                       equ 0005h
CLCnSEL1_D2S5_POSITION                   equ 0005h
CLCnSEL1_D2S5_SIZE                       equ 0001h
CLCnSEL1_D2S5_LENGTH                     equ 0001h
CLCnSEL1_D2S5_MASK                       equ 0020h
CLCnSEL1_D2S6_POSN                       equ 0006h
CLCnSEL1_D2S6_POSITION                   equ 0006h
CLCnSEL1_D2S6_SIZE                       equ 0001h
CLCnSEL1_D2S6_LENGTH                     equ 0001h
CLCnSEL1_D2S6_MASK                       equ 0040h

// Register: CLCnSEL2
#define CLCnSEL2 CLCnSEL2
CLCnSEL2                                 equ 0690h
// bitfield definitions
CLCnSEL2_D3S_POSN                        equ 0000h
CLCnSEL2_D3S_POSITION                    equ 0000h
CLCnSEL2_D3S_SIZE                        equ 0008h
CLCnSEL2_D3S_LENGTH                      equ 0008h
CLCnSEL2_D3S_MASK                        equ 00FFh
CLCnSEL2_D3S0_POSN                       equ 0000h
CLCnSEL2_D3S0_POSITION                   equ 0000h
CLCnSEL2_D3S0_SIZE                       equ 0001h
CLCnSEL2_D3S0_LENGTH                     equ 0001h
CLCnSEL2_D3S0_MASK                       equ 0001h
CLCnSEL2_D3S1_POSN                       equ 0001h
CLCnSEL2_D3S1_POSITION                   equ 0001h
CLCnSEL2_D3S1_SIZE                       equ 0001h
CLCnSEL2_D3S1_LENGTH                     equ 0001h
CLCnSEL2_D3S1_MASK                       equ 0002h
CLCnSEL2_D3S2_POSN                       equ 0002h
CLCnSEL2_D3S2_POSITION                   equ 0002h
CLCnSEL2_D3S2_SIZE                       equ 0001h
CLCnSEL2_D3S2_LENGTH                     equ 0001h
CLCnSEL2_D3S2_MASK                       equ 0004h
CLCnSEL2_D3S3_POSN                       equ 0003h
CLCnSEL2_D3S3_POSITION                   equ 0003h
CLCnSEL2_D3S3_SIZE                       equ 0001h
CLCnSEL2_D3S3_LENGTH                     equ 0001h
CLCnSEL2_D3S3_MASK                       equ 0008h
CLCnSEL2_D3S4_POSN                       equ 0004h
CLCnSEL2_D3S4_POSITION                   equ 0004h
CLCnSEL2_D3S4_SIZE                       equ 0001h
CLCnSEL2_D3S4_LENGTH                     equ 0001h
CLCnSEL2_D3S4_MASK                       equ 0010h
CLCnSEL2_D3S5_POSN                       equ 0005h
CLCnSEL2_D3S5_POSITION                   equ 0005h
CLCnSEL2_D3S5_SIZE                       equ 0001h
CLCnSEL2_D3S5_LENGTH                     equ 0001h
CLCnSEL2_D3S5_MASK                       equ 0020h
CLCnSEL2_D3S6_POSN                       equ 0006h
CLCnSEL2_D3S6_POSITION                   equ 0006h
CLCnSEL2_D3S6_SIZE                       equ 0001h
CLCnSEL2_D3S6_LENGTH                     equ 0001h
CLCnSEL2_D3S6_MASK                       equ 0040h

// Register: CLCnSEL3
#define CLCnSEL3 CLCnSEL3
CLCnSEL3                                 equ 0691h
// bitfield definitions
CLCnSEL3_D4S_POSN                        equ 0000h
CLCnSEL3_D4S_POSITION                    equ 0000h
CLCnSEL3_D4S_SIZE                        equ 0008h
CLCnSEL3_D4S_LENGTH                      equ 0008h
CLCnSEL3_D4S_MASK                        equ 00FFh
CLCnSEL3_D4S0_POSN                       equ 0000h
CLCnSEL3_D4S0_POSITION                   equ 0000h
CLCnSEL3_D4S0_SIZE                       equ 0001h
CLCnSEL3_D4S0_LENGTH                     equ 0001h
CLCnSEL3_D4S0_MASK                       equ 0001h
CLCnSEL3_D4S1_POSN                       equ 0001h
CLCnSEL3_D4S1_POSITION                   equ 0001h
CLCnSEL3_D4S1_SIZE                       equ 0001h
CLCnSEL3_D4S1_LENGTH                     equ 0001h
CLCnSEL3_D4S1_MASK                       equ 0002h
CLCnSEL3_D4S2_POSN                       equ 0002h
CLCnSEL3_D4S2_POSITION                   equ 0002h
CLCnSEL3_D4S2_SIZE                       equ 0001h
CLCnSEL3_D4S2_LENGTH                     equ 0001h
CLCnSEL3_D4S2_MASK                       equ 0004h
CLCnSEL3_D4S3_POSN                       equ 0003h
CLCnSEL3_D4S3_POSITION                   equ 0003h
CLCnSEL3_D4S3_SIZE                       equ 0001h
CLCnSEL3_D4S3_LENGTH                     equ 0001h
CLCnSEL3_D4S3_MASK                       equ 0008h
CLCnSEL3_D4S4_POSN                       equ 0004h
CLCnSEL3_D4S4_POSITION                   equ 0004h
CLCnSEL3_D4S4_SIZE                       equ 0001h
CLCnSEL3_D4S4_LENGTH                     equ 0001h
CLCnSEL3_D4S4_MASK                       equ 0010h
CLCnSEL3_D4S5_POSN                       equ 0005h
CLCnSEL3_D4S5_POSITION                   equ 0005h
CLCnSEL3_D4S5_SIZE                       equ 0001h
CLCnSEL3_D4S5_LENGTH                     equ 0001h
CLCnSEL3_D4S5_MASK                       equ 0020h
CLCnSEL3_D4S6_POSN                       equ 0006h
CLCnSEL3_D4S6_POSITION                   equ 0006h
CLCnSEL3_D4S6_SIZE                       equ 0001h
CLCnSEL3_D4S6_LENGTH                     equ 0001h
CLCnSEL3_D4S6_MASK                       equ 0040h

// Register: CLCnGLS0
#define CLCnGLS0 CLCnGLS0
CLCnGLS0                                 equ 0692h
// bitfield definitions
CLCnGLS0_G1D1N_POSN                      equ 0000h
CLCnGLS0_G1D1N_POSITION                  equ 0000h
CLCnGLS0_G1D1N_SIZE                      equ 0001h
CLCnGLS0_G1D1N_LENGTH                    equ 0001h
CLCnGLS0_G1D1N_MASK                      equ 0001h
CLCnGLS0_G1D1T_POSN                      equ 0001h
CLCnGLS0_G1D1T_POSITION                  equ 0001h
CLCnGLS0_G1D1T_SIZE                      equ 0001h
CLCnGLS0_G1D1T_LENGTH                    equ 0001h
CLCnGLS0_G1D1T_MASK                      equ 0002h
CLCnGLS0_G1D2N_POSN                      equ 0002h
CLCnGLS0_G1D2N_POSITION                  equ 0002h
CLCnGLS0_G1D2N_SIZE                      equ 0001h
CLCnGLS0_G1D2N_LENGTH                    equ 0001h
CLCnGLS0_G1D2N_MASK                      equ 0004h
CLCnGLS0_G1D2T_POSN                      equ 0003h
CLCnGLS0_G1D2T_POSITION                  equ 0003h
CLCnGLS0_G1D2T_SIZE                      equ 0001h
CLCnGLS0_G1D2T_LENGTH                    equ 0001h
CLCnGLS0_G1D2T_MASK                      equ 0008h
CLCnGLS0_G1D3N_POSN                      equ 0004h
CLCnGLS0_G1D3N_POSITION                  equ 0004h
CLCnGLS0_G1D3N_SIZE                      equ 0001h
CLCnGLS0_G1D3N_LENGTH                    equ 0001h
CLCnGLS0_G1D3N_MASK                      equ 0010h
CLCnGLS0_G1D3T_POSN                      equ 0005h
CLCnGLS0_G1D3T_POSITION                  equ 0005h
CLCnGLS0_G1D3T_SIZE                      equ 0001h
CLCnGLS0_G1D3T_LENGTH                    equ 0001h
CLCnGLS0_G1D3T_MASK                      equ 0020h
CLCnGLS0_G1D4N_POSN                      equ 0006h
CLCnGLS0_G1D4N_POSITION                  equ 0006h
CLCnGLS0_G1D4N_SIZE                      equ 0001h
CLCnGLS0_G1D4N_LENGTH                    equ 0001h
CLCnGLS0_G1D4N_MASK                      equ 0040h
CLCnGLS0_G1D4T_POSN                      equ 0007h
CLCnGLS0_G1D4T_POSITION                  equ 0007h
CLCnGLS0_G1D4T_SIZE                      equ 0001h
CLCnGLS0_G1D4T_LENGTH                    equ 0001h
CLCnGLS0_G1D4T_MASK                      equ 0080h

// Register: CLCnGLS1
#define CLCnGLS1 CLCnGLS1
CLCnGLS1                                 equ 0693h
// bitfield definitions
CLCnGLS1_G2D1N_POSN                      equ 0000h
CLCnGLS1_G2D1N_POSITION                  equ 0000h
CLCnGLS1_G2D1N_SIZE                      equ 0001h
CLCnGLS1_G2D1N_LENGTH                    equ 0001h
CLCnGLS1_G2D1N_MASK                      equ 0001h
CLCnGLS1_G2D1T_POSN                      equ 0001h
CLCnGLS1_G2D1T_POSITION                  equ 0001h
CLCnGLS1_G2D1T_SIZE                      equ 0001h
CLCnGLS1_G2D1T_LENGTH                    equ 0001h
CLCnGLS1_G2D1T_MASK                      equ 0002h
CLCnGLS1_G2D2N_POSN                      equ 0002h
CLCnGLS1_G2D2N_POSITION                  equ 0002h
CLCnGLS1_G2D2N_SIZE                      equ 0001h
CLCnGLS1_G2D2N_LENGTH                    equ 0001h
CLCnGLS1_G2D2N_MASK                      equ 0004h
CLCnGLS1_G2D2T_POSN                      equ 0003h
CLCnGLS1_G2D2T_POSITION                  equ 0003h
CLCnGLS1_G2D2T_SIZE                      equ 0001h
CLCnGLS1_G2D2T_LENGTH                    equ 0001h
CLCnGLS1_G2D2T_MASK                      equ 0008h
CLCnGLS1_G2D3N_POSN                      equ 0004h
CLCnGLS1_G2D3N_POSITION                  equ 0004h
CLCnGLS1_G2D3N_SIZE                      equ 0001h
CLCnGLS1_G2D3N_LENGTH                    equ 0001h
CLCnGLS1_G2D3N_MASK                      equ 0010h
CLCnGLS1_G2D3T_POSN                      equ 0005h
CLCnGLS1_G2D3T_POSITION                  equ 0005h
CLCnGLS1_G2D3T_SIZE                      equ 0001h
CLCnGLS1_G2D3T_LENGTH                    equ 0001h
CLCnGLS1_G2D3T_MASK                      equ 0020h
CLCnGLS1_G2D4N_POSN                      equ 0006h
CLCnGLS1_G2D4N_POSITION                  equ 0006h
CLCnGLS1_G2D4N_SIZE                      equ 0001h
CLCnGLS1_G2D4N_LENGTH                    equ 0001h
CLCnGLS1_G2D4N_MASK                      equ 0040h
CLCnGLS1_G2D4T_POSN                      equ 0007h
CLCnGLS1_G2D4T_POSITION                  equ 0007h
CLCnGLS1_G2D4T_SIZE                      equ 0001h
CLCnGLS1_G2D4T_LENGTH                    equ 0001h
CLCnGLS1_G2D4T_MASK                      equ 0080h

// Register: CLCnGLS2
#define CLCnGLS2 CLCnGLS2
CLCnGLS2                                 equ 0694h
// bitfield definitions
CLCnGLS2_G3D1N_POSN                      equ 0000h
CLCnGLS2_G3D1N_POSITION                  equ 0000h
CLCnGLS2_G3D1N_SIZE                      equ 0001h
CLCnGLS2_G3D1N_LENGTH                    equ 0001h
CLCnGLS2_G3D1N_MASK                      equ 0001h
CLCnGLS2_G3D1T_POSN                      equ 0001h
CLCnGLS2_G3D1T_POSITION                  equ 0001h
CLCnGLS2_G3D1T_SIZE                      equ 0001h
CLCnGLS2_G3D1T_LENGTH                    equ 0001h
CLCnGLS2_G3D1T_MASK                      equ 0002h
CLCnGLS2_G3D2N_POSN                      equ 0002h
CLCnGLS2_G3D2N_POSITION                  equ 0002h
CLCnGLS2_G3D2N_SIZE                      equ 0001h
CLCnGLS2_G3D2N_LENGTH                    equ 0001h
CLCnGLS2_G3D2N_MASK                      equ 0004h
CLCnGLS2_G3D2T_POSN                      equ 0003h
CLCnGLS2_G3D2T_POSITION                  equ 0003h
CLCnGLS2_G3D2T_SIZE                      equ 0001h
CLCnGLS2_G3D2T_LENGTH                    equ 0001h
CLCnGLS2_G3D2T_MASK                      equ 0008h
CLCnGLS2_G3D3N_POSN                      equ 0004h
CLCnGLS2_G3D3N_POSITION                  equ 0004h
CLCnGLS2_G3D3N_SIZE                      equ 0001h
CLCnGLS2_G3D3N_LENGTH                    equ 0001h
CLCnGLS2_G3D3N_MASK                      equ 0010h
CLCnGLS2_G3D3T_POSN                      equ 0005h
CLCnGLS2_G3D3T_POSITION                  equ 0005h
CLCnGLS2_G3D3T_SIZE                      equ 0001h
CLCnGLS2_G3D3T_LENGTH                    equ 0001h
CLCnGLS2_G3D3T_MASK                      equ 0020h
CLCnGLS2_G3D4N_POSN                      equ 0006h
CLCnGLS2_G3D4N_POSITION                  equ 0006h
CLCnGLS2_G3D4N_SIZE                      equ 0001h
CLCnGLS2_G3D4N_LENGTH                    equ 0001h
CLCnGLS2_G3D4N_MASK                      equ 0040h
CLCnGLS2_G3D4T_POSN                      equ 0007h
CLCnGLS2_G3D4T_POSITION                  equ 0007h
CLCnGLS2_G3D4T_SIZE                      equ 0001h
CLCnGLS2_G3D4T_LENGTH                    equ 0001h
CLCnGLS2_G3D4T_MASK                      equ 0080h

// Register: CLCnGLS3
#define CLCnGLS3 CLCnGLS3
CLCnGLS3                                 equ 0695h
// bitfield definitions
CLCnGLS3_G4D1N_POSN                      equ 0000h
CLCnGLS3_G4D1N_POSITION                  equ 0000h
CLCnGLS3_G4D1N_SIZE                      equ 0001h
CLCnGLS3_G4D1N_LENGTH                    equ 0001h
CLCnGLS3_G4D1N_MASK                      equ 0001h
CLCnGLS3_G4D1T_POSN                      equ 0001h
CLCnGLS3_G4D1T_POSITION                  equ 0001h
CLCnGLS3_G4D1T_SIZE                      equ 0001h
CLCnGLS3_G4D1T_LENGTH                    equ 0001h
CLCnGLS3_G4D1T_MASK                      equ 0002h
CLCnGLS3_G4D2N_POSN                      equ 0002h
CLCnGLS3_G4D2N_POSITION                  equ 0002h
CLCnGLS3_G4D2N_SIZE                      equ 0001h
CLCnGLS3_G4D2N_LENGTH                    equ 0001h
CLCnGLS3_G4D2N_MASK                      equ 0004h
CLCnGLS3_G4D2T_POSN                      equ 0003h
CLCnGLS3_G4D2T_POSITION                  equ 0003h
CLCnGLS3_G4D2T_SIZE                      equ 0001h
CLCnGLS3_G4D2T_LENGTH                    equ 0001h
CLCnGLS3_G4D2T_MASK                      equ 0008h
CLCnGLS3_G4D3N_POSN                      equ 0004h
CLCnGLS3_G4D3N_POSITION                  equ 0004h
CLCnGLS3_G4D3N_SIZE                      equ 0001h
CLCnGLS3_G4D3N_LENGTH                    equ 0001h
CLCnGLS3_G4D3N_MASK                      equ 0010h
CLCnGLS3_G4D3T_POSN                      equ 0005h
CLCnGLS3_G4D3T_POSITION                  equ 0005h
CLCnGLS3_G4D3T_SIZE                      equ 0001h
CLCnGLS3_G4D3T_LENGTH                    equ 0001h
CLCnGLS3_G4D3T_MASK                      equ 0020h
CLCnGLS3_G4D4N_POSN                      equ 0006h
CLCnGLS3_G4D4N_POSITION                  equ 0006h
CLCnGLS3_G4D4N_SIZE                      equ 0001h
CLCnGLS3_G4D4N_LENGTH                    equ 0001h
CLCnGLS3_G4D4N_MASK                      equ 0040h
CLCnGLS3_G4D4T_POSN                      equ 0007h
CLCnGLS3_G4D4T_POSITION                  equ 0007h
CLCnGLS3_G4D4T_SIZE                      equ 0001h
CLCnGLS3_G4D4T_LENGTH                    equ 0001h
CLCnGLS3_G4D4T_MASK                      equ 0080h

// Register: CLCSELECT
#define CLCSELECT CLCSELECT
CLCSELECT                                equ 0696h
// bitfield definitions
CLCSELECT_SLCT_POSN                      equ 0000h
CLCSELECT_SLCT_POSITION                  equ 0000h
CLCSELECT_SLCT_SIZE                      equ 0008h
CLCSELECT_SLCT_LENGTH                    equ 0008h
CLCSELECT_SLCT_MASK                      equ 00FFh
CLCSELECT_SLCT0_POSN                     equ 0000h
CLCSELECT_SLCT0_POSITION                 equ 0000h
CLCSELECT_SLCT0_SIZE                     equ 0001h
CLCSELECT_SLCT0_LENGTH                   equ 0001h
CLCSELECT_SLCT0_MASK                     equ 0001h
CLCSELECT_SLCT1_POSN                     equ 0001h
CLCSELECT_SLCT1_POSITION                 equ 0001h
CLCSELECT_SLCT1_SIZE                     equ 0001h
CLCSELECT_SLCT1_LENGTH                   equ 0001h
CLCSELECT_SLCT1_MASK                     equ 0002h

// Register: CLCDATA
#define CLCDATA CLCDATA
CLCDATA                                  equ 0697h
// bitfield definitions
CLCDATA_CLC1OUT_POSN                     equ 0000h
CLCDATA_CLC1OUT_POSITION                 equ 0000h
CLCDATA_CLC1OUT_SIZE                     equ 0001h
CLCDATA_CLC1OUT_LENGTH                   equ 0001h
CLCDATA_CLC1OUT_MASK                     equ 0001h
CLCDATA_CLC2OUT_POSN                     equ 0001h
CLCDATA_CLC2OUT_POSITION                 equ 0001h
CLCDATA_CLC2OUT_SIZE                     equ 0001h
CLCDATA_CLC2OUT_LENGTH                   equ 0001h
CLCDATA_CLC2OUT_MASK                     equ 0002h
CLCDATA_CLC3OUT_POSN                     equ 0002h
CLCDATA_CLC3OUT_POSITION                 equ 0002h
CLCDATA_CLC3OUT_SIZE                     equ 0001h
CLCDATA_CLC3OUT_LENGTH                   equ 0001h
CLCDATA_CLC3OUT_MASK                     equ 0004h
CLCDATA_CLC4OUT_POSN                     equ 0003h
CLCDATA_CLC4OUT_POSITION                 equ 0003h
CLCDATA_CLC4OUT_SIZE                     equ 0001h
CLCDATA_CLC4OUT_LENGTH                   equ 0001h
CLCDATA_CLC4OUT_MASK                     equ 0008h

// Register: RC1REG
#define RC1REG RC1REG
RC1REG                                   equ 070Ch
// bitfield definitions
RC1REG_RCREG_POSN                        equ 0000h
RC1REG_RCREG_POSITION                    equ 0000h
RC1REG_RCREG_SIZE                        equ 0008h
RC1REG_RCREG_LENGTH                      equ 0008h
RC1REG_RCREG_MASK                        equ 00FFh

// Register: TX1REG
#define TX1REG TX1REG
TX1REG                                   equ 070Dh
// bitfield definitions
TX1REG_TXREG_POSN                        equ 0000h
TX1REG_TXREG_POSITION                    equ 0000h
TX1REG_TXREG_SIZE                        equ 0008h
TX1REG_TXREG_LENGTH                      equ 0008h
TX1REG_TXREG_MASK                        equ 00FFh

// Register: SP1BRGL
#define SP1BRGL SP1BRGL
SP1BRGL                                  equ 070Eh
// bitfield definitions
SP1BRGL_SPBRGL_POSN                      equ 0000h
SP1BRGL_SPBRGL_POSITION                  equ 0000h
SP1BRGL_SPBRGL_SIZE                      equ 0008h
SP1BRGL_SPBRGL_LENGTH                    equ 0008h
SP1BRGL_SPBRGL_MASK                      equ 00FFh

// Register: SP1BRGH
#define SP1BRGH SP1BRGH
SP1BRGH                                  equ 070Fh
// bitfield definitions
SP1BRGH_SPBRGH_POSN                      equ 0000h
SP1BRGH_SPBRGH_POSITION                  equ 0000h
SP1BRGH_SPBRGH_SIZE                      equ 0008h
SP1BRGH_SPBRGH_LENGTH                    equ 0008h
SP1BRGH_SPBRGH_MASK                      equ 00FFh

// Register: RC1STA
#define RC1STA RC1STA
RC1STA                                   equ 0710h
// bitfield definitions
RC1STA_RX9D_POSN                         equ 0000h
RC1STA_RX9D_POSITION                     equ 0000h
RC1STA_RX9D_SIZE                         equ 0001h
RC1STA_RX9D_LENGTH                       equ 0001h
RC1STA_RX9D_MASK                         equ 0001h
RC1STA_OERR_POSN                         equ 0001h
RC1STA_OERR_POSITION                     equ 0001h
RC1STA_OERR_SIZE                         equ 0001h
RC1STA_OERR_LENGTH                       equ 0001h
RC1STA_OERR_MASK                         equ 0002h
RC1STA_FERR_POSN                         equ 0002h
RC1STA_FERR_POSITION                     equ 0002h
RC1STA_FERR_SIZE                         equ 0001h
RC1STA_FERR_LENGTH                       equ 0001h
RC1STA_FERR_MASK                         equ 0004h
RC1STA_ADDEN_POSN                        equ 0003h
RC1STA_ADDEN_POSITION                    equ 0003h
RC1STA_ADDEN_SIZE                        equ 0001h
RC1STA_ADDEN_LENGTH                      equ 0001h
RC1STA_ADDEN_MASK                        equ 0008h
RC1STA_CREN_POSN                         equ 0004h
RC1STA_CREN_POSITION                     equ 0004h
RC1STA_CREN_SIZE                         equ 0001h
RC1STA_CREN_LENGTH                       equ 0001h
RC1STA_CREN_MASK                         equ 0010h
RC1STA_SREN_POSN                         equ 0005h
RC1STA_SREN_POSITION                     equ 0005h
RC1STA_SREN_SIZE                         equ 0001h
RC1STA_SREN_LENGTH                       equ 0001h
RC1STA_SREN_MASK                         equ 0020h
RC1STA_RX9_POSN                          equ 0006h
RC1STA_RX9_POSITION                      equ 0006h
RC1STA_RX9_SIZE                          equ 0001h
RC1STA_RX9_LENGTH                        equ 0001h
RC1STA_RX9_MASK                          equ 0040h
RC1STA_SPEN_POSN                         equ 0007h
RC1STA_SPEN_POSITION                     equ 0007h
RC1STA_SPEN_SIZE                         equ 0001h
RC1STA_SPEN_LENGTH                       equ 0001h
RC1STA_SPEN_MASK                         equ 0080h

// Register: TX1STA
#define TX1STA TX1STA
TX1STA                                   equ 0711h
// bitfield definitions
TX1STA_TX9D_POSN                         equ 0000h
TX1STA_TX9D_POSITION                     equ 0000h
TX1STA_TX9D_SIZE                         equ 0001h
TX1STA_TX9D_LENGTH                       equ 0001h
TX1STA_TX9D_MASK                         equ 0001h
TX1STA_TRMT_POSN                         equ 0001h
TX1STA_TRMT_POSITION                     equ 0001h
TX1STA_TRMT_SIZE                         equ 0001h
TX1STA_TRMT_LENGTH                       equ 0001h
TX1STA_TRMT_MASK                         equ 0002h
TX1STA_BRGH_POSN                         equ 0002h
TX1STA_BRGH_POSITION                     equ 0002h
TX1STA_BRGH_SIZE                         equ 0001h
TX1STA_BRGH_LENGTH                       equ 0001h
TX1STA_BRGH_MASK                         equ 0004h
TX1STA_SENDB_POSN                        equ 0003h
TX1STA_SENDB_POSITION                    equ 0003h
TX1STA_SENDB_SIZE                        equ 0001h
TX1STA_SENDB_LENGTH                      equ 0001h
TX1STA_SENDB_MASK                        equ 0008h
TX1STA_SYNC_POSN                         equ 0004h
TX1STA_SYNC_POSITION                     equ 0004h
TX1STA_SYNC_SIZE                         equ 0001h
TX1STA_SYNC_LENGTH                       equ 0001h
TX1STA_SYNC_MASK                         equ 0010h
TX1STA_TXEN_POSN                         equ 0005h
TX1STA_TXEN_POSITION                     equ 0005h
TX1STA_TXEN_SIZE                         equ 0001h
TX1STA_TXEN_LENGTH                       equ 0001h
TX1STA_TXEN_MASK                         equ 0020h
TX1STA_TX9_POSN                          equ 0006h
TX1STA_TX9_POSITION                      equ 0006h
TX1STA_TX9_SIZE                          equ 0001h
TX1STA_TX9_LENGTH                        equ 0001h
TX1STA_TX9_MASK                          equ 0040h
TX1STA_CSRC_POSN                         equ 0007h
TX1STA_CSRC_POSITION                     equ 0007h
TX1STA_CSRC_SIZE                         equ 0001h
TX1STA_CSRC_LENGTH                       equ 0001h
TX1STA_CSRC_MASK                         equ 0080h

// Register: BAUD1CON
#define BAUD1CON BAUD1CON
BAUD1CON                                 equ 0712h
// bitfield definitions
BAUD1CON_ABDEN_POSN                      equ 0000h
BAUD1CON_ABDEN_POSITION                  equ 0000h
BAUD1CON_ABDEN_SIZE                      equ 0001h
BAUD1CON_ABDEN_LENGTH                    equ 0001h
BAUD1CON_ABDEN_MASK                      equ 0001h
BAUD1CON_WUE_POSN                        equ 0001h
BAUD1CON_WUE_POSITION                    equ 0001h
BAUD1CON_WUE_SIZE                        equ 0001h
BAUD1CON_WUE_LENGTH                      equ 0001h
BAUD1CON_WUE_MASK                        equ 0002h
BAUD1CON_BRG16_POSN                      equ 0003h
BAUD1CON_BRG16_POSITION                  equ 0003h
BAUD1CON_BRG16_SIZE                      equ 0001h
BAUD1CON_BRG16_LENGTH                    equ 0001h
BAUD1CON_BRG16_MASK                      equ 0008h
BAUD1CON_SCKP_POSN                       equ 0004h
BAUD1CON_SCKP_POSITION                   equ 0004h
BAUD1CON_SCKP_SIZE                       equ 0001h
BAUD1CON_SCKP_LENGTH                     equ 0001h
BAUD1CON_SCKP_MASK                       equ 0010h
BAUD1CON_RCIDL_POSN                      equ 0006h
BAUD1CON_RCIDL_POSITION                  equ 0006h
BAUD1CON_RCIDL_SIZE                      equ 0001h
BAUD1CON_RCIDL_LENGTH                    equ 0001h
BAUD1CON_RCIDL_MASK                      equ 0040h
BAUD1CON_ABDOVF_POSN                     equ 0007h
BAUD1CON_ABDOVF_POSITION                 equ 0007h
BAUD1CON_ABDOVF_SIZE                     equ 0001h
BAUD1CON_ABDOVF_LENGTH                   equ 0001h
BAUD1CON_ABDOVF_MASK                     equ 0080h

// Register: SSP1BUF
#define SSP1BUF SSP1BUF
SSP1BUF                                  equ 078Ch
// bitfield definitions
SSP1BUF_SSPBUF_POSN                      equ 0000h
SSP1BUF_SSPBUF_POSITION                  equ 0000h
SSP1BUF_SSPBUF_SIZE                      equ 0008h
SSP1BUF_SSPBUF_LENGTH                    equ 0008h
SSP1BUF_SSPBUF_MASK                      equ 00FFh

// Register: SSP1ADD
#define SSP1ADD SSP1ADD
SSP1ADD                                  equ 078Dh
// bitfield definitions
SSP1ADD_SSPADD_POSN                      equ 0000h
SSP1ADD_SSPADD_POSITION                  equ 0000h
SSP1ADD_SSPADD_SIZE                      equ 0008h
SSP1ADD_SSPADD_LENGTH                    equ 0008h
SSP1ADD_SSPADD_MASK                      equ 00FFh
SSP1ADD_MSK0_POSN                        equ 0000h
SSP1ADD_MSK0_POSITION                    equ 0000h
SSP1ADD_MSK0_SIZE                        equ 0001h
SSP1ADD_MSK0_LENGTH                      equ 0001h
SSP1ADD_MSK0_MASK                        equ 0001h
SSP1ADD_MSK1_POSN                        equ 0001h
SSP1ADD_MSK1_POSITION                    equ 0001h
SSP1ADD_MSK1_SIZE                        equ 0001h
SSP1ADD_MSK1_LENGTH                      equ 0001h
SSP1ADD_MSK1_MASK                        equ 0002h
SSP1ADD_MSK2_POSN                        equ 0002h
SSP1ADD_MSK2_POSITION                    equ 0002h
SSP1ADD_MSK2_SIZE                        equ 0001h
SSP1ADD_MSK2_LENGTH                      equ 0001h
SSP1ADD_MSK2_MASK                        equ 0004h
SSP1ADD_MSK3_POSN                        equ 0003h
SSP1ADD_MSK3_POSITION                    equ 0003h
SSP1ADD_MSK3_SIZE                        equ 0001h
SSP1ADD_MSK3_LENGTH                      equ 0001h
SSP1ADD_MSK3_MASK                        equ 0008h
SSP1ADD_MSK4_POSN                        equ 0004h
SSP1ADD_MSK4_POSITION                    equ 0004h
SSP1ADD_MSK4_SIZE                        equ 0001h
SSP1ADD_MSK4_LENGTH                      equ 0001h
SSP1ADD_MSK4_MASK                        equ 0010h
SSP1ADD_MSK5_POSN                        equ 0005h
SSP1ADD_MSK5_POSITION                    equ 0005h
SSP1ADD_MSK5_SIZE                        equ 0001h
SSP1ADD_MSK5_LENGTH                      equ 0001h
SSP1ADD_MSK5_MASK                        equ 0020h
SSP1ADD_MSK6_POSN                        equ 0006h
SSP1ADD_MSK6_POSITION                    equ 0006h
SSP1ADD_MSK6_SIZE                        equ 0001h
SSP1ADD_MSK6_LENGTH                      equ 0001h
SSP1ADD_MSK6_MASK                        equ 0040h
SSP1ADD_MSK7_POSN                        equ 0007h
SSP1ADD_MSK7_POSITION                    equ 0007h
SSP1ADD_MSK7_SIZE                        equ 0001h
SSP1ADD_MSK7_LENGTH                      equ 0001h
SSP1ADD_MSK7_MASK                        equ 0080h
SSP1ADD_MSK01_POSN                       equ 0000h
SSP1ADD_MSK01_POSITION                   equ 0000h
SSP1ADD_MSK01_SIZE                       equ 0001h
SSP1ADD_MSK01_LENGTH                     equ 0001h
SSP1ADD_MSK01_MASK                       equ 0001h
SSP1ADD_MSK11_POSN                       equ 0001h
SSP1ADD_MSK11_POSITION                   equ 0001h
SSP1ADD_MSK11_SIZE                       equ 0001h
SSP1ADD_MSK11_LENGTH                     equ 0001h
SSP1ADD_MSK11_MASK                       equ 0002h
SSP1ADD_MSK21_POSN                       equ 0002h
SSP1ADD_MSK21_POSITION                   equ 0002h
SSP1ADD_MSK21_SIZE                       equ 0001h
SSP1ADD_MSK21_LENGTH                     equ 0001h
SSP1ADD_MSK21_MASK                       equ 0004h
SSP1ADD_MSK31_POSN                       equ 0003h
SSP1ADD_MSK31_POSITION                   equ 0003h
SSP1ADD_MSK31_SIZE                       equ 0001h
SSP1ADD_MSK31_LENGTH                     equ 0001h
SSP1ADD_MSK31_MASK                       equ 0008h
SSP1ADD_MSK41_POSN                       equ 0004h
SSP1ADD_MSK41_POSITION                   equ 0004h
SSP1ADD_MSK41_SIZE                       equ 0001h
SSP1ADD_MSK41_LENGTH                     equ 0001h
SSP1ADD_MSK41_MASK                       equ 0010h
SSP1ADD_MSK51_POSN                       equ 0005h
SSP1ADD_MSK51_POSITION                   equ 0005h
SSP1ADD_MSK51_SIZE                       equ 0001h
SSP1ADD_MSK51_LENGTH                     equ 0001h
SSP1ADD_MSK51_MASK                       equ 0020h
SSP1ADD_MSK61_POSN                       equ 0006h
SSP1ADD_MSK61_POSITION                   equ 0006h
SSP1ADD_MSK61_SIZE                       equ 0001h
SSP1ADD_MSK61_LENGTH                     equ 0001h
SSP1ADD_MSK61_MASK                       equ 0040h
SSP1ADD_MSK71_POSN                       equ 0007h
SSP1ADD_MSK71_POSITION                   equ 0007h
SSP1ADD_MSK71_SIZE                       equ 0001h
SSP1ADD_MSK71_LENGTH                     equ 0001h
SSP1ADD_MSK71_MASK                       equ 0080h

// Register: SSP1MSK
#define SSP1MSK SSP1MSK
SSP1MSK                                  equ 078Eh
// bitfield definitions
SSP1MSK_SSPMSK_POSN                      equ 0000h
SSP1MSK_SSPMSK_POSITION                  equ 0000h
SSP1MSK_SSPMSK_SIZE                      equ 0008h
SSP1MSK_SSPMSK_LENGTH                    equ 0008h
SSP1MSK_SSPMSK_MASK                      equ 00FFh
SSP1MSK_MSK0_POSN                        equ 0000h
SSP1MSK_MSK0_POSITION                    equ 0000h
SSP1MSK_MSK0_SIZE                        equ 0001h
SSP1MSK_MSK0_LENGTH                      equ 0001h
SSP1MSK_MSK0_MASK                        equ 0001h
SSP1MSK_MSK1_POSN                        equ 0001h
SSP1MSK_MSK1_POSITION                    equ 0001h
SSP1MSK_MSK1_SIZE                        equ 0001h
SSP1MSK_MSK1_LENGTH                      equ 0001h
SSP1MSK_MSK1_MASK                        equ 0002h
SSP1MSK_MSK2_POSN                        equ 0002h
SSP1MSK_MSK2_POSITION                    equ 0002h
SSP1MSK_MSK2_SIZE                        equ 0001h
SSP1MSK_MSK2_LENGTH                      equ 0001h
SSP1MSK_MSK2_MASK                        equ 0004h
SSP1MSK_MSK3_POSN                        equ 0003h
SSP1MSK_MSK3_POSITION                    equ 0003h
SSP1MSK_MSK3_SIZE                        equ 0001h
SSP1MSK_MSK3_LENGTH                      equ 0001h
SSP1MSK_MSK3_MASK                        equ 0008h
SSP1MSK_MSK4_POSN                        equ 0004h
SSP1MSK_MSK4_POSITION                    equ 0004h
SSP1MSK_MSK4_SIZE                        equ 0001h
SSP1MSK_MSK4_LENGTH                      equ 0001h
SSP1MSK_MSK4_MASK                        equ 0010h
SSP1MSK_MSK5_POSN                        equ 0005h
SSP1MSK_MSK5_POSITION                    equ 0005h
SSP1MSK_MSK5_SIZE                        equ 0001h
SSP1MSK_MSK5_LENGTH                      equ 0001h
SSP1MSK_MSK5_MASK                        equ 0020h
SSP1MSK_MSK6_POSN                        equ 0006h
SSP1MSK_MSK6_POSITION                    equ 0006h
SSP1MSK_MSK6_SIZE                        equ 0001h
SSP1MSK_MSK6_LENGTH                      equ 0001h
SSP1MSK_MSK6_MASK                        equ 0040h
SSP1MSK_MSK7_POSN                        equ 0007h
SSP1MSK_MSK7_POSITION                    equ 0007h
SSP1MSK_MSK7_SIZE                        equ 0001h
SSP1MSK_MSK7_LENGTH                      equ 0001h
SSP1MSK_MSK7_MASK                        equ 0080h

// Register: SSP1STAT
#define SSP1STAT SSP1STAT
SSP1STAT                                 equ 078Fh
// bitfield definitions
SSP1STAT_BF_POSN                         equ 0000h
SSP1STAT_BF_POSITION                     equ 0000h
SSP1STAT_BF_SIZE                         equ 0001h
SSP1STAT_BF_LENGTH                       equ 0001h
SSP1STAT_BF_MASK                         equ 0001h
SSP1STAT_UA_POSN                         equ 0001h
SSP1STAT_UA_POSITION                     equ 0001h
SSP1STAT_UA_SIZE                         equ 0001h
SSP1STAT_UA_LENGTH                       equ 0001h
SSP1STAT_UA_MASK                         equ 0002h
SSP1STAT_R_nW_POSN                       equ 0002h
SSP1STAT_R_nW_POSITION                   equ 0002h
SSP1STAT_R_nW_SIZE                       equ 0001h
SSP1STAT_R_nW_LENGTH                     equ 0001h
SSP1STAT_R_nW_MASK                       equ 0004h
SSP1STAT_S_POSN                          equ 0003h
SSP1STAT_S_POSITION                      equ 0003h
SSP1STAT_S_SIZE                          equ 0001h
SSP1STAT_S_LENGTH                        equ 0001h
SSP1STAT_S_MASK                          equ 0008h
SSP1STAT_P_POSN                          equ 0004h
SSP1STAT_P_POSITION                      equ 0004h
SSP1STAT_P_SIZE                          equ 0001h
SSP1STAT_P_LENGTH                        equ 0001h
SSP1STAT_P_MASK                          equ 0010h
SSP1STAT_D_nA_POSN                       equ 0005h
SSP1STAT_D_nA_POSITION                   equ 0005h
SSP1STAT_D_nA_SIZE                       equ 0001h
SSP1STAT_D_nA_LENGTH                     equ 0001h
SSP1STAT_D_nA_MASK                       equ 0020h
SSP1STAT_CKE_POSN                        equ 0006h
SSP1STAT_CKE_POSITION                    equ 0006h
SSP1STAT_CKE_SIZE                        equ 0001h
SSP1STAT_CKE_LENGTH                      equ 0001h
SSP1STAT_CKE_MASK                        equ 0040h
SSP1STAT_SMP_POSN                        equ 0007h
SSP1STAT_SMP_POSITION                    equ 0007h
SSP1STAT_SMP_SIZE                        equ 0001h
SSP1STAT_SMP_LENGTH                      equ 0001h
SSP1STAT_SMP_MASK                        equ 0080h
SSP1STAT_R_W_POSN                        equ 0002h
SSP1STAT_R_W_POSITION                    equ 0002h
SSP1STAT_R_W_SIZE                        equ 0001h
SSP1STAT_R_W_LENGTH                      equ 0001h
SSP1STAT_R_W_MASK                        equ 0004h
SSP1STAT_D_A_POSN                        equ 0005h
SSP1STAT_D_A_POSITION                    equ 0005h
SSP1STAT_D_A_SIZE                        equ 0001h
SSP1STAT_D_A_LENGTH                      equ 0001h
SSP1STAT_D_A_MASK                        equ 0020h
SSP1STAT_nW_POSN                         equ 0002h
SSP1STAT_nW_POSITION                     equ 0002h
SSP1STAT_nW_SIZE                         equ 0001h
SSP1STAT_nW_LENGTH                       equ 0001h
SSP1STAT_nW_MASK                         equ 0004h
SSP1STAT_nA_POSN                         equ 0005h
SSP1STAT_nA_POSITION                     equ 0005h
SSP1STAT_nA_SIZE                         equ 0001h
SSP1STAT_nA_LENGTH                       equ 0001h
SSP1STAT_nA_MASK                         equ 0020h
SSP1STAT_nWRITE_POSN                     equ 0002h
SSP1STAT_nWRITE_POSITION                 equ 0002h
SSP1STAT_nWRITE_SIZE                     equ 0001h
SSP1STAT_nWRITE_LENGTH                   equ 0001h
SSP1STAT_nWRITE_MASK                     equ 0004h
SSP1STAT_nADDRESS_POSN                   equ 0005h
SSP1STAT_nADDRESS_POSITION               equ 0005h
SSP1STAT_nADDRESS_SIZE                   equ 0001h
SSP1STAT_nADDRESS_LENGTH                 equ 0001h
SSP1STAT_nADDRESS_MASK                   equ 0020h
SSP1STAT_READ_WRITE_POSN                 equ 0002h
SSP1STAT_READ_WRITE_POSITION             equ 0002h
SSP1STAT_READ_WRITE_SIZE                 equ 0001h
SSP1STAT_READ_WRITE_LENGTH               equ 0001h
SSP1STAT_READ_WRITE_MASK                 equ 0004h
SSP1STAT_DATA_ADDRESS_POSN               equ 0005h
SSP1STAT_DATA_ADDRESS_POSITION           equ 0005h
SSP1STAT_DATA_ADDRESS_SIZE               equ 0001h
SSP1STAT_DATA_ADDRESS_LENGTH             equ 0001h
SSP1STAT_DATA_ADDRESS_MASK               equ 0020h
SSP1STAT_I2C_READ_POSN                   equ 0002h
SSP1STAT_I2C_READ_POSITION               equ 0002h
SSP1STAT_I2C_READ_SIZE                   equ 0001h
SSP1STAT_I2C_READ_LENGTH                 equ 0001h
SSP1STAT_I2C_READ_MASK                   equ 0004h
SSP1STAT_I2C_START_POSN                  equ 0003h
SSP1STAT_I2C_START_POSITION              equ 0003h
SSP1STAT_I2C_START_SIZE                  equ 0001h
SSP1STAT_I2C_START_LENGTH                equ 0001h
SSP1STAT_I2C_START_MASK                  equ 0008h
SSP1STAT_I2C_STOP_POSN                   equ 0004h
SSP1STAT_I2C_STOP_POSITION               equ 0004h
SSP1STAT_I2C_STOP_SIZE                   equ 0001h
SSP1STAT_I2C_STOP_LENGTH                 equ 0001h
SSP1STAT_I2C_STOP_MASK                   equ 0010h
SSP1STAT_I2C_DAT_POSN                    equ 0005h
SSP1STAT_I2C_DAT_POSITION                equ 0005h
SSP1STAT_I2C_DAT_SIZE                    equ 0001h
SSP1STAT_I2C_DAT_LENGTH                  equ 0001h
SSP1STAT_I2C_DAT_MASK                    equ 0020h
SSP1STAT_BF1_POSN                        equ 0000h
SSP1STAT_BF1_POSITION                    equ 0000h
SSP1STAT_BF1_SIZE                        equ 0001h
SSP1STAT_BF1_LENGTH                      equ 0001h
SSP1STAT_BF1_MASK                        equ 0001h
SSP1STAT_UA1_POSN                        equ 0001h
SSP1STAT_UA1_POSITION                    equ 0001h
SSP1STAT_UA1_SIZE                        equ 0001h
SSP1STAT_UA1_LENGTH                      equ 0001h
SSP1STAT_UA1_MASK                        equ 0002h
SSP1STAT_R_POSN                          equ 0002h
SSP1STAT_R_POSITION                      equ 0002h
SSP1STAT_R_SIZE                          equ 0001h
SSP1STAT_R_LENGTH                        equ 0001h
SSP1STAT_R_MASK                          equ 0004h
SSP1STAT_START_POSN                      equ 0003h
SSP1STAT_START_POSITION                  equ 0003h
SSP1STAT_START_SIZE                      equ 0001h
SSP1STAT_START_LENGTH                    equ 0001h
SSP1STAT_START_MASK                      equ 0008h
SSP1STAT_STOP_POSN                       equ 0004h
SSP1STAT_STOP_POSITION                   equ 0004h
SSP1STAT_STOP_SIZE                       equ 0001h
SSP1STAT_STOP_LENGTH                     equ 0001h
SSP1STAT_STOP_MASK                       equ 0010h
SSP1STAT_D_POSN                          equ 0005h
SSP1STAT_D_POSITION                      equ 0005h
SSP1STAT_D_SIZE                          equ 0001h
SSP1STAT_D_LENGTH                        equ 0001h
SSP1STAT_D_MASK                          equ 0020h
SSP1STAT_CKE1_POSN                       equ 0006h
SSP1STAT_CKE1_POSITION                   equ 0006h
SSP1STAT_CKE1_SIZE                       equ 0001h
SSP1STAT_CKE1_LENGTH                     equ 0001h
SSP1STAT_CKE1_MASK                       equ 0040h
SSP1STAT_SMP1_POSN                       equ 0007h
SSP1STAT_SMP1_POSITION                   equ 0007h
SSP1STAT_SMP1_SIZE                       equ 0001h
SSP1STAT_SMP1_LENGTH                     equ 0001h
SSP1STAT_SMP1_MASK                       equ 0080h
SSP1STAT_RW_POSN                         equ 0002h
SSP1STAT_RW_POSITION                     equ 0002h
SSP1STAT_RW_SIZE                         equ 0001h
SSP1STAT_RW_LENGTH                       equ 0001h
SSP1STAT_RW_MASK                         equ 0004h
SSP1STAT_START1_POSN                     equ 0003h
SSP1STAT_START1_POSITION                 equ 0003h
SSP1STAT_START1_SIZE                     equ 0001h
SSP1STAT_START1_LENGTH                   equ 0001h
SSP1STAT_START1_MASK                     equ 0008h
SSP1STAT_STOP1_POSN                      equ 0004h
SSP1STAT_STOP1_POSITION                  equ 0004h
SSP1STAT_STOP1_SIZE                      equ 0001h
SSP1STAT_STOP1_LENGTH                    equ 0001h
SSP1STAT_STOP1_MASK                      equ 0010h
SSP1STAT_DA_POSN                         equ 0005h
SSP1STAT_DA_POSITION                     equ 0005h
SSP1STAT_DA_SIZE                         equ 0001h
SSP1STAT_DA_LENGTH                       equ 0001h
SSP1STAT_DA_MASK                         equ 0020h
SSP1STAT_RW1_POSN                        equ 0002h
SSP1STAT_RW1_POSITION                    equ 0002h
SSP1STAT_RW1_SIZE                        equ 0001h
SSP1STAT_RW1_LENGTH                      equ 0001h
SSP1STAT_RW1_MASK                        equ 0004h
SSP1STAT_I2C_START1_POSN                 equ 0003h
SSP1STAT_I2C_START1_POSITION             equ 0003h
SSP1STAT_I2C_START1_SIZE                 equ 0001h
SSP1STAT_I2C_START1_LENGTH               equ 0001h
SSP1STAT_I2C_START1_MASK                 equ 0008h
SSP1STAT_I2C_STOP2_POSN                  equ 0004h
SSP1STAT_I2C_STOP2_POSITION              equ 0004h
SSP1STAT_I2C_STOP2_SIZE                  equ 0001h
SSP1STAT_I2C_STOP2_LENGTH                equ 0001h
SSP1STAT_I2C_STOP2_MASK                  equ 0010h
SSP1STAT_DA1_POSN                        equ 0005h
SSP1STAT_DA1_POSITION                    equ 0005h
SSP1STAT_DA1_SIZE                        equ 0001h
SSP1STAT_DA1_LENGTH                      equ 0001h
SSP1STAT_DA1_MASK                        equ 0020h
SSP1STAT_I2C_READ1_POSN                  equ 0002h
SSP1STAT_I2C_READ1_POSITION              equ 0002h
SSP1STAT_I2C_READ1_SIZE                  equ 0001h
SSP1STAT_I2C_READ1_LENGTH                equ 0001h
SSP1STAT_I2C_READ1_MASK                  equ 0004h
SSP1STAT_S2_POSN                         equ 0003h
SSP1STAT_S2_POSITION                     equ 0003h
SSP1STAT_S2_SIZE                         equ 0001h
SSP1STAT_S2_LENGTH                       equ 0001h
SSP1STAT_S2_MASK                         equ 0008h
SSP1STAT_P2_POSN                         equ 0004h
SSP1STAT_P2_POSITION                     equ 0004h
SSP1STAT_P2_SIZE                         equ 0001h
SSP1STAT_P2_LENGTH                       equ 0001h
SSP1STAT_P2_MASK                         equ 0010h
SSP1STAT_DATA_ADDRESS1_POSN              equ 0005h
SSP1STAT_DATA_ADDRESS1_POSITION          equ 0005h
SSP1STAT_DATA_ADDRESS1_SIZE              equ 0001h
SSP1STAT_DATA_ADDRESS1_LENGTH            equ 0001h
SSP1STAT_DATA_ADDRESS1_MASK              equ 0020h
SSP1STAT_READ_WRITE1_POSN                equ 0002h
SSP1STAT_READ_WRITE1_POSITION            equ 0002h
SSP1STAT_READ_WRITE1_SIZE                equ 0001h
SSP1STAT_READ_WRITE1_LENGTH              equ 0001h
SSP1STAT_READ_WRITE1_MASK                equ 0004h
SSP1STAT_D_A1_POSN                       equ 0005h
SSP1STAT_D_A1_POSITION                   equ 0005h
SSP1STAT_D_A1_SIZE                       equ 0001h
SSP1STAT_D_A1_LENGTH                     equ 0001h
SSP1STAT_D_A1_MASK                       equ 0020h
SSP1STAT_R_W1_POSN                       equ 0002h
SSP1STAT_R_W1_POSITION                   equ 0002h
SSP1STAT_R_W1_SIZE                       equ 0001h
SSP1STAT_R_W1_LENGTH                     equ 0001h
SSP1STAT_R_W1_MASK                       equ 0004h
SSP1STAT_D_nA1_POSN                      equ 0005h
SSP1STAT_D_nA1_POSITION                  equ 0005h
SSP1STAT_D_nA1_SIZE                      equ 0001h
SSP1STAT_D_nA1_LENGTH                    equ 0001h
SSP1STAT_D_nA1_MASK                      equ 0020h
SSP1STAT_R_nW1_POSN                      equ 0002h
SSP1STAT_R_nW1_POSITION                  equ 0002h
SSP1STAT_R_nW1_SIZE                      equ 0001h
SSP1STAT_R_nW1_LENGTH                    equ 0001h
SSP1STAT_R_nW1_MASK                      equ 0004h
SSP1STAT_I2C_DAT1_POSN                   equ 0005h
SSP1STAT_I2C_DAT1_POSITION               equ 0005h
SSP1STAT_I2C_DAT1_SIZE                   equ 0001h
SSP1STAT_I2C_DAT1_LENGTH                 equ 0001h
SSP1STAT_I2C_DAT1_MASK                   equ 0020h
SSP1STAT_nW2_POSN                        equ 0002h
SSP1STAT_nW2_POSITION                    equ 0002h
SSP1STAT_nW2_SIZE                        equ 0001h
SSP1STAT_nW2_LENGTH                      equ 0001h
SSP1STAT_nW2_MASK                        equ 0004h
SSP1STAT_nA2_POSN                        equ 0005h
SSP1STAT_nA2_POSITION                    equ 0005h
SSP1STAT_nA2_SIZE                        equ 0001h
SSP1STAT_nA2_LENGTH                      equ 0001h
SSP1STAT_nA2_MASK                        equ 0020h
SSP1STAT_nWRITE1_POSN                    equ 0002h
SSP1STAT_nWRITE1_POSITION                equ 0002h
SSP1STAT_nWRITE1_SIZE                    equ 0001h
SSP1STAT_nWRITE1_LENGTH                  equ 0001h
SSP1STAT_nWRITE1_MASK                    equ 0004h
SSP1STAT_nADDRESS1_POSN                  equ 0005h
SSP1STAT_nADDRESS1_POSITION              equ 0005h
SSP1STAT_nADDRESS1_SIZE                  equ 0001h
SSP1STAT_nADDRESS1_LENGTH                equ 0001h
SSP1STAT_nADDRESS1_MASK                  equ 0020h

// Register: SSP1CON1
#define SSP1CON1 SSP1CON1
SSP1CON1                                 equ 0790h
// bitfield definitions
SSP1CON1_SSPM_POSN                       equ 0000h
SSP1CON1_SSPM_POSITION                   equ 0000h
SSP1CON1_SSPM_SIZE                       equ 0004h
SSP1CON1_SSPM_LENGTH                     equ 0004h
SSP1CON1_SSPM_MASK                       equ 000Fh
SSP1CON1_CKP_POSN                        equ 0004h
SSP1CON1_CKP_POSITION                    equ 0004h
SSP1CON1_CKP_SIZE                        equ 0001h
SSP1CON1_CKP_LENGTH                      equ 0001h
SSP1CON1_CKP_MASK                        equ 0010h
SSP1CON1_SSPEN_POSN                      equ 0005h
SSP1CON1_SSPEN_POSITION                  equ 0005h
SSP1CON1_SSPEN_SIZE                      equ 0001h
SSP1CON1_SSPEN_LENGTH                    equ 0001h
SSP1CON1_SSPEN_MASK                      equ 0020h
SSP1CON1_SSPOV_POSN                      equ 0006h
SSP1CON1_SSPOV_POSITION                  equ 0006h
SSP1CON1_SSPOV_SIZE                      equ 0001h
SSP1CON1_SSPOV_LENGTH                    equ 0001h
SSP1CON1_SSPOV_MASK                      equ 0040h
SSP1CON1_WCOL_POSN                       equ 0007h
SSP1CON1_WCOL_POSITION                   equ 0007h
SSP1CON1_WCOL_SIZE                       equ 0001h
SSP1CON1_WCOL_LENGTH                     equ 0001h
SSP1CON1_WCOL_MASK                       equ 0080h
SSP1CON1_SSPM0_POSN                      equ 0000h
SSP1CON1_SSPM0_POSITION                  equ 0000h
SSP1CON1_SSPM0_SIZE                      equ 0001h
SSP1CON1_SSPM0_LENGTH                    equ 0001h
SSP1CON1_SSPM0_MASK                      equ 0001h
SSP1CON1_SSPM1_POSN                      equ 0001h
SSP1CON1_SSPM1_POSITION                  equ 0001h
SSP1CON1_SSPM1_SIZE                      equ 0001h
SSP1CON1_SSPM1_LENGTH                    equ 0001h
SSP1CON1_SSPM1_MASK                      equ 0002h
SSP1CON1_SSPM2_POSN                      equ 0002h
SSP1CON1_SSPM2_POSITION                  equ 0002h
SSP1CON1_SSPM2_SIZE                      equ 0001h
SSP1CON1_SSPM2_LENGTH                    equ 0001h
SSP1CON1_SSPM2_MASK                      equ 0004h
SSP1CON1_SSPM3_POSN                      equ 0003h
SSP1CON1_SSPM3_POSITION                  equ 0003h
SSP1CON1_SSPM3_SIZE                      equ 0001h
SSP1CON1_SSPM3_LENGTH                    equ 0001h
SSP1CON1_SSPM3_MASK                      equ 0008h
SSP1CON1_SSPM01_POSN                     equ 0000h
SSP1CON1_SSPM01_POSITION                 equ 0000h
SSP1CON1_SSPM01_SIZE                     equ 0001h
SSP1CON1_SSPM01_LENGTH                   equ 0001h
SSP1CON1_SSPM01_MASK                     equ 0001h
SSP1CON1_SSPM11_POSN                     equ 0001h
SSP1CON1_SSPM11_POSITION                 equ 0001h
SSP1CON1_SSPM11_SIZE                     equ 0001h
SSP1CON1_SSPM11_LENGTH                   equ 0001h
SSP1CON1_SSPM11_MASK                     equ 0002h
SSP1CON1_SSPM21_POSN                     equ 0002h
SSP1CON1_SSPM21_POSITION                 equ 0002h
SSP1CON1_SSPM21_SIZE                     equ 0001h
SSP1CON1_SSPM21_LENGTH                   equ 0001h
SSP1CON1_SSPM21_MASK                     equ 0004h
SSP1CON1_SSPM31_POSN                     equ 0003h
SSP1CON1_SSPM31_POSITION                 equ 0003h
SSP1CON1_SSPM31_SIZE                     equ 0001h
SSP1CON1_SSPM31_LENGTH                   equ 0001h
SSP1CON1_SSPM31_MASK                     equ 0008h
SSP1CON1_CKP1_POSN                       equ 0004h
SSP1CON1_CKP1_POSITION                   equ 0004h
SSP1CON1_CKP1_SIZE                       equ 0001h
SSP1CON1_CKP1_LENGTH                     equ 0001h
SSP1CON1_CKP1_MASK                       equ 0010h
SSP1CON1_SSPEN1_POSN                     equ 0005h
SSP1CON1_SSPEN1_POSITION                 equ 0005h
SSP1CON1_SSPEN1_SIZE                     equ 0001h
SSP1CON1_SSPEN1_LENGTH                   equ 0001h
SSP1CON1_SSPEN1_MASK                     equ 0020h
SSP1CON1_SSPOV1_POSN                     equ 0006h
SSP1CON1_SSPOV1_POSITION                 equ 0006h
SSP1CON1_SSPOV1_SIZE                     equ 0001h
SSP1CON1_SSPOV1_LENGTH                   equ 0001h
SSP1CON1_SSPOV1_MASK                     equ 0040h
SSP1CON1_WCOL1_POSN                      equ 0007h
SSP1CON1_WCOL1_POSITION                  equ 0007h
SSP1CON1_WCOL1_SIZE                      equ 0001h
SSP1CON1_WCOL1_LENGTH                    equ 0001h
SSP1CON1_WCOL1_MASK                      equ 0080h

// Register: SSP1CON2
#define SSP1CON2 SSP1CON2
SSP1CON2                                 equ 0791h
// bitfield definitions
SSP1CON2_SEN_POSN                        equ 0000h
SSP1CON2_SEN_POSITION                    equ 0000h
SSP1CON2_SEN_SIZE                        equ 0001h
SSP1CON2_SEN_LENGTH                      equ 0001h
SSP1CON2_SEN_MASK                        equ 0001h
SSP1CON2_RSEN_POSN                       equ 0001h
SSP1CON2_RSEN_POSITION                   equ 0001h
SSP1CON2_RSEN_SIZE                       equ 0001h
SSP1CON2_RSEN_LENGTH                     equ 0001h
SSP1CON2_RSEN_MASK                       equ 0002h
SSP1CON2_PEN_POSN                        equ 0002h
SSP1CON2_PEN_POSITION                    equ 0002h
SSP1CON2_PEN_SIZE                        equ 0001h
SSP1CON2_PEN_LENGTH                      equ 0001h
SSP1CON2_PEN_MASK                        equ 0004h
SSP1CON2_RCEN_POSN                       equ 0003h
SSP1CON2_RCEN_POSITION                   equ 0003h
SSP1CON2_RCEN_SIZE                       equ 0001h
SSP1CON2_RCEN_LENGTH                     equ 0001h
SSP1CON2_RCEN_MASK                       equ 0008h
SSP1CON2_ACKEN_POSN                      equ 0004h
SSP1CON2_ACKEN_POSITION                  equ 0004h
SSP1CON2_ACKEN_SIZE                      equ 0001h
SSP1CON2_ACKEN_LENGTH                    equ 0001h
SSP1CON2_ACKEN_MASK                      equ 0010h
SSP1CON2_ACKDT_POSN                      equ 0005h
SSP1CON2_ACKDT_POSITION                  equ 0005h
SSP1CON2_ACKDT_SIZE                      equ 0001h
SSP1CON2_ACKDT_LENGTH                    equ 0001h
SSP1CON2_ACKDT_MASK                      equ 0020h
SSP1CON2_ACKSTAT_POSN                    equ 0006h
SSP1CON2_ACKSTAT_POSITION                equ 0006h
SSP1CON2_ACKSTAT_SIZE                    equ 0001h
SSP1CON2_ACKSTAT_LENGTH                  equ 0001h
SSP1CON2_ACKSTAT_MASK                    equ 0040h
SSP1CON2_GCEN_POSN                       equ 0007h
SSP1CON2_GCEN_POSITION                   equ 0007h
SSP1CON2_GCEN_SIZE                       equ 0001h
SSP1CON2_GCEN_LENGTH                     equ 0001h
SSP1CON2_GCEN_MASK                       equ 0080h
SSP1CON2_ADMSK_POSN                      equ 0001h
SSP1CON2_ADMSK_POSITION                  equ 0001h
SSP1CON2_ADMSK_SIZE                      equ 0005h
SSP1CON2_ADMSK_LENGTH                    equ 0005h
SSP1CON2_ADMSK_MASK                      equ 003Eh
SSP1CON2_ADMSK1_POSN                     equ 0001h
SSP1CON2_ADMSK1_POSITION                 equ 0001h
SSP1CON2_ADMSK1_SIZE                     equ 0001h
SSP1CON2_ADMSK1_LENGTH                   equ 0001h
SSP1CON2_ADMSK1_MASK                     equ 0002h
SSP1CON2_ADMSK2_POSN                     equ 0002h
SSP1CON2_ADMSK2_POSITION                 equ 0002h
SSP1CON2_ADMSK2_SIZE                     equ 0001h
SSP1CON2_ADMSK2_LENGTH                   equ 0001h
SSP1CON2_ADMSK2_MASK                     equ 0004h
SSP1CON2_ADMSK3_POSN                     equ 0003h
SSP1CON2_ADMSK3_POSITION                 equ 0003h
SSP1CON2_ADMSK3_SIZE                     equ 0001h
SSP1CON2_ADMSK3_LENGTH                   equ 0001h
SSP1CON2_ADMSK3_MASK                     equ 0008h
SSP1CON2_ADMSK4_POSN                     equ 0004h
SSP1CON2_ADMSK4_POSITION                 equ 0004h
SSP1CON2_ADMSK4_SIZE                     equ 0001h
SSP1CON2_ADMSK4_LENGTH                   equ 0001h
SSP1CON2_ADMSK4_MASK                     equ 0010h
SSP1CON2_ADMSK5_POSN                     equ 0005h
SSP1CON2_ADMSK5_POSITION                 equ 0005h
SSP1CON2_ADMSK5_SIZE                     equ 0001h
SSP1CON2_ADMSK5_LENGTH                   equ 0001h
SSP1CON2_ADMSK5_MASK                     equ 0020h
SSP1CON2_SEN1_POSN                       equ 0000h
SSP1CON2_SEN1_POSITION                   equ 0000h
SSP1CON2_SEN1_SIZE                       equ 0001h
SSP1CON2_SEN1_LENGTH                     equ 0001h
SSP1CON2_SEN1_MASK                       equ 0001h
SSP1CON2_ADMSK11_POSN                    equ 0001h
SSP1CON2_ADMSK11_POSITION                equ 0001h
SSP1CON2_ADMSK11_SIZE                    equ 0001h
SSP1CON2_ADMSK11_LENGTH                  equ 0001h
SSP1CON2_ADMSK11_MASK                    equ 0002h
SSP1CON2_ADMSK21_POSN                    equ 0002h
SSP1CON2_ADMSK21_POSITION                equ 0002h
SSP1CON2_ADMSK21_SIZE                    equ 0001h
SSP1CON2_ADMSK21_LENGTH                  equ 0001h
SSP1CON2_ADMSK21_MASK                    equ 0004h
SSP1CON2_ADMSK31_POSN                    equ 0003h
SSP1CON2_ADMSK31_POSITION                equ 0003h
SSP1CON2_ADMSK31_SIZE                    equ 0001h
SSP1CON2_ADMSK31_LENGTH                  equ 0001h
SSP1CON2_ADMSK31_MASK                    equ 0008h
SSP1CON2_ACKEN1_POSN                     equ 0004h
SSP1CON2_ACKEN1_POSITION                 equ 0004h
SSP1CON2_ACKEN1_SIZE                     equ 0001h
SSP1CON2_ACKEN1_LENGTH                   equ 0001h
SSP1CON2_ACKEN1_MASK                     equ 0010h
SSP1CON2_ACKDT1_POSN                     equ 0005h
SSP1CON2_ACKDT1_POSITION                 equ 0005h
SSP1CON2_ACKDT1_SIZE                     equ 0001h
SSP1CON2_ACKDT1_LENGTH                   equ 0001h
SSP1CON2_ACKDT1_MASK                     equ 0020h
SSP1CON2_ACKSTAT1_POSN                   equ 0006h
SSP1CON2_ACKSTAT1_POSITION               equ 0006h
SSP1CON2_ACKSTAT1_SIZE                   equ 0001h
SSP1CON2_ACKSTAT1_LENGTH                 equ 0001h
SSP1CON2_ACKSTAT1_MASK                   equ 0040h
SSP1CON2_GCEN1_POSN                      equ 0007h
SSP1CON2_GCEN1_POSITION                  equ 0007h
SSP1CON2_GCEN1_SIZE                      equ 0001h
SSP1CON2_GCEN1_LENGTH                    equ 0001h
SSP1CON2_GCEN1_MASK                      equ 0080h
SSP1CON2_RSEN1_POSN                      equ 0001h
SSP1CON2_RSEN1_POSITION                  equ 0001h
SSP1CON2_RSEN1_SIZE                      equ 0001h
SSP1CON2_RSEN1_LENGTH                    equ 0001h
SSP1CON2_RSEN1_MASK                      equ 0002h
SSP1CON2_PEN1_POSN                       equ 0002h
SSP1CON2_PEN1_POSITION                   equ 0002h
SSP1CON2_PEN1_SIZE                       equ 0001h
SSP1CON2_PEN1_LENGTH                     equ 0001h
SSP1CON2_PEN1_MASK                       equ 0004h
SSP1CON2_RCEN1_POSN                      equ 0003h
SSP1CON2_RCEN1_POSITION                  equ 0003h
SSP1CON2_RCEN1_SIZE                      equ 0001h
SSP1CON2_RCEN1_LENGTH                    equ 0001h
SSP1CON2_RCEN1_MASK                      equ 0008h
SSP1CON2_ADMSK41_POSN                    equ 0004h
SSP1CON2_ADMSK41_POSITION                equ 0004h
SSP1CON2_ADMSK41_SIZE                    equ 0001h
SSP1CON2_ADMSK41_LENGTH                  equ 0001h
SSP1CON2_ADMSK41_MASK                    equ 0010h
SSP1CON2_ADMSK51_POSN                    equ 0005h
SSP1CON2_ADMSK51_POSITION                equ 0005h
SSP1CON2_ADMSK51_SIZE                    equ 0001h
SSP1CON2_ADMSK51_LENGTH                  equ 0001h
SSP1CON2_ADMSK51_MASK                    equ 0020h

// Register: SSP1CON3
#define SSP1CON3 SSP1CON3
SSP1CON3                                 equ 0792h
// bitfield definitions
SSP1CON3_DHEN_POSN                       equ 0000h
SSP1CON3_DHEN_POSITION                   equ 0000h
SSP1CON3_DHEN_SIZE                       equ 0001h
SSP1CON3_DHEN_LENGTH                     equ 0001h
SSP1CON3_DHEN_MASK                       equ 0001h
SSP1CON3_AHEN_POSN                       equ 0001h
SSP1CON3_AHEN_POSITION                   equ 0001h
SSP1CON3_AHEN_SIZE                       equ 0001h
SSP1CON3_AHEN_LENGTH                     equ 0001h
SSP1CON3_AHEN_MASK                       equ 0002h
SSP1CON3_SBCDE_POSN                      equ 0002h
SSP1CON3_SBCDE_POSITION                  equ 0002h
SSP1CON3_SBCDE_SIZE                      equ 0001h
SSP1CON3_SBCDE_LENGTH                    equ 0001h
SSP1CON3_SBCDE_MASK                      equ 0004h
SSP1CON3_SDAHT_POSN                      equ 0003h
SSP1CON3_SDAHT_POSITION                  equ 0003h
SSP1CON3_SDAHT_SIZE                      equ 0001h
SSP1CON3_SDAHT_LENGTH                    equ 0001h
SSP1CON3_SDAHT_MASK                      equ 0008h
SSP1CON3_BOEN_POSN                       equ 0004h
SSP1CON3_BOEN_POSITION                   equ 0004h
SSP1CON3_BOEN_SIZE                       equ 0001h
SSP1CON3_BOEN_LENGTH                     equ 0001h
SSP1CON3_BOEN_MASK                       equ 0010h
SSP1CON3_SCIE_POSN                       equ 0005h
SSP1CON3_SCIE_POSITION                   equ 0005h
SSP1CON3_SCIE_SIZE                       equ 0001h
SSP1CON3_SCIE_LENGTH                     equ 0001h
SSP1CON3_SCIE_MASK                       equ 0020h
SSP1CON3_PCIE_POSN                       equ 0006h
SSP1CON3_PCIE_POSITION                   equ 0006h
SSP1CON3_PCIE_SIZE                       equ 0001h
SSP1CON3_PCIE_LENGTH                     equ 0001h
SSP1CON3_PCIE_MASK                       equ 0040h
SSP1CON3_ACKTIM_POSN                     equ 0007h
SSP1CON3_ACKTIM_POSITION                 equ 0007h
SSP1CON3_ACKTIM_SIZE                     equ 0001h
SSP1CON3_ACKTIM_LENGTH                   equ 0001h
SSP1CON3_ACKTIM_MASK                     equ 0080h

// Register: CM1CON0
#define CM1CON0 CM1CON0
CM1CON0                                  equ 080Ch
// bitfield definitions
CM1CON0_SYNC_POSN                        equ 0000h
CM1CON0_SYNC_POSITION                    equ 0000h
CM1CON0_SYNC_SIZE                        equ 0001h
CM1CON0_SYNC_LENGTH                      equ 0001h
CM1CON0_SYNC_MASK                        equ 0001h
CM1CON0_HYS_POSN                         equ 0001h
CM1CON0_HYS_POSITION                     equ 0001h
CM1CON0_HYS_SIZE                         equ 0001h
CM1CON0_HYS_LENGTH                       equ 0001h
CM1CON0_HYS_MASK                         equ 0002h
CM1CON0_SP_POSN                          equ 0002h
CM1CON0_SP_POSITION                      equ 0002h
CM1CON0_SP_SIZE                          equ 0001h
CM1CON0_SP_LENGTH                        equ 0001h
CM1CON0_SP_MASK                          equ 0004h
CM1CON0_POL_POSN                         equ 0004h
CM1CON0_POL_POSITION                     equ 0004h
CM1CON0_POL_SIZE                         equ 0001h
CM1CON0_POL_LENGTH                       equ 0001h
CM1CON0_POL_MASK                         equ 0010h
CM1CON0_OUT_POSN                         equ 0006h
CM1CON0_OUT_POSITION                     equ 0006h
CM1CON0_OUT_SIZE                         equ 0001h
CM1CON0_OUT_LENGTH                       equ 0001h
CM1CON0_OUT_MASK                         equ 0040h
CM1CON0_EN_POSN                          equ 0007h
CM1CON0_EN_POSITION                      equ 0007h
CM1CON0_EN_SIZE                          equ 0001h
CM1CON0_EN_LENGTH                        equ 0001h
CM1CON0_EN_MASK                          equ 0080h
CM1CON0_C1SYNC_POSN                      equ 0000h
CM1CON0_C1SYNC_POSITION                  equ 0000h
CM1CON0_C1SYNC_SIZE                      equ 0001h
CM1CON0_C1SYNC_LENGTH                    equ 0001h
CM1CON0_C1SYNC_MASK                      equ 0001h
CM1CON0_C1HYS_POSN                       equ 0001h
CM1CON0_C1HYS_POSITION                   equ 0001h
CM1CON0_C1HYS_SIZE                       equ 0001h
CM1CON0_C1HYS_LENGTH                     equ 0001h
CM1CON0_C1HYS_MASK                       equ 0002h
CM1CON0_C1SP_POSN                        equ 0002h
CM1CON0_C1SP_POSITION                    equ 0002h
CM1CON0_C1SP_SIZE                        equ 0001h
CM1CON0_C1SP_LENGTH                      equ 0001h
CM1CON0_C1SP_MASK                        equ 0004h
CM1CON0_C1POL_POSN                       equ 0004h
CM1CON0_C1POL_POSITION                   equ 0004h
CM1CON0_C1POL_SIZE                       equ 0001h
CM1CON0_C1POL_LENGTH                     equ 0001h
CM1CON0_C1POL_MASK                       equ 0010h
CM1CON0_C1OUT_POSN                       equ 0006h
CM1CON0_C1OUT_POSITION                   equ 0006h
CM1CON0_C1OUT_SIZE                       equ 0001h
CM1CON0_C1OUT_LENGTH                     equ 0001h
CM1CON0_C1OUT_MASK                       equ 0040h
CM1CON0_C1EN_POSN                        equ 0007h
CM1CON0_C1EN_POSITION                    equ 0007h
CM1CON0_C1EN_SIZE                        equ 0001h
CM1CON0_C1EN_LENGTH                      equ 0001h
CM1CON0_C1EN_MASK                        equ 0080h

// Register: CM1CON1
#define CM1CON1 CM1CON1
CM1CON1                                  equ 080Dh
// bitfield definitions
CM1CON1_INTN_POSN                        equ 0000h
CM1CON1_INTN_POSITION                    equ 0000h
CM1CON1_INTN_SIZE                        equ 0001h
CM1CON1_INTN_LENGTH                      equ 0001h
CM1CON1_INTN_MASK                        equ 0001h
CM1CON1_INTP_POSN                        equ 0001h
CM1CON1_INTP_POSITION                    equ 0001h
CM1CON1_INTP_SIZE                        equ 0001h
CM1CON1_INTP_LENGTH                      equ 0001h
CM1CON1_INTP_MASK                        equ 0002h
CM1CON1_C1INTN_POSN                      equ 0000h
CM1CON1_C1INTN_POSITION                  equ 0000h
CM1CON1_C1INTN_SIZE                      equ 0001h
CM1CON1_C1INTN_LENGTH                    equ 0001h
CM1CON1_C1INTN_MASK                      equ 0001h
CM1CON1_C1INTP_POSN                      equ 0001h
CM1CON1_C1INTP_POSITION                  equ 0001h
CM1CON1_C1INTP_SIZE                      equ 0001h
CM1CON1_C1INTP_LENGTH                    equ 0001h
CM1CON1_C1INTP_MASK                      equ 0002h

// Register: CM1NCH
#define CM1NCH CM1NCH
CM1NCH                                   equ 080Eh
// bitfield definitions
CM1NCH_NCH_POSN                          equ 0000h
CM1NCH_NCH_POSITION                      equ 0000h
CM1NCH_NCH_SIZE                          equ 0003h
CM1NCH_NCH_LENGTH                        equ 0003h
CM1NCH_NCH_MASK                          equ 0007h
CM1NCH_NCH0_POSN                         equ 0000h
CM1NCH_NCH0_POSITION                     equ 0000h
CM1NCH_NCH0_SIZE                         equ 0001h
CM1NCH_NCH0_LENGTH                       equ 0001h
CM1NCH_NCH0_MASK                         equ 0001h
CM1NCH_NCH1_POSN                         equ 0001h
CM1NCH_NCH1_POSITION                     equ 0001h
CM1NCH_NCH1_SIZE                         equ 0001h
CM1NCH_NCH1_LENGTH                       equ 0001h
CM1NCH_NCH1_MASK                         equ 0002h
CM1NCH_NCH2_POSN                         equ 0002h
CM1NCH_NCH2_POSITION                     equ 0002h
CM1NCH_NCH2_SIZE                         equ 0001h
CM1NCH_NCH2_LENGTH                       equ 0001h
CM1NCH_NCH2_MASK                         equ 0004h
CM1NCH_C1NCH0_POSN                       equ 0000h
CM1NCH_C1NCH0_POSITION                   equ 0000h
CM1NCH_C1NCH0_SIZE                       equ 0001h
CM1NCH_C1NCH0_LENGTH                     equ 0001h
CM1NCH_C1NCH0_MASK                       equ 0001h
CM1NCH_C1NCH1_POSN                       equ 0001h
CM1NCH_C1NCH1_POSITION                   equ 0001h
CM1NCH_C1NCH1_SIZE                       equ 0001h
CM1NCH_C1NCH1_LENGTH                     equ 0001h
CM1NCH_C1NCH1_MASK                       equ 0002h
CM1NCH_C1NCH2_POSN                       equ 0002h
CM1NCH_C1NCH2_POSITION                   equ 0002h
CM1NCH_C1NCH2_SIZE                       equ 0001h
CM1NCH_C1NCH2_LENGTH                     equ 0001h
CM1NCH_C1NCH2_MASK                       equ 0004h

// Register: CM1PCH
#define CM1PCH CM1PCH
CM1PCH                                   equ 080Fh
// bitfield definitions
CM1PCH_PCH_POSN                          equ 0000h
CM1PCH_PCH_POSITION                      equ 0000h
CM1PCH_PCH_SIZE                          equ 0003h
CM1PCH_PCH_LENGTH                        equ 0003h
CM1PCH_PCH_MASK                          equ 0007h
CM1PCH_PCH0_POSN                         equ 0000h
CM1PCH_PCH0_POSITION                     equ 0000h
CM1PCH_PCH0_SIZE                         equ 0001h
CM1PCH_PCH0_LENGTH                       equ 0001h
CM1PCH_PCH0_MASK                         equ 0001h
CM1PCH_PCH1_POSN                         equ 0001h
CM1PCH_PCH1_POSITION                     equ 0001h
CM1PCH_PCH1_SIZE                         equ 0001h
CM1PCH_PCH1_LENGTH                       equ 0001h
CM1PCH_PCH1_MASK                         equ 0002h
CM1PCH_PCH2_POSN                         equ 0002h
CM1PCH_PCH2_POSITION                     equ 0002h
CM1PCH_PCH2_SIZE                         equ 0001h
CM1PCH_PCH2_LENGTH                       equ 0001h
CM1PCH_PCH2_MASK                         equ 0004h
CM1PCH_C1PCH0_POSN                       equ 0000h
CM1PCH_C1PCH0_POSITION                   equ 0000h
CM1PCH_C1PCH0_SIZE                       equ 0001h
CM1PCH_C1PCH0_LENGTH                     equ 0001h
CM1PCH_C1PCH0_MASK                       equ 0001h
CM1PCH_C1PCH1_POSN                       equ 0001h
CM1PCH_C1PCH1_POSITION                   equ 0001h
CM1PCH_C1PCH1_SIZE                       equ 0001h
CM1PCH_C1PCH1_LENGTH                     equ 0001h
CM1PCH_C1PCH1_MASK                       equ 0002h
CM1PCH_C1PCH2_POSN                       equ 0002h
CM1PCH_C1PCH2_POSITION                   equ 0002h
CM1PCH_C1PCH2_SIZE                       equ 0001h
CM1PCH_C1PCH2_LENGTH                     equ 0001h
CM1PCH_C1PCH2_MASK                       equ 0004h

// Register: CM2CON0
#define CM2CON0 CM2CON0
CM2CON0                                  equ 0810h
// bitfield definitions
CM2CON0_SYNC_POSN                        equ 0000h
CM2CON0_SYNC_POSITION                    equ 0000h
CM2CON0_SYNC_SIZE                        equ 0001h
CM2CON0_SYNC_LENGTH                      equ 0001h
CM2CON0_SYNC_MASK                        equ 0001h
CM2CON0_HYS_POSN                         equ 0001h
CM2CON0_HYS_POSITION                     equ 0001h
CM2CON0_HYS_SIZE                         equ 0001h
CM2CON0_HYS_LENGTH                       equ 0001h
CM2CON0_HYS_MASK                         equ 0002h
CM2CON0_SP_POSN                          equ 0002h
CM2CON0_SP_POSITION                      equ 0002h
CM2CON0_SP_SIZE                          equ 0001h
CM2CON0_SP_LENGTH                        equ 0001h
CM2CON0_SP_MASK                          equ 0004h
CM2CON0_POL_POSN                         equ 0004h
CM2CON0_POL_POSITION                     equ 0004h
CM2CON0_POL_SIZE                         equ 0001h
CM2CON0_POL_LENGTH                       equ 0001h
CM2CON0_POL_MASK                         equ 0010h
CM2CON0_OUT_POSN                         equ 0006h
CM2CON0_OUT_POSITION                     equ 0006h
CM2CON0_OUT_SIZE                         equ 0001h
CM2CON0_OUT_LENGTH                       equ 0001h
CM2CON0_OUT_MASK                         equ 0040h
CM2CON0_EN_POSN                          equ 0007h
CM2CON0_EN_POSITION                      equ 0007h
CM2CON0_EN_SIZE                          equ 0001h
CM2CON0_EN_LENGTH                        equ 0001h
CM2CON0_EN_MASK                          equ 0080h
CM2CON0_C2SYNC_POSN                      equ 0000h
CM2CON0_C2SYNC_POSITION                  equ 0000h
CM2CON0_C2SYNC_SIZE                      equ 0001h
CM2CON0_C2SYNC_LENGTH                    equ 0001h
CM2CON0_C2SYNC_MASK                      equ 0001h
CM2CON0_C2HYS_POSN                       equ 0001h
CM2CON0_C2HYS_POSITION                   equ 0001h
CM2CON0_C2HYS_SIZE                       equ 0001h
CM2CON0_C2HYS_LENGTH                     equ 0001h
CM2CON0_C2HYS_MASK                       equ 0002h
CM2CON0_C2SP_POSN                        equ 0002h
CM2CON0_C2SP_POSITION                    equ 0002h
CM2CON0_C2SP_SIZE                        equ 0001h
CM2CON0_C2SP_LENGTH                      equ 0001h
CM2CON0_C2SP_MASK                        equ 0004h
CM2CON0_C2POL_POSN                       equ 0004h
CM2CON0_C2POL_POSITION                   equ 0004h
CM2CON0_C2POL_SIZE                       equ 0001h
CM2CON0_C2POL_LENGTH                     equ 0001h
CM2CON0_C2POL_MASK                       equ 0010h
CM2CON0_C2OUT_POSN                       equ 0006h
CM2CON0_C2OUT_POSITION                   equ 0006h
CM2CON0_C2OUT_SIZE                       equ 0001h
CM2CON0_C2OUT_LENGTH                     equ 0001h
CM2CON0_C2OUT_MASK                       equ 0040h
CM2CON0_C2EN_POSN                        equ 0007h
CM2CON0_C2EN_POSITION                    equ 0007h
CM2CON0_C2EN_SIZE                        equ 0001h
CM2CON0_C2EN_LENGTH                      equ 0001h
CM2CON0_C2EN_MASK                        equ 0080h

// Register: CM2CON1
#define CM2CON1 CM2CON1
CM2CON1                                  equ 0811h
// bitfield definitions
CM2CON1_INTN_POSN                        equ 0000h
CM2CON1_INTN_POSITION                    equ 0000h
CM2CON1_INTN_SIZE                        equ 0001h
CM2CON1_INTN_LENGTH                      equ 0001h
CM2CON1_INTN_MASK                        equ 0001h
CM2CON1_INTP_POSN                        equ 0001h
CM2CON1_INTP_POSITION                    equ 0001h
CM2CON1_INTP_SIZE                        equ 0001h
CM2CON1_INTP_LENGTH                      equ 0001h
CM2CON1_INTP_MASK                        equ 0002h
CM2CON1_C2INTN_POSN                      equ 0000h
CM2CON1_C2INTN_POSITION                  equ 0000h
CM2CON1_C2INTN_SIZE                      equ 0001h
CM2CON1_C2INTN_LENGTH                    equ 0001h
CM2CON1_C2INTN_MASK                      equ 0001h
CM2CON1_C2INTP_POSN                      equ 0001h
CM2CON1_C2INTP_POSITION                  equ 0001h
CM2CON1_C2INTP_SIZE                      equ 0001h
CM2CON1_C2INTP_LENGTH                    equ 0001h
CM2CON1_C2INTP_MASK                      equ 0002h

// Register: CM2NCH
#define CM2NCH CM2NCH
CM2NCH                                   equ 0812h
// bitfield definitions
CM2NCH_NCH_POSN                          equ 0000h
CM2NCH_NCH_POSITION                      equ 0000h
CM2NCH_NCH_SIZE                          equ 0003h
CM2NCH_NCH_LENGTH                        equ 0003h
CM2NCH_NCH_MASK                          equ 0007h
CM2NCH_NCH0_POSN                         equ 0000h
CM2NCH_NCH0_POSITION                     equ 0000h
CM2NCH_NCH0_SIZE                         equ 0001h
CM2NCH_NCH0_LENGTH                       equ 0001h
CM2NCH_NCH0_MASK                         equ 0001h
CM2NCH_NCH1_POSN                         equ 0001h
CM2NCH_NCH1_POSITION                     equ 0001h
CM2NCH_NCH1_SIZE                         equ 0001h
CM2NCH_NCH1_LENGTH                       equ 0001h
CM2NCH_NCH1_MASK                         equ 0002h
CM2NCH_NCH2_POSN                         equ 0002h
CM2NCH_NCH2_POSITION                     equ 0002h
CM2NCH_NCH2_SIZE                         equ 0001h
CM2NCH_NCH2_LENGTH                       equ 0001h
CM2NCH_NCH2_MASK                         equ 0004h
CM2NCH_C2NCH0_POSN                       equ 0000h
CM2NCH_C2NCH0_POSITION                   equ 0000h
CM2NCH_C2NCH0_SIZE                       equ 0001h
CM2NCH_C2NCH0_LENGTH                     equ 0001h
CM2NCH_C2NCH0_MASK                       equ 0001h
CM2NCH_C2NCH1_POSN                       equ 0001h
CM2NCH_C2NCH1_POSITION                   equ 0001h
CM2NCH_C2NCH1_SIZE                       equ 0001h
CM2NCH_C2NCH1_LENGTH                     equ 0001h
CM2NCH_C2NCH1_MASK                       equ 0002h
CM2NCH_C2NCH2_POSN                       equ 0002h
CM2NCH_C2NCH2_POSITION                   equ 0002h
CM2NCH_C2NCH2_SIZE                       equ 0001h
CM2NCH_C2NCH2_LENGTH                     equ 0001h
CM2NCH_C2NCH2_MASK                       equ 0004h

// Register: CM2PCH
#define CM2PCH CM2PCH
CM2PCH                                   equ 0813h
// bitfield definitions
CM2PCH_PCH_POSN                          equ 0000h
CM2PCH_PCH_POSITION                      equ 0000h
CM2PCH_PCH_SIZE                          equ 0003h
CM2PCH_PCH_LENGTH                        equ 0003h
CM2PCH_PCH_MASK                          equ 0007h
CM2PCH_PCH0_POSN                         equ 0000h
CM2PCH_PCH0_POSITION                     equ 0000h
CM2PCH_PCH0_SIZE                         equ 0001h
CM2PCH_PCH0_LENGTH                       equ 0001h
CM2PCH_PCH0_MASK                         equ 0001h
CM2PCH_PCH1_POSN                         equ 0001h
CM2PCH_PCH1_POSITION                     equ 0001h
CM2PCH_PCH1_SIZE                         equ 0001h
CM2PCH_PCH1_LENGTH                       equ 0001h
CM2PCH_PCH1_MASK                         equ 0002h
CM2PCH_PCH2_POSN                         equ 0002h
CM2PCH_PCH2_POSITION                     equ 0002h
CM2PCH_PCH2_SIZE                         equ 0001h
CM2PCH_PCH2_LENGTH                       equ 0001h
CM2PCH_PCH2_MASK                         equ 0004h
CM2PCH_C2PCH0_POSN                       equ 0000h
CM2PCH_C2PCH0_POSITION                   equ 0000h
CM2PCH_C2PCH0_SIZE                       equ 0001h
CM2PCH_C2PCH0_LENGTH                     equ 0001h
CM2PCH_C2PCH0_MASK                       equ 0001h
CM2PCH_C2PCH1_POSN                       equ 0001h
CM2PCH_C2PCH1_POSITION                   equ 0001h
CM2PCH_C2PCH1_SIZE                       equ 0001h
CM2PCH_C2PCH1_LENGTH                     equ 0001h
CM2PCH_C2PCH1_MASK                       equ 0002h
CM2PCH_C2PCH2_POSN                       equ 0002h
CM2PCH_C2PCH2_POSITION                   equ 0002h
CM2PCH_C2PCH2_SIZE                       equ 0001h
CM2PCH_C2PCH2_LENGTH                     equ 0001h
CM2PCH_C2PCH2_MASK                       equ 0004h

// Register: CMOUT
#define CMOUT CMOUT
CMOUT                                    equ 081Fh
// bitfield definitions
CMOUT_C1OUT_POSN                         equ 0000h
CMOUT_C1OUT_POSITION                     equ 0000h
CMOUT_C1OUT_SIZE                         equ 0001h
CMOUT_C1OUT_LENGTH                       equ 0001h
CMOUT_C1OUT_MASK                         equ 0001h
CMOUT_C2OUT_POSN                         equ 0001h
CMOUT_C2OUT_POSITION                     equ 0001h
CMOUT_C2OUT_SIZE                         equ 0001h
CMOUT_C2OUT_LENGTH                       equ 0001h
CMOUT_C2OUT_MASK                         equ 0002h

// Register: PWM1DCL
#define PWM1DCL PWM1DCL
PWM1DCL                                  equ 0820h
// bitfield definitions
PWM1DCL_DCL_POSN                         equ 0006h
PWM1DCL_DCL_POSITION                     equ 0006h
PWM1DCL_DCL_SIZE                         equ 0002h
PWM1DCL_DCL_LENGTH                       equ 0002h
PWM1DCL_DCL_MASK                         equ 00C0h

// Register: PWM1DCH
#define PWM1DCH PWM1DCH
PWM1DCH                                  equ 0821h
// bitfield definitions
PWM1DCH_DCH_POSN                         equ 0000h
PWM1DCH_DCH_POSITION                     equ 0000h
PWM1DCH_DCH_SIZE                         equ 0008h
PWM1DCH_DCH_LENGTH                       equ 0008h
PWM1DCH_DCH_MASK                         equ 00FFh

// Register: PWM1CON
#define PWM1CON PWM1CON
PWM1CON                                  equ 0822h
// bitfield definitions
PWM1CON_POL_POSN                         equ 0004h
PWM1CON_POL_POSITION                     equ 0004h
PWM1CON_POL_SIZE                         equ 0001h
PWM1CON_POL_LENGTH                       equ 0001h
PWM1CON_POL_MASK                         equ 0010h
PWM1CON_OUT_POSN                         equ 0005h
PWM1CON_OUT_POSITION                     equ 0005h
PWM1CON_OUT_SIZE                         equ 0001h
PWM1CON_OUT_LENGTH                       equ 0001h
PWM1CON_OUT_MASK                         equ 0020h
PWM1CON_EN_POSN                          equ 0007h
PWM1CON_EN_POSITION                      equ 0007h
PWM1CON_EN_SIZE                          equ 0001h
PWM1CON_EN_LENGTH                        equ 0001h
PWM1CON_EN_MASK                          equ 0080h
PWM1CON_PWM1POL_POSN                     equ 0004h
PWM1CON_PWM1POL_POSITION                 equ 0004h
PWM1CON_PWM1POL_SIZE                     equ 0001h
PWM1CON_PWM1POL_LENGTH                   equ 0001h
PWM1CON_PWM1POL_MASK                     equ 0010h
PWM1CON_PWM1OUT_POSN                     equ 0005h
PWM1CON_PWM1OUT_POSITION                 equ 0005h
PWM1CON_PWM1OUT_SIZE                     equ 0001h
PWM1CON_PWM1OUT_LENGTH                   equ 0001h
PWM1CON_PWM1OUT_MASK                     equ 0020h
PWM1CON_PWM1EN_POSN                      equ 0007h
PWM1CON_PWM1EN_POSITION                  equ 0007h
PWM1CON_PWM1EN_SIZE                      equ 0001h
PWM1CON_PWM1EN_LENGTH                    equ 0001h
PWM1CON_PWM1EN_MASK                      equ 0080h

// Register: PWM2DCL
#define PWM2DCL PWM2DCL
PWM2DCL                                  equ 0823h
// bitfield definitions
PWM2DCL_DCL_POSN                         equ 0006h
PWM2DCL_DCL_POSITION                     equ 0006h
PWM2DCL_DCL_SIZE                         equ 0002h
PWM2DCL_DCL_LENGTH                       equ 0002h
PWM2DCL_DCL_MASK                         equ 00C0h

// Register: PWM2DCH
#define PWM2DCH PWM2DCH
PWM2DCH                                  equ 0824h
// bitfield definitions
PWM2DCH_DCH_POSN                         equ 0000h
PWM2DCH_DCH_POSITION                     equ 0000h
PWM2DCH_DCH_SIZE                         equ 0008h
PWM2DCH_DCH_LENGTH                       equ 0008h
PWM2DCH_DCH_MASK                         equ 00FFh

// Register: PWM2CON
#define PWM2CON PWM2CON
PWM2CON                                  equ 0825h
// bitfield definitions
PWM2CON_POL_POSN                         equ 0004h
PWM2CON_POL_POSITION                     equ 0004h
PWM2CON_POL_SIZE                         equ 0001h
PWM2CON_POL_LENGTH                       equ 0001h
PWM2CON_POL_MASK                         equ 0010h
PWM2CON_OUT_POSN                         equ 0005h
PWM2CON_OUT_POSITION                     equ 0005h
PWM2CON_OUT_SIZE                         equ 0001h
PWM2CON_OUT_LENGTH                       equ 0001h
PWM2CON_OUT_MASK                         equ 0020h
PWM2CON_EN_POSN                          equ 0007h
PWM2CON_EN_POSITION                      equ 0007h
PWM2CON_EN_SIZE                          equ 0001h
PWM2CON_EN_LENGTH                        equ 0001h
PWM2CON_EN_MASK                          equ 0080h
PWM2CON_PWM2POL_POSN                     equ 0004h
PWM2CON_PWM2POL_POSITION                 equ 0004h
PWM2CON_PWM2POL_SIZE                     equ 0001h
PWM2CON_PWM2POL_LENGTH                   equ 0001h
PWM2CON_PWM2POL_MASK                     equ 0010h
PWM2CON_PWM2OUT_POSN                     equ 0005h
PWM2CON_PWM2OUT_POSITION                 equ 0005h
PWM2CON_PWM2OUT_SIZE                     equ 0001h
PWM2CON_PWM2OUT_LENGTH                   equ 0001h
PWM2CON_PWM2OUT_MASK                     equ 0020h
PWM2CON_PWM2EN_POSN                      equ 0007h
PWM2CON_PWM2EN_POSITION                  equ 0007h
PWM2CON_PWM2EN_SIZE                      equ 0001h
PWM2CON_PWM2EN_LENGTH                    equ 0001h
PWM2CON_PWM2EN_MASK                      equ 0080h

// Register: PWMTMRS0
#define PWMTMRS0 PWMTMRS0
PWMTMRS0                                 equ 082Fh
// bitfield definitions
PWMTMRS0_P1TSEL_POSN                     equ 0000h
PWMTMRS0_P1TSEL_POSITION                 equ 0000h
PWMTMRS0_P1TSEL_SIZE                     equ 0002h
PWMTMRS0_P1TSEL_LENGTH                   equ 0002h
PWMTMRS0_P1TSEL_MASK                     equ 0003h
PWMTMRS0_P2TSEL_POSN                     equ 0002h
PWMTMRS0_P2TSEL_POSITION                 equ 0002h
PWMTMRS0_P2TSEL_SIZE                     equ 0002h
PWMTMRS0_P2TSEL_LENGTH                   equ 0002h
PWMTMRS0_P2TSEL_MASK                     equ 000Ch

// Register: DAC1CON
#define DAC1CON DAC1CON
DAC1CON                                  equ 088Ch
// bitfield definitions
DAC1CON_PSS_POSN                         equ 0002h
DAC1CON_PSS_POSITION                     equ 0002h
DAC1CON_PSS_SIZE                         equ 0002h
DAC1CON_PSS_LENGTH                       equ 0002h
DAC1CON_PSS_MASK                         equ 000Ch
DAC1CON_OE_POSN                          equ 0004h
DAC1CON_OE_POSITION                      equ 0004h
DAC1CON_OE_SIZE                          equ 0002h
DAC1CON_OE_LENGTH                        equ 0002h
DAC1CON_OE_MASK                          equ 0030h
DAC1CON_REFRNG_POSN                      equ 0006h
DAC1CON_REFRNG_POSITION                  equ 0006h
DAC1CON_REFRNG_SIZE                      equ 0001h
DAC1CON_REFRNG_LENGTH                    equ 0001h
DAC1CON_REFRNG_MASK                      equ 0040h
DAC1CON_EN_POSN                          equ 0007h
DAC1CON_EN_POSITION                      equ 0007h
DAC1CON_EN_SIZE                          equ 0001h
DAC1CON_EN_LENGTH                        equ 0001h
DAC1CON_EN_MASK                          equ 0080h
DAC1CON_PSS0_POSN                        equ 0002h
DAC1CON_PSS0_POSITION                    equ 0002h
DAC1CON_PSS0_SIZE                        equ 0001h
DAC1CON_PSS0_LENGTH                      equ 0001h
DAC1CON_PSS0_MASK                        equ 0004h
DAC1CON_PSS1_POSN                        equ 0003h
DAC1CON_PSS1_POSITION                    equ 0003h
DAC1CON_PSS1_SIZE                        equ 0001h
DAC1CON_PSS1_LENGTH                      equ 0001h
DAC1CON_PSS1_MASK                        equ 0008h
DAC1CON_OE0_POSN                         equ 0004h
DAC1CON_OE0_POSITION                     equ 0004h
DAC1CON_OE0_SIZE                         equ 0001h
DAC1CON_OE0_LENGTH                       equ 0001h
DAC1CON_OE0_MASK                         equ 0010h
DAC1CON_OE1_POSN                         equ 0005h
DAC1CON_OE1_POSITION                     equ 0005h
DAC1CON_OE1_SIZE                         equ 0001h
DAC1CON_OE1_LENGTH                       equ 0001h
DAC1CON_OE1_MASK                         equ 0020h

// Register: DAC1DATL
#define DAC1DATL DAC1DATL
DAC1DATL                                 equ 088Dh
// bitfield definitions
DAC1DATL_DAC1R_POSN                      equ 0000h
DAC1DATL_DAC1R_POSITION                  equ 0000h
DAC1DATL_DAC1R_SIZE                      equ 0008h
DAC1DATL_DAC1R_LENGTH                    equ 0008h
DAC1DATL_DAC1R_MASK                      equ 00FFh
DAC1DATL_DAT_POSN                        equ 0000h
DAC1DATL_DAT_POSITION                    equ 0000h
DAC1DATL_DAT_SIZE                        equ 0008h
DAC1DATL_DAT_LENGTH                      equ 0008h
DAC1DATL_DAT_MASK                        equ 00FFh

// Register: NVMADRL
#define NVMADRL NVMADRL
NVMADRL                                  equ 01C8Ch
// bitfield definitions
NVMADRL_NVMADR_POSN                      equ 0000h
NVMADRL_NVMADR_POSITION                  equ 0000h
NVMADRL_NVMADR_SIZE                      equ 0008h
NVMADRL_NVMADR_LENGTH                    equ 0008h
NVMADRL_NVMADR_MASK                      equ 00FFh
NVMADRL_NVMADR0_POSN                     equ 0000h
NVMADRL_NVMADR0_POSITION                 equ 0000h
NVMADRL_NVMADR0_SIZE                     equ 0001h
NVMADRL_NVMADR0_LENGTH                   equ 0001h
NVMADRL_NVMADR0_MASK                     equ 0001h
NVMADRL_NVMADR1_POSN                     equ 0001h
NVMADRL_NVMADR1_POSITION                 equ 0001h
NVMADRL_NVMADR1_SIZE                     equ 0001h
NVMADRL_NVMADR1_LENGTH                   equ 0001h
NVMADRL_NVMADR1_MASK                     equ 0002h
NVMADRL_NVMADR2_POSN                     equ 0002h
NVMADRL_NVMADR2_POSITION                 equ 0002h
NVMADRL_NVMADR2_SIZE                     equ 0001h
NVMADRL_NVMADR2_LENGTH                   equ 0001h
NVMADRL_NVMADR2_MASK                     equ 0004h
NVMADRL_NVMADR3_POSN                     equ 0003h
NVMADRL_NVMADR3_POSITION                 equ 0003h
NVMADRL_NVMADR3_SIZE                     equ 0001h
NVMADRL_NVMADR3_LENGTH                   equ 0001h
NVMADRL_NVMADR3_MASK                     equ 0008h
NVMADRL_NVMADR4_POSN                     equ 0004h
NVMADRL_NVMADR4_POSITION                 equ 0004h
NVMADRL_NVMADR4_SIZE                     equ 0001h
NVMADRL_NVMADR4_LENGTH                   equ 0001h
NVMADRL_NVMADR4_MASK                     equ 0010h
NVMADRL_NVMADR5_POSN                     equ 0005h
NVMADRL_NVMADR5_POSITION                 equ 0005h
NVMADRL_NVMADR5_SIZE                     equ 0001h
NVMADRL_NVMADR5_LENGTH                   equ 0001h
NVMADRL_NVMADR5_MASK                     equ 0020h
NVMADRL_NVMADR6_POSN                     equ 0006h
NVMADRL_NVMADR6_POSITION                 equ 0006h
NVMADRL_NVMADR6_SIZE                     equ 0001h
NVMADRL_NVMADR6_LENGTH                   equ 0001h
NVMADRL_NVMADR6_MASK                     equ 0040h
NVMADRL_NVMADR7_POSN                     equ 0007h
NVMADRL_NVMADR7_POSITION                 equ 0007h
NVMADRL_NVMADR7_SIZE                     equ 0001h
NVMADRL_NVMADR7_LENGTH                   equ 0001h
NVMADRL_NVMADR7_MASK                     equ 0080h

// Register: NVMADRH
#define NVMADRH NVMADRH
NVMADRH                                  equ 01C8Dh
// bitfield definitions
NVMADRH_NVMADR_POSN                      equ 0000h
NVMADRH_NVMADR_POSITION                  equ 0000h
NVMADRH_NVMADR_SIZE                      equ 0007h
NVMADRH_NVMADR_LENGTH                    equ 0007h
NVMADRH_NVMADR_MASK                      equ 007Fh
NVMADRH_NVMADR8_POSN                     equ 0000h
NVMADRH_NVMADR8_POSITION                 equ 0000h
NVMADRH_NVMADR8_SIZE                     equ 0001h
NVMADRH_NVMADR8_LENGTH                   equ 0001h
NVMADRH_NVMADR8_MASK                     equ 0001h
NVMADRH_NVMADR9_POSN                     equ 0001h
NVMADRH_NVMADR9_POSITION                 equ 0001h
NVMADRH_NVMADR9_SIZE                     equ 0001h
NVMADRH_NVMADR9_LENGTH                   equ 0001h
NVMADRH_NVMADR9_MASK                     equ 0002h
NVMADRH_NVMADR10_POSN                    equ 0002h
NVMADRH_NVMADR10_POSITION                equ 0002h
NVMADRH_NVMADR10_SIZE                    equ 0001h
NVMADRH_NVMADR10_LENGTH                  equ 0001h
NVMADRH_NVMADR10_MASK                    equ 0004h
NVMADRH_NVMADR11_POSN                    equ 0003h
NVMADRH_NVMADR11_POSITION                equ 0003h
NVMADRH_NVMADR11_SIZE                    equ 0001h
NVMADRH_NVMADR11_LENGTH                  equ 0001h
NVMADRH_NVMADR11_MASK                    equ 0008h
NVMADRH_NVMADR12_POSN                    equ 0004h
NVMADRH_NVMADR12_POSITION                equ 0004h
NVMADRH_NVMADR12_SIZE                    equ 0001h
NVMADRH_NVMADR12_LENGTH                  equ 0001h
NVMADRH_NVMADR12_MASK                    equ 0010h
NVMADRH_NVMADR13_POSN                    equ 0005h
NVMADRH_NVMADR13_POSITION                equ 0005h
NVMADRH_NVMADR13_SIZE                    equ 0001h
NVMADRH_NVMADR13_LENGTH                  equ 0001h
NVMADRH_NVMADR13_MASK                    equ 0020h
NVMADRH_NVMADR14_POSN                    equ 0006h
NVMADRH_NVMADR14_POSITION                equ 0006h
NVMADRH_NVMADR14_SIZE                    equ 0001h
NVMADRH_NVMADR14_LENGTH                  equ 0001h
NVMADRH_NVMADR14_MASK                    equ 0040h

// Register: NVMDATL
#define NVMDATL NVMDATL
NVMDATL                                  equ 01C8Eh
// bitfield definitions
NVMDATL_NVMDAT_POSN                      equ 0000h
NVMDATL_NVMDAT_POSITION                  equ 0000h
NVMDATL_NVMDAT_SIZE                      equ 0008h
NVMDATL_NVMDAT_LENGTH                    equ 0008h
NVMDATL_NVMDAT_MASK                      equ 00FFh
NVMDATL_NVMDAT0_POSN                     equ 0000h
NVMDATL_NVMDAT0_POSITION                 equ 0000h
NVMDATL_NVMDAT0_SIZE                     equ 0001h
NVMDATL_NVMDAT0_LENGTH                   equ 0001h
NVMDATL_NVMDAT0_MASK                     equ 0001h
NVMDATL_NVMDAT1_POSN                     equ 0001h
NVMDATL_NVMDAT1_POSITION                 equ 0001h
NVMDATL_NVMDAT1_SIZE                     equ 0001h
NVMDATL_NVMDAT1_LENGTH                   equ 0001h
NVMDATL_NVMDAT1_MASK                     equ 0002h
NVMDATL_NVMDAT2_POSN                     equ 0002h
NVMDATL_NVMDAT2_POSITION                 equ 0002h
NVMDATL_NVMDAT2_SIZE                     equ 0001h
NVMDATL_NVMDAT2_LENGTH                   equ 0001h
NVMDATL_NVMDAT2_MASK                     equ 0004h
NVMDATL_NVMDAT3_POSN                     equ 0003h
NVMDATL_NVMDAT3_POSITION                 equ 0003h
NVMDATL_NVMDAT3_SIZE                     equ 0001h
NVMDATL_NVMDAT3_LENGTH                   equ 0001h
NVMDATL_NVMDAT3_MASK                     equ 0008h
NVMDATL_NVMDAT4_POSN                     equ 0004h
NVMDATL_NVMDAT4_POSITION                 equ 0004h
NVMDATL_NVMDAT4_SIZE                     equ 0001h
NVMDATL_NVMDAT4_LENGTH                   equ 0001h
NVMDATL_NVMDAT4_MASK                     equ 0010h
NVMDATL_NVMDAT5_POSN                     equ 0005h
NVMDATL_NVMDAT5_POSITION                 equ 0005h
NVMDATL_NVMDAT5_SIZE                     equ 0001h
NVMDATL_NVMDAT5_LENGTH                   equ 0001h
NVMDATL_NVMDAT5_MASK                     equ 0020h
NVMDATL_NVMDAT6_POSN                     equ 0006h
NVMDATL_NVMDAT6_POSITION                 equ 0006h
NVMDATL_NVMDAT6_SIZE                     equ 0001h
NVMDATL_NVMDAT6_LENGTH                   equ 0001h
NVMDATL_NVMDAT6_MASK                     equ 0040h
NVMDATL_NVMDAT7_POSN                     equ 0007h
NVMDATL_NVMDAT7_POSITION                 equ 0007h
NVMDATL_NVMDAT7_SIZE                     equ 0001h
NVMDATL_NVMDAT7_LENGTH                   equ 0001h
NVMDATL_NVMDAT7_MASK                     equ 0080h

// Register: NVMDATH
#define NVMDATH NVMDATH
NVMDATH                                  equ 01C8Fh
// bitfield definitions
NVMDATH_NVMDAT_POSN                      equ 0000h
NVMDATH_NVMDAT_POSITION                  equ 0000h
NVMDATH_NVMDAT_SIZE                      equ 0006h
NVMDATH_NVMDAT_LENGTH                    equ 0006h
NVMDATH_NVMDAT_MASK                      equ 003Fh
NVMDATH_NVMDAT8_POSN                     equ 0000h
NVMDATH_NVMDAT8_POSITION                 equ 0000h
NVMDATH_NVMDAT8_SIZE                     equ 0001h
NVMDATH_NVMDAT8_LENGTH                   equ 0001h
NVMDATH_NVMDAT8_MASK                     equ 0001h
NVMDATH_NVMDAT9_POSN                     equ 0001h
NVMDATH_NVMDAT9_POSITION                 equ 0001h
NVMDATH_NVMDAT9_SIZE                     equ 0001h
NVMDATH_NVMDAT9_LENGTH                   equ 0001h
NVMDATH_NVMDAT9_MASK                     equ 0002h
NVMDATH_NVMDAT10_POSN                    equ 0002h
NVMDATH_NVMDAT10_POSITION                equ 0002h
NVMDATH_NVMDAT10_SIZE                    equ 0001h
NVMDATH_NVMDAT10_LENGTH                  equ 0001h
NVMDATH_NVMDAT10_MASK                    equ 0004h
NVMDATH_NVMDAT11_POSN                    equ 0003h
NVMDATH_NVMDAT11_POSITION                equ 0003h
NVMDATH_NVMDAT11_SIZE                    equ 0001h
NVMDATH_NVMDAT11_LENGTH                  equ 0001h
NVMDATH_NVMDAT11_MASK                    equ 0008h
NVMDATH_NVMDAT12_POSN                    equ 0004h
NVMDATH_NVMDAT12_POSITION                equ 0004h
NVMDATH_NVMDAT12_SIZE                    equ 0001h
NVMDATH_NVMDAT12_LENGTH                  equ 0001h
NVMDATH_NVMDAT12_MASK                    equ 0010h
NVMDATH_NVMDAT13_POSN                    equ 0005h
NVMDATH_NVMDAT13_POSITION                equ 0005h
NVMDATH_NVMDAT13_SIZE                    equ 0001h
NVMDATH_NVMDAT13_LENGTH                  equ 0001h
NVMDATH_NVMDAT13_MASK                    equ 0020h

// Register: NVMCON1
#define NVMCON1 NVMCON1
NVMCON1                                  equ 01C90h
// bitfield definitions
NVMCON1_RD_POSN                          equ 0000h
NVMCON1_RD_POSITION                      equ 0000h
NVMCON1_RD_SIZE                          equ 0001h
NVMCON1_RD_LENGTH                        equ 0001h
NVMCON1_RD_MASK                          equ 0001h
NVMCON1_WR_POSN                          equ 0001h
NVMCON1_WR_POSITION                      equ 0001h
NVMCON1_WR_SIZE                          equ 0001h
NVMCON1_WR_LENGTH                        equ 0001h
NVMCON1_WR_MASK                          equ 0002h
NVMCON1_WREN_POSN                        equ 0002h
NVMCON1_WREN_POSITION                    equ 0002h
NVMCON1_WREN_SIZE                        equ 0001h
NVMCON1_WREN_LENGTH                      equ 0001h
NVMCON1_WREN_MASK                        equ 0004h
NVMCON1_WRERR_POSN                       equ 0003h
NVMCON1_WRERR_POSITION                   equ 0003h
NVMCON1_WRERR_SIZE                       equ 0001h
NVMCON1_WRERR_LENGTH                     equ 0001h
NVMCON1_WRERR_MASK                       equ 0008h
NVMCON1_FREE_POSN                        equ 0004h
NVMCON1_FREE_POSITION                    equ 0004h
NVMCON1_FREE_SIZE                        equ 0001h
NVMCON1_FREE_LENGTH                      equ 0001h
NVMCON1_FREE_MASK                        equ 0010h
NVMCON1_LWLO_POSN                        equ 0005h
NVMCON1_LWLO_POSITION                    equ 0005h
NVMCON1_LWLO_SIZE                        equ 0001h
NVMCON1_LWLO_LENGTH                      equ 0001h
NVMCON1_LWLO_MASK                        equ 0020h
NVMCON1_NVMREGS_POSN                     equ 0006h
NVMCON1_NVMREGS_POSITION                 equ 0006h
NVMCON1_NVMREGS_SIZE                     equ 0001h
NVMCON1_NVMREGS_LENGTH                   equ 0001h
NVMCON1_NVMREGS_MASK                     equ 0040h

// Register: NVMCON2
#define NVMCON2 NVMCON2
NVMCON2                                  equ 01C91h
// bitfield definitions
NVMCON2_NVMCON2_POSN                     equ 0000h
NVMCON2_NVMCON2_POSITION                 equ 0000h
NVMCON2_NVMCON2_SIZE                     equ 0008h
NVMCON2_NVMCON2_LENGTH                   equ 0008h
NVMCON2_NVMCON2_MASK                     equ 00FFh

// Register: SCANCON0
#define SCANCON0 SCANCON0
SCANCON0                                 equ 01C92h
// bitfield definitions
SCANCON0_MD_POSN                         equ 0000h
SCANCON0_MD_POSITION                     equ 0000h
SCANCON0_MD_SIZE                         equ 0002h
SCANCON0_MD_LENGTH                       equ 0002h
SCANCON0_MD_MASK                         equ 0003h
SCANCON0_INTM_POSN                       equ 0003h
SCANCON0_INTM_POSITION                   equ 0003h
SCANCON0_INTM_SIZE                       equ 0001h
SCANCON0_INTM_LENGTH                     equ 0001h
SCANCON0_INTM_MASK                       equ 0008h
SCANCON0_DABORT_POSN                     equ 0004h
SCANCON0_DABORT_POSITION                 equ 0004h
SCANCON0_DABORT_SIZE                     equ 0001h
SCANCON0_DABORT_LENGTH                   equ 0001h
SCANCON0_DABORT_MASK                     equ 0010h
SCANCON0_BUSY_POSN                       equ 0005h
SCANCON0_BUSY_POSITION                   equ 0005h
SCANCON0_BUSY_SIZE                       equ 0001h
SCANCON0_BUSY_LENGTH                     equ 0001h
SCANCON0_BUSY_MASK                       equ 0020h
SCANCON0_SGO_POSN                        equ 0006h
SCANCON0_SGO_POSITION                    equ 0006h
SCANCON0_SGO_SIZE                        equ 0001h
SCANCON0_SGO_LENGTH                      equ 0001h
SCANCON0_SGO_MASK                        equ 0040h
SCANCON0_EN_POSN                         equ 0007h
SCANCON0_EN_POSITION                     equ 0007h
SCANCON0_EN_SIZE                         equ 0001h
SCANCON0_EN_LENGTH                       equ 0001h
SCANCON0_EN_MASK                         equ 0080h
SCANCON0_MD0_POSN                        equ 0000h
SCANCON0_MD0_POSITION                    equ 0000h
SCANCON0_MD0_SIZE                        equ 0001h
SCANCON0_MD0_LENGTH                      equ 0001h
SCANCON0_MD0_MASK                        equ 0001h
SCANCON0_MD1_POSN                        equ 0001h
SCANCON0_MD1_POSITION                    equ 0001h
SCANCON0_MD1_SIZE                        equ 0001h
SCANCON0_MD1_LENGTH                      equ 0001h
SCANCON0_MD1_MASK                        equ 0002h

// Register: SCANLADRL
#define SCANLADRL SCANLADRL
SCANLADRL                                equ 01C93h
// bitfield definitions
SCANLADRL_SCANLADRL_POSN                 equ 0000h
SCANLADRL_SCANLADRL_POSITION             equ 0000h
SCANLADRL_SCANLADRL_SIZE                 equ 0008h
SCANLADRL_SCANLADRL_LENGTH               equ 0008h
SCANLADRL_SCANLADRL_MASK                 equ 00FFh

// Register: SCANLADRH
#define SCANLADRH SCANLADRH
SCANLADRH                                equ 01C94h
// bitfield definitions
SCANLADRH_SCANLADRH_POSN                 equ 0000h
SCANLADRH_SCANLADRH_POSITION             equ 0000h
SCANLADRH_SCANLADRH_SIZE                 equ 0008h
SCANLADRH_SCANLADRH_LENGTH               equ 0008h
SCANLADRH_SCANLADRH_MASK                 equ 00FFh

// Register: SCANHADRL
#define SCANHADRL SCANHADRL
SCANHADRL                                equ 01C96h
// bitfield definitions
SCANHADRL_SCANHADRL_POSN                 equ 0000h
SCANHADRL_SCANHADRL_POSITION             equ 0000h
SCANHADRL_SCANHADRL_SIZE                 equ 0008h
SCANHADRL_SCANHADRL_LENGTH               equ 0008h
SCANHADRL_SCANHADRL_MASK                 equ 00FFh

// Register: SCANHADRH
#define SCANHADRH SCANHADRH
SCANHADRH                                equ 01C97h
// bitfield definitions
SCANHADRH_SCANHADRH_POSN                 equ 0000h
SCANHADRH_SCANHADRH_POSITION             equ 0000h
SCANHADRH_SCANHADRH_SIZE                 equ 0008h
SCANHADRH_SCANHADRH_LENGTH               equ 0008h
SCANHADRH_SCANHADRH_MASK                 equ 00FFh

// Register: SCANDPS
#define SCANDPS SCANDPS
SCANDPS                                  equ 01C99h
// bitfield definitions
SCANDPS_DPS_POSN                         equ 0000h
SCANDPS_DPS_POSITION                     equ 0000h
SCANDPS_DPS_SIZE                         equ 0001h
SCANDPS_DPS_LENGTH                       equ 0001h
SCANDPS_DPS_MASK                         equ 0001h

// Register: SCANTRIG
#define SCANTRIG SCANTRIG
SCANTRIG                                 equ 01C9Ah
// bitfield definitions
SCANTRIG_TSEL_POSN                       equ 0000h
SCANTRIG_TSEL_POSITION                   equ 0000h
SCANTRIG_TSEL_SIZE                       equ 0004h
SCANTRIG_TSEL_LENGTH                     equ 0004h
SCANTRIG_TSEL_MASK                       equ 000Fh

// Register: CRCDATAL
#define CRCDATAL CRCDATAL
CRCDATAL                                 equ 01C9Dh
// bitfield definitions
CRCDATAL_DATA_POSN                       equ 0000h
CRCDATAL_DATA_POSITION                   equ 0000h
CRCDATAL_DATA_SIZE                       equ 0008h
CRCDATAL_DATA_LENGTH                     equ 0008h
CRCDATAL_DATA_MASK                       equ 00FFh
CRCDATAL_DATA0_POSN                      equ 0000h
CRCDATAL_DATA0_POSITION                  equ 0000h
CRCDATAL_DATA0_SIZE                      equ 0001h
CRCDATAL_DATA0_LENGTH                    equ 0001h
CRCDATAL_DATA0_MASK                      equ 0001h
CRCDATAL_DATA1_POSN                      equ 0001h
CRCDATAL_DATA1_POSITION                  equ 0001h
CRCDATAL_DATA1_SIZE                      equ 0001h
CRCDATAL_DATA1_LENGTH                    equ 0001h
CRCDATAL_DATA1_MASK                      equ 0002h
CRCDATAL_DATA2_POSN                      equ 0002h
CRCDATAL_DATA2_POSITION                  equ 0002h
CRCDATAL_DATA2_SIZE                      equ 0001h
CRCDATAL_DATA2_LENGTH                    equ 0001h
CRCDATAL_DATA2_MASK                      equ 0004h
CRCDATAL_DATA3_POSN                      equ 0003h
CRCDATAL_DATA3_POSITION                  equ 0003h
CRCDATAL_DATA3_SIZE                      equ 0001h
CRCDATAL_DATA3_LENGTH                    equ 0001h
CRCDATAL_DATA3_MASK                      equ 0008h
CRCDATAL_DATA4_POSN                      equ 0004h
CRCDATAL_DATA4_POSITION                  equ 0004h
CRCDATAL_DATA4_SIZE                      equ 0001h
CRCDATAL_DATA4_LENGTH                    equ 0001h
CRCDATAL_DATA4_MASK                      equ 0010h
CRCDATAL_DATA5_POSN                      equ 0005h
CRCDATAL_DATA5_POSITION                  equ 0005h
CRCDATAL_DATA5_SIZE                      equ 0001h
CRCDATAL_DATA5_LENGTH                    equ 0001h
CRCDATAL_DATA5_MASK                      equ 0020h
CRCDATAL_DATA6_POSN                      equ 0006h
CRCDATAL_DATA6_POSITION                  equ 0006h
CRCDATAL_DATA6_SIZE                      equ 0001h
CRCDATAL_DATA6_LENGTH                    equ 0001h
CRCDATAL_DATA6_MASK                      equ 0040h
CRCDATAL_DATA7_POSN                      equ 0007h
CRCDATAL_DATA7_POSITION                  equ 0007h
CRCDATAL_DATA7_SIZE                      equ 0001h
CRCDATAL_DATA7_LENGTH                    equ 0001h
CRCDATAL_DATA7_MASK                      equ 0080h

// Register: CRCDATAH
#define CRCDATAH CRCDATAH
CRCDATAH                                 equ 01C9Eh
// bitfield definitions
CRCDATAH_DATA_POSN                       equ 0000h
CRCDATAH_DATA_POSITION                   equ 0000h
CRCDATAH_DATA_SIZE                       equ 0008h
CRCDATAH_DATA_LENGTH                     equ 0008h
CRCDATAH_DATA_MASK                       equ 00FFh
CRCDATAH_DATA8_POSN                      equ 0000h
CRCDATAH_DATA8_POSITION                  equ 0000h
CRCDATAH_DATA8_SIZE                      equ 0001h
CRCDATAH_DATA8_LENGTH                    equ 0001h
CRCDATAH_DATA8_MASK                      equ 0001h
CRCDATAH_DATA9_POSN                      equ 0001h
CRCDATAH_DATA9_POSITION                  equ 0001h
CRCDATAH_DATA9_SIZE                      equ 0001h
CRCDATAH_DATA9_LENGTH                    equ 0001h
CRCDATAH_DATA9_MASK                      equ 0002h
CRCDATAH_DATA10_POSN                     equ 0002h
CRCDATAH_DATA10_POSITION                 equ 0002h
CRCDATAH_DATA10_SIZE                     equ 0001h
CRCDATAH_DATA10_LENGTH                   equ 0001h
CRCDATAH_DATA10_MASK                     equ 0004h
CRCDATAH_DATA11_POSN                     equ 0003h
CRCDATAH_DATA11_POSITION                 equ 0003h
CRCDATAH_DATA11_SIZE                     equ 0001h
CRCDATAH_DATA11_LENGTH                   equ 0001h
CRCDATAH_DATA11_MASK                     equ 0008h
CRCDATAH_DATA12_POSN                     equ 0004h
CRCDATAH_DATA12_POSITION                 equ 0004h
CRCDATAH_DATA12_SIZE                     equ 0001h
CRCDATAH_DATA12_LENGTH                   equ 0001h
CRCDATAH_DATA12_MASK                     equ 0010h
CRCDATAH_DATA13_POSN                     equ 0005h
CRCDATAH_DATA13_POSITION                 equ 0005h
CRCDATAH_DATA13_SIZE                     equ 0001h
CRCDATAH_DATA13_LENGTH                   equ 0001h
CRCDATAH_DATA13_MASK                     equ 0020h
CRCDATAH_DATA14_POSN                     equ 0006h
CRCDATAH_DATA14_POSITION                 equ 0006h
CRCDATAH_DATA14_SIZE                     equ 0001h
CRCDATAH_DATA14_LENGTH                   equ 0001h
CRCDATAH_DATA14_MASK                     equ 0040h
CRCDATAH_DATA15_POSN                     equ 0007h
CRCDATAH_DATA15_POSITION                 equ 0007h
CRCDATAH_DATA15_SIZE                     equ 0001h
CRCDATAH_DATA15_LENGTH                   equ 0001h
CRCDATAH_DATA15_MASK                     equ 0080h

// Register: CRCDATAU
#define CRCDATAU CRCDATAU
CRCDATAU                                 equ 01C9Fh
// bitfield definitions
CRCDATAU_DATA_POSN                       equ 0000h
CRCDATAU_DATA_POSITION                   equ 0000h
CRCDATAU_DATA_SIZE                       equ 0008h
CRCDATAU_DATA_LENGTH                     equ 0008h
CRCDATAU_DATA_MASK                       equ 00FFh
CRCDATAU_DATA16_POSN                     equ 0000h
CRCDATAU_DATA16_POSITION                 equ 0000h
CRCDATAU_DATA16_SIZE                     equ 0001h
CRCDATAU_DATA16_LENGTH                   equ 0001h
CRCDATAU_DATA16_MASK                     equ 0001h
CRCDATAU_DATA17_POSN                     equ 0001h
CRCDATAU_DATA17_POSITION                 equ 0001h
CRCDATAU_DATA17_SIZE                     equ 0001h
CRCDATAU_DATA17_LENGTH                   equ 0001h
CRCDATAU_DATA17_MASK                     equ 0002h
CRCDATAU_DATA18_POSN                     equ 0002h
CRCDATAU_DATA18_POSITION                 equ 0002h
CRCDATAU_DATA18_SIZE                     equ 0001h
CRCDATAU_DATA18_LENGTH                   equ 0001h
CRCDATAU_DATA18_MASK                     equ 0004h
CRCDATAU_DATA19_POSN                     equ 0003h
CRCDATAU_DATA19_POSITION                 equ 0003h
CRCDATAU_DATA19_SIZE                     equ 0001h
CRCDATAU_DATA19_LENGTH                   equ 0001h
CRCDATAU_DATA19_MASK                     equ 0008h
CRCDATAU_DATA20_POSN                     equ 0004h
CRCDATAU_DATA20_POSITION                 equ 0004h
CRCDATAU_DATA20_SIZE                     equ 0001h
CRCDATAU_DATA20_LENGTH                   equ 0001h
CRCDATAU_DATA20_MASK                     equ 0010h
CRCDATAU_DATA21_POSN                     equ 0005h
CRCDATAU_DATA21_POSITION                 equ 0005h
CRCDATAU_DATA21_SIZE                     equ 0001h
CRCDATAU_DATA21_LENGTH                   equ 0001h
CRCDATAU_DATA21_MASK                     equ 0020h
CRCDATAU_DATA22_POSN                     equ 0006h
CRCDATAU_DATA22_POSITION                 equ 0006h
CRCDATAU_DATA22_SIZE                     equ 0001h
CRCDATAU_DATA22_LENGTH                   equ 0001h
CRCDATAU_DATA22_MASK                     equ 0040h
CRCDATAU_DATA23_POSN                     equ 0007h
CRCDATAU_DATA23_POSITION                 equ 0007h
CRCDATAU_DATA23_SIZE                     equ 0001h
CRCDATAU_DATA23_LENGTH                   equ 0001h
CRCDATAU_DATA23_MASK                     equ 0080h

// Register: CRCDATAT
#define CRCDATAT CRCDATAT
CRCDATAT                                 equ 01CA0h
// bitfield definitions
CRCDATAT_DATA_POSN                       equ 0000h
CRCDATAT_DATA_POSITION                   equ 0000h
CRCDATAT_DATA_SIZE                       equ 0008h
CRCDATAT_DATA_LENGTH                     equ 0008h
CRCDATAT_DATA_MASK                       equ 00FFh
CRCDATAT_DATA24_POSN                     equ 0000h
CRCDATAT_DATA24_POSITION                 equ 0000h
CRCDATAT_DATA24_SIZE                     equ 0001h
CRCDATAT_DATA24_LENGTH                   equ 0001h
CRCDATAT_DATA24_MASK                     equ 0001h
CRCDATAT_DATA25_POSN                     equ 0001h
CRCDATAT_DATA25_POSITION                 equ 0001h
CRCDATAT_DATA25_SIZE                     equ 0001h
CRCDATAT_DATA25_LENGTH                   equ 0001h
CRCDATAT_DATA25_MASK                     equ 0002h
CRCDATAT_DATA26_POSN                     equ 0002h
CRCDATAT_DATA26_POSITION                 equ 0002h
CRCDATAT_DATA26_SIZE                     equ 0001h
CRCDATAT_DATA26_LENGTH                   equ 0001h
CRCDATAT_DATA26_MASK                     equ 0004h
CRCDATAT_DATA27_POSN                     equ 0003h
CRCDATAT_DATA27_POSITION                 equ 0003h
CRCDATAT_DATA27_SIZE                     equ 0001h
CRCDATAT_DATA27_LENGTH                   equ 0001h
CRCDATAT_DATA27_MASK                     equ 0008h
CRCDATAT_DATA28_POSN                     equ 0004h
CRCDATAT_DATA28_POSITION                 equ 0004h
CRCDATAT_DATA28_SIZE                     equ 0001h
CRCDATAT_DATA28_LENGTH                   equ 0001h
CRCDATAT_DATA28_MASK                     equ 0010h
CRCDATAT_DATA29_POSN                     equ 0005h
CRCDATAT_DATA29_POSITION                 equ 0005h
CRCDATAT_DATA29_SIZE                     equ 0001h
CRCDATAT_DATA29_LENGTH                   equ 0001h
CRCDATAT_DATA29_MASK                     equ 0020h
CRCDATAT_DATA30_POSN                     equ 0006h
CRCDATAT_DATA30_POSITION                 equ 0006h
CRCDATAT_DATA30_SIZE                     equ 0001h
CRCDATAT_DATA30_LENGTH                   equ 0001h
CRCDATAT_DATA30_MASK                     equ 0040h
CRCDATAT_DATA31_POSN                     equ 0007h
CRCDATAT_DATA31_POSITION                 equ 0007h
CRCDATAT_DATA31_SIZE                     equ 0001h
CRCDATAT_DATA31_LENGTH                   equ 0001h
CRCDATAT_DATA31_MASK                     equ 0080h

// Register: CRCOUTL
#define CRCOUTL CRCOUTL
CRCOUTL                                  equ 01CA1h
// bitfield definitions
CRCOUTL_OUT_POSN                         equ 0000h
CRCOUTL_OUT_POSITION                     equ 0000h
CRCOUTL_OUT_SIZE                         equ 0008h
CRCOUTL_OUT_LENGTH                       equ 0008h
CRCOUTL_OUT_MASK                         equ 00FFh
CRCOUTL_OUT0_POSN                        equ 0000h
CRCOUTL_OUT0_POSITION                    equ 0000h
CRCOUTL_OUT0_SIZE                        equ 0001h
CRCOUTL_OUT0_LENGTH                      equ 0001h
CRCOUTL_OUT0_MASK                        equ 0001h
CRCOUTL_OUT1_POSN                        equ 0001h
CRCOUTL_OUT1_POSITION                    equ 0001h
CRCOUTL_OUT1_SIZE                        equ 0001h
CRCOUTL_OUT1_LENGTH                      equ 0001h
CRCOUTL_OUT1_MASK                        equ 0002h
CRCOUTL_OUT2_POSN                        equ 0002h
CRCOUTL_OUT2_POSITION                    equ 0002h
CRCOUTL_OUT2_SIZE                        equ 0001h
CRCOUTL_OUT2_LENGTH                      equ 0001h
CRCOUTL_OUT2_MASK                        equ 0004h
CRCOUTL_OUT3_POSN                        equ 0003h
CRCOUTL_OUT3_POSITION                    equ 0003h
CRCOUTL_OUT3_SIZE                        equ 0001h
CRCOUTL_OUT3_LENGTH                      equ 0001h
CRCOUTL_OUT3_MASK                        equ 0008h
CRCOUTL_OUT4_POSN                        equ 0004h
CRCOUTL_OUT4_POSITION                    equ 0004h
CRCOUTL_OUT4_SIZE                        equ 0001h
CRCOUTL_OUT4_LENGTH                      equ 0001h
CRCOUTL_OUT4_MASK                        equ 0010h
CRCOUTL_OUT5_POSN                        equ 0005h
CRCOUTL_OUT5_POSITION                    equ 0005h
CRCOUTL_OUT5_SIZE                        equ 0001h
CRCOUTL_OUT5_LENGTH                      equ 0001h
CRCOUTL_OUT5_MASK                        equ 0020h
CRCOUTL_OUT6_POSN                        equ 0006h
CRCOUTL_OUT6_POSITION                    equ 0006h
CRCOUTL_OUT6_SIZE                        equ 0001h
CRCOUTL_OUT6_LENGTH                      equ 0001h
CRCOUTL_OUT6_MASK                        equ 0040h
CRCOUTL_OUT7_POSN                        equ 0007h
CRCOUTL_OUT7_POSITION                    equ 0007h
CRCOUTL_OUT7_SIZE                        equ 0001h
CRCOUTL_OUT7_LENGTH                      equ 0001h
CRCOUTL_OUT7_MASK                        equ 0080h

// Register: CRCSHFTL
#define CRCSHFTL CRCSHFTL
CRCSHFTL                                 equ 01CA1h
// bitfield definitions
CRCSHFTL_SHIFT_POSN                      equ 0000h
CRCSHFTL_SHIFT_POSITION                  equ 0000h
CRCSHFTL_SHIFT_SIZE                      equ 0008h
CRCSHFTL_SHIFT_LENGTH                    equ 0008h
CRCSHFTL_SHIFT_MASK                      equ 00FFh
CRCSHFTL_SHIFT0_POSN                     equ 0000h
CRCSHFTL_SHIFT0_POSITION                 equ 0000h
CRCSHFTL_SHIFT0_SIZE                     equ 0001h
CRCSHFTL_SHIFT0_LENGTH                   equ 0001h
CRCSHFTL_SHIFT0_MASK                     equ 0001h
CRCSHFTL_SHIFT1_POSN                     equ 0001h
CRCSHFTL_SHIFT1_POSITION                 equ 0001h
CRCSHFTL_SHIFT1_SIZE                     equ 0001h
CRCSHFTL_SHIFT1_LENGTH                   equ 0001h
CRCSHFTL_SHIFT1_MASK                     equ 0002h
CRCSHFTL_SHIFT2_POSN                     equ 0002h
CRCSHFTL_SHIFT2_POSITION                 equ 0002h
CRCSHFTL_SHIFT2_SIZE                     equ 0001h
CRCSHFTL_SHIFT2_LENGTH                   equ 0001h
CRCSHFTL_SHIFT2_MASK                     equ 0004h
CRCSHFTL_SHIFT3_POSN                     equ 0003h
CRCSHFTL_SHIFT3_POSITION                 equ 0003h
CRCSHFTL_SHIFT3_SIZE                     equ 0001h
CRCSHFTL_SHIFT3_LENGTH                   equ 0001h
CRCSHFTL_SHIFT3_MASK                     equ 0008h
CRCSHFTL_SHIFT4_POSN                     equ 0004h
CRCSHFTL_SHIFT4_POSITION                 equ 0004h
CRCSHFTL_SHIFT4_SIZE                     equ 0001h
CRCSHFTL_SHIFT4_LENGTH                   equ 0001h
CRCSHFTL_SHIFT4_MASK                     equ 0010h
CRCSHFTL_SHIFT5_POSN                     equ 0005h
CRCSHFTL_SHIFT5_POSITION                 equ 0005h
CRCSHFTL_SHIFT5_SIZE                     equ 0001h
CRCSHFTL_SHIFT5_LENGTH                   equ 0001h
CRCSHFTL_SHIFT5_MASK                     equ 0020h
CRCSHFTL_SHIFT6_POSN                     equ 0006h
CRCSHFTL_SHIFT6_POSITION                 equ 0006h
CRCSHFTL_SHIFT6_SIZE                     equ 0001h
CRCSHFTL_SHIFT6_LENGTH                   equ 0001h
CRCSHFTL_SHIFT6_MASK                     equ 0040h
CRCSHFTL_SHIFT7_POSN                     equ 0007h
CRCSHFTL_SHIFT7_POSITION                 equ 0007h
CRCSHFTL_SHIFT7_SIZE                     equ 0001h
CRCSHFTL_SHIFT7_LENGTH                   equ 0001h
CRCSHFTL_SHIFT7_MASK                     equ 0080h

// Register: CRCXORL
#define CRCXORL CRCXORL
CRCXORL                                  equ 01CA1h
// bitfield definitions
CRCXORL_XOR_POSN                         equ 0000h
CRCXORL_XOR_POSITION                     equ 0000h
CRCXORL_XOR_SIZE                         equ 0008h
CRCXORL_XOR_LENGTH                       equ 0008h
CRCXORL_XOR_MASK                         equ 00FFh
CRCXORL_XOR0_POSN                        equ 0000h
CRCXORL_XOR0_POSITION                    equ 0000h
CRCXORL_XOR0_SIZE                        equ 0001h
CRCXORL_XOR0_LENGTH                      equ 0001h
CRCXORL_XOR0_MASK                        equ 0001h
CRCXORL_XOR1_POSN                        equ 0001h
CRCXORL_XOR1_POSITION                    equ 0001h
CRCXORL_XOR1_SIZE                        equ 0001h
CRCXORL_XOR1_LENGTH                      equ 0001h
CRCXORL_XOR1_MASK                        equ 0002h
CRCXORL_XOR2_POSN                        equ 0002h
CRCXORL_XOR2_POSITION                    equ 0002h
CRCXORL_XOR2_SIZE                        equ 0001h
CRCXORL_XOR2_LENGTH                      equ 0001h
CRCXORL_XOR2_MASK                        equ 0004h
CRCXORL_XOR3_POSN                        equ 0003h
CRCXORL_XOR3_POSITION                    equ 0003h
CRCXORL_XOR3_SIZE                        equ 0001h
CRCXORL_XOR3_LENGTH                      equ 0001h
CRCXORL_XOR3_MASK                        equ 0008h
CRCXORL_XOR4_POSN                        equ 0004h
CRCXORL_XOR4_POSITION                    equ 0004h
CRCXORL_XOR4_SIZE                        equ 0001h
CRCXORL_XOR4_LENGTH                      equ 0001h
CRCXORL_XOR4_MASK                        equ 0010h
CRCXORL_XOR5_POSN                        equ 0005h
CRCXORL_XOR5_POSITION                    equ 0005h
CRCXORL_XOR5_SIZE                        equ 0001h
CRCXORL_XOR5_LENGTH                      equ 0001h
CRCXORL_XOR5_MASK                        equ 0020h
CRCXORL_XOR6_POSN                        equ 0006h
CRCXORL_XOR6_POSITION                    equ 0006h
CRCXORL_XOR6_SIZE                        equ 0001h
CRCXORL_XOR6_LENGTH                      equ 0001h
CRCXORL_XOR6_MASK                        equ 0040h
CRCXORL_XOR7_POSN                        equ 0007h
CRCXORL_XOR7_POSITION                    equ 0007h
CRCXORL_XOR7_SIZE                        equ 0001h
CRCXORL_XOR7_LENGTH                      equ 0001h
CRCXORL_XOR7_MASK                        equ 0080h

// Register: CRCOUTH
#define CRCOUTH CRCOUTH
CRCOUTH                                  equ 01CA2h
// bitfield definitions
CRCOUTH_OUT_POSN                         equ 0000h
CRCOUTH_OUT_POSITION                     equ 0000h
CRCOUTH_OUT_SIZE                         equ 0008h
CRCOUTH_OUT_LENGTH                       equ 0008h
CRCOUTH_OUT_MASK                         equ 00FFh
CRCOUTH_OUT8_POSN                        equ 0000h
CRCOUTH_OUT8_POSITION                    equ 0000h
CRCOUTH_OUT8_SIZE                        equ 0001h
CRCOUTH_OUT8_LENGTH                      equ 0001h
CRCOUTH_OUT8_MASK                        equ 0001h
CRCOUTH_OUT9_POSN                        equ 0001h
CRCOUTH_OUT9_POSITION                    equ 0001h
CRCOUTH_OUT9_SIZE                        equ 0001h
CRCOUTH_OUT9_LENGTH                      equ 0001h
CRCOUTH_OUT9_MASK                        equ 0002h
CRCOUTH_OUT10_POSN                       equ 0002h
CRCOUTH_OUT10_POSITION                   equ 0002h
CRCOUTH_OUT10_SIZE                       equ 0001h
CRCOUTH_OUT10_LENGTH                     equ 0001h
CRCOUTH_OUT10_MASK                       equ 0004h
CRCOUTH_OUT11_POSN                       equ 0003h
CRCOUTH_OUT11_POSITION                   equ 0003h
CRCOUTH_OUT11_SIZE                       equ 0001h
CRCOUTH_OUT11_LENGTH                     equ 0001h
CRCOUTH_OUT11_MASK                       equ 0008h
CRCOUTH_OUT12_POSN                       equ 0004h
CRCOUTH_OUT12_POSITION                   equ 0004h
CRCOUTH_OUT12_SIZE                       equ 0001h
CRCOUTH_OUT12_LENGTH                     equ 0001h
CRCOUTH_OUT12_MASK                       equ 0010h
CRCOUTH_OUT13_POSN                       equ 0005h
CRCOUTH_OUT13_POSITION                   equ 0005h
CRCOUTH_OUT13_SIZE                       equ 0001h
CRCOUTH_OUT13_LENGTH                     equ 0001h
CRCOUTH_OUT13_MASK                       equ 0020h
CRCOUTH_OUT14_POSN                       equ 0006h
CRCOUTH_OUT14_POSITION                   equ 0006h
CRCOUTH_OUT14_SIZE                       equ 0001h
CRCOUTH_OUT14_LENGTH                     equ 0001h
CRCOUTH_OUT14_MASK                       equ 0040h
CRCOUTH_OUT15_POSN                       equ 0007h
CRCOUTH_OUT15_POSITION                   equ 0007h
CRCOUTH_OUT15_SIZE                       equ 0001h
CRCOUTH_OUT15_LENGTH                     equ 0001h
CRCOUTH_OUT15_MASK                       equ 0080h

// Register: CRCSHFTH
#define CRCSHFTH CRCSHFTH
CRCSHFTH                                 equ 01CA2h
// bitfield definitions
CRCSHFTH_SHIFT_POSN                      equ 0000h
CRCSHFTH_SHIFT_POSITION                  equ 0000h
CRCSHFTH_SHIFT_SIZE                      equ 0008h
CRCSHFTH_SHIFT_LENGTH                    equ 0008h
CRCSHFTH_SHIFT_MASK                      equ 00FFh
CRCSHFTH_SHIFT8_POSN                     equ 0000h
CRCSHFTH_SHIFT8_POSITION                 equ 0000h
CRCSHFTH_SHIFT8_SIZE                     equ 0001h
CRCSHFTH_SHIFT8_LENGTH                   equ 0001h
CRCSHFTH_SHIFT8_MASK                     equ 0001h
CRCSHFTH_SHIFT9_POSN                     equ 0001h
CRCSHFTH_SHIFT9_POSITION                 equ 0001h
CRCSHFTH_SHIFT9_SIZE                     equ 0001h
CRCSHFTH_SHIFT9_LENGTH                   equ 0001h
CRCSHFTH_SHIFT9_MASK                     equ 0002h
CRCSHFTH_SHIFT10_POSN                    equ 0002h
CRCSHFTH_SHIFT10_POSITION                equ 0002h
CRCSHFTH_SHIFT10_SIZE                    equ 0001h
CRCSHFTH_SHIFT10_LENGTH                  equ 0001h
CRCSHFTH_SHIFT10_MASK                    equ 0004h
CRCSHFTH_SHIFT11_POSN                    equ 0003h
CRCSHFTH_SHIFT11_POSITION                equ 0003h
CRCSHFTH_SHIFT11_SIZE                    equ 0001h
CRCSHFTH_SHIFT11_LENGTH                  equ 0001h
CRCSHFTH_SHIFT11_MASK                    equ 0008h
CRCSHFTH_SHIFT12_POSN                    equ 0004h
CRCSHFTH_SHIFT12_POSITION                equ 0004h
CRCSHFTH_SHIFT12_SIZE                    equ 0001h
CRCSHFTH_SHIFT12_LENGTH                  equ 0001h
CRCSHFTH_SHIFT12_MASK                    equ 0010h
CRCSHFTH_SHIFT13_POSN                    equ 0005h
CRCSHFTH_SHIFT13_POSITION                equ 0005h
CRCSHFTH_SHIFT13_SIZE                    equ 0001h
CRCSHFTH_SHIFT13_LENGTH                  equ 0001h
CRCSHFTH_SHIFT13_MASK                    equ 0020h
CRCSHFTH_SHIFT14_POSN                    equ 0006h
CRCSHFTH_SHIFT14_POSITION                equ 0006h
CRCSHFTH_SHIFT14_SIZE                    equ 0001h
CRCSHFTH_SHIFT14_LENGTH                  equ 0001h
CRCSHFTH_SHIFT14_MASK                    equ 0040h
CRCSHFTH_SHIFT15_POSN                    equ 0007h
CRCSHFTH_SHIFT15_POSITION                equ 0007h
CRCSHFTH_SHIFT15_SIZE                    equ 0001h
CRCSHFTH_SHIFT15_LENGTH                  equ 0001h
CRCSHFTH_SHIFT15_MASK                    equ 0080h

// Register: CRCXORH
#define CRCXORH CRCXORH
CRCXORH                                  equ 01CA2h
// bitfield definitions
CRCXORH_XOR_POSN                         equ 0000h
CRCXORH_XOR_POSITION                     equ 0000h
CRCXORH_XOR_SIZE                         equ 0008h
CRCXORH_XOR_LENGTH                       equ 0008h
CRCXORH_XOR_MASK                         equ 00FFh
CRCXORH_XOR8_POSN                        equ 0000h
CRCXORH_XOR8_POSITION                    equ 0000h
CRCXORH_XOR8_SIZE                        equ 0001h
CRCXORH_XOR8_LENGTH                      equ 0001h
CRCXORH_XOR8_MASK                        equ 0001h
CRCXORH_XOR9_POSN                        equ 0001h
CRCXORH_XOR9_POSITION                    equ 0001h
CRCXORH_XOR9_SIZE                        equ 0001h
CRCXORH_XOR9_LENGTH                      equ 0001h
CRCXORH_XOR9_MASK                        equ 0002h
CRCXORH_XOR10_POSN                       equ 0002h
CRCXORH_XOR10_POSITION                   equ 0002h
CRCXORH_XOR10_SIZE                       equ 0001h
CRCXORH_XOR10_LENGTH                     equ 0001h
CRCXORH_XOR10_MASK                       equ 0004h
CRCXORH_XOR11_POSN                       equ 0003h
CRCXORH_XOR11_POSITION                   equ 0003h
CRCXORH_XOR11_SIZE                       equ 0001h
CRCXORH_XOR11_LENGTH                     equ 0001h
CRCXORH_XOR11_MASK                       equ 0008h
CRCXORH_XOR12_POSN                       equ 0004h
CRCXORH_XOR12_POSITION                   equ 0004h
CRCXORH_XOR12_SIZE                       equ 0001h
CRCXORH_XOR12_LENGTH                     equ 0001h
CRCXORH_XOR12_MASK                       equ 0010h
CRCXORH_XOR13_POSN                       equ 0005h
CRCXORH_XOR13_POSITION                   equ 0005h
CRCXORH_XOR13_SIZE                       equ 0001h
CRCXORH_XOR13_LENGTH                     equ 0001h
CRCXORH_XOR13_MASK                       equ 0020h
CRCXORH_XOR14_POSN                       equ 0006h
CRCXORH_XOR14_POSITION                   equ 0006h
CRCXORH_XOR14_SIZE                       equ 0001h
CRCXORH_XOR14_LENGTH                     equ 0001h
CRCXORH_XOR14_MASK                       equ 0040h
CRCXORH_XOR15_POSN                       equ 0007h
CRCXORH_XOR15_POSITION                   equ 0007h
CRCXORH_XOR15_SIZE                       equ 0001h
CRCXORH_XOR15_LENGTH                     equ 0001h
CRCXORH_XOR15_MASK                       equ 0080h

// Register: CRCOUTU
#define CRCOUTU CRCOUTU
CRCOUTU                                  equ 01CA3h
// bitfield definitions
CRCOUTU_OUT_POSN                         equ 0000h
CRCOUTU_OUT_POSITION                     equ 0000h
CRCOUTU_OUT_SIZE                         equ 0008h
CRCOUTU_OUT_LENGTH                       equ 0008h
CRCOUTU_OUT_MASK                         equ 00FFh
CRCOUTU_OUT16_POSN                       equ 0000h
CRCOUTU_OUT16_POSITION                   equ 0000h
CRCOUTU_OUT16_SIZE                       equ 0001h
CRCOUTU_OUT16_LENGTH                     equ 0001h
CRCOUTU_OUT16_MASK                       equ 0001h
CRCOUTU_OUT17_POSN                       equ 0001h
CRCOUTU_OUT17_POSITION                   equ 0001h
CRCOUTU_OUT17_SIZE                       equ 0001h
CRCOUTU_OUT17_LENGTH                     equ 0001h
CRCOUTU_OUT17_MASK                       equ 0002h
CRCOUTU_OUT18_POSN                       equ 0002h
CRCOUTU_OUT18_POSITION                   equ 0002h
CRCOUTU_OUT18_SIZE                       equ 0001h
CRCOUTU_OUT18_LENGTH                     equ 0001h
CRCOUTU_OUT18_MASK                       equ 0004h
CRCOUTU_OUT19_POSN                       equ 0003h
CRCOUTU_OUT19_POSITION                   equ 0003h
CRCOUTU_OUT19_SIZE                       equ 0001h
CRCOUTU_OUT19_LENGTH                     equ 0001h
CRCOUTU_OUT19_MASK                       equ 0008h
CRCOUTU_OUT20_POSN                       equ 0004h
CRCOUTU_OUT20_POSITION                   equ 0004h
CRCOUTU_OUT20_SIZE                       equ 0001h
CRCOUTU_OUT20_LENGTH                     equ 0001h
CRCOUTU_OUT20_MASK                       equ 0010h
CRCOUTU_OUT21_POSN                       equ 0005h
CRCOUTU_OUT21_POSITION                   equ 0005h
CRCOUTU_OUT21_SIZE                       equ 0001h
CRCOUTU_OUT21_LENGTH                     equ 0001h
CRCOUTU_OUT21_MASK                       equ 0020h
CRCOUTU_OUT22_POSN                       equ 0006h
CRCOUTU_OUT22_POSITION                   equ 0006h
CRCOUTU_OUT22_SIZE                       equ 0001h
CRCOUTU_OUT22_LENGTH                     equ 0001h
CRCOUTU_OUT22_MASK                       equ 0040h
CRCOUTU_OUT23_POSN                       equ 0007h
CRCOUTU_OUT23_POSITION                   equ 0007h
CRCOUTU_OUT23_SIZE                       equ 0001h
CRCOUTU_OUT23_LENGTH                     equ 0001h
CRCOUTU_OUT23_MASK                       equ 0080h

// Register: CRCSHFTU
#define CRCSHFTU CRCSHFTU
CRCSHFTU                                 equ 01CA3h
// bitfield definitions
CRCSHFTU_SHIFT_POSN                      equ 0000h
CRCSHFTU_SHIFT_POSITION                  equ 0000h
CRCSHFTU_SHIFT_SIZE                      equ 0008h
CRCSHFTU_SHIFT_LENGTH                    equ 0008h
CRCSHFTU_SHIFT_MASK                      equ 00FFh
CRCSHFTU_SHIFT16_POSN                    equ 0000h
CRCSHFTU_SHIFT16_POSITION                equ 0000h
CRCSHFTU_SHIFT16_SIZE                    equ 0001h
CRCSHFTU_SHIFT16_LENGTH                  equ 0001h
CRCSHFTU_SHIFT16_MASK                    equ 0001h
CRCSHFTU_SHIFT17_POSN                    equ 0001h
CRCSHFTU_SHIFT17_POSITION                equ 0001h
CRCSHFTU_SHIFT17_SIZE                    equ 0001h
CRCSHFTU_SHIFT17_LENGTH                  equ 0001h
CRCSHFTU_SHIFT17_MASK                    equ 0002h
CRCSHFTU_SHIFT18_POSN                    equ 0002h
CRCSHFTU_SHIFT18_POSITION                equ 0002h
CRCSHFTU_SHIFT18_SIZE                    equ 0001h
CRCSHFTU_SHIFT18_LENGTH                  equ 0001h
CRCSHFTU_SHIFT18_MASK                    equ 0004h
CRCSHFTU_SHIFT19_POSN                    equ 0003h
CRCSHFTU_SHIFT19_POSITION                equ 0003h
CRCSHFTU_SHIFT19_SIZE                    equ 0001h
CRCSHFTU_SHIFT19_LENGTH                  equ 0001h
CRCSHFTU_SHIFT19_MASK                    equ 0008h
CRCSHFTU_SHIFT20_POSN                    equ 0004h
CRCSHFTU_SHIFT20_POSITION                equ 0004h
CRCSHFTU_SHIFT20_SIZE                    equ 0001h
CRCSHFTU_SHIFT20_LENGTH                  equ 0001h
CRCSHFTU_SHIFT20_MASK                    equ 0010h
CRCSHFTU_SHIFT21_POSN                    equ 0005h
CRCSHFTU_SHIFT21_POSITION                equ 0005h
CRCSHFTU_SHIFT21_SIZE                    equ 0001h
CRCSHFTU_SHIFT21_LENGTH                  equ 0001h
CRCSHFTU_SHIFT21_MASK                    equ 0020h
CRCSHFTU_SHIFT22_POSN                    equ 0006h
CRCSHFTU_SHIFT22_POSITION                equ 0006h
CRCSHFTU_SHIFT22_SIZE                    equ 0001h
CRCSHFTU_SHIFT22_LENGTH                  equ 0001h
CRCSHFTU_SHIFT22_MASK                    equ 0040h
CRCSHFTU_SHIFT23_POSN                    equ 0007h
CRCSHFTU_SHIFT23_POSITION                equ 0007h
CRCSHFTU_SHIFT23_SIZE                    equ 0001h
CRCSHFTU_SHIFT23_LENGTH                  equ 0001h
CRCSHFTU_SHIFT23_MASK                    equ 0080h

// Register: CRCXORU
#define CRCXORU CRCXORU
CRCXORU                                  equ 01CA3h
// bitfield definitions
CRCXORU_XOR_POSN                         equ 0000h
CRCXORU_XOR_POSITION                     equ 0000h
CRCXORU_XOR_SIZE                         equ 0008h
CRCXORU_XOR_LENGTH                       equ 0008h
CRCXORU_XOR_MASK                         equ 00FFh
CRCXORU_XOR16_POSN                       equ 0000h
CRCXORU_XOR16_POSITION                   equ 0000h
CRCXORU_XOR16_SIZE                       equ 0001h
CRCXORU_XOR16_LENGTH                     equ 0001h
CRCXORU_XOR16_MASK                       equ 0001h
CRCXORU_XOR17_POSN                       equ 0001h
CRCXORU_XOR17_POSITION                   equ 0001h
CRCXORU_XOR17_SIZE                       equ 0001h
CRCXORU_XOR17_LENGTH                     equ 0001h
CRCXORU_XOR17_MASK                       equ 0002h
CRCXORU_XOR18_POSN                       equ 0002h
CRCXORU_XOR18_POSITION                   equ 0002h
CRCXORU_XOR18_SIZE                       equ 0001h
CRCXORU_XOR18_LENGTH                     equ 0001h
CRCXORU_XOR18_MASK                       equ 0004h
CRCXORU_XOR19_POSN                       equ 0003h
CRCXORU_XOR19_POSITION                   equ 0003h
CRCXORU_XOR19_SIZE                       equ 0001h
CRCXORU_XOR19_LENGTH                     equ 0001h
CRCXORU_XOR19_MASK                       equ 0008h
CRCXORU_XOR20_POSN                       equ 0004h
CRCXORU_XOR20_POSITION                   equ 0004h
CRCXORU_XOR20_SIZE                       equ 0001h
CRCXORU_XOR20_LENGTH                     equ 0001h
CRCXORU_XOR20_MASK                       equ 0010h
CRCXORU_XOR21_POSN                       equ 0005h
CRCXORU_XOR21_POSITION                   equ 0005h
CRCXORU_XOR21_SIZE                       equ 0001h
CRCXORU_XOR21_LENGTH                     equ 0001h
CRCXORU_XOR21_MASK                       equ 0020h
CRCXORU_XOR22_POSN                       equ 0006h
CRCXORU_XOR22_POSITION                   equ 0006h
CRCXORU_XOR22_SIZE                       equ 0001h
CRCXORU_XOR22_LENGTH                     equ 0001h
CRCXORU_XOR22_MASK                       equ 0040h
CRCXORU_XOR23_POSN                       equ 0007h
CRCXORU_XOR23_POSITION                   equ 0007h
CRCXORU_XOR23_SIZE                       equ 0001h
CRCXORU_XOR23_LENGTH                     equ 0001h
CRCXORU_XOR23_MASK                       equ 0080h

// Register: CRCOUTT
#define CRCOUTT CRCOUTT
CRCOUTT                                  equ 01CA4h
// bitfield definitions
CRCOUTT_OUT_POSN                         equ 0000h
CRCOUTT_OUT_POSITION                     equ 0000h
CRCOUTT_OUT_SIZE                         equ 0008h
CRCOUTT_OUT_LENGTH                       equ 0008h
CRCOUTT_OUT_MASK                         equ 00FFh
CRCOUTT_OUT24_POSN                       equ 0000h
CRCOUTT_OUT24_POSITION                   equ 0000h
CRCOUTT_OUT24_SIZE                       equ 0001h
CRCOUTT_OUT24_LENGTH                     equ 0001h
CRCOUTT_OUT24_MASK                       equ 0001h
CRCOUTT_OUT25_POSN                       equ 0001h
CRCOUTT_OUT25_POSITION                   equ 0001h
CRCOUTT_OUT25_SIZE                       equ 0001h
CRCOUTT_OUT25_LENGTH                     equ 0001h
CRCOUTT_OUT25_MASK                       equ 0002h
CRCOUTT_OUT26_POSN                       equ 0002h
CRCOUTT_OUT26_POSITION                   equ 0002h
CRCOUTT_OUT26_SIZE                       equ 0001h
CRCOUTT_OUT26_LENGTH                     equ 0001h
CRCOUTT_OUT26_MASK                       equ 0004h
CRCOUTT_OUT27_POSN                       equ 0003h
CRCOUTT_OUT27_POSITION                   equ 0003h
CRCOUTT_OUT27_SIZE                       equ 0001h
CRCOUTT_OUT27_LENGTH                     equ 0001h
CRCOUTT_OUT27_MASK                       equ 0008h
CRCOUTT_OUT28_POSN                       equ 0004h
CRCOUTT_OUT28_POSITION                   equ 0004h
CRCOUTT_OUT28_SIZE                       equ 0001h
CRCOUTT_OUT28_LENGTH                     equ 0001h
CRCOUTT_OUT28_MASK                       equ 0010h
CRCOUTT_OUT29_POSN                       equ 0005h
CRCOUTT_OUT29_POSITION                   equ 0005h
CRCOUTT_OUT29_SIZE                       equ 0001h
CRCOUTT_OUT29_LENGTH                     equ 0001h
CRCOUTT_OUT29_MASK                       equ 0020h
CRCOUTT_OUT30_POSN                       equ 0006h
CRCOUTT_OUT30_POSITION                   equ 0006h
CRCOUTT_OUT30_SIZE                       equ 0001h
CRCOUTT_OUT30_LENGTH                     equ 0001h
CRCOUTT_OUT30_MASK                       equ 0040h
CRCOUTT_OUT31_POSN                       equ 0007h
CRCOUTT_OUT31_POSITION                   equ 0007h
CRCOUTT_OUT31_SIZE                       equ 0001h
CRCOUTT_OUT31_LENGTH                     equ 0001h
CRCOUTT_OUT31_MASK                       equ 0080h

// Register: CRCSHFTT
#define CRCSHFTT CRCSHFTT
CRCSHFTT                                 equ 01CA4h
// bitfield definitions
CRCSHFTT_SHIFT_POSN                      equ 0000h
CRCSHFTT_SHIFT_POSITION                  equ 0000h
CRCSHFTT_SHIFT_SIZE                      equ 0008h
CRCSHFTT_SHIFT_LENGTH                    equ 0008h
CRCSHFTT_SHIFT_MASK                      equ 00FFh
CRCSHFTT_SHIFT24_POSN                    equ 0000h
CRCSHFTT_SHIFT24_POSITION                equ 0000h
CRCSHFTT_SHIFT24_SIZE                    equ 0001h
CRCSHFTT_SHIFT24_LENGTH                  equ 0001h
CRCSHFTT_SHIFT24_MASK                    equ 0001h
CRCSHFTT_SHIFT25_POSN                    equ 0001h
CRCSHFTT_SHIFT25_POSITION                equ 0001h
CRCSHFTT_SHIFT25_SIZE                    equ 0001h
CRCSHFTT_SHIFT25_LENGTH                  equ 0001h
CRCSHFTT_SHIFT25_MASK                    equ 0002h
CRCSHFTT_SHIFT26_POSN                    equ 0002h
CRCSHFTT_SHIFT26_POSITION                equ 0002h
CRCSHFTT_SHIFT26_SIZE                    equ 0001h
CRCSHFTT_SHIFT26_LENGTH                  equ 0001h
CRCSHFTT_SHIFT26_MASK                    equ 0004h
CRCSHFTT_SHIFT27_POSN                    equ 0003h
CRCSHFTT_SHIFT27_POSITION                equ 0003h
CRCSHFTT_SHIFT27_SIZE                    equ 0001h
CRCSHFTT_SHIFT27_LENGTH                  equ 0001h
CRCSHFTT_SHIFT27_MASK                    equ 0008h
CRCSHFTT_SHIFT28_POSN                    equ 0004h
CRCSHFTT_SHIFT28_POSITION                equ 0004h
CRCSHFTT_SHIFT28_SIZE                    equ 0001h
CRCSHFTT_SHIFT28_LENGTH                  equ 0001h
CRCSHFTT_SHIFT28_MASK                    equ 0010h
CRCSHFTT_SHIFT29_POSN                    equ 0005h
CRCSHFTT_SHIFT29_POSITION                equ 0005h
CRCSHFTT_SHIFT29_SIZE                    equ 0001h
CRCSHFTT_SHIFT29_LENGTH                  equ 0001h
CRCSHFTT_SHIFT29_MASK                    equ 0020h
CRCSHFTT_SHIFT30_POSN                    equ 0006h
CRCSHFTT_SHIFT30_POSITION                equ 0006h
CRCSHFTT_SHIFT30_SIZE                    equ 0001h
CRCSHFTT_SHIFT30_LENGTH                  equ 0001h
CRCSHFTT_SHIFT30_MASK                    equ 0040h
CRCSHFTT_SHIFT31_POSN                    equ 0007h
CRCSHFTT_SHIFT31_POSITION                equ 0007h
CRCSHFTT_SHIFT31_SIZE                    equ 0001h
CRCSHFTT_SHIFT31_LENGTH                  equ 0001h
CRCSHFTT_SHIFT31_MASK                    equ 0080h

// Register: CRCXORT
#define CRCXORT CRCXORT
CRCXORT                                  equ 01CA4h
// bitfield definitions
CRCXORT_XOR_POSN                         equ 0000h
CRCXORT_XOR_POSITION                     equ 0000h
CRCXORT_XOR_SIZE                         equ 0008h
CRCXORT_XOR_LENGTH                       equ 0008h
CRCXORT_XOR_MASK                         equ 00FFh
CRCXORT_XOR24_POSN                       equ 0000h
CRCXORT_XOR24_POSITION                   equ 0000h
CRCXORT_XOR24_SIZE                       equ 0001h
CRCXORT_XOR24_LENGTH                     equ 0001h
CRCXORT_XOR24_MASK                       equ 0001h
CRCXORT_XOR25_POSN                       equ 0001h
CRCXORT_XOR25_POSITION                   equ 0001h
CRCXORT_XOR25_SIZE                       equ 0001h
CRCXORT_XOR25_LENGTH                     equ 0001h
CRCXORT_XOR25_MASK                       equ 0002h
CRCXORT_XOR26_POSN                       equ 0002h
CRCXORT_XOR26_POSITION                   equ 0002h
CRCXORT_XOR26_SIZE                       equ 0001h
CRCXORT_XOR26_LENGTH                     equ 0001h
CRCXORT_XOR26_MASK                       equ 0004h
CRCXORT_XOR27_POSN                       equ 0003h
CRCXORT_XOR27_POSITION                   equ 0003h
CRCXORT_XOR27_SIZE                       equ 0001h
CRCXORT_XOR27_LENGTH                     equ 0001h
CRCXORT_XOR27_MASK                       equ 0008h
CRCXORT_XOR28_POSN                       equ 0004h
CRCXORT_XOR28_POSITION                   equ 0004h
CRCXORT_XOR28_SIZE                       equ 0001h
CRCXORT_XOR28_LENGTH                     equ 0001h
CRCXORT_XOR28_MASK                       equ 0010h
CRCXORT_XOR29_POSN                       equ 0005h
CRCXORT_XOR29_POSITION                   equ 0005h
CRCXORT_XOR29_SIZE                       equ 0001h
CRCXORT_XOR29_LENGTH                     equ 0001h
CRCXORT_XOR29_MASK                       equ 0020h
CRCXORT_XOR30_POSN                       equ 0006h
CRCXORT_XOR30_POSITION                   equ 0006h
CRCXORT_XOR30_SIZE                       equ 0001h
CRCXORT_XOR30_LENGTH                     equ 0001h
CRCXORT_XOR30_MASK                       equ 0040h
CRCXORT_XOR31_POSN                       equ 0007h
CRCXORT_XOR31_POSITION                   equ 0007h
CRCXORT_XOR31_SIZE                       equ 0001h
CRCXORT_XOR31_LENGTH                     equ 0001h
CRCXORT_XOR31_MASK                       equ 0080h

// Register: CRCCON0
#define CRCCON0 CRCCON0
CRCCON0                                  equ 01CA5h
// bitfield definitions
CRCCON0_FULL_POSN                        equ 0000h
CRCCON0_FULL_POSITION                    equ 0000h
CRCCON0_FULL_SIZE                        equ 0001h
CRCCON0_FULL_LENGTH                      equ 0001h
CRCCON0_FULL_MASK                        equ 0001h
CRCCON0_SHIFTM_POSN                      equ 0001h
CRCCON0_SHIFTM_POSITION                  equ 0001h
CRCCON0_SHIFTM_SIZE                      equ 0001h
CRCCON0_SHIFTM_LENGTH                    equ 0001h
CRCCON0_SHIFTM_MASK                      equ 0002h
CRCCON0_SETUP_POSN                       equ 0002h
CRCCON0_SETUP_POSITION                   equ 0002h
CRCCON0_SETUP_SIZE                       equ 0002h
CRCCON0_SETUP_LENGTH                     equ 0002h
CRCCON0_SETUP_MASK                       equ 000Ch
CRCCON0_ACCMOD_POSN                      equ 0004h
CRCCON0_ACCMOD_POSITION                  equ 0004h
CRCCON0_ACCMOD_SIZE                      equ 0001h
CRCCON0_ACCMOD_LENGTH                    equ 0001h
CRCCON0_ACCMOD_MASK                      equ 0010h
CRCCON0_CRCBUSY_POSN                     equ 0005h
CRCCON0_CRCBUSY_POSITION                 equ 0005h
CRCCON0_CRCBUSY_SIZE                     equ 0001h
CRCCON0_CRCBUSY_LENGTH                   equ 0001h
CRCCON0_CRCBUSY_MASK                     equ 0020h
CRCCON0_CRCGO_POSN                       equ 0006h
CRCCON0_CRCGO_POSITION                   equ 0006h
CRCCON0_CRCGO_SIZE                       equ 0001h
CRCCON0_CRCGO_LENGTH                     equ 0001h
CRCCON0_CRCGO_MASK                       equ 0040h
CRCCON0_CRCEN_POSN                       equ 0007h
CRCCON0_CRCEN_POSITION                   equ 0007h
CRCCON0_CRCEN_SIZE                       equ 0001h
CRCCON0_CRCEN_LENGTH                     equ 0001h
CRCCON0_CRCEN_MASK                       equ 0080h
CRCCON0_LENDIAN_POSN                     equ 0001h
CRCCON0_LENDIAN_POSITION                 equ 0001h
CRCCON0_LENDIAN_SIZE                     equ 0001h
CRCCON0_LENDIAN_LENGTH                   equ 0001h
CRCCON0_LENDIAN_MASK                     equ 0002h
CRCCON0_SETUP0_POSN                      equ 0002h
CRCCON0_SETUP0_POSITION                  equ 0002h
CRCCON0_SETUP0_SIZE                      equ 0001h
CRCCON0_SETUP0_LENGTH                    equ 0001h
CRCCON0_SETUP0_MASK                      equ 0004h
CRCCON0_SETUP1_POSN                      equ 0003h
CRCCON0_SETUP1_POSITION                  equ 0003h
CRCCON0_SETUP1_SIZE                      equ 0001h
CRCCON0_SETUP1_LENGTH                    equ 0001h
CRCCON0_SETUP1_MASK                      equ 0008h
CRCCON0_ACCM_POSN                        equ 0004h
CRCCON0_ACCM_POSITION                    equ 0004h
CRCCON0_ACCM_SIZE                        equ 0001h
CRCCON0_ACCM_LENGTH                      equ 0001h
CRCCON0_ACCM_MASK                        equ 0010h
CRCCON0_BUSY_POSN                        equ 0005h
CRCCON0_BUSY_POSITION                    equ 0005h
CRCCON0_BUSY_SIZE                        equ 0001h
CRCCON0_BUSY_LENGTH                      equ 0001h
CRCCON0_BUSY_MASK                        equ 0020h
CRCCON0_GO_POSN                          equ 0006h
CRCCON0_GO_POSITION                      equ 0006h
CRCCON0_GO_SIZE                          equ 0001h
CRCCON0_GO_LENGTH                        equ 0001h
CRCCON0_GO_MASK                          equ 0040h
CRCCON0_EN_POSN                          equ 0007h
CRCCON0_EN_POSITION                      equ 0007h
CRCCON0_EN_SIZE                          equ 0001h
CRCCON0_EN_LENGTH                        equ 0001h
CRCCON0_EN_MASK                          equ 0080h

// Register: CRCCON1
#define CRCCON1 CRCCON1
CRCCON1                                  equ 01CA6h
// bitfield definitions
CRCCON1_PLEN_POSN                        equ 0000h
CRCCON1_PLEN_POSITION                    equ 0000h
CRCCON1_PLEN_SIZE                        equ 0005h
CRCCON1_PLEN_LENGTH                      equ 0005h
CRCCON1_PLEN_MASK                        equ 001Fh
CRCCON1_PLEN0_POSN                       equ 0000h
CRCCON1_PLEN0_POSITION                   equ 0000h
CRCCON1_PLEN0_SIZE                       equ 0001h
CRCCON1_PLEN0_LENGTH                     equ 0001h
CRCCON1_PLEN0_MASK                       equ 0001h
CRCCON1_PLEN1_POSN                       equ 0001h
CRCCON1_PLEN1_POSITION                   equ 0001h
CRCCON1_PLEN1_SIZE                       equ 0001h
CRCCON1_PLEN1_LENGTH                     equ 0001h
CRCCON1_PLEN1_MASK                       equ 0002h
CRCCON1_PLEN2_POSN                       equ 0002h
CRCCON1_PLEN2_POSITION                   equ 0002h
CRCCON1_PLEN2_SIZE                       equ 0001h
CRCCON1_PLEN2_LENGTH                     equ 0001h
CRCCON1_PLEN2_MASK                       equ 0004h
CRCCON1_PLEN3_POSN                       equ 0003h
CRCCON1_PLEN3_POSITION                   equ 0003h
CRCCON1_PLEN3_SIZE                       equ 0001h
CRCCON1_PLEN3_LENGTH                     equ 0001h
CRCCON1_PLEN3_MASK                       equ 0008h
CRCCON1_PLEN4_POSN                       equ 0004h
CRCCON1_PLEN4_POSITION                   equ 0004h
CRCCON1_PLEN4_SIZE                       equ 0001h
CRCCON1_PLEN4_LENGTH                     equ 0001h
CRCCON1_PLEN4_MASK                       equ 0010h

// Register: CRCCON2
#define CRCCON2 CRCCON2
CRCCON2                                  equ 01CA7h
// bitfield definitions
CRCCON2_DLEN_POSN                        equ 0000h
CRCCON2_DLEN_POSITION                    equ 0000h
CRCCON2_DLEN_SIZE                        equ 0005h
CRCCON2_DLEN_LENGTH                      equ 0005h
CRCCON2_DLEN_MASK                        equ 001Fh
CRCCON2_DLEN0_POSN                       equ 0000h
CRCCON2_DLEN0_POSITION                   equ 0000h
CRCCON2_DLEN0_SIZE                       equ 0001h
CRCCON2_DLEN0_LENGTH                     equ 0001h
CRCCON2_DLEN0_MASK                       equ 0001h
CRCCON2_DLEN1_POSN                       equ 0001h
CRCCON2_DLEN1_POSITION                   equ 0001h
CRCCON2_DLEN1_SIZE                       equ 0001h
CRCCON2_DLEN1_LENGTH                     equ 0001h
CRCCON2_DLEN1_MASK                       equ 0002h
CRCCON2_DLEN2_POSN                       equ 0002h
CRCCON2_DLEN2_POSITION                   equ 0002h
CRCCON2_DLEN2_SIZE                       equ 0001h
CRCCON2_DLEN2_LENGTH                     equ 0001h
CRCCON2_DLEN2_MASK                       equ 0004h
CRCCON2_DLEN3_POSN                       equ 0003h
CRCCON2_DLEN3_POSITION                   equ 0003h
CRCCON2_DLEN3_SIZE                       equ 0001h
CRCCON2_DLEN3_LENGTH                     equ 0001h
CRCCON2_DLEN3_MASK                       equ 0008h
CRCCON2_DLEN4_POSN                       equ 0004h
CRCCON2_DLEN4_POSITION                   equ 0004h
CRCCON2_DLEN4_SIZE                       equ 0001h
CRCCON2_DLEN4_LENGTH                     equ 0001h
CRCCON2_DLEN4_MASK                       equ 0010h

// Register: ADLTHL
#define ADLTHL ADLTHL
ADLTHL                                   equ 01D0Ch
// bitfield definitions
ADLTHL_LTH_POSN                          equ 0000h
ADLTHL_LTH_POSITION                      equ 0000h
ADLTHL_LTH_SIZE                          equ 0008h
ADLTHL_LTH_LENGTH                        equ 0008h
ADLTHL_LTH_MASK                          equ 00FFh
ADLTHL_ADLTH0_POSN                       equ 0000h
ADLTHL_ADLTH0_POSITION                   equ 0000h
ADLTHL_ADLTH0_SIZE                       equ 0001h
ADLTHL_ADLTH0_LENGTH                     equ 0001h
ADLTHL_ADLTH0_MASK                       equ 0001h
ADLTHL_ADLTH1_POSN                       equ 0001h
ADLTHL_ADLTH1_POSITION                   equ 0001h
ADLTHL_ADLTH1_SIZE                       equ 0001h
ADLTHL_ADLTH1_LENGTH                     equ 0001h
ADLTHL_ADLTH1_MASK                       equ 0002h
ADLTHL_ADLTH2_POSN                       equ 0002h
ADLTHL_ADLTH2_POSITION                   equ 0002h
ADLTHL_ADLTH2_SIZE                       equ 0001h
ADLTHL_ADLTH2_LENGTH                     equ 0001h
ADLTHL_ADLTH2_MASK                       equ 0004h
ADLTHL_ADLTH3_POSN                       equ 0003h
ADLTHL_ADLTH3_POSITION                   equ 0003h
ADLTHL_ADLTH3_SIZE                       equ 0001h
ADLTHL_ADLTH3_LENGTH                     equ 0001h
ADLTHL_ADLTH3_MASK                       equ 0008h
ADLTHL_ADLTH4_POSN                       equ 0004h
ADLTHL_ADLTH4_POSITION                   equ 0004h
ADLTHL_ADLTH4_SIZE                       equ 0001h
ADLTHL_ADLTH4_LENGTH                     equ 0001h
ADLTHL_ADLTH4_MASK                       equ 0010h
ADLTHL_ADLTH5_POSN                       equ 0005h
ADLTHL_ADLTH5_POSITION                   equ 0005h
ADLTHL_ADLTH5_SIZE                       equ 0001h
ADLTHL_ADLTH5_LENGTH                     equ 0001h
ADLTHL_ADLTH5_MASK                       equ 0020h
ADLTHL_ADLTH6_POSN                       equ 0006h
ADLTHL_ADLTH6_POSITION                   equ 0006h
ADLTHL_ADLTH6_SIZE                       equ 0001h
ADLTHL_ADLTH6_LENGTH                     equ 0001h
ADLTHL_ADLTH6_MASK                       equ 0040h
ADLTHL_ADLTH7_POSN                       equ 0007h
ADLTHL_ADLTH7_POSITION                   equ 0007h
ADLTHL_ADLTH7_SIZE                       equ 0001h
ADLTHL_ADLTH7_LENGTH                     equ 0001h
ADLTHL_ADLTH7_MASK                       equ 0080h
ADLTHL_ADLTH_POSN                        equ 0000h
ADLTHL_ADLTH_POSITION                    equ 0000h
ADLTHL_ADLTH_SIZE                        equ 0008h
ADLTHL_ADLTH_LENGTH                      equ 0008h
ADLTHL_ADLTH_MASK                        equ 00FFh
ADLTHL_LTH0_POSN                         equ 0000h
ADLTHL_LTH0_POSITION                     equ 0000h
ADLTHL_LTH0_SIZE                         equ 0001h
ADLTHL_LTH0_LENGTH                       equ 0001h
ADLTHL_LTH0_MASK                         equ 0001h
ADLTHL_LTH1_POSN                         equ 0001h
ADLTHL_LTH1_POSITION                     equ 0001h
ADLTHL_LTH1_SIZE                         equ 0001h
ADLTHL_LTH1_LENGTH                       equ 0001h
ADLTHL_LTH1_MASK                         equ 0002h
ADLTHL_LTH2_POSN                         equ 0002h
ADLTHL_LTH2_POSITION                     equ 0002h
ADLTHL_LTH2_SIZE                         equ 0001h
ADLTHL_LTH2_LENGTH                       equ 0001h
ADLTHL_LTH2_MASK                         equ 0004h
ADLTHL_LTH3_POSN                         equ 0003h
ADLTHL_LTH3_POSITION                     equ 0003h
ADLTHL_LTH3_SIZE                         equ 0001h
ADLTHL_LTH3_LENGTH                       equ 0001h
ADLTHL_LTH3_MASK                         equ 0008h
ADLTHL_LTH4_POSN                         equ 0004h
ADLTHL_LTH4_POSITION                     equ 0004h
ADLTHL_LTH4_SIZE                         equ 0001h
ADLTHL_LTH4_LENGTH                       equ 0001h
ADLTHL_LTH4_MASK                         equ 0010h
ADLTHL_LTH5_POSN                         equ 0005h
ADLTHL_LTH5_POSITION                     equ 0005h
ADLTHL_LTH5_SIZE                         equ 0001h
ADLTHL_LTH5_LENGTH                       equ 0001h
ADLTHL_LTH5_MASK                         equ 0020h
ADLTHL_LTH6_POSN                         equ 0006h
ADLTHL_LTH6_POSITION                     equ 0006h
ADLTHL_LTH6_SIZE                         equ 0001h
ADLTHL_LTH6_LENGTH                       equ 0001h
ADLTHL_LTH6_MASK                         equ 0040h
ADLTHL_LTH7_POSN                         equ 0007h
ADLTHL_LTH7_POSITION                     equ 0007h
ADLTHL_LTH7_SIZE                         equ 0001h
ADLTHL_LTH7_LENGTH                       equ 0001h
ADLTHL_LTH7_MASK                         equ 0080h

// Register: ADLTHH
#define ADLTHH ADLTHH
ADLTHH                                   equ 01D0Dh
// bitfield definitions
ADLTHH_LTH_POSN                          equ 0000h
ADLTHH_LTH_POSITION                      equ 0000h
ADLTHH_LTH_SIZE                          equ 0008h
ADLTHH_LTH_LENGTH                        equ 0008h
ADLTHH_LTH_MASK                          equ 00FFh
ADLTHH_ADLTH8_POSN                       equ 0000h
ADLTHH_ADLTH8_POSITION                   equ 0000h
ADLTHH_ADLTH8_SIZE                       equ 0001h
ADLTHH_ADLTH8_LENGTH                     equ 0001h
ADLTHH_ADLTH8_MASK                       equ 0001h
ADLTHH_ADLTH9_POSN                       equ 0001h
ADLTHH_ADLTH9_POSITION                   equ 0001h
ADLTHH_ADLTH9_SIZE                       equ 0001h
ADLTHH_ADLTH9_LENGTH                     equ 0001h
ADLTHH_ADLTH9_MASK                       equ 0002h
ADLTHH_ADLTH10_POSN                      equ 0002h
ADLTHH_ADLTH10_POSITION                  equ 0002h
ADLTHH_ADLTH10_SIZE                      equ 0001h
ADLTHH_ADLTH10_LENGTH                    equ 0001h
ADLTHH_ADLTH10_MASK                      equ 0004h
ADLTHH_ADLTH11_POSN                      equ 0003h
ADLTHH_ADLTH11_POSITION                  equ 0003h
ADLTHH_ADLTH11_SIZE                      equ 0001h
ADLTHH_ADLTH11_LENGTH                    equ 0001h
ADLTHH_ADLTH11_MASK                      equ 0008h
ADLTHH_ADLTH12_POSN                      equ 0004h
ADLTHH_ADLTH12_POSITION                  equ 0004h
ADLTHH_ADLTH12_SIZE                      equ 0001h
ADLTHH_ADLTH12_LENGTH                    equ 0001h
ADLTHH_ADLTH12_MASK                      equ 0010h
ADLTHH_ADLTH13_POSN                      equ 0005h
ADLTHH_ADLTH13_POSITION                  equ 0005h
ADLTHH_ADLTH13_SIZE                      equ 0001h
ADLTHH_ADLTH13_LENGTH                    equ 0001h
ADLTHH_ADLTH13_MASK                      equ 0020h
ADLTHH_ADLTH14_POSN                      equ 0006h
ADLTHH_ADLTH14_POSITION                  equ 0006h
ADLTHH_ADLTH14_SIZE                      equ 0001h
ADLTHH_ADLTH14_LENGTH                    equ 0001h
ADLTHH_ADLTH14_MASK                      equ 0040h
ADLTHH_ADLTH15_POSN                      equ 0007h
ADLTHH_ADLTH15_POSITION                  equ 0007h
ADLTHH_ADLTH15_SIZE                      equ 0001h
ADLTHH_ADLTH15_LENGTH                    equ 0001h
ADLTHH_ADLTH15_MASK                      equ 0080h
ADLTHH_ADLTH_POSN                        equ 0000h
ADLTHH_ADLTH_POSITION                    equ 0000h
ADLTHH_ADLTH_SIZE                        equ 0008h
ADLTHH_ADLTH_LENGTH                      equ 0008h
ADLTHH_ADLTH_MASK                        equ 00FFh
ADLTHH_LTH8_POSN                         equ 0000h
ADLTHH_LTH8_POSITION                     equ 0000h
ADLTHH_LTH8_SIZE                         equ 0001h
ADLTHH_LTH8_LENGTH                       equ 0001h
ADLTHH_LTH8_MASK                         equ 0001h
ADLTHH_LTH9_POSN                         equ 0001h
ADLTHH_LTH9_POSITION                     equ 0001h
ADLTHH_LTH9_SIZE                         equ 0001h
ADLTHH_LTH9_LENGTH                       equ 0001h
ADLTHH_LTH9_MASK                         equ 0002h
ADLTHH_LTH10_POSN                        equ 0002h
ADLTHH_LTH10_POSITION                    equ 0002h
ADLTHH_LTH10_SIZE                        equ 0001h
ADLTHH_LTH10_LENGTH                      equ 0001h
ADLTHH_LTH10_MASK                        equ 0004h
ADLTHH_LTH11_POSN                        equ 0003h
ADLTHH_LTH11_POSITION                    equ 0003h
ADLTHH_LTH11_SIZE                        equ 0001h
ADLTHH_LTH11_LENGTH                      equ 0001h
ADLTHH_LTH11_MASK                        equ 0008h
ADLTHH_LTH12_POSN                        equ 0004h
ADLTHH_LTH12_POSITION                    equ 0004h
ADLTHH_LTH12_SIZE                        equ 0001h
ADLTHH_LTH12_LENGTH                      equ 0001h
ADLTHH_LTH12_MASK                        equ 0010h
ADLTHH_LTH13_POSN                        equ 0005h
ADLTHH_LTH13_POSITION                    equ 0005h
ADLTHH_LTH13_SIZE                        equ 0001h
ADLTHH_LTH13_LENGTH                      equ 0001h
ADLTHH_LTH13_MASK                        equ 0020h
ADLTHH_LTH14_POSN                        equ 0006h
ADLTHH_LTH14_POSITION                    equ 0006h
ADLTHH_LTH14_SIZE                        equ 0001h
ADLTHH_LTH14_LENGTH                      equ 0001h
ADLTHH_LTH14_MASK                        equ 0040h
ADLTHH_LTH15_POSN                        equ 0007h
ADLTHH_LTH15_POSITION                    equ 0007h
ADLTHH_LTH15_SIZE                        equ 0001h
ADLTHH_LTH15_LENGTH                      equ 0001h
ADLTHH_LTH15_MASK                        equ 0080h

// Register: ADUTHL
#define ADUTHL ADUTHL
ADUTHL                                   equ 01D0Eh
// bitfield definitions
ADUTHL_UTH_POSN                          equ 0000h
ADUTHL_UTH_POSITION                      equ 0000h
ADUTHL_UTH_SIZE                          equ 0008h
ADUTHL_UTH_LENGTH                        equ 0008h
ADUTHL_UTH_MASK                          equ 00FFh
ADUTHL_ADUTH0_POSN                       equ 0000h
ADUTHL_ADUTH0_POSITION                   equ 0000h
ADUTHL_ADUTH0_SIZE                       equ 0001h
ADUTHL_ADUTH0_LENGTH                     equ 0001h
ADUTHL_ADUTH0_MASK                       equ 0001h
ADUTHL_ADUTH1_POSN                       equ 0001h
ADUTHL_ADUTH1_POSITION                   equ 0001h
ADUTHL_ADUTH1_SIZE                       equ 0001h
ADUTHL_ADUTH1_LENGTH                     equ 0001h
ADUTHL_ADUTH1_MASK                       equ 0002h
ADUTHL_ADUTH2_POSN                       equ 0002h
ADUTHL_ADUTH2_POSITION                   equ 0002h
ADUTHL_ADUTH2_SIZE                       equ 0001h
ADUTHL_ADUTH2_LENGTH                     equ 0001h
ADUTHL_ADUTH2_MASK                       equ 0004h
ADUTHL_ADUTH3_POSN                       equ 0003h
ADUTHL_ADUTH3_POSITION                   equ 0003h
ADUTHL_ADUTH3_SIZE                       equ 0001h
ADUTHL_ADUTH3_LENGTH                     equ 0001h
ADUTHL_ADUTH3_MASK                       equ 0008h
ADUTHL_ADUTH4_POSN                       equ 0004h
ADUTHL_ADUTH4_POSITION                   equ 0004h
ADUTHL_ADUTH4_SIZE                       equ 0001h
ADUTHL_ADUTH4_LENGTH                     equ 0001h
ADUTHL_ADUTH4_MASK                       equ 0010h
ADUTHL_ADUTH5_POSN                       equ 0005h
ADUTHL_ADUTH5_POSITION                   equ 0005h
ADUTHL_ADUTH5_SIZE                       equ 0001h
ADUTHL_ADUTH5_LENGTH                     equ 0001h
ADUTHL_ADUTH5_MASK                       equ 0020h
ADUTHL_ADUTH6_POSN                       equ 0006h
ADUTHL_ADUTH6_POSITION                   equ 0006h
ADUTHL_ADUTH6_SIZE                       equ 0001h
ADUTHL_ADUTH6_LENGTH                     equ 0001h
ADUTHL_ADUTH6_MASK                       equ 0040h
ADUTHL_ADUTH7_POSN                       equ 0007h
ADUTHL_ADUTH7_POSITION                   equ 0007h
ADUTHL_ADUTH7_SIZE                       equ 0001h
ADUTHL_ADUTH7_LENGTH                     equ 0001h
ADUTHL_ADUTH7_MASK                       equ 0080h
ADUTHL_ADUTH_POSN                        equ 0000h
ADUTHL_ADUTH_POSITION                    equ 0000h
ADUTHL_ADUTH_SIZE                        equ 0008h
ADUTHL_ADUTH_LENGTH                      equ 0008h
ADUTHL_ADUTH_MASK                        equ 00FFh
ADUTHL_UTH0_POSN                         equ 0000h
ADUTHL_UTH0_POSITION                     equ 0000h
ADUTHL_UTH0_SIZE                         equ 0001h
ADUTHL_UTH0_LENGTH                       equ 0001h
ADUTHL_UTH0_MASK                         equ 0001h
ADUTHL_UTH1_POSN                         equ 0001h
ADUTHL_UTH1_POSITION                     equ 0001h
ADUTHL_UTH1_SIZE                         equ 0001h
ADUTHL_UTH1_LENGTH                       equ 0001h
ADUTHL_UTH1_MASK                         equ 0002h
ADUTHL_UTH2_POSN                         equ 0002h
ADUTHL_UTH2_POSITION                     equ 0002h
ADUTHL_UTH2_SIZE                         equ 0001h
ADUTHL_UTH2_LENGTH                       equ 0001h
ADUTHL_UTH2_MASK                         equ 0004h
ADUTHL_UTH3_POSN                         equ 0003h
ADUTHL_UTH3_POSITION                     equ 0003h
ADUTHL_UTH3_SIZE                         equ 0001h
ADUTHL_UTH3_LENGTH                       equ 0001h
ADUTHL_UTH3_MASK                         equ 0008h
ADUTHL_UTH4_POSN                         equ 0004h
ADUTHL_UTH4_POSITION                     equ 0004h
ADUTHL_UTH4_SIZE                         equ 0001h
ADUTHL_UTH4_LENGTH                       equ 0001h
ADUTHL_UTH4_MASK                         equ 0010h
ADUTHL_UTH5_POSN                         equ 0005h
ADUTHL_UTH5_POSITION                     equ 0005h
ADUTHL_UTH5_SIZE                         equ 0001h
ADUTHL_UTH5_LENGTH                       equ 0001h
ADUTHL_UTH5_MASK                         equ 0020h
ADUTHL_UTH6_POSN                         equ 0006h
ADUTHL_UTH6_POSITION                     equ 0006h
ADUTHL_UTH6_SIZE                         equ 0001h
ADUTHL_UTH6_LENGTH                       equ 0001h
ADUTHL_UTH6_MASK                         equ 0040h
ADUTHL_UTH7_POSN                         equ 0007h
ADUTHL_UTH7_POSITION                     equ 0007h
ADUTHL_UTH7_SIZE                         equ 0001h
ADUTHL_UTH7_LENGTH                       equ 0001h
ADUTHL_UTH7_MASK                         equ 0080h

// Register: ADUTHH
#define ADUTHH ADUTHH
ADUTHH                                   equ 01D0Fh
// bitfield definitions
ADUTHH_UTH_POSN                          equ 0000h
ADUTHH_UTH_POSITION                      equ 0000h
ADUTHH_UTH_SIZE                          equ 0008h
ADUTHH_UTH_LENGTH                        equ 0008h
ADUTHH_UTH_MASK                          equ 00FFh
ADUTHH_ADUTH8_POSN                       equ 0000h
ADUTHH_ADUTH8_POSITION                   equ 0000h
ADUTHH_ADUTH8_SIZE                       equ 0001h
ADUTHH_ADUTH8_LENGTH                     equ 0001h
ADUTHH_ADUTH8_MASK                       equ 0001h
ADUTHH_ADUTH9_POSN                       equ 0001h
ADUTHH_ADUTH9_POSITION                   equ 0001h
ADUTHH_ADUTH9_SIZE                       equ 0001h
ADUTHH_ADUTH9_LENGTH                     equ 0001h
ADUTHH_ADUTH9_MASK                       equ 0002h
ADUTHH_ADUTH10_POSN                      equ 0002h
ADUTHH_ADUTH10_POSITION                  equ 0002h
ADUTHH_ADUTH10_SIZE                      equ 0001h
ADUTHH_ADUTH10_LENGTH                    equ 0001h
ADUTHH_ADUTH10_MASK                      equ 0004h
ADUTHH_ADUTH11_POSN                      equ 0003h
ADUTHH_ADUTH11_POSITION                  equ 0003h
ADUTHH_ADUTH11_SIZE                      equ 0001h
ADUTHH_ADUTH11_LENGTH                    equ 0001h
ADUTHH_ADUTH11_MASK                      equ 0008h
ADUTHH_ADUTH12_POSN                      equ 0004h
ADUTHH_ADUTH12_POSITION                  equ 0004h
ADUTHH_ADUTH12_SIZE                      equ 0001h
ADUTHH_ADUTH12_LENGTH                    equ 0001h
ADUTHH_ADUTH12_MASK                      equ 0010h
ADUTHH_ADUTH13_POSN                      equ 0005h
ADUTHH_ADUTH13_POSITION                  equ 0005h
ADUTHH_ADUTH13_SIZE                      equ 0001h
ADUTHH_ADUTH13_LENGTH                    equ 0001h
ADUTHH_ADUTH13_MASK                      equ 0020h
ADUTHH_ADUTH14_POSN                      equ 0006h
ADUTHH_ADUTH14_POSITION                  equ 0006h
ADUTHH_ADUTH14_SIZE                      equ 0001h
ADUTHH_ADUTH14_LENGTH                    equ 0001h
ADUTHH_ADUTH14_MASK                      equ 0040h
ADUTHH_ADUTH15_POSN                      equ 0007h
ADUTHH_ADUTH15_POSITION                  equ 0007h
ADUTHH_ADUTH15_SIZE                      equ 0001h
ADUTHH_ADUTH15_LENGTH                    equ 0001h
ADUTHH_ADUTH15_MASK                      equ 0080h
ADUTHH_ADUTH_POSN                        equ 0000h
ADUTHH_ADUTH_POSITION                    equ 0000h
ADUTHH_ADUTH_SIZE                        equ 0008h
ADUTHH_ADUTH_LENGTH                      equ 0008h
ADUTHH_ADUTH_MASK                        equ 00FFh
ADUTHH_UTH8_POSN                         equ 0000h
ADUTHH_UTH8_POSITION                     equ 0000h
ADUTHH_UTH8_SIZE                         equ 0001h
ADUTHH_UTH8_LENGTH                       equ 0001h
ADUTHH_UTH8_MASK                         equ 0001h
ADUTHH_UTH9_POSN                         equ 0001h
ADUTHH_UTH9_POSITION                     equ 0001h
ADUTHH_UTH9_SIZE                         equ 0001h
ADUTHH_UTH9_LENGTH                       equ 0001h
ADUTHH_UTH9_MASK                         equ 0002h
ADUTHH_UTH10_POSN                        equ 0002h
ADUTHH_UTH10_POSITION                    equ 0002h
ADUTHH_UTH10_SIZE                        equ 0001h
ADUTHH_UTH10_LENGTH                      equ 0001h
ADUTHH_UTH10_MASK                        equ 0004h
ADUTHH_UTH11_POSN                        equ 0003h
ADUTHH_UTH11_POSITION                    equ 0003h
ADUTHH_UTH11_SIZE                        equ 0001h
ADUTHH_UTH11_LENGTH                      equ 0001h
ADUTHH_UTH11_MASK                        equ 0008h
ADUTHH_UTH12_POSN                        equ 0004h
ADUTHH_UTH12_POSITION                    equ 0004h
ADUTHH_UTH12_SIZE                        equ 0001h
ADUTHH_UTH12_LENGTH                      equ 0001h
ADUTHH_UTH12_MASK                        equ 0010h
ADUTHH_UTH13_POSN                        equ 0005h
ADUTHH_UTH13_POSITION                    equ 0005h
ADUTHH_UTH13_SIZE                        equ 0001h
ADUTHH_UTH13_LENGTH                      equ 0001h
ADUTHH_UTH13_MASK                        equ 0020h
ADUTHH_UTH14_POSN                        equ 0006h
ADUTHH_UTH14_POSITION                    equ 0006h
ADUTHH_UTH14_SIZE                        equ 0001h
ADUTHH_UTH14_LENGTH                      equ 0001h
ADUTHH_UTH14_MASK                        equ 0040h
ADUTHH_UTH15_POSN                        equ 0007h
ADUTHH_UTH15_POSITION                    equ 0007h
ADUTHH_UTH15_SIZE                        equ 0001h
ADUTHH_UTH15_LENGTH                      equ 0001h
ADUTHH_UTH15_MASK                        equ 0080h

// Register: ADERRL
#define ADERRL ADERRL
ADERRL                                   equ 01D10h
// bitfield definitions
ADERRL_ERR_POSN                          equ 0000h
ADERRL_ERR_POSITION                      equ 0000h
ADERRL_ERR_SIZE                          equ 0008h
ADERRL_ERR_LENGTH                        equ 0008h
ADERRL_ERR_MASK                          equ 00FFh
ADERRL_ADERR0_POSN                       equ 0000h
ADERRL_ADERR0_POSITION                   equ 0000h
ADERRL_ADERR0_SIZE                       equ 0001h
ADERRL_ADERR0_LENGTH                     equ 0001h
ADERRL_ADERR0_MASK                       equ 0001h
ADERRL_ADERR1_POSN                       equ 0001h
ADERRL_ADERR1_POSITION                   equ 0001h
ADERRL_ADERR1_SIZE                       equ 0001h
ADERRL_ADERR1_LENGTH                     equ 0001h
ADERRL_ADERR1_MASK                       equ 0002h
ADERRL_ADERR2_POSN                       equ 0002h
ADERRL_ADERR2_POSITION                   equ 0002h
ADERRL_ADERR2_SIZE                       equ 0001h
ADERRL_ADERR2_LENGTH                     equ 0001h
ADERRL_ADERR2_MASK                       equ 0004h
ADERRL_ADERR3_POSN                       equ 0003h
ADERRL_ADERR3_POSITION                   equ 0003h
ADERRL_ADERR3_SIZE                       equ 0001h
ADERRL_ADERR3_LENGTH                     equ 0001h
ADERRL_ADERR3_MASK                       equ 0008h
ADERRL_ADERR4_POSN                       equ 0004h
ADERRL_ADERR4_POSITION                   equ 0004h
ADERRL_ADERR4_SIZE                       equ 0001h
ADERRL_ADERR4_LENGTH                     equ 0001h
ADERRL_ADERR4_MASK                       equ 0010h
ADERRL_ADERR5_POSN                       equ 0005h
ADERRL_ADERR5_POSITION                   equ 0005h
ADERRL_ADERR5_SIZE                       equ 0001h
ADERRL_ADERR5_LENGTH                     equ 0001h
ADERRL_ADERR5_MASK                       equ 0020h
ADERRL_ADERR6_POSN                       equ 0006h
ADERRL_ADERR6_POSITION                   equ 0006h
ADERRL_ADERR6_SIZE                       equ 0001h
ADERRL_ADERR6_LENGTH                     equ 0001h
ADERRL_ADERR6_MASK                       equ 0040h
ADERRL_ADERR7_POSN                       equ 0007h
ADERRL_ADERR7_POSITION                   equ 0007h
ADERRL_ADERR7_SIZE                       equ 0001h
ADERRL_ADERR7_LENGTH                     equ 0001h
ADERRL_ADERR7_MASK                       equ 0080h
ADERRL_ADERR_POSN                        equ 0000h
ADERRL_ADERR_POSITION                    equ 0000h
ADERRL_ADERR_SIZE                        equ 0008h
ADERRL_ADERR_LENGTH                      equ 0008h
ADERRL_ADERR_MASK                        equ 00FFh
ADERRL_ERR0_POSN                         equ 0000h
ADERRL_ERR0_POSITION                     equ 0000h
ADERRL_ERR0_SIZE                         equ 0001h
ADERRL_ERR0_LENGTH                       equ 0001h
ADERRL_ERR0_MASK                         equ 0001h
ADERRL_ERR1_POSN                         equ 0001h
ADERRL_ERR1_POSITION                     equ 0001h
ADERRL_ERR1_SIZE                         equ 0001h
ADERRL_ERR1_LENGTH                       equ 0001h
ADERRL_ERR1_MASK                         equ 0002h
ADERRL_ERR2_POSN                         equ 0002h
ADERRL_ERR2_POSITION                     equ 0002h
ADERRL_ERR2_SIZE                         equ 0001h
ADERRL_ERR2_LENGTH                       equ 0001h
ADERRL_ERR2_MASK                         equ 0004h
ADERRL_ERR3_POSN                         equ 0003h
ADERRL_ERR3_POSITION                     equ 0003h
ADERRL_ERR3_SIZE                         equ 0001h
ADERRL_ERR3_LENGTH                       equ 0001h
ADERRL_ERR3_MASK                         equ 0008h
ADERRL_ERR4_POSN                         equ 0004h
ADERRL_ERR4_POSITION                     equ 0004h
ADERRL_ERR4_SIZE                         equ 0001h
ADERRL_ERR4_LENGTH                       equ 0001h
ADERRL_ERR4_MASK                         equ 0010h
ADERRL_ERR5_POSN                         equ 0005h
ADERRL_ERR5_POSITION                     equ 0005h
ADERRL_ERR5_SIZE                         equ 0001h
ADERRL_ERR5_LENGTH                       equ 0001h
ADERRL_ERR5_MASK                         equ 0020h
ADERRL_ERR6_POSN                         equ 0006h
ADERRL_ERR6_POSITION                     equ 0006h
ADERRL_ERR6_SIZE                         equ 0001h
ADERRL_ERR6_LENGTH                       equ 0001h
ADERRL_ERR6_MASK                         equ 0040h
ADERRL_ERR7_POSN                         equ 0007h
ADERRL_ERR7_POSITION                     equ 0007h
ADERRL_ERR7_SIZE                         equ 0001h
ADERRL_ERR7_LENGTH                       equ 0001h
ADERRL_ERR7_MASK                         equ 0080h

// Register: ADERRH
#define ADERRH ADERRH
ADERRH                                   equ 01D11h
// bitfield definitions
ADERRH_ERR_POSN                          equ 0000h
ADERRH_ERR_POSITION                      equ 0000h
ADERRH_ERR_SIZE                          equ 0008h
ADERRH_ERR_LENGTH                        equ 0008h
ADERRH_ERR_MASK                          equ 00FFh
ADERRH_ADERR8_POSN                       equ 0000h
ADERRH_ADERR8_POSITION                   equ 0000h
ADERRH_ADERR8_SIZE                       equ 0001h
ADERRH_ADERR8_LENGTH                     equ 0001h
ADERRH_ADERR8_MASK                       equ 0001h
ADERRH_ADERR9_POSN                       equ 0001h
ADERRH_ADERR9_POSITION                   equ 0001h
ADERRH_ADERR9_SIZE                       equ 0001h
ADERRH_ADERR9_LENGTH                     equ 0001h
ADERRH_ADERR9_MASK                       equ 0002h
ADERRH_ADERR10_POSN                      equ 0002h
ADERRH_ADERR10_POSITION                  equ 0002h
ADERRH_ADERR10_SIZE                      equ 0001h
ADERRH_ADERR10_LENGTH                    equ 0001h
ADERRH_ADERR10_MASK                      equ 0004h
ADERRH_ADERR11_POSN                      equ 0003h
ADERRH_ADERR11_POSITION                  equ 0003h
ADERRH_ADERR11_SIZE                      equ 0001h
ADERRH_ADERR11_LENGTH                    equ 0001h
ADERRH_ADERR11_MASK                      equ 0008h
ADERRH_ADERR12_POSN                      equ 0004h
ADERRH_ADERR12_POSITION                  equ 0004h
ADERRH_ADERR12_SIZE                      equ 0001h
ADERRH_ADERR12_LENGTH                    equ 0001h
ADERRH_ADERR12_MASK                      equ 0010h
ADERRH_ADERR13_POSN                      equ 0005h
ADERRH_ADERR13_POSITION                  equ 0005h
ADERRH_ADERR13_SIZE                      equ 0001h
ADERRH_ADERR13_LENGTH                    equ 0001h
ADERRH_ADERR13_MASK                      equ 0020h
ADERRH_ADERR14_POSN                      equ 0006h
ADERRH_ADERR14_POSITION                  equ 0006h
ADERRH_ADERR14_SIZE                      equ 0001h
ADERRH_ADERR14_LENGTH                    equ 0001h
ADERRH_ADERR14_MASK                      equ 0040h
ADERRH_ADERR15_POSN                      equ 0007h
ADERRH_ADERR15_POSITION                  equ 0007h
ADERRH_ADERR15_SIZE                      equ 0001h
ADERRH_ADERR15_LENGTH                    equ 0001h
ADERRH_ADERR15_MASK                      equ 0080h
ADERRH_ADERR_POSN                        equ 0000h
ADERRH_ADERR_POSITION                    equ 0000h
ADERRH_ADERR_SIZE                        equ 0008h
ADERRH_ADERR_LENGTH                      equ 0008h
ADERRH_ADERR_MASK                        equ 00FFh
ADERRH_ERR8_POSN                         equ 0000h
ADERRH_ERR8_POSITION                     equ 0000h
ADERRH_ERR8_SIZE                         equ 0001h
ADERRH_ERR8_LENGTH                       equ 0001h
ADERRH_ERR8_MASK                         equ 0001h
ADERRH_ERR9_POSN                         equ 0001h
ADERRH_ERR9_POSITION                     equ 0001h
ADERRH_ERR9_SIZE                         equ 0001h
ADERRH_ERR9_LENGTH                       equ 0001h
ADERRH_ERR9_MASK                         equ 0002h
ADERRH_ERR10_POSN                        equ 0002h
ADERRH_ERR10_POSITION                    equ 0002h
ADERRH_ERR10_SIZE                        equ 0001h
ADERRH_ERR10_LENGTH                      equ 0001h
ADERRH_ERR10_MASK                        equ 0004h
ADERRH_ERR11_POSN                        equ 0003h
ADERRH_ERR11_POSITION                    equ 0003h
ADERRH_ERR11_SIZE                        equ 0001h
ADERRH_ERR11_LENGTH                      equ 0001h
ADERRH_ERR11_MASK                        equ 0008h
ADERRH_ERR12_POSN                        equ 0004h
ADERRH_ERR12_POSITION                    equ 0004h
ADERRH_ERR12_SIZE                        equ 0001h
ADERRH_ERR12_LENGTH                      equ 0001h
ADERRH_ERR12_MASK                        equ 0010h
ADERRH_ERR13_POSN                        equ 0005h
ADERRH_ERR13_POSITION                    equ 0005h
ADERRH_ERR13_SIZE                        equ 0001h
ADERRH_ERR13_LENGTH                      equ 0001h
ADERRH_ERR13_MASK                        equ 0020h
ADERRH_ERR14_POSN                        equ 0006h
ADERRH_ERR14_POSITION                    equ 0006h
ADERRH_ERR14_SIZE                        equ 0001h
ADERRH_ERR14_LENGTH                      equ 0001h
ADERRH_ERR14_MASK                        equ 0040h
ADERRH_ERR15_POSN                        equ 0007h
ADERRH_ERR15_POSITION                    equ 0007h
ADERRH_ERR15_SIZE                        equ 0001h
ADERRH_ERR15_LENGTH                      equ 0001h
ADERRH_ERR15_MASK                        equ 0080h

// Register: ADSTPTL
#define ADSTPTL ADSTPTL
ADSTPTL                                  equ 01D12h
// bitfield definitions
ADSTPTL_STPT_POSN                        equ 0000h
ADSTPTL_STPT_POSITION                    equ 0000h
ADSTPTL_STPT_SIZE                        equ 0008h
ADSTPTL_STPT_LENGTH                      equ 0008h
ADSTPTL_STPT_MASK                        equ 00FFh
ADSTPTL_ADSTPT0_POSN                     equ 0000h
ADSTPTL_ADSTPT0_POSITION                 equ 0000h
ADSTPTL_ADSTPT0_SIZE                     equ 0001h
ADSTPTL_ADSTPT0_LENGTH                   equ 0001h
ADSTPTL_ADSTPT0_MASK                     equ 0001h
ADSTPTL_ADSTPT1_POSN                     equ 0001h
ADSTPTL_ADSTPT1_POSITION                 equ 0001h
ADSTPTL_ADSTPT1_SIZE                     equ 0001h
ADSTPTL_ADSTPT1_LENGTH                   equ 0001h
ADSTPTL_ADSTPT1_MASK                     equ 0002h
ADSTPTL_ADSTPT2_POSN                     equ 0002h
ADSTPTL_ADSTPT2_POSITION                 equ 0002h
ADSTPTL_ADSTPT2_SIZE                     equ 0001h
ADSTPTL_ADSTPT2_LENGTH                   equ 0001h
ADSTPTL_ADSTPT2_MASK                     equ 0004h
ADSTPTL_ADSTPT3_POSN                     equ 0003h
ADSTPTL_ADSTPT3_POSITION                 equ 0003h
ADSTPTL_ADSTPT3_SIZE                     equ 0001h
ADSTPTL_ADSTPT3_LENGTH                   equ 0001h
ADSTPTL_ADSTPT3_MASK                     equ 0008h
ADSTPTL_ADSTPT4_POSN                     equ 0004h
ADSTPTL_ADSTPT4_POSITION                 equ 0004h
ADSTPTL_ADSTPT4_SIZE                     equ 0001h
ADSTPTL_ADSTPT4_LENGTH                   equ 0001h
ADSTPTL_ADSTPT4_MASK                     equ 0010h
ADSTPTL_ADSTPT5_POSN                     equ 0005h
ADSTPTL_ADSTPT5_POSITION                 equ 0005h
ADSTPTL_ADSTPT5_SIZE                     equ 0001h
ADSTPTL_ADSTPT5_LENGTH                   equ 0001h
ADSTPTL_ADSTPT5_MASK                     equ 0020h
ADSTPTL_ADSTPT6_POSN                     equ 0006h
ADSTPTL_ADSTPT6_POSITION                 equ 0006h
ADSTPTL_ADSTPT6_SIZE                     equ 0001h
ADSTPTL_ADSTPT6_LENGTH                   equ 0001h
ADSTPTL_ADSTPT6_MASK                     equ 0040h
ADSTPTL_ADSTPT7_POSN                     equ 0007h
ADSTPTL_ADSTPT7_POSITION                 equ 0007h
ADSTPTL_ADSTPT7_SIZE                     equ 0001h
ADSTPTL_ADSTPT7_LENGTH                   equ 0001h
ADSTPTL_ADSTPT7_MASK                     equ 0080h
ADSTPTL_ADSTPT_POSN                      equ 0000h
ADSTPTL_ADSTPT_POSITION                  equ 0000h
ADSTPTL_ADSTPT_SIZE                      equ 0008h
ADSTPTL_ADSTPT_LENGTH                    equ 0008h
ADSTPTL_ADSTPT_MASK                      equ 00FFh
ADSTPTL_STPT0_POSN                       equ 0000h
ADSTPTL_STPT0_POSITION                   equ 0000h
ADSTPTL_STPT0_SIZE                       equ 0001h
ADSTPTL_STPT0_LENGTH                     equ 0001h
ADSTPTL_STPT0_MASK                       equ 0001h
ADSTPTL_STPT1_POSN                       equ 0001h
ADSTPTL_STPT1_POSITION                   equ 0001h
ADSTPTL_STPT1_SIZE                       equ 0001h
ADSTPTL_STPT1_LENGTH                     equ 0001h
ADSTPTL_STPT1_MASK                       equ 0002h
ADSTPTL_STPT2_POSN                       equ 0002h
ADSTPTL_STPT2_POSITION                   equ 0002h
ADSTPTL_STPT2_SIZE                       equ 0001h
ADSTPTL_STPT2_LENGTH                     equ 0001h
ADSTPTL_STPT2_MASK                       equ 0004h
ADSTPTL_STPT3_POSN                       equ 0003h
ADSTPTL_STPT3_POSITION                   equ 0003h
ADSTPTL_STPT3_SIZE                       equ 0001h
ADSTPTL_STPT3_LENGTH                     equ 0001h
ADSTPTL_STPT3_MASK                       equ 0008h
ADSTPTL_STPT4_POSN                       equ 0004h
ADSTPTL_STPT4_POSITION                   equ 0004h
ADSTPTL_STPT4_SIZE                       equ 0001h
ADSTPTL_STPT4_LENGTH                     equ 0001h
ADSTPTL_STPT4_MASK                       equ 0010h
ADSTPTL_STPT5_POSN                       equ 0005h
ADSTPTL_STPT5_POSITION                   equ 0005h
ADSTPTL_STPT5_SIZE                       equ 0001h
ADSTPTL_STPT5_LENGTH                     equ 0001h
ADSTPTL_STPT5_MASK                       equ 0020h
ADSTPTL_STPT6_POSN                       equ 0006h
ADSTPTL_STPT6_POSITION                   equ 0006h
ADSTPTL_STPT6_SIZE                       equ 0001h
ADSTPTL_STPT6_LENGTH                     equ 0001h
ADSTPTL_STPT6_MASK                       equ 0040h
ADSTPTL_STPT7_POSN                       equ 0007h
ADSTPTL_STPT7_POSITION                   equ 0007h
ADSTPTL_STPT7_SIZE                       equ 0001h
ADSTPTL_STPT7_LENGTH                     equ 0001h
ADSTPTL_STPT7_MASK                       equ 0080h

// Register: ADSTPTH
#define ADSTPTH ADSTPTH
ADSTPTH                                  equ 01D13h
// bitfield definitions
ADSTPTH_STPT_POSN                        equ 0000h
ADSTPTH_STPT_POSITION                    equ 0000h
ADSTPTH_STPT_SIZE                        equ 0008h
ADSTPTH_STPT_LENGTH                      equ 0008h
ADSTPTH_STPT_MASK                        equ 00FFh
ADSTPTH_ADSTPT8_POSN                     equ 0000h
ADSTPTH_ADSTPT8_POSITION                 equ 0000h
ADSTPTH_ADSTPT8_SIZE                     equ 0001h
ADSTPTH_ADSTPT8_LENGTH                   equ 0001h
ADSTPTH_ADSTPT8_MASK                     equ 0001h
ADSTPTH_ADSTPT9_POSN                     equ 0001h
ADSTPTH_ADSTPT9_POSITION                 equ 0001h
ADSTPTH_ADSTPT9_SIZE                     equ 0001h
ADSTPTH_ADSTPT9_LENGTH                   equ 0001h
ADSTPTH_ADSTPT9_MASK                     equ 0002h
ADSTPTH_ADSTPT10_POSN                    equ 0002h
ADSTPTH_ADSTPT10_POSITION                equ 0002h
ADSTPTH_ADSTPT10_SIZE                    equ 0001h
ADSTPTH_ADSTPT10_LENGTH                  equ 0001h
ADSTPTH_ADSTPT10_MASK                    equ 0004h
ADSTPTH_ADSTPT11_POSN                    equ 0003h
ADSTPTH_ADSTPT11_POSITION                equ 0003h
ADSTPTH_ADSTPT11_SIZE                    equ 0001h
ADSTPTH_ADSTPT11_LENGTH                  equ 0001h
ADSTPTH_ADSTPT11_MASK                    equ 0008h
ADSTPTH_ADSTPT12_POSN                    equ 0004h
ADSTPTH_ADSTPT12_POSITION                equ 0004h
ADSTPTH_ADSTPT12_SIZE                    equ 0001h
ADSTPTH_ADSTPT12_LENGTH                  equ 0001h
ADSTPTH_ADSTPT12_MASK                    equ 0010h
ADSTPTH_ADSTPT13_POSN                    equ 0005h
ADSTPTH_ADSTPT13_POSITION                equ 0005h
ADSTPTH_ADSTPT13_SIZE                    equ 0001h
ADSTPTH_ADSTPT13_LENGTH                  equ 0001h
ADSTPTH_ADSTPT13_MASK                    equ 0020h
ADSTPTH_ADSTPT14_POSN                    equ 0006h
ADSTPTH_ADSTPT14_POSITION                equ 0006h
ADSTPTH_ADSTPT14_SIZE                    equ 0001h
ADSTPTH_ADSTPT14_LENGTH                  equ 0001h
ADSTPTH_ADSTPT14_MASK                    equ 0040h
ADSTPTH_ADSTPT15_POSN                    equ 0007h
ADSTPTH_ADSTPT15_POSITION                equ 0007h
ADSTPTH_ADSTPT15_SIZE                    equ 0001h
ADSTPTH_ADSTPT15_LENGTH                  equ 0001h
ADSTPTH_ADSTPT15_MASK                    equ 0080h
ADSTPTH_ADSTPT_POSN                      equ 0000h
ADSTPTH_ADSTPT_POSITION                  equ 0000h
ADSTPTH_ADSTPT_SIZE                      equ 0008h
ADSTPTH_ADSTPT_LENGTH                    equ 0008h
ADSTPTH_ADSTPT_MASK                      equ 00FFh
ADSTPTH_STPT8_POSN                       equ 0000h
ADSTPTH_STPT8_POSITION                   equ 0000h
ADSTPTH_STPT8_SIZE                       equ 0001h
ADSTPTH_STPT8_LENGTH                     equ 0001h
ADSTPTH_STPT8_MASK                       equ 0001h
ADSTPTH_STPT9_POSN                       equ 0001h
ADSTPTH_STPT9_POSITION                   equ 0001h
ADSTPTH_STPT9_SIZE                       equ 0001h
ADSTPTH_STPT9_LENGTH                     equ 0001h
ADSTPTH_STPT9_MASK                       equ 0002h
ADSTPTH_STPT10_POSN                      equ 0002h
ADSTPTH_STPT10_POSITION                  equ 0002h
ADSTPTH_STPT10_SIZE                      equ 0001h
ADSTPTH_STPT10_LENGTH                    equ 0001h
ADSTPTH_STPT10_MASK                      equ 0004h
ADSTPTH_STPT11_POSN                      equ 0003h
ADSTPTH_STPT11_POSITION                  equ 0003h
ADSTPTH_STPT11_SIZE                      equ 0001h
ADSTPTH_STPT11_LENGTH                    equ 0001h
ADSTPTH_STPT11_MASK                      equ 0008h
ADSTPTH_STPT12_POSN                      equ 0004h
ADSTPTH_STPT12_POSITION                  equ 0004h
ADSTPTH_STPT12_SIZE                      equ 0001h
ADSTPTH_STPT12_LENGTH                    equ 0001h
ADSTPTH_STPT12_MASK                      equ 0010h
ADSTPTH_STPT13_POSN                      equ 0005h
ADSTPTH_STPT13_POSITION                  equ 0005h
ADSTPTH_STPT13_SIZE                      equ 0001h
ADSTPTH_STPT13_LENGTH                    equ 0001h
ADSTPTH_STPT13_MASK                      equ 0020h
ADSTPTH_STPT15_POSN                      equ 0006h
ADSTPTH_STPT15_POSITION                  equ 0006h
ADSTPTH_STPT15_SIZE                      equ 0001h
ADSTPTH_STPT15_LENGTH                    equ 0001h
ADSTPTH_STPT15_MASK                      equ 0040h
ADSTPTH_STPT16_POSN                      equ 0007h
ADSTPTH_STPT16_POSITION                  equ 0007h
ADSTPTH_STPT16_SIZE                      equ 0001h
ADSTPTH_STPT16_LENGTH                    equ 0001h
ADSTPTH_STPT16_MASK                      equ 0080h

// Register: ADFLTRL
#define ADFLTRL ADFLTRL
ADFLTRL                                  equ 01D14h
// bitfield definitions
ADFLTRL_FLTR_POSN                        equ 0000h
ADFLTRL_FLTR_POSITION                    equ 0000h
ADFLTRL_FLTR_SIZE                        equ 0008h
ADFLTRL_FLTR_LENGTH                      equ 0008h
ADFLTRL_FLTR_MASK                        equ 00FFh
ADFLTRL_ADFLTR0_POSN                     equ 0000h
ADFLTRL_ADFLTR0_POSITION                 equ 0000h
ADFLTRL_ADFLTR0_SIZE                     equ 0001h
ADFLTRL_ADFLTR0_LENGTH                   equ 0001h
ADFLTRL_ADFLTR0_MASK                     equ 0001h
ADFLTRL_ADFLTR1_POSN                     equ 0001h
ADFLTRL_ADFLTR1_POSITION                 equ 0001h
ADFLTRL_ADFLTR1_SIZE                     equ 0001h
ADFLTRL_ADFLTR1_LENGTH                   equ 0001h
ADFLTRL_ADFLTR1_MASK                     equ 0002h
ADFLTRL_ADFLTR2_POSN                     equ 0002h
ADFLTRL_ADFLTR2_POSITION                 equ 0002h
ADFLTRL_ADFLTR2_SIZE                     equ 0001h
ADFLTRL_ADFLTR2_LENGTH                   equ 0001h
ADFLTRL_ADFLTR2_MASK                     equ 0004h
ADFLTRL_ADFLTR3_POSN                     equ 0003h
ADFLTRL_ADFLTR3_POSITION                 equ 0003h
ADFLTRL_ADFLTR3_SIZE                     equ 0001h
ADFLTRL_ADFLTR3_LENGTH                   equ 0001h
ADFLTRL_ADFLTR3_MASK                     equ 0008h
ADFLTRL_ADFLTR4_POSN                     equ 0004h
ADFLTRL_ADFLTR4_POSITION                 equ 0004h
ADFLTRL_ADFLTR4_SIZE                     equ 0001h
ADFLTRL_ADFLTR4_LENGTH                   equ 0001h
ADFLTRL_ADFLTR4_MASK                     equ 0010h
ADFLTRL_ADFLTR5_POSN                     equ 0005h
ADFLTRL_ADFLTR5_POSITION                 equ 0005h
ADFLTRL_ADFLTR5_SIZE                     equ 0001h
ADFLTRL_ADFLTR5_LENGTH                   equ 0001h
ADFLTRL_ADFLTR5_MASK                     equ 0020h
ADFLTRL_ADFLTR6_POSN                     equ 0006h
ADFLTRL_ADFLTR6_POSITION                 equ 0006h
ADFLTRL_ADFLTR6_SIZE                     equ 0001h
ADFLTRL_ADFLTR6_LENGTH                   equ 0001h
ADFLTRL_ADFLTR6_MASK                     equ 0040h
ADFLTRL_ADFLTR7_POSN                     equ 0007h
ADFLTRL_ADFLTR7_POSITION                 equ 0007h
ADFLTRL_ADFLTR7_SIZE                     equ 0001h
ADFLTRL_ADFLTR7_LENGTH                   equ 0001h
ADFLTRL_ADFLTR7_MASK                     equ 0080h
ADFLTRL_ADFLTR_POSN                      equ 0000h
ADFLTRL_ADFLTR_POSITION                  equ 0000h
ADFLTRL_ADFLTR_SIZE                      equ 0008h
ADFLTRL_ADFLTR_LENGTH                    equ 0008h
ADFLTRL_ADFLTR_MASK                      equ 00FFh
ADFLTRL_FLTR0_POSN                       equ 0000h
ADFLTRL_FLTR0_POSITION                   equ 0000h
ADFLTRL_FLTR0_SIZE                       equ 0001h
ADFLTRL_FLTR0_LENGTH                     equ 0001h
ADFLTRL_FLTR0_MASK                       equ 0001h
ADFLTRL_FLTR1_POSN                       equ 0001h
ADFLTRL_FLTR1_POSITION                   equ 0001h
ADFLTRL_FLTR1_SIZE                       equ 0001h
ADFLTRL_FLTR1_LENGTH                     equ 0001h
ADFLTRL_FLTR1_MASK                       equ 0002h
ADFLTRL_FLTR2_POSN                       equ 0002h
ADFLTRL_FLTR2_POSITION                   equ 0002h
ADFLTRL_FLTR2_SIZE                       equ 0001h
ADFLTRL_FLTR2_LENGTH                     equ 0001h
ADFLTRL_FLTR2_MASK                       equ 0004h
ADFLTRL_FLTR3_POSN                       equ 0003h
ADFLTRL_FLTR3_POSITION                   equ 0003h
ADFLTRL_FLTR3_SIZE                       equ 0001h
ADFLTRL_FLTR3_LENGTH                     equ 0001h
ADFLTRL_FLTR3_MASK                       equ 0008h
ADFLTRL_FLTR4_POSN                       equ 0004h
ADFLTRL_FLTR4_POSITION                   equ 0004h
ADFLTRL_FLTR4_SIZE                       equ 0001h
ADFLTRL_FLTR4_LENGTH                     equ 0001h
ADFLTRL_FLTR4_MASK                       equ 0010h
ADFLTRL_FLTR5_POSN                       equ 0005h
ADFLTRL_FLTR5_POSITION                   equ 0005h
ADFLTRL_FLTR5_SIZE                       equ 0001h
ADFLTRL_FLTR5_LENGTH                     equ 0001h
ADFLTRL_FLTR5_MASK                       equ 0020h
ADFLTRL_FLTR6_POSN                       equ 0006h
ADFLTRL_FLTR6_POSITION                   equ 0006h
ADFLTRL_FLTR6_SIZE                       equ 0001h
ADFLTRL_FLTR6_LENGTH                     equ 0001h
ADFLTRL_FLTR6_MASK                       equ 0040h
ADFLTRL_FLTR7_POSN                       equ 0007h
ADFLTRL_FLTR7_POSITION                   equ 0007h
ADFLTRL_FLTR7_SIZE                       equ 0001h
ADFLTRL_FLTR7_LENGTH                     equ 0001h
ADFLTRL_FLTR7_MASK                       equ 0080h

// Register: ADFLTRH
#define ADFLTRH ADFLTRH
ADFLTRH                                  equ 01D15h
// bitfield definitions
ADFLTRH_FLTR_POSN                        equ 0000h
ADFLTRH_FLTR_POSITION                    equ 0000h
ADFLTRH_FLTR_SIZE                        equ 0008h
ADFLTRH_FLTR_LENGTH                      equ 0008h
ADFLTRH_FLTR_MASK                        equ 00FFh
ADFLTRH_ADFLTR8_POSN                     equ 0000h
ADFLTRH_ADFLTR8_POSITION                 equ 0000h
ADFLTRH_ADFLTR8_SIZE                     equ 0001h
ADFLTRH_ADFLTR8_LENGTH                   equ 0001h
ADFLTRH_ADFLTR8_MASK                     equ 0001h
ADFLTRH_ADFLTR9_POSN                     equ 0001h
ADFLTRH_ADFLTR9_POSITION                 equ 0001h
ADFLTRH_ADFLTR9_SIZE                     equ 0001h
ADFLTRH_ADFLTR9_LENGTH                   equ 0001h
ADFLTRH_ADFLTR9_MASK                     equ 0002h
ADFLTRH_ADFLTR10_POSN                    equ 0002h
ADFLTRH_ADFLTR10_POSITION                equ 0002h
ADFLTRH_ADFLTR10_SIZE                    equ 0001h
ADFLTRH_ADFLTR10_LENGTH                  equ 0001h
ADFLTRH_ADFLTR10_MASK                    equ 0004h
ADFLTRH_ADFLTR11_POSN                    equ 0003h
ADFLTRH_ADFLTR11_POSITION                equ 0003h
ADFLTRH_ADFLTR11_SIZE                    equ 0001h
ADFLTRH_ADFLTR11_LENGTH                  equ 0001h
ADFLTRH_ADFLTR11_MASK                    equ 0008h
ADFLTRH_ADFLTR12_POSN                    equ 0004h
ADFLTRH_ADFLTR12_POSITION                equ 0004h
ADFLTRH_ADFLTR12_SIZE                    equ 0001h
ADFLTRH_ADFLTR12_LENGTH                  equ 0001h
ADFLTRH_ADFLTR12_MASK                    equ 0010h
ADFLTRH_ADFLTR13_POSN                    equ 0005h
ADFLTRH_ADFLTR13_POSITION                equ 0005h
ADFLTRH_ADFLTR13_SIZE                    equ 0001h
ADFLTRH_ADFLTR13_LENGTH                  equ 0001h
ADFLTRH_ADFLTR13_MASK                    equ 0020h
ADFLTRH_ADFLTR14_POSN                    equ 0006h
ADFLTRH_ADFLTR14_POSITION                equ 0006h
ADFLTRH_ADFLTR14_SIZE                    equ 0001h
ADFLTRH_ADFLTR14_LENGTH                  equ 0001h
ADFLTRH_ADFLTR14_MASK                    equ 0040h
ADFLTRH_ADFLTR15_POSN                    equ 0007h
ADFLTRH_ADFLTR15_POSITION                equ 0007h
ADFLTRH_ADFLTR15_SIZE                    equ 0001h
ADFLTRH_ADFLTR15_LENGTH                  equ 0001h
ADFLTRH_ADFLTR15_MASK                    equ 0080h
ADFLTRH_ADFLTR_POSN                      equ 0000h
ADFLTRH_ADFLTR_POSITION                  equ 0000h
ADFLTRH_ADFLTR_SIZE                      equ 0008h
ADFLTRH_ADFLTR_LENGTH                    equ 0008h
ADFLTRH_ADFLTR_MASK                      equ 00FFh
ADFLTRH_FLTR8_POSN                       equ 0000h
ADFLTRH_FLTR8_POSITION                   equ 0000h
ADFLTRH_FLTR8_SIZE                       equ 0001h
ADFLTRH_FLTR8_LENGTH                     equ 0001h
ADFLTRH_FLTR8_MASK                       equ 0001h
ADFLTRH_FLTR9_POSN                       equ 0001h
ADFLTRH_FLTR9_POSITION                   equ 0001h
ADFLTRH_FLTR9_SIZE                       equ 0001h
ADFLTRH_FLTR9_LENGTH                     equ 0001h
ADFLTRH_FLTR9_MASK                       equ 0002h
ADFLTRH_FLTR10_POSN                      equ 0002h
ADFLTRH_FLTR10_POSITION                  equ 0002h
ADFLTRH_FLTR10_SIZE                      equ 0001h
ADFLTRH_FLTR10_LENGTH                    equ 0001h
ADFLTRH_FLTR10_MASK                      equ 0004h
ADFLTRH_FLTR11_POSN                      equ 0003h
ADFLTRH_FLTR11_POSITION                  equ 0003h
ADFLTRH_FLTR11_SIZE                      equ 0001h
ADFLTRH_FLTR11_LENGTH                    equ 0001h
ADFLTRH_FLTR11_MASK                      equ 0008h
ADFLTRH_FLTR12_POSN                      equ 0004h
ADFLTRH_FLTR12_POSITION                  equ 0004h
ADFLTRH_FLTR12_SIZE                      equ 0001h
ADFLTRH_FLTR12_LENGTH                    equ 0001h
ADFLTRH_FLTR12_MASK                      equ 0010h
ADFLTRH_FLTR13_POSN                      equ 0005h
ADFLTRH_FLTR13_POSITION                  equ 0005h
ADFLTRH_FLTR13_SIZE                      equ 0001h
ADFLTRH_FLTR13_LENGTH                    equ 0001h
ADFLTRH_FLTR13_MASK                      equ 0020h
ADFLTRH_FLTR14_POSN                      equ 0006h
ADFLTRH_FLTR14_POSITION                  equ 0006h
ADFLTRH_FLTR14_SIZE                      equ 0001h
ADFLTRH_FLTR14_LENGTH                    equ 0001h
ADFLTRH_FLTR14_MASK                      equ 0040h
ADFLTRH_FLTR15_POSN                      equ 0007h
ADFLTRH_FLTR15_POSITION                  equ 0007h
ADFLTRH_FLTR15_SIZE                      equ 0001h
ADFLTRH_FLTR15_LENGTH                    equ 0001h
ADFLTRH_FLTR15_MASK                      equ 0080h

// Register: ADACCL
#define ADACCL ADACCL
ADACCL                                   equ 01D16h
// bitfield definitions
ADACCL_ACC_POSN                          equ 0000h
ADACCL_ACC_POSITION                      equ 0000h
ADACCL_ACC_SIZE                          equ 0008h
ADACCL_ACC_LENGTH                        equ 0008h
ADACCL_ACC_MASK                          equ 00FFh
ADACCL_ADACC0_POSN                       equ 0000h
ADACCL_ADACC0_POSITION                   equ 0000h
ADACCL_ADACC0_SIZE                       equ 0001h
ADACCL_ADACC0_LENGTH                     equ 0001h
ADACCL_ADACC0_MASK                       equ 0001h
ADACCL_ADACC1_POSN                       equ 0001h
ADACCL_ADACC1_POSITION                   equ 0001h
ADACCL_ADACC1_SIZE                       equ 0001h
ADACCL_ADACC1_LENGTH                     equ 0001h
ADACCL_ADACC1_MASK                       equ 0002h
ADACCL_ADACC2_POSN                       equ 0002h
ADACCL_ADACC2_POSITION                   equ 0002h
ADACCL_ADACC2_SIZE                       equ 0001h
ADACCL_ADACC2_LENGTH                     equ 0001h
ADACCL_ADACC2_MASK                       equ 0004h
ADACCL_ADACC3_POSN                       equ 0003h
ADACCL_ADACC3_POSITION                   equ 0003h
ADACCL_ADACC3_SIZE                       equ 0001h
ADACCL_ADACC3_LENGTH                     equ 0001h
ADACCL_ADACC3_MASK                       equ 0008h
ADACCL_ADACC4_POSN                       equ 0004h
ADACCL_ADACC4_POSITION                   equ 0004h
ADACCL_ADACC4_SIZE                       equ 0001h
ADACCL_ADACC4_LENGTH                     equ 0001h
ADACCL_ADACC4_MASK                       equ 0010h
ADACCL_ADACC5_POSN                       equ 0005h
ADACCL_ADACC5_POSITION                   equ 0005h
ADACCL_ADACC5_SIZE                       equ 0001h
ADACCL_ADACC5_LENGTH                     equ 0001h
ADACCL_ADACC5_MASK                       equ 0020h
ADACCL_ADACC6_POSN                       equ 0006h
ADACCL_ADACC6_POSITION                   equ 0006h
ADACCL_ADACC6_SIZE                       equ 0001h
ADACCL_ADACC6_LENGTH                     equ 0001h
ADACCL_ADACC6_MASK                       equ 0040h
ADACCL_ADACC7_POSN                       equ 0007h
ADACCL_ADACC7_POSITION                   equ 0007h
ADACCL_ADACC7_SIZE                       equ 0001h
ADACCL_ADACC7_LENGTH                     equ 0001h
ADACCL_ADACC7_MASK                       equ 0080h
ADACCL_ADACC_POSN                        equ 0000h
ADACCL_ADACC_POSITION                    equ 0000h
ADACCL_ADACC_SIZE                        equ 0008h
ADACCL_ADACC_LENGTH                      equ 0008h
ADACCL_ADACC_MASK                        equ 00FFh
ADACCL_ACC0_POSN                         equ 0000h
ADACCL_ACC0_POSITION                     equ 0000h
ADACCL_ACC0_SIZE                         equ 0001h
ADACCL_ACC0_LENGTH                       equ 0001h
ADACCL_ACC0_MASK                         equ 0001h
ADACCL_ACC1_POSN                         equ 0001h
ADACCL_ACC1_POSITION                     equ 0001h
ADACCL_ACC1_SIZE                         equ 0001h
ADACCL_ACC1_LENGTH                       equ 0001h
ADACCL_ACC1_MASK                         equ 0002h
ADACCL_ACC2_POSN                         equ 0002h
ADACCL_ACC2_POSITION                     equ 0002h
ADACCL_ACC2_SIZE                         equ 0001h
ADACCL_ACC2_LENGTH                       equ 0001h
ADACCL_ACC2_MASK                         equ 0004h
ADACCL_ACC3_POSN                         equ 0003h
ADACCL_ACC3_POSITION                     equ 0003h
ADACCL_ACC3_SIZE                         equ 0001h
ADACCL_ACC3_LENGTH                       equ 0001h
ADACCL_ACC3_MASK                         equ 0008h
ADACCL_ACC4_POSN                         equ 0004h
ADACCL_ACC4_POSITION                     equ 0004h
ADACCL_ACC4_SIZE                         equ 0001h
ADACCL_ACC4_LENGTH                       equ 0001h
ADACCL_ACC4_MASK                         equ 0010h
ADACCL_ACC5_POSN                         equ 0005h
ADACCL_ACC5_POSITION                     equ 0005h
ADACCL_ACC5_SIZE                         equ 0001h
ADACCL_ACC5_LENGTH                       equ 0001h
ADACCL_ACC5_MASK                         equ 0020h
ADACCL_ACC6_POSN                         equ 0006h
ADACCL_ACC6_POSITION                     equ 0006h
ADACCL_ACC6_SIZE                         equ 0001h
ADACCL_ACC6_LENGTH                       equ 0001h
ADACCL_ACC6_MASK                         equ 0040h
ADACCL_ACC7_POSN                         equ 0007h
ADACCL_ACC7_POSITION                     equ 0007h
ADACCL_ACC7_SIZE                         equ 0001h
ADACCL_ACC7_LENGTH                       equ 0001h
ADACCL_ACC7_MASK                         equ 0080h

// Register: ADACCH
#define ADACCH ADACCH
ADACCH                                   equ 01D17h
// bitfield definitions
ADACCH_ACC_POSN                          equ 0000h
ADACCH_ACC_POSITION                      equ 0000h
ADACCH_ACC_SIZE                          equ 0008h
ADACCH_ACC_LENGTH                        equ 0008h
ADACCH_ACC_MASK                          equ 00FFh
ADACCH_ADACC8_POSN                       equ 0000h
ADACCH_ADACC8_POSITION                   equ 0000h
ADACCH_ADACC8_SIZE                       equ 0001h
ADACCH_ADACC8_LENGTH                     equ 0001h
ADACCH_ADACC8_MASK                       equ 0001h
ADACCH_ADACC9_POSN                       equ 0001h
ADACCH_ADACC9_POSITION                   equ 0001h
ADACCH_ADACC9_SIZE                       equ 0001h
ADACCH_ADACC9_LENGTH                     equ 0001h
ADACCH_ADACC9_MASK                       equ 0002h
ADACCH_ADACC10_POSN                      equ 0002h
ADACCH_ADACC10_POSITION                  equ 0002h
ADACCH_ADACC10_SIZE                      equ 0001h
ADACCH_ADACC10_LENGTH                    equ 0001h
ADACCH_ADACC10_MASK                      equ 0004h
ADACCH_ADACC11_POSN                      equ 0003h
ADACCH_ADACC11_POSITION                  equ 0003h
ADACCH_ADACC11_SIZE                      equ 0001h
ADACCH_ADACC11_LENGTH                    equ 0001h
ADACCH_ADACC11_MASK                      equ 0008h
ADACCH_ADACC12_POSN                      equ 0004h
ADACCH_ADACC12_POSITION                  equ 0004h
ADACCH_ADACC12_SIZE                      equ 0001h
ADACCH_ADACC12_LENGTH                    equ 0001h
ADACCH_ADACC12_MASK                      equ 0010h
ADACCH_ADACC13_POSN                      equ 0005h
ADACCH_ADACC13_POSITION                  equ 0005h
ADACCH_ADACC13_SIZE                      equ 0001h
ADACCH_ADACC13_LENGTH                    equ 0001h
ADACCH_ADACC13_MASK                      equ 0020h
ADACCH_ADACC14_POSN                      equ 0006h
ADACCH_ADACC14_POSITION                  equ 0006h
ADACCH_ADACC14_SIZE                      equ 0001h
ADACCH_ADACC14_LENGTH                    equ 0001h
ADACCH_ADACC14_MASK                      equ 0040h
ADACCH_ADACC15_POSN                      equ 0007h
ADACCH_ADACC15_POSITION                  equ 0007h
ADACCH_ADACC15_SIZE                      equ 0001h
ADACCH_ADACC15_LENGTH                    equ 0001h
ADACCH_ADACC15_MASK                      equ 0080h
ADACCH_ADACC_POSN                        equ 0000h
ADACCH_ADACC_POSITION                    equ 0000h
ADACCH_ADACC_SIZE                        equ 0008h
ADACCH_ADACC_LENGTH                      equ 0008h
ADACCH_ADACC_MASK                        equ 00FFh
ADACCH_ACC8_POSN                         equ 0000h
ADACCH_ACC8_POSITION                     equ 0000h
ADACCH_ACC8_SIZE                         equ 0001h
ADACCH_ACC8_LENGTH                       equ 0001h
ADACCH_ACC8_MASK                         equ 0001h
ADACCH_ACC9_POSN                         equ 0001h
ADACCH_ACC9_POSITION                     equ 0001h
ADACCH_ACC9_SIZE                         equ 0001h
ADACCH_ACC9_LENGTH                       equ 0001h
ADACCH_ACC9_MASK                         equ 0002h
ADACCH_ACC10_POSN                        equ 0002h
ADACCH_ACC10_POSITION                    equ 0002h
ADACCH_ACC10_SIZE                        equ 0001h
ADACCH_ACC10_LENGTH                      equ 0001h
ADACCH_ACC10_MASK                        equ 0004h
ADACCH_ACC11_POSN                        equ 0003h
ADACCH_ACC11_POSITION                    equ 0003h
ADACCH_ACC11_SIZE                        equ 0001h
ADACCH_ACC11_LENGTH                      equ 0001h
ADACCH_ACC11_MASK                        equ 0008h
ADACCH_ACC12_POSN                        equ 0004h
ADACCH_ACC12_POSITION                    equ 0004h
ADACCH_ACC12_SIZE                        equ 0001h
ADACCH_ACC12_LENGTH                      equ 0001h
ADACCH_ACC12_MASK                        equ 0010h
ADACCH_ACC13_POSN                        equ 0005h
ADACCH_ACC13_POSITION                    equ 0005h
ADACCH_ACC13_SIZE                        equ 0001h
ADACCH_ACC13_LENGTH                      equ 0001h
ADACCH_ACC13_MASK                        equ 0020h
ADACCH_ACC14_POSN                        equ 0006h
ADACCH_ACC14_POSITION                    equ 0006h
ADACCH_ACC14_SIZE                        equ 0001h
ADACCH_ACC14_LENGTH                      equ 0001h
ADACCH_ACC14_MASK                        equ 0040h
ADACCH_ACC15_POSN                        equ 0007h
ADACCH_ACC15_POSITION                    equ 0007h
ADACCH_ACC15_SIZE                        equ 0001h
ADACCH_ACC15_LENGTH                      equ 0001h
ADACCH_ACC15_MASK                        equ 0080h

// Register: ADACCU
#define ADACCU ADACCU
ADACCU                                   equ 01D18h
// bitfield definitions
ADACCU_ACC_POSN                          equ 0000h
ADACCU_ACC_POSITION                      equ 0000h
ADACCU_ACC_SIZE                          equ 0008h
ADACCU_ACC_LENGTH                        equ 0008h
ADACCU_ACC_MASK                          equ 00FFh
ADACCU_ADACC16_POSN                      equ 0000h
ADACCU_ADACC16_POSITION                  equ 0000h
ADACCU_ADACC16_SIZE                      equ 0001h
ADACCU_ADACC16_LENGTH                    equ 0001h
ADACCU_ADACC16_MASK                      equ 0001h
ADACCU_ADACC17_POSN                      equ 0001h
ADACCU_ADACC17_POSITION                  equ 0001h
ADACCU_ADACC17_SIZE                      equ 0001h
ADACCU_ADACC17_LENGTH                    equ 0001h
ADACCU_ADACC17_MASK                      equ 0002h
ADACCU_ADACC_POSN                        equ 0000h
ADACCU_ADACC_POSITION                    equ 0000h
ADACCU_ADACC_SIZE                        equ 0008h
ADACCU_ADACC_LENGTH                      equ 0008h
ADACCU_ADACC_MASK                        equ 00FFh
ADACCU_ACC16_POSN                        equ 0000h
ADACCU_ACC16_POSITION                    equ 0000h
ADACCU_ACC16_SIZE                        equ 0001h
ADACCU_ACC16_LENGTH                      equ 0001h
ADACCU_ACC16_MASK                        equ 0001h
ADACCU_ACC17_POSN                        equ 0001h
ADACCU_ACC17_POSITION                    equ 0001h
ADACCU_ACC17_SIZE                        equ 0001h
ADACCU_ACC17_LENGTH                      equ 0001h
ADACCU_ACC17_MASK                        equ 0002h

// Register: ADCNT
#define ADCNT ADCNT
ADCNT                                    equ 01D19h
// bitfield definitions
ADCNT_CNT_POSN                           equ 0000h
ADCNT_CNT_POSITION                       equ 0000h
ADCNT_CNT_SIZE                           equ 0008h
ADCNT_CNT_LENGTH                         equ 0008h
ADCNT_CNT_MASK                           equ 00FFh
ADCNT_ADCNT0_POSN                        equ 0000h
ADCNT_ADCNT0_POSITION                    equ 0000h
ADCNT_ADCNT0_SIZE                        equ 0001h
ADCNT_ADCNT0_LENGTH                      equ 0001h
ADCNT_ADCNT0_MASK                        equ 0001h
ADCNT_ADCNT1_POSN                        equ 0001h
ADCNT_ADCNT1_POSITION                    equ 0001h
ADCNT_ADCNT1_SIZE                        equ 0001h
ADCNT_ADCNT1_LENGTH                      equ 0001h
ADCNT_ADCNT1_MASK                        equ 0002h
ADCNT_ADCNT2_POSN                        equ 0002h
ADCNT_ADCNT2_POSITION                    equ 0002h
ADCNT_ADCNT2_SIZE                        equ 0001h
ADCNT_ADCNT2_LENGTH                      equ 0001h
ADCNT_ADCNT2_MASK                        equ 0004h
ADCNT_ADCNT3_POSN                        equ 0003h
ADCNT_ADCNT3_POSITION                    equ 0003h
ADCNT_ADCNT3_SIZE                        equ 0001h
ADCNT_ADCNT3_LENGTH                      equ 0001h
ADCNT_ADCNT3_MASK                        equ 0008h
ADCNT_ADCNT4_POSN                        equ 0004h
ADCNT_ADCNT4_POSITION                    equ 0004h
ADCNT_ADCNT4_SIZE                        equ 0001h
ADCNT_ADCNT4_LENGTH                      equ 0001h
ADCNT_ADCNT4_MASK                        equ 0010h
ADCNT_ADCNT5_POSN                        equ 0005h
ADCNT_ADCNT5_POSITION                    equ 0005h
ADCNT_ADCNT5_SIZE                        equ 0001h
ADCNT_ADCNT5_LENGTH                      equ 0001h
ADCNT_ADCNT5_MASK                        equ 0020h
ADCNT_ADCNT6_POSN                        equ 0006h
ADCNT_ADCNT6_POSITION                    equ 0006h
ADCNT_ADCNT6_SIZE                        equ 0001h
ADCNT_ADCNT6_LENGTH                      equ 0001h
ADCNT_ADCNT6_MASK                        equ 0040h
ADCNT_ADCNT7_POSN                        equ 0007h
ADCNT_ADCNT7_POSITION                    equ 0007h
ADCNT_ADCNT7_SIZE                        equ 0001h
ADCNT_ADCNT7_LENGTH                      equ 0001h
ADCNT_ADCNT7_MASK                        equ 0080h
ADCNT_ADCNT_POSN                         equ 0000h
ADCNT_ADCNT_POSITION                     equ 0000h
ADCNT_ADCNT_SIZE                         equ 0008h
ADCNT_ADCNT_LENGTH                       equ 0008h
ADCNT_ADCNT_MASK                         equ 00FFh
ADCNT_CNT0_POSN                          equ 0000h
ADCNT_CNT0_POSITION                      equ 0000h
ADCNT_CNT0_SIZE                          equ 0001h
ADCNT_CNT0_LENGTH                        equ 0001h
ADCNT_CNT0_MASK                          equ 0001h
ADCNT_CNT1_POSN                          equ 0001h
ADCNT_CNT1_POSITION                      equ 0001h
ADCNT_CNT1_SIZE                          equ 0001h
ADCNT_CNT1_LENGTH                        equ 0001h
ADCNT_CNT1_MASK                          equ 0002h
ADCNT_CNT2_POSN                          equ 0002h
ADCNT_CNT2_POSITION                      equ 0002h
ADCNT_CNT2_SIZE                          equ 0001h
ADCNT_CNT2_LENGTH                        equ 0001h
ADCNT_CNT2_MASK                          equ 0004h
ADCNT_CNT3_POSN                          equ 0003h
ADCNT_CNT3_POSITION                      equ 0003h
ADCNT_CNT3_SIZE                          equ 0001h
ADCNT_CNT3_LENGTH                        equ 0001h
ADCNT_CNT3_MASK                          equ 0008h
ADCNT_CNT4_POSN                          equ 0004h
ADCNT_CNT4_POSITION                      equ 0004h
ADCNT_CNT4_SIZE                          equ 0001h
ADCNT_CNT4_LENGTH                        equ 0001h
ADCNT_CNT4_MASK                          equ 0010h
ADCNT_CNT5_POSN                          equ 0005h
ADCNT_CNT5_POSITION                      equ 0005h
ADCNT_CNT5_SIZE                          equ 0001h
ADCNT_CNT5_LENGTH                        equ 0001h
ADCNT_CNT5_MASK                          equ 0020h
ADCNT_CNT6_POSN                          equ 0006h
ADCNT_CNT6_POSITION                      equ 0006h
ADCNT_CNT6_SIZE                          equ 0001h
ADCNT_CNT6_LENGTH                        equ 0001h
ADCNT_CNT6_MASK                          equ 0040h
ADCNT_CNT7_POSN                          equ 0007h
ADCNT_CNT7_POSITION                      equ 0007h
ADCNT_CNT7_SIZE                          equ 0001h
ADCNT_CNT7_LENGTH                        equ 0001h
ADCNT_CNT7_MASK                          equ 0080h

// Register: ADRPT
#define ADRPT ADRPT
ADRPT                                    equ 01D1Ah
// bitfield definitions
ADRPT_RPT_POSN                           equ 0000h
ADRPT_RPT_POSITION                       equ 0000h
ADRPT_RPT_SIZE                           equ 0008h
ADRPT_RPT_LENGTH                         equ 0008h
ADRPT_RPT_MASK                           equ 00FFh
ADRPT_ADRPT0_POSN                        equ 0000h
ADRPT_ADRPT0_POSITION                    equ 0000h
ADRPT_ADRPT0_SIZE                        equ 0001h
ADRPT_ADRPT0_LENGTH                      equ 0001h
ADRPT_ADRPT0_MASK                        equ 0001h
ADRPT_ADRPT1_POSN                        equ 0001h
ADRPT_ADRPT1_POSITION                    equ 0001h
ADRPT_ADRPT1_SIZE                        equ 0001h
ADRPT_ADRPT1_LENGTH                      equ 0001h
ADRPT_ADRPT1_MASK                        equ 0002h
ADRPT_ADRPT2_POSN                        equ 0002h
ADRPT_ADRPT2_POSITION                    equ 0002h
ADRPT_ADRPT2_SIZE                        equ 0001h
ADRPT_ADRPT2_LENGTH                      equ 0001h
ADRPT_ADRPT2_MASK                        equ 0004h
ADRPT_ADRPT3_POSN                        equ 0003h
ADRPT_ADRPT3_POSITION                    equ 0003h
ADRPT_ADRPT3_SIZE                        equ 0001h
ADRPT_ADRPT3_LENGTH                      equ 0001h
ADRPT_ADRPT3_MASK                        equ 0008h
ADRPT_ADRPT4_POSN                        equ 0004h
ADRPT_ADRPT4_POSITION                    equ 0004h
ADRPT_ADRPT4_SIZE                        equ 0001h
ADRPT_ADRPT4_LENGTH                      equ 0001h
ADRPT_ADRPT4_MASK                        equ 0010h
ADRPT_ADRPT5_POSN                        equ 0005h
ADRPT_ADRPT5_POSITION                    equ 0005h
ADRPT_ADRPT5_SIZE                        equ 0001h
ADRPT_ADRPT5_LENGTH                      equ 0001h
ADRPT_ADRPT5_MASK                        equ 0020h
ADRPT_ADRPT6_POSN                        equ 0006h
ADRPT_ADRPT6_POSITION                    equ 0006h
ADRPT_ADRPT6_SIZE                        equ 0001h
ADRPT_ADRPT6_LENGTH                      equ 0001h
ADRPT_ADRPT6_MASK                        equ 0040h
ADRPT_ADRPT7_POSN                        equ 0007h
ADRPT_ADRPT7_POSITION                    equ 0007h
ADRPT_ADRPT7_SIZE                        equ 0001h
ADRPT_ADRPT7_LENGTH                      equ 0001h
ADRPT_ADRPT7_MASK                        equ 0080h
ADRPT_ADRPT_POSN                         equ 0000h
ADRPT_ADRPT_POSITION                     equ 0000h
ADRPT_ADRPT_SIZE                         equ 0008h
ADRPT_ADRPT_LENGTH                       equ 0008h
ADRPT_ADRPT_MASK                         equ 00FFh
ADRPT_RPT0_POSN                          equ 0000h
ADRPT_RPT0_POSITION                      equ 0000h
ADRPT_RPT0_SIZE                          equ 0001h
ADRPT_RPT0_LENGTH                        equ 0001h
ADRPT_RPT0_MASK                          equ 0001h
ADRPT_RPT1_POSN                          equ 0001h
ADRPT_RPT1_POSITION                      equ 0001h
ADRPT_RPT1_SIZE                          equ 0001h
ADRPT_RPT1_LENGTH                        equ 0001h
ADRPT_RPT1_MASK                          equ 0002h
ADRPT_RPT2_POSN                          equ 0002h
ADRPT_RPT2_POSITION                      equ 0002h
ADRPT_RPT2_SIZE                          equ 0001h
ADRPT_RPT2_LENGTH                        equ 0001h
ADRPT_RPT2_MASK                          equ 0004h
ADRPT_RPT3_POSN                          equ 0003h
ADRPT_RPT3_POSITION                      equ 0003h
ADRPT_RPT3_SIZE                          equ 0001h
ADRPT_RPT3_LENGTH                        equ 0001h
ADRPT_RPT3_MASK                          equ 0008h
ADRPT_RPT4_POSN                          equ 0004h
ADRPT_RPT4_POSITION                      equ 0004h
ADRPT_RPT4_SIZE                          equ 0001h
ADRPT_RPT4_LENGTH                        equ 0001h
ADRPT_RPT4_MASK                          equ 0010h
ADRPT_RPT5_POSN                          equ 0005h
ADRPT_RPT5_POSITION                      equ 0005h
ADRPT_RPT5_SIZE                          equ 0001h
ADRPT_RPT5_LENGTH                        equ 0001h
ADRPT_RPT5_MASK                          equ 0020h
ADRPT_RPT6_POSN                          equ 0006h
ADRPT_RPT6_POSITION                      equ 0006h
ADRPT_RPT6_SIZE                          equ 0001h
ADRPT_RPT6_LENGTH                        equ 0001h
ADRPT_RPT6_MASK                          equ 0040h
ADRPT_RPT7_POSN                          equ 0007h
ADRPT_RPT7_POSITION                      equ 0007h
ADRPT_RPT7_SIZE                          equ 0001h
ADRPT_RPT7_LENGTH                        equ 0001h
ADRPT_RPT7_MASK                          equ 0080h

// Register: ADPREVL
#define ADPREVL ADPREVL
ADPREVL                                  equ 01D1Bh
// bitfield definitions
ADPREVL_PREV_POSN                        equ 0000h
ADPREVL_PREV_POSITION                    equ 0000h
ADPREVL_PREV_SIZE                        equ 0008h
ADPREVL_PREV_LENGTH                      equ 0008h
ADPREVL_PREV_MASK                        equ 00FFh
ADPREVL_ADPREV0_POSN                     equ 0000h
ADPREVL_ADPREV0_POSITION                 equ 0000h
ADPREVL_ADPREV0_SIZE                     equ 0001h
ADPREVL_ADPREV0_LENGTH                   equ 0001h
ADPREVL_ADPREV0_MASK                     equ 0001h
ADPREVL_ADPREV1_POSN                     equ 0001h
ADPREVL_ADPREV1_POSITION                 equ 0001h
ADPREVL_ADPREV1_SIZE                     equ 0001h
ADPREVL_ADPREV1_LENGTH                   equ 0001h
ADPREVL_ADPREV1_MASK                     equ 0002h
ADPREVL_ADPREV2_POSN                     equ 0002h
ADPREVL_ADPREV2_POSITION                 equ 0002h
ADPREVL_ADPREV2_SIZE                     equ 0001h
ADPREVL_ADPREV2_LENGTH                   equ 0001h
ADPREVL_ADPREV2_MASK                     equ 0004h
ADPREVL_ADPREV3_POSN                     equ 0003h
ADPREVL_ADPREV3_POSITION                 equ 0003h
ADPREVL_ADPREV3_SIZE                     equ 0001h
ADPREVL_ADPREV3_LENGTH                   equ 0001h
ADPREVL_ADPREV3_MASK                     equ 0008h
ADPREVL_ADPREV4_POSN                     equ 0004h
ADPREVL_ADPREV4_POSITION                 equ 0004h
ADPREVL_ADPREV4_SIZE                     equ 0001h
ADPREVL_ADPREV4_LENGTH                   equ 0001h
ADPREVL_ADPREV4_MASK                     equ 0010h
ADPREVL_ADPREV5_POSN                     equ 0005h
ADPREVL_ADPREV5_POSITION                 equ 0005h
ADPREVL_ADPREV5_SIZE                     equ 0001h
ADPREVL_ADPREV5_LENGTH                   equ 0001h
ADPREVL_ADPREV5_MASK                     equ 0020h
ADPREVL_ADPREV6_POSN                     equ 0006h
ADPREVL_ADPREV6_POSITION                 equ 0006h
ADPREVL_ADPREV6_SIZE                     equ 0001h
ADPREVL_ADPREV6_LENGTH                   equ 0001h
ADPREVL_ADPREV6_MASK                     equ 0040h
ADPREVL_ADPREV7_POSN                     equ 0007h
ADPREVL_ADPREV7_POSITION                 equ 0007h
ADPREVL_ADPREV7_SIZE                     equ 0001h
ADPREVL_ADPREV7_LENGTH                   equ 0001h
ADPREVL_ADPREV7_MASK                     equ 0080h
ADPREVL_ADPREV_POSN                      equ 0000h
ADPREVL_ADPREV_POSITION                  equ 0000h
ADPREVL_ADPREV_SIZE                      equ 0008h
ADPREVL_ADPREV_LENGTH                    equ 0008h
ADPREVL_ADPREV_MASK                      equ 00FFh
ADPREVL_PREV0_POSN                       equ 0000h
ADPREVL_PREV0_POSITION                   equ 0000h
ADPREVL_PREV0_SIZE                       equ 0001h
ADPREVL_PREV0_LENGTH                     equ 0001h
ADPREVL_PREV0_MASK                       equ 0001h
ADPREVL_PREV1_POSN                       equ 0001h
ADPREVL_PREV1_POSITION                   equ 0001h
ADPREVL_PREV1_SIZE                       equ 0001h
ADPREVL_PREV1_LENGTH                     equ 0001h
ADPREVL_PREV1_MASK                       equ 0002h
ADPREVL_PREV2_POSN                       equ 0002h
ADPREVL_PREV2_POSITION                   equ 0002h
ADPREVL_PREV2_SIZE                       equ 0001h
ADPREVL_PREV2_LENGTH                     equ 0001h
ADPREVL_PREV2_MASK                       equ 0004h
ADPREVL_PREV3_POSN                       equ 0003h
ADPREVL_PREV3_POSITION                   equ 0003h
ADPREVL_PREV3_SIZE                       equ 0001h
ADPREVL_PREV3_LENGTH                     equ 0001h
ADPREVL_PREV3_MASK                       equ 0008h
ADPREVL_PREV4_POSN                       equ 0004h
ADPREVL_PREV4_POSITION                   equ 0004h
ADPREVL_PREV4_SIZE                       equ 0001h
ADPREVL_PREV4_LENGTH                     equ 0001h
ADPREVL_PREV4_MASK                       equ 0010h
ADPREVL_PREV5_POSN                       equ 0005h
ADPREVL_PREV5_POSITION                   equ 0005h
ADPREVL_PREV5_SIZE                       equ 0001h
ADPREVL_PREV5_LENGTH                     equ 0001h
ADPREVL_PREV5_MASK                       equ 0020h
ADPREVL_PREV6_POSN                       equ 0006h
ADPREVL_PREV6_POSITION                   equ 0006h
ADPREVL_PREV6_SIZE                       equ 0001h
ADPREVL_PREV6_LENGTH                     equ 0001h
ADPREVL_PREV6_MASK                       equ 0040h
ADPREVL_PREV7_POSN                       equ 0007h
ADPREVL_PREV7_POSITION                   equ 0007h
ADPREVL_PREV7_SIZE                       equ 0001h
ADPREVL_PREV7_LENGTH                     equ 0001h
ADPREVL_PREV7_MASK                       equ 0080h

// Register: ADPREVH
#define ADPREVH ADPREVH
ADPREVH                                  equ 01D1Ch
// bitfield definitions
ADPREVH_PREV_POSN                        equ 0000h
ADPREVH_PREV_POSITION                    equ 0000h
ADPREVH_PREV_SIZE                        equ 0008h
ADPREVH_PREV_LENGTH                      equ 0008h
ADPREVH_PREV_MASK                        equ 00FFh
ADPREVH_ADPREV8_POSN                     equ 0000h
ADPREVH_ADPREV8_POSITION                 equ 0000h
ADPREVH_ADPREV8_SIZE                     equ 0001h
ADPREVH_ADPREV8_LENGTH                   equ 0001h
ADPREVH_ADPREV8_MASK                     equ 0001h
ADPREVH_ADPREV9_POSN                     equ 0001h
ADPREVH_ADPREV9_POSITION                 equ 0001h
ADPREVH_ADPREV9_SIZE                     equ 0001h
ADPREVH_ADPREV9_LENGTH                   equ 0001h
ADPREVH_ADPREV9_MASK                     equ 0002h
ADPREVH_ADPREV10_POSN                    equ 0002h
ADPREVH_ADPREV10_POSITION                equ 0002h
ADPREVH_ADPREV10_SIZE                    equ 0001h
ADPREVH_ADPREV10_LENGTH                  equ 0001h
ADPREVH_ADPREV10_MASK                    equ 0004h
ADPREVH_ADPREV11_POSN                    equ 0003h
ADPREVH_ADPREV11_POSITION                equ 0003h
ADPREVH_ADPREV11_SIZE                    equ 0001h
ADPREVH_ADPREV11_LENGTH                  equ 0001h
ADPREVH_ADPREV11_MASK                    equ 0008h
ADPREVH_ADPREV12_POSN                    equ 0004h
ADPREVH_ADPREV12_POSITION                equ 0004h
ADPREVH_ADPREV12_SIZE                    equ 0001h
ADPREVH_ADPREV12_LENGTH                  equ 0001h
ADPREVH_ADPREV12_MASK                    equ 0010h
ADPREVH_ADPREV13_POSN                    equ 0005h
ADPREVH_ADPREV13_POSITION                equ 0005h
ADPREVH_ADPREV13_SIZE                    equ 0001h
ADPREVH_ADPREV13_LENGTH                  equ 0001h
ADPREVH_ADPREV13_MASK                    equ 0020h
ADPREVH_ADPREV14_POSN                    equ 0006h
ADPREVH_ADPREV14_POSITION                equ 0006h
ADPREVH_ADPREV14_SIZE                    equ 0001h
ADPREVH_ADPREV14_LENGTH                  equ 0001h
ADPREVH_ADPREV14_MASK                    equ 0040h
ADPREVH_ADPREV15_POSN                    equ 0007h
ADPREVH_ADPREV15_POSITION                equ 0007h
ADPREVH_ADPREV15_SIZE                    equ 0001h
ADPREVH_ADPREV15_LENGTH                  equ 0001h
ADPREVH_ADPREV15_MASK                    equ 0080h
ADPREVH_ADPREV_POSN                      equ 0000h
ADPREVH_ADPREV_POSITION                  equ 0000h
ADPREVH_ADPREV_SIZE                      equ 0008h
ADPREVH_ADPREV_LENGTH                    equ 0008h
ADPREVH_ADPREV_MASK                      equ 00FFh
ADPREVH_PREV8_POSN                       equ 0000h
ADPREVH_PREV8_POSITION                   equ 0000h
ADPREVH_PREV8_SIZE                       equ 0001h
ADPREVH_PREV8_LENGTH                     equ 0001h
ADPREVH_PREV8_MASK                       equ 0001h
ADPREVH_PREV9_POSN                       equ 0001h
ADPREVH_PREV9_POSITION                   equ 0001h
ADPREVH_PREV9_SIZE                       equ 0001h
ADPREVH_PREV9_LENGTH                     equ 0001h
ADPREVH_PREV9_MASK                       equ 0002h
ADPREVH_PREV10_POSN                      equ 0002h
ADPREVH_PREV10_POSITION                  equ 0002h
ADPREVH_PREV10_SIZE                      equ 0001h
ADPREVH_PREV10_LENGTH                    equ 0001h
ADPREVH_PREV10_MASK                      equ 0004h
ADPREVH_PREV11_POSN                      equ 0003h
ADPREVH_PREV11_POSITION                  equ 0003h
ADPREVH_PREV11_SIZE                      equ 0001h
ADPREVH_PREV11_LENGTH                    equ 0001h
ADPREVH_PREV11_MASK                      equ 0008h
ADPREVH_PREV12_POSN                      equ 0004h
ADPREVH_PREV12_POSITION                  equ 0004h
ADPREVH_PREV12_SIZE                      equ 0001h
ADPREVH_PREV12_LENGTH                    equ 0001h
ADPREVH_PREV12_MASK                      equ 0010h
ADPREVH_PREV13_POSN                      equ 0005h
ADPREVH_PREV13_POSITION                  equ 0005h
ADPREVH_PREV13_SIZE                      equ 0001h
ADPREVH_PREV13_LENGTH                    equ 0001h
ADPREVH_PREV13_MASK                      equ 0020h
ADPREVH_PREV14_POSN                      equ 0006h
ADPREVH_PREV14_POSITION                  equ 0006h
ADPREVH_PREV14_SIZE                      equ 0001h
ADPREVH_PREV14_LENGTH                    equ 0001h
ADPREVH_PREV14_MASK                      equ 0040h
ADPREVH_PREV15_POSN                      equ 0007h
ADPREVH_PREV15_POSITION                  equ 0007h
ADPREVH_PREV15_SIZE                      equ 0001h
ADPREVH_PREV15_LENGTH                    equ 0001h
ADPREVH_PREV15_MASK                      equ 0080h

// Register: ADRESL
#define ADRESL ADRESL
ADRESL                                   equ 01D1Dh
// bitfield definitions
ADRESL_RES_POSN                          equ 0000h
ADRESL_RES_POSITION                      equ 0000h
ADRESL_RES_SIZE                          equ 0008h
ADRESL_RES_LENGTH                        equ 0008h
ADRESL_RES_MASK                          equ 00FFh
ADRESL_ADRES0_POSN                       equ 0000h
ADRESL_ADRES0_POSITION                   equ 0000h
ADRESL_ADRES0_SIZE                       equ 0001h
ADRESL_ADRES0_LENGTH                     equ 0001h
ADRESL_ADRES0_MASK                       equ 0001h
ADRESL_ADRES1_POSN                       equ 0001h
ADRESL_ADRES1_POSITION                   equ 0001h
ADRESL_ADRES1_SIZE                       equ 0001h
ADRESL_ADRES1_LENGTH                     equ 0001h
ADRESL_ADRES1_MASK                       equ 0002h
ADRESL_ADRES2_POSN                       equ 0002h
ADRESL_ADRES2_POSITION                   equ 0002h
ADRESL_ADRES2_SIZE                       equ 0001h
ADRESL_ADRES2_LENGTH                     equ 0001h
ADRESL_ADRES2_MASK                       equ 0004h
ADRESL_ADRES3_POSN                       equ 0003h
ADRESL_ADRES3_POSITION                   equ 0003h
ADRESL_ADRES3_SIZE                       equ 0001h
ADRESL_ADRES3_LENGTH                     equ 0001h
ADRESL_ADRES3_MASK                       equ 0008h
ADRESL_ADRES4_POSN                       equ 0004h
ADRESL_ADRES4_POSITION                   equ 0004h
ADRESL_ADRES4_SIZE                       equ 0001h
ADRESL_ADRES4_LENGTH                     equ 0001h
ADRESL_ADRES4_MASK                       equ 0010h
ADRESL_ADRES5_POSN                       equ 0005h
ADRESL_ADRES5_POSITION                   equ 0005h
ADRESL_ADRES5_SIZE                       equ 0001h
ADRESL_ADRES5_LENGTH                     equ 0001h
ADRESL_ADRES5_MASK                       equ 0020h
ADRESL_ADRES6_POSN                       equ 0006h
ADRESL_ADRES6_POSITION                   equ 0006h
ADRESL_ADRES6_SIZE                       equ 0001h
ADRESL_ADRES6_LENGTH                     equ 0001h
ADRESL_ADRES6_MASK                       equ 0040h
ADRESL_ADRES7_POSN                       equ 0007h
ADRESL_ADRES7_POSITION                   equ 0007h
ADRESL_ADRES7_SIZE                       equ 0001h
ADRESL_ADRES7_LENGTH                     equ 0001h
ADRESL_ADRES7_MASK                       equ 0080h
ADRESL_ADRES_POSN                        equ 0000h
ADRESL_ADRES_POSITION                    equ 0000h
ADRESL_ADRES_SIZE                        equ 0008h
ADRESL_ADRES_LENGTH                      equ 0008h
ADRESL_ADRES_MASK                        equ 00FFh
ADRESL_RES0_POSN                         equ 0000h
ADRESL_RES0_POSITION                     equ 0000h
ADRESL_RES0_SIZE                         equ 0001h
ADRESL_RES0_LENGTH                       equ 0001h
ADRESL_RES0_MASK                         equ 0001h
ADRESL_RES1_POSN                         equ 0001h
ADRESL_RES1_POSITION                     equ 0001h
ADRESL_RES1_SIZE                         equ 0001h
ADRESL_RES1_LENGTH                       equ 0001h
ADRESL_RES1_MASK                         equ 0002h
ADRESL_RES2_POSN                         equ 0002h
ADRESL_RES2_POSITION                     equ 0002h
ADRESL_RES2_SIZE                         equ 0001h
ADRESL_RES2_LENGTH                       equ 0001h
ADRESL_RES2_MASK                         equ 0004h
ADRESL_RES3_POSN                         equ 0003h
ADRESL_RES3_POSITION                     equ 0003h
ADRESL_RES3_SIZE                         equ 0001h
ADRESL_RES3_LENGTH                       equ 0001h
ADRESL_RES3_MASK                         equ 0008h
ADRESL_RES4_POSN                         equ 0004h
ADRESL_RES4_POSITION                     equ 0004h
ADRESL_RES4_SIZE                         equ 0001h
ADRESL_RES4_LENGTH                       equ 0001h
ADRESL_RES4_MASK                         equ 0010h
ADRESL_RES5_POSN                         equ 0005h
ADRESL_RES5_POSITION                     equ 0005h
ADRESL_RES5_SIZE                         equ 0001h
ADRESL_RES5_LENGTH                       equ 0001h
ADRESL_RES5_MASK                         equ 0020h
ADRESL_RES6_POSN                         equ 0006h
ADRESL_RES6_POSITION                     equ 0006h
ADRESL_RES6_SIZE                         equ 0001h
ADRESL_RES6_LENGTH                       equ 0001h
ADRESL_RES6_MASK                         equ 0040h
ADRESL_RES7_POSN                         equ 0007h
ADRESL_RES7_POSITION                     equ 0007h
ADRESL_RES7_SIZE                         equ 0001h
ADRESL_RES7_LENGTH                       equ 0001h
ADRESL_RES7_MASK                         equ 0080h

// Register: ADRESH
#define ADRESH ADRESH
ADRESH                                   equ 01D1Eh
// bitfield definitions
ADRESH_ADRES8_POSN                       equ 0000h
ADRESH_ADRES8_POSITION                   equ 0000h
ADRESH_ADRES8_SIZE                       equ 0001h
ADRESH_ADRES8_LENGTH                     equ 0001h
ADRESH_ADRES8_MASK                       equ 0001h
ADRESH_ADRES9_POSN                       equ 0001h
ADRESH_ADRES9_POSITION                   equ 0001h
ADRESH_ADRES9_SIZE                       equ 0001h
ADRESH_ADRES9_LENGTH                     equ 0001h
ADRESH_ADRES9_MASK                       equ 0002h
ADRESH_ADRES10_POSN                      equ 0002h
ADRESH_ADRES10_POSITION                  equ 0002h
ADRESH_ADRES10_SIZE                      equ 0001h
ADRESH_ADRES10_LENGTH                    equ 0001h
ADRESH_ADRES10_MASK                      equ 0004h
ADRESH_ADRES11_POSN                      equ 0003h
ADRESH_ADRES11_POSITION                  equ 0003h
ADRESH_ADRES11_SIZE                      equ 0001h
ADRESH_ADRES11_LENGTH                    equ 0001h
ADRESH_ADRES11_MASK                      equ 0008h
ADRESH_ADRES12_POSN                      equ 0004h
ADRESH_ADRES12_POSITION                  equ 0004h
ADRESH_ADRES12_SIZE                      equ 0001h
ADRESH_ADRES12_LENGTH                    equ 0001h
ADRESH_ADRES12_MASK                      equ 0010h
ADRESH_ADRES13_POSN                      equ 0005h
ADRESH_ADRES13_POSITION                  equ 0005h
ADRESH_ADRES13_SIZE                      equ 0001h
ADRESH_ADRES13_LENGTH                    equ 0001h
ADRESH_ADRES13_MASK                      equ 0020h
ADRESH_ADRES14_POSN                      equ 0006h
ADRESH_ADRES14_POSITION                  equ 0006h
ADRESH_ADRES14_SIZE                      equ 0001h
ADRESH_ADRES14_LENGTH                    equ 0001h
ADRESH_ADRES14_MASK                      equ 0040h
ADRESH_ADRES15_POSN                      equ 0007h
ADRESH_ADRES15_POSITION                  equ 0007h
ADRESH_ADRES15_SIZE                      equ 0001h
ADRESH_ADRES15_LENGTH                    equ 0001h
ADRESH_ADRES15_MASK                      equ 0080h
ADRESH_ADRES_POSN                        equ 0000h
ADRESH_ADRES_POSITION                    equ 0000h
ADRESH_ADRES_SIZE                        equ 0008h
ADRESH_ADRES_LENGTH                      equ 0008h
ADRESH_ADRES_MASK                        equ 00FFh
ADRESH_RES8_POSN                         equ 0000h
ADRESH_RES8_POSITION                     equ 0000h
ADRESH_RES8_SIZE                         equ 0001h
ADRESH_RES8_LENGTH                       equ 0001h
ADRESH_RES8_MASK                         equ 0001h
ADRESH_RES9_POSN                         equ 0001h
ADRESH_RES9_POSITION                     equ 0001h
ADRESH_RES9_SIZE                         equ 0001h
ADRESH_RES9_LENGTH                       equ 0001h
ADRESH_RES9_MASK                         equ 0002h
ADRESH_RES10_POSN                        equ 0002h
ADRESH_RES10_POSITION                    equ 0002h
ADRESH_RES10_SIZE                        equ 0001h
ADRESH_RES10_LENGTH                      equ 0001h
ADRESH_RES10_MASK                        equ 0004h
ADRESH_RES11_POSN                        equ 0003h
ADRESH_RES11_POSITION                    equ 0003h
ADRESH_RES11_SIZE                        equ 0001h
ADRESH_RES11_LENGTH                      equ 0001h
ADRESH_RES11_MASK                        equ 0008h
ADRESH_RES12_POSN                        equ 0004h
ADRESH_RES12_POSITION                    equ 0004h
ADRESH_RES12_SIZE                        equ 0001h
ADRESH_RES12_LENGTH                      equ 0001h
ADRESH_RES12_MASK                        equ 0010h
ADRESH_RES13_POSN                        equ 0005h
ADRESH_RES13_POSITION                    equ 0005h
ADRESH_RES13_SIZE                        equ 0001h
ADRESH_RES13_LENGTH                      equ 0001h
ADRESH_RES13_MASK                        equ 0020h
ADRESH_RES14_POSN                        equ 0006h
ADRESH_RES14_POSITION                    equ 0006h
ADRESH_RES14_SIZE                        equ 0001h
ADRESH_RES14_LENGTH                      equ 0001h
ADRESH_RES14_MASK                        equ 0040h
ADRESH_RES15_POSN                        equ 0007h
ADRESH_RES15_POSITION                    equ 0007h
ADRESH_RES15_SIZE                        equ 0001h
ADRESH_RES15_LENGTH                      equ 0001h
ADRESH_RES15_MASK                        equ 0080h

// Register: ADPCH
#define ADPCH ADPCH
ADPCH                                    equ 01D1Fh
// bitfield definitions
ADPCH_PCH_POSN                           equ 0000h
ADPCH_PCH_POSITION                       equ 0000h
ADPCH_PCH_SIZE                           equ 0008h
ADPCH_PCH_LENGTH                         equ 0008h
ADPCH_PCH_MASK                           equ 00FFh
ADPCH_ADPCH0_POSN                        equ 0000h
ADPCH_ADPCH0_POSITION                    equ 0000h
ADPCH_ADPCH0_SIZE                        equ 0001h
ADPCH_ADPCH0_LENGTH                      equ 0001h
ADPCH_ADPCH0_MASK                        equ 0001h
ADPCH_ADPCH1_POSN                        equ 0001h
ADPCH_ADPCH1_POSITION                    equ 0001h
ADPCH_ADPCH1_SIZE                        equ 0001h
ADPCH_ADPCH1_LENGTH                      equ 0001h
ADPCH_ADPCH1_MASK                        equ 0002h
ADPCH_ADPCH2_POSN                        equ 0002h
ADPCH_ADPCH2_POSITION                    equ 0002h
ADPCH_ADPCH2_SIZE                        equ 0001h
ADPCH_ADPCH2_LENGTH                      equ 0001h
ADPCH_ADPCH2_MASK                        equ 0004h
ADPCH_ADPCH3_POSN                        equ 0003h
ADPCH_ADPCH3_POSITION                    equ 0003h
ADPCH_ADPCH3_SIZE                        equ 0001h
ADPCH_ADPCH3_LENGTH                      equ 0001h
ADPCH_ADPCH3_MASK                        equ 0008h
ADPCH_ADPCH4_POSN                        equ 0004h
ADPCH_ADPCH4_POSITION                    equ 0004h
ADPCH_ADPCH4_SIZE                        equ 0001h
ADPCH_ADPCH4_LENGTH                      equ 0001h
ADPCH_ADPCH4_MASK                        equ 0010h
ADPCH_ADPCH5_POSN                        equ 0005h
ADPCH_ADPCH5_POSITION                    equ 0005h
ADPCH_ADPCH5_SIZE                        equ 0001h
ADPCH_ADPCH5_LENGTH                      equ 0001h
ADPCH_ADPCH5_MASK                        equ 0020h

// Register: ADACQL
#define ADACQL ADACQL
ADACQL                                   equ 01D21h
// bitfield definitions
ADACQL_ACQ_POSN                          equ 0000h
ADACQL_ACQ_POSITION                      equ 0000h
ADACQL_ACQ_SIZE                          equ 0008h
ADACQL_ACQ_LENGTH                        equ 0008h
ADACQL_ACQ_MASK                          equ 00FFh
ADACQL_ADACQ0_POSN                       equ 0000h
ADACQL_ADACQ0_POSITION                   equ 0000h
ADACQL_ADACQ0_SIZE                       equ 0001h
ADACQL_ADACQ0_LENGTH                     equ 0001h
ADACQL_ADACQ0_MASK                       equ 0001h
ADACQL_ADACQ1_POSN                       equ 0001h
ADACQL_ADACQ1_POSITION                   equ 0001h
ADACQL_ADACQ1_SIZE                       equ 0001h
ADACQL_ADACQ1_LENGTH                     equ 0001h
ADACQL_ADACQ1_MASK                       equ 0002h
ADACQL_ADACQ2_POSN                       equ 0002h
ADACQL_ADACQ2_POSITION                   equ 0002h
ADACQL_ADACQ2_SIZE                       equ 0001h
ADACQL_ADACQ2_LENGTH                     equ 0001h
ADACQL_ADACQ2_MASK                       equ 0004h
ADACQL_ADACQ3_POSN                       equ 0003h
ADACQL_ADACQ3_POSITION                   equ 0003h
ADACQL_ADACQ3_SIZE                       equ 0001h
ADACQL_ADACQ3_LENGTH                     equ 0001h
ADACQL_ADACQ3_MASK                       equ 0008h
ADACQL_ADACQ4_POSN                       equ 0004h
ADACQL_ADACQ4_POSITION                   equ 0004h
ADACQL_ADACQ4_SIZE                       equ 0001h
ADACQL_ADACQ4_LENGTH                     equ 0001h
ADACQL_ADACQ4_MASK                       equ 0010h
ADACQL_ADACQ5_POSN                       equ 0005h
ADACQL_ADACQ5_POSITION                   equ 0005h
ADACQL_ADACQ5_SIZE                       equ 0001h
ADACQL_ADACQ5_LENGTH                     equ 0001h
ADACQL_ADACQ5_MASK                       equ 0020h
ADACQL_ADACQ6_POSN                       equ 0006h
ADACQL_ADACQ6_POSITION                   equ 0006h
ADACQL_ADACQ6_SIZE                       equ 0001h
ADACQL_ADACQ6_LENGTH                     equ 0001h
ADACQL_ADACQ6_MASK                       equ 0040h
ADACQL_ADACQ7_POSN                       equ 0007h
ADACQL_ADACQ7_POSITION                   equ 0007h
ADACQL_ADACQ7_SIZE                       equ 0001h
ADACQL_ADACQ7_LENGTH                     equ 0001h
ADACQL_ADACQ7_MASK                       equ 0080h
ADACQL_ADACQ_POSN                        equ 0000h
ADACQL_ADACQ_POSITION                    equ 0000h
ADACQL_ADACQ_SIZE                        equ 0008h
ADACQL_ADACQ_LENGTH                      equ 0008h
ADACQL_ADACQ_MASK                        equ 00FFh
ADACQL_ACQ0_POSN                         equ 0000h
ADACQL_ACQ0_POSITION                     equ 0000h
ADACQL_ACQ0_SIZE                         equ 0001h
ADACQL_ACQ0_LENGTH                       equ 0001h
ADACQL_ACQ0_MASK                         equ 0001h
ADACQL_ACQ1_POSN                         equ 0001h
ADACQL_ACQ1_POSITION                     equ 0001h
ADACQL_ACQ1_SIZE                         equ 0001h
ADACQL_ACQ1_LENGTH                       equ 0001h
ADACQL_ACQ1_MASK                         equ 0002h
ADACQL_ACQ2_POSN                         equ 0002h
ADACQL_ACQ2_POSITION                     equ 0002h
ADACQL_ACQ2_SIZE                         equ 0001h
ADACQL_ACQ2_LENGTH                       equ 0001h
ADACQL_ACQ2_MASK                         equ 0004h
ADACQL_ACQ3_POSN                         equ 0003h
ADACQL_ACQ3_POSITION                     equ 0003h
ADACQL_ACQ3_SIZE                         equ 0001h
ADACQL_ACQ3_LENGTH                       equ 0001h
ADACQL_ACQ3_MASK                         equ 0008h
ADACQL_ACQ4_POSN                         equ 0004h
ADACQL_ACQ4_POSITION                     equ 0004h
ADACQL_ACQ4_SIZE                         equ 0001h
ADACQL_ACQ4_LENGTH                       equ 0001h
ADACQL_ACQ4_MASK                         equ 0010h
ADACQL_ACQ5_POSN                         equ 0005h
ADACQL_ACQ5_POSITION                     equ 0005h
ADACQL_ACQ5_SIZE                         equ 0001h
ADACQL_ACQ5_LENGTH                       equ 0001h
ADACQL_ACQ5_MASK                         equ 0020h
ADACQL_ACQ6_POSN                         equ 0006h
ADACQL_ACQ6_POSITION                     equ 0006h
ADACQL_ACQ6_SIZE                         equ 0001h
ADACQL_ACQ6_LENGTH                       equ 0001h
ADACQL_ACQ6_MASK                         equ 0040h
ADACQL_ACQ7_POSN                         equ 0007h
ADACQL_ACQ7_POSITION                     equ 0007h
ADACQL_ACQ7_SIZE                         equ 0001h
ADACQL_ACQ7_LENGTH                       equ 0001h
ADACQL_ACQ7_MASK                         equ 0080h

// Register: ADACQH
#define ADACQH ADACQH
ADACQH                                   equ 01D22h
// bitfield definitions
ADACQH_ACQ_POSN                          equ 0000h
ADACQH_ACQ_POSITION                      equ 0000h
ADACQH_ACQ_SIZE                          equ 0005h
ADACQH_ACQ_LENGTH                        equ 0005h
ADACQH_ACQ_MASK                          equ 001Fh
ADACQH_ADACQ8_POSN                       equ 0000h
ADACQH_ADACQ8_POSITION                   equ 0000h
ADACQH_ADACQ8_SIZE                       equ 0001h
ADACQH_ADACQ8_LENGTH                     equ 0001h
ADACQH_ADACQ8_MASK                       equ 0001h
ADACQH_ADACQ9_POSN                       equ 0001h
ADACQH_ADACQ9_POSITION                   equ 0001h
ADACQH_ADACQ9_SIZE                       equ 0001h
ADACQH_ADACQ9_LENGTH                     equ 0001h
ADACQH_ADACQ9_MASK                       equ 0002h
ADACQH_ADACQ10_POSN                      equ 0002h
ADACQH_ADACQ10_POSITION                  equ 0002h
ADACQH_ADACQ10_SIZE                      equ 0001h
ADACQH_ADACQ10_LENGTH                    equ 0001h
ADACQH_ADACQ10_MASK                      equ 0004h
ADACQH_ADACQ11_POSN                      equ 0003h
ADACQH_ADACQ11_POSITION                  equ 0003h
ADACQH_ADACQ11_SIZE                      equ 0001h
ADACQH_ADACQ11_LENGTH                    equ 0001h
ADACQH_ADACQ11_MASK                      equ 0008h
ADACQH_ADACQ12_POSN                      equ 0004h
ADACQH_ADACQ12_POSITION                  equ 0004h
ADACQH_ADACQ12_SIZE                      equ 0001h
ADACQH_ADACQ12_LENGTH                    equ 0001h
ADACQH_ADACQ12_MASK                      equ 0010h
ADACQH_ADACQ_POSN                        equ 0000h
ADACQH_ADACQ_POSITION                    equ 0000h
ADACQH_ADACQ_SIZE                        equ 0005h
ADACQH_ADACQ_LENGTH                      equ 0005h
ADACQH_ADACQ_MASK                        equ 001Fh
ADACQH_ACQ8_POSN                         equ 0000h
ADACQH_ACQ8_POSITION                     equ 0000h
ADACQH_ACQ8_SIZE                         equ 0001h
ADACQH_ACQ8_LENGTH                       equ 0001h
ADACQH_ACQ8_MASK                         equ 0001h
ADACQH_ACQ9_POSN                         equ 0001h
ADACQH_ACQ9_POSITION                     equ 0001h
ADACQH_ACQ9_SIZE                         equ 0001h
ADACQH_ACQ9_LENGTH                       equ 0001h
ADACQH_ACQ9_MASK                         equ 0002h
ADACQH_ACQ10_POSN                        equ 0002h
ADACQH_ACQ10_POSITION                    equ 0002h
ADACQH_ACQ10_SIZE                        equ 0001h
ADACQH_ACQ10_LENGTH                      equ 0001h
ADACQH_ACQ10_MASK                        equ 0004h
ADACQH_ACQ11_POSN                        equ 0003h
ADACQH_ACQ11_POSITION                    equ 0003h
ADACQH_ACQ11_SIZE                        equ 0001h
ADACQH_ACQ11_LENGTH                      equ 0001h
ADACQH_ACQ11_MASK                        equ 0008h
ADACQH_ACQ12_POSN                        equ 0004h
ADACQH_ACQ12_POSITION                    equ 0004h
ADACQH_ACQ12_SIZE                        equ 0001h
ADACQH_ACQ12_LENGTH                      equ 0001h
ADACQH_ACQ12_MASK                        equ 0010h

// Register: ADCAP
#define ADCAP ADCAP
ADCAP                                    equ 01D23h
// bitfield definitions
ADCAP_CAP_POSN                           equ 0000h
ADCAP_CAP_POSITION                       equ 0000h
ADCAP_CAP_SIZE                           equ 0008h
ADCAP_CAP_LENGTH                         equ 0008h
ADCAP_CAP_MASK                           equ 00FFh
ADCAP_ADCAP0_POSN                        equ 0000h
ADCAP_ADCAP0_POSITION                    equ 0000h
ADCAP_ADCAP0_SIZE                        equ 0001h
ADCAP_ADCAP0_LENGTH                      equ 0001h
ADCAP_ADCAP0_MASK                        equ 0001h
ADCAP_ADCAP1_POSN                        equ 0001h
ADCAP_ADCAP1_POSITION                    equ 0001h
ADCAP_ADCAP1_SIZE                        equ 0001h
ADCAP_ADCAP1_LENGTH                      equ 0001h
ADCAP_ADCAP1_MASK                        equ 0002h
ADCAP_ADCAP2_POSN                        equ 0002h
ADCAP_ADCAP2_POSITION                    equ 0002h
ADCAP_ADCAP2_SIZE                        equ 0001h
ADCAP_ADCAP2_LENGTH                      equ 0001h
ADCAP_ADCAP2_MASK                        equ 0004h
ADCAP_ADCAP3_POSN                        equ 0003h
ADCAP_ADCAP3_POSITION                    equ 0003h
ADCAP_ADCAP3_SIZE                        equ 0001h
ADCAP_ADCAP3_LENGTH                      equ 0001h
ADCAP_ADCAP3_MASK                        equ 0008h
ADCAP_ADCAP4_POSN                        equ 0004h
ADCAP_ADCAP4_POSITION                    equ 0004h
ADCAP_ADCAP4_SIZE                        equ 0001h
ADCAP_ADCAP4_LENGTH                      equ 0001h
ADCAP_ADCAP4_MASK                        equ 0010h

// Register: ADPREL
#define ADPREL ADPREL
ADPREL                                   equ 01D24h
// bitfield definitions
ADPREL_PRE_POSN                          equ 0000h
ADPREL_PRE_POSITION                      equ 0000h
ADPREL_PRE_SIZE                          equ 0008h
ADPREL_PRE_LENGTH                        equ 0008h
ADPREL_PRE_MASK                          equ 00FFh
ADPREL_PRE0_POSN                         equ 0000h
ADPREL_PRE0_POSITION                     equ 0000h
ADPREL_PRE0_SIZE                         equ 0001h
ADPREL_PRE0_LENGTH                       equ 0001h
ADPREL_PRE0_MASK                         equ 0001h
ADPREL_PRE1_POSN                         equ 0001h
ADPREL_PRE1_POSITION                     equ 0001h
ADPREL_PRE1_SIZE                         equ 0001h
ADPREL_PRE1_LENGTH                       equ 0001h
ADPREL_PRE1_MASK                         equ 0002h
ADPREL_PRE2_POSN                         equ 0002h
ADPREL_PRE2_POSITION                     equ 0002h
ADPREL_PRE2_SIZE                         equ 0001h
ADPREL_PRE2_LENGTH                       equ 0001h
ADPREL_PRE2_MASK                         equ 0004h
ADPREL_PRE3_POSN                         equ 0003h
ADPREL_PRE3_POSITION                     equ 0003h
ADPREL_PRE3_SIZE                         equ 0001h
ADPREL_PRE3_LENGTH                       equ 0001h
ADPREL_PRE3_MASK                         equ 0008h
ADPREL_PRE4_POSN                         equ 0004h
ADPREL_PRE4_POSITION                     equ 0004h
ADPREL_PRE4_SIZE                         equ 0001h
ADPREL_PRE4_LENGTH                       equ 0001h
ADPREL_PRE4_MASK                         equ 0010h
ADPREL_PRE5_POSN                         equ 0005h
ADPREL_PRE5_POSITION                     equ 0005h
ADPREL_PRE5_SIZE                         equ 0001h
ADPREL_PRE5_LENGTH                       equ 0001h
ADPREL_PRE5_MASK                         equ 0020h
ADPREL_PRE6_POSN                         equ 0006h
ADPREL_PRE6_POSITION                     equ 0006h
ADPREL_PRE6_SIZE                         equ 0001h
ADPREL_PRE6_LENGTH                       equ 0001h
ADPREL_PRE6_MASK                         equ 0040h
ADPREL_PRE7_POSN                         equ 0007h
ADPREL_PRE7_POSITION                     equ 0007h
ADPREL_PRE7_SIZE                         equ 0001h
ADPREL_PRE7_LENGTH                       equ 0001h
ADPREL_PRE7_MASK                         equ 0080h
ADPREL_ADPRE_POSN                        equ 0000h
ADPREL_ADPRE_POSITION                    equ 0000h
ADPREL_ADPRE_SIZE                        equ 0008h
ADPREL_ADPRE_LENGTH                      equ 0008h
ADPREL_ADPRE_MASK                        equ 00FFh
ADPREL_ADPRE0_POSN                       equ 0000h
ADPREL_ADPRE0_POSITION                   equ 0000h
ADPREL_ADPRE0_SIZE                       equ 0001h
ADPREL_ADPRE0_LENGTH                     equ 0001h
ADPREL_ADPRE0_MASK                       equ 0001h
ADPREL_ADPRE1_POSN                       equ 0001h
ADPREL_ADPRE1_POSITION                   equ 0001h
ADPREL_ADPRE1_SIZE                       equ 0001h
ADPREL_ADPRE1_LENGTH                     equ 0001h
ADPREL_ADPRE1_MASK                       equ 0002h
ADPREL_ADPRE2_POSN                       equ 0002h
ADPREL_ADPRE2_POSITION                   equ 0002h
ADPREL_ADPRE2_SIZE                       equ 0001h
ADPREL_ADPRE2_LENGTH                     equ 0001h
ADPREL_ADPRE2_MASK                       equ 0004h
ADPREL_ADPRE3_POSN                       equ 0003h
ADPREL_ADPRE3_POSITION                   equ 0003h
ADPREL_ADPRE3_SIZE                       equ 0001h
ADPREL_ADPRE3_LENGTH                     equ 0001h
ADPREL_ADPRE3_MASK                       equ 0008h
ADPREL_ADPRE4_POSN                       equ 0004h
ADPREL_ADPRE4_POSITION                   equ 0004h
ADPREL_ADPRE4_SIZE                       equ 0001h
ADPREL_ADPRE4_LENGTH                     equ 0001h
ADPREL_ADPRE4_MASK                       equ 0010h
ADPREL_ADPRE5_POSN                       equ 0005h
ADPREL_ADPRE5_POSITION                   equ 0005h
ADPREL_ADPRE5_SIZE                       equ 0001h
ADPREL_ADPRE5_LENGTH                     equ 0001h
ADPREL_ADPRE5_MASK                       equ 0020h
ADPREL_ADPRE6_POSN                       equ 0006h
ADPREL_ADPRE6_POSITION                   equ 0006h
ADPREL_ADPRE6_SIZE                       equ 0001h
ADPREL_ADPRE6_LENGTH                     equ 0001h
ADPREL_ADPRE6_MASK                       equ 0040h
ADPREL_ADPRE7_POSN                       equ 0007h
ADPREL_ADPRE7_POSITION                   equ 0007h
ADPREL_ADPRE7_SIZE                       equ 0001h
ADPREL_ADPRE7_LENGTH                     equ 0001h
ADPREL_ADPRE7_MASK                       equ 0080h

// Register: ADPREH
#define ADPREH ADPREH
ADPREH                                   equ 01D25h
// bitfield definitions
ADPREH_PRE_POSN                          equ 0000h
ADPREH_PRE_POSITION                      equ 0000h
ADPREH_PRE_SIZE                          equ 0005h
ADPREH_PRE_LENGTH                        equ 0005h
ADPREH_PRE_MASK                          equ 001Fh
ADPREH_PRE8_POSN                         equ 0000h
ADPREH_PRE8_POSITION                     equ 0000h
ADPREH_PRE8_SIZE                         equ 0001h
ADPREH_PRE8_LENGTH                       equ 0001h
ADPREH_PRE8_MASK                         equ 0001h
ADPREH_PRE9_POSN                         equ 0001h
ADPREH_PRE9_POSITION                     equ 0001h
ADPREH_PRE9_SIZE                         equ 0001h
ADPREH_PRE9_LENGTH                       equ 0001h
ADPREH_PRE9_MASK                         equ 0002h
ADPREH_PRE10_POSN                        equ 0002h
ADPREH_PRE10_POSITION                    equ 0002h
ADPREH_PRE10_SIZE                        equ 0001h
ADPREH_PRE10_LENGTH                      equ 0001h
ADPREH_PRE10_MASK                        equ 0004h
ADPREH_PRE11_POSN                        equ 0003h
ADPREH_PRE11_POSITION                    equ 0003h
ADPREH_PRE11_SIZE                        equ 0001h
ADPREH_PRE11_LENGTH                      equ 0001h
ADPREH_PRE11_MASK                        equ 0008h
ADPREH_PRE12_POSN                        equ 0004h
ADPREH_PRE12_POSITION                    equ 0004h
ADPREH_PRE12_SIZE                        equ 0001h
ADPREH_PRE12_LENGTH                      equ 0001h
ADPREH_PRE12_MASK                        equ 0010h
ADPREH_ADPRE_POSN                        equ 0000h
ADPREH_ADPRE_POSITION                    equ 0000h
ADPREH_ADPRE_SIZE                        equ 0005h
ADPREH_ADPRE_LENGTH                      equ 0005h
ADPREH_ADPRE_MASK                        equ 001Fh
ADPREH_ADPRE8_POSN                       equ 0000h
ADPREH_ADPRE8_POSITION                   equ 0000h
ADPREH_ADPRE8_SIZE                       equ 0001h
ADPREH_ADPRE8_LENGTH                     equ 0001h
ADPREH_ADPRE8_MASK                       equ 0001h
ADPREH_ADPRE9_POSN                       equ 0001h
ADPREH_ADPRE9_POSITION                   equ 0001h
ADPREH_ADPRE9_SIZE                       equ 0001h
ADPREH_ADPRE9_LENGTH                     equ 0001h
ADPREH_ADPRE9_MASK                       equ 0002h
ADPREH_ADPRE10_POSN                      equ 0002h
ADPREH_ADPRE10_POSITION                  equ 0002h
ADPREH_ADPRE10_SIZE                      equ 0001h
ADPREH_ADPRE10_LENGTH                    equ 0001h
ADPREH_ADPRE10_MASK                      equ 0004h
ADPREH_ADPRE11_POSN                      equ 0003h
ADPREH_ADPRE11_POSITION                  equ 0003h
ADPREH_ADPRE11_SIZE                      equ 0001h
ADPREH_ADPRE11_LENGTH                    equ 0001h
ADPREH_ADPRE11_MASK                      equ 0008h
ADPREH_ADPRE12_POSN                      equ 0004h
ADPREH_ADPRE12_POSITION                  equ 0004h
ADPREH_ADPRE12_SIZE                      equ 0001h
ADPREH_ADPRE12_LENGTH                    equ 0001h
ADPREH_ADPRE12_MASK                      equ 0010h

// Register: ADCON0
#define ADCON0 ADCON0
ADCON0                                   equ 01D26h
// bitfield definitions
ADCON0_GO_POSN                           equ 0000h
ADCON0_GO_POSITION                       equ 0000h
ADCON0_GO_SIZE                           equ 0001h
ADCON0_GO_LENGTH                         equ 0001h
ADCON0_GO_MASK                           equ 0001h
ADCON0_FM_POSN                           equ 0002h
ADCON0_FM_POSITION                       equ 0002h
ADCON0_FM_SIZE                           equ 0002h
ADCON0_FM_LENGTH                         equ 0002h
ADCON0_FM_MASK                           equ 000Ch
ADCON0_CS_POSN                           equ 0004h
ADCON0_CS_POSITION                       equ 0004h
ADCON0_CS_SIZE                           equ 0001h
ADCON0_CS_LENGTH                         equ 0001h
ADCON0_CS_MASK                           equ 0010h
ADCON0_CONT_POSN                         equ 0006h
ADCON0_CONT_POSITION                     equ 0006h
ADCON0_CONT_SIZE                         equ 0001h
ADCON0_CONT_LENGTH                       equ 0001h
ADCON0_CONT_MASK                         equ 0040h
ADCON0_ON_POSN                           equ 0007h
ADCON0_ON_POSITION                       equ 0007h
ADCON0_ON_SIZE                           equ 0001h
ADCON0_ON_LENGTH                         equ 0001h
ADCON0_ON_MASK                           equ 0080h
ADCON0_ADGO_POSN                         equ 0000h
ADCON0_ADGO_POSITION                     equ 0000h
ADCON0_ADGO_SIZE                         equ 0001h
ADCON0_ADGO_LENGTH                       equ 0001h
ADCON0_ADGO_MASK                         equ 0001h
ADCON0_ADFM_POSN                         equ 0002h
ADCON0_ADFM_POSITION                     equ 0002h
ADCON0_ADFM_SIZE                         equ 0002h
ADCON0_ADFM_LENGTH                       equ 0002h
ADCON0_ADFM_MASK                         equ 000Ch
ADCON0_ADCS_POSN                         equ 0004h
ADCON0_ADCS_POSITION                     equ 0004h
ADCON0_ADCS_SIZE                         equ 0001h
ADCON0_ADCS_LENGTH                       equ 0001h
ADCON0_ADCS_MASK                         equ 0010h
ADCON0_ADCONT_POSN                       equ 0006h
ADCON0_ADCONT_POSITION                   equ 0006h
ADCON0_ADCONT_SIZE                       equ 0001h
ADCON0_ADCONT_LENGTH                     equ 0001h
ADCON0_ADCONT_MASK                       equ 0040h
ADCON0_ADON_POSN                         equ 0007h
ADCON0_ADON_POSITION                     equ 0007h
ADCON0_ADON_SIZE                         equ 0001h
ADCON0_ADON_LENGTH                       equ 0001h
ADCON0_ADON_MASK                         equ 0080h
ADCON0_DONE_POSN                         equ 0000h
ADCON0_DONE_POSITION                     equ 0000h
ADCON0_DONE_SIZE                         equ 0001h
ADCON0_DONE_LENGTH                       equ 0001h
ADCON0_DONE_MASK                         equ 0001h
ADCON0_FM0_POSN                          equ 0002h
ADCON0_FM0_POSITION                      equ 0002h
ADCON0_FM0_SIZE                          equ 0001h
ADCON0_FM0_LENGTH                        equ 0001h
ADCON0_FM0_MASK                          equ 0004h
ADCON0_GO_nDONE_POSN                     equ 0000h
ADCON0_GO_nDONE_POSITION                 equ 0000h
ADCON0_GO_nDONE_SIZE                     equ 0001h
ADCON0_GO_nDONE_LENGTH                   equ 0001h
ADCON0_GO_nDONE_MASK                     equ 0001h
ADCON0_ADFM0_POSN                        equ 0002h
ADCON0_ADFM0_POSITION                    equ 0002h
ADCON0_ADFM0_SIZE                        equ 0001h
ADCON0_ADFM0_LENGTH                      equ 0001h
ADCON0_ADFM0_MASK                        equ 0004h

// Register: ADCON1
#define ADCON1 ADCON1
ADCON1                                   equ 01D27h
// bitfield definitions
ADCON1_DSEN_POSN                         equ 0000h
ADCON1_DSEN_POSITION                     equ 0000h
ADCON1_DSEN_SIZE                         equ 0001h
ADCON1_DSEN_LENGTH                       equ 0001h
ADCON1_DSEN_MASK                         equ 0001h
ADCON1_PCSC_POSN                         equ 0001h
ADCON1_PCSC_POSITION                     equ 0001h
ADCON1_PCSC_SIZE                         equ 0001h
ADCON1_PCSC_LENGTH                       equ 0001h
ADCON1_PCSC_MASK                         equ 0002h
ADCON1_GPOL_POSN                         equ 0005h
ADCON1_GPOL_POSITION                     equ 0005h
ADCON1_GPOL_SIZE                         equ 0001h
ADCON1_GPOL_LENGTH                       equ 0001h
ADCON1_GPOL_MASK                         equ 0020h
ADCON1_IPEN_POSN                         equ 0006h
ADCON1_IPEN_POSITION                     equ 0006h
ADCON1_IPEN_SIZE                         equ 0001h
ADCON1_IPEN_LENGTH                       equ 0001h
ADCON1_IPEN_MASK                         equ 0040h
ADCON1_PPOL_POSN                         equ 0007h
ADCON1_PPOL_POSITION                     equ 0007h
ADCON1_PPOL_SIZE                         equ 0001h
ADCON1_PPOL_LENGTH                       equ 0001h
ADCON1_PPOL_MASK                         equ 0080h
ADCON1_ADDSEN_POSN                       equ 0000h
ADCON1_ADDSEN_POSITION                   equ 0000h
ADCON1_ADDSEN_SIZE                       equ 0001h
ADCON1_ADDSEN_LENGTH                     equ 0001h
ADCON1_ADDSEN_MASK                       equ 0001h
ADCON1_ADGPOL_POSN                       equ 0005h
ADCON1_ADGPOL_POSITION                   equ 0005h
ADCON1_ADGPOL_SIZE                       equ 0001h
ADCON1_ADGPOL_LENGTH                     equ 0001h
ADCON1_ADGPOL_MASK                       equ 0020h
ADCON1_ADIPEN_POSN                       equ 0006h
ADCON1_ADIPEN_POSITION                   equ 0006h
ADCON1_ADIPEN_SIZE                       equ 0001h
ADCON1_ADIPEN_LENGTH                     equ 0001h
ADCON1_ADIPEN_MASK                       equ 0040h
ADCON1_ADPPOL_POSN                       equ 0007h
ADCON1_ADPPOL_POSITION                   equ 0007h
ADCON1_ADPPOL_SIZE                       equ 0001h
ADCON1_ADPPOL_LENGTH                     equ 0001h
ADCON1_ADPPOL_MASK                       equ 0080h

// Register: ADCON2
#define ADCON2 ADCON2
ADCON2                                   equ 01D28h
// bitfield definitions
ADCON2_MD_POSN                           equ 0000h
ADCON2_MD_POSITION                       equ 0000h
ADCON2_MD_SIZE                           equ 0003h
ADCON2_MD_LENGTH                         equ 0003h
ADCON2_MD_MASK                           equ 0007h
ADCON2_ACLR_POSN                         equ 0003h
ADCON2_ACLR_POSITION                     equ 0003h
ADCON2_ACLR_SIZE                         equ 0001h
ADCON2_ACLR_LENGTH                       equ 0001h
ADCON2_ACLR_MASK                         equ 0008h
ADCON2_CRS_POSN                          equ 0004h
ADCON2_CRS_POSITION                      equ 0004h
ADCON2_CRS_SIZE                          equ 0003h
ADCON2_CRS_LENGTH                        equ 0003h
ADCON2_CRS_MASK                          equ 0070h
ADCON2_PSIS_POSN                         equ 0007h
ADCON2_PSIS_POSITION                     equ 0007h
ADCON2_PSIS_SIZE                         equ 0001h
ADCON2_PSIS_LENGTH                       equ 0001h
ADCON2_PSIS_MASK                         equ 0080h
ADCON2_ADMD0_POSN                        equ 0000h
ADCON2_ADMD0_POSITION                    equ 0000h
ADCON2_ADMD0_SIZE                        equ 0001h
ADCON2_ADMD0_LENGTH                      equ 0001h
ADCON2_ADMD0_MASK                        equ 0001h
ADCON2_ADMD1_POSN                        equ 0001h
ADCON2_ADMD1_POSITION                    equ 0001h
ADCON2_ADMD1_SIZE                        equ 0001h
ADCON2_ADMD1_LENGTH                      equ 0001h
ADCON2_ADMD1_MASK                        equ 0002h
ADCON2_ADMD2_POSN                        equ 0002h
ADCON2_ADMD2_POSITION                    equ 0002h
ADCON2_ADMD2_SIZE                        equ 0001h
ADCON2_ADMD2_LENGTH                      equ 0001h
ADCON2_ADMD2_MASK                        equ 0004h
ADCON2_ADACLR_POSN                       equ 0003h
ADCON2_ADACLR_POSITION                   equ 0003h
ADCON2_ADACLR_SIZE                       equ 0001h
ADCON2_ADACLR_LENGTH                     equ 0001h
ADCON2_ADACLR_MASK                       equ 0008h
ADCON2_ADCRS0_POSN                       equ 0004h
ADCON2_ADCRS0_POSITION                   equ 0004h
ADCON2_ADCRS0_SIZE                       equ 0001h
ADCON2_ADCRS0_LENGTH                     equ 0001h
ADCON2_ADCRS0_MASK                       equ 0010h
ADCON2_ADCRS1_POSN                       equ 0005h
ADCON2_ADCRS1_POSITION                   equ 0005h
ADCON2_ADCRS1_SIZE                       equ 0001h
ADCON2_ADCRS1_LENGTH                     equ 0001h
ADCON2_ADCRS1_MASK                       equ 0020h
ADCON2_ADCRS2_POSN                       equ 0006h
ADCON2_ADCRS2_POSITION                   equ 0006h
ADCON2_ADCRS2_SIZE                       equ 0001h
ADCON2_ADCRS2_LENGTH                     equ 0001h
ADCON2_ADCRS2_MASK                       equ 0040h
ADCON2_ADPSIS_POSN                       equ 0007h
ADCON2_ADPSIS_POSITION                   equ 0007h
ADCON2_ADPSIS_SIZE                       equ 0001h
ADCON2_ADPSIS_LENGTH                     equ 0001h
ADCON2_ADPSIS_MASK                       equ 0080h
ADCON2_ADMD_POSN                         equ 0000h
ADCON2_ADMD_POSITION                     equ 0000h
ADCON2_ADMD_SIZE                         equ 0003h
ADCON2_ADMD_LENGTH                       equ 0003h
ADCON2_ADMD_MASK                         equ 0007h
ADCON2_ADCRS_POSN                        equ 0004h
ADCON2_ADCRS_POSITION                    equ 0004h
ADCON2_ADCRS_SIZE                        equ 0003h
ADCON2_ADCRS_LENGTH                      equ 0003h
ADCON2_ADCRS_MASK                        equ 0070h
ADCON2_MD0_POSN                          equ 0000h
ADCON2_MD0_POSITION                      equ 0000h
ADCON2_MD0_SIZE                          equ 0001h
ADCON2_MD0_LENGTH                        equ 0001h
ADCON2_MD0_MASK                          equ 0001h
ADCON2_MD1_POSN                          equ 0001h
ADCON2_MD1_POSITION                      equ 0001h
ADCON2_MD1_SIZE                          equ 0001h
ADCON2_MD1_LENGTH                        equ 0001h
ADCON2_MD1_MASK                          equ 0002h
ADCON2_MD2_POSN                          equ 0002h
ADCON2_MD2_POSITION                      equ 0002h
ADCON2_MD2_SIZE                          equ 0001h
ADCON2_MD2_LENGTH                        equ 0001h
ADCON2_MD2_MASK                          equ 0004h
ADCON2_CRS0_POSN                         equ 0004h
ADCON2_CRS0_POSITION                     equ 0004h
ADCON2_CRS0_SIZE                         equ 0001h
ADCON2_CRS0_LENGTH                       equ 0001h
ADCON2_CRS0_MASK                         equ 0010h
ADCON2_CRS1_POSN                         equ 0005h
ADCON2_CRS1_POSITION                     equ 0005h
ADCON2_CRS1_SIZE                         equ 0001h
ADCON2_CRS1_LENGTH                       equ 0001h
ADCON2_CRS1_MASK                         equ 0020h
ADCON2_CRS2_POSN                         equ 0006h
ADCON2_CRS2_POSITION                     equ 0006h
ADCON2_CRS2_SIZE                         equ 0001h
ADCON2_CRS2_LENGTH                       equ 0001h
ADCON2_CRS2_MASK                         equ 0040h

// Register: ADCON3
#define ADCON3 ADCON3
ADCON3                                   equ 01D29h
// bitfield definitions
ADCON3_TMD_POSN                          equ 0000h
ADCON3_TMD_POSITION                      equ 0000h
ADCON3_TMD_SIZE                          equ 0003h
ADCON3_TMD_LENGTH                        equ 0003h
ADCON3_TMD_MASK                          equ 0007h
ADCON3_SOI_POSN                          equ 0003h
ADCON3_SOI_POSITION                      equ 0003h
ADCON3_SOI_SIZE                          equ 0001h
ADCON3_SOI_LENGTH                        equ 0001h
ADCON3_SOI_MASK                          equ 0008h
ADCON3_CALC_POSN                         equ 0004h
ADCON3_CALC_POSITION                     equ 0004h
ADCON3_CALC_SIZE                         equ 0003h
ADCON3_CALC_LENGTH                       equ 0003h
ADCON3_CALC_MASK                         equ 0070h
ADCON3_ADTMD0_POSN                       equ 0000h
ADCON3_ADTMD0_POSITION                   equ 0000h
ADCON3_ADTMD0_SIZE                       equ 0001h
ADCON3_ADTMD0_LENGTH                     equ 0001h
ADCON3_ADTMD0_MASK                       equ 0001h
ADCON3_ADTMD1_POSN                       equ 0001h
ADCON3_ADTMD1_POSITION                   equ 0001h
ADCON3_ADTMD1_SIZE                       equ 0001h
ADCON3_ADTMD1_LENGTH                     equ 0001h
ADCON3_ADTMD1_MASK                       equ 0002h
ADCON3_ADTMD2_POSN                       equ 0002h
ADCON3_ADTMD2_POSITION                   equ 0002h
ADCON3_ADTMD2_SIZE                       equ 0001h
ADCON3_ADTMD2_LENGTH                     equ 0001h
ADCON3_ADTMD2_MASK                       equ 0004h
ADCON3_ADSOI_POSN                        equ 0003h
ADCON3_ADSOI_POSITION                    equ 0003h
ADCON3_ADSOI_SIZE                        equ 0001h
ADCON3_ADSOI_LENGTH                      equ 0001h
ADCON3_ADSOI_MASK                        equ 0008h
ADCON3_ADCALC0_POSN                      equ 0004h
ADCON3_ADCALC0_POSITION                  equ 0004h
ADCON3_ADCALC0_SIZE                      equ 0001h
ADCON3_ADCALC0_LENGTH                    equ 0001h
ADCON3_ADCALC0_MASK                      equ 0010h
ADCON3_ADCALC1_POSN                      equ 0005h
ADCON3_ADCALC1_POSITION                  equ 0005h
ADCON3_ADCALC1_SIZE                      equ 0001h
ADCON3_ADCALC1_LENGTH                    equ 0001h
ADCON3_ADCALC1_MASK                      equ 0020h
ADCON3_ADCALC2_POSN                      equ 0006h
ADCON3_ADCALC2_POSITION                  equ 0006h
ADCON3_ADCALC2_SIZE                      equ 0001h
ADCON3_ADCALC2_LENGTH                    equ 0001h
ADCON3_ADCALC2_MASK                      equ 0040h
ADCON3_ADTMD_POSN                        equ 0000h
ADCON3_ADTMD_POSITION                    equ 0000h
ADCON3_ADTMD_SIZE                        equ 0003h
ADCON3_ADTMD_LENGTH                      equ 0003h
ADCON3_ADTMD_MASK                        equ 0007h
ADCON3_ADCALC_POSN                       equ 0004h
ADCON3_ADCALC_POSITION                   equ 0004h
ADCON3_ADCALC_SIZE                       equ 0003h
ADCON3_ADCALC_LENGTH                     equ 0003h
ADCON3_ADCALC_MASK                       equ 0070h
ADCON3_TMD0_POSN                         equ 0000h
ADCON3_TMD0_POSITION                     equ 0000h
ADCON3_TMD0_SIZE                         equ 0001h
ADCON3_TMD0_LENGTH                       equ 0001h
ADCON3_TMD0_MASK                         equ 0001h
ADCON3_TMD1_POSN                         equ 0001h
ADCON3_TMD1_POSITION                     equ 0001h
ADCON3_TMD1_SIZE                         equ 0001h
ADCON3_TMD1_LENGTH                       equ 0001h
ADCON3_TMD1_MASK                         equ 0002h
ADCON3_TMD2_POSN                         equ 0002h
ADCON3_TMD2_POSITION                     equ 0002h
ADCON3_TMD2_SIZE                         equ 0001h
ADCON3_TMD2_LENGTH                       equ 0001h
ADCON3_TMD2_MASK                         equ 0004h
ADCON3_CALC0_POSN                        equ 0004h
ADCON3_CALC0_POSITION                    equ 0004h
ADCON3_CALC0_SIZE                        equ 0001h
ADCON3_CALC0_LENGTH                      equ 0001h
ADCON3_CALC0_MASK                        equ 0010h
ADCON3_CALC1_POSN                        equ 0005h
ADCON3_CALC1_POSITION                    equ 0005h
ADCON3_CALC1_SIZE                        equ 0001h
ADCON3_CALC1_LENGTH                      equ 0001h
ADCON3_CALC1_MASK                        equ 0020h
ADCON3_CALC2_POSN                        equ 0006h
ADCON3_CALC2_POSITION                    equ 0006h
ADCON3_CALC2_SIZE                        equ 0001h
ADCON3_CALC2_LENGTH                      equ 0001h
ADCON3_CALC2_MASK                        equ 0040h

// Register: ADSTAT
#define ADSTAT ADSTAT
ADSTAT                                   equ 01D2Ah
// bitfield definitions
ADSTAT_STAT_POSN                         equ 0000h
ADSTAT_STAT_POSITION                     equ 0000h
ADSTAT_STAT_SIZE                         equ 0003h
ADSTAT_STAT_LENGTH                       equ 0003h
ADSTAT_STAT_MASK                         equ 0007h
ADSTAT_MATH_POSN                         equ 0004h
ADSTAT_MATH_POSITION                     equ 0004h
ADSTAT_MATH_SIZE                         equ 0001h
ADSTAT_MATH_LENGTH                       equ 0001h
ADSTAT_MATH_MASK                         equ 0010h
ADSTAT_LTHR_POSN                         equ 0005h
ADSTAT_LTHR_POSITION                     equ 0005h
ADSTAT_LTHR_SIZE                         equ 0001h
ADSTAT_LTHR_LENGTH                       equ 0001h
ADSTAT_LTHR_MASK                         equ 0020h
ADSTAT_UTHR_POSN                         equ 0006h
ADSTAT_UTHR_POSITION                     equ 0006h
ADSTAT_UTHR_SIZE                         equ 0001h
ADSTAT_UTHR_LENGTH                       equ 0001h
ADSTAT_UTHR_MASK                         equ 0040h
ADSTAT_AOV_POSN                          equ 0007h
ADSTAT_AOV_POSITION                      equ 0007h
ADSTAT_AOV_SIZE                          equ 0001h
ADSTAT_AOV_LENGTH                        equ 0001h
ADSTAT_AOV_MASK                          equ 0080h
ADSTAT_ADSTAT0_POSN                      equ 0000h
ADSTAT_ADSTAT0_POSITION                  equ 0000h
ADSTAT_ADSTAT0_SIZE                      equ 0001h
ADSTAT_ADSTAT0_LENGTH                    equ 0001h
ADSTAT_ADSTAT0_MASK                      equ 0001h
ADSTAT_ADSTAT1_POSN                      equ 0001h
ADSTAT_ADSTAT1_POSITION                  equ 0001h
ADSTAT_ADSTAT1_SIZE                      equ 0001h
ADSTAT_ADSTAT1_LENGTH                    equ 0001h
ADSTAT_ADSTAT1_MASK                      equ 0002h
ADSTAT_ADSTAT2_POSN                      equ 0002h
ADSTAT_ADSTAT2_POSITION                  equ 0002h
ADSTAT_ADSTAT2_SIZE                      equ 0001h
ADSTAT_ADSTAT2_LENGTH                    equ 0001h
ADSTAT_ADSTAT2_MASK                      equ 0004h
ADSTAT_ADMATH_POSN                       equ 0004h
ADSTAT_ADMATH_POSITION                   equ 0004h
ADSTAT_ADMATH_SIZE                       equ 0001h
ADSTAT_ADMATH_LENGTH                     equ 0001h
ADSTAT_ADMATH_MASK                       equ 0010h
ADSTAT_ADLTHR_POSN                       equ 0005h
ADSTAT_ADLTHR_POSITION                   equ 0005h
ADSTAT_ADLTHR_SIZE                       equ 0001h
ADSTAT_ADLTHR_LENGTH                     equ 0001h
ADSTAT_ADLTHR_MASK                       equ 0020h
ADSTAT_ADUTHR_POSN                       equ 0006h
ADSTAT_ADUTHR_POSITION                   equ 0006h
ADSTAT_ADUTHR_SIZE                       equ 0001h
ADSTAT_ADUTHR_LENGTH                     equ 0001h
ADSTAT_ADUTHR_MASK                       equ 0040h
ADSTAT_ADAOV_POSN                        equ 0007h
ADSTAT_ADAOV_POSITION                    equ 0007h
ADSTAT_ADAOV_SIZE                        equ 0001h
ADSTAT_ADAOV_LENGTH                      equ 0001h
ADSTAT_ADAOV_MASK                        equ 0080h
ADSTAT_ADSTAT_POSN                       equ 0000h
ADSTAT_ADSTAT_POSITION                   equ 0000h
ADSTAT_ADSTAT_SIZE                       equ 0003h
ADSTAT_ADSTAT_LENGTH                     equ 0003h
ADSTAT_ADSTAT_MASK                       equ 0007h
ADSTAT_ADOV_POSN                         equ 0007h
ADSTAT_ADOV_POSITION                     equ 0007h
ADSTAT_ADOV_SIZE                         equ 0001h
ADSTAT_ADOV_LENGTH                       equ 0001h
ADSTAT_ADOV_MASK                         equ 0080h
ADSTAT_STAT0_POSN                        equ 0000h
ADSTAT_STAT0_POSITION                    equ 0000h
ADSTAT_STAT0_SIZE                        equ 0001h
ADSTAT_STAT0_LENGTH                      equ 0001h
ADSTAT_STAT0_MASK                        equ 0001h
ADSTAT_STAT1_POSN                        equ 0001h
ADSTAT_STAT1_POSITION                    equ 0001h
ADSTAT_STAT1_SIZE                        equ 0001h
ADSTAT_STAT1_LENGTH                      equ 0001h
ADSTAT_STAT1_MASK                        equ 0002h
ADSTAT_STAT2_POSN                        equ 0002h
ADSTAT_STAT2_POSITION                    equ 0002h
ADSTAT_STAT2_SIZE                        equ 0001h
ADSTAT_STAT2_LENGTH                      equ 0001h
ADSTAT_STAT2_MASK                        equ 0004h
ADSTAT_OV_POSN                           equ 0007h
ADSTAT_OV_POSITION                       equ 0007h
ADSTAT_OV_SIZE                           equ 0001h
ADSTAT_OV_LENGTH                         equ 0001h
ADSTAT_OV_MASK                           equ 0080h

// Register: ADREF
#define ADREF ADREF
ADREF                                    equ 01D2Bh
// bitfield definitions
ADREF_PREF_POSN                          equ 0000h
ADREF_PREF_POSITION                      equ 0000h
ADREF_PREF_SIZE                          equ 0004h
ADREF_PREF_LENGTH                        equ 0004h
ADREF_PREF_MASK                          equ 000Fh
ADREF_ADPREF_POSN                        equ 0000h
ADREF_ADPREF_POSITION                    equ 0000h
ADREF_ADPREF_SIZE                        equ 0004h
ADREF_ADPREF_LENGTH                      equ 0004h
ADREF_ADPREF_MASK                        equ 000Fh
ADREF_PREF0_POSN                         equ 0000h
ADREF_PREF0_POSITION                     equ 0000h
ADREF_PREF0_SIZE                         equ 0001h
ADREF_PREF0_LENGTH                       equ 0001h
ADREF_PREF0_MASK                         equ 0001h
ADREF_PREF1_POSN                         equ 0001h
ADREF_PREF1_POSITION                     equ 0001h
ADREF_PREF1_SIZE                         equ 0001h
ADREF_PREF1_LENGTH                       equ 0001h
ADREF_PREF1_MASK                         equ 0002h
ADREF_ADPREF0_POSN                       equ 0000h
ADREF_ADPREF0_POSITION                   equ 0000h
ADREF_ADPREF0_SIZE                       equ 0001h
ADREF_ADPREF0_LENGTH                     equ 0001h
ADREF_ADPREF0_MASK                       equ 0001h
ADREF_ADPREF1_POSN                       equ 0001h
ADREF_ADPREF1_POSITION                   equ 0001h
ADREF_ADPREF1_SIZE                       equ 0001h
ADREF_ADPREF1_LENGTH                     equ 0001h
ADREF_ADPREF1_MASK                       equ 0002h

// Register: ADACT
#define ADACT ADACT
ADACT                                    equ 01D2Ch
// bitfield definitions
ADACT_ACT_POSN                           equ 0000h
ADACT_ACT_POSITION                       equ 0000h
ADACT_ACT_SIZE                           equ 0008h
ADACT_ACT_LENGTH                         equ 0008h
ADACT_ACT_MASK                           equ 00FFh
ADACT_ADACT0_POSN                        equ 0000h
ADACT_ADACT0_POSITION                    equ 0000h
ADACT_ADACT0_SIZE                        equ 0001h
ADACT_ADACT0_LENGTH                      equ 0001h
ADACT_ADACT0_MASK                        equ 0001h
ADACT_ADACT1_POSN                        equ 0001h
ADACT_ADACT1_POSITION                    equ 0001h
ADACT_ADACT1_SIZE                        equ 0001h
ADACT_ADACT1_LENGTH                      equ 0001h
ADACT_ADACT1_MASK                        equ 0002h
ADACT_ADACT2_POSN                        equ 0002h
ADACT_ADACT2_POSITION                    equ 0002h
ADACT_ADACT2_SIZE                        equ 0001h
ADACT_ADACT2_LENGTH                      equ 0001h
ADACT_ADACT2_MASK                        equ 0004h
ADACT_ADACT3_POSN                        equ 0003h
ADACT_ADACT3_POSITION                    equ 0003h
ADACT_ADACT3_SIZE                        equ 0001h
ADACT_ADACT3_LENGTH                      equ 0001h
ADACT_ADACT3_MASK                        equ 0008h
ADACT_ADACT4_POSN                        equ 0004h
ADACT_ADACT4_POSITION                    equ 0004h
ADACT_ADACT4_SIZE                        equ 0001h
ADACT_ADACT4_LENGTH                      equ 0001h
ADACT_ADACT4_MASK                        equ 0010h
ADACT_ADACT5_POSN                        equ 0005h
ADACT_ADACT5_POSITION                    equ 0005h
ADACT_ADACT5_SIZE                        equ 0001h
ADACT_ADACT5_LENGTH                      equ 0001h
ADACT_ADACT5_MASK                        equ 0020h
ADACT_ADACT_POSN                         equ 0000h
ADACT_ADACT_POSITION                     equ 0000h
ADACT_ADACT_SIZE                         equ 0008h
ADACT_ADACT_LENGTH                       equ 0008h
ADACT_ADACT_MASK                         equ 00FFh
ADACT_ACT0_POSN                          equ 0000h
ADACT_ACT0_POSITION                      equ 0000h
ADACT_ACT0_SIZE                          equ 0001h
ADACT_ACT0_LENGTH                        equ 0001h
ADACT_ACT0_MASK                          equ 0001h
ADACT_ACT1_POSN                          equ 0001h
ADACT_ACT1_POSITION                      equ 0001h
ADACT_ACT1_SIZE                          equ 0001h
ADACT_ACT1_LENGTH                        equ 0001h
ADACT_ACT1_MASK                          equ 0002h
ADACT_ACT2_POSN                          equ 0002h
ADACT_ACT2_POSITION                      equ 0002h
ADACT_ACT2_SIZE                          equ 0001h
ADACT_ACT2_LENGTH                        equ 0001h
ADACT_ACT2_MASK                          equ 0004h
ADACT_ACT3_POSN                          equ 0003h
ADACT_ACT3_POSITION                      equ 0003h
ADACT_ACT3_SIZE                          equ 0001h
ADACT_ACT3_LENGTH                        equ 0001h
ADACT_ACT3_MASK                          equ 0008h
ADACT_ACT4_POSN                          equ 0004h
ADACT_ACT4_POSITION                      equ 0004h
ADACT_ACT4_SIZE                          equ 0001h
ADACT_ACT4_LENGTH                        equ 0001h
ADACT_ACT4_MASK                          equ 0010h
ADACT_ACT5_POSN                          equ 0005h
ADACT_ACT5_POSITION                      equ 0005h
ADACT_ACT5_SIZE                          equ 0001h
ADACT_ACT5_LENGTH                        equ 0001h
ADACT_ACT5_MASK                          equ 0020h

// Register: ADCLK
#define ADCLK ADCLK
ADCLK                                    equ 01D2Dh
// bitfield definitions
ADCLK_CS_POSN                            equ 0000h
ADCLK_CS_POSITION                        equ 0000h
ADCLK_CS_SIZE                            equ 0008h
ADCLK_CS_LENGTH                          equ 0008h
ADCLK_CS_MASK                            equ 00FFh
ADCLK_ADCS0_POSN                         equ 0000h
ADCLK_ADCS0_POSITION                     equ 0000h
ADCLK_ADCS0_SIZE                         equ 0001h
ADCLK_ADCS0_LENGTH                       equ 0001h
ADCLK_ADCS0_MASK                         equ 0001h
ADCLK_ADCS1_POSN                         equ 0001h
ADCLK_ADCS1_POSITION                     equ 0001h
ADCLK_ADCS1_SIZE                         equ 0001h
ADCLK_ADCS1_LENGTH                       equ 0001h
ADCLK_ADCS1_MASK                         equ 0002h
ADCLK_ADCS2_POSN                         equ 0002h
ADCLK_ADCS2_POSITION                     equ 0002h
ADCLK_ADCS2_SIZE                         equ 0001h
ADCLK_ADCS2_LENGTH                       equ 0001h
ADCLK_ADCS2_MASK                         equ 0004h
ADCLK_ADCS3_POSN                         equ 0003h
ADCLK_ADCS3_POSITION                     equ 0003h
ADCLK_ADCS3_SIZE                         equ 0001h
ADCLK_ADCS3_LENGTH                       equ 0001h
ADCLK_ADCS3_MASK                         equ 0008h
ADCLK_ADCS4_POSN                         equ 0004h
ADCLK_ADCS4_POSITION                     equ 0004h
ADCLK_ADCS4_SIZE                         equ 0001h
ADCLK_ADCS4_LENGTH                       equ 0001h
ADCLK_ADCS4_MASK                         equ 0010h
ADCLK_ADCS5_POSN                         equ 0005h
ADCLK_ADCS5_POSITION                     equ 0005h
ADCLK_ADCS5_SIZE                         equ 0001h
ADCLK_ADCS5_LENGTH                       equ 0001h
ADCLK_ADCS5_MASK                         equ 0020h
ADCLK_ADCS_POSN                          equ 0000h
ADCLK_ADCS_POSITION                      equ 0000h
ADCLK_ADCS_SIZE                          equ 0008h
ADCLK_ADCS_LENGTH                        equ 0008h
ADCLK_ADCS_MASK                          equ 00FFh
ADCLK_CS0_POSN                           equ 0000h
ADCLK_CS0_POSITION                       equ 0000h
ADCLK_CS0_SIZE                           equ 0001h
ADCLK_CS0_LENGTH                         equ 0001h
ADCLK_CS0_MASK                           equ 0001h
ADCLK_CS1_POSN                           equ 0001h
ADCLK_CS1_POSITION                       equ 0001h
ADCLK_CS1_SIZE                           equ 0001h
ADCLK_CS1_LENGTH                         equ 0001h
ADCLK_CS1_MASK                           equ 0002h
ADCLK_CS2_POSN                           equ 0002h
ADCLK_CS2_POSITION                       equ 0002h
ADCLK_CS2_SIZE                           equ 0001h
ADCLK_CS2_LENGTH                         equ 0001h
ADCLK_CS2_MASK                           equ 0004h
ADCLK_CS3_POSN                           equ 0003h
ADCLK_CS3_POSITION                       equ 0003h
ADCLK_CS3_SIZE                           equ 0001h
ADCLK_CS3_LENGTH                         equ 0001h
ADCLK_CS3_MASK                           equ 0008h
ADCLK_CS4_POSN                           equ 0004h
ADCLK_CS4_POSITION                       equ 0004h
ADCLK_CS4_SIZE                           equ 0001h
ADCLK_CS4_LENGTH                         equ 0001h
ADCLK_CS4_MASK                           equ 0010h
ADCLK_CS5_POSN                           equ 0005h
ADCLK_CS5_POSITION                       equ 0005h
ADCLK_CS5_SIZE                           equ 0001h
ADCLK_CS5_LENGTH                         equ 0001h
ADCLK_CS5_MASK                           equ 0020h

// Register: ADCG1A
#define ADCG1A ADCG1A
ADCG1A                                   equ 01D2Eh
// bitfield definitions
ADCG1A_CGA0_POSN                         equ 0000h
ADCG1A_CGA0_POSITION                     equ 0000h
ADCG1A_CGA0_SIZE                         equ 0001h
ADCG1A_CGA0_LENGTH                       equ 0001h
ADCG1A_CGA0_MASK                         equ 0001h
ADCG1A_CGA1_POSN                         equ 0001h
ADCG1A_CGA1_POSITION                     equ 0001h
ADCG1A_CGA1_SIZE                         equ 0001h
ADCG1A_CGA1_LENGTH                       equ 0001h
ADCG1A_CGA1_MASK                         equ 0002h
ADCG1A_CGA2_POSN                         equ 0002h
ADCG1A_CGA2_POSITION                     equ 0002h
ADCG1A_CGA2_SIZE                         equ 0001h
ADCG1A_CGA2_LENGTH                       equ 0001h
ADCG1A_CGA2_MASK                         equ 0004h
ADCG1A_CGA4_POSN                         equ 0004h
ADCG1A_CGA4_POSITION                     equ 0004h
ADCG1A_CGA4_SIZE                         equ 0001h
ADCG1A_CGA4_LENGTH                       equ 0001h
ADCG1A_CGA4_MASK                         equ 0010h
ADCG1A_CGA5_POSN                         equ 0005h
ADCG1A_CGA5_POSITION                     equ 0005h
ADCG1A_CGA5_SIZE                         equ 0001h
ADCG1A_CGA5_LENGTH                       equ 0001h
ADCG1A_CGA5_MASK                         equ 0020h

// Register: RA0PPS
#define RA0PPS RA0PPS
RA0PPS                                   equ 01D8Ch
// bitfield definitions
RA0PPS_RA0PPS_POSN                       equ 0000h
RA0PPS_RA0PPS_POSITION                   equ 0000h
RA0PPS_RA0PPS_SIZE                       equ 0006h
RA0PPS_RA0PPS_LENGTH                     equ 0006h
RA0PPS_RA0PPS_MASK                       equ 003Fh

// Register: RA1PPS
#define RA1PPS RA1PPS
RA1PPS                                   equ 01D8Dh
// bitfield definitions
RA1PPS_RA1PPS_POSN                       equ 0000h
RA1PPS_RA1PPS_POSITION                   equ 0000h
RA1PPS_RA1PPS_SIZE                       equ 0006h
RA1PPS_RA1PPS_LENGTH                     equ 0006h
RA1PPS_RA1PPS_MASK                       equ 003Fh

// Register: RA2PPS
#define RA2PPS RA2PPS
RA2PPS                                   equ 01D8Eh
// bitfield definitions
RA2PPS_RA2PPS_POSN                       equ 0000h
RA2PPS_RA2PPS_POSITION                   equ 0000h
RA2PPS_RA2PPS_SIZE                       equ 0006h
RA2PPS_RA2PPS_LENGTH                     equ 0006h
RA2PPS_RA2PPS_MASK                       equ 003Fh

// Register: RA4PPS
#define RA4PPS RA4PPS
RA4PPS                                   equ 01D90h
// bitfield definitions
RA4PPS_RA4PPS_POSN                       equ 0000h
RA4PPS_RA4PPS_POSITION                   equ 0000h
RA4PPS_RA4PPS_SIZE                       equ 0006h
RA4PPS_RA4PPS_LENGTH                     equ 0006h
RA4PPS_RA4PPS_MASK                       equ 003Fh

// Register: RA5PPS
#define RA5PPS RA5PPS
RA5PPS                                   equ 01D91h
// bitfield definitions
RA5PPS_RA5PPS_POSN                       equ 0000h
RA5PPS_RA5PPS_POSITION                   equ 0000h
RA5PPS_RA5PPS_SIZE                       equ 0006h
RA5PPS_RA5PPS_LENGTH                     equ 0006h
RA5PPS_RA5PPS_MASK                       equ 003Fh

// Register: PPSLOCK
#define PPSLOCK PPSLOCK
PPSLOCK                                  equ 01E0Ch
// bitfield definitions
PPSLOCK_PPSLOCKED_POSN                   equ 0000h
PPSLOCK_PPSLOCKED_POSITION               equ 0000h
PPSLOCK_PPSLOCKED_SIZE                   equ 0001h
PPSLOCK_PPSLOCKED_LENGTH                 equ 0001h
PPSLOCK_PPSLOCKED_MASK                   equ 0001h

// Register: INTPPS
#define INTPPS INTPPS
INTPPS                                   equ 01E0Dh
// bitfield definitions
INTPPS_INTPPS_POSN                       equ 0000h
INTPPS_INTPPS_POSITION                   equ 0000h
INTPPS_INTPPS_SIZE                       equ 0005h
INTPPS_INTPPS_LENGTH                     equ 0005h
INTPPS_INTPPS_MASK                       equ 001Fh
INTPPS_INTPPS0_POSN                      equ 0000h
INTPPS_INTPPS0_POSITION                  equ 0000h
INTPPS_INTPPS0_SIZE                      equ 0001h
INTPPS_INTPPS0_LENGTH                    equ 0001h
INTPPS_INTPPS0_MASK                      equ 0001h
INTPPS_INTPPS1_POSN                      equ 0001h
INTPPS_INTPPS1_POSITION                  equ 0001h
INTPPS_INTPPS1_SIZE                      equ 0001h
INTPPS_INTPPS1_LENGTH                    equ 0001h
INTPPS_INTPPS1_MASK                      equ 0002h
INTPPS_INTPPS2_POSN                      equ 0002h
INTPPS_INTPPS2_POSITION                  equ 0002h
INTPPS_INTPPS2_SIZE                      equ 0001h
INTPPS_INTPPS2_LENGTH                    equ 0001h
INTPPS_INTPPS2_MASK                      equ 0004h
INTPPS_INTPPS3_POSN                      equ 0003h
INTPPS_INTPPS3_POSITION                  equ 0003h
INTPPS_INTPPS3_SIZE                      equ 0001h
INTPPS_INTPPS3_LENGTH                    equ 0001h
INTPPS_INTPPS3_MASK                      equ 0008h
INTPPS_INTPPS4_POSN                      equ 0004h
INTPPS_INTPPS4_POSITION                  equ 0004h
INTPPS_INTPPS4_SIZE                      equ 0001h
INTPPS_INTPPS4_LENGTH                    equ 0001h
INTPPS_INTPPS4_MASK                      equ 0010h

// Register: T0CKIPPS
#define T0CKIPPS T0CKIPPS
T0CKIPPS                                 equ 01E0Eh
// bitfield definitions
T0CKIPPS_T0CKIPPS_POSN                   equ 0000h
T0CKIPPS_T0CKIPPS_POSITION               equ 0000h
T0CKIPPS_T0CKIPPS_SIZE                   equ 0005h
T0CKIPPS_T0CKIPPS_LENGTH                 equ 0005h
T0CKIPPS_T0CKIPPS_MASK                   equ 001Fh
T0CKIPPS_T0CKIPPS0_POSN                  equ 0000h
T0CKIPPS_T0CKIPPS0_POSITION              equ 0000h
T0CKIPPS_T0CKIPPS0_SIZE                  equ 0001h
T0CKIPPS_T0CKIPPS0_LENGTH                equ 0001h
T0CKIPPS_T0CKIPPS0_MASK                  equ 0001h
T0CKIPPS_T0CKIPPS1_POSN                  equ 0001h
T0CKIPPS_T0CKIPPS1_POSITION              equ 0001h
T0CKIPPS_T0CKIPPS1_SIZE                  equ 0001h
T0CKIPPS_T0CKIPPS1_LENGTH                equ 0001h
T0CKIPPS_T0CKIPPS1_MASK                  equ 0002h
T0CKIPPS_T0CKIPPS2_POSN                  equ 0002h
T0CKIPPS_T0CKIPPS2_POSITION              equ 0002h
T0CKIPPS_T0CKIPPS2_SIZE                  equ 0001h
T0CKIPPS_T0CKIPPS2_LENGTH                equ 0001h
T0CKIPPS_T0CKIPPS2_MASK                  equ 0004h
T0CKIPPS_T0CKIPPS3_POSN                  equ 0003h
T0CKIPPS_T0CKIPPS3_POSITION              equ 0003h
T0CKIPPS_T0CKIPPS3_SIZE                  equ 0001h
T0CKIPPS_T0CKIPPS3_LENGTH                equ 0001h
T0CKIPPS_T0CKIPPS3_MASK                  equ 0008h
T0CKIPPS_T0CKIPPS4_POSN                  equ 0004h
T0CKIPPS_T0CKIPPS4_POSITION              equ 0004h
T0CKIPPS_T0CKIPPS4_SIZE                  equ 0001h
T0CKIPPS_T0CKIPPS4_LENGTH                equ 0001h
T0CKIPPS_T0CKIPPS4_MASK                  equ 0010h

// Register: T1CKIPPS
#define T1CKIPPS T1CKIPPS
T1CKIPPS                                 equ 01E0Fh
// bitfield definitions
T1CKIPPS_T1CKIPPS_POSN                   equ 0000h
T1CKIPPS_T1CKIPPS_POSITION               equ 0000h
T1CKIPPS_T1CKIPPS_SIZE                   equ 0005h
T1CKIPPS_T1CKIPPS_LENGTH                 equ 0005h
T1CKIPPS_T1CKIPPS_MASK                   equ 001Fh
T1CKIPPS_T1CKIPPS0_POSN                  equ 0000h
T1CKIPPS_T1CKIPPS0_POSITION              equ 0000h
T1CKIPPS_T1CKIPPS0_SIZE                  equ 0001h
T1CKIPPS_T1CKIPPS0_LENGTH                equ 0001h
T1CKIPPS_T1CKIPPS0_MASK                  equ 0001h
T1CKIPPS_T1CKIPPS1_POSN                  equ 0001h
T1CKIPPS_T1CKIPPS1_POSITION              equ 0001h
T1CKIPPS_T1CKIPPS1_SIZE                  equ 0001h
T1CKIPPS_T1CKIPPS1_LENGTH                equ 0001h
T1CKIPPS_T1CKIPPS1_MASK                  equ 0002h
T1CKIPPS_T1CKIPPS2_POSN                  equ 0002h
T1CKIPPS_T1CKIPPS2_POSITION              equ 0002h
T1CKIPPS_T1CKIPPS2_SIZE                  equ 0001h
T1CKIPPS_T1CKIPPS2_LENGTH                equ 0001h
T1CKIPPS_T1CKIPPS2_MASK                  equ 0004h
T1CKIPPS_T1CKIPPS3_POSN                  equ 0003h
T1CKIPPS_T1CKIPPS3_POSITION              equ 0003h
T1CKIPPS_T1CKIPPS3_SIZE                  equ 0001h
T1CKIPPS_T1CKIPPS3_LENGTH                equ 0001h
T1CKIPPS_T1CKIPPS3_MASK                  equ 0008h
T1CKIPPS_T1CKIPPS4_POSN                  equ 0004h
T1CKIPPS_T1CKIPPS4_POSITION              equ 0004h
T1CKIPPS_T1CKIPPS4_SIZE                  equ 0001h
T1CKIPPS_T1CKIPPS4_LENGTH                equ 0001h
T1CKIPPS_T1CKIPPS4_MASK                  equ 0010h

// Register: T1GPPS
#define T1GPPS T1GPPS
T1GPPS                                   equ 01E10h
// bitfield definitions
T1GPPS_T1GPPS_POSN                       equ 0000h
T1GPPS_T1GPPS_POSITION                   equ 0000h
T1GPPS_T1GPPS_SIZE                       equ 0005h
T1GPPS_T1GPPS_LENGTH                     equ 0005h
T1GPPS_T1GPPS_MASK                       equ 001Fh
T1GPPS_T1GPPS0_POSN                      equ 0000h
T1GPPS_T1GPPS0_POSITION                  equ 0000h
T1GPPS_T1GPPS0_SIZE                      equ 0001h
T1GPPS_T1GPPS0_LENGTH                    equ 0001h
T1GPPS_T1GPPS0_MASK                      equ 0001h
T1GPPS_T1GPPS1_POSN                      equ 0001h
T1GPPS_T1GPPS1_POSITION                  equ 0001h
T1GPPS_T1GPPS1_SIZE                      equ 0001h
T1GPPS_T1GPPS1_LENGTH                    equ 0001h
T1GPPS_T1GPPS1_MASK                      equ 0002h
T1GPPS_T1GPPS2_POSN                      equ 0002h
T1GPPS_T1GPPS2_POSITION                  equ 0002h
T1GPPS_T1GPPS2_SIZE                      equ 0001h
T1GPPS_T1GPPS2_LENGTH                    equ 0001h
T1GPPS_T1GPPS2_MASK                      equ 0004h
T1GPPS_T1GPPS3_POSN                      equ 0003h
T1GPPS_T1GPPS3_POSITION                  equ 0003h
T1GPPS_T1GPPS3_SIZE                      equ 0001h
T1GPPS_T1GPPS3_LENGTH                    equ 0001h
T1GPPS_T1GPPS3_MASK                      equ 0008h
T1GPPS_T1GPPS4_POSN                      equ 0004h
T1GPPS_T1GPPS4_POSITION                  equ 0004h
T1GPPS_T1GPPS4_SIZE                      equ 0001h
T1GPPS_T1GPPS4_LENGTH                    equ 0001h
T1GPPS_T1GPPS4_MASK                      equ 0010h

// Register: T2INPPS
#define T2INPPS T2INPPS
T2INPPS                                  equ 01E19h
// bitfield definitions
T2INPPS_T2INPPS_POSN                     equ 0000h
T2INPPS_T2INPPS_POSITION                 equ 0000h
T2INPPS_T2INPPS_SIZE                     equ 0005h
T2INPPS_T2INPPS_LENGTH                   equ 0005h
T2INPPS_T2INPPS_MASK                     equ 001Fh
T2INPPS_T2INPPS0_POSN                    equ 0000h
T2INPPS_T2INPPS0_POSITION                equ 0000h
T2INPPS_T2INPPS0_SIZE                    equ 0001h
T2INPPS_T2INPPS0_LENGTH                  equ 0001h
T2INPPS_T2INPPS0_MASK                    equ 0001h
T2INPPS_T2INPPS1_POSN                    equ 0001h
T2INPPS_T2INPPS1_POSITION                equ 0001h
T2INPPS_T2INPPS1_SIZE                    equ 0001h
T2INPPS_T2INPPS1_LENGTH                  equ 0001h
T2INPPS_T2INPPS1_MASK                    equ 0002h
T2INPPS_T2INPPS2_POSN                    equ 0002h
T2INPPS_T2INPPS2_POSITION                equ 0002h
T2INPPS_T2INPPS2_SIZE                    equ 0001h
T2INPPS_T2INPPS2_LENGTH                  equ 0001h
T2INPPS_T2INPPS2_MASK                    equ 0004h
T2INPPS_T2INPPS3_POSN                    equ 0003h
T2INPPS_T2INPPS3_POSITION                equ 0003h
T2INPPS_T2INPPS3_SIZE                    equ 0001h
T2INPPS_T2INPPS3_LENGTH                  equ 0001h
T2INPPS_T2INPPS3_MASK                    equ 0008h
T2INPPS_T2INPPS4_POSN                    equ 0004h
T2INPPS_T2INPPS4_POSITION                equ 0004h
T2INPPS_T2INPPS4_SIZE                    equ 0001h
T2INPPS_T2INPPS4_LENGTH                  equ 0001h
T2INPPS_T2INPPS4_MASK                    equ 0010h

// Register: CCP1PPS
#define CCP1PPS CCP1PPS
CCP1PPS                                  equ 01E1Eh
// bitfield definitions
CCP1PPS_CCP1PPS_POSN                     equ 0000h
CCP1PPS_CCP1PPS_POSITION                 equ 0000h
CCP1PPS_CCP1PPS_SIZE                     equ 0005h
CCP1PPS_CCP1PPS_LENGTH                   equ 0005h
CCP1PPS_CCP1PPS_MASK                     equ 001Fh
CCP1PPS_CCP1PPS0_POSN                    equ 0000h
CCP1PPS_CCP1PPS0_POSITION                equ 0000h
CCP1PPS_CCP1PPS0_SIZE                    equ 0001h
CCP1PPS_CCP1PPS0_LENGTH                  equ 0001h
CCP1PPS_CCP1PPS0_MASK                    equ 0001h
CCP1PPS_CCP1PPS1_POSN                    equ 0001h
CCP1PPS_CCP1PPS1_POSITION                equ 0001h
CCP1PPS_CCP1PPS1_SIZE                    equ 0001h
CCP1PPS_CCP1PPS1_LENGTH                  equ 0001h
CCP1PPS_CCP1PPS1_MASK                    equ 0002h
CCP1PPS_CCP1PPS2_POSN                    equ 0002h
CCP1PPS_CCP1PPS2_POSITION                equ 0002h
CCP1PPS_CCP1PPS2_SIZE                    equ 0001h
CCP1PPS_CCP1PPS2_LENGTH                  equ 0001h
CCP1PPS_CCP1PPS2_MASK                    equ 0004h
CCP1PPS_CCP1PPS3_POSN                    equ 0003h
CCP1PPS_CCP1PPS3_POSITION                equ 0003h
CCP1PPS_CCP1PPS3_SIZE                    equ 0001h
CCP1PPS_CCP1PPS3_LENGTH                  equ 0001h
CCP1PPS_CCP1PPS3_MASK                    equ 0008h
CCP1PPS_CCP1PPS4_POSN                    equ 0004h
CCP1PPS_CCP1PPS4_POSITION                equ 0004h
CCP1PPS_CCP1PPS4_SIZE                    equ 0001h
CCP1PPS_CCP1PPS4_LENGTH                  equ 0001h
CCP1PPS_CCP1PPS4_MASK                    equ 0010h

// Register: CCP2PPS
#define CCP2PPS CCP2PPS
CCP2PPS                                  equ 01E1Fh
// bitfield definitions
CCP2PPS_CCP2PPS_POSN                     equ 0000h
CCP2PPS_CCP2PPS_POSITION                 equ 0000h
CCP2PPS_CCP2PPS_SIZE                     equ 0005h
CCP2PPS_CCP2PPS_LENGTH                   equ 0005h
CCP2PPS_CCP2PPS_MASK                     equ 001Fh
CCP2PPS_CCP2PPS0_POSN                    equ 0000h
CCP2PPS_CCP2PPS0_POSITION                equ 0000h
CCP2PPS_CCP2PPS0_SIZE                    equ 0001h
CCP2PPS_CCP2PPS0_LENGTH                  equ 0001h
CCP2PPS_CCP2PPS0_MASK                    equ 0001h
CCP2PPS_CCP2PPS1_POSN                    equ 0001h
CCP2PPS_CCP2PPS1_POSITION                equ 0001h
CCP2PPS_CCP2PPS1_SIZE                    equ 0001h
CCP2PPS_CCP2PPS1_LENGTH                  equ 0001h
CCP2PPS_CCP2PPS1_MASK                    equ 0002h
CCP2PPS_CCP2PPS2_POSN                    equ 0002h
CCP2PPS_CCP2PPS2_POSITION                equ 0002h
CCP2PPS_CCP2PPS2_SIZE                    equ 0001h
CCP2PPS_CCP2PPS2_LENGTH                  equ 0001h
CCP2PPS_CCP2PPS2_MASK                    equ 0004h
CCP2PPS_CCP2PPS3_POSN                    equ 0003h
CCP2PPS_CCP2PPS3_POSITION                equ 0003h
CCP2PPS_CCP2PPS3_SIZE                    equ 0001h
CCP2PPS_CCP2PPS3_LENGTH                  equ 0001h
CCP2PPS_CCP2PPS3_MASK                    equ 0008h
CCP2PPS_CCP2PPS4_POSN                    equ 0004h
CCP2PPS_CCP2PPS4_POSITION                equ 0004h
CCP2PPS_CCP2PPS4_SIZE                    equ 0001h
CCP2PPS_CCP2PPS4_LENGTH                  equ 0001h
CCP2PPS_CCP2PPS4_MASK                    equ 0010h

// Register: CLCIN0PPS
#define CLCIN0PPS CLCIN0PPS
CLCIN0PPS                                equ 01E3Dh
// bitfield definitions
CLCIN0PPS_CLCIN0PPS_POSN                 equ 0000h
CLCIN0PPS_CLCIN0PPS_POSITION             equ 0000h
CLCIN0PPS_CLCIN0PPS_SIZE                 equ 0005h
CLCIN0PPS_CLCIN0PPS_LENGTH               equ 0005h
CLCIN0PPS_CLCIN0PPS_MASK                 equ 001Fh
CLCIN0PPS_CLCIN0PPS0_POSN                equ 0000h
CLCIN0PPS_CLCIN0PPS0_POSITION            equ 0000h
CLCIN0PPS_CLCIN0PPS0_SIZE                equ 0001h
CLCIN0PPS_CLCIN0PPS0_LENGTH              equ 0001h
CLCIN0PPS_CLCIN0PPS0_MASK                equ 0001h
CLCIN0PPS_CLCIN0PPS1_POSN                equ 0001h
CLCIN0PPS_CLCIN0PPS1_POSITION            equ 0001h
CLCIN0PPS_CLCIN0PPS1_SIZE                equ 0001h
CLCIN0PPS_CLCIN0PPS1_LENGTH              equ 0001h
CLCIN0PPS_CLCIN0PPS1_MASK                equ 0002h
CLCIN0PPS_CLCIN0PPS2_POSN                equ 0002h
CLCIN0PPS_CLCIN0PPS2_POSITION            equ 0002h
CLCIN0PPS_CLCIN0PPS2_SIZE                equ 0001h
CLCIN0PPS_CLCIN0PPS2_LENGTH              equ 0001h
CLCIN0PPS_CLCIN0PPS2_MASK                equ 0004h
CLCIN0PPS_CLCIN0PPS3_POSN                equ 0003h
CLCIN0PPS_CLCIN0PPS3_POSITION            equ 0003h
CLCIN0PPS_CLCIN0PPS3_SIZE                equ 0001h
CLCIN0PPS_CLCIN0PPS3_LENGTH              equ 0001h
CLCIN0PPS_CLCIN0PPS3_MASK                equ 0008h
CLCIN0PPS_CLCIN0PPS4_POSN                equ 0004h
CLCIN0PPS_CLCIN0PPS4_POSITION            equ 0004h
CLCIN0PPS_CLCIN0PPS4_SIZE                equ 0001h
CLCIN0PPS_CLCIN0PPS4_LENGTH              equ 0001h
CLCIN0PPS_CLCIN0PPS4_MASK                equ 0010h

// Register: CLCIN1PPS
#define CLCIN1PPS CLCIN1PPS
CLCIN1PPS                                equ 01E3Eh
// bitfield definitions
CLCIN1PPS_CLCIN1PPS_POSN                 equ 0000h
CLCIN1PPS_CLCIN1PPS_POSITION             equ 0000h
CLCIN1PPS_CLCIN1PPS_SIZE                 equ 0005h
CLCIN1PPS_CLCIN1PPS_LENGTH               equ 0005h
CLCIN1PPS_CLCIN1PPS_MASK                 equ 001Fh
CLCIN1PPS_CLCIN1PPS0_POSN                equ 0000h
CLCIN1PPS_CLCIN1PPS0_POSITION            equ 0000h
CLCIN1PPS_CLCIN1PPS0_SIZE                equ 0001h
CLCIN1PPS_CLCIN1PPS0_LENGTH              equ 0001h
CLCIN1PPS_CLCIN1PPS0_MASK                equ 0001h
CLCIN1PPS_CLCIN1PPS1_POSN                equ 0001h
CLCIN1PPS_CLCIN1PPS1_POSITION            equ 0001h
CLCIN1PPS_CLCIN1PPS1_SIZE                equ 0001h
CLCIN1PPS_CLCIN1PPS1_LENGTH              equ 0001h
CLCIN1PPS_CLCIN1PPS1_MASK                equ 0002h
CLCIN1PPS_CLCIN1PPS2_POSN                equ 0002h
CLCIN1PPS_CLCIN1PPS2_POSITION            equ 0002h
CLCIN1PPS_CLCIN1PPS2_SIZE                equ 0001h
CLCIN1PPS_CLCIN1PPS2_LENGTH              equ 0001h
CLCIN1PPS_CLCIN1PPS2_MASK                equ 0004h
CLCIN1PPS_CLCIN1PPS3_POSN                equ 0003h
CLCIN1PPS_CLCIN1PPS3_POSITION            equ 0003h
CLCIN1PPS_CLCIN1PPS3_SIZE                equ 0001h
CLCIN1PPS_CLCIN1PPS3_LENGTH              equ 0001h
CLCIN1PPS_CLCIN1PPS3_MASK                equ 0008h
CLCIN1PPS_CLCIN1PPS4_POSN                equ 0004h
CLCIN1PPS_CLCIN1PPS4_POSITION            equ 0004h
CLCIN1PPS_CLCIN1PPS4_SIZE                equ 0001h
CLCIN1PPS_CLCIN1PPS4_LENGTH              equ 0001h
CLCIN1PPS_CLCIN1PPS4_MASK                equ 0010h

// Register: CLCIN2PPS
#define CLCIN2PPS CLCIN2PPS
CLCIN2PPS                                equ 01E3Fh
// bitfield definitions
CLCIN2PPS_CLCIN2PPS_POSN                 equ 0000h
CLCIN2PPS_CLCIN2PPS_POSITION             equ 0000h
CLCIN2PPS_CLCIN2PPS_SIZE                 equ 0005h
CLCIN2PPS_CLCIN2PPS_LENGTH               equ 0005h
CLCIN2PPS_CLCIN2PPS_MASK                 equ 001Fh
CLCIN2PPS_CLCIN2PPS0_POSN                equ 0000h
CLCIN2PPS_CLCIN2PPS0_POSITION            equ 0000h
CLCIN2PPS_CLCIN2PPS0_SIZE                equ 0001h
CLCIN2PPS_CLCIN2PPS0_LENGTH              equ 0001h
CLCIN2PPS_CLCIN2PPS0_MASK                equ 0001h
CLCIN2PPS_CLCIN2PPS1_POSN                equ 0001h
CLCIN2PPS_CLCIN2PPS1_POSITION            equ 0001h
CLCIN2PPS_CLCIN2PPS1_SIZE                equ 0001h
CLCIN2PPS_CLCIN2PPS1_LENGTH              equ 0001h
CLCIN2PPS_CLCIN2PPS1_MASK                equ 0002h
CLCIN2PPS_CLCIN2PPS2_POSN                equ 0002h
CLCIN2PPS_CLCIN2PPS2_POSITION            equ 0002h
CLCIN2PPS_CLCIN2PPS2_SIZE                equ 0001h
CLCIN2PPS_CLCIN2PPS2_LENGTH              equ 0001h
CLCIN2PPS_CLCIN2PPS2_MASK                equ 0004h
CLCIN2PPS_CLCIN2PPS3_POSN                equ 0003h
CLCIN2PPS_CLCIN2PPS3_POSITION            equ 0003h
CLCIN2PPS_CLCIN2PPS3_SIZE                equ 0001h
CLCIN2PPS_CLCIN2PPS3_LENGTH              equ 0001h
CLCIN2PPS_CLCIN2PPS3_MASK                equ 0008h
CLCIN2PPS_CLCIN2PPS4_POSN                equ 0004h
CLCIN2PPS_CLCIN2PPS4_POSITION            equ 0004h
CLCIN2PPS_CLCIN2PPS4_SIZE                equ 0001h
CLCIN2PPS_CLCIN2PPS4_LENGTH              equ 0001h
CLCIN2PPS_CLCIN2PPS4_MASK                equ 0010h

// Register: CLCIN3PPS
#define CLCIN3PPS CLCIN3PPS
CLCIN3PPS                                equ 01E40h
// bitfield definitions
CLCIN3PPS_CLCIN3PPS_POSN                 equ 0000h
CLCIN3PPS_CLCIN3PPS_POSITION             equ 0000h
CLCIN3PPS_CLCIN3PPS_SIZE                 equ 0005h
CLCIN3PPS_CLCIN3PPS_LENGTH               equ 0005h
CLCIN3PPS_CLCIN3PPS_MASK                 equ 001Fh
CLCIN3PPS_CLCIN3PPS0_POSN                equ 0000h
CLCIN3PPS_CLCIN3PPS0_POSITION            equ 0000h
CLCIN3PPS_CLCIN3PPS0_SIZE                equ 0001h
CLCIN3PPS_CLCIN3PPS0_LENGTH              equ 0001h
CLCIN3PPS_CLCIN3PPS0_MASK                equ 0001h
CLCIN3PPS_CLCIN3PPS1_POSN                equ 0001h
CLCIN3PPS_CLCIN3PPS1_POSITION            equ 0001h
CLCIN3PPS_CLCIN3PPS1_SIZE                equ 0001h
CLCIN3PPS_CLCIN3PPS1_LENGTH              equ 0001h
CLCIN3PPS_CLCIN3PPS1_MASK                equ 0002h
CLCIN3PPS_CLCIN3PPS2_POSN                equ 0002h
CLCIN3PPS_CLCIN3PPS2_POSITION            equ 0002h
CLCIN3PPS_CLCIN3PPS2_SIZE                equ 0001h
CLCIN3PPS_CLCIN3PPS2_LENGTH              equ 0001h
CLCIN3PPS_CLCIN3PPS2_MASK                equ 0004h
CLCIN3PPS_CLCIN3PPS3_POSN                equ 0003h
CLCIN3PPS_CLCIN3PPS3_POSITION            equ 0003h
CLCIN3PPS_CLCIN3PPS3_SIZE                equ 0001h
CLCIN3PPS_CLCIN3PPS3_LENGTH              equ 0001h
CLCIN3PPS_CLCIN3PPS3_MASK                equ 0008h
CLCIN3PPS_CLCIN3PPS4_POSN                equ 0004h
CLCIN3PPS_CLCIN3PPS4_POSITION            equ 0004h
CLCIN3PPS_CLCIN3PPS4_SIZE                equ 0001h
CLCIN3PPS_CLCIN3PPS4_LENGTH              equ 0001h
CLCIN3PPS_CLCIN3PPS4_MASK                equ 0010h

// Register: CK1PPS
#define CK1PPS CK1PPS
CK1PPS                                   equ 01E41h
// bitfield definitions
CK1PPS_CK1PPS_POSN                       equ 0000h
CK1PPS_CK1PPS_POSITION                   equ 0000h
CK1PPS_CK1PPS_SIZE                       equ 0005h
CK1PPS_CK1PPS_LENGTH                     equ 0005h
CK1PPS_CK1PPS_MASK                       equ 001Fh

// Register: RX1PPS
#define RX1PPS RX1PPS
RX1PPS                                   equ 01E42h
// bitfield definitions
RX1PPS_RX1PPS_POSN                       equ 0000h
RX1PPS_RX1PPS_POSITION                   equ 0000h
RX1PPS_RX1PPS_SIZE                       equ 0005h
RX1PPS_RX1PPS_LENGTH                     equ 0005h
RX1PPS_RX1PPS_MASK                       equ 001Fh

// Register: SSP1CLKPPS
#define SSP1CLKPPS SSP1CLKPPS
SSP1CLKPPS                               equ 01E47h
// bitfield definitions
SSP1CLKPPS_SSP1CLKPPS_POSN               equ 0000h
SSP1CLKPPS_SSP1CLKPPS_POSITION           equ 0000h
SSP1CLKPPS_SSP1CLKPPS_SIZE               equ 0005h
SSP1CLKPPS_SSP1CLKPPS_LENGTH             equ 0005h
SSP1CLKPPS_SSP1CLKPPS_MASK               equ 001Fh
SSP1CLKPPS_SSP1CLKPPS0_POSN              equ 0000h
SSP1CLKPPS_SSP1CLKPPS0_POSITION          equ 0000h
SSP1CLKPPS_SSP1CLKPPS0_SIZE              equ 0001h
SSP1CLKPPS_SSP1CLKPPS0_LENGTH            equ 0001h
SSP1CLKPPS_SSP1CLKPPS0_MASK              equ 0001h
SSP1CLKPPS_SSP1CLKPPS1_POSN              equ 0001h
SSP1CLKPPS_SSP1CLKPPS1_POSITION          equ 0001h
SSP1CLKPPS_SSP1CLKPPS1_SIZE              equ 0001h
SSP1CLKPPS_SSP1CLKPPS1_LENGTH            equ 0001h
SSP1CLKPPS_SSP1CLKPPS1_MASK              equ 0002h
SSP1CLKPPS_SSP1CLKPPS2_POSN              equ 0002h
SSP1CLKPPS_SSP1CLKPPS2_POSITION          equ 0002h
SSP1CLKPPS_SSP1CLKPPS2_SIZE              equ 0001h
SSP1CLKPPS_SSP1CLKPPS2_LENGTH            equ 0001h
SSP1CLKPPS_SSP1CLKPPS2_MASK              equ 0004h
SSP1CLKPPS_SSP1CLKPPS3_POSN              equ 0003h
SSP1CLKPPS_SSP1CLKPPS3_POSITION          equ 0003h
SSP1CLKPPS_SSP1CLKPPS3_SIZE              equ 0001h
SSP1CLKPPS_SSP1CLKPPS3_LENGTH            equ 0001h
SSP1CLKPPS_SSP1CLKPPS3_MASK              equ 0008h
SSP1CLKPPS_SSP1CLKPPS4_POSN              equ 0004h
SSP1CLKPPS_SSP1CLKPPS4_POSITION          equ 0004h
SSP1CLKPPS_SSP1CLKPPS4_SIZE              equ 0001h
SSP1CLKPPS_SSP1CLKPPS4_LENGTH            equ 0001h
SSP1CLKPPS_SSP1CLKPPS4_MASK              equ 0010h

// Register: SSP1DATPPS
#define SSP1DATPPS SSP1DATPPS
SSP1DATPPS                               equ 01E48h
// bitfield definitions
SSP1DATPPS_SSP1DATPPS_POSN               equ 0000h
SSP1DATPPS_SSP1DATPPS_POSITION           equ 0000h
SSP1DATPPS_SSP1DATPPS_SIZE               equ 0005h
SSP1DATPPS_SSP1DATPPS_LENGTH             equ 0005h
SSP1DATPPS_SSP1DATPPS_MASK               equ 001Fh
SSP1DATPPS_SSP1DATPPS0_POSN              equ 0000h
SSP1DATPPS_SSP1DATPPS0_POSITION          equ 0000h
SSP1DATPPS_SSP1DATPPS0_SIZE              equ 0001h
SSP1DATPPS_SSP1DATPPS0_LENGTH            equ 0001h
SSP1DATPPS_SSP1DATPPS0_MASK              equ 0001h
SSP1DATPPS_SSP1DATPPS1_POSN              equ 0001h
SSP1DATPPS_SSP1DATPPS1_POSITION          equ 0001h
SSP1DATPPS_SSP1DATPPS1_SIZE              equ 0001h
SSP1DATPPS_SSP1DATPPS1_LENGTH            equ 0001h
SSP1DATPPS_SSP1DATPPS1_MASK              equ 0002h
SSP1DATPPS_SSP1DATPPS2_POSN              equ 0002h
SSP1DATPPS_SSP1DATPPS2_POSITION          equ 0002h
SSP1DATPPS_SSP1DATPPS2_SIZE              equ 0001h
SSP1DATPPS_SSP1DATPPS2_LENGTH            equ 0001h
SSP1DATPPS_SSP1DATPPS2_MASK              equ 0004h
SSP1DATPPS_SSP1DATPPS3_POSN              equ 0003h
SSP1DATPPS_SSP1DATPPS3_POSITION          equ 0003h
SSP1DATPPS_SSP1DATPPS3_SIZE              equ 0001h
SSP1DATPPS_SSP1DATPPS3_LENGTH            equ 0001h
SSP1DATPPS_SSP1DATPPS3_MASK              equ 0008h
SSP1DATPPS_SSP1DATPPS4_POSN              equ 0004h
SSP1DATPPS_SSP1DATPPS4_POSITION          equ 0004h
SSP1DATPPS_SSP1DATPPS4_SIZE              equ 0001h
SSP1DATPPS_SSP1DATPPS4_LENGTH            equ 0001h
SSP1DATPPS_SSP1DATPPS4_MASK              equ 0010h

// Register: SSP1SSPPS
#define SSP1SSPPS SSP1SSPPS
SSP1SSPPS                                equ 01E49h
// bitfield definitions
SSP1SSPPS_SSP1SSPPS_POSN                 equ 0000h
SSP1SSPPS_SSP1SSPPS_POSITION             equ 0000h
SSP1SSPPS_SSP1SSPPS_SIZE                 equ 0005h
SSP1SSPPS_SSP1SSPPS_LENGTH               equ 0005h
SSP1SSPPS_SSP1SSPPS_MASK                 equ 001Fh
SSP1SSPPS_SSP1SSPPS0_POSN                equ 0000h
SSP1SSPPS_SSP1SSPPS0_POSITION            equ 0000h
SSP1SSPPS_SSP1SSPPS0_SIZE                equ 0001h
SSP1SSPPS_SSP1SSPPS0_LENGTH              equ 0001h
SSP1SSPPS_SSP1SSPPS0_MASK                equ 0001h
SSP1SSPPS_SSP1SSPPS1_POSN                equ 0001h
SSP1SSPPS_SSP1SSPPS1_POSITION            equ 0001h
SSP1SSPPS_SSP1SSPPS1_SIZE                equ 0001h
SSP1SSPPS_SSP1SSPPS1_LENGTH              equ 0001h
SSP1SSPPS_SSP1SSPPS1_MASK                equ 0002h
SSP1SSPPS_SSP1SSPPS2_POSN                equ 0002h
SSP1SSPPS_SSP1SSPPS2_POSITION            equ 0002h
SSP1SSPPS_SSP1SSPPS2_SIZE                equ 0001h
SSP1SSPPS_SSP1SSPPS2_LENGTH              equ 0001h
SSP1SSPPS_SSP1SSPPS2_MASK                equ 0004h
SSP1SSPPS_SSP1SSPPS3_POSN                equ 0003h
SSP1SSPPS_SSP1SSPPS3_POSITION            equ 0003h
SSP1SSPPS_SSP1SSPPS3_SIZE                equ 0001h
SSP1SSPPS_SSP1SSPPS3_LENGTH              equ 0001h
SSP1SSPPS_SSP1SSPPS3_MASK                equ 0008h
SSP1SSPPS_SSP1SSPPS4_POSN                equ 0004h
SSP1SSPPS_SSP1SSPPS4_POSITION            equ 0004h
SSP1SSPPS_SSP1SSPPS4_SIZE                equ 0001h
SSP1SSPPS_SSP1SSPPS4_LENGTH              equ 0001h
SSP1SSPPS_SSP1SSPPS4_MASK                equ 0010h

// Register: ADACTPPS
#define ADACTPPS ADACTPPS
ADACTPPS                                 equ 01E50h
// bitfield definitions
ADACTPPS_ADACTPPS_POSN                   equ 0000h
ADACTPPS_ADACTPPS_POSITION               equ 0000h
ADACTPPS_ADACTPPS_SIZE                   equ 0005h
ADACTPPS_ADACTPPS_LENGTH                 equ 0005h
ADACTPPS_ADACTPPS_MASK                   equ 001Fh

// Register: CLBIN0PPS
#define CLBIN0PPS CLBIN0PPS
CLBIN0PPS                                equ 01E57h
// bitfield definitions
CLBIN0PPS_CLBIN0PPS_POSN                 equ 0000h
CLBIN0PPS_CLBIN0PPS_POSITION             equ 0000h
CLBIN0PPS_CLBIN0PPS_SIZE                 equ 0005h
CLBIN0PPS_CLBIN0PPS_LENGTH               equ 0005h
CLBIN0PPS_CLBIN0PPS_MASK                 equ 001Fh

// Register: CLBIN1PPS
#define CLBIN1PPS CLBIN1PPS
CLBIN1PPS                                equ 01E58h
// bitfield definitions
CLBIN1PPS_CLBIN1PPS_POSN                 equ 0000h
CLBIN1PPS_CLBIN1PPS_POSITION             equ 0000h
CLBIN1PPS_CLBIN1PPS_SIZE                 equ 0005h
CLBIN1PPS_CLBIN1PPS_LENGTH               equ 0005h
CLBIN1PPS_CLBIN1PPS_MASK                 equ 001Fh

// Register: CLBIN2PPS
#define CLBIN2PPS CLBIN2PPS
CLBIN2PPS                                equ 01E59h
// bitfield definitions
CLBIN2PPS_CLBIN2PPS_POSN                 equ 0000h
CLBIN2PPS_CLBIN2PPS_POSITION             equ 0000h
CLBIN2PPS_CLBIN2PPS_SIZE                 equ 0005h
CLBIN2PPS_CLBIN2PPS_LENGTH               equ 0005h
CLBIN2PPS_CLBIN2PPS_MASK                 equ 001Fh

// Register: CLBIN3PPS
#define CLBIN3PPS CLBIN3PPS
CLBIN3PPS                                equ 01E5Ah
// bitfield definitions
CLBIN3PPS_CLBIN3PPS_POSN                 equ 0000h
CLBIN3PPS_CLBIN3PPS_POSITION             equ 0000h
CLBIN3PPS_CLBIN3PPS_SIZE                 equ 0005h
CLBIN3PPS_CLBIN3PPS_LENGTH               equ 0005h
CLBIN3PPS_CLBIN3PPS_MASK                 equ 001Fh

// Register: ANSELA
#define ANSELA ANSELA
ANSELA                                   equ 01E8Ch
// bitfield definitions
ANSELA_ANSELA0_POSN                      equ 0000h
ANSELA_ANSELA0_POSITION                  equ 0000h
ANSELA_ANSELA0_SIZE                      equ 0001h
ANSELA_ANSELA0_LENGTH                    equ 0001h
ANSELA_ANSELA0_MASK                      equ 0001h
ANSELA_ANSELA1_POSN                      equ 0001h
ANSELA_ANSELA1_POSITION                  equ 0001h
ANSELA_ANSELA1_SIZE                      equ 0001h
ANSELA_ANSELA1_LENGTH                    equ 0001h
ANSELA_ANSELA1_MASK                      equ 0002h
ANSELA_ANSELA2_POSN                      equ 0002h
ANSELA_ANSELA2_POSITION                  equ 0002h
ANSELA_ANSELA2_SIZE                      equ 0001h
ANSELA_ANSELA2_LENGTH                    equ 0001h
ANSELA_ANSELA2_MASK                      equ 0004h
ANSELA_ANSELA4_POSN                      equ 0004h
ANSELA_ANSELA4_POSITION                  equ 0004h
ANSELA_ANSELA4_SIZE                      equ 0001h
ANSELA_ANSELA4_LENGTH                    equ 0001h
ANSELA_ANSELA4_MASK                      equ 0010h
ANSELA_ANSELA5_POSN                      equ 0005h
ANSELA_ANSELA5_POSITION                  equ 0005h
ANSELA_ANSELA5_SIZE                      equ 0001h
ANSELA_ANSELA5_LENGTH                    equ 0001h
ANSELA_ANSELA5_MASK                      equ 0020h
ANSELA_ANSA0_POSN                        equ 0000h
ANSELA_ANSA0_POSITION                    equ 0000h
ANSELA_ANSA0_SIZE                        equ 0001h
ANSELA_ANSA0_LENGTH                      equ 0001h
ANSELA_ANSA0_MASK                        equ 0001h
ANSELA_ANSA1_POSN                        equ 0001h
ANSELA_ANSA1_POSITION                    equ 0001h
ANSELA_ANSA1_SIZE                        equ 0001h
ANSELA_ANSA1_LENGTH                      equ 0001h
ANSELA_ANSA1_MASK                        equ 0002h
ANSELA_ANSA2_POSN                        equ 0002h
ANSELA_ANSA2_POSITION                    equ 0002h
ANSELA_ANSA2_SIZE                        equ 0001h
ANSELA_ANSA2_LENGTH                      equ 0001h
ANSELA_ANSA2_MASK                        equ 0004h
ANSELA_ANSA4_POSN                        equ 0004h
ANSELA_ANSA4_POSITION                    equ 0004h
ANSELA_ANSA4_SIZE                        equ 0001h
ANSELA_ANSA4_LENGTH                      equ 0001h
ANSELA_ANSA4_MASK                        equ 0010h
ANSELA_ANSA5_POSN                        equ 0005h
ANSELA_ANSA5_POSITION                    equ 0005h
ANSELA_ANSA5_SIZE                        equ 0001h
ANSELA_ANSA5_LENGTH                      equ 0001h
ANSELA_ANSA5_MASK                        equ 0020h

// Register: WPUA
#define WPUA WPUA
WPUA                                     equ 01E8Dh
// bitfield definitions
WPUA_WPUA0_POSN                          equ 0000h
WPUA_WPUA0_POSITION                      equ 0000h
WPUA_WPUA0_SIZE                          equ 0001h
WPUA_WPUA0_LENGTH                        equ 0001h
WPUA_WPUA0_MASK                          equ 0001h
WPUA_WPUA1_POSN                          equ 0001h
WPUA_WPUA1_POSITION                      equ 0001h
WPUA_WPUA1_SIZE                          equ 0001h
WPUA_WPUA1_LENGTH                        equ 0001h
WPUA_WPUA1_MASK                          equ 0002h
WPUA_WPUA2_POSN                          equ 0002h
WPUA_WPUA2_POSITION                      equ 0002h
WPUA_WPUA2_SIZE                          equ 0001h
WPUA_WPUA2_LENGTH                        equ 0001h
WPUA_WPUA2_MASK                          equ 0004h
WPUA_WPUA3_POSN                          equ 0003h
WPUA_WPUA3_POSITION                      equ 0003h
WPUA_WPUA3_SIZE                          equ 0001h
WPUA_WPUA3_LENGTH                        equ 0001h
WPUA_WPUA3_MASK                          equ 0008h
WPUA_WPUA4_POSN                          equ 0004h
WPUA_WPUA4_POSITION                      equ 0004h
WPUA_WPUA4_SIZE                          equ 0001h
WPUA_WPUA4_LENGTH                        equ 0001h
WPUA_WPUA4_MASK                          equ 0010h
WPUA_WPUA5_POSN                          equ 0005h
WPUA_WPUA5_POSITION                      equ 0005h
WPUA_WPUA5_SIZE                          equ 0001h
WPUA_WPUA5_LENGTH                        equ 0001h
WPUA_WPUA5_MASK                          equ 0020h

// Register: ODCONA
#define ODCONA ODCONA
ODCONA                                   equ 01E8Eh
// bitfield definitions
ODCONA_ODCA0_POSN                        equ 0000h
ODCONA_ODCA0_POSITION                    equ 0000h
ODCONA_ODCA0_SIZE                        equ 0001h
ODCONA_ODCA0_LENGTH                      equ 0001h
ODCONA_ODCA0_MASK                        equ 0001h
ODCONA_ODCA1_POSN                        equ 0001h
ODCONA_ODCA1_POSITION                    equ 0001h
ODCONA_ODCA1_SIZE                        equ 0001h
ODCONA_ODCA1_LENGTH                      equ 0001h
ODCONA_ODCA1_MASK                        equ 0002h
ODCONA_ODCA2_POSN                        equ 0002h
ODCONA_ODCA2_POSITION                    equ 0002h
ODCONA_ODCA2_SIZE                        equ 0001h
ODCONA_ODCA2_LENGTH                      equ 0001h
ODCONA_ODCA2_MASK                        equ 0004h
ODCONA_ODCA4_POSN                        equ 0004h
ODCONA_ODCA4_POSITION                    equ 0004h
ODCONA_ODCA4_SIZE                        equ 0001h
ODCONA_ODCA4_LENGTH                      equ 0001h
ODCONA_ODCA4_MASK                        equ 0010h
ODCONA_ODCA5_POSN                        equ 0005h
ODCONA_ODCA5_POSITION                    equ 0005h
ODCONA_ODCA5_SIZE                        equ 0001h
ODCONA_ODCA5_LENGTH                      equ 0001h
ODCONA_ODCA5_MASK                        equ 0020h

// Register: SLRCONA
#define SLRCONA SLRCONA
SLRCONA                                  equ 01E8Fh
// bitfield definitions
SLRCONA_SLRA0_POSN                       equ 0000h
SLRCONA_SLRA0_POSITION                   equ 0000h
SLRCONA_SLRA0_SIZE                       equ 0001h
SLRCONA_SLRA0_LENGTH                     equ 0001h
SLRCONA_SLRA0_MASK                       equ 0001h
SLRCONA_SLRA1_POSN                       equ 0001h
SLRCONA_SLRA1_POSITION                   equ 0001h
SLRCONA_SLRA1_SIZE                       equ 0001h
SLRCONA_SLRA1_LENGTH                     equ 0001h
SLRCONA_SLRA1_MASK                       equ 0002h
SLRCONA_SLRA2_POSN                       equ 0002h
SLRCONA_SLRA2_POSITION                   equ 0002h
SLRCONA_SLRA2_SIZE                       equ 0001h
SLRCONA_SLRA2_LENGTH                     equ 0001h
SLRCONA_SLRA2_MASK                       equ 0004h
SLRCONA_SLRA4_POSN                       equ 0004h
SLRCONA_SLRA4_POSITION                   equ 0004h
SLRCONA_SLRA4_SIZE                       equ 0001h
SLRCONA_SLRA4_LENGTH                     equ 0001h
SLRCONA_SLRA4_MASK                       equ 0010h
SLRCONA_SLRA5_POSN                       equ 0005h
SLRCONA_SLRA5_POSITION                   equ 0005h
SLRCONA_SLRA5_SIZE                       equ 0001h
SLRCONA_SLRA5_LENGTH                     equ 0001h
SLRCONA_SLRA5_MASK                       equ 0020h

// Register: INLVLA
#define INLVLA INLVLA
INLVLA                                   equ 01E90h
// bitfield definitions
INLVLA_INLVLA0_POSN                      equ 0000h
INLVLA_INLVLA0_POSITION                  equ 0000h
INLVLA_INLVLA0_SIZE                      equ 0001h
INLVLA_INLVLA0_LENGTH                    equ 0001h
INLVLA_INLVLA0_MASK                      equ 0001h
INLVLA_INLVLA1_POSN                      equ 0001h
INLVLA_INLVLA1_POSITION                  equ 0001h
INLVLA_INLVLA1_SIZE                      equ 0001h
INLVLA_INLVLA1_LENGTH                    equ 0001h
INLVLA_INLVLA1_MASK                      equ 0002h
INLVLA_INLVLA2_POSN                      equ 0002h
INLVLA_INLVLA2_POSITION                  equ 0002h
INLVLA_INLVLA2_SIZE                      equ 0001h
INLVLA_INLVLA2_LENGTH                    equ 0001h
INLVLA_INLVLA2_MASK                      equ 0004h
INLVLA_INLVLA3_POSN                      equ 0003h
INLVLA_INLVLA3_POSITION                  equ 0003h
INLVLA_INLVLA3_SIZE                      equ 0001h
INLVLA_INLVLA3_LENGTH                    equ 0001h
INLVLA_INLVLA3_MASK                      equ 0008h
INLVLA_INLVLA4_POSN                      equ 0004h
INLVLA_INLVLA4_POSITION                  equ 0004h
INLVLA_INLVLA4_SIZE                      equ 0001h
INLVLA_INLVLA4_LENGTH                    equ 0001h
INLVLA_INLVLA4_MASK                      equ 0010h
INLVLA_INLVLA5_POSN                      equ 0005h
INLVLA_INLVLA5_POSITION                  equ 0005h
INLVLA_INLVLA5_SIZE                      equ 0001h
INLVLA_INLVLA5_LENGTH                    equ 0001h
INLVLA_INLVLA5_MASK                      equ 0020h

// Register: IOCAP
#define IOCAP IOCAP
IOCAP                                    equ 01E91h
// bitfield definitions
IOCAP_IOCAP0_POSN                        equ 0000h
IOCAP_IOCAP0_POSITION                    equ 0000h
IOCAP_IOCAP0_SIZE                        equ 0001h
IOCAP_IOCAP0_LENGTH                      equ 0001h
IOCAP_IOCAP0_MASK                        equ 0001h
IOCAP_IOCAP1_POSN                        equ 0001h
IOCAP_IOCAP1_POSITION                    equ 0001h
IOCAP_IOCAP1_SIZE                        equ 0001h
IOCAP_IOCAP1_LENGTH                      equ 0001h
IOCAP_IOCAP1_MASK                        equ 0002h
IOCAP_IOCAP2_POSN                        equ 0002h
IOCAP_IOCAP2_POSITION                    equ 0002h
IOCAP_IOCAP2_SIZE                        equ 0001h
IOCAP_IOCAP2_LENGTH                      equ 0001h
IOCAP_IOCAP2_MASK                        equ 0004h
IOCAP_IOCAP3_POSN                        equ 0003h
IOCAP_IOCAP3_POSITION                    equ 0003h
IOCAP_IOCAP3_SIZE                        equ 0001h
IOCAP_IOCAP3_LENGTH                      equ 0001h
IOCAP_IOCAP3_MASK                        equ 0008h
IOCAP_IOCAP4_POSN                        equ 0004h
IOCAP_IOCAP4_POSITION                    equ 0004h
IOCAP_IOCAP4_SIZE                        equ 0001h
IOCAP_IOCAP4_LENGTH                      equ 0001h
IOCAP_IOCAP4_MASK                        equ 0010h
IOCAP_IOCAP5_POSN                        equ 0005h
IOCAP_IOCAP5_POSITION                    equ 0005h
IOCAP_IOCAP5_SIZE                        equ 0001h
IOCAP_IOCAP5_LENGTH                      equ 0001h
IOCAP_IOCAP5_MASK                        equ 0020h

// Register: IOCAN
#define IOCAN IOCAN
IOCAN                                    equ 01E92h
// bitfield definitions
IOCAN_IOCAN0_POSN                        equ 0000h
IOCAN_IOCAN0_POSITION                    equ 0000h
IOCAN_IOCAN0_SIZE                        equ 0001h
IOCAN_IOCAN0_LENGTH                      equ 0001h
IOCAN_IOCAN0_MASK                        equ 0001h
IOCAN_IOCAN1_POSN                        equ 0001h
IOCAN_IOCAN1_POSITION                    equ 0001h
IOCAN_IOCAN1_SIZE                        equ 0001h
IOCAN_IOCAN1_LENGTH                      equ 0001h
IOCAN_IOCAN1_MASK                        equ 0002h
IOCAN_IOCAN2_POSN                        equ 0002h
IOCAN_IOCAN2_POSITION                    equ 0002h
IOCAN_IOCAN2_SIZE                        equ 0001h
IOCAN_IOCAN2_LENGTH                      equ 0001h
IOCAN_IOCAN2_MASK                        equ 0004h
IOCAN_IOCAN3_POSN                        equ 0003h
IOCAN_IOCAN3_POSITION                    equ 0003h
IOCAN_IOCAN3_SIZE                        equ 0001h
IOCAN_IOCAN3_LENGTH                      equ 0001h
IOCAN_IOCAN3_MASK                        equ 0008h
IOCAN_IOCAN4_POSN                        equ 0004h
IOCAN_IOCAN4_POSITION                    equ 0004h
IOCAN_IOCAN4_SIZE                        equ 0001h
IOCAN_IOCAN4_LENGTH                      equ 0001h
IOCAN_IOCAN4_MASK                        equ 0010h
IOCAN_IOCAN5_POSN                        equ 0005h
IOCAN_IOCAN5_POSITION                    equ 0005h
IOCAN_IOCAN5_SIZE                        equ 0001h
IOCAN_IOCAN5_LENGTH                      equ 0001h
IOCAN_IOCAN5_MASK                        equ 0020h

// Register: IOCAF
#define IOCAF IOCAF
IOCAF                                    equ 01E93h
// bitfield definitions
IOCAF_IOCAF0_POSN                        equ 0000h
IOCAF_IOCAF0_POSITION                    equ 0000h
IOCAF_IOCAF0_SIZE                        equ 0001h
IOCAF_IOCAF0_LENGTH                      equ 0001h
IOCAF_IOCAF0_MASK                        equ 0001h
IOCAF_IOCAF1_POSN                        equ 0001h
IOCAF_IOCAF1_POSITION                    equ 0001h
IOCAF_IOCAF1_SIZE                        equ 0001h
IOCAF_IOCAF1_LENGTH                      equ 0001h
IOCAF_IOCAF1_MASK                        equ 0002h
IOCAF_IOCAF2_POSN                        equ 0002h
IOCAF_IOCAF2_POSITION                    equ 0002h
IOCAF_IOCAF2_SIZE                        equ 0001h
IOCAF_IOCAF2_LENGTH                      equ 0001h
IOCAF_IOCAF2_MASK                        equ 0004h
IOCAF_IOCAF3_POSN                        equ 0003h
IOCAF_IOCAF3_POSITION                    equ 0003h
IOCAF_IOCAF3_SIZE                        equ 0001h
IOCAF_IOCAF3_LENGTH                      equ 0001h
IOCAF_IOCAF3_MASK                        equ 0008h
IOCAF_IOCAF4_POSN                        equ 0004h
IOCAF_IOCAF4_POSITION                    equ 0004h
IOCAF_IOCAF4_SIZE                        equ 0001h
IOCAF_IOCAF4_LENGTH                      equ 0001h
IOCAF_IOCAF4_MASK                        equ 0010h
IOCAF_IOCAF5_POSN                        equ 0005h
IOCAF_IOCAF5_POSITION                    equ 0005h
IOCAF_IOCAF5_SIZE                        equ 0001h
IOCAF_IOCAF5_LENGTH                      equ 0001h
IOCAF_IOCAF5_MASK                        equ 0020h

// Register: RA1I2C
#define RA1I2C RA1I2C
RA1I2C                                   equ 01EE1h
// bitfield definitions
RA1I2C_TH_POSN                           equ 0000h
RA1I2C_TH_POSITION                       equ 0000h
RA1I2C_TH_SIZE                           equ 0002h
RA1I2C_TH_LENGTH                         equ 0002h
RA1I2C_TH_MASK                           equ 0003h
RA1I2C_PU_POSN                           equ 0004h
RA1I2C_PU_POSITION                       equ 0004h
RA1I2C_PU_SIZE                           equ 0002h
RA1I2C_PU_LENGTH                         equ 0002h
RA1I2C_PU_MASK                           equ 0030h
RA1I2C_SLEW_POSN                         equ 0006h
RA1I2C_SLEW_POSITION                     equ 0006h
RA1I2C_SLEW_SIZE                         equ 0001h
RA1I2C_SLEW_LENGTH                       equ 0001h
RA1I2C_SLEW_MASK                         equ 0040h

// Register: RA2I2C
#define RA2I2C RA2I2C
RA2I2C                                   equ 01EE2h
// bitfield definitions
RA2I2C_TH_POSN                           equ 0000h
RA2I2C_TH_POSITION                       equ 0000h
RA2I2C_TH_SIZE                           equ 0002h
RA2I2C_TH_LENGTH                         equ 0002h
RA2I2C_TH_MASK                           equ 0003h
RA2I2C_PU_POSN                           equ 0004h
RA2I2C_PU_POSITION                       equ 0004h
RA2I2C_PU_SIZE                           equ 0002h
RA2I2C_PU_LENGTH                         equ 0002h
RA2I2C_PU_MASK                           equ 0030h
RA2I2C_SLEW_POSN                         equ 0006h
RA2I2C_SLEW_POSITION                     equ 0006h
RA2I2C_SLEW_SIZE                         equ 0001h
RA2I2C_SLEW_LENGTH                       equ 0001h
RA2I2C_SLEW_MASK                         equ 0040h

// Register: UMTOAP
#define UMTOAP UMTOAP
UMTOAP                                   equ 01F0Ch
// bitfield definitions
UMTOAP_UMTOAP_POSN                       equ 0000h
UMTOAP_UMTOAP_POSITION                   equ 0000h
UMTOAP_UMTOAP_SIZE                       equ 0008h
UMTOAP_UMTOAP_LENGTH                     equ 0008h
UMTOAP_UMTOAP_MASK                       equ 00FFh

// Register: UMTOAL
#define UMTOAL UMTOAL
UMTOAL                                   equ 01F0Dh
// bitfield definitions
UMTOAL_UMTOAL_POSN                       equ 0000h
UMTOAL_UMTOAL_POSITION                   equ 0000h
UMTOAL_UMTOAL_SIZE                       equ 0008h
UMTOAL_UMTOAL_LENGTH                     equ 0008h
UMTOAL_UMTOAL_MASK                       equ 00FFh

// Register: UMTOAH
#define UMTOAH UMTOAH
UMTOAH                                   equ 01F0Eh
// bitfield definitions
UMTOAH_UMTOAH_POSN                       equ 0000h
UMTOAH_UMTOAH_POSITION                   equ 0000h
UMTOAH_UMTOAH_SIZE                       equ 0008h
UMTOAH_UMTOAH_LENGTH                     equ 0008h
UMTOAH_UMTOAH_MASK                       equ 00FFh

// Register: STATUS_SHAD
#define STATUS_SHAD STATUS_SHAD
STATUS_SHAD                              equ 01FE4h
// bitfield definitions
STATUS_SHAD_STATUS_SHAD_POSN             equ 0000h
STATUS_SHAD_STATUS_SHAD_POSITION         equ 0000h
STATUS_SHAD_STATUS_SHAD_SIZE             equ 0003h
STATUS_SHAD_STATUS_SHAD_LENGTH           equ 0003h
STATUS_SHAD_STATUS_SHAD_MASK             equ 0007h
STATUS_SHAD_STATUS_SHAD0_POSN            equ 0000h
STATUS_SHAD_STATUS_SHAD0_POSITION        equ 0000h
STATUS_SHAD_STATUS_SHAD0_SIZE            equ 0001h
STATUS_SHAD_STATUS_SHAD0_LENGTH          equ 0001h
STATUS_SHAD_STATUS_SHAD0_MASK            equ 0001h
STATUS_SHAD_STATUS_SHAD1_POSN            equ 0001h
STATUS_SHAD_STATUS_SHAD1_POSITION        equ 0001h
STATUS_SHAD_STATUS_SHAD1_SIZE            equ 0001h
STATUS_SHAD_STATUS_SHAD1_LENGTH          equ 0001h
STATUS_SHAD_STATUS_SHAD1_MASK            equ 0002h
STATUS_SHAD_STATUS_SHAD2_POSN            equ 0002h
STATUS_SHAD_STATUS_SHAD2_POSITION        equ 0002h
STATUS_SHAD_STATUS_SHAD2_SIZE            equ 0001h
STATUS_SHAD_STATUS_SHAD2_LENGTH          equ 0001h
STATUS_SHAD_STATUS_SHAD2_MASK            equ 0004h

// Register: WREG_SHAD
#define WREG_SHAD WREG_SHAD
WREG_SHAD                                equ 01FE5h
// bitfield definitions
WREG_SHAD_WREG_SHAD_POSN                 equ 0000h
WREG_SHAD_WREG_SHAD_POSITION             equ 0000h
WREG_SHAD_WREG_SHAD_SIZE                 equ 0008h
WREG_SHAD_WREG_SHAD_LENGTH               equ 0008h
WREG_SHAD_WREG_SHAD_MASK                 equ 00FFh

// Register: BSR_SHAD
#define BSR_SHAD BSR_SHAD
BSR_SHAD                                 equ 01FE6h
// bitfield definitions
BSR_SHAD_BSR_SHAD_POSN                   equ 0000h
BSR_SHAD_BSR_SHAD_POSITION               equ 0000h
BSR_SHAD_BSR_SHAD_SIZE                   equ 0008h
BSR_SHAD_BSR_SHAD_LENGTH                 equ 0008h
BSR_SHAD_BSR_SHAD_MASK                   equ 00FFh

// Register: PCLATH_SHAD
#define PCLATH_SHAD PCLATH_SHAD
PCLATH_SHAD                              equ 01FE7h
// bitfield definitions
PCLATH_SHAD_PCLATH_SHAD_POSN             equ 0000h
PCLATH_SHAD_PCLATH_SHAD_POSITION         equ 0000h
PCLATH_SHAD_PCLATH_SHAD_SIZE             equ 0008h
PCLATH_SHAD_PCLATH_SHAD_LENGTH           equ 0008h
PCLATH_SHAD_PCLATH_SHAD_MASK             equ 00FFh

// Register: FSR0L_SHAD
#define FSR0L_SHAD FSR0L_SHAD
FSR0L_SHAD                               equ 01FE8h
// bitfield definitions
FSR0L_SHAD_FSR0L_SHAD_POSN               equ 0000h
FSR0L_SHAD_FSR0L_SHAD_POSITION           equ 0000h
FSR0L_SHAD_FSR0L_SHAD_SIZE               equ 0008h
FSR0L_SHAD_FSR0L_SHAD_LENGTH             equ 0008h
FSR0L_SHAD_FSR0L_SHAD_MASK               equ 00FFh

// Register: FSR0H_SHAD
#define FSR0H_SHAD FSR0H_SHAD
FSR0H_SHAD                               equ 01FE9h
// bitfield definitions
FSR0H_SHAD_FSR0H_SHAD_POSN               equ 0000h
FSR0H_SHAD_FSR0H_SHAD_POSITION           equ 0000h
FSR0H_SHAD_FSR0H_SHAD_SIZE               equ 0008h
FSR0H_SHAD_FSR0H_SHAD_LENGTH             equ 0008h
FSR0H_SHAD_FSR0H_SHAD_MASK               equ 00FFh

// Register: FSR1L_SHAD
#define FSR1L_SHAD FSR1L_SHAD
FSR1L_SHAD                               equ 01FEAh
// bitfield definitions
FSR1L_SHAD_FSR1L_SHAD_POSN               equ 0000h
FSR1L_SHAD_FSR1L_SHAD_POSITION           equ 0000h
FSR1L_SHAD_FSR1L_SHAD_SIZE               equ 0008h
FSR1L_SHAD_FSR1L_SHAD_LENGTH             equ 0008h
FSR1L_SHAD_FSR1L_SHAD_MASK               equ 00FFh

// Register: FSR1H_SHAD
#define FSR1H_SHAD FSR1H_SHAD
FSR1H_SHAD                               equ 01FEBh
// bitfield definitions
FSR1H_SHAD_FSR1H_SHAD_POSN               equ 0000h
FSR1H_SHAD_FSR1H_SHAD_POSITION           equ 0000h
FSR1H_SHAD_FSR1H_SHAD_SIZE               equ 0008h
FSR1H_SHAD_FSR1H_SHAD_LENGTH             equ 0008h
FSR1H_SHAD_FSR1H_SHAD_MASK               equ 00FFh

// Register: STKPTR
#define STKPTR STKPTR
STKPTR                                   equ 01FEDh
// bitfield definitions
STKPTR_STKPTR0_POSN                      equ 0000h
STKPTR_STKPTR0_POSITION                  equ 0000h
STKPTR_STKPTR0_SIZE                      equ 0001h
STKPTR_STKPTR0_LENGTH                    equ 0001h
STKPTR_STKPTR0_MASK                      equ 0001h
STKPTR_STKPTR1_POSN                      equ 0001h
STKPTR_STKPTR1_POSITION                  equ 0001h
STKPTR_STKPTR1_SIZE                      equ 0001h
STKPTR_STKPTR1_LENGTH                    equ 0001h
STKPTR_STKPTR1_MASK                      equ 0002h
STKPTR_STKPTR2_POSN                      equ 0002h
STKPTR_STKPTR2_POSITION                  equ 0002h
STKPTR_STKPTR2_SIZE                      equ 0001h
STKPTR_STKPTR2_LENGTH                    equ 0001h
STKPTR_STKPTR2_MASK                      equ 0004h
STKPTR_STKPTR3_POSN                      equ 0003h
STKPTR_STKPTR3_POSITION                  equ 0003h
STKPTR_STKPTR3_SIZE                      equ 0001h
STKPTR_STKPTR3_LENGTH                    equ 0001h
STKPTR_STKPTR3_MASK                      equ 0008h
STKPTR_STKPTR4_POSN                      equ 0004h
STKPTR_STKPTR4_POSITION                  equ 0004h
STKPTR_STKPTR4_SIZE                      equ 0001h
STKPTR_STKPTR4_LENGTH                    equ 0001h
STKPTR_STKPTR4_MASK                      equ 0010h

// Register: TOSL
#define TOSL TOSL
TOSL                                     equ 01FEEh
// bitfield definitions
TOSL_TOSL_POSN                           equ 0000h
TOSL_TOSL_POSITION                       equ 0000h
TOSL_TOSL_SIZE                           equ 0008h
TOSL_TOSL_LENGTH                         equ 0008h
TOSL_TOSL_MASK                           equ 00FFh
TOSL_TOSL0_POSN                          equ 0000h
TOSL_TOSL0_POSITION                      equ 0000h
TOSL_TOSL0_SIZE                          equ 0001h
TOSL_TOSL0_LENGTH                        equ 0001h
TOSL_TOSL0_MASK                          equ 0001h
TOSL_TOSL1_POSN                          equ 0001h
TOSL_TOSL1_POSITION                      equ 0001h
TOSL_TOSL1_SIZE                          equ 0001h
TOSL_TOSL1_LENGTH                        equ 0001h
TOSL_TOSL1_MASK                          equ 0002h
TOSL_TOSL2_POSN                          equ 0002h
TOSL_TOSL2_POSITION                      equ 0002h
TOSL_TOSL2_SIZE                          equ 0001h
TOSL_TOSL2_LENGTH                        equ 0001h
TOSL_TOSL2_MASK                          equ 0004h
TOSL_TOSL3_POSN                          equ 0003h
TOSL_TOSL3_POSITION                      equ 0003h
TOSL_TOSL3_SIZE                          equ 0001h
TOSL_TOSL3_LENGTH                        equ 0001h
TOSL_TOSL3_MASK                          equ 0008h
TOSL_TOSL4_POSN                          equ 0004h
TOSL_TOSL4_POSITION                      equ 0004h
TOSL_TOSL4_SIZE                          equ 0001h
TOSL_TOSL4_LENGTH                        equ 0001h
TOSL_TOSL4_MASK                          equ 0010h
TOSL_TOSL5_POSN                          equ 0005h
TOSL_TOSL5_POSITION                      equ 0005h
TOSL_TOSL5_SIZE                          equ 0001h
TOSL_TOSL5_LENGTH                        equ 0001h
TOSL_TOSL5_MASK                          equ 0020h
TOSL_TOSL6_POSN                          equ 0006h
TOSL_TOSL6_POSITION                      equ 0006h
TOSL_TOSL6_SIZE                          equ 0001h
TOSL_TOSL6_LENGTH                        equ 0001h
TOSL_TOSL6_MASK                          equ 0040h
TOSL_TOSL7_POSN                          equ 0007h
TOSL_TOSL7_POSITION                      equ 0007h
TOSL_TOSL7_SIZE                          equ 0001h
TOSL_TOSL7_LENGTH                        equ 0001h
TOSL_TOSL7_MASK                          equ 0080h

// Register: TOSH
#define TOSH TOSH
TOSH                                     equ 01FEFh
// bitfield definitions
TOSH_TOSH_POSN                           equ 0000h
TOSH_TOSH_POSITION                       equ 0000h
TOSH_TOSH_SIZE                           equ 0008h
TOSH_TOSH_LENGTH                         equ 0008h
TOSH_TOSH_MASK                           equ 00FFh
TOSH_TOSH0_POSN                          equ 0000h
TOSH_TOSH0_POSITION                      equ 0000h
TOSH_TOSH0_SIZE                          equ 0001h
TOSH_TOSH0_LENGTH                        equ 0001h
TOSH_TOSH0_MASK                          equ 0001h
TOSH_TOSH1_POSN                          equ 0001h
TOSH_TOSH1_POSITION                      equ 0001h
TOSH_TOSH1_SIZE                          equ 0001h
TOSH_TOSH1_LENGTH                        equ 0001h
TOSH_TOSH1_MASK                          equ 0002h
TOSH_TOSH2_POSN                          equ 0002h
TOSH_TOSH2_POSITION                      equ 0002h
TOSH_TOSH2_SIZE                          equ 0001h
TOSH_TOSH2_LENGTH                        equ 0001h
TOSH_TOSH2_MASK                          equ 0004h
TOSH_TOSH3_POSN                          equ 0003h
TOSH_TOSH3_POSITION                      equ 0003h
TOSH_TOSH3_SIZE                          equ 0001h
TOSH_TOSH3_LENGTH                        equ 0001h
TOSH_TOSH3_MASK                          equ 0008h
TOSH_TOSH4_POSN                          equ 0004h
TOSH_TOSH4_POSITION                      equ 0004h
TOSH_TOSH4_SIZE                          equ 0001h
TOSH_TOSH4_LENGTH                        equ 0001h
TOSH_TOSH4_MASK                          equ 0010h
TOSH_TOSH5_POSN                          equ 0005h
TOSH_TOSH5_POSITION                      equ 0005h
TOSH_TOSH5_SIZE                          equ 0001h
TOSH_TOSH5_LENGTH                        equ 0001h
TOSH_TOSH5_MASK                          equ 0020h
TOSH_TOSH6_POSN                          equ 0006h
TOSH_TOSH6_POSITION                      equ 0006h
TOSH_TOSH6_SIZE                          equ 0001h
TOSH_TOSH6_LENGTH                        equ 0001h
TOSH_TOSH6_MASK                          equ 0040h
TOSH_TOSH7_POSN                          equ 0007h
TOSH_TOSH7_POSITION                      equ 0007h
TOSH_TOSH7_SIZE                          equ 0001h
TOSH_TOSH7_LENGTH                        equ 0001h
TOSH_TOSH7_MASK                          equ 0080h

/*
 * Bit Access Macros
 */

#ifndef PAGEMASK
#define PAGEMASK(addr) ((addr) and 07FFh)
#endif
#ifndef BANKMASK
#define BANKMASK(addr) ((addr) and 07Fh)
#endif
#define ABDEN                            BANKMASK(BAUD1CON), 0
#define ABDOVF                           BANKMASK(BAUD1CON), 7
#define ACC0                             BANKMASK(ADACCL), 0
#define ACC1                             BANKMASK(ADACCL), 1
#define ACC10                            BANKMASK(ADACCH), 2
#define ACC11                            BANKMASK(ADACCH), 3
#define ACC12                            BANKMASK(ADACCH), 4
#define ACC13                            BANKMASK(ADACCH), 5
#define ACC14                            BANKMASK(ADACCH), 6
#define ACC15                            BANKMASK(ADACCH), 7
#define ACC16                            BANKMASK(ADACCU), 0
#define ACC17                            BANKMASK(ADACCU), 1
#define ACC2                             BANKMASK(ADACCL), 2
#define ACC3                             BANKMASK(ADACCL), 3
#define ACC4                             BANKMASK(ADACCL), 4
#define ACC5                             BANKMASK(ADACCL), 5
#define ACC6                             BANKMASK(ADACCL), 6
#define ACC7                             BANKMASK(ADACCL), 7
#define ACC8                             BANKMASK(ADACCH), 0
#define ACC9                             BANKMASK(ADACCH), 1
#define ACCM                             BANKMASK(CRCCON0), 4
#define ACCMOD                           BANKMASK(CRCCON0), 4
#define ACKDT                            BANKMASK(SSP1CON2), 5
#define ACKDT1                           BANKMASK(SSP1CON2), 5
#define ACKEN                            BANKMASK(SSP1CON2), 4
#define ACKEN1                           BANKMASK(SSP1CON2), 4
#define ACKSTAT                          BANKMASK(SSP1CON2), 6
#define ACKSTAT1                         BANKMASK(SSP1CON2), 6
#define ACKTIM                           BANKMASK(SSP1CON3), 7
#define ACLR                             BANKMASK(ADCON2), 3
#define ACQ0                             BANKMASK(ADACQL), 0
#define ACQ1                             BANKMASK(ADACQL), 1
#define ACQ10                            BANKMASK(ADACQH), 2
#define ACQ11                            BANKMASK(ADACQH), 3
#define ACQ12                            BANKMASK(ADACQH), 4
#define ACQ2                             BANKMASK(ADACQL), 2
#define ACQ3                             BANKMASK(ADACQL), 3
#define ACQ4                             BANKMASK(ADACQL), 4
#define ACQ5                             BANKMASK(ADACQL), 5
#define ACQ6                             BANKMASK(ADACQL), 6
#define ACQ7                             BANKMASK(ADACQL), 7
#define ACQ8                             BANKMASK(ADACQH), 0
#define ACQ9                             BANKMASK(ADACQH), 1
#define ACT0                             BANKMASK(ADACT), 0
#define ACT1                             BANKMASK(ADACT), 1
#define ACT2                             BANKMASK(ADACT), 2
#define ACT3                             BANKMASK(ADACT), 3
#define ACT4                             BANKMASK(ADACT), 4
#define ACT5                             BANKMASK(ADACT), 5
#define ADACC0                           BANKMASK(ADACCL), 0
#define ADACC1                           BANKMASK(ADACCL), 1
#define ADACC10                          BANKMASK(ADACCH), 2
#define ADACC11                          BANKMASK(ADACCH), 3
#define ADACC12                          BANKMASK(ADACCH), 4
#define ADACC13                          BANKMASK(ADACCH), 5
#define ADACC14                          BANKMASK(ADACCH), 6
#define ADACC15                          BANKMASK(ADACCH), 7
#define ADACC16                          BANKMASK(ADACCU), 0
#define ADACC17                          BANKMASK(ADACCU), 1
#define ADACC2                           BANKMASK(ADACCL), 2
#define ADACC3                           BANKMASK(ADACCL), 3
#define ADACC4                           BANKMASK(ADACCL), 4
#define ADACC5                           BANKMASK(ADACCL), 5
#define ADACC6                           BANKMASK(ADACCL), 6
#define ADACC7                           BANKMASK(ADACCL), 7
#define ADACC8                           BANKMASK(ADACCH), 0
#define ADACC9                           BANKMASK(ADACCH), 1
#define ADACLR                           BANKMASK(ADCON2), 3
#define ADACQ0                           BANKMASK(ADACQL), 0
#define ADACQ1                           BANKMASK(ADACQL), 1
#define ADACQ10                          BANKMASK(ADACQH), 2
#define ADACQ11                          BANKMASK(ADACQH), 3
#define ADACQ12                          BANKMASK(ADACQH), 4
#define ADACQ2                           BANKMASK(ADACQL), 2
#define ADACQ3                           BANKMASK(ADACQL), 3
#define ADACQ4                           BANKMASK(ADACQL), 4
#define ADACQ5                           BANKMASK(ADACQL), 5
#define ADACQ6                           BANKMASK(ADACQL), 6
#define ADACQ7                           BANKMASK(ADACQL), 7
#define ADACQ8                           BANKMASK(ADACQH), 0
#define ADACQ9                           BANKMASK(ADACQH), 1
#define ADACT0                           BANKMASK(ADACT), 0
#define ADACT1                           BANKMASK(ADACT), 1
#define ADACT2                           BANKMASK(ADACT), 2
#define ADACT3                           BANKMASK(ADACT), 3
#define ADACT4                           BANKMASK(ADACT), 4
#define ADACT5                           BANKMASK(ADACT), 5
#define ADAOV                            BANKMASK(ADSTAT), 7
#define ADCALC0                          BANKMASK(ADCON3), 4
#define ADCALC1                          BANKMASK(ADCON3), 5
#define ADCALC2                          BANKMASK(ADCON3), 6
#define ADCAP0                           BANKMASK(ADCAP), 0
#define ADCAP1                           BANKMASK(ADCAP), 1
#define ADCAP2                           BANKMASK(ADCAP), 2
#define ADCAP3                           BANKMASK(ADCAP), 3
#define ADCAP4                           BANKMASK(ADCAP), 4
#define ADCMD                            BANKMASK(PMD4), 0
#define ADCNT0                           BANKMASK(ADCNT), 0
#define ADCNT1                           BANKMASK(ADCNT), 1
#define ADCNT2                           BANKMASK(ADCNT), 2
#define ADCNT3                           BANKMASK(ADCNT), 3
#define ADCNT4                           BANKMASK(ADCNT), 4
#define ADCNT5                           BANKMASK(ADCNT), 5
#define ADCNT6                           BANKMASK(ADCNT), 6
#define ADCNT7                           BANKMASK(ADCNT), 7
#define ADCONT                           BANKMASK(ADCON0), 6
#define ADCRS0                           BANKMASK(ADCON2), 4
#define ADCRS1                           BANKMASK(ADCON2), 5
#define ADCRS2                           BANKMASK(ADCON2), 6
#define ADCS                             BANKMASK(ADCON0), 4
#define ADCS0                            BANKMASK(ADCLK), 0
#define ADCS1                            BANKMASK(ADCLK), 1
#define ADCS2                            BANKMASK(ADCLK), 2
#define ADCS3                            BANKMASK(ADCLK), 3
#define ADCS4                            BANKMASK(ADCLK), 4
#define ADCS5                            BANKMASK(ADCLK), 5
#define ADDEN                            BANKMASK(RC1STA), 3
#define ADDSEN                           BANKMASK(ADCON1), 0
#define ADERR0                           BANKMASK(ADERRL), 0
#define ADERR1                           BANKMASK(ADERRL), 1
#define ADERR10                          BANKMASK(ADERRH), 2
#define ADERR11                          BANKMASK(ADERRH), 3
#define ADERR12                          BANKMASK(ADERRH), 4
#define ADERR13                          BANKMASK(ADERRH), 5
#define ADERR14                          BANKMASK(ADERRH), 6
#define ADERR15                          BANKMASK(ADERRH), 7
#define ADERR2                           BANKMASK(ADERRL), 2
#define ADERR3                           BANKMASK(ADERRL), 3
#define ADERR4                           BANKMASK(ADERRL), 4
#define ADERR5                           BANKMASK(ADERRL), 5
#define ADERR6                           BANKMASK(ADERRL), 6
#define ADERR7                           BANKMASK(ADERRL), 7
#define ADERR8                           BANKMASK(ADERRH), 0
#define ADERR9                           BANKMASK(ADERRH), 1
#define ADFLTR0                          BANKMASK(ADFLTRL), 0
#define ADFLTR1                          BANKMASK(ADFLTRL), 1
#define ADFLTR10                         BANKMASK(ADFLTRH), 2
#define ADFLTR11                         BANKMASK(ADFLTRH), 3
#define ADFLTR12                         BANKMASK(ADFLTRH), 4
#define ADFLTR13                         BANKMASK(ADFLTRH), 5
#define ADFLTR14                         BANKMASK(ADFLTRH), 6
#define ADFLTR15                         BANKMASK(ADFLTRH), 7
#define ADFLTR2                          BANKMASK(ADFLTRL), 2
#define ADFLTR3                          BANKMASK(ADFLTRL), 3
#define ADFLTR4                          BANKMASK(ADFLTRL), 4
#define ADFLTR5                          BANKMASK(ADFLTRL), 5
#define ADFLTR6                          BANKMASK(ADFLTRL), 6
#define ADFLTR7                          BANKMASK(ADFLTRL), 7
#define ADFLTR8                          BANKMASK(ADFLTRH), 0
#define ADFLTR9                          BANKMASK(ADFLTRH), 1
#define ADFM0                            BANKMASK(ADCON0), 2
#define ADFVR0                           BANKMASK(FVRCON), 0
#define ADFVR1                           BANKMASK(FVRCON), 1
#define ADGO                             BANKMASK(ADCON0), 0
#define ADGPOL                           BANKMASK(ADCON1), 5
#define ADIE                             BANKMASK(PIE6), 0
#define ADIF                             BANKMASK(PIR6), 0
#define ADIPEN                           BANKMASK(ADCON1), 6
#define ADLTH0                           BANKMASK(ADLTHL), 0
#define ADLTH1                           BANKMASK(ADLTHL), 1
#define ADLTH10                          BANKMASK(ADLTHH), 2
#define ADLTH11                          BANKMASK(ADLTHH), 3
#define ADLTH12                          BANKMASK(ADLTHH), 4
#define ADLTH13                          BANKMASK(ADLTHH), 5
#define ADLTH14                          BANKMASK(ADLTHH), 6
#define ADLTH15                          BANKMASK(ADLTHH), 7
#define ADLTH2                           BANKMASK(ADLTHL), 2
#define ADLTH3                           BANKMASK(ADLTHL), 3
#define ADLTH4                           BANKMASK(ADLTHL), 4
#define ADLTH5                           BANKMASK(ADLTHL), 5
#define ADLTH6                           BANKMASK(ADLTHL), 6
#define ADLTH7                           BANKMASK(ADLTHL), 7
#define ADLTH8                           BANKMASK(ADLTHH), 0
#define ADLTH9                           BANKMASK(ADLTHH), 1
#define ADLTHR                           BANKMASK(ADSTAT), 5
#define ADMATH                           BANKMASK(ADSTAT), 4
#define ADMD0                            BANKMASK(ADCON2), 0
#define ADMD1                            BANKMASK(ADCON2), 1
#define ADMD2                            BANKMASK(ADCON2), 2
#define ADMSK1                           BANKMASK(SSP1CON2), 1
#define ADMSK11                          BANKMASK(SSP1CON2), 1
#define ADMSK2                           BANKMASK(SSP1CON2), 2
#define ADMSK21                          BANKMASK(SSP1CON2), 2
#define ADMSK3                           BANKMASK(SSP1CON2), 3
#define ADMSK31                          BANKMASK(SSP1CON2), 3
#define ADMSK4                           BANKMASK(SSP1CON2), 4
#define ADMSK41                          BANKMASK(SSP1CON2), 4
#define ADMSK5                           BANKMASK(SSP1CON2), 5
#define ADMSK51                          BANKMASK(SSP1CON2), 5
#define ADOEN                            BANKMASK(OSCEN), 2
#define ADON                             BANKMASK(ADCON0), 7
#define ADOR                             BANKMASK(OSCSTAT), 2
#define ADOV                             BANKMASK(ADSTAT), 7
#define ADPCH0                           BANKMASK(ADPCH), 0
#define ADPCH1                           BANKMASK(ADPCH), 1
#define ADPCH2                           BANKMASK(ADPCH), 2
#define ADPCH3                           BANKMASK(ADPCH), 3
#define ADPCH4                           BANKMASK(ADPCH), 4
#define ADPCH5                           BANKMASK(ADPCH), 5
#define ADPPOL                           BANKMASK(ADCON1), 7
#define ADPRE0                           BANKMASK(ADPREL), 0
#define ADPRE1                           BANKMASK(ADPREL), 1
#define ADPRE10                          BANKMASK(ADPREH), 2
#define ADPRE11                          BANKMASK(ADPREH), 3
#define ADPRE12                          BANKMASK(ADPREH), 4
#define ADPRE2                           BANKMASK(ADPREL), 2
#define ADPRE3                           BANKMASK(ADPREL), 3
#define ADPRE4                           BANKMASK(ADPREL), 4
#define ADPRE5                           BANKMASK(ADPREL), 5
#define ADPRE6                           BANKMASK(ADPREL), 6
#define ADPRE7                           BANKMASK(ADPREL), 7
#define ADPRE8                           BANKMASK(ADPREH), 0
#define ADPRE9                           BANKMASK(ADPREH), 1
#define ADPREF0                          BANKMASK(ADREF), 0
#define ADPREF1                          BANKMASK(ADREF), 1
#define ADPREV0                          BANKMASK(ADPREVL), 0
#define ADPREV1                          BANKMASK(ADPREVL), 1
#define ADPREV10                         BANKMASK(ADPREVH), 2
#define ADPREV11                         BANKMASK(ADPREVH), 3
#define ADPREV12                         BANKMASK(ADPREVH), 4
#define ADPREV13                         BANKMASK(ADPREVH), 5
#define ADPREV14                         BANKMASK(ADPREVH), 6
#define ADPREV15                         BANKMASK(ADPREVH), 7
#define ADPREV2                          BANKMASK(ADPREVL), 2
#define ADPREV3                          BANKMASK(ADPREVL), 3
#define ADPREV4                          BANKMASK(ADPREVL), 4
#define ADPREV5                          BANKMASK(ADPREVL), 5
#define ADPREV6                          BANKMASK(ADPREVL), 6
#define ADPREV7                          BANKMASK(ADPREVL), 7
#define ADPREV8                          BANKMASK(ADPREVH), 0
#define ADPREV9                          BANKMASK(ADPREVH), 1
#define ADPSIS                           BANKMASK(ADCON2), 7
#define ADRES0                           BANKMASK(ADRESL), 0
#define ADRES1                           BANKMASK(ADRESL), 1
#define ADRES10                          BANKMASK(ADRESH), 2
#define ADRES11                          BANKMASK(ADRESH), 3
#define ADRES12                          BANKMASK(ADRESH), 4
#define ADRES13                          BANKMASK(ADRESH), 5
#define ADRES14                          BANKMASK(ADRESH), 6
#define ADRES15                          BANKMASK(ADRESH), 7
#define ADRES2                           BANKMASK(ADRESL), 2
#define ADRES3                           BANKMASK(ADRESL), 3
#define ADRES4                           BANKMASK(ADRESL), 4
#define ADRES5                           BANKMASK(ADRESL), 5
#define ADRES6                           BANKMASK(ADRESL), 6
#define ADRES7                           BANKMASK(ADRESL), 7
#define ADRES8                           BANKMASK(ADRESH), 0
#define ADRES9                           BANKMASK(ADRESH), 1
#define ADRPT0                           BANKMASK(ADRPT), 0
#define ADRPT1                           BANKMASK(ADRPT), 1
#define ADRPT2                           BANKMASK(ADRPT), 2
#define ADRPT3                           BANKMASK(ADRPT), 3
#define ADRPT4                           BANKMASK(ADRPT), 4
#define ADRPT5                           BANKMASK(ADRPT), 5
#define ADRPT6                           BANKMASK(ADRPT), 6
#define ADRPT7                           BANKMASK(ADRPT), 7
#define ADSOI                            BANKMASK(ADCON3), 3
#define ADSTAT0                          BANKMASK(ADSTAT), 0
#define ADSTAT1                          BANKMASK(ADSTAT), 1
#define ADSTAT2                          BANKMASK(ADSTAT), 2
#define ADSTPT0                          BANKMASK(ADSTPTL), 0
#define ADSTPT1                          BANKMASK(ADSTPTL), 1
#define ADSTPT10                         BANKMASK(ADSTPTH), 2
#define ADSTPT11                         BANKMASK(ADSTPTH), 3
#define ADSTPT12                         BANKMASK(ADSTPTH), 4
#define ADSTPT13                         BANKMASK(ADSTPTH), 5
#define ADSTPT14                         BANKMASK(ADSTPTH), 6
#define ADSTPT15                         BANKMASK(ADSTPTH), 7
#define ADSTPT2                          BANKMASK(ADSTPTL), 2
#define ADSTPT3                          BANKMASK(ADSTPTL), 3
#define ADSTPT4                          BANKMASK(ADSTPTL), 4
#define ADSTPT5                          BANKMASK(ADSTPTL), 5
#define ADSTPT6                          BANKMASK(ADSTPTL), 6
#define ADSTPT7                          BANKMASK(ADSTPTL), 7
#define ADSTPT8                          BANKMASK(ADSTPTH), 0
#define ADSTPT9                          BANKMASK(ADSTPTH), 1
#define ADTIE                            BANKMASK(PIE6), 1
#define ADTIF                            BANKMASK(PIR6), 1
#define ADTMD0                           BANKMASK(ADCON3), 0
#define ADTMD1                           BANKMASK(ADCON3), 1
#define ADTMD2                           BANKMASK(ADCON3), 2
#define ADUTH0                           BANKMASK(ADUTHL), 0
#define ADUTH1                           BANKMASK(ADUTHL), 1
#define ADUTH10                          BANKMASK(ADUTHH), 2
#define ADUTH11                          BANKMASK(ADUTHH), 3
#define ADUTH12                          BANKMASK(ADUTHH), 4
#define ADUTH13                          BANKMASK(ADUTHH), 5
#define ADUTH14                          BANKMASK(ADUTHH), 6
#define ADUTH15                          BANKMASK(ADUTHH), 7
#define ADUTH2                           BANKMASK(ADUTHL), 2
#define ADUTH3                           BANKMASK(ADUTHL), 3
#define ADUTH4                           BANKMASK(ADUTHL), 4
#define ADUTH5                           BANKMASK(ADUTHL), 5
#define ADUTH6                           BANKMASK(ADUTHL), 6
#define ADUTH7                           BANKMASK(ADUTHL), 7
#define ADUTH8                           BANKMASK(ADUTHH), 0
#define ADUTH9                           BANKMASK(ADUTHH), 1
#define ADUTHR                           BANKMASK(ADSTAT), 6
#define AHEN                             BANKMASK(SSP1CON3), 1
#define ANSA0                            BANKMASK(ANSELA), 0
#define ANSA1                            BANKMASK(ANSELA), 1
#define ANSA2                            BANKMASK(ANSELA), 2
#define ANSA4                            BANKMASK(ANSELA), 4
#define ANSA5                            BANKMASK(ANSELA), 5
#define ANSELA0                          BANKMASK(ANSELA), 0
#define ANSELA1                          BANKMASK(ANSELA), 1
#define ANSELA2                          BANKMASK(ANSELA), 2
#define ANSELA4                          BANKMASK(ANSELA), 4
#define ANSELA5                          BANKMASK(ANSELA), 5
#define AOV                              BANKMASK(ADSTAT), 7
#define ASYNC                            BANKMASK(T0CON1), 4
#define BCL1IE                           BANKMASK(PIE5), 3
#define BCL1IF                           BANKMASK(PIR5), 3
#define BF                               BANKMASK(SSP1STAT), 0
#define BF1                              BANKMASK(SSP1STAT), 0
#define BOEN                             BANKMASK(SSP1CON3), 4
#define BORRDY                           BANKMASK(BORCON), 0
#define BRG16                            BANKMASK(BAUD1CON), 3
#define BRGH                             BANKMASK(TX1STA), 2
#define BSR0                             BANKMASK(BSR), 0
#define BSR1                             BANKMASK(BSR), 1
#define BSR2                             BANKMASK(BSR), 2
#define BSR3                             BANKMASK(BSR), 3
#define BSR4                             BANKMASK(BSR), 4
#define BSR5                             BANKMASK(BSR), 5
#define C1EN                             BANKMASK(CM1CON0), 7
#define C1HYS                            BANKMASK(CM1CON0), 1
#define C1INTN                           BANKMASK(CM1CON1), 0
#define C1INTP                           BANKMASK(CM1CON1), 1
#define C1NCH0                           BANKMASK(CM1NCH), 0
#define C1NCH1                           BANKMASK(CM1NCH), 1
#define C1NCH2                           BANKMASK(CM1NCH), 2
#define C1PCH0                           BANKMASK(CM1PCH), 0
#define C1PCH1                           BANKMASK(CM1PCH), 1
#define C1PCH2                           BANKMASK(CM1PCH), 2
#define C1POL                            BANKMASK(CM1CON0), 4
#define C1SP                             BANKMASK(CM1CON0), 2
#define C1SYNC                           BANKMASK(CM1CON0), 0
#define C2EN                             BANKMASK(CM2CON0), 7
#define C2HYS                            BANKMASK(CM2CON0), 1
#define C2INTN                           BANKMASK(CM2CON1), 0
#define C2INTP                           BANKMASK(CM2CON1), 1
#define C2NCH0                           BANKMASK(CM2NCH), 0
#define C2NCH1                           BANKMASK(CM2NCH), 1
#define C2NCH2                           BANKMASK(CM2NCH), 2
#define C2PCH0                           BANKMASK(CM2PCH), 0
#define C2PCH1                           BANKMASK(CM2PCH), 1
#define C2PCH2                           BANKMASK(CM2PCH), 2
#define C2POL                            BANKMASK(CM2CON0), 4
#define C2SP                             BANKMASK(CM2CON0), 2
#define C2SYNC                           BANKMASK(CM2CON0), 0
#define CAL01                            BANKMASK(TMR1L), 0
#define CAL11                            BANKMASK(TMR1L), 1
#define CAL21                            BANKMASK(TMR1L), 2
#define CAL31                            BANKMASK(TMR1L), 3
#define CAL41                            BANKMASK(TMR1L), 4
#define CAL51                            BANKMASK(TMR1L), 5
#define CAL61                            BANKMASK(TMR1L), 6
#define CAL71                            BANKMASK(TMR1L), 7
#define CALC0                            BANKMASK(ADCON3), 4
#define CALC1                            BANKMASK(ADCON3), 5
#define CALC2                            BANKMASK(ADCON3), 6
#define CARRY                            BANKMASK(STATUS), 0
#define CCP1CTS0                         BANKMASK(CCP1CAP), 0
#define CCP1CTS1                         BANKMASK(CCP1CAP), 1
#define CCP1CTS2                         BANKMASK(CCP1CAP), 2
#define CCP1CTS3                         BANKMASK(CCP1CAP), 3
#define CCP1EN                           BANKMASK(CCP1CON), 7
#define CCP1FMT                          BANKMASK(CCP1CON), 4
#define CCP1IE                           BANKMASK(PIE2), 5
#define CCP1IF                           BANKMASK(PIR2), 5
#define CCP1MD                           BANKMASK(PMD1), 5
#define CCP1MODE0                        BANKMASK(CCP1CON), 0
#define CCP1MODE1                        BANKMASK(CCP1CON), 1
#define CCP1MODE2                        BANKMASK(CCP1CON), 2
#define CCP1MODE3                        BANKMASK(CCP1CON), 3
#define CCP1OUT                          BANKMASK(CCP1CON), 5
#define CCP1PPS0                         BANKMASK(CCP1PPS), 0
#define CCP1PPS1                         BANKMASK(CCP1PPS), 1
#define CCP1PPS2                         BANKMASK(CCP1PPS), 2
#define CCP1PPS3                         BANKMASK(CCP1PPS), 3
#define CCP1PPS4                         BANKMASK(CCP1PPS), 4
#define CCP2CTS0                         BANKMASK(CCP2CAP), 0
#define CCP2CTS1                         BANKMASK(CCP2CAP), 1
#define CCP2CTS2                         BANKMASK(CCP2CAP), 2
#define CCP2CTS3                         BANKMASK(CCP2CAP), 3
#define CCP2EN                           BANKMASK(CCP2CON), 7
#define CCP2FMT                          BANKMASK(CCP2CON), 4
#define CCP2IE                           BANKMASK(PIE2), 6
#define CCP2IF                           BANKMASK(PIR2), 6
#define CCP2MD                           BANKMASK(PMD1), 6
#define CCP2MODE0                        BANKMASK(CCP2CON), 0
#define CCP2MODE1                        BANKMASK(CCP2CON), 1
#define CCP2MODE2                        BANKMASK(CCP2CON), 2
#define CCP2MODE3                        BANKMASK(CCP2CON), 3
#define CCP2OUT                          BANKMASK(CCP2CON), 5
#define CCP2PPS0                         BANKMASK(CCP2PPS), 0
#define CCP2PPS1                         BANKMASK(CCP2PPS), 1
#define CCP2PPS2                         BANKMASK(CCP2PPS), 2
#define CCP2PPS3                         BANKMASK(CCP2PPS), 3
#define CCP2PPS4                         BANKMASK(CCP2PPS), 4
#define CDAFVR0                          BANKMASK(FVRCON), 2
#define CDAFVR1                          BANKMASK(FVRCON), 3
#define CDIV0                            BANKMASK(OSCCON2), 0
#define CDIV1                            BANKMASK(OSCCON2), 1
#define CDIV2                            BANKMASK(OSCCON2), 2
#define CDIV3                            BANKMASK(OSCCON2), 3
#define CGA0                             BANKMASK(ADCG1A), 0
#define CGA1                             BANKMASK(ADCG1A), 1
#define CGA2                             BANKMASK(ADCG1A), 2
#define CGA4                             BANKMASK(ADCG1A), 4
#define CGA5                             BANKMASK(ADCG1A), 5
#define CKE                              BANKMASK(SSP1STAT), 6
#define CKE1                             BANKMASK(SSP1STAT), 6
#define CKP                              BANKMASK(SSP1CON1), 4
#define CKP1                             BANKMASK(SSP1CON1), 4
#define CKPOL                            BANKMASK(T2HLT), 6
#define CKPS3                            BANKMASK(T0CON1), 3
#define CKSYNC                           BANKMASK(T2HLT), 5
#define CLB1IE0                          BANKMASK(PIE7), 0
#define CLB1IE1                          BANKMASK(PIE7), 1
#define CLB1IE2                          BANKMASK(PIE7), 2
#define CLB1IE3                          BANKMASK(PIE7), 3
#define CLB1IF0                          BANKMASK(PIR7), 0
#define CLB1IF1                          BANKMASK(PIR7), 1
#define CLB1IF2                          BANKMASK(PIR7), 2
#define CLB1IF3                          BANKMASK(PIR7), 3
#define CLBEN                            BANKMASK(CLBCON), 7
#define CLBMD                            BANKMASK(PMD4), 7
#define CLBSWIN0                         BANKMASK(CLBSWINL), 0
#define CLBSWIN1                         BANKMASK(CLBSWINL), 1
#define CLBSWIN10                        BANKMASK(CLBSWINM), 2
#define CLBSWIN11                        BANKMASK(CLBSWINM), 3
#define CLBSWIN12                        BANKMASK(CLBSWINM), 4
#define CLBSWIN13                        BANKMASK(CLBSWINM), 5
#define CLBSWIN14                        BANKMASK(CLBSWINM), 6
#define CLBSWIN15                        BANKMASK(CLBSWINM), 7
#define CLBSWIN16                        BANKMASK(CLBSWINH), 0
#define CLBSWIN17                        BANKMASK(CLBSWINH), 1
#define CLBSWIN18                        BANKMASK(CLBSWINH), 2
#define CLBSWIN19                        BANKMASK(CLBSWINH), 3
#define CLBSWIN2                         BANKMASK(CLBSWINL), 2
#define CLBSWIN20                        BANKMASK(CLBSWINH), 4
#define CLBSWIN21                        BANKMASK(CLBSWINH), 5
#define CLBSWIN22                        BANKMASK(CLBSWINH), 6
#define CLBSWIN23                        BANKMASK(CLBSWINH), 7
#define CLBSWIN24                        BANKMASK(CLBSWINU), 0
#define CLBSWIN25                        BANKMASK(CLBSWINU), 1
#define CLBSWIN26                        BANKMASK(CLBSWINU), 2
#define CLBSWIN27                        BANKMASK(CLBSWINU), 3
#define CLBSWIN28                        BANKMASK(CLBSWINU), 4
#define CLBSWIN29                        BANKMASK(CLBSWINU), 5
#define CLBSWIN3                         BANKMASK(CLBSWINL), 3
#define CLBSWIN30                        BANKMASK(CLBSWINU), 6
#define CLBSWIN31                        BANKMASK(CLBSWINU), 7
#define CLBSWIN4                         BANKMASK(CLBSWINL), 4
#define CLBSWIN5                         BANKMASK(CLBSWINL), 5
#define CLBSWIN6                         BANKMASK(CLBSWINL), 6
#define CLBSWIN7                         BANKMASK(CLBSWINL), 7
#define CLBSWIN8                         BANKMASK(CLBSWINM), 0
#define CLBSWIN9                         BANKMASK(CLBSWINM), 1
#define CLC1IE                           BANKMASK(PIE4), 2
#define CLC1IF                           BANKMASK(PIR4), 2
#define CLC1MD                           BANKMASK(PMD2), 5
#define CLC1OUT                          BANKMASK(CLCDATA), 0
#define CLC2IE                           BANKMASK(PIE4), 3
#define CLC2IF                           BANKMASK(PIR4), 3
#define CLC2MD                           BANKMASK(PMD2), 6
#define CLC2OUT                          BANKMASK(CLCDATA), 1
#define CLC3IE                           BANKMASK(PIE4), 4
#define CLC3IF                           BANKMASK(PIR4), 4
#define CLC3MD                           BANKMASK(PMD2), 7
#define CLC3OUT                          BANKMASK(CLCDATA), 2
#define CLC4IE                           BANKMASK(PIE4), 5
#define CLC4IF                           BANKMASK(PIR4), 5
#define CLC4MD                           BANKMASK(PMD3), 0
#define CLC4OUT                          BANKMASK(CLCDATA), 3
#define CLCIN0PPS0                       BANKMASK(CLCIN0PPS), 0
#define CLCIN0PPS1                       BANKMASK(CLCIN0PPS), 1
#define CLCIN0PPS2                       BANKMASK(CLCIN0PPS), 2
#define CLCIN0PPS3                       BANKMASK(CLCIN0PPS), 3
#define CLCIN0PPS4                       BANKMASK(CLCIN0PPS), 4
#define CLCIN1PPS0                       BANKMASK(CLCIN1PPS), 0
#define CLCIN1PPS1                       BANKMASK(CLCIN1PPS), 1
#define CLCIN1PPS2                       BANKMASK(CLCIN1PPS), 2
#define CLCIN1PPS3                       BANKMASK(CLCIN1PPS), 3
#define CLCIN1PPS4                       BANKMASK(CLCIN1PPS), 4
#define CLCIN2PPS0                       BANKMASK(CLCIN2PPS), 0
#define CLCIN2PPS1                       BANKMASK(CLCIN2PPS), 1
#define CLCIN2PPS2                       BANKMASK(CLCIN2PPS), 2
#define CLCIN2PPS3                       BANKMASK(CLCIN2PPS), 3
#define CLCIN2PPS4                       BANKMASK(CLCIN2PPS), 4
#define CLCIN3PPS0                       BANKMASK(CLCIN3PPS), 0
#define CLCIN3PPS1                       BANKMASK(CLCIN3PPS), 1
#define CLCIN3PPS2                       BANKMASK(CLCIN3PPS), 2
#define CLCIN3PPS3                       BANKMASK(CLCIN3PPS), 3
#define CLCIN3PPS4                       BANKMASK(CLCIN3PPS), 4
#define CLK0                             BANKMASK(CLBCLK), 0
#define CLK1                             BANKMASK(CLBCLK), 1
#define CLK2                             BANKMASK(CLBCLK), 2
#define CLK3                             BANKMASK(CLBCLK), 3
#define CM1IE                            BANKMASK(PIE5), 6
#define CM1IF                            BANKMASK(PIR5), 6
#define CM1MD                            BANKMASK(PMD3), 6
#define CM2IE                            BANKMASK(PIE5), 7
#define CM2IF                            BANKMASK(PIR5), 7
#define CM2MD                            BANKMASK(PMD3), 7
#define CNT0                             BANKMASK(ADCNT), 0
#define CNT1                             BANKMASK(ADCNT), 1
#define CNT2                             BANKMASK(ADCNT), 2
#define CNT3                             BANKMASK(ADCNT), 3
#define CNT4                             BANKMASK(ADCNT), 4
#define CNT5                             BANKMASK(ADCNT), 5
#define CNT6                             BANKMASK(ADCNT), 6
#define CNT7                             BANKMASK(ADCNT), 7
#define CONT                             BANKMASK(ADCON0), 6
#define COSC0                            BANKMASK(OSCCON2), 4
#define COSC1                            BANKMASK(OSCCON2), 5
#define COSC2                            BANKMASK(OSCCON2), 6
#define CPOL                             BANKMASK(T2HLT), 6
#define CPOS                             BANKMASK(CPCON), 5
#define CPRDY                            BANKMASK(CPCON), 0
#define CPREQ                            BANKMASK(CPCON), 2
#define CPT                              BANKMASK(CPCON), 1
#define CRCBUSY                          BANKMASK(CRCCON0), 5
#define CRCEN                            BANKMASK(CRCCON0), 7
#define CRCGO                            BANKMASK(CRCCON0), 6
#define CRCIE                            BANKMASK(PIE1), 1
#define CRCIF                            BANKMASK(PIR1), 1
#define CRCMD                            BANKMASK(PMD0), 1
#define CREN                             BANKMASK(RC1STA), 4
#define CRS0                             BANKMASK(ADCON2), 4
#define CRS1                             BANKMASK(ADCON2), 5
#define CRS2                             BANKMASK(ADCON2), 6
#define CS                               BANKMASK(ADCON0), 4
#define CS5                              BANKMASK(ADCLK), 5
#define CSRC                             BANKMASK(TX1STA), 7
#define CSWHOLD                          BANKMASK(OSCCON3), 7
#define CSWIE                            BANKMASK(PIE1), 4
#define CSWIF                            BANKMASK(PIR1), 4
#define CSYNC                            BANKMASK(T2HLT), 5
#define D1S0                             BANKMASK(CLCnSEL0), 0
#define D1S1                             BANKMASK(CLCnSEL0), 1
#define D1S2                             BANKMASK(CLCnSEL0), 2
#define D1S3                             BANKMASK(CLCnSEL0), 3
#define D1S4                             BANKMASK(CLCnSEL0), 4
#define D1S5                             BANKMASK(CLCnSEL0), 5
#define D1S6                             BANKMASK(CLCnSEL0), 6
#define D2S0                             BANKMASK(CLCnSEL1), 0
#define D2S1                             BANKMASK(CLCnSEL1), 1
#define D2S2                             BANKMASK(CLCnSEL1), 2
#define D2S3                             BANKMASK(CLCnSEL1), 3
#define D2S4                             BANKMASK(CLCnSEL1), 4
#define D2S5                             BANKMASK(CLCnSEL1), 5
#define D2S6                             BANKMASK(CLCnSEL1), 6
#define D3S0                             BANKMASK(CLCnSEL2), 0
#define D3S1                             BANKMASK(CLCnSEL2), 1
#define D3S2                             BANKMASK(CLCnSEL2), 2
#define D3S3                             BANKMASK(CLCnSEL2), 3
#define D3S4                             BANKMASK(CLCnSEL2), 4
#define D3S5                             BANKMASK(CLCnSEL2), 5
#define D3S6                             BANKMASK(CLCnSEL2), 6
#define D4S0                             BANKMASK(CLCnSEL3), 0
#define D4S1                             BANKMASK(CLCnSEL3), 1
#define D4S2                             BANKMASK(CLCnSEL3), 2
#define D4S3                             BANKMASK(CLCnSEL3), 3
#define D4S4                             BANKMASK(CLCnSEL3), 4
#define D4S5                             BANKMASK(CLCnSEL3), 5
#define D4S6                             BANKMASK(CLCnSEL3), 6
#define DA                               BANKMASK(SSP1STAT), 5
#define DA1                              BANKMASK(SSP1STAT), 5
#define DABORT                           BANKMASK(SCANCON0), 4
#define DAC1MD                           BANKMASK(PMD4), 1
#define DATA0                            BANKMASK(CRCDATAL), 0
#define DATA1                            BANKMASK(CRCDATAL), 1
#define DATA10                           BANKMASK(CRCDATAH), 2
#define DATA11                           BANKMASK(CRCDATAH), 3
#define DATA12                           BANKMASK(CRCDATAH), 4
#define DATA13                           BANKMASK(CRCDATAH), 5
#define DATA14                           BANKMASK(CRCDATAH), 6
#define DATA15                           BANKMASK(CRCDATAH), 7
#define DATA16                           BANKMASK(CRCDATAU), 0
#define DATA17                           BANKMASK(CRCDATAU), 1
#define DATA18                           BANKMASK(CRCDATAU), 2
#define DATA19                           BANKMASK(CRCDATAU), 3
#define DATA2                            BANKMASK(CRCDATAL), 2
#define DATA20                           BANKMASK(CRCDATAU), 4
#define DATA21                           BANKMASK(CRCDATAU), 5
#define DATA22                           BANKMASK(CRCDATAU), 6
#define DATA23                           BANKMASK(CRCDATAU), 7
#define DATA24                           BANKMASK(CRCDATAT), 0
#define DATA25                           BANKMASK(CRCDATAT), 1
#define DATA26                           BANKMASK(CRCDATAT), 2
#define DATA27                           BANKMASK(CRCDATAT), 3
#define DATA28                           BANKMASK(CRCDATAT), 4
#define DATA29                           BANKMASK(CRCDATAT), 5
#define DATA3                            BANKMASK(CRCDATAL), 3
#define DATA30                           BANKMASK(CRCDATAT), 6
#define DATA31                           BANKMASK(CRCDATAT), 7
#define DATA4                            BANKMASK(CRCDATAL), 4
#define DATA5                            BANKMASK(CRCDATAL), 5
#define DATA6                            BANKMASK(CRCDATAL), 6
#define DATA7                            BANKMASK(CRCDATAL), 7
#define DATA8                            BANKMASK(CRCDATAH), 0
#define DATA9                            BANKMASK(CRCDATAH), 1
#define DATA_ADDRESS                     BANKMASK(SSP1STAT), 5
#define DATA_ADDRESS1                    BANKMASK(SSP1STAT), 5
#define DC                               BANKMASK(STATUS), 1
#define DHEN                             BANKMASK(SSP1CON3), 0
#define DLEN0                            BANKMASK(CRCCON2), 0
#define DLEN1                            BANKMASK(CRCCON2), 1
#define DLEN2                            BANKMASK(CRCCON2), 2
#define DLEN3                            BANKMASK(CRCCON2), 3
#define DLEN4                            BANKMASK(CRCCON2), 4
#define DOE                              BANKMASK(CPUDOZE), 4
#define DONE                             BANKMASK(ADCON0), 0
#define DOZEN                            BANKMASK(CPUDOZE), 6
#define DPS                              BANKMASK(SCANDPS), 0
#define DSEN                             BANKMASK(ADCON1), 0
#define D_A                              BANKMASK(SSP1STAT), 5
#define D_A1                             BANKMASK(SSP1STAT), 5
#define D_nA                             BANKMASK(SSP1STAT), 5
#define D_nA1                            BANKMASK(SSP1STAT), 5
#define ERR0                             BANKMASK(ADERRL), 0
#define ERR1                             BANKMASK(ADERRL), 1
#define ERR10                            BANKMASK(ADERRH), 2
#define ERR11                            BANKMASK(ADERRH), 3
#define ERR12                            BANKMASK(ADERRH), 4
#define ERR13                            BANKMASK(ADERRH), 5
#define ERR14                            BANKMASK(ADERRH), 6
#define ERR15                            BANKMASK(ADERRH), 7
#define ERR2                             BANKMASK(ADERRL), 2
#define ERR3                             BANKMASK(ADERRL), 3
#define ERR4                             BANKMASK(ADERRL), 4
#define ERR5                             BANKMASK(ADERRL), 5
#define ERR6                             BANKMASK(ADERRL), 6
#define ERR7                             BANKMASK(ADERRL), 7
#define ERR8                             BANKMASK(ADERRH), 0
#define ERR9                             BANKMASK(ADERRH), 1
#define EXTOEN                           BANKMASK(OSCEN), 7
#define EXTOR                            BANKMASK(OSCSTAT), 7
#define FERR                             BANKMASK(RC1STA), 2
#define FLTR0                            BANKMASK(ADFLTRL), 0
#define FLTR1                            BANKMASK(ADFLTRL), 1
#define FLTR10                           BANKMASK(ADFLTRH), 2
#define FLTR11                           BANKMASK(ADFLTRH), 3
#define FLTR12                           BANKMASK(ADFLTRH), 4
#define FLTR13                           BANKMASK(ADFLTRH), 5
#define FLTR14                           BANKMASK(ADFLTRH), 6
#define FLTR15                           BANKMASK(ADFLTRH), 7
#define FLTR2                            BANKMASK(ADFLTRL), 2
#define FLTR3                            BANKMASK(ADFLTRL), 3
#define FLTR4                            BANKMASK(ADFLTRL), 4
#define FLTR5                            BANKMASK(ADFLTRL), 5
#define FLTR6                            BANKMASK(ADFLTRL), 6
#define FLTR7                            BANKMASK(ADFLTRL), 7
#define FLTR8                            BANKMASK(ADFLTRH), 0
#define FLTR9                            BANKMASK(ADFLTRH), 1
#define FM0                              BANKMASK(ADCON0), 2
#define FREE                             BANKMASK(NVMCON1), 4
#define FRQ0                             BANKMASK(OSCFRQ), 0
#define FRQ1                             BANKMASK(OSCFRQ), 1
#define FRQ2                             BANKMASK(OSCFRQ), 2
#define FULL                             BANKMASK(CRCCON0), 0
#define FVREN                            BANKMASK(FVRCON), 7
#define FVRMD                            BANKMASK(PMD3), 5
#define FVRRDY                           BANKMASK(FVRCON), 6
#define G1D1N                            BANKMASK(CLCnGLS0), 0
#define G1D1T                            BANKMASK(CLCnGLS0), 1
#define G1D2N                            BANKMASK(CLCnGLS0), 2
#define G1D2T                            BANKMASK(CLCnGLS0), 3
#define G1D3N                            BANKMASK(CLCnGLS0), 4
#define G1D3T                            BANKMASK(CLCnGLS0), 5
#define G1D4N                            BANKMASK(CLCnGLS0), 6
#define G1D4T                            BANKMASK(CLCnGLS0), 7
#define G1POL                            BANKMASK(CLCnPOL), 0
#define G2D1N                            BANKMASK(CLCnGLS1), 0
#define G2D1T                            BANKMASK(CLCnGLS1), 1
#define G2D2N                            BANKMASK(CLCnGLS1), 2
#define G2D2T                            BANKMASK(CLCnGLS1), 3
#define G2D3N                            BANKMASK(CLCnGLS1), 4
#define G2D3T                            BANKMASK(CLCnGLS1), 5
#define G2D4N                            BANKMASK(CLCnGLS1), 6
#define G2D4T                            BANKMASK(CLCnGLS1), 7
#define G2POL                            BANKMASK(CLCnPOL), 1
#define G3D1N                            BANKMASK(CLCnGLS2), 0
#define G3D1T                            BANKMASK(CLCnGLS2), 1
#define G3D2N                            BANKMASK(CLCnGLS2), 2
#define G3D2T                            BANKMASK(CLCnGLS2), 3
#define G3D3N                            BANKMASK(CLCnGLS2), 4
#define G3D3T                            BANKMASK(CLCnGLS2), 5
#define G3D4N                            BANKMASK(CLCnGLS2), 6
#define G3D4T                            BANKMASK(CLCnGLS2), 7
#define G3POL                            BANKMASK(CLCnPOL), 2
#define G4D1N                            BANKMASK(CLCnGLS3), 0
#define G4D1T                            BANKMASK(CLCnGLS3), 1
#define G4D2N                            BANKMASK(CLCnGLS3), 2
#define G4D2T                            BANKMASK(CLCnGLS3), 3
#define G4D3N                            BANKMASK(CLCnGLS3), 4
#define G4D3T                            BANKMASK(CLCnGLS3), 5
#define G4D4N                            BANKMASK(CLCnGLS3), 6
#define G4D4T                            BANKMASK(CLCnGLS3), 7
#define G4POL                            BANKMASK(CLCnPOL), 3
#define GCEN                             BANKMASK(SSP1CON2), 7
#define GCEN1                            BANKMASK(SSP1CON2), 7
#define GGO_nDONE                        BANKMASK(T1GCON), 3
#define GIE                              BANKMASK(INTCON), 7
#define GO_nDONE                         BANKMASK(ADCON0), 0
#define GSPM                             BANKMASK(T1GCON), 4
#define GSS0                             BANKMASK(T1GATE), 0
#define GSS1                             BANKMASK(T1GATE), 1
#define GSS2                             BANKMASK(T1GATE), 2
#define GSS3                             BANKMASK(T1GATE), 3
#define GSS4                             BANKMASK(T1GATE), 4
#define GTM                              BANKMASK(T1GCON), 5
#define GVAL                             BANKMASK(T1GCON), 2
#define HFOEN                            BANKMASK(OSCEN), 6
#define HFOR                             BANKMASK(OSCSTAT), 6
#define I2C_DAT                          BANKMASK(SSP1STAT), 5
#define I2C_DAT1                         BANKMASK(SSP1STAT), 5
#define I2C_READ                         BANKMASK(SSP1STAT), 2
#define I2C_READ1                        BANKMASK(SSP1STAT), 2
#define I2C_START                        BANKMASK(SSP1STAT), 3
#define I2C_START1                       BANKMASK(SSP1STAT), 3
#define I2C_STOP                         BANKMASK(SSP1STAT), 4
#define I2C_STOP2                        BANKMASK(SSP1STAT), 4
#define IDLEN                            BANKMASK(CPUDOZE), 7
#define INLVLA0                          BANKMASK(INLVLA), 0
#define INLVLA1                          BANKMASK(INLVLA), 1
#define INLVLA2                          BANKMASK(INLVLA), 2
#define INLVLA3                          BANKMASK(INLVLA), 3
#define INLVLA4                          BANKMASK(INLVLA), 4
#define INLVLA5                          BANKMASK(INLVLA), 5
#define INTE                             BANKMASK(PIE0), 0
#define INTEDG                           BANKMASK(INTCON), 0
#define INTF                             BANKMASK(PIR0), 0
#define INTM                             BANKMASK(SCANCON0), 3
#define INTPPS0                          BANKMASK(INTPPS), 0
#define INTPPS1                          BANKMASK(INTPPS), 1
#define INTPPS2                          BANKMASK(INTPPS), 2
#define INTPPS3                          BANKMASK(INTPPS), 3
#define INTPPS4                          BANKMASK(INTPPS), 4
#define IOCAF0                           BANKMASK(IOCAF), 0
#define IOCAF1                           BANKMASK(IOCAF), 1
#define IOCAF2                           BANKMASK(IOCAF), 2
#define IOCAF3                           BANKMASK(IOCAF), 3
#define IOCAF4                           BANKMASK(IOCAF), 4
#define IOCAF5                           BANKMASK(IOCAF), 5
#define IOCAN0                           BANKMASK(IOCAN), 0
#define IOCAN1                           BANKMASK(IOCAN), 1
#define IOCAN2                           BANKMASK(IOCAN), 2
#define IOCAN3                           BANKMASK(IOCAN), 3
#define IOCAN4                           BANKMASK(IOCAN), 4
#define IOCAN5                           BANKMASK(IOCAN), 5
#define IOCAP0                           BANKMASK(IOCAP), 0
#define IOCAP1                           BANKMASK(IOCAP), 1
#define IOCAP2                           BANKMASK(IOCAP), 2
#define IOCAP3                           BANKMASK(IOCAP), 3
#define IOCAP4                           BANKMASK(IOCAP), 4
#define IOCAP5                           BANKMASK(IOCAP), 5
#define IOCIE                            BANKMASK(PIE0), 4
#define IOCIF                            BANKMASK(PIR0), 4
#define IOCMD                            BANKMASK(PMD0), 5
#define IPEN                             BANKMASK(ADCON1), 6
#define LATA0                            BANKMASK(LATA), 0
#define LATA1                            BANKMASK(LATA), 1
#define LATA2                            BANKMASK(LATA), 2
#define LATA4                            BANKMASK(LATA), 4
#define LATA5                            BANKMASK(LATA), 5
#define LENDIAN                          BANKMASK(CRCCON0), 1
#define LFOEN                            BANKMASK(OSCEN), 4
#define LFOR                             BANKMASK(OSCSTAT), 4
#define LTH0                             BANKMASK(ADLTHL), 0
#define LTH1                             BANKMASK(ADLTHL), 1
#define LTH10                            BANKMASK(ADLTHH), 2
#define LTH11                            BANKMASK(ADLTHH), 3
#define LTH12                            BANKMASK(ADLTHH), 4
#define LTH13                            BANKMASK(ADLTHH), 5
#define LTH14                            BANKMASK(ADLTHH), 6
#define LTH15                            BANKMASK(ADLTHH), 7
#define LTH2                             BANKMASK(ADLTHL), 2
#define LTH3                             BANKMASK(ADLTHL), 3
#define LTH4                             BANKMASK(ADLTHL), 4
#define LTH5                             BANKMASK(ADLTHL), 5
#define LTH6                             BANKMASK(ADLTHL), 6
#define LTH7                             BANKMASK(ADLTHL), 7
#define LTH8                             BANKMASK(ADLTHH), 0
#define LTH9                             BANKMASK(ADLTHH), 1
#define LTHR                             BANKMASK(ADSTAT), 5
#define LWLO                             BANKMASK(NVMCON1), 5
#define MATH                             BANKMASK(ADSTAT), 4
#define MD16                             BANKMASK(T0CON0), 4
#define MD2                              BANKMASK(ADCON2), 2
#define MFOEN                            BANKMASK(OSCEN), 5
#define MFOR                             BANKMASK(OSCSTAT), 5
#define MODE4                            BANKMASK(T2HLT), 4
#define MSK01                            BANKMASK(SSP1ADD), 0
#define MSK11                            BANKMASK(SSP1ADD), 1
#define MSK21                            BANKMASK(SSP1ADD), 2
#define MSK31                            BANKMASK(SSP1ADD), 3
#define MSK41                            BANKMASK(SSP1ADD), 4
#define MSK51                            BANKMASK(SSP1ADD), 5
#define MSK61                            BANKMASK(SSP1ADD), 6
#define MSK71                            BANKMASK(SSP1ADD), 7
#define MSSP1MD                          BANKMASK(PMD3), 3
#define NDIV0                            BANKMASK(OSCCON1), 0
#define NDIV1                            BANKMASK(OSCCON1), 1
#define NDIV2                            BANKMASK(OSCCON1), 2
#define NDIV3                            BANKMASK(OSCCON1), 3
#define NOSC0                            BANKMASK(OSCCON1), 4
#define NOSC1                            BANKMASK(OSCCON1), 5
#define NOSC2                            BANKMASK(OSCCON1), 6
#define NOSCR                            BANKMASK(OSCCON3), 3
#define NVMADR0                          BANKMASK(NVMADRL), 0
#define NVMADR1                          BANKMASK(NVMADRL), 1
#define NVMADR10                         BANKMASK(NVMADRH), 2
#define NVMADR11                         BANKMASK(NVMADRH), 3
#define NVMADR12                         BANKMASK(NVMADRH), 4
#define NVMADR13                         BANKMASK(NVMADRH), 5
#define NVMADR14                         BANKMASK(NVMADRH), 6
#define NVMADR2                          BANKMASK(NVMADRL), 2
#define NVMADR3                          BANKMASK(NVMADRL), 3
#define NVMADR4                          BANKMASK(NVMADRL), 4
#define NVMADR5                          BANKMASK(NVMADRL), 5
#define NVMADR6                          BANKMASK(NVMADRL), 6
#define NVMADR7                          BANKMASK(NVMADRL), 7
#define NVMADR8                          BANKMASK(NVMADRH), 0
#define NVMADR9                          BANKMASK(NVMADRH), 1
#define NVMDAT0                          BANKMASK(NVMDATL), 0
#define NVMDAT1                          BANKMASK(NVMDATL), 1
#define NVMDAT10                         BANKMASK(NVMDATH), 2
#define NVMDAT11                         BANKMASK(NVMDATH), 3
#define NVMDAT12                         BANKMASK(NVMDATH), 4
#define NVMDAT13                         BANKMASK(NVMDATH), 5
#define NVMDAT2                          BANKMASK(NVMDATL), 2
#define NVMDAT3                          BANKMASK(NVMDATL), 3
#define NVMDAT4                          BANKMASK(NVMDATL), 4
#define NVMDAT5                          BANKMASK(NVMDATL), 5
#define NVMDAT6                          BANKMASK(NVMDATL), 6
#define NVMDAT7                          BANKMASK(NVMDATL), 7
#define NVMDAT8                          BANKMASK(NVMDATH), 0
#define NVMDAT9                          BANKMASK(NVMDATH), 1
#define NVMIE                            BANKMASK(PIE1), 0
#define NVMIF                            BANKMASK(PIR1), 0
#define NVMMD                            BANKMASK(PMD0), 0
#define NVMREGS                          BANKMASK(NVMCON1), 6
#define ODCA0                            BANKMASK(ODCONA), 0
#define ODCA1                            BANKMASK(ODCONA), 1
#define ODCA2                            BANKMASK(ODCONA), 2
#define ODCA4                            BANKMASK(ODCONA), 4
#define ODCA5                            BANKMASK(ODCONA), 5
#define OE0                              BANKMASK(DAC1CON), 4
#define OE1                              BANKMASK(DAC1CON), 5
#define OERR                             BANKMASK(RC1STA), 1
#define ORDY                             BANKMASK(OSCCON3), 4
#define OSFIE                            BANKMASK(PIE1), 5
#define OSFIF                            BANKMASK(PIR1), 5
#define OUT0                             BANKMASK(CRCOUTL), 0
#define OUT1                             BANKMASK(CRCOUTL), 1
#define OUT10                            BANKMASK(CRCOUTH), 2
#define OUT11                            BANKMASK(CRCOUTH), 3
#define OUT12                            BANKMASK(CRCOUTH), 4
#define OUT13                            BANKMASK(CRCOUTH), 5
#define OUT14                            BANKMASK(CRCOUTH), 6
#define OUT15                            BANKMASK(CRCOUTH), 7
#define OUT16                            BANKMASK(CRCOUTU), 0
#define OUT17                            BANKMASK(CRCOUTU), 1
#define OUT18                            BANKMASK(CRCOUTU), 2
#define OUT19                            BANKMASK(CRCOUTU), 3
#define OUT2                             BANKMASK(CRCOUTL), 2
#define OUT20                            BANKMASK(CRCOUTU), 4
#define OUT21                            BANKMASK(CRCOUTU), 5
#define OUT22                            BANKMASK(CRCOUTU), 6
#define OUT23                            BANKMASK(CRCOUTU), 7
#define OUT24                            BANKMASK(CRCOUTT), 0
#define OUT25                            BANKMASK(CRCOUTT), 1
#define OUT26                            BANKMASK(CRCOUTT), 2
#define OUT27                            BANKMASK(CRCOUTT), 3
#define OUT28                            BANKMASK(CRCOUTT), 4
#define OUT29                            BANKMASK(CRCOUTT), 5
#define OUT3                             BANKMASK(CRCOUTL), 3
#define OUT30                            BANKMASK(CRCOUTT), 6
#define OUT31                            BANKMASK(CRCOUTT), 7
#define OUT4                             BANKMASK(CRCOUTL), 4
#define OUT5                             BANKMASK(CRCOUTL), 5
#define OUT6                             BANKMASK(CRCOUTL), 6
#define OUT7                             BANKMASK(CRCOUTL), 7
#define OUT8                             BANKMASK(CRCOUTH), 0
#define OUT9                             BANKMASK(CRCOUTH), 1
#define OV                               BANKMASK(ADSTAT), 7
#define P1M1                             BANKMASK(CCP1CON), 7
#define P2                               BANKMASK(SSP1STAT), 4
#define P2M1                             BANKMASK(CCP2CON), 7
#define PCIE                             BANKMASK(SSP1CON3), 6
#define PCSC                             BANKMASK(ADCON1), 1
#define PEIE                             BANKMASK(INTCON), 6
#define PEN                              BANKMASK(SSP1CON2), 2
#define PEN1                             BANKMASK(SSP1CON2), 2
#define PLEN0                            BANKMASK(CRCCON1), 0
#define PLEN1                            BANKMASK(CRCCON1), 1
#define PLEN2                            BANKMASK(CRCCON1), 2
#define PLEN3                            BANKMASK(CRCCON1), 3
#define PLEN4                            BANKMASK(CRCCON1), 4
#define PLLEN                            BANKMASK(OSCEN), 0
#define PLLR                             BANKMASK(OSCSTAT), 0
#define PPOL                             BANKMASK(ADCON1), 7
#define PPSLOCKED                        BANKMASK(PPSLOCK), 0
#define PRE0                             BANKMASK(ADPREL), 0
#define PRE1                             BANKMASK(ADPREL), 1
#define PRE10                            BANKMASK(ADPREH), 2
#define PRE11                            BANKMASK(ADPREH), 3
#define PRE12                            BANKMASK(ADPREH), 4
#define PRE2                             BANKMASK(ADPREL), 2
#define PRE3                             BANKMASK(ADPREL), 3
#define PRE4                             BANKMASK(ADPREL), 4
#define PRE5                             BANKMASK(ADPREL), 5
#define PRE6                             BANKMASK(ADPREL), 6
#define PRE7                             BANKMASK(ADPREL), 7
#define PRE8                             BANKMASK(ADPREH), 0
#define PRE9                             BANKMASK(ADPREH), 1
#define PREF0                            BANKMASK(ADREF), 0
#define PREF1                            BANKMASK(ADREF), 1
#define PREV0                            BANKMASK(ADPREVL), 0
#define PREV1                            BANKMASK(ADPREVL), 1
#define PREV10                           BANKMASK(ADPREVH), 2
#define PREV11                           BANKMASK(ADPREVH), 3
#define PREV12                           BANKMASK(ADPREVH), 4
#define PREV13                           BANKMASK(ADPREVH), 5
#define PREV14                           BANKMASK(ADPREVH), 6
#define PREV15                           BANKMASK(ADPREVH), 7
#define PREV2                            BANKMASK(ADPREVL), 2
#define PREV3                            BANKMASK(ADPREVL), 3
#define PREV4                            BANKMASK(ADPREVL), 4
#define PREV5                            BANKMASK(ADPREVL), 5
#define PREV6                            BANKMASK(ADPREVL), 6
#define PREV7                            BANKMASK(ADPREVL), 7
#define PREV8                            BANKMASK(ADPREVH), 0
#define PREV9                            BANKMASK(ADPREVH), 1
#define PS0                              BANKMASK(WDTCON0), 1
#define PS1                              BANKMASK(WDTCON0), 2
#define PS2                              BANKMASK(WDTCON0), 3
#define PS3                              BANKMASK(WDTCON0), 4
#define PS4                              BANKMASK(WDTCON0), 5
#define PSCNT0                           BANKMASK(WDTPSL), 0
#define PSCNT1                           BANKMASK(WDTPSL), 1
#define PSCNT10                          BANKMASK(WDTPSH), 2
#define PSCNT11                          BANKMASK(WDTPSH), 3
#define PSCNT12                          BANKMASK(WDTPSH), 4
#define PSCNT13                          BANKMASK(WDTPSH), 5
#define PSCNT14                          BANKMASK(WDTPSH), 6
#define PSCNT15                          BANKMASK(WDTPSH), 7
#define PSCNT16                          BANKMASK(WDTTMR), 0
#define PSCNT17                          BANKMASK(WDTTMR), 1
#define PSCNT2                           BANKMASK(WDTPSL), 2
#define PSCNT3                           BANKMASK(WDTPSL), 3
#define PSCNT4                           BANKMASK(WDTPSL), 4
#define PSCNT5                           BANKMASK(WDTPSL), 5
#define PSCNT6                           BANKMASK(WDTPSL), 6
#define PSCNT7                           BANKMASK(WDTPSL), 7
#define PSCNT8                           BANKMASK(WDTPSH), 0
#define PSCNT9                           BANKMASK(WDTPSH), 1
#define PSIS                             BANKMASK(ADCON2), 7
#define PSS0                             BANKMASK(DAC1CON), 2
#define PSS1                             BANKMASK(DAC1CON), 3
#define PSYNC                            BANKMASK(T2HLT), 7
#define PWM1EN                           BANKMASK(PWM1CON), 7
#define PWM1MD                           BANKMASK(PMD5), 0
#define PWM1OUT                          BANKMASK(PWM1CON), 5
#define PWM1POL                          BANKMASK(PWM1CON), 4
#define PWM2EN                           BANKMASK(PWM2CON), 7
#define PWM2MD                           BANKMASK(PMD5), 1
#define PWM2OUT                          BANKMASK(PWM2CON), 5
#define PWM2POL                          BANKMASK(PWM2CON), 4
#define RA0                              BANKMASK(PORTA), 0
#define RA1                              BANKMASK(PORTA), 1
#define RA2                              BANKMASK(PORTA), 2
#define RA3                              BANKMASK(PORTA), 3
#define RA4                              BANKMASK(PORTA), 4
#define RA5                              BANKMASK(PORTA), 5
#define RC1IE                            BANKMASK(PIE4), 7
#define RC1IF                            BANKMASK(PIR4), 7
#define RCEN                             BANKMASK(SSP1CON2), 3
#define RCEN1                            BANKMASK(SSP1CON2), 3
#define RCIDL                            BANKMASK(BAUD1CON), 6
#define RD                               BANKMASK(NVMCON1), 0
#define RD16                             BANKMASK(T1CON), 1
#define RD161                            BANKMASK(T1CON), 1
#define RDY                              BANKMASK(FVRCON), 6
#define READ_WRITE                       BANKMASK(SSP1STAT), 2
#define READ_WRITE1                      BANKMASK(SSP1STAT), 2
#define REFRNG                           BANKMASK(DAC1CON), 6
#define RES0                             BANKMASK(ADRESL), 0
#define RES1                             BANKMASK(ADRESL), 1
#define RES10                            BANKMASK(ADRESH), 2
#define RES11                            BANKMASK(ADRESH), 3
#define RES12                            BANKMASK(ADRESH), 4
#define RES13                            BANKMASK(ADRESH), 5
#define RES14                            BANKMASK(ADRESH), 6
#define RES15                            BANKMASK(ADRESH), 7
#define RES2                             BANKMASK(ADRESL), 2
#define RES3                             BANKMASK(ADRESL), 3
#define RES4                             BANKMASK(ADRESL), 4
#define RES5                             BANKMASK(ADRESL), 5
#define RES6                             BANKMASK(ADRESL), 6
#define RES7                             BANKMASK(ADRESL), 7
#define RES8                             BANKMASK(ADRESH), 0
#define RES9                             BANKMASK(ADRESH), 1
#define ROI                              BANKMASK(CPUDOZE), 5
#define RPT0                             BANKMASK(ADRPT), 0
#define RPT1                             BANKMASK(ADRPT), 1
#define RPT2                             BANKMASK(ADRPT), 2
#define RPT3                             BANKMASK(ADRPT), 3
#define RPT4                             BANKMASK(ADRPT), 4
#define RPT5                             BANKMASK(ADRPT), 5
#define RPT6                             BANKMASK(ADRPT), 6
#define RPT7                             BANKMASK(ADRPT), 7
#define RSEL0                            BANKMASK(T2RST), 0
#define RSEL1                            BANKMASK(T2RST), 1
#define RSEL2                            BANKMASK(T2RST), 2
#define RSEL3                            BANKMASK(T2RST), 3
#define RSEL4                            BANKMASK(T2RST), 4
#define RSEN                             BANKMASK(SSP1CON2), 1
#define RSEN1                            BANKMASK(SSP1CON2), 1
#define RW                               BANKMASK(SSP1STAT), 2
#define RW1                              BANKMASK(SSP1STAT), 2
#define RX9                              BANKMASK(RC1STA), 6
#define RX9D                             BANKMASK(RC1STA), 0
#define R_W                              BANKMASK(SSP1STAT), 2
#define R_W1                             BANKMASK(SSP1STAT), 2
#define R_nW                             BANKMASK(SSP1STAT), 2
#define R_nW1                            BANKMASK(SSP1STAT), 2
#define S2                               BANKMASK(SSP1STAT), 3
#define SBCDE                            BANKMASK(SSP1CON3), 2
#define SBOREN                           BANKMASK(BORCON), 7
#define SCANIE                           BANKMASK(PIE1), 2
#define SCANIF                           BANKMASK(PIR1), 2
#define SCANMD                           BANKMASK(PMD0), 2
#define SCIE                             BANKMASK(SSP1CON3), 5
#define SCKP                             BANKMASK(BAUD1CON), 4
#define SDAHT                            BANKMASK(SSP1CON3), 3
#define SEN1                             BANKMASK(SSP1CON2), 0
#define SENDB                            BANKMASK(TX1STA), 3
#define SETUP0                           BANKMASK(CRCCON0), 2
#define SETUP1                           BANKMASK(CRCCON0), 3
#define SFOR                             BANKMASK(OSCSTAT), 1
#define SGO                              BANKMASK(SCANCON0), 6
#define SHIFT0                           BANKMASK(CRCSHFTL), 0
#define SHIFT1                           BANKMASK(CRCSHFTL), 1
#define SHIFT10                          BANKMASK(CRCSHFTH), 2
#define SHIFT11                          BANKMASK(CRCSHFTH), 3
#define SHIFT12                          BANKMASK(CRCSHFTH), 4
#define SHIFT13                          BANKMASK(CRCSHFTH), 5
#define SHIFT14                          BANKMASK(CRCSHFTH), 6
#define SHIFT15                          BANKMASK(CRCSHFTH), 7
#define SHIFT16                          BANKMASK(CRCSHFTU), 0
#define SHIFT17                          BANKMASK(CRCSHFTU), 1
#define SHIFT18                          BANKMASK(CRCSHFTU), 2
#define SHIFT19                          BANKMASK(CRCSHFTU), 3
#define SHIFT2                           BANKMASK(CRCSHFTL), 2
#define SHIFT20                          BANKMASK(CRCSHFTU), 4
#define SHIFT21                          BANKMASK(CRCSHFTU), 5
#define SHIFT22                          BANKMASK(CRCSHFTU), 6
#define SHIFT23                          BANKMASK(CRCSHFTU), 7
#define SHIFT24                          BANKMASK(CRCSHFTT), 0
#define SHIFT25                          BANKMASK(CRCSHFTT), 1
#define SHIFT26                          BANKMASK(CRCSHFTT), 2
#define SHIFT27                          BANKMASK(CRCSHFTT), 3
#define SHIFT28                          BANKMASK(CRCSHFTT), 4
#define SHIFT29                          BANKMASK(CRCSHFTT), 5
#define SHIFT3                           BANKMASK(CRCSHFTL), 3
#define SHIFT30                          BANKMASK(CRCSHFTT), 6
#define SHIFT31                          BANKMASK(CRCSHFTT), 7
#define SHIFT4                           BANKMASK(CRCSHFTL), 4
#define SHIFT5                           BANKMASK(CRCSHFTL), 5
#define SHIFT6                           BANKMASK(CRCSHFTL), 6
#define SHIFT7                           BANKMASK(CRCSHFTL), 7
#define SHIFT8                           BANKMASK(CRCSHFTH), 0
#define SHIFT9                           BANKMASK(CRCSHFTH), 1
#define SHIFTM                           BANKMASK(CRCCON0), 1
#define SLCT0                            BANKMASK(CLCSELECT), 0
#define SLCT1                            BANKMASK(CLCSELECT), 1
#define SLRA0                            BANKMASK(SLRCONA), 0
#define SLRA1                            BANKMASK(SLRCONA), 1
#define SLRA2                            BANKMASK(SLRCONA), 2
#define SLRA4                            BANKMASK(SLRCONA), 4
#define SLRA5                            BANKMASK(SLRCONA), 5
#define SMP                              BANKMASK(SSP1STAT), 7
#define SMP1                             BANKMASK(SSP1STAT), 7
#define SOI                              BANKMASK(ADCON3), 3
#define SPEN                             BANKMASK(RC1STA), 7
#define SREN                             BANKMASK(RC1STA), 5
#define SSP1CLKPPS0                      BANKMASK(SSP1CLKPPS), 0
#define SSP1CLKPPS1                      BANKMASK(SSP1CLKPPS), 1
#define SSP1CLKPPS2                      BANKMASK(SSP1CLKPPS), 2
#define SSP1CLKPPS3                      BANKMASK(SSP1CLKPPS), 3
#define SSP1CLKPPS4                      BANKMASK(SSP1CLKPPS), 4
#define SSP1DATPPS0                      BANKMASK(SSP1DATPPS), 0
#define SSP1DATPPS1                      BANKMASK(SSP1DATPPS), 1
#define SSP1DATPPS2                      BANKMASK(SSP1DATPPS), 2
#define SSP1DATPPS3                      BANKMASK(SSP1DATPPS), 3
#define SSP1DATPPS4                      BANKMASK(SSP1DATPPS), 4
#define SSP1IE                           BANKMASK(PIE5), 2
#define SSP1IF                           BANKMASK(PIR5), 2
#define SSP1SSPPS0                       BANKMASK(SSP1SSPPS), 0
#define SSP1SSPPS1                       BANKMASK(SSP1SSPPS), 1
#define SSP1SSPPS2                       BANKMASK(SSP1SSPPS), 2
#define SSP1SSPPS3                       BANKMASK(SSP1SSPPS), 3
#define SSP1SSPPS4                       BANKMASK(SSP1SSPPS), 4
#define SSPEN                            BANKMASK(SSP1CON1), 5
#define SSPEN1                           BANKMASK(SSP1CON1), 5
#define SSPM0                            BANKMASK(SSP1CON1), 0
#define SSPM01                           BANKMASK(SSP1CON1), 0
#define SSPM1                            BANKMASK(SSP1CON1), 1
#define SSPM11                           BANKMASK(SSP1CON1), 1
#define SSPM2                            BANKMASK(SSP1CON1), 2
#define SSPM21                           BANKMASK(SSP1CON1), 2
#define SSPM3                            BANKMASK(SSP1CON1), 3
#define SSPM31                           BANKMASK(SSP1CON1), 3
#define SSPOV                            BANKMASK(SSP1CON1), 6
#define SSPOV1                           BANKMASK(SSP1CON1), 6
#define START                            BANKMASK(SSP1STAT), 3
#define START1                           BANKMASK(SSP1STAT), 3
#define STAT0                            BANKMASK(ADSTAT), 0
#define STAT1                            BANKMASK(ADSTAT), 1
#define STAT2                            BANKMASK(ADSTAT), 2
#define STATE                            BANKMASK(WDTTMR), 2
#define STATUS_SHAD0                     BANKMASK(STATUS_SHAD), 0
#define STATUS_SHAD1                     BANKMASK(STATUS_SHAD), 1
#define STATUS_SHAD2                     BANKMASK(STATUS_SHAD), 2
#define STKOVF                           BANKMASK(PCON0), 7
#define STKPTR0                          BANKMASK(STKPTR), 0
#define STKPTR1                          BANKMASK(STKPTR), 1
#define STKPTR2                          BANKMASK(STKPTR), 2
#define STKPTR3                          BANKMASK(STKPTR), 3
#define STKPTR4                          BANKMASK(STKPTR), 4
#define STKUNF                           BANKMASK(PCON0), 6
#define STOP                             BANKMASK(SSP1STAT), 4
#define STOP1                            BANKMASK(SSP1STAT), 4
#define STPT0                            BANKMASK(ADSTPTL), 0
#define STPT1                            BANKMASK(ADSTPTL), 1
#define STPT10                           BANKMASK(ADSTPTH), 2
#define STPT11                           BANKMASK(ADSTPTH), 3
#define STPT12                           BANKMASK(ADSTPTH), 4
#define STPT13                           BANKMASK(ADSTPTH), 5
#define STPT15                           BANKMASK(ADSTPTH), 6
#define STPT16                           BANKMASK(ADSTPTH), 7
#define STPT2                            BANKMASK(ADSTPTL), 2
#define STPT3                            BANKMASK(ADSTPTL), 3
#define STPT4                            BANKMASK(ADSTPTL), 4
#define STPT5                            BANKMASK(ADSTPTL), 5
#define STPT6                            BANKMASK(ADSTPTL), 6
#define STPT7                            BANKMASK(ADSTPTL), 7
#define STPT8                            BANKMASK(ADSTPTH), 0
#define STPT9                            BANKMASK(ADSTPTH), 1
#define SWDTEN                           BANKMASK(WDTCON0), 0
#define SYSCMD                           BANKMASK(PMD0), 3
#define T016BIT                          BANKMASK(T0CON0), 4
#define T0ASYNC                          BANKMASK(T0CON1), 4
#define T0CKIPPS0                        BANKMASK(T0CKIPPS), 0
#define T0CKIPPS1                        BANKMASK(T0CKIPPS), 1
#define T0CKIPPS2                        BANKMASK(T0CKIPPS), 2
#define T0CKIPPS3                        BANKMASK(T0CKIPPS), 3
#define T0CKIPPS4                        BANKMASK(T0CKIPPS), 4
#define T0CKPS0                          BANKMASK(T0CON1), 0
#define T0CKPS1                          BANKMASK(T0CON1), 1
#define T0CKPS2                          BANKMASK(T0CON1), 2
#define T0CKPS3                          BANKMASK(T0CON1), 3
#define T0CS0                            BANKMASK(T0CON1), 5
#define T0CS1                            BANKMASK(T0CON1), 6
#define T0CS2                            BANKMASK(T0CON1), 7
#define T0EN                             BANKMASK(T0CON0), 7
#define T0MD16                           BANKMASK(T0CON0), 4
#define T0OUT                            BANKMASK(T0CON0), 5
#define T0OUTPS0                         BANKMASK(T0CON0), 0
#define T0OUTPS1                         BANKMASK(T0CON0), 1
#define T0OUTPS2                         BANKMASK(T0CON0), 2
#define T0OUTPS3                         BANKMASK(T0CON0), 3
#define T0PR0                            BANKMASK(TMR0H), 0
#define T0PR1                            BANKMASK(TMR0H), 1
#define T0PR2                            BANKMASK(TMR0H), 2
#define T0PR3                            BANKMASK(TMR0H), 3
#define T0PR4                            BANKMASK(TMR0H), 4
#define T0PR5                            BANKMASK(TMR0H), 5
#define T0PR6                            BANKMASK(TMR0H), 6
#define T0PR7                            BANKMASK(TMR0H), 7
#define T1CKIPPS0                        BANKMASK(T1CKIPPS), 0
#define T1CKIPPS1                        BANKMASK(T1CKIPPS), 1
#define T1CKIPPS2                        BANKMASK(T1CKIPPS), 2
#define T1CKIPPS3                        BANKMASK(T1CKIPPS), 3
#define T1CKIPPS4                        BANKMASK(T1CKIPPS), 4
#define T1CKPS0                          BANKMASK(T1CON), 4
#define T1CKPS1                          BANKMASK(T1CON), 5
#define T1CS0                            BANKMASK(T1CLK), 0
#define T1CS1                            BANKMASK(T1CLK), 1
#define T1CS2                            BANKMASK(T1CLK), 2
#define T1CS3                            BANKMASK(T1CLK), 3
#define T1CS4                            BANKMASK(T1CLK), 4
#define T1GE                             BANKMASK(T1GCON), 7
#define T1GGO                            BANKMASK(T1GCON), 3
#define T1GGO_nDONE                      BANKMASK(T1GCON), 3
#define T1GPOL                           BANKMASK(T1GCON), 6
#define T1GPPS0                          BANKMASK(T1GPPS), 0
#define T1GPPS1                          BANKMASK(T1GPPS), 1
#define T1GPPS2                          BANKMASK(T1GPPS), 2
#define T1GPPS3                          BANKMASK(T1GPPS), 3
#define T1GPPS4                          BANKMASK(T1GPPS), 4
#define T1GSPM                           BANKMASK(T1GCON), 4
#define T1GSS0                           BANKMASK(T1GATE), 0
#define T1GSS1                           BANKMASK(T1GATE), 1
#define T1GSS2                           BANKMASK(T1GATE), 2
#define T1GSS3                           BANKMASK(T1GATE), 3
#define T1GSS4                           BANKMASK(T1GATE), 4
#define T1GTM                            BANKMASK(T1GCON), 5
#define T1GVAL                           BANKMASK(T1GCON), 2
#define T1RD16                           BANKMASK(T1CON), 1
#define T2CKPS0                          BANKMASK(T2CON), 4
#define T2CKPS1                          BANKMASK(T2CON), 5
#define T2CKPS2                          BANKMASK(T2CON), 6
#define T2CPOL                           BANKMASK(T2HLT), 6
#define T2CS0                            BANKMASK(T2CLKCON), 0
#define T2CS1                            BANKMASK(T2CLKCON), 1
#define T2CS2                            BANKMASK(T2CLKCON), 2
#define T2CS3                            BANKMASK(T2CLKCON), 3
#define T2CS4                            BANKMASK(T2CLKCON), 4
#define T2CSYNC                          BANKMASK(T2HLT), 5
#define T2INPPS0                         BANKMASK(T2INPPS), 0
#define T2INPPS1                         BANKMASK(T2INPPS), 1
#define T2INPPS2                         BANKMASK(T2INPPS), 2
#define T2INPPS3                         BANKMASK(T2INPPS), 3
#define T2INPPS4                         BANKMASK(T2INPPS), 4
#define T2MODE0                          BANKMASK(T2HLT), 0
#define T2MODE1                          BANKMASK(T2HLT), 1
#define T2MODE2                          BANKMASK(T2HLT), 2
#define T2MODE3                          BANKMASK(T2HLT), 3
#define T2MODE4                          BANKMASK(T2HLT), 4
#define T2ON                             BANKMASK(T2CON), 7
#define T2OUTPS0                         BANKMASK(T2CON), 0
#define T2OUTPS1                         BANKMASK(T2CON), 1
#define T2OUTPS2                         BANKMASK(T2CON), 2
#define T2OUTPS3                         BANKMASK(T2CON), 3
#define T2PSYNC                          BANKMASK(T2HLT), 7
#define T2RSEL0                          BANKMASK(T2RST), 0
#define T2RSEL1                          BANKMASK(T2RST), 1
#define T2RSEL2                          BANKMASK(T2RST), 2
#define T2RSEL3                          BANKMASK(T2RST), 3
#define T2RSEL4                          BANKMASK(T2RST), 4
#define TMD0                             BANKMASK(ADCON3), 0
#define TMD1                             BANKMASK(ADCON3), 1
#define TMD2                             BANKMASK(ADCON3), 2
#define TMR0H0                           BANKMASK(TMR0H), 0
#define TMR0H1                           BANKMASK(TMR0H), 1
#define TMR0H2                           BANKMASK(TMR0H), 2
#define TMR0H3                           BANKMASK(TMR0H), 3
#define TMR0H4                           BANKMASK(TMR0H), 4
#define TMR0H5                           BANKMASK(TMR0H), 5
#define TMR0H6                           BANKMASK(TMR0H), 6
#define TMR0H7                           BANKMASK(TMR0H), 7
#define TMR0IE                           BANKMASK(PIE0), 5
#define TMR0IF                           BANKMASK(PIR0), 5
#define TMR0L0                           BANKMASK(TMR0L), 0
#define TMR0L1                           BANKMASK(TMR0L), 1
#define TMR0L2                           BANKMASK(TMR0L), 2
#define TMR0L3                           BANKMASK(TMR0L), 3
#define TMR0L4                           BANKMASK(TMR0L), 4
#define TMR0L5                           BANKMASK(TMR0L), 5
#define TMR0L6                           BANKMASK(TMR0L), 6
#define TMR0L7                           BANKMASK(TMR0L), 7
#define TMR0MD                           BANKMASK(PMD0), 7
#define TMR10                            BANKMASK(TMR1L), 0
#define TMR11                            BANKMASK(TMR1L), 1
#define TMR110                           BANKMASK(TMR1H), 2
#define TMR111                           BANKMASK(TMR1H), 3
#define TMR112                           BANKMASK(TMR1H), 4
#define TMR113                           BANKMASK(TMR1H), 5
#define TMR114                           BANKMASK(TMR1H), 6
#define TMR115                           BANKMASK(TMR1H), 7
#define TMR12                            BANKMASK(TMR1L), 2
#define TMR13                            BANKMASK(TMR1L), 3
#define TMR14                            BANKMASK(TMR1L), 4
#define TMR15                            BANKMASK(TMR1L), 5
#define TMR16                            BANKMASK(TMR1L), 6
#define TMR17                            BANKMASK(TMR1L), 7
#define TMR18                            BANKMASK(TMR1H), 0
#define TMR19                            BANKMASK(TMR1H), 1
#define TMR1GIE                          BANKMASK(PIE1), 7
#define TMR1GIF                          BANKMASK(PIR1), 7
#define TMR1H0                           BANKMASK(TMR1H), 0
#define TMR1H1                           BANKMASK(TMR1H), 1
#define TMR1H2                           BANKMASK(TMR1H), 2
#define TMR1H3                           BANKMASK(TMR1H), 3
#define TMR1H4                           BANKMASK(TMR1H), 4
#define TMR1H5                           BANKMASK(TMR1H), 5
#define TMR1H6                           BANKMASK(TMR1H), 6
#define TMR1H7                           BANKMASK(TMR1H), 7
#define TMR1IE                           BANKMASK(PIE1), 6
#define TMR1IF                           BANKMASK(PIR1), 6
#define TMR1L0                           BANKMASK(TMR1L), 0
#define TMR1L1                           BANKMASK(TMR1L), 1
#define TMR1L2                           BANKMASK(TMR1L), 2
#define TMR1L3                           BANKMASK(TMR1L), 3
#define TMR1L4                           BANKMASK(TMR1L), 4
#define TMR1L5                           BANKMASK(TMR1L), 5
#define TMR1L6                           BANKMASK(TMR1L), 6
#define TMR1L7                           BANKMASK(TMR1L), 7
#define TMR1MD                           BANKMASK(PMD1), 0
#define TMR1ON                           BANKMASK(T1CON), 0
#define TMR2IE                           BANKMASK(PIE2), 2
#define TMR2IF                           BANKMASK(PIR2), 2
#define TMR2MD                           BANKMASK(PMD1), 2
#define TMR2ON                           BANKMASK(T2CON), 7
#define TOSH0                            BANKMASK(TOSH), 0
#define TOSH1                            BANKMASK(TOSH), 1
#define TOSH2                            BANKMASK(TOSH), 2
#define TOSH3                            BANKMASK(TOSH), 3
#define TOSH4                            BANKMASK(TOSH), 4
#define TOSH5                            BANKMASK(TOSH), 5
#define TOSH6                            BANKMASK(TOSH), 6
#define TOSH7                            BANKMASK(TOSH), 7
#define TOSL0                            BANKMASK(TOSL), 0
#define TOSL1                            BANKMASK(TOSL), 1
#define TOSL2                            BANKMASK(TOSL), 2
#define TOSL3                            BANKMASK(TOSL), 3
#define TOSL4                            BANKMASK(TOSL), 4
#define TOSL5                            BANKMASK(TOSL), 5
#define TOSL6                            BANKMASK(TOSL), 6
#define TOSL7                            BANKMASK(TOSL), 7
#define TRISA0                           BANKMASK(TRISA), 0
#define TRISA1                           BANKMASK(TRISA), 1
#define TRISA2                           BANKMASK(TRISA), 2
#define TRISA4                           BANKMASK(TRISA), 4
#define TRISA5                           BANKMASK(TRISA), 5
#define TRMT                             BANKMASK(TX1STA), 1
#define TSEN                             BANKMASK(FVRCON), 5
#define TSRNG                            BANKMASK(FVRCON), 4
#define TUN0                             BANKMASK(OSCTUNE), 0
#define TUN1                             BANKMASK(OSCTUNE), 1
#define TUN2                             BANKMASK(OSCTUNE), 2
#define TUN3                             BANKMASK(OSCTUNE), 3
#define TUN4                             BANKMASK(OSCTUNE), 4
#define TUN5                             BANKMASK(OSCTUNE), 5
#define TX1IE                            BANKMASK(PIE4), 6
#define TX1IF                            BANKMASK(PIR4), 6
#define TX9                              BANKMASK(TX1STA), 6
#define TX9D                             BANKMASK(TX1STA), 0
#define TXEN                             BANKMASK(TX1STA), 5
#define UA                               BANKMASK(SSP1STAT), 1
#define UA1                              BANKMASK(SSP1STAT), 1
#define UART1MD                          BANKMASK(PMD3), 1
#define UTH0                             BANKMASK(ADUTHL), 0
#define UTH1                             BANKMASK(ADUTHL), 1
#define UTH10                            BANKMASK(ADUTHH), 2
#define UTH11                            BANKMASK(ADUTHH), 3
#define UTH12                            BANKMASK(ADUTHH), 4
#define UTH13                            BANKMASK(ADUTHH), 5
#define UTH14                            BANKMASK(ADUTHH), 6
#define UTH15                            BANKMASK(ADUTHH), 7
#define UTH2                             BANKMASK(ADUTHL), 2
#define UTH3                             BANKMASK(ADUTHL), 3
#define UTH4                             BANKMASK(ADUTHL), 4
#define UTH5                             BANKMASK(ADUTHL), 5
#define UTH6                             BANKMASK(ADUTHL), 6
#define UTH7                             BANKMASK(ADUTHL), 7
#define UTH8                             BANKMASK(ADUTHH), 0
#define UTH9                             BANKMASK(ADUTHH), 1
#define UTHR                             BANKMASK(ADSTAT), 6
#define WCOL                             BANKMASK(SSP1CON1), 7
#define WCOL1                            BANKMASK(SSP1CON1), 7
#define WDTCS0                           BANKMASK(WDTCON1), 4
#define WDTCS1                           BANKMASK(WDTCON1), 5
#define WDTCS2                           BANKMASK(WDTCON1), 6
#define WDTPS0                           BANKMASK(WDTCON0), 1
#define WDTPS1                           BANKMASK(WDTCON0), 2
#define WDTPS2                           BANKMASK(WDTCON0), 3
#define WDTPS3                           BANKMASK(WDTCON0), 4
#define WDTPS4                           BANKMASK(WDTCON0), 5
#define WDTPSCNT16                       BANKMASK(WDTTMR), 0
#define WDTPSCNT17                       BANKMASK(WDTTMR), 1
#define WDTSEN                           BANKMASK(WDTCON0), 0
#define WDTSTATE                         BANKMASK(WDTTMR), 2
#define WDTTMR0                          BANKMASK(WDTTMR), 3
#define WDTTMR1                          BANKMASK(WDTTMR), 4
#define WDTTMR2                          BANKMASK(WDTTMR), 5
#define WDTTMR3                          BANKMASK(WDTTMR), 6
#define WDTTMR4                          BANKMASK(WDTTMR), 7
#define WDTWINDOW0                       BANKMASK(WDTCON1), 0
#define WDTWINDOW1                       BANKMASK(WDTCON1), 1
#define WDTWINDOW2                       BANKMASK(WDTCON1), 2
#define WINDOW0                          BANKMASK(WDTCON1), 0
#define WINDOW1                          BANKMASK(WDTCON1), 1
#define WINDOW2                          BANKMASK(WDTCON1), 2
#define WPUA0                            BANKMASK(WPUA), 0
#define WPUA1                            BANKMASK(WPUA), 1
#define WPUA2                            BANKMASK(WPUA), 2
#define WPUA3                            BANKMASK(WPUA), 3
#define WPUA4                            BANKMASK(WPUA), 4
#define WPUA5                            BANKMASK(WPUA), 5
#define WR                               BANKMASK(NVMCON1), 1
#define WREN                             BANKMASK(NVMCON1), 2
#define WRERR                            BANKMASK(NVMCON1), 3
#define WUE                              BANKMASK(BAUD1CON), 1
#define XOR0                             BANKMASK(CRCXORL), 0
#define XOR1                             BANKMASK(CRCXORL), 1
#define XOR10                            BANKMASK(CRCXORH), 2
#define XOR11                            BANKMASK(CRCXORH), 3
#define XOR12                            BANKMASK(CRCXORH), 4
#define XOR13                            BANKMASK(CRCXORH), 5
#define XOR14                            BANKMASK(CRCXORH), 6
#define XOR15                            BANKMASK(CRCXORH), 7
#define XOR16                            BANKMASK(CRCXORU), 0
#define XOR17                            BANKMASK(CRCXORU), 1
#define XOR18                            BANKMASK(CRCXORU), 2
#define XOR19                            BANKMASK(CRCXORU), 3
#define XOR2                             BANKMASK(CRCXORL), 2
#define XOR20                            BANKMASK(CRCXORU), 4
#define XOR21                            BANKMASK(CRCXORU), 5
#define XOR22                            BANKMASK(CRCXORU), 6
#define XOR23                            BANKMASK(CRCXORU), 7
#define XOR24                            BANKMASK(CRCXORT), 0
#define XOR25                            BANKMASK(CRCXORT), 1
#define XOR26                            BANKMASK(CRCXORT), 2
#define XOR27                            BANKMASK(CRCXORT), 3
#define XOR28                            BANKMASK(CRCXORT), 4
#define XOR29                            BANKMASK(CRCXORT), 5
#define XOR3                             BANKMASK(CRCXORL), 3
#define XOR30                            BANKMASK(CRCXORT), 6
#define XOR31                            BANKMASK(CRCXORT), 7
#define XOR4                             BANKMASK(CRCXORL), 4
#define XOR5                             BANKMASK(CRCXORL), 5
#define XOR6                             BANKMASK(CRCXORL), 6
#define XOR7                             BANKMASK(CRCXORL), 7
#define XOR8                             BANKMASK(CRCXORH), 0
#define XOR9                             BANKMASK(CRCXORH), 1
#define ZERO                             BANKMASK(STATUS), 2
#define nA                               BANKMASK(SSP1STAT), 5
#define nA2                              BANKMASK(SSP1STAT), 5
#define nADDRESS                         BANKMASK(SSP1STAT), 5
#define nADDRESS1                        BANKMASK(SSP1STAT), 5
#define nBOR                             BANKMASK(PCON0), 0
#define nMEMV                            BANKMASK(PCON1), 1
#define nPD                              BANKMASK(STATUS), 3
#define nPOR                             BANKMASK(PCON0), 1
#define nRI                              BANKMASK(PCON0), 2
#define nRMCLR                           BANKMASK(PCON0), 3
#define nRWDT                            BANKMASK(PCON0), 4
#define nSYNC                            BANKMASK(T1CON), 2
#define nT1SYNC                          BANKMASK(T1CON), 2
#define nTO                              BANKMASK(STATUS), 4
#define nW                               BANKMASK(SSP1STAT), 2
#define nW2                              BANKMASK(SSP1STAT), 2
#define nWDTWV                           BANKMASK(PCON0), 5
#define nWRITE                           BANKMASK(SSP1STAT), 2
#define nWRITE1                          BANKMASK(SSP1STAT), 2

/*
 * Device Psects
 */

#ifdef _XC_INC_

// Memory Spaces
#define SPACE_CODE   0
#define SPACE_DATA   1
#define SPACE_EEPROM 3

psect udata_shr,class=COMMON,space=SPACE_DATA,noexec
psect udata,class=RAM,space=SPACE_DATA,noexec
psect udata_bank0,class=BANK0,space=SPACE_DATA,noexec
psect udata_bank1,class=BANK1,space=SPACE_DATA,noexec
psect udata_bank2,class=BANK2,space=SPACE_DATA,noexec
psect code,class=CODE,space=SPACE_CODE,delta=2
psect data,class=STRCODE,space=SPACE_CODE,delta=2,noexec

#endif // _XC_INC_

#endif // _PIC16F13113_INC_
