#pragma once
#include "memory.h"

typedef unsigned char Byte;
typedef unsigned short Word;

#define FLAG_C 0b00000001
#define FLAG_Z 0b00000010
#define FLAG_I 0b00000100
#define FLAG_D 0b00001000
#define FLAG_B 0b00010000
#define FLAG_U 0b00100000
#define FLAG_V 0b01000000
#define FLAG_N 0b10000000

typedef void (*InstructionHandler)(CPU *cpu,Mem *mem,unsigned int *ticks);

typedef struct CPU { 

    Byte SP;
    Word PC;

    Byte A; 
    Byte Y; 
    Byte X;

    Byte Status;
    InstructionHandler handlers[256];
    

}CPU; 

void SetFlag(CPU *cpu,Byte flag , int value);
void Execute(CPU *cpu , Mem *mem , unsigned int ticks);
void Reset(CPU *cpu, Mem *mem);

void register_instructions(CPU *cpu,Mem* mem, InstructionHandler handler);
void register_all_instructions(CPU *cpu);
