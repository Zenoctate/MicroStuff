/*
    Refer to Atmega328p datasheet
    Only reference locations I used is written
*/
#include "time.h"

void delay(uint16_t ms) {
    /*
        See section 14 (specially 14.9)

        Timer0 will only be used to halt execution for a set duration
        TODO: Is this valid and good way to implement?
    */

    // Table 14-8 & 14-9
    *TCCR0A = 0b00000000; // CTC mode
    *TCCR0B = 0b00000011; // Every 4us, TCNT0 increments (16MHz clock)

    // Section 14.9.3
    *TCNT0 = 0;
    
    for(uint16_t milis = 0; milis < ms; milis++) {
        while(*TCNT0 < 250); // 4us * 250 = 1ms delay
        *TCNT0 = 0;
    }
}