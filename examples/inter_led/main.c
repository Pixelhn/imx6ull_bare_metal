#include "board/fire_mini.h"
#include "imx6ull.h"

#include "irq_table.h"


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
    gpio_init(1, 4, 1, IOMUXC_GPIO1_IO04_GPIO1_IO04);//D4

    gpio_init(4, 20, 1, IOMUXC_CSI_HSYNC_GPIO4_IO20);

    gpio_init(4, 19, 1, IOMUXC_CSI_VSYNC_GPIO4_IO19);

    gpio_init(5, 3, 1, IOMUXC_SNVS_SNVS_TAMPER3_GPIO5_IO03);
}

int button_init()
{
    gpio_init(5, 1, 0, IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01);
}

int main()
{
    int c=0;
    clk_enable();
    irq_table_init();

    button_init();
    led_init();

    while(1)
    {
        if (gpio_read(5, 1))
        {
            while(gpio_read(5, 1));

            if (gpio_read(1, 4))
            {
                gpio_write(1, 4, 0);
                gpio_write(4, 20, 0);
                gpio_write(4, 19, 0);
                gpio_write(5,3, 0);
            }
            else
            {
                gpio_write(1, 4, 1);
                gpio_write(4, 20, 1);
                gpio_write(4, 19, 1);
                gpio_write(5,3, 1);
            }
        }
    }
}