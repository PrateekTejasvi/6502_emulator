#include<stdio.h> 
#include<stdlib.h>
#include"instruction_set.h"
#include "cpu.h"
#include "memory.h"

void DumpCPU(CPU *cpu)
{
    printf("A:%02X X:%02X Y:%02X PC:%04X SP:%02X STATUS:%02X\n",
           cpu->A,
           cpu->X,
           cpu->Y,
           cpu->PC,
           cpu->SP,
           cpu->Status);
}

int main(){

Mem mem;
CPU cpu;

Init(&mem);

mem.Data[0xFFFC] = 0x00;
mem.Data[0xFFFD] = 0x80;

mem.Data[0x8000] = INS_LDA_IM;
mem.Data[0x8001] = 0x42;

mem.Data[0x8002] = INS_LDA_ZP;
mem.Data[0x8003] = 0x10;
mem.Data[0x0010] = 0x55;


Reset(&cpu,&mem);

Execute(&cpu,&mem,20);
DumpCPU(&cpu);
}
