.global _start

# IOMUXC_CSI_VSYNC_GPIO4_IO19
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

loop:
    b loop
