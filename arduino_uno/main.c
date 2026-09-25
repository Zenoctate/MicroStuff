#define DDRB *((volatile char *)0x24)
#define DDB5 5
#define PORTB *((volatile char *)0x25)
#define PORTB5 5

void delay();

/*
    Order of function matters
    The first function is always placed at address 0x0000 by compiler
    Execution starts at 0x0000 as per the configuration of microcontroller

    TODO: Write small assembly code (always run on reset) and jmp to start
*/
void start() {
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

