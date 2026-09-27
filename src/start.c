#include "globaldefs.h"
#include "mem.h"

CODE_SEC void delay();
CODE_SEC void start();

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

