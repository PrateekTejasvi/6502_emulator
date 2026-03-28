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

Byte ReadFromMem(CPU*, Mem*,unsigned int*,Word);

Byte FetchByte(CPU* , Mem*, unsigned int*);

Word FetchWord(CPU*, Mem*,unsigned int*);

void WriteByte(CPU*,Mem*,unsigned int*,Word,Byte);
