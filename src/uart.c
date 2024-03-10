#include "uart.h"
#include "lib.h"

void write_char(char c) {
    while (get32(UART0_FR) & (1 << 5)) { }
    put32(UART0_DR, c);
}

char read_char() {
    while (get32(UART0_FR) & (1 << 4)) { }
    return get32(UART0_DR);
}

void write_string(const char *str) {
    while(*str) {
        if(*str == '\n'){
            write_char('\r');
        }
        write_char(*str);
        str++;
    }
}

void init_uart() {
    put32(UART0_CR, 0);
    put32(UART0_IBRD, 26);
    put32(UART0_FBRD, 0);
    put32(UART0_LCRH, (1 << 4) | (1 << 5) | (1 << 6));
    put32(UART0_IMSC, 0);
    put32(UART0_CR, (1 << 0) | (1 << 8) | (1 << 9));
}
