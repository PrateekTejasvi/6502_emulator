#include<stdio.h>
#include<stdlib.h>
#include "include/cpu.h"
#include "memory.h"
#include"instruction_set.h"

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


/* RESET VECTOR */

mem.Data[0xFFFC] = 0x00;
mem.Data[0xFFFD] = 0x80;

mem.Data[0x8000]=INS_LDA_IM;
mem.Data[0x8001]=0x42;

mem.Data[0x8002]=INS_STA_ZP;
mem.Data[0x8003]=0x34;

Reset(&cpu,&mem);

//Execute(&cpu,&mem,60);
execute_action(&cpu,&mem,60);
printf("A:%02X\n",cpu.A);
printf("X:%02X\n",cpu.X);
printf("Y:%02X\n",cpu.Y);

printf("mem[0034]:%02X\n",mem.Data[0x0034]);
printf("mem[0025]:%02X\n",mem.Data[0x0025]);
printf("mem[0023]:%02X\n",mem.Data[0x0023]);

printf("mem[3000]:%02X\n",mem.Data[0x3000]);
printf("mem[4005]:%02X\n",mem.Data[0x4005]);
printf("mem[5003]:%02X\n",mem.Data[0x5003]);
}
