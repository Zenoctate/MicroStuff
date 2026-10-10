#pragma once

#include "memory.h"
#include "time.h"

void init_i2c();
uint8_t start_i2c();
uint8_t write_i2c(uint8_t data);
uint8_t read_i2c(uint8_t ack);
uint8_t stop_i2c();
