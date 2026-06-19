#include "cpu.h"
#include "instruction_set.h"
#include "memory.h"
#include <complex.h>
#include <stdint.h>

void Execute(CPU *cpu,Mem *mem,unsigned int ticks){

    while(ticks > 0){
        if(ticks == 0)break;
        Byte Ins = FetchByte(cpu,mem,&ticks);
        switch(Ins){
            case INS_LDA_IM:{
                Byte value = addr_immediate(cpu,mem, &ticks);
                Execute_INS_LDA(cpu,value);
                break;
            }
            case INS_LDA_ZP:{
                    Byte value  = addr_zero_page(cpu, mem,&ticks);
                    Execute_INS_LDA(cpu,value);
                    break;
            }
            case INS_LDA_ABS:{
                    Byte value = addr_absolute(cpu, mem, &ticks);
                    Execute_INS_LDA(cpu,value);
                break;
            }

            case INS_LDA_ZP_X:{
                Byte value = addr_zero_page_x(cpu, mem, &ticks);
                Execute_INS_LDA(cpu,value);
                break;
            }
//TODO:LDA_ABS_X/Y can take an extra clock cylce 4+1 depending on the wrapping
            case INS_LDA_ABS_X:{
                Byte value = addr_absolute_x(cpu, mem, &ticks);
                Execute_INS_LDA(cpu,value);
                break;
            }

            case INS_LDA_ABS_Y:{
                Byte value = addr_absolute_y(cpu,mem,&ticks);
                Execute_INS_LDA(cpu,value);
                break;
            }
//INSTRUCTION SET FOR LDX

            case INS_LDX_IM:{
                Byte value = addr_immediate(cpu,mem,&ticks);
                Execute_INS_LDX(cpu,value);
                break;
            }

            case INS_LDX_ZP:{
                Byte ZP_Value = addr_zero_page(cpu,mem,&ticks);
                Execute_INS_LDX(cpu,ZP_Value);
                break;
            }
            case INS_LDX_ABS:{
                 Byte Value = addr_absolute(cpu, mem, &ticks);
                 Execute_INS_LDX(cpu,Value);
                 break;
            }

            case INS_LDX_ZP_Y:{
                Byte value = addr_zero_page_y(cpu, mem, &ticks);
                Execute_INS_LDX(cpu,value);
                break;
            }

            case INS_LDX_ABS_Y:{
                Byte value = addr_absolute_y(cpu, mem, &ticks);
                Execute_INS_LDX(cpu,value);
                break;
            }

//INSTRUCTION SET FOR LDY
            case INS_LDY_IM:{
                Byte Value = addr_immediate(cpu, mem, &ticks);
                Execute_INS_LDY(cpu,Value);
                break;
            }
            case INS_LDY_ZP:{
                Byte ZP_Value = addr_zero_page(cpu,mem,&ticks);
                Execute_INS_LDY(cpu,ZP_Value);
                break;
            }
            case INS_LDY_ZP_X:{
                Byte value = addr_zero_page_x(cpu, mem, &ticks);
                Execute_INS_LDY(cpu,value);
                break;
            }

            case INS_LDY_ABS:{
                 Byte Value = addr_absolute(cpu, mem, &ticks);
                 Execute_INS_LDY(cpu,Value);
                break;
            }
            case INS_LDY_ABS_X:{
                Byte value = addr_absolute_x(cpu, mem, &ticks);
                Execute_INS_LDY(cpu,value);
                break;
            }
//INSTRUCTION SET FOR STA
            case INS_STA_ZP:{
                Byte address = addr_zp_write(cpu, mem, &ticks);
                Execute_INS_STA(cpu,mem,&ticks,address);
                break;

            }
            case INS_STA_ABS:{
                Word Addr = addr_abs_write(cpu, mem, &ticks);
                Execute_INS_STA(cpu,mem,&ticks,Addr);
                break;
            }
            case INS_STA_ZP_X:{
                Byte addr = addr_zp_x_write(cpu,mem,&ticks);
                Execute_INS_STA(cpu,mem,&ticks,addr);
                break;
            }

            case INS_STA_ABS_X:{
                Word addr = addr_abs_x_write(cpu,mem,&ticks);
                Execute_INS_STA(cpu,mem,&ticks,addr);
                break;
            }

            case INS_STA_ABS_Y:{
                Word addr = addr_abs_y_write(cpu,mem,&ticks);
                Execute_INS_STA(cpu,mem,&ticks,addr);
                break;
            }
//INSTRUCTION SET FOR STX
            case INS_STX_ZP:{
                Byte addr = addr_zp_write(cpu,mem,&ticks);
                Execute_INS_STX(cpu,mem,&ticks,addr);
                break;
            }
            case INS_STX_ZP_Y:{
                Byte addr = addr_zp_y_write(cpu,mem,&ticks);
                Execute_INS_STX(cpu,mem,&ticks,addr);
                break;
            }
            case INS_STX_ABS:{
                Word addr = addr_abs_write(cpu, mem, &ticks);
                Execute_INS_STX(cpu,mem,&ticks,addr);
                break;
            }
//INSTRUCTION SET FOR STY
            case INS_STY_ZP:{
                Byte addr = addr_zp_write(cpu,mem,&ticks);
                Execute_INS_STY(cpu,mem,&ticks,addr);
                break;
            }
            case INS_STY_ZP_X:{
                Byte addr = addr_zp_x_write(cpu,mem,&ticks);
                Execute_INS_STY(cpu,mem,&ticks,addr);
                break;
            }
            case INS_STY_ABS:{
                Word addr = addr_abs_write(cpu,mem,&ticks);
                Execute_INS_STY(cpu,mem,&ticks,addr);
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
Instruction InstructionTable[256];
void InitInstructionTable(void){
    InstructionTable[INS_LDA_IM] = (
        Instruction
    )
    {
       .Mnemonic="LDA",
       .Operation =LDA,
       .AddressMode =Immediate,
       .ticks = 2,
       .PageCrossPenalty = 0
    };
    InstructionTable[INS_LDA_ZP] = (
       Instruction
        ){
            .Mnemonic = "LDA",
            .Operation = LDA,
            .AddressMode = ZeroPage,
            .ticks = 3,
            .PageCrossPenalty=0
        };
    InstructionTable[INS_LDA_ZP_X] = (
        Instruction
    ){
        .Mnemonic = "LDA",
        .Operation=LDA,
        .AddressMode = ZeroPage_X,
        .ticks = 3,
        .PageCrossPenalty=0
    };
    InstructionTable[INS_LDA_ABS] = (
        Instruction
    ){
        .Mnemonic = "LDA",
        .Operation=LDA,
        .AddressMode=Absolute,
        .ticks=4,
        .PageCrossPenalty =0

    };
    InstructionTable[INS_LDA_ABS_X]=(
        Instruction
    ){
        .Mnemonic="LDA",
        .Operation=LDA,
        .AddressMode=Absolute_X,
        .ticks=4,
        .PageCrossPenalty = 1
    };
    InstructionTable[INS_LDA_ABS_Y]=(
        Instruction
    ){
        .Mnemonic="LDA",
        .Operation=LDA,
        .AddressMode=Absolute_Y,
        .ticks=4,
        .PageCrossPenalty = 1
    };
}
