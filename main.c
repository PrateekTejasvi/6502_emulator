#include<stdio.h> 
#include<stdlib.h> 
#include <sys/types.h>
typedef unsigned char Byte;
typedef unsigned short WORD; 

struct CPU{ 
    WORD PC : 16; //program counter  
    WORD SP : 16;  //Stack pointer

    Byte A : 8; //registers A , X and Y ; 
    Byte X : 8; 
    Byte Y : 8;

    // Status flags
    Byte Carry : 1; //Carry flag 
    Byte Zero : 1; //Zero flag 
    Byte OF  : 1; //Overflow flag 
    Byte Int : 1; //interrupt register 
    Byte D : 1;  //Decimal
    Byte Break : 1;//Break; 
    Byte Negative : 1;//Negative  
};

struct MEM{
    unsigned int MAX_MEM;
    Byte Data[1024*64];
};

void Initialize(struct MEM *mem){
    mem->MAX_MEM = 1024 * 64;
    for(int i = 0;i<mem->MAX_MEM;i++){
        mem->Data[i] = 0;
    }
}

Byte Fetch(struct CPU *cpu,struct MEM *mem,unsigned int ticks){
    Byte data = mem->Data[cpu->PC]; //not a good method to fetch the data cause we would be directly poking into mem
    cpu->PC++; 
    ticks--;
    return data;


}

void Execute(struct CPU *cpu, struct MEM *mem, unsigned int ticks){
    //LDA
    Byte ins;
    if(cpu->A == 0 ) cpu->Zero =1; 
        ins = Fetch(cpu,mem,ticks);
    printf("%#x",ins);
    
}

void Reset(struct CPU *cpu,struct MEM *mem){
    cpu->PC = 0xFFFC ; 
    cpu->D = 0; 
    cpu->SP = 0x0100; 
    cpu->A = 0; 
    cpu->X = 0; 
    cpu->Y = 0; 
    cpu->Carry = 0; 
    cpu->Zero =0; 
    cpu->OF = 0; 
    cpu->Int  = 0; 
    cpu->D = 0; 
    cpu->Break = 0; 
    cpu->Negative= 0;
}


int main(){
    struct CPU cpu;
    struct MEM mem; 
    Reset(&cpu,&mem);
    printf("%d",cpu.PC);
    Initialize(&mem);
    mem.Data[0xFFFC] = 0xA9;
    Execute(&cpu,&mem,2);

    return 0; 
}
