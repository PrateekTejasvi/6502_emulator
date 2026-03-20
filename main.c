#include<stdio.h> 
#include<stdlib.h>

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

    CPU cpu; 
    Mem mem;

    Init(&mem);

    mem.Data[0xFFFC] = 0x00; 
    mem.Data[0xFFFD] = 0x80;

    Reset(&cpu,&mem);

    DumpCPU(&cpu);

    return 0;
}
