.global _start

_start:
    # 使能时钟 CCM_CCGR3
    ldr r0, =0X020C4074
    ldr r1, =0XFFFFFFFF
    str r1, [r0]

    # MUX
    ldr r0, =0X020E01DC
    ldr r1, =0X5
    str r1, [r0]

    # PAD
    ldr r0, =0X020E0468
    ldr r1, =0X10B0
    str r1, [r0]

    # GPIO4_GDIR
    ldr r0, =0X020A8004
    ldr r1, =0X80000    //# IO19
    str r1, [r0]

    # GPIO4_DR
    ldr r0, =0X020A8000
    ldr r1, =0          //# IO19低电平
    str r1, [r0]

    # 进入SVC模式
    mrs r0, cpsr
    bic r0, r0, #0X1F   /* 低5位清0 */
    orr r0, r0, #0X13   /* 低5位10011 SVC模式 */
    msr cpsr, r0

    ldr sp, =0X80200000   /* 设置栈指针 */
    b main

loop:
    b loop
