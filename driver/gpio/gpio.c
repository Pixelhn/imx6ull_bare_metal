#include "cc.h"
#include "driver/gpio.h"
#include "io/io.h"
#include "irq_table.h"


GPIO_Type *g_GPIO[6] = 
{
    [1] = GPIO1,
    [2] = GPIO2,
    [3] = GPIO3,
    [4] = GPIO4,
    [5] = GPIO5,
};

struct gpio_irq_s
{
    gpio_irq_f  gpio_irq_00_15[16];
    gpio_irq_f  gpio_irq_16_31[16];
};

struct gpio_irq_s g_gpio_irq[6];


void gpio_inter_handler(IRQn_Type iar, void *private)
{

    switch (iar)
    {
        case GPIO1_Combined_0_15_IRQn:
        case GPIO1_Combined_16_31_IRQn:

            break;
        case GPIO2_Combined_0_15_IRQn:
        case GPIO2_Combined_16_31_IRQn:

            break;
        case GPIO3_Combined_0_15_IRQn:
        case GPIO3_Combined_16_31_IRQn:

            break;
        case GPIO4_Combined_0_15_IRQn:
        case GPIO4_Combined_16_31_IRQn:

            break;
        case GPIO5_Combined_0_15_IRQn:
        case GPIO5_Combined_16_31_IRQn:

            break;
    }
}

int gpio_init(uint8_t gpio, uint8_t io, gdir_e gdir,
                                        uint32_t muxRegister,
                                        uint32_t muxMode,
                                        uint32_t inputRegister,
                                        uint32_t inputDaisy,
                                        uint32_t configRegister)
{
    if (gpio > 5 || io > 32)
        return -1;

    gpio_disable_inter(gpio, io);
    
    IOMUXC_SetPinMux(muxRegister, muxMode, inputRegister, inputDaisy, configRegister, 1);

    if (gdir)
    {
        IOMUXC_SetPinConfig(muxRegister, muxMode, inputRegister, inputDaisy, configRegister, DEF_PAD_OUT);  
        g_GPIO[gpio]->GDIR |= (1 << io);
    }
    else
    {
        IOMUXC_SetPinConfig(muxRegister, muxMode, inputRegister, inputDaisy, configRegister, DEF_PAD_IN);
        g_GPIO[gpio]->GDIR &= ~(1 << io);
    }

    return 0;
}

void gpio_write(uint8_t gpio, uint8_t io, int value)
{
    if (gpio > 5 || io > 32)
        return;
    
    if (value)
        g_GPIO[gpio]->DR |= (1 << io);
    else
        g_GPIO[gpio]->DR &= ~(1 << io);

    return; 
}

int gpio_read(uint8_t gpio, uint8_t io)
{
    if (gpio > 5 || io > 32)
        return -1;

    return g_GPIO[gpio]->DR & (1 << io); 
}

int gpio_set_inter(uint8_t gpio, uint8_t io, gpio_interrupt_mode_t mode, gpio_irq_f cb)
{
    volatile uint32_t *icr;
    uint8_t io_tmp = io;
    struct irq_table_s irq;

    if (gpio > 5 || io > 32)
        return -1;
    
    g_GPIO[gpio]->EDGE_SEL &= ~(1U << io);

    if (io < 16)
    {
        g_gpio_irq[gpio].gpio_irq_00_15[io] = cb;

        icr = &g_GPIO[gpio]->ICR1;
    }
    else
    {
        g_gpio_irq[gpio].gpio_irq_16_31[io] = cb;

        icr = &g_GPIO[gpio]->ICR2;
        io_tmp -= 16;
    }

    switch(mode)
    {
        case(kGPIO_IntLowLevel):
            *icr &= ~(3U << (2 * io_tmp));
            break;
        case(kGPIO_IntHighLevel):
            *icr = (*icr & (~(3U << (2 * io_tmp)))) | (1U << (2 * io_tmp));
            break;
        case(kGPIO_IntRisingEdge):
            *icr = (*icr & (~(3U << (2 * io_tmp)))) | (2U << (2 * io_tmp));
            break;
        case(kGPIO_IntFallingEdge):
            *icr |= (3U << (2 * io_tmp));
            break;
        case(kGPIO_IntRisingOrFallingEdge):
            g_GPIO[gpio]->EDGE_SEL |= (1U << io);
            break;
        default:
            break;
    }


    irq.irq_handler = gpio_inter_handler;
    irq.private = 0;
    irq_table_register(GPIO1_Combined_16_31_IRQn, &irq);

    gpio_enable_inter(gpio, io);
    return 0;
}

void gpio_enable_inter(uint8_t gpio, uint8_t io)
{
    if (gpio > 5 || io > 32)
        return;
    
    g_GPIO[gpio]->IMR |= (1U << io);

    return;
}

void gpio_disable_inter(uint8_t gpio, uint8_t io)
{
    if (gpio > 5 || io > 32)
        return;
    
    g_GPIO[gpio]->IMR &= -(1U << io);

    return;
}

int gpio_check_inter(uint8_t gpio, uint8_t io)
{
    return (g_GPIO[gpio]->ISR & (1U << io))? 1: 0;
}

void gpio_clear_inter(uint8_t gpio, uint8_t io)
{
    if (gpio > 5 || io > 32)
        return;
    
    g_GPIO[gpio]->ISR |= (1U << io);

    return;
}