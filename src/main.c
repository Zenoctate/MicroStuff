#include "globaldefs.h"
#include "memory.h"
#include "usart.h"
#include "time.h"
#include "spi.h"
#include "libs/serial.h"

void main() {
    load_SRAM();    // Always first
    init_timer0();
    init_usart0();
    init_spi();
    
    // Enable interrupts
    __asm__ __volatile__("sei" ::: "memory");
    
    serialSend("Hello from microcontroller\r\n");

    // Communicate with Atmega8a
    transmit_spi(0xAC);
    transmit_spi(0x53);
    uint8_t response = transmit_spi(0x00);
    transmit_spi(0x00);

    if(response == 0x53) {
        serialSend("Success connection!!\r\n");
    } else {
        serialSend("Failure...\r\n");
    }

    while (1) {
        uint8_t wow = wait_receive_usart0();
        transmit_usart0(wow);
    }
}

