#include "time.h"

// TODO: Use timer instead, may need to switch to assembly
void delay(uint16_t ms) {
    for(uint8_t i = 0; i < 100; i++) {
        for(uint8_t j = 0; j < 100; j++) {
            for(uint8_t k = 0; k < 100; k++) {
                // Nothing, waste CPU cycles
            }
        }
    }
}