#include<stdio.h> 
#include<stdlib.h>

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

typedef struct CPU { 
    Byte PC; //program counter
    Word SP;//stack pointer

    Byte A : 8; 
    Byte Y : 8; 
    Byte X : 8;

//Status flags - 8 bit 8 flags

    Byte Status;


}CPU; 

typedef struct Memory{ 
    unsigned int MAX_MEM; 
    Byte Data[1024 * 64];

}Mem;


void SetFlag(CPU *cpu,Byte flag , int value){
    if(value){
        cpu -> Status |= flag;
    }
    else { 
        cpu -> Status &= ~flag;
    }
}

void Reset(CPU *cpu, Mem *mem){
    cpu -> PC = mem->Data[0xFFFC] | (mem->Data[0xFFFD] << 8);
    cpu -> SP = 0xFD;
    cpu -> A = 0; 
    cpu -> Y = 0; 
    cpu -> X = 0;
    SetFlag(cpu,FLAG_C,0);
    SetFlag(cpu,FLAG_B,0);
    SetFlag(cpu,FLAG_D,0);
    SetFlag(cpu,FLAG_I,0);
    SetFlag(cpu,FLAG_N,0);
    SetFlag(cpu,FLAG_Z,0);
    SetFlag(cpu,FLAG_V,0);
    SetFlag(cpu,FLAG_U,0);

}


void Init(Mem *mem){
    mem ->MAX_MEM = 1024 * 64;
    for(int i= 0 ; i < 1024 * 64 ; i++ ){
        mem->Data[i] = 0;
    }

}




int main(){
    CPU cpu; 
    return 0;
}
