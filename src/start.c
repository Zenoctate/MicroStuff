#include "globaldefs.h"
#include "mem.h"
#include "time.h"

CODE_SEC void start();

void start() {
    *DDRB |= bit5;   // Arduino digital pin 13 -> Output

    while (1) {
        *PORTB ^= bit5; // Toggle pin 13
        delay(250);
    }
}

