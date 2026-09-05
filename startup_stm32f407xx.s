.syntax unified
.cpu cortex-m4
.thumb

/* _estack is defined in the linker script (top of RAM) */
.global _estack
.global Reset_Handler

/*
 * Vector table.
 * MUST be placed at the very start of flash (0x08000000).
 * Word 0 = initial stack pointer value (not an address to branch to).
 * Word 1 = Reset_Handler address.
 * Words 2-14 = fixed core exceptions, in this exact order (ARM-mandated).
 * After that would come vendor-specific IRQs (from RM0090), which you
 * can add later if you enable peripherals that use interrupts.
 */
.section .isr_vector, "a", %progbits
.type g_pfnVectors, %object
g_pfnVectors:
    .word _estack               /* 0: initial SP */
    .word Reset_Handler         /* 1: Reset */
    .word Default_Handler       /* 2: NMI */
    .word Default_Handler       /* 3: HardFault */
    .word Default_Handler       /* 4: MemManage */
    .word Default_Handler       /* 5: BusFault */
    .word Default_Handler       /* 6: UsageFault */
    .word 0                     /* 7: Reserved */
    .word 0                     /* 8: Reserved */
    .word 0                     /* 9: Reserved */
    .word 0                     /* 10: Reserved */
    .word Default_Handler       /* 11: SVCall */
    .word Default_Handler       /* 12: DebugMonitor */
    .word 0                     /* 13: Reserved */
    .word Default_Handler       /* 14: PendSV */
    .word Default_Handler       /* 15: SysTick */
    /* Peripheral IRQs (USART, TIM, EXTI, etc.) would be appended here */
.size g_pfnVectors, .-g_pfnVectors

/*
 * Reset_Handler: first code that runs after reset.
 * Job: initialize RAM contents before main() can safely use globals.
 */
.section .text.Reset_Handler
.weak Reset_Handler
.type Reset_Handler, %function
Reset_Handler:
    /* Copy .data section (initial values of globals) from FLASH to RAM.
       _sdata/_edata/_sidata are symbols defined in the linker script. */
    ldr r0, =_sdata      /* r0 = destination start (RAM) */
    ldr r1, =_edata      /* r1 = destination end (RAM) */
    ldr r2, =_sidata     /* r2 = source start (FLASH, load address) */
    movs r3, #0
    b LoopCopyDataInit

CopyDataInit:
    ldr r4, [r2, r3]
    str r4, [r0, r3]
    adds r3, r3, #4

LoopCopyDataInit:
    adds r4, r0, r3
    cmp r4, r1
    bcc CopyDataInit

    /* Zero-fill .bss (uninitialized globals must start at 0) */
    ldr r2, =_sbss
    ldr r4, =_ebss
    movs r3, #0
    b LoopFillZerobss

FillZerobss:
    str r3, [r2]
    adds r2, r2, #4

LoopFillZerobss:
    cmp r2, r4
    bcc FillZerobss

    /* RAM is ready — jump into your code */
    bl main
    b .                  /* trap here if main() ever returns */
.size Reset_Handler, .-Reset_Handler

/* Fallback handler for any exception you haven't implemented yet */
.section .text.Default_Handler, "ax", %progbits
Default_Handler:
    b .
.size Default_Handler, .-Default_Handler
