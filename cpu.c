#include "cpu.h"
#include "instruction_set.h"
#include "memory.h"
//TODO:major change to tackle is to ensure that ADDRESS calculation also takes a tick or clock cycle
//right now it just assumes only instructions take a clock cycle

void Execute(CPU *cpu,Mem *mem,unsigned int ticks){
    while(ticks > 0){
        if(ticks == 0)break;
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

            case INS_LDA_ABS:{
                    Word ABS_address = FetchWord(cpu,mem,&ticks);
                    Word ABS_Value = ReadFromMem(cpu,mem,&ticks,ABS_address);
                    Execute_INS_LDA_ABS(cpu,mem,&ticks,ABS_Value);
                break;
            }

            case INS_LDA_ZP_X:{
                Byte addr = FetchByte(cpu,mem,&ticks);
                addr = (addr + cpu->X) & 0xFF;
                Byte value = ReadFromMem(cpu,mem,&ticks,addr);
                Execute_INS_LDA_ZP_X(cpu,mem,&ticks,value);
                break;
            }
//TODO:LDA_ABS_X/Y can take an extra clock cylce 4+1 depending on the wrapping
            case INS_LDA_ABS_X:{
                Word base = FetchWord(cpu,mem,&ticks);
                Word addr = base + cpu->X;
                Byte value = ReadFromMem(cpu,mem,&ticks,addr);
                Execute_INS_LDA_ABS_X(cpu,mem,&ticks,value);
                break;
            }

            case INS_LDA_ABS_Y:{
                Word base = FetchWord(cpu,mem,&ticks);
                Word addr = base + cpu->Y;
                Byte value = ReadFromMem(cpu,mem,&ticks,addr);
                Execute_INS_LDA_ABS_Y(cpu,mem,&ticks,value);
                break;
            }
//INSTRUCTION SET FOR LDX

            case INS_LDX_IM:{
                Byte value = FetchByte(cpu,mem,&ticks);
                Execute_INS_LDX_IM(cpu,mem,&ticks,value);
                break;
            }
            
            case INS_LDX_ZP:{
                Byte ZP_Addr = FetchByte(cpu,mem,&ticks);
                Byte ZP_Value = ReadFromMem(cpu,mem,&ticks,ZP_Addr);
                Execute_INS_LDX_ZP(cpu,mem,&ticks,ZP_Value);
                break;
            }
            case INS_LDX_ABS:{
                 Word Addr = FetchWord(cpu,mem,&ticks);
                 Byte Value = ReadFromMem(cpu,mem,&ticks,Addr);
                 Execute_INS_LDX_ABS(cpu,mem,&ticks,Value);
                 break;
            }

            case INS_LDX_ZP_Y:{
                Byte addr = FetchByte(cpu,mem,&ticks);
                Byte ZP_addr = (addr + cpu->Y) & 0xFF;
                Byte value = ReadFromMem(cpu,mem,&ticks,ZP_addr);
                Execute_INS_LDX_ZP_Y(cpu,mem,&ticks,value);
                break;
            }

            case INS_LDX_ABS_Y:{
                Word addr = FetchWord(cpu,mem,&ticks);
                Word ABS_addr = (addr+cpu->Y);
                Byte value = ReadFromMem(cpu,mem,&ticks,ABS_addr);
                Execute_INS_LDX_ABS_Y(cpu,mem,&ticks,value);
                break;
            }

//INSTRUCTION SET FOR LDY
            case INS_LDY_IM:{
                Byte Value = FetchByte(cpu,mem,&ticks);
                Execute_INS_LDY_IM(cpu,mem,&ticks,Value);
                break;
            }
            case INS_LDY_ZP:{
                Byte ZP_Addr = FetchByte(cpu,mem,&ticks);
                Byte ZP_Value = ReadFromMem(cpu,mem,&ticks,ZP_Addr);
                Execute_INS_LDY_ZP(cpu,mem,&ticks,ZP_Value);
                break;
            }
            
            case INS_LDY_ZP_X:{
                Byte addr = FetchByte(cpu,mem,&ticks);
                Byte ZP_addr = (addr + cpu->X) & 0xFF;
                Byte value = ReadFromMem(cpu,mem,&ticks,ZP_addr);
                Execute_INS_LDY_ZP_X(cpu,mem,&ticks,value);
                break;
            }

            case INS_LDY_ABS:{
                 Word Addr = FetchWord(cpu,mem,&ticks);
                 Byte Value = ReadFromMem(cpu,mem,&ticks,Addr);
                 Execute_INS_LDY_ABS(cpu,mem,&ticks,Value);
                break;
            }
            case INS_LDY_ABS_X:{
                Word addr = FetchWord(cpu,mem,&ticks);
                Word ABS_addr = (addr+cpu->X);
                Byte value = ReadFromMem(cpu,mem,&ticks,ABS_addr);
                Execute_INS_LDY_ABS_X(cpu,mem,&ticks,value);
                break;
            }
//INSTRUCTION SET FOR STA
            case INS_STA_ZP:{
                Byte address = FetchByte(cpu,mem,&ticks);
                Execute_INS_STA_ZP(cpu,mem,&ticks,address);
                break;

            }
            case INS_STA_ABS:{
                Word Addr = FetchWord(cpu,mem,&ticks);
                Execute_INS_STA_ABS(cpu,mem,&ticks,Addr);
                break;
            }
            case INS_STA_ZP_X:{
                Byte base = FetchByte(cpu,mem,&ticks);
                Byte addr = (base + cpu->X) & 0xFF;
                ticks--;
                Execute_INS_STA_ZP_X(cpu,mem,&ticks,addr);
                break;
            }

            case INS_STA_ABS_X:{
                Word base = FetchWord(cpu,mem,&ticks);
                Word addr = (base + cpu -> X) ;
                ticks--;
                Execute_INS_STA_ABS_X(cpu,mem,&ticks,addr);
                break;
            }
            
            case INS_STA_ABS_Y:{
                Word base = FetchWord(cpu,mem,&ticks);
                Word addr = (base+ cpu -> Y);
                ticks--;
                Execute_INS_STA_ABS_Y(cpu,mem,&ticks,addr);
                break;
            }
//INSTRUCTION SET FOR STX
            case INS_STX_ZP:{
                Byte addr = FetchByte(cpu,mem,&ticks);
                Execute_INS_STX_ZP(cpu,mem,&ticks,addr);
                break;
            }
            case INS_STX_ZP_Y:{
                Byte addr = FetchByte(cpu,mem,&ticks);
                addr = (addr +  cpu->Y) & 0xFF;
                Execute_INS_STX_ZP_Y(cpu,mem,&ticks,addr);
                break;
            }
            case INS_STX_ABS:{
                Word addr = FetchWord(cpu,mem,&ticks);
                Execute_INS_STX_ABS(cpu,mem,&ticks,addr);
                break;
            }
//INSTRUCTION SET FOR STY
            case INS_STY_ZP:{
                Byte addr = FetchByte(cpu,mem,&ticks);
                Execute_INS_STY_ZP(cpu,mem,&ticks,addr);
                break;
            }
            case INS_STY_ZP_X:{
                Byte addr = FetchByte(cpu,mem,&ticks);
                addr = (addr +  cpu->X) & 0xFF;
                Execute_INS_STY_ZP_X(cpu,mem,&ticks,addr);
                break;
            }
            case INS_STY_ABS:{
                Word addr = FetchWord(cpu,mem,&ticks);
                Execute_INS_STY_ABS(cpu,mem,&ticks,addr);
                break;
            }
//INSTRUCTION SET FOR TAX 
            case INS_TAX_IMP:{
                Execute_INS_TAX(cpu);
                ticks--;//aftering executing minus one more tick
                break;
            }
            case INS_TXA_IMP:{
                Execute_INS_TXA(cpu);
                ticks--;
                break;
                                
            }
             case INS_TAY_IMP:{
                Execute_INS_TAY(cpu);
                ticks--;
                break;
                                
            } case INS_TYA_IMP:{
                Execute_INS_TYA(cpu);
                ticks--;
                break;
                                
            } case INS_TSX_IMP:{
                Execute_INS_TSX(cpu);
                ticks--;
                break;
                                
            } case INS_TXS_IMP:{
                Execute_INS_TXS(cpu);
                ticks--;
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
