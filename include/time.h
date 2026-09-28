#pragma once

#include "globaldefs.h"
#include "mem.h"

// extern volatile uint32_t system_ms;

CODE_SEC void init_timer0();
CODE_SEC void delay(uint32_t ms);

// Only for pointer references, don't call
CODE_SEC ISR void ISR_timer0A();