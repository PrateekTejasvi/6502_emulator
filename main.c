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


    mem.Data[0x0010] = 0x11;   // ZP
    mem.Data[0x0025] = 0x22;   // ZP,X (0x20 + X)

    mem.Data[0x3000] = 0x33;   // ABS
    mem.Data[0x4005] = 0x44;   // ABS,X (0x4000 + X)
    mem.Data[0x5003] = 0x55;   // ABS,Y (0x5000 + Y)

    /* Program */

    /* LDA #$42 */
    mem.Data[0x8000] = INS_LDA_IM;
    mem.Data[0x8001] = 0x42;

    /* LDX #$05 */
    mem.Data[0x8002] = INS_LDX_IM;
    mem.Data[0x8003] = 0x05;

    /* LDY #$03 */
    mem.Data[0x8004] = INS_LDY_IM;
    mem.Data[0x8005] = 0x03;

    /* LDA $10 */
    mem.Data[0x8006] = INS_LDA_ZP;
    mem.Data[0x8007] = 0x10;

    /* LDA $20,X -> $25 */
    mem.Data[0x8008] = INS_LDA_ZP_X;
    mem.Data[0x8009] = 0x20;

    /* LDA $3000 */
    mem.Data[0x800A] = INS_LDA_ABS;
    mem.Data[0x800B] = 0x00;
    mem.Data[0x800C] = 0x30;

    /* LDA $4000,X -> $4005 */
    mem.Data[0x800D] = INS_LDA_ABS_X;
    mem.Data[0x800E] = 0x00;
    mem.Data[0x800F] = 0x40;

    /* LDA $5000,Y -> $5003 */
    mem.Data[0x8010] = INS_LDA_ABS_Y;
    mem.Data[0x8011] = 0x00;
    mem.Data[0x8012] = 0x50;

Reset(&cpu,&mem);

//Execute(&cpu,&mem,60);
execute_action(&cpu,&mem,60);
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
