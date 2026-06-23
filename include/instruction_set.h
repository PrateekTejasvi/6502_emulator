#pragma once
#include "cpu.h"
#include "memory.h"
//LDA INSTRUCTIONS
#define INS_LDA_IM 0xA9
#define INS_LDA_ZP 0xA5
#define INS_LDA_ZP_X 0xB5
#define INS_LDA_ABS 0xAD
#define INS_LDA_ABS_X 0xBD
#define INS_LDA_ABS_Y 0xB9
//LDX INSTRUCTIONS
#define INS_LDX_IM 0xA2
#define INS_LDX_ZP 0xA6
#define INS_LDX_ZP_Y 0xB6
#define INS_LDX_ABS 0xAE
#define INS_LDX_ABS_Y 0xBE
//LDY INSTRUCTIONS
#define INS_LDY_IM 0xA0
#define INS_LDY_ZP 0xA4
#define INS_LDY_ZP_X 0xB4
#define INS_LDY_ABS 0xAC
#define INS_LDY_ABS_X 0xBC
//STA INSTRUCTIONS
#define INS_STA_ZP    0x85
#define INS_STA_ZP_X  0x95
#define INS_STA_ABS   0x8D
#define INS_STA_ABS_X 0x9D
#define INS_STA_ABS_Y 0x99
//STX INSTRUCTIONS
#define INS_STX_ZP 0x86
#define INS_STX_ZP_Y 0x96
#define INS_STX_ABS 0x8E
//STY INSTRUCTIONS
#define INS_STY_ZP 0x84
#define INS_STY_ZP_X 0x94
#define INS_STY_ABS 0x8C
//TAX INSTRUCTION
#define INS_TAX_IMP 0xAA
//TAY INSTRUCTION
#define INS_TAY_IMP 0xA8
//TSX INSTRUCTION
#define INS_TSX_IMP 0xBA
//TXA INSTRUCTION
#define INS_TXA_IMP 0x8A
//TXS INSTRUCTION
#define INS_TXS_IMP 0x9A
//TYA INSTRUCTION
#define INS_TYA_IMP 0x98
//ADC- add with carry instructions
#define INS_ADC_IM 0x69
#define INS_ADC_ZP 0x65
#define INS_ADC_ZP_X 0x75
#define INS_ADC_ABS 0x6D
#define INS_ADC_ABS_X 0x7D
#define INS_ADC_ABS_Y 0x79
#define INS_ADC_IND_X 0x61
#define INS_ADC_IND_Y 0x71
//AND INSTRUCTIONS
#define INS_AND_IM 0x29
#define INS_AND_ZP 0x25
#define INS_AND_ZP_X 0x35
#define INS_AND_ABS 0x2D
#define INS_AND_ABS_X 0x3D
#define INS_AND_ABS_Y 0x39
#define INS_AND_IND_X 0x21
#define INS_AND_IND_Y 0x31
//ASL INSTRUCTIONS
#define INS_ASL_ACCM 0x0A
#define INS_ASL_ZP 0x06
#define INS_ASL_ZP_X 0x16
#define INS_ASL_ABS 0x0E
#define INS_ASL_ABS_X 0x1E

//merge LDA instructions
void Execute_INS_LDA(CPU*,Byte);
//LDX INSTRUCTIONS
void Execute_INS_LDX(CPU*,Byte);
//LDY INSTRUCTIONS
void Execute_INS_LDY(CPU*,Byte);
//STA INSTRUCTIONS
void Execute_INS_STA(CPU*,Mem *,unsigned int*,Word);
//STX INSTRUCTIONS
void Execute_INS_STX(CPU*,Mem*,unsigned int*,Word);
//STY INSTRUCTIONS
void Execute_INS_STY(CPU*,Mem *,unsigned int*,Word);
//TRANSFER INSTRUCTIONS
void Execute_INS_TAX(CPU*);
void Execute_INS_TAY(CPU*);
void Execute_INS_TSX(CPU*);
void Execute_INS_TXA(CPU*);
void Execute_INS_TXS(CPU*);
void Execute_INS_TYA(CPU*);
//ADC INSTRUCTIONS
