#include "cpu.h"
#include "memory.h"

void Init(Mem *mem){

    mem->MAX_MEM = 1024 * 64;

    for(int i=0;i<1024*64;i++){
        mem->Data[i]=0;
    }

}

Byte ReadFromMem(CPU *cpu , Mem *mem,unsigned int *ticks,Word addr){

    Byte data = mem->Data[addr];

    (*ticks)--;

    return data;
}

Byte FetchByte(CPU *cpu , Mem *mem, unsigned int *ticks){

    Word address = cpu->PC;

    Byte data = mem->Data[address];

    cpu->PC = (cpu->PC + 1) & 0xFFFF;

    (*ticks)--;

    return data;
}

Word FetchWord(CPU *cpu , Mem *mem,unsigned int *ticks){

    Byte lowByte = FetchByte(cpu , mem , ticks);

    Byte highByte = FetchByte(cpu , mem , ticks);

    Word value = lowByte | (highByte << 8);

    return value;
}

void WriteByte(CPU *cpu,Mem *mem,unsigned int *ticks,Word addr,Byte value){
    mem -> Data[addr] = value;
    (*ticks)--;
}


