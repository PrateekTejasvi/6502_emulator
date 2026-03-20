#pragma once

typedef unsigned char Byte;
typedef unsigned short Word;


struct CPU;
typedef struct CPU CPU;

typedef struct Memory{ 

    unsigned int MAX_MEM; 
    Byte Data[1024 * 64];

}Mem;

void Init(Mem *mem);

Byte ReadFromMem(CPU *cpu , Mem *mem,unsigned int *ticks,Word addr);

Byte FetchByte(CPU *cpu , Mem *mem, unsigned int *ticks);

Word FetchWord(CPU *cpu , Mem *mem,unsigned int *ticks);
