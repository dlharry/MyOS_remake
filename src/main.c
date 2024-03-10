#include "uart.h"
#include "printf.h"
#include "debug.h"
#include "lib.h"

void putc(void *p, char c) {
    if(c == '\n') write_char('\r');
    write_char(c);
}

void kernel_main() {
    init_uart();
    init_printf(0, putc);
    printf("Hello, Raspberry pi\r\n");
    printf("We are at EL %u\r\n", (u64)get_el());
    
    while (1) {
        ;
    }
}