; Current timer values
.set TCNT0, 0x46
.set TCNT1L, 0x84
.set TCNT1H, 0x85
.set TCNT2, 0xB2

; Timer compare
.set OCR0A, 0x47
.set OCR0B, 0x48
.set OCR1AL, 0x88
.set OCR1AH, 0x89
.set OCR1BL, 0x8A
.set OCR1BH, 0x8B
.set OCR2A, 0xB3
.set OCR2B, 0xB4

; Timer configuration
.set TCCR0A, 0x44
.set TCCR0B, 0x45
.set TCCR1A, 0x80
.set TCCR1B, 0x81
.set TCCR1C, 0x82
.set TCCR2A, 0xB0
.set TCCR2B, 0xB1

; Timer interrupt mask
.set TIMSK0, 0x6E
.set TIMSK1, 0x6F
.set TIMSK2, 0x70

; Timer interrupt flags
.set TIFR0, 0x35
.set TIFR1, 0x36
.set TIFR2, 0x37

; Port B
.set PINB, 0x23
.set DDRB, 0x24
.set PORTB, 0x25

; Port C
.set PINC, 0x26
.set DDRC, 0x27
.set PORTC, 0x28

; Port D
.set PIND, 0x29
.set DDRD, 0x2A
.set PORTD, 0x2B

; USART
.set UCSR0A, 0xC0
.set UCSR0B, 0xC1
.set UCSR0C, 0xC2
.set UBRR0L, 0xC4
.set UBRR0H, 0xC5
.set UDR0, 0xC6
