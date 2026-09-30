#pragma once

#include "globaldefs.h"
#include "memory.h"

CODE_SEC void init_usart0();
CODE_SEC void transmit_usart0(uint8_t data);
// CODE_SEC uint8_t receive_usart0();