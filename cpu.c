#include "cpu.h"
#include "instruction_set.h"
#include "memory.h"


void Execute(CPU *cpu,Mem *mem,unsigned int ticks){
    while(ticks > 0 ){
        Byte Ins = FetchByte(cpu,mem,&ticks);
        switch(Ins){
            case INS_LDA_IM:{
                Byte value = FetchByte(cpu,mem,&ticks);
                Execute_INS_LDA_IM(cpu,mem,&ticks,value);
                break;

            }
            case INS_LDA_ZP:{
                    Byte ZP_addr = FetchByte(cpu,mem,&ticks);
                    Byte ZP_value = ReadFromMem(cpu, mem, &ticks,ZP_addr);
                    Execute_INS_LDA_ZP(cpu,mem,&ticks,ZP_value);
                    break;
            }

    }
}
}

void SetFlag(CPU *cpu,Byte flag , int value){

    if(value){
        cpu->Status |= flag;
    }
    else{ 
        cpu->Status &= ~flag;
    }

}

void Reset(CPU *cpu, Mem *mem){

    cpu->PC = mem->Data[0xFFFC] | (mem->Data[0xFFFD] << 8);

    cpu->SP = 0xFD;

    cpu->A = 0; 
    cpu->Y = 0; 
    cpu->X = 0;

    SetFlag(cpu,FLAG_C,0);
    SetFlag(cpu,FLAG_B,0);
    SetFlag(cpu,FLAG_D,0);
    SetFlag(cpu,FLAG_I,0);
    SetFlag(cpu,FLAG_N,0);
    SetFlag(cpu,FLAG_Z,0);
    SetFlag(cpu,FLAG_V,0);
    SetFlag(cpu,FLAG_U,0);

}
