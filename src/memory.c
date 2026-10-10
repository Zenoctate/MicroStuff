#include "memory.h"

// void load_SRAM() {
//     uint8_t *temp = (uint8_t *)0x100; // Start of SRAM
//     uint8_t *temp2 = (uint8_t *)ld_s_data;
//     uint16_t size = ld_data_size;

//     while(size-- > 0) {
//         *temp = read_flash_byte(temp2);
//         temp++; temp2++;
//     }
// }

uint8_t read_flash_byte(uint8_t* flash_addr) {
    uint8_t value;

    __asm__ __volatile__(
        "lpm %0, Z"
        : "=r" (value)
        : "z" (flash_addr)
    );

    return value;
}