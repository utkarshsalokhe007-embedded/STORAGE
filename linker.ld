/* Tell the linker where execution starts */
ENTRY(Reset_Handler)

/*
 * Memory layout from the STM32F407VG datasheet:
 * FLASH: 0x08000000, 1024K (1MB)
 * RAM:   0x20000000, 128K  (main SRAM; there's also a separate 64K CCM
 *        RAM at 0x10000000 not usable for DMA — ignore it for now)
 */
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 1024K
    RAM (rwx)   : ORIGIN = 0x20000000, LENGTH = 128K
}

/* Stack grows downward from top of RAM */
_estack = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS
{
    /* Vector table must be the very first thing in flash */
    .isr_vector :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))   /* KEEP prevents the linker from discarding it
                                   as "unused" during garbage collection */
        . = ALIGN(4);
    } > FLASH

    /* Your actual code + read-only constants, stored in flash */
    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text*)
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
    } > FLASH

    /* _sidata = where .data's initial values live in FLASH (load address).
       Reset_Handler copies from here to RAM at startup. */
    _sidata = LOADADDR(.data);

    /* Initialized globals: live in RAM at runtime, but their initial
       values are stored in FLASH until Reset_Handler copies them */
    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } > RAM AT> FLASH

    /* Uninitialized globals: just need space in RAM, zeroed at startup */
    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } > RAM

    /* Reserve some space so heap/stack don't silently collide with .bss.
       Not a real allocator — just a safety margin check. */
    ._user_heap_stack :
    {
        . = ALIGN(8);
        . = . + 0x200;
        . = ALIGN(8);
    } > RAM
}
