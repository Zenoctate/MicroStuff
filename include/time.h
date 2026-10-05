#pragma once

#include "globaldefs.h"
#include "memory.h"

// extern volatile uint32_t system_ms;

void init_timer0();
void delay(uint32_t ms);

// Only for pointer references, don't call
ISR void ISR_timer0A();