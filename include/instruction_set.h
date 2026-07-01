#pragma once
#include "cpu.h"
#include "memory.h"

#ifndef INSTRUCTION_SET_H
#define INSTRUCTION_SET_H

typedef enum {
  INS_LDA_IM = 0xA9,
  INS_LDA_ZP = 0xA5,
  INS_LDA_ZP_X = 0xB5,
  INS_LDA_ABS = 0xAD,
  INS_LDA_ABS_X = 0xBD,
  INS_LDA_ABS_Y = 0xB9,

  INS_LDX_IM = 0xA2,
  INS_LDX_ZP = 0xA6,
  INS_LDX_ZP_Y = 0xB6,
  INS_LDX_ABS = 0xAE,
  INS_LDX_ABS_Y = 0xBE,

  INS_LDY_IM = 0xA0,
  INS_LDY_ZP = 0xA4,
  INS_LDY_ZP_X = 0xB4,
  INS_LDY_ABS = 0xAC,
  INS_LDY_ABS_X = 0xBC,

  INS_STA_ZP = 0x85,
  INS_STA_ZP_X = 0x95,
  INS_STA_ABS = 0x8D,
  INS_STA_ABS_X = 0x9D,
  INS_STA_ABS_Y = 0x99,

  INS_STX_ZP = 0x86,
  INS_STX_ZP_Y=0x96,
  INS_STX_ABS =0x8E,

  INS_STY_ZP = 0x84,
  INS_STY_ZP_X = 0x94,
  INS_STY_ABS = 0x8C,
  // TAX INSTRUCTION
  INS_TAX_IMP = 0xAA,
  // TAY INSTRUCTION
  INS_TAY_IMP = 0xA8,
  // TSX INSTRUCTION
  INS_TSX_IMP = 0xBA,
  // TXA INSTRUCTION
  INS_TXA_IMP = 0x8A,
  // TXS INSTRUCTION
  INS_TXS_IMP = 0x9A,
  // TYA INSTRUCTION
  INS_TYA_IMP = 0x98,
  // ADC- add with carry instructions
  INS_ADC_IM = 0x69,
  INS_ADC_ZP = 0x65,
  INS_ADC_ZP_X = 0x75,
  INS_ADC_ABS = 0x6D,
  INS_ADC_ABS_X = 0x7D,
  INS_ADC_ABS_Y = 0x79,
  INS_ADC_IND_X = 0x61,
  INS_ADC_IND_Y = 0x71,
  // AND INSTRUCTIONS
  INS_AND_IM = 0x29,
  INS_AND_ZP = 0x25,
  INS_AND_ZP_X = 0x35,
  INS_AND_ABS = 0x2D,
  INS_AND_ABS_X = 0x3D,
  INS_AND_ABS_Y = 0x39,
  INS_AND_IND_X = 0x21,
  INS_AND_IND_Y = 0x31,
  // ASL INSTRUCTIONS
  INS_ASL_ACCM = 0x0A,
  INS_ASL_ZP = 0x06,
  INS_ASL_ZP_X = 0x16,
  INS_ASL_ABS = 0x0E,
  INS_ASL_ABS_X = 0x1E,
} opCodes;

#endif

// merge LDA instructions
void Execute_INS_LDA(CPU *, Byte);
// LDX INSTRUCTIONS
void Execute_INS_LDX(CPU *, Byte);
// LDY INSTRUCTIONS
void Execute_INS_LDY(CPU *, Byte);
// STA INSTRUCTIONS
void Execute_INS_STA(CPU *, Mem *, unsigned int *, Word);
// STX INSTRUCTIONS
void Execute_INS_STX(CPU *, Mem *, unsigned int *, Word);
// STY INSTRUCTIONS
void Execute_INS_STY(CPU *, Mem *, unsigned int *, Word);
// TRANSFER INSTRUCTIONS
void Execute_INS_TAX(CPU *);
void Execute_INS_TAY(CPU *);
void Execute_INS_TSX(CPU *);
void Execute_INS_TXA(CPU *);
void Execute_INS_TXS(CPU *);
void Execute_INS_TYA(CPU *);
// ADC INSTRUCTIONS
void Execute_INS_ADC(CPU *, Mem *, Byte);
void Execute_INS_AND(CPU *,Mem*,Byte);
