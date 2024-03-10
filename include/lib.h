#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef volatile u32 reg32;

void delay(u64 ticks);
void put32(u64 address, u32 value);
u32 get32(u64 address);

void memset(void *dst, u32 value, u32 size);
void memcpy(void *dst, void *src, u32 size);
void memmove(void *dst, void *src, u32 size);
u32 memcmp(void *src1, void *src2, u32 size);
u32 get_el(void);
void putc(void *p, char c);