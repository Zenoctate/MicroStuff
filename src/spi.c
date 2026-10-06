#include "spi.h"

void init_spi() {
    // Enable, Master Mode, Clk Fosc/16  (MSB First)
    *SPCR = bit6 | bit4 | bit0;

    // Set Output (PB3 - MOSI; PB5 - SCK)
    *DDRB = bit5 | bit3;
}

uint8_t transmit_spi(uint8_t data) {
    *SPDR = data;
    while(!(*SPSR & bit7));
    return *SPDR;
}