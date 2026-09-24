#define DDRB *((volatile char *)0x24)
#define DDB5 5
#define PORTB *((volatile char *)0x25)
#define PORTB5 5

void delay();

void main(void) {
    DDRB |= (1 << DDB5);   // Arduino digital pin 13
    
    
    while (1) {
        PORTB ^= (1 << PORTB5);
        delay();
    }
}

void delay() {
    for(char i = 0; i < 100; i++) {
        for(char j = 0; j < 100; j++) {
            for(char k = 0; k < 100; k++) {

            }
        }
    }
}

