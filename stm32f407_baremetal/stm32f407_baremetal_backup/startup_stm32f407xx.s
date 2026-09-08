.syntax unified
.cpu cortex-m4
.thumb

/* Stack top = end of RAM (defined in linker script) */
.global _estack

.section .isr_vector, "a", %progbits
.type g_pfnVectors, %object
g_pfnVectors:
    .word _estack               /* Initial stack pointer */
    .word Reset_Handler         /* Reset handler */
    .word Default_Handler       /* NMI */
    .word Default_Handler       /* HardFault */
    .word Default_Handler       /* MemManage */
    .word Default_Handler       /* BusFault */
    .word Default_Handler       /* UsageFault */
    .word 0                     /* Reserved */
    .word 0                     /* Reserved */
    .word 0                     /* Reserved */
    .word 0                     /* Reserved */
    .word Default_Handler       /* SVCall */
    .word Default_Handler       /* DebugMonitor */
    .word 0                     /* Reserved */
    .word Default_Handler       /* PendSV */
    .word Default_Handler       /* SysTick */
    /* External interrupts would follow here if needed */

.size g_pfnVectors, .-g_pfnVectors

.section .text.Reset_Handler
.weak Reset_Handler
.type Reset_Handler, %function
Reset_Handler:
    /* Copy .data section from FLASH to RAM */
    ldr r0, =_sdata
    ldr r1, =_edata
    ldr r2, =_sidata
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

    /* Zero-fill the .bss section */
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

    /* Call main */
    bl main
    b .

.size Reset_Handler, .-Reset_Handler

.section .text.Default_Handler, "ax", %progbits
Default_Handler:
    b .
.size Default_Handler, .-Default_Handler
