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


//LDA INSTRUCTINS
void Execute_INS_LDA_IM(CPU*,Mem*,unsigned int*,Byte );
void Execute_INS_LDA_ZP(CPU* , Mem* ,unsigned int *,Byte );
void Execute_INS_LDA_ZP_X(CPU *,Mem *,unsigned int *,Byte );
void Execute_INS_LDA_ABS(CPU *,Mem *,unsigned int *,Byte );
void Execute_INS_LDA_ABS_X(CPU *,Mem *,unsigned int *,Byte );
void Execute_INS_LDA_ABS_Y(CPU *,Mem *,unsigned int *,Byte );
//LDX INSTRUCTIONS
void Execute_INS_LDX_IM(CPU *,Mem *,unsigned int *,Byte );
void Execute_INS_LDX_ZP(CPU * , Mem * , unsigned int *,Byte );
void Execute_INS_LDX_ZP_Y(CPU *,Mem *,unsigned int *,Byte );
void Execute_INS_LDX_ABS(CPU *,Mem *,unsigned int *,Byte );
void Execute_INS_LDX_ABS_Y(CPU *,Mem *,unsigned int *,Byte );
//LDY INSTRUCTIONS
void Execute_INS_LDY_IM(CPU *,Mem *,unsigned int *,Byte );
void Execute_INS_LDY_ZP(CPU * , Mem * , unsigned int *,Byte );
void Execute_INS_LDY_ZP_X(CPU *,Mem *,unsigned int *,Byte );
void Execute_INS_LDY_ABS(CPU *,Mem *,unsigned int *,Byte );
void Execute_INS_LDY_ABS_X(CPU *,Mem *,unsigned int *,Byte );
//STA INSTRUCTIONS
void Execute_INS_STA_ZP(CPU *,Mem *,unsigned int *,Word);
void Execute_INS_STA_ZP_X(CPU *,Mem *,unsigned int *,Word);
void Execute_INS_STA_ABS(CPU *,Mem *,unsigned int *,Word);
void Execute_INS_STA_ABS_X(CPU *,Mem *,unsigned int *,Word);
void Execute_INS_STA_ABS_Y(CPU *,Mem *,unsigned int *,Word);


