#pragma once

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t; // I want to it rarely used

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed long int32_t; // I want to it rarely used

// #define RST_SEC __attribute__((section(".reset")))
#define CODE_SEC __attribute__((section(".text")))
#define RODATA_SEC __attribute__((section(".rodata")))
#define DATA_SEC __attribute__((section(".data")))

#define ISR __attribute__((signal, used))

#define bit0 0b1
#define bit1 0b10
#define bit2 0b100
#define bit3 0b1000
#define bit4 0b10000
#define bit5 0b100000
#define bit6 0b1000000
#define bit7 0b10000000