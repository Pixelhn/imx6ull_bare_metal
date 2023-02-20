#ifndef __MAIN_H__
#define __MAIN_H__

#define REGISTER(r) *((volatile unsigned int *)r)

#define CCM_CCGR3 *((volatile unsigned int *)0x020C4068)


#define MUX_CTL_PAD_CSI_HSYNC *((volatile unsigned int *)0x020E01E0)
#define PAD_CTL_PAD_CSI_HSYNC *((volatile unsigned int *)0X020E046C)

#define GPIO4_GDIR  REGISTER(0x020A8004)
#define GPIO4_DR    REGISTER(0x020A8000)


#endif