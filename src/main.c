#include "globaldefs.h"
#include "memory.h"
#include "usart.h"
#include "time.h"
#include "libs/serial.h"

CODE_SEC void main();

void main() {
    load_SRAM();    // Always first
    init_timer0();
    init_usart0();
    
    // Enable interrupts
    __asm__ __volatile__("sei" ::: "memory");
    
    *DDRB |= bit5; // Arduino digital pin 13 -> Output
    while (1) {
        *PORTB ^= bit5; // Toggle pin 13
        serialSend("Hello from microcontroller\r\n");
        delay(250);
    }
}

