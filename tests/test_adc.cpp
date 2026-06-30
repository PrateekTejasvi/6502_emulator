#include<gtest/gtest.h>
extern "C"{
#include "cpu.h"
#include "memory.h"
#include"test_fixture.h"
}

TEST_F(CPUFixture, ADC_INSTRUCTION){
    unsigned int ticks = 2;
    Reset(&cpu,&mem);
    mem.Data[0x8000]=INS_ADC_IM;
    mem.Data[0x8001]=0x32;
    Byte Ins =FetchByte(&cpu,&mem,&ticks);
    Byte value = addr_immediate(&cpu, &mem, &ticks);
    Execute_INS_ADC(&cpu,&mem,value);
    EXPECT_EQ(cpu.A,0x32);
}
