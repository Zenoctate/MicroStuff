#pragma once

#include "globaldefs.h"

// Current timer values
#define TCNT0   ((volatile uint8_t *)0x46)
#define TCNT1L  ((volatile uint8_t *)0x84)
#define TCNT1H  ((volatile uint8_t *)0x85)
#define TCNT2   ((volatile uint8_t *)0xB2)

// Timer compare
#define OCR0A   ((volatile uint8_t *)0x47)
#define OCR0B   ((volatile uint8_t *)0x48)
#define OCR1AL  ((volatile uint8_t *)0x88)
#define OCR1AH  ((volatile uint8_t *)0x89)
#define OCR1BL  ((volatile uint8_t *)0x8A)
#define OCR1BH  ((volatile uint8_t *)0x8B)
#define OCR2A   ((volatile uint8_t *)0xB3)
#define OCR2B   ((volatile uint8_t *)0xB4)

// Timer configuration
#define TCCR0A  ((volatile uint8_t *)0x44)
#define TCCR0B  ((volatile uint8_t *)0x45)
#define TCCR1A  ((volatile uint8_t *)0x80)
#define TCCR1B  ((volatile uint8_t *)0x81)
#define TCCR1C  ((volatile uint8_t *)0x82)
#define TCCR2A  ((volatile uint8_t *)0xB0)
#define TCCR2B  ((volatile uint8_t *)0xB1)

// Timer interrupt mask
#define TIMSK0  ((volatile uint8_t *)0x6E)
#define TIMSK1  ((volatile uint8_t *)0x6F)
#define TIMSK2  ((volatile uint8_t *)0x70)

// Timer interrupt flags
#define TIFR0   ((volatile uint8_t *)0x35)
#define TIFR1   ((volatile uint8_t *)0x36)
#define TIFR2   ((volatile uint8_t *)0x37)

// Port B
#define PINB    ((volatile uint8_t *)0x23)
#define DDRB    ((volatile uint8_t *)0x24)
#define PORTB   ((volatile uint8_t *)0x25)

// Port C
#define PINC    ((volatile uint8_t *)0x26)
#define DDRC    ((volatile uint8_t *)0x27)
#define PORTC   ((volatile uint8_t *)0x28)

// Port D
#define PIND    ((volatile uint8_t *)0x29)
#define DDRD    ((volatile uint8_t *)0x2A)
#define PORTD   ((volatile uint8_t *)0x2B)

// USART
#define UCSR0A  ((volatile uint8_t *)0xC0)
#define UCSR0B  ((volatile uint8_t *)0xC1)
#define UCSR0C  ((volatile uint8_t *)0xC2)
#define UBRR0L  ((volatile uint8_t *)0xC4)
#define UBRR0H  ((volatile uint8_t *)0xC5)
#define UDR0    ((volatile uint8_t *)0xC6)

// SPI
#define SPCR    ((volatile uint8_t *)0x4C)
#define SPSR    ((volatile uint8_t *)0x4D)
#define SPDR    ((volatile uint8_t *)0x4E)

// I2C
#define TWBR    ((volatile uint8_t *)0xB8)
#define TWSR    ((volatile uint8_t *)0xB9)
#define TWDR    ((volatile uint8_t *)0xBB)
#define TWCR    ((volatile uint8_t *)0xBC)


// From inside linker script
extern const uint8_t *ld_s_text;
extern const uint8_t *ld_text_size;
extern const uint8_t *ld_e_text;

extern const uint8_t *ld_s_data;
extern const uint8_t *ld_data_size;
extern const uint8_t *ld_e_data;

void load_SRAM();
uint8_t read_flash_byte(uint8_t* flash_addr);