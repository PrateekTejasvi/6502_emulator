#pragma once
#include<gtest/gtest.h>
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
