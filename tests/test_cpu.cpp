#include <gtest/gtest.h>

extern "C" {
#include "cpu.h"
#include "memory.h"
#include "instruction_set.h"
}

class CPUFixture : public ::testing::Test
{
protected:
    CPU cpu;
    Mem mem;

    void SetUp() override
    {
        Init(&mem);

        mem.Data[0xFFFC] = 0x00;
        mem.Data[0xFFFD] = 0x80;

        Reset(&cpu,&mem);
    }
};

//test for reset vector -> program counter
TEST_F(CPUFixture,ResetLoadsProgramCounterFromResetVector){
    EXPECT_EQ(cpu.PC,0x8000);
}
//test for reset -> Stack Pointer
TEST_F(CPUFixture,ResetInitalizesStackPointer){
    EXPECT_EQ(cpu.SP,0xFD);
}
//tests for  register clear
TEST_F(CPUFixture,ResetStatusRegisters){
    EXPECT_EQ(cpu.A,0x00);
    EXPECT_EQ(cpu.X,0x00);
    EXPECT_EQ(cpu.Y,0x00);
}

TEST_F(CPUFixture,ResetVector){
    CPU cpu;
    Mem mem;
    Init(&mem);
    mem.Data[0xFFFC] = 0x34;
    mem.Data[0xFFFD] = 0x12;
    Reset(&cpu,&mem);
    EXPECT_EQ(cpu.PC,0x1234);
}

TEST_F(CPUFixture,FetchByteReturnsValue){
    unsigned int clock = 10;
    unsigned int *ticks = &clock;
    mem.Data[0x8000] = 0x42;
    Byte data = FetchByte(&cpu, &mem, ticks);
    EXPECT_EQ(data,0x42);
}
