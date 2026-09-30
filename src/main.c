#include "globaldefs.h"
#include "memory.h"
#include "usart.h"
#include "time.h"

CODE_SEC void main();

void main() {
    *DDRB |= bit5; // Arduino digital pin 13 -> Output
    init_timer0();
    init_usart0();

    // Enable interrupts
    __asm__ __volatile__("sei" ::: "memory");

    while (1) {
        *PORTB ^= bit5; // Toggle pin 13
        transmit_usart0('H');
        transmit_usart0('e');
        transmit_usart0('l');
        transmit_usart0('l');
        transmit_usart0('o');
        transmit_usart0('\r');
        transmit_usart0('\n');
        delay(250);
    }
}

