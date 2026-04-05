#ifndef CHIP8_REGISTERS
#define CHIP8_REGISTERS

#include "config.h"

struct chip8_registers
{
    unsigned char V[CHIP8_TOTAL_DATA_REGISTERS];
    unsigned short I; // 16 bit to store memory addresses
    unsigned char delay_timer;
    unsigned char sound_timer;
    unsigned char PC; // program counter
    unsigned char SP; // stack pointer
};

#endif