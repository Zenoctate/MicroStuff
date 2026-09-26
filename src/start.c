#include "globaldefs.h"
#include "mem.h"

void delay();

/*
    Order of function matters
    The first function is always placed at address 0x0000 by compiler
    Execution starts at 0x0000 as per the configuration of microcontroller

    TODO: Write small assembly code (always run on reset) and jmp to start
        In a linker scipt of course
*/
void start() {
    *DDRB |= bit5;   // Arduino digital pin 13
    test();

    while (1) {
        *PORTB ^= bit5; // Toggle pin 13 using XOR operator
        delay();
    }
}

void delay() {
    for(uint8_t i = 0; i < 100; i++) {
        for(uint8_t j = 0; j < 100; j++) {
            for(uint8_t k = 0; k < 100; k++) {
                // Nothing, waste CPU cycles
            }
        }
    }
}

