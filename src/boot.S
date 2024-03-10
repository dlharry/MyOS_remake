.section ".text.boot"
.globl _start

_start:
    mrs x0, mpidr_el1 // read the multiprocessor affinity register(mpidr_el1) into reg x1
    // to get the processor id, use 'and' isolate the lower bits(which usually indicate the core id)
    // and check if the core id is 0(the main core, the one we want)
    and x0, x0, #3
    cbz x0, kernel_entry
    b end

end:
    wfe
    b end

kernel_entry:
    mrs x0, currentel
    lsr x0, x0, #2
    cmp x0, #2
    bne end

    msr sctlr_el1, xzr
    mov x0, #(1 << 31)
    msr hcr_el2, x0

    mov x0, #0b1111000101
    msr spsr_el2, x0

    adr x0, el1_entry
    msr elr_el2, x0

    eret

el1_entry:
    mov sp, #0x80000

    ldr x0, =bss_start
    ldr x1, =bss_end
    sub x2, x1, x0
    mov x1, #0
    bl memset

    bl kernel_main // implement in c
    b end
    