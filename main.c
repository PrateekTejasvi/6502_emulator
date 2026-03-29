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


/* RESET VECTOR */

mem.Data[0xFFFC] = 0x00;
mem.Data[0xFFFD] = 0x80;


/* PROGRAM */

mem.Data[0x8000] = INS_LDA_IM;
mem.Data[0x8001] = 0x42;

mem.Data[0x8002] = INS_LDX_IM;
mem.Data[0x8003] = 0x05;

mem.Data[0x8004] = INS_LDY_IM;
mem.Data[0x8005] = 0x03;


/* STA ZP */

mem.Data[0x8006] = INS_STA_ZP;
mem.Data[0x8007] = 0x10;


/* STA ZP,X */

mem.Data[0x8008] = INS_STA_ZP_X;
mem.Data[0x8009] = 0x20;


/* STA ZP,Y (if implemented skip otherwise) */


/* STA ABS */

mem.Data[0x800A] = INS_STA_ABS;
mem.Data[0x800B] = 0x00;
mem.Data[0x800C] = 0x30;


/* STA ABS,X */

mem.Data[0x800D] = INS_STA_ABS_X;
mem.Data[0x800E] = 0x00;
mem.Data[0x800F] = 0x40;


/* STA ABS,Y */

mem.Data[0x8010] = INS_STA_ABS_Y;
mem.Data[0x8011] = 0x00;
mem.Data[0x8012] = 0x50;


/* LOAD BACK TEST */

mem.Data[0x8013] = INS_LDA_ZP;
mem.Data[0x8014] = 0x10;

mem.Data[0x8015] = INS_LDX_ZP;
mem.Data[0x8016] = 0x25;

mem.Data[0x8017] = INS_LDY_ZP;
mem.Data[0x8018] = 0x23;


/* ABS LOAD */

mem.Data[0x8019] = INS_LDA_ABS;
mem.Data[0x801A] = 0x00;
mem.Data[0x801B] = 0x30;

mem.Data[0x801C] = INS_LDX_ABS;
mem.Data[0x801D] = 0x05;
mem.Data[0x801E] = 0x40;

mem.Data[0x801F] = INS_LDY_ABS;
mem.Data[0x8020] = 0x03;
mem.Data[0x8021] = 0x50;



Reset(&cpu,&mem);

Execute(&cpu,&mem,60);
printf("A:%02X\n",cpu.A);
printf("X:%02X\n",cpu.X);
printf("Y:%02X\n",cpu.Y);

printf("mem[0010]:%02X\n",mem.Data[0x0010]);
printf("mem[0025]:%02X\n",mem.Data[0x0025]);
printf("mem[0023]:%02X\n",mem.Data[0x0023]);

printf("mem[3000]:%02X\n",mem.Data[0x3000]);
printf("mem[4005]:%02X\n",mem.Data[0x4005]);
printf("mem[5003]:%02X\n",mem.Data[0x5003]);
}
