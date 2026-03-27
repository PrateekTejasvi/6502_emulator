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


mem.Data[0x8004] = INS_LDA_ABS;
mem.Data[0x8005] = 0x00;
mem.Data[0x8006] = 0x20;
mem.Data[0x2000] = 0x99;

mem.Data[0x8007] = INS_LDA_ZP_X;
mem.Data[0x8008] = 0x10;
cpu.X = 1;
mem.Data[0x0011] = 0x77;

mem.Data[0x8009] = INS_LDA_ABS_X;
mem.Data[0x800A] = 0x00;
mem.Data[0x800B] = 0x30;
mem.Data[0x3001] = 0x88;

mem.Data[0x800C] = INS_LDA_ABS_Y;
mem.Data[0x800D] = 0x00;
mem.Data[0x800E] = 0x40;

cpu.Y = 2;

mem.Data[0x4002] = 0xAB;


Reset(&cpu,&mem);

Execute(&cpu,&mem,20);
DumpCPU(&cpu);
}
