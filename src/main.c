#include "globaldefs.h"
#include "memory.h"
#include "time.h"

CODE_SEC void main();

void main() {
    *DDRB |= bit5; // Arduino digital pin 13 -> Output
    init_timer0();

    // Enable interrupts
    __asm__ __volatile__("sei" ::: "memory");

    while (1) {
        *PORTB ^= bit5; // Toggle pin 13
        delay(250);
    }
}

