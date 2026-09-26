/*
    For atmega328p
*/
#pragma once

#include "globaldefs.h"

#define PINB    ((volatile uint8_t *)0x23)
#define DDRB    ((volatile uint8_t *)0x24)
#define PORTB   ((volatile uint8_t *)0x25)

#define PINC    ((volatile uint8_t *)0x26)
#define DDRC    ((volatile uint8_t *)0x27)
#define PORTC   ((volatile uint8_t *)0x28)

#define PIND    ((volatile uint8_t *)0x29)
#define DDRD    ((volatile uint8_t *)0x2A)
#define PORTD   ((volatile uint8_t *)0x2B)

uint16_t memcpy(uint8_t *src, uint8_t *dest, uint16_t size);