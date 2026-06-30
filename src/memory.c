#include "cpu.h"
#include "memory.h"
//TODO:add page boundary crossing
void Init(Mem *mem){

    mem->MAX_MEM = 1024 * 64;

    for(int i=0;i<1024*64;i++){
        mem->Data[i]=0;
    }

}

Byte ReadFromMem(CPU *cpu , Mem *mem,unsigned int *ticks,Word addr){

    Byte data = mem->Data[addr];

    (*ticks)--;

    return data;
}

Byte FetchByte(CPU *cpu , Mem *mem, unsigned int *ticks){

    Word address = cpu->PC;

    Byte data = mem->Data[address];

    cpu->PC = (cpu->PC + 1) & 0xFFFF;

    (*ticks)--;

    return data;
}

Word FetchWord(CPU *cpu , Mem *mem,unsigned int *ticks){

    Byte lowByte = FetchByte(cpu , mem , ticks);

    Byte highByte = FetchByte(cpu , mem , ticks);

    Word value = lowByte | (highByte << 8);

    return value;
}

void WriteByte(CPU *cpu,Mem *mem,unsigned int *ticks,Word addr,Byte value){
    mem -> Data[addr] = value;
    (*ticks)--;
}

Byte addr_immediate(CPU *cpu, Mem *mem, unsigned int *ticks){
    return FetchByte(cpu,mem,ticks);
}

Byte addr_zero_page(CPU *cpu, Mem *mem, unsigned int *ticks){
    Word zero_page_addr = FetchByte(cpu,mem,ticks);
    Byte data = ReadFromMem(cpu, mem,ticks,zero_page_addr);
    return data;

}

Byte addr_zero_page_x(CPU *cpu,Mem *mem,unsigned int *ticks){
    Word zero_page_addr = FetchByte(cpu,mem,ticks);
    (*ticks)--;
    Byte data = ReadFromMem(cpu,mem,ticks,(zero_page_addr+cpu->X)&0xFF);
    return data;

}

Byte addr_zero_page_y(CPU *cpu , Mem *mem,unsigned int *ticks){
    Word zero_page_addr = FetchByte(cpu,mem,ticks);
    (*ticks)--;
    Byte data = ReadFromMem(cpu,mem,ticks,(zero_page_addr+cpu->Y)&0xFF);
    return data;
}

Byte addr_absolute(CPU *cpu, Mem *mem, unsigned int *ticks){
    Byte lowByte = FetchByte(cpu, mem, ticks);
    Byte highByte = FetchByte(cpu,mem,ticks);
    Word address = lowByte | (highByte<<8);
    Byte value = ReadFromMem(cpu, mem, ticks, address);
    return value;
}


Byte addr_absolute_x(CPU *cpu, Mem *mem, unsigned int *ticks){
    Byte lowByte = FetchByte(cpu,mem,ticks);
    Byte highByte = FetchByte(cpu, mem, ticks);
    Word base_address = lowByte | (highByte<<8);
    Word final_address = base_address + cpu->X;
    if((final_address >> 8) != (base_address>>8)){
        (*ticks)--;
    }
    Byte value = ReadFromMem(cpu, mem,ticks, final_address);
    return value;

}


Byte addr_absolute_y(CPU *cpu, Mem *mem, unsigned int *ticks){
    Byte lowByte = FetchByte(cpu, mem, ticks);
    Byte highByte=FetchByte(cpu,mem,ticks);
    Word base_address = lowByte | (highByte << 8);
    Word final_address = base_address + cpu -> Y;
    if((final_address >> 8) != (base_address>>8)){
        (*ticks)--;
    }
    Byte value = ReadFromMem(cpu, mem, ticks, final_address);
    return value;
}



Word addr_zp_write(CPU *cpu, Mem *mem, unsigned int *ticks){
    Byte addr = FetchByte(cpu, mem, ticks);
    return (Word)addr;
}

Word addr_zp_x_write(CPU *cpu,Mem *mem,unsigned int *ticks){
    Byte base_address= FetchByte(cpu,mem,ticks);
    Byte final_address = (base_address + cpu->X) & 0xFF;
    (*ticks)--;
    return (Word)final_address;
}
Word addr_zp_y_write(CPU *cpu,Mem *mem,unsigned int *ticks){
    Byte base_address = FetchByte(cpu,mem,ticks);
    Byte final_address = (base_address + cpu -> Y) & 0xFF;
    (*ticks)--;
    return (Word)final_address;
}

Word addr_abs_write(CPU *cpu, Mem *mem, unsigned int *ticks){
    Word address = FetchWord(cpu, mem, ticks);
    return address;

}

Word addr_abs_x_write(CPU *cpu, Mem *mem, unsigned int *ticks){
    Word base_address = FetchWord(cpu, mem, ticks);
    Word final_address = base_address + cpu->X;
    (*ticks)--;
    return final_address;

}
Word addr_abs_y_write(CPU *cpu, Mem *mem, unsigned int *ticks){
    Word base_address = FetchWord(cpu, mem, ticks);
    Word final_address = base_address + cpu->Y;
    (*ticks)--;
    return final_address;

}

//implementing remaining addressing modes
