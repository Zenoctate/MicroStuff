#include "mem.h"

uint16_t memcpy(uint8_t *src, uint8_t *dest, uint16_t size) {
    uint16_t i = 0;
    for(; i < size; i++) {
        *dest = *src;
        dest++; src++;
        // TODO: require error checking (out of memory)
    }
    return i;
}