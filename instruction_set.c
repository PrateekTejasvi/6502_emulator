#include"instruction_set.h"


static void INS_LDA (CPU *cpu, Byte value){
    cpu->A = value;
    SetFlag(cpu,FLAG_Z,cpu->A == 0);
    SetFlag(cpu,FLAG_N,cpu->A & 0b10000000);

}

static void INS_LDX (CPU *cpu, Byte value){
    cpu->X = value;
    SetFlag(cpu,FLAG_Z,cpu->X == 0);
    SetFlag(cpu,FLAG_N,cpu->X & 0b10000000);
}

static void INS_LDY (CPU *cpu,Byte value){
    cpu->Y = value;
    SetFlag(cpu,FLAG_Z,cpu->Y == 0);
    SetFlag(cpu,FLAG_N,cpu->Y & 0b10000000);
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



void Execute_INS_LDX_IM(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value){
    INS_LDX(cpu,value);

}
void Execute_INS_LDX_ZP(CPU *cpu , Mem *mem , unsigned int *ticks,Byte value){
    INS_LDX(cpu,value);

}
void Execute_INS_LDX_ZP_Y(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value){
    INS_LDX(cpu,value);

}
void Execute_INS_LDX_ABS(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value){
    INS_LDX(cpu,value);

}
void Execute_INS_LDX_ABS_Y(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value){
    INS_LDX(cpu,value);
}



void Execute_INS_LDY_IM(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value){
    INS_LDY(cpu,value);
}
void Execute_INS_LDY_ZP(CPU *cpu , Mem *mem , unsigned int *ticks,Byte value){
        INS_LDY(cpu,value);
}
void Execute_INS_LDY_ZP_X(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value){
        INS_LDY(cpu,value);
}
void Execute_INS_LDY_ABS(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value){
    INS_LDY(cpu,value);
}
void Execute_INS_LDY_ABS_X(CPU *cpu,Mem *mem,unsigned int *ticks,Byte value){
    INS_LDY(cpu,value);
}
