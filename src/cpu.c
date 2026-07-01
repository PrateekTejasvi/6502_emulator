#include "cpu.h"
#include "instruction_set.h"
#include "memory.h"
#include <stdint.h>
#include <stdio.h>
#define InsHandler(name,addr_fn,exec_fn)\
    void name(CPU *cpu,Mem *mem,unsigned int *ticks){\
        Byte value = addr_fn(cpu,mem,ticks);\
        exec_fn(cpu,value);\
}\

#define StoreHandler(name, addr_fn, exec_fn)            \
void name(CPU *cpu, Mem *mem, unsigned int *ticks) {    \
    Word addr = addr_fn(cpu, mem, ticks);               \
    exec_fn(cpu, mem,ticks, addr);                            \
}
InsHandler(LDA_IM,addr_immediate,Execute_INS_LDA);
InsHandler(LDA_ZP,addr_zero_page,Execute_INS_LDA);
InsHandler(LDA_ZP_X,addr_zero_page_x,Execute_INS_LDA);
InsHandler(LDA_ABS,addr_absolute,Execute_INS_LDA);
InsHandler(LDA_ABS_X,addr_absolute_x,Execute_INS_LDA);
InsHandler(LDA_ABS_Y,addr_absolute_y,Execute_INS_LDA);

InsHandler(LDX_IM,addr_immediate,Execute_INS_LDX);
InsHandler(LDX_ZP,addr_zero_page,Execute_INS_LDX);
InsHandler(LDX_ZP_Y,addr_zero_page_y,Execute_INS_LDX);
InsHandler(LDX_ABS,addr_absolute,Execute_INS_LDX);
InsHandler(LDX_ABS_Y,addr_absolute_y,Execute_INS_LDX);

InsHandler(LDY_IM,addr_immediate,Execute_INS_LDY);
InsHandler(LDY_ZP,addr_zero_page,Execute_INS_LDY);
InsHandler(LDY_ZP_X,addr_zero_page_x,Execute_INS_LDY);
InsHandler(LDY_ABS,addr_absolute,Execute_INS_LDY);
InsHandler(LDY_ABS_X,addr_absolute_x,Execute_INS_LDY);

StoreHandler(STA_ZP,addr_zp_write,Execute_INS_STA);
StoreHandler(STA_ZP_X,addr_zp_x_write,Execute_INS_STA);
StoreHandler(STA_ABS,addr_abs_write,Execute_INS_STA);
StoreHandler(STA_ABS_X,addr_abs_x_write,Execute_INS_STA);
StoreHandler(STA_ABS_Y,addr_abs_y_write,Execute_INS_STA);

StoreHandler(STX_ZP,addr_zp_write,Execute_INS_STX);
StoreHandler(STX_ZP_Y,addr_zp_y_write,Execute_INS_STX);
StoreHandler(STX_ABS,addr_abs_write,Execute_INS_STX);

StoreHandler(STY_ZP,addr_zp_write,Execute_INS_STY);
StoreHandler(STY_ZP_X,addr_zp_x_write,Execute_INS_STY);
StoreHandler(STY_ABS,addr_abs_write,Execute_INS_STY);


InstructionHandler handleIns[] = {
    [INS_LDA_IM] = LDA_IM,
    [INS_LDA_ZP]=LDA_ZP,
    [INS_LDA_ZP_X]=LDA_ZP_X,
    [INS_LDA_ABS]=LDA_ABS,
    [INS_LDA_ABS_X]=LDA_ABS_X,
    [INS_LDA_ABS_Y]=LDA_ABS_Y,

    [INS_LDX_IM]=LDX_IM,
    [INS_LDX_ABS]=LDX_ABS,
    [INS_LDX_ZP]=LDX_ZP,
    [INS_LDX_ZP_Y]=LDX_ZP_Y,
    [INS_LDX_ABS_Y]=LDX_ABS_Y,

    [INS_LDY_IM]=LDY_IM,
    [INS_LDY_ZP]=LDY_ZP,
    [INS_LDY_ZP_X]=LDY_ZP_X,
    [INS_LDY_ABS]=LDY_ABS,
    [INS_LDY_ABS_X]=LDY_ABS_X,

    [INS_STA_ZP] = STA_ZP,
    [INS_STA_ZP_X]=STA_ZP_X,
    [INS_STA_ABS]=STA_ABS,
    [INS_STA_ABS_X]=STA_ABS_X,
    [INS_STA_ABS_Y]=STA_ABS_Y,

    [INS_STX_ZP]=STX_ZP,
    [INS_STX_ZP_Y]=STX_ZP_Y,
    [INS_STX_ABS]=STX_ABS

};

void execute_action(CPU *cpu, Mem *mem, unsigned int ticks) {
  while(ticks > 0){
    Byte opCode = FetchByte(cpu, mem, &ticks);
     if(ticks == 0)break;
      if (handleIns[opCode] != NULL) {
        handleIns[opCode](cpu, mem, &ticks);
      }
  }
}


void SetFlag(CPU *cpu, Byte flag, int value) {

  if (value) {
    cpu->Status |= flag;
  } else {
    cpu->Status &= ~flag;
  }
}

void Reset(CPU *cpu, Mem *mem) {

  cpu->PC = mem->Data[0xFFFC] | (mem->Data[0xFFFD] << 8);

  cpu->SP = 0xFD;

  cpu->A = 0;
  cpu->Y = 0;
  cpu->X = 0;

  SetFlag(cpu, FLAG_C, 0);
  SetFlag(cpu, FLAG_B, 0);
  SetFlag(cpu, FLAG_D, 0);
  SetFlag(cpu, FLAG_I, 0);
  SetFlag(cpu, FLAG_N, 0);
  SetFlag(cpu, FLAG_Z, 0);
  SetFlag(cpu, FLAG_V, 0);
  SetFlag(cpu, FLAG_U, 0);
}
