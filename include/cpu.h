#pragma once
#include "memory.h"
#include<stdbool.h>

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

typedef enum AddressMode{
    Immediate,
    ZeroPage,
    ZeroPage_X,
    ZeroPage_Y,
    Absolute,
    Absolute_X,
    Absolute_Y,
    Implied, // for Transfer instructions

}AddressMode;

typedef enum Operation{
    LDA,
    LDX,
    LDY,
}Operation;

typedef struct Instruction{
    const char *Mnemonic;
    Operation Operation;
    AddressMode AddressMode;
    unsigned int ticks;
    Byte PageCrossPenalty;
}Instruction;

typedef struct AddressResult{
    Word Address;
    Byte Value;
    bool PageCrossed;

}AddressResult;



typedef struct CPU {

    Byte SP;
    Word PC;

    Byte A;
    Byte Y;
    Byte X;

    Byte Status;


}CPU;

void SetFlag(CPU *cpu,Byte flag , int value);
void Execute(CPU *cpu , Mem *mem , unsigned int ticks);
void Reset(CPU *cpu, Mem *mem);


extern Instruction InstructionTable[256];
void InitInstructionTable(void);
