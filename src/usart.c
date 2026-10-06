#include "usart.h"

void init_usart0() {
    /*
        Section 19 (specifically 19.10)
    */

    // Table 19-12
    // Set baud rate: 9600 (if bit 1 of UCSR0A, i.e. U2X0, is 0)
    // TODO: 115200 doesn't work, find reason (maybe should try later with U2X0 as 1)
    *UBRR0H = 0;
    *UBRR0L = 103;

    // Section 19.10.3
    // Enable receiver and transmitter
    *UCSR0B = bit4 | bit3;

    // Section 19.10.4
    // Set frame format: Asynchronous, Parity disabled, 1 bit stop, 8 bits data
    *UCSR0C = bit2 | bit1 ;
}

void transmit_usart0(uint8_t data) {
    // Section 19.10.2
    while (!(*UCSR0A & bit5)); // Wait for empty transmit buffer

    // Section 19.10.1
    *UDR0 = data;
}

uint8_t wait_receive_usart0() {
    // Section 19.10.2
    while (!(*UCSR0A & bit7)); // Wait for data to arrive (RXC flag = 1)

    // Section 19.10.1
    return *UDR0;
}

// ISR void ISR_usart0_rx() {
    
// }