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


//LDA INSTRUCTINS
void Execute_INS_LDA_IM(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);
void Execute_INS_LDA_ZP(CPU *cpu , Mem *mem , unsigned int *ticks,Byte value);
void Execute_INS_LDA_ZP_X(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);
void Execute_INS_LDA_ABS(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);
void Execute_INS_LDA_ABS_X(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);
void Execute_INS_LDA_ABS_Y(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);
//LDX INSTRUCTIONS
void Execute_INS_LDX_IM(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);
void Execute_INS_LDX_ZP(CPU *cpu , Mem *mem , unsigned int *ticks,Byte value);
void Execute_INS_LDX_ZP_Y(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);
void Execute_INS_LDX_ABS(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);
void Execute_INS_LDX_ABS_Y(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);
//LDY INSTRUCTIONS
void Execute_INS_LDY_IM(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);
void Execute_INS_LDY_ZP(CPU *cpu , Mem *mem , unsigned int *ticks,Byte value);
void Execute_INS_LDY_ZP_X(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);
void Execute_INS_LDY_ABS(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);
void Execute_INS_LDY_ABS_X(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);


