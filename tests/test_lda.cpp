#include"test_fixture.h"
extern "C"{
    #include"memory.h"
    #include"instruction_set.h"
}
TEST_F(CPUFixture,ImmediateAddr){
    unsigned int ticks=1;
    mem.Data[0x8000] = 0x42;
   Byte value= addr_immediate(&cpu,&mem,&ticks);
    EXPECT_EQ(value,0x42);
}

TEST_F(CPUFixture,ImmediateAddrTicks){
    unsigned int ticks = 1;
    mem.Data[0x8000] = 0x42;
    Byte value = addr_immediate(&cpu, &mem, &ticks);
    EXPECT_EQ(ticks,0);
}

TEST_F(CPUFixture,LoadAccumalatorImmediate){
    unsigned int ticks = 2;
    mem.Data[0x8000] = INS_LDA_IM;
    mem.Data[0x8001] = 0x42;
    Byte Ins = FetchByte(&cpu,&mem,&ticks);
    Byte value = addr_immediate(&cpu,&mem,&ticks);
    Execute_INS_LDA(&cpu,&mem,&ticks,value);
    EXPECT_EQ(cpu.A,0x42);
}
TEST_F(CPUFixture,LoadAccumalatorImmediateStatus){
    unsigned int ticks = 2;
    mem.Data[0x8000] = INS_LDA_IM;
    mem.Data[0x8001] = 0x42;
    Byte Ins = FetchByte(&cpu,&mem,&ticks);
    Byte value = addr_immediate(&cpu,&mem,&ticks);
    Execute_INS_LDA(&cpu, &mem, &ticks, value);
    EXPECT_FALSE(cpu.Status & FLAG_Z);
    EXPECT_FALSE(cpu.Status & FLAG_N);
}
