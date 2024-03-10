ENTRY(_start)
SECTIONS
{
    . = 0x80000;

    .text.boot : { *(.text.boot) }
    .text : { *(.text) }

    .rodata : {
        *(.rodata)
    }

    . = ALIGN(16);
    .data : {
        *(.data)
    }

    .bss : {
        bss_start = .;
        *(.bss)
        bss_end = .;
    }
}