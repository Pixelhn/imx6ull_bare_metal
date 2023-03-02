#include "board/fire_mini.h"
#include "imx6ull.h"
#include "irq_table.h"
#include "moto.h"

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


int gpio_cb(uint8_t gpio, uint8_t io)
{
    if (GPIO_COMBINED(gpio, io) != GPIO_COMBINED(5, 1))
        return -1;

    if (gpio_read(D4_LED))
    {
        gpio_write(D4_LED, 0);
    }
    else
    {
        gpio_write(D4_LED, 1);
    }

    return 0;
}

int button_init()
{
    struct irq_table_s irq;

    gpio_init(SW2_KEY, 0, IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01);
    gpio_set_inter(SW2_KEY, kGPIO_IntRisingEdge, gpio_cb);
    
    return 0;
}

int main()
{
    int c=0;
    clk_enable();
    clk_init();
    irq_table_init();

    led_init();
    button_init();
    moto_init();


#define DIV 20000

    epit_init(2500, 2199, moto_loop);

    while(1)
    {

        gpio_write(D7_LED, 0);
        //moto_loop();
        delay(500);
        gpio_write(D7_LED, 1);
        //moto_loop();
        delay(500);
    }
}