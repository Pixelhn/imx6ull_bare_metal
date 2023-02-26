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
    gpio_init(D4_LED, 1, IOMUXC_GPIO1_IO04_GPIO1_IO04);

    gpio_init(D5_LED, 1, IOMUXC_CSI_HSYNC_GPIO4_IO20);

    gpio_init(D6_LED, 1, IOMUXC_CSI_VSYNC_GPIO4_IO19);

    gpio_init(D7_LED, 1, IOMUXC_SNVS_SNVS_TAMPER3_GPIO5_IO03);
}


int status;
void irq_hand(IRQn_Type iar, void *private)
{
    if (gpio_read(5, 1))
    {
        if (status)
        {
            gpio_write(D4_LED, 1);
            status = 0;
        }
        else
        {
            gpio_write(D4_LED, 0);
            status = 1;
        }
    }

    gpio_clear_inter(SW2_KEY);
}

int button_init()
{
    struct irq_table_s irq;

    gpio_init(SW2_KEY, 0, IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01);
    gpio_set_inter(SW2_KEY, kGPIO_IntRisingOrFallingEdge);

    irq.irq_handler = irq_hand;
    irq.private = NULL;

    irq_table_register(GPIO5_Combined_0_15_IRQn, &irq);
}

int main()
{
    int c=0;
    clk_enable();
    irq_table_init();

    led_init();
    gpio_write(D7_LED, 0);

    button_init();

    while(1)
    {
        gpio_write(4, 20, 0);
        gpio_write(4, 19, 0);
        delay(500);
        gpio_write(4, 20, 1);
        gpio_write(4, 19, 1);
        delay(500);
    }
}