#include "cpu.h"
#include "memory.h"

void SetFlag(CPU *cpu,Byte flag , int value){

    if(value){
        cpu->Status |= flag;
    }
    else{ 
        cpu->Status &= ~flag;
    }

}

void Reset(CPU *cpu, Mem *mem){

    cpu->PC = mem->Data[0xFFFC] | (mem->Data[0xFFFD] << 8);

    cpu->SP = 0xFD;

    cpu->A = 0; 
    cpu->Y = 0; 
    cpu->X = 0;

    SetFlag(cpu,FLAG_C,0);
    SetFlag(cpu,FLAG_B,0);
    SetFlag(cpu,FLAG_D,0);
    SetFlag(cpu,FLAG_I,0);
    SetFlag(cpu,FLAG_N,0);
    SetFlag(cpu,FLAG_Z,0);
    SetFlag(cpu,FLAG_V,0);
    SetFlag(cpu,FLAG_U,0);

}
