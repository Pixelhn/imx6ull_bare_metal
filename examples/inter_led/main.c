#include "main.h"
#include "imx6ull_fire_mini.h"

#include "button.h"
#include "irq_table.h"

void clk_enable()
{
    CCM_CCGR3 = 0XFFFFFFFF;
    CCM->CCGR0 = 0XFFFFFFFF;
    CCM->CCGR1 = 0XFFFFFFFF;
    CCM->CCGR2 = 0XFFFFFFFF;
    CCM->CCGR3 = 0XFFFFFFFF;
    CCM->CCGR4 = 0XFFFFFFFF;
    CCM->CCGR5 = 0XFFFFFFFF; 
    CCM->CCGR6 = 0XFFFFFFFF;  
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

uint32_t gpio_get()
{
    return GPIO4_DR & (1 << 20); 
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

void led_init()
{
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO04_GPIO1_IO04, 0);

    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO04_GPIO1_IO04, LED_PAD);
    GPIO1->GDIR |= (1 << 4);
}

int main()
{
    clk_enable();
    mux_set();
    pad_set();
    gpio_init();

    irq_table_init();
    button_init();
    led_init();

    while(1)
    {
        gpio_set(0);
        GPIO1->DR &= ~(1 << 4);
        delay(500);

        gpio_set(1);
        GPIO1->DR |= (1 << 4);
        delay(500);
    }
}