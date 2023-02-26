
.arch armv7-a

.global _start

_start:
    ldr     pc, =Reset_Handler  /* Reset                  复位*/
    ldr     pc, =loop           /* Undefined instructions 未定义指令*/
    ldr     pc, =loop           /* Supervisor Call        SWI(Linux系统调用内陷内核)*/
    ldr     pc, =loop           /* Prefetch abort         预取指令出错*/
    ldr     pc, =loop           /* Data abort             数据访问出错*/
    ldr     pc, =loop           /* unused */
    ldr     pc, =IRQ_Handler    /* IRQ interrupt          */
    ldr     pc, =loop           /* FIQ interrupt          快速中断*/

Reset_Handler:

    cpsid   i               /* Mask interrupts */

    /* Reset SCTlr Settings 关闭I D Cache 分支预测，对齐检测 MMU*/
    mrc     p15, 0, r0, c1, c0, 0     /* Read CP15 System Control register                  */
    bic     r0,  r0, #(0x1 << 12)     /* Clear I bit 12 to disable I Cache                  */
    bic     r0,  r0, #(0x1 <<  2)     /* Clear C bit  2 to disable D Cache                  */
    bic     r0,  r0, #0x2             /* Clear A bit  1 to disable strict alignment         */
    bic     r0,  r0, #(0x1 << 11)     /* Clear Z bit 11 to disable branch prediction        */
    bic     r0,  r0, #0x1             /* Clear M bit  0 to disable MMU                      */
    mcr     p15, 0, r0, c1, c0, 0     /* Write value back to CP15 System Control register   */

    /*设置IRQ，SYS的栈指针*/
    cps     #0x12 /* IRQ */
    ldr     sp, =0x80600000

    cps     #0x1F /* SYS */
    ldr     sp, =0x80400000

    cpsie   i                    /*打开IRQ中断*/

    # 进入SVC模式
    mrs r0, cpsr
    bic r0, r0, #0X1F   /* 低5位清0 */
    orr r0, r0, #0X13   /* 低5位10011 SVC模式 */
    msr cpsr, r0

    ldr sp, =0X80200000   /* 设置栈指针 */
    b main

loop:
    ldr r0, =loop
    bx  r0

IRQ_Handler:
    push    {lr}                         /* Save return address+4                                */
    push    {r0-r3, r12}                 /* Push caller save registers                           */

    mrs     r0, spsr                     /* Save SPRS to allow interrupt reentry                 */
    push    {r0}

    mrc     P15, 4, r1, C15, C0, 0       /* Get GIC base address                                 */
    add     r1, r1, #0x2000              /* r1: GICC base address                                */
    ldr     r0, [r1, #0xC]               /* r0: IAR                                              */

    push    {r0, r1}

    cps     #0x13                        /* Change to Supervisor mode to allow interrupt reentry */

    push    {lr}                         /* Save Supervisor lr                                   */
    ldr     r2, =irq_table_run
    blx     r2                           /* Call SystemIrqHandler with param GCC                 */
    pop     {lr}

    cps     #0x12                        /* Back to IRQ mode                                     */

    pop     {r0, r1}

    str     r0, [r1, #0x10]              /* Now IRQ handler finished: write to EOIR              */

    pop     {r0}
    msr     spsr_cxsf, r0

    pop     {r0-r3, r12}
    pop     {lr}
    subs    pc, lr, #4
