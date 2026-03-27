#pragma once

#include "cpu.h"
#include "memory.h"

#define INS_LDA_IM 0xA9
#define INS_LDA_ZP 0xA5
#define INS_LDA_ZP_X 0xB5 
#define INS_LDA_ABS 0xAD
#define INS_LDA_ABS_X 0xBD
#define INS_LDA_ABS_Y 0xB9

void Execute_INS_LDA_IM(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);
void Execute_INS_LDA_ZP(CPU *cpu , Mem *mem , unsigned int *ticks,Byte value);
void Execute_INS_LDA_ZP_X(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);
void Execute_INS_LDA_ABS(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);
void Execute_INS_LDA_ABS_X(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);
void Execute_INS_LDA_ABS_Y(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value);
