/*
    Refer to Atmega328p datasheet
    Reference locations I used are written
*/
#include "time.h"

DATA_SEC volatile uint8_t TEST = 40; // 4us * 40 = 160us, if not loaded then 4us * (0xff) = 1ms approx.
DATA_SEC volatile uint32_t system_ms = 0;
// #define system_ms *((volatile uint32_t *)0x100)  // Start of SRAM, temporary for now

void init_timer0() {
    /*
        Section 14 (specially 14.9)
    */

    // Table 14-8 & 14-9
    *TCCR0A = 0b00000010; // CTC mode
    *TCCR0B = 0b00000011; // Every 4us, TCNT0 increments (16MHz clock)

    // Section 14.9.4
    // *OCR0A = 249; // 4us * 250 = 1ms clock
    *OCR0A = TEST;

    // Section 14.9.6
    *TIMSK0 = 0b010; // Interupt on OCR0A match TCNT0
}

void delay(uint32_t ms) {
    uint32_t end = system_ms + ms;
    while(system_ms < end);
}

void ISR_timer0A() {
    system_ms += 1;
}