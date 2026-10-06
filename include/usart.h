#pragma once

#include "globaldefs.h"
#include "memory.h"

void init_usart0();
void transmit_usart0(uint8_t data);
uint8_t wait_receive_usart0();

// ISR void ISR_usart0_rx();