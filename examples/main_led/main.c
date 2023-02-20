#include "main.h"

void clk_enable()
{
    CCM_CCGR3 = 0XFFFFFFFF;
}

void mux_set()
{
    MUX_CTL_PAD_CSI_HSYNC = 0x5;
}

void pad_set()
{
    PAD_CTL_PAD_CSI_HSYNC = 0X10B0;
}

void gpio_init()
{
    GPIO4_GDIR |= (1 << 20);
}

void gpio_set(int val)
{
    if(val)
        GPIO4_DR |= (1 << 20);
    else
        GPIO4_DR &= ~(1 << 20); 
}

void delay_s(volatile unsigned int n)
{
    while (n--)
    {

    }
}

void delay(volatile unsigned int n)
{
    while (n--)
    {
        delay_s(0x7FF);
    }
}

int main()
{
    clk_enable();
    mux_set();
    pad_set();
    gpio_init();

    while(1)
    {
        gpio_set(0);
        delay(500);

        gpio_set(1);
        delay(500);
    }
}