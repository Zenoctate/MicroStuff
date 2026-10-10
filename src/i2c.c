// TODO: Provide documentation references
#include "i2c.h"

uint8_t wait_timeout() {
    uint8_t timeout = 200;
    while (!(*TWCR & bit7)) {
        delay(1);
        if(--timeout == 0) {
            return 0;
        }
    }

    return 1;
}

void init_i2c() {
    *TWSR = 0; // Prescaler = 1
    *TWBR = 72; // 100 kHz clock
    *TWCR = bit2; // Enable I2C
}

uint8_t start_i2c() {
    *TWCR = bit7 | bit5 | bit2;
    wait_timeout();

    switch(*TWSR & 0xF8) {
        case 0x08: // Start ACK
        case 0x10: // Start NOT ACK
            break;
        default:
            return 0;
    }

    return 1;
} 

uint8_t write_i2c(uint8_t data) {
    *TWDR = data;
    *TWCR = bit7 | bit2;
    wait_timeout();

    switch(*TWSR & 0xF8) {
        case 0x18: // SLA ACK
        case 0x20: // SLA NOT ACK
        case 0x28: // DATA ACK
        case 0x30: // DATA NOT ACK
        case 0x40: // SLA MR ACK
        case 0x48: // SLA MR NOT ACK
        case 0x50: // DATA MR ACK
        case 0x58: // DATA MR NOT ACK
            break;

        default:
            return 0;
    }

    return 1;
}

uint8_t read_i2c(uint8_t ack) {
    *TWCR = bit7 | bit2;
    if(ack) { *TWCR |= bit6; }
    
    if(!wait_timeout()) { return 0; }
    return *TWDR;
}

uint8_t stop_i2c() {
    *TWCR = bit7 | bit4 | bit2;
    
    uint8_t timeout = 200;
    while (!(*TWCR & bit7)) {
        delay(1);
        if(--timeout == 0) {
            return 0;
        }
    }

    return 1;
}