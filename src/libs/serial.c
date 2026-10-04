#include "libs/serial.h"

void serialSend(char* str) {
    char c = 'a';
    while(c != 0) {
        c = read_flash_byte((uint8_t *)str++);
        transmit_usart0(c);
    }
}