
# 6502 CPU Emulator in C

A emulator for the MOS 6502 microprocessor written in C.

This project aims to recreate the behavior of the original 6502 CPU, including instruction execution, memory operations, addressing modes, register transfers, status flag updates, and clock-cycle accounting.


---

## Features

### CPU Core

Implemented CPU registers:

* Accumulator (A)
* Index Register X
* Index Register Y
* Program Counter (PC)
* Stack Pointer (SP)
* Status Register

Implemented status flags:

* Carry (C)
* Zero (Z)
* Interrupt Disable (I)
* Decimal Mode (D)
* Break (B)
* Unused (U)
* Overflow (V)
* Negative (N)

---

### Memory System

* 64 KB address space
* Byte and Word fetching
* Memory reads and writes
* Reset vector support
* Tick-based memory access simulation

---

### Implemented Instructions

#### Load Instructions

LDA

* Immediate
* Zero Page
* Zero Page,X
* Absolute
* Absolute,X
* Absolute,Y

LDX

* Immediate
* Zero Page
* Zero Page,Y
* Absolute
* Absolute,Y

LDY

* Immediate
* Zero Page
* Zero Page,X
* Absolute
* Absolute,X

#### Store Instructions

STA

* Zero Page
* Zero Page,X
* Absolute
* Absolute,X
* Absolute,Y

STX

* Zero Page
* Zero Page,Y
* Absolute

STY

* Zero Page
* Zero Page,X
* Absolute

#### Transfer Instructions

* TAX
* TXA
* TAY
* TYA
* TSX
* TXS

---

## Project Structure

```text
.
├── cpu.c
├── cpu.h
├── memory.c
├── memory.h
├── instruction_set.c
├── instruction_set.h
├── main.c
└── tests/
```

### Responsibilities

| File              | Purpose                                     |
| ----------------- | ------------------------------------------- |
| cpu.c             | CPU execution loop and instruction decoding |
| memory.c          | Memory access and addressing helpers        |
| instruction_set.c | Instruction implementations                 |
| cpu.h             | CPU structures and flag definitions         |
| memory.h          | Memory interface                            |
| instruction_set.h | Opcode definitions                          |

---

## Example Program

```assembly
LDA #$42
LDX #$05
LDY #$03

STA $10
STA $20,X
STA $3000
STA $4000,X
STA $5000,Y
```

Expected result:

```text
A = 42
X = 05
Y = 03

Memory[0010] = 42
Memory[0025] = 42
Memory[3000] = 42
Memory[4005] = 42
Memory[5003] = 42
```

---

## Build

```bash
mkdir build
cd build

cmake ..
make
```

Run:

```bash
./6502_emulator
```

---

## References

* MOS Technology 6502 Programming Manual
* Visual6502
* 6502.org
* NESDev Wiki

---

## Author

Built as a systems programming project to understand:

* CPU architecture
* Instruction decoding
* Memory systems
* Cycle-accurate emulation
* Test-driven development in C/C++

```
```
