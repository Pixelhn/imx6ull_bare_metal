#include "driver/clk.h"
#include "imx6ull.h"

int clk_init()
{
    unsigned int reg = 0;

    //PLL1 ARM主频率 792
    if (((CCM->CCSR >> 2) & 0x1) == 0)
    {
        CCM->CCSR &= ~(CCM_CCSR_STEP_SEL(0));
        CCM->CCSR |= CCM_CCSR_PLL1_SW_CLK_SEL(1);
    }

    CCM_ANALOG->PLL_ARM = CCM_ANALOG_PLL_ARM_ENABLE(1) | CCM_ANALOG_PLL_ARM_DIV_SELECT(66);

    CCM->CCSR &= ~CCM_CCSR_PLL1_SW_CLK_SEL(1);
    CCM->CACRR = CCM_CACRR_ARM_PODF(0);

    //PLL2 PFD
    reg = CCM_ANALOG->PFD_528;
    reg &= ~(0X3F3F3F3F); 
    reg |= CCM_ANALOG_PFD_528_PFD3_FRAC(32);      /* PLL2_PFD3=528*18/32=297Mhz */
    reg |= CCM_ANALOG_PFD_528_PFD2_FRAC(18);      /* PLL2_PFD2=528*18/24=396Mhz */
    reg |= CCM_ANALOG_PFD_528_PFD1_FRAC(16);       /* PLL2_PFD1=528*18/16=594Mhz */
    reg |= CCM_ANALOG_PFD_528_PFD0_FRAC(27);       /* PLL2_PFD0=528*18/27=352Mhz */
    CCM_ANALOG->PFD_528=reg;

    //PLL3 PFD
    reg = CCM_ANALOG->PFD_480;
    reg &= ~(0X3F3F3F3F); 
    reg |= CCM_ANALOG_PFD_480_PFD0_FRAC(19);      /* PLL2_PFD3=528*18/32=297Mhz */
    reg |= CCM_ANALOG_PFD_480_PFD0_FRAC(17);      /* PLL2_PFD2=528*18/24=396Mhz */
    reg |= CCM_ANALOG_PFD_480_PFD0_FRAC(16);       /* PLL2_PFD1=528*18/16=594Mhz */
    reg |= CCM_ANALOG_PFD_480_PFD0_FRAC(12);       /* PLL2_PFD0=528*18/27=352Mhz */
    CCM_ANALOG->PFD_528=reg;

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