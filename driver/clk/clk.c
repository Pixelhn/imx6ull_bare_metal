#include "driver/clk.h"
#include "imx6ull.h"

int pll1_arm()
{
    if (((CCM->CCSR >> 2) & 0x1) == 0)
    {
        CCM->CCSR &= ~(CCM_CCSR_STEP_SEL(0));
        CCM->CCSR |= CCM_CCSR_PLL1_SW_CLK_SEL(1);
    }

    CCM_ANALOG->PLL_ARM = CCM_ANALOG_PLL_ARM_ENABLE(1) | CCM_ANALOG_PLL_ARM_DIV_SELECT(66);

    CCM->CCSR &= ~CCM_CCSR_PLL1_SW_CLK_SEL(1);
    CCM->CACRR = CCM_CACRR_ARM_PODF(0);
}

int pll2_pfd()
{
    unsigned int reg = 0;

    reg = CCM_ANALOG->PFD_528;
    reg &= ~(0X3F3F3F3F); 
    reg |= CCM_ANALOG_PFD_528_PFD3_FRAC(32);      /* PLL2_PFD3=528*18/32=297Mhz */
    reg |= CCM_ANALOG_PFD_528_PFD2_FRAC(24);      /* PLL2_PFD2=528*18/24=396Mhz */
    reg |= CCM_ANALOG_PFD_528_PFD1_FRAC(16);       /* PLL2_PFD1=528*18/16=594Mhz */
    reg |= CCM_ANALOG_PFD_528_PFD0_FRAC(27);       /* PLL2_PFD0=528*18/27=352Mhz */
    CCM_ANALOG->PFD_528=reg;
}

int pll3_pfd()
{
    unsigned int reg = 0;

    reg = CCM_ANALOG->PFD_480;
    reg &= ~(0X3F3F3F3F); 
    reg |= CCM_ANALOG_PFD_480_PFD3_FRAC(19);      /* PLL3_PFD3=480*18/19=454.74Mhz */
    reg |= CCM_ANALOG_PFD_480_PFD2_FRAC(17);      /* PLL3_PFD2=480*18/17=508.24Mhz */
    reg |= CCM_ANALOG_PFD_480_PFD1_FRAC(16);      /* PLL3_PFD1=480*18/16=540Mhz */
    reg |= CCM_ANALOG_PFD_480_PFD0_FRAC(12);      /* PLL3_PFD0=480*18/12=720Mhz */
    CCM_ANALOG->PFD_528=reg;
}

int clk_init()
{
    //PLL1 ARM主频率 792
    pll1_arm();

    //PLL2 PFD
    pll2_pfd();

    //PLL3 PFD
    pll3_pfd();

    //ipg_clk_root
    //pll2_pfd(mux)->(mux)->div3->div2->66Mhz
    MASK_SET(CCM->CBCMR, CCM_CBCMR_PRE_PERIPH_CLK_SEL, 1); //mux

    MASK_SET(CCM->CBCDR, CCM_CBCDR_PERIPH_CLK_SEL, 0); //mux

    MASK_SET(CCM->CBCDR, CCM_CBCDR_AHB_PODF, 2); //div3
    MASK_SET(CCM->CBCDR, CCM_CBCDR_IPG_PODF, 1); //div2
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