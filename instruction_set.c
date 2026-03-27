#include"instruction_set.h"


static void INS_LDA (CPU *cpu, Byte value){
    cpu->A = value;
    SetFlag(cpu,FLAG_Z,cpu->A == 0);
    SetFlag(cpu,FLAG_N,cpu->A & 0b10000000);

}

void Execute_INS_LDA_ZP(CPU *cpu, Mem *mem, unsigned int *ticks,Byte value){
    INS_LDA(cpu,value);
}

void Execute_INS_LDA_IM(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value){
    INS_LDA(cpu,value);

}


void Execute_INS_LDA_ABS(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value){
    INS_LDA(cpu,value);

}

void Execute_INS_LDA_ZP_X(CPU *cpu, Mem *mem, unsigned int *ticks, Byte value){
    INS_LDA(cpu,value);

}
void Execute_INS_LDA_ABS_X(CPU *cpu, Mem *mem, unsigned int *ticks, Byte value){
    INS_LDA(cpu,value);

}
void Execute_INS_LDA_ABS_Y(CPU *cpu, Mem *mem, unsigned int *ticks, Byte value){
    INS_LDA(cpu,value);

}

