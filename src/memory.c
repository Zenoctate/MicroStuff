#include "memory.h"

// void load_SRAM() {
//     uint16_t size = ld_e_data - ld_s_data;

//     volatile uint8_t *temp = (volatile uint8_t *)0x100; // Start of SRAM
//     volatile uint8_t *temp2 = (volatile uint8_t *)ld_e_text; // TODO: Don't do this

//     while(size-- > 0) {
//         __asm__ __volatile__(
//             "lpm r0, Z\n\t"      // Load byte from FLASH at address Z (temp2)
//             "st X, r0\n\t"       // Store byte to SRAM at address X (temp)
//             :
//             : "x" (temp), "z" (temp2)
//             : "r0"
//         );
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