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


Byte addr_immediate  (CPU *cpu, Mem *mem, unsigned int *ticks);
Byte addr_zero_page  (CPU *cpu, Mem *mem, unsigned int *ticks);
Byte addr_zero_page_x(CPU *cpu, Mem *mem, unsigned int *ticks);
Byte addr_zero_page_y(CPU *cpu, Mem *mem, unsigned int *ticks);
 
Byte addr_absolute   (CPU *cpu, Mem *mem, unsigned int *ticks);
Byte addr_absolute_x (CPU *cpu, Mem *mem, unsigned int *ticks);
Byte addr_absolute_y (CPU *cpu, Mem *mem, unsigned int *ticks);
 
/* Write-mode variants*/
Word addr_zp_write   (CPU *cpu, Mem *mem, unsigned int *ticks);
Word addr_zp_x_write (CPU *cpu, Mem *mem, unsigned int *ticks);
Word addr_abs_write  (CPU *cpu, Mem *mem, unsigned int *ticks);
Word addr_abs_x_write(CPU *cpu, Mem *mem, unsigned int *ticks);
Word addr_abs_y_write(CPU *cpu, Mem *mem, unsigned int *ticks);