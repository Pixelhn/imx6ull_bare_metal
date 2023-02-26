#include "board/fire_mini.h"
#include "imx6ull.h"
#include "irq_table.h"

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

    gpio_write(D7_LED, 1);
    gpio_write(D6_LED, 1);
    gpio_write(D5_LED, 1);
    gpio_write(D4_LED, 1);
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

int status2;
int status3;
void irq_hand2(IRQn_Type iar, void *private)
{
    if (gpio_read(4, 26))
    {
        if (status2)
        {
            gpio_write(D5_LED, 1);
            status2 = 0;
        }
        else
        {
            gpio_write(D5_LED, 0);
            status2 = 1;
        }
        gpio_clear_inter(4, 26);
    }

    if (gpio_read(4, 23))
    {
        if (status3)
        {
            gpio_write(D6_LED, 1);
            status3 = 0;
        }
        else
        {
            gpio_write(D6_LED, 0);
            status3 = 1;
        }
        gpio_clear_inter(4, 23);
    }
}

int button_init()
{
    struct irq_table_s irq;

    gpio_init(SW2_KEY, 0, IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01);
    gpio_set_inter(SW2_KEY, kGPIO_IntRisingEdge);

    irq.irq_handler = irq_hand;
    irq.private = 0;
    irq_table_register(GPIO5_Combined_0_15_IRQn, &irq);

    return 0;
    gpio_init(4, 26, 0, IOMUXC_CSI_DATA05_GPIO4_IO26);
    gpio_set_inter(4, 26, kGPIO_IntRisingEdge);

    irq.irq_handler = irq_hand2;
    irq.private = 0;
    irq_table_register(GPIO4_Combined_16_31_IRQn, &irq);
    gpio_enable_inter(4, 26);

    gpio_init(4, 23, 0, IOMUXC_CSI_DATA02_GPIO4_IO23);
    gpio_set_inter(4, 23, kGPIO_IntRisingEdge);

    gpio_enable_inter(4, 23);
}

int main()
{
    int c=0;
    clk_enable();
    //clk_init();
    irq_table_init();

    led_init();
    button_init();

    while(1)
    {

        gpio_write(D7_LED, 0);
        delay(500);
        gpio_write(D7_LED, 1);
        delay(500);
    }
}