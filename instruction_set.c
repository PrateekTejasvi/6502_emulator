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
static void INS_STA (CPU *cpu,Mem *mem,unsigned int *ticks,Word addr){
    WriteByte(cpu,mem,ticks,addr,cpu->A); 
}

static void INS_STX(CPU *cpu , Mem *mem,unsigned int *ticks,Word addr){
    WriteByte(cpu,mem,ticks,addr,cpu->X);
}
static void INS_STY(CPU *cpu , Mem *mem , unsigned int *ticks,Word addr){
    WriteByte(cpu,mem,ticks,addr,cpu->Y);
}

static void INS_TAX(CPU *cpu){
    cpu->X = cpu->A;
    SetFlag(cpu, FLAG_Z, cpu->X == 0);
    SetFlag(cpu,FLAG_N,cpu->X & 0x80);

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



void Execute_INS_STA_ZP(CPU *cpu, Mem *mem, unsigned int *ticks, Word address){
    INS_STA(cpu,mem,ticks,address);

}


void Execute_INS_STA_ZP_X(CPU *cpu,Mem *mem,unsigned int *ticks,Word address){

    INS_STA(cpu,mem,ticks,address);
}


void Execute_INS_STA_ABS(CPU *cpu,Mem *mem,unsigned int *ticks,Word address){

    INS_STA(cpu,mem,ticks,address);
}


void Execute_INS_STA_ABS_X(CPU *cpu , Mem *mem,unsigned int *ticks,Word address){

    INS_STA(cpu,mem,ticks,address);
}


void Execute_INS_STA_ABS_Y(CPU *cpu,Mem *mem,unsigned int *ticks,Word address){

    INS_STA(cpu,mem,ticks,address);
}

void Execute_INS_STX_ZP(CPU *cpu,Mem *mem,unsigned int *ticks,Word address){
    INS_STX(cpu,mem,ticks,address);
}

void Execute_INS_STX_ZP_Y(CPU *cpu , Mem *mem,unsigned int *ticks,Word address){
    INS_STX(cpu,mem,ticks,address);
}
void Execute_INS_STX_ABS(CPU *cpu,Mem *mem,unsigned int *ticks,Word address){
    INS_STX(cpu,mem,ticks,address);
}

void Execute_INS_STY_ZP(CPU *cpu,Mem *mem,unsigned int *ticks,Word address){
    INS_STY(cpu,mem,ticks,address);
}
void Execute_INS_STY_ZP_X(CPU *cpu,Mem *mem,unsigned int *ticks,Word address){
    INS_STY(cpu,mem,ticks,address);
}
void Execute_INS_STY_ABS(CPU *cpu,Mem *mem,unsigned int *ticks,Word address){
    INS_STY(cpu,mem,ticks,address);
}

void Execute_INS_TAX(CPU *cpu){
    INS_TAX(cpu);
}
