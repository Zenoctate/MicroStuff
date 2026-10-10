#include "spi.h"

void init_spi() {
    // Enable, Master Mode, Clk Fosc/16  (MSB First)
    *SPCR = bit6 | bit4 | bit0;
    *SPSR = 0;

    // Set pins (PB3 - MOSI; PB5 - SCK; PB4 - MISO)
    *DDRB |= bit5 | bit3;
    *DDRB &= ~bit4;
}

uint8_t transmit_spi(uint8_t data) {
    *SPDR = data;
    while(!(*SPSR & bit7));
    return *SPDR;
}