#include"test_fixture.h"
extern "C"{
    #include"memory.h"
}
TEST_F(CPUFixture,FetchWordReturnsCorrectValue){
    mem.Data[0x8000] = 0x34;
    mem.Data[0x8001] = 0x12;
    unsigned int ticks = 2;
    Word value = FetchWord(&cpu, &mem, &ticks);
    EXPECT_EQ(value,0x1234);
}

TEST_F(CPUFixture,FetchWordPCincremented){
    mem.Data[0x8000] = 0x34;
    mem.Data[0x8001] = 0x12;
    unsigned int ticks = 2;
    Word value = FetchWord(&cpu,&mem,&ticks);
    EXPECT_EQ(cpu.PC,0x8002);
}

TEST_F(CPUFixture,FetchWordConsumesCycles){
    mem.Data[0x8000] = 0x34;
    mem.Data[0x8001] = 0x12;
    unsigned int ticks = 2;
    Word value = FetchWord(&cpu,&mem,&ticks);
    EXPECT_EQ(ticks,0);
}
TEST_F(CPUFixture,ReadFromMem){
    mem.Data[0x8000] = 0x34;
    unsigned int ticks = 2;
    Byte data = ReadFromMem(&cpu, &mem, &ticks, 0x8000);
    EXPECT_EQ(data,0x34);
    EXPECT_EQ(ticks,1);
}

TEST_F(CPUFixture,WriteByte){
    unsigned int ticks = 2;
    WriteByte(&cpu,&mem,&ticks,0x8000,0x12);
    EXPECT_EQ(mem.Data[0x8000], 0x12);
    EXPECT_EQ(ticks,1);
}
