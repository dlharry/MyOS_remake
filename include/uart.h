#pragma once
#include "peripherals/uart.h"

char read_char();
void write_char(char c);
void write_string(const char *str);
void init_uart();