#include "driver/clk.h"
#include "imx6ull.h"

int clk_init()
{
    if (((CCM->CCSR >> 2) & 0x1) == 0)
    {
        CCM->CCSR &= -(CCM_CCSR_STEP_SEL(0));
        CCM->CCSR |= CCM_CCSR_PLL1_SW_CLK_SEL(1);
    }

    CCM_ANALOG->PLL_ARM = CCM_ANALOG_PLL_ARM_ENABLE(1) | CCM_ANALOG_PLL_ARM_DIV_SELECT(88);
    CCM->CCSR &= -CCM_CCSR_PLL1_SW_CLK_SEL(1);
    CCM->CACRR = CCM_CACRR_ARM_PODF(2);
}

void clk_enable()
{
    CCM->CCGR0 = 0XFFFFFFFF;
    CCM->CCGR1 = 0XFFFFFFFF;
    CCM->CCGR2 = 0XFFFFFFFF;
    CCM->CCGR3 = 0XFFFFFFFF;
    CCM->CCGR4 = 0XFFFFFFFF;
    CCM->CCGR5 = 0XFFFFFFFF; 
    CCM->CCGR6 = 0XFFFFFFFF;  
}