#include<stdio.h> 
#include<stdlib.h> 
#include <sys/types.h>

#define INS_LDA_IM 0xA9 
#define INS_LDA_ZP 0xA5
typedef unsigned char Byte; //8 bit
typedef unsigned short WORD; //16 bit 

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
//Creating memory
struct MEM{
    unsigned int MAX_MEM;
    Byte Data[1024*64];
};

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


void Initialize(struct MEM *mem){
    mem->MAX_MEM = 1024 * 64;
    for(int i = 0;i<mem->MAX_MEM;i++){
        mem->Data[i] = 0;
    }
}

Byte Fetch(struct CPU *cpu,struct MEM *mem,unsigned int *ticks){
    Byte data = mem->Data[cpu->PC]; //not a good method to fetch the data cause we would be directly poking into mem
    cpu->PC = (cpu->PC + 1) & 0xFFFF;//do not overlow the PC ; 
    (*ticks)--;
    return data;

}
Byte ReadFromMem(struct CPU *cpu,struct MEM *mem,unsigned int *ticks,WORD addr){
    Byte data;
    data = mem->Data[addr];
    (*ticks)--;
    return data;

}

void setZeroFlag(struct CPU *cpu){
    cpu->Zero = (cpu->A == 0);
    cpu->Negative = (cpu->A & 0b10000000) > 0; 
}


void Execute(struct CPU *cpu, struct MEM *mem, unsigned int *ticks){
    //LDA
    Byte ins;
    Byte value;
    ins = Fetch(cpu,mem,ticks);
    switch(ins){
        case INS_LDA_IM: 
            value = Fetch(cpu,mem,ticks);
            cpu->A = value; 
            setZeroFlag(cpu);
            break;
        
        case INS_LDA_ZP: 
            value = Fetch(cpu,mem,ticks); // zero byte address 
            cpu->A = ReadFromMem(cpu,mem,ticks,value);
            setZeroFlag(cpu);
            break;

        default : 
            printf("Instruction Not handled %d",ins);
    }
    printf("%#x",cpu->A);
    
} //TO DO: fix the implemntation of these two functions execute and Fetch


int main(){
    struct CPU cpu;
    struct MEM mem; 
    Reset(&cpu,&mem);
    Initialize(&mem);
    mem.Data[0xFFFC] = 0xA5;
    mem.Data[0xFFFD] = 0xA5;
    mem.Data[0x00A5] = 0x42;
    unsigned int ticks = 3 ;
    Execute(&cpu,&mem,&ticks);

    return 0; 
}
