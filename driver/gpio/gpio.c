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
    int         irq_id[2];
    gpio_irq_f  gpio_irq_00_15[16];
    gpio_irq_f  gpio_irq_16_31[16];
};

struct gpio_irq_s g_gpio_irq[6] = 
{
    [1].irq_id = {[0] = GPIO1_Combined_0_15_IRQn, [1] = GPIO1_Combined_16_31_IRQn},
    [2].irq_id = {[0] = GPIO2_Combined_0_15_IRQn, [1] = GPIO2_Combined_16_31_IRQn},
    [3].irq_id = {[0] = GPIO3_Combined_0_15_IRQn, [1] = GPIO3_Combined_16_31_IRQn},
    [4].irq_id = {[0] = GPIO4_Combined_0_15_IRQn, [1] = GPIO4_Combined_16_31_IRQn},
    [5].irq_id = {[0] = GPIO5_Combined_0_15_IRQn, [1] = GPIO5_Combined_16_31_IRQn},
};


void gpio_inter_handler(IRQn_Type iar, void *private)
{
    uint8_t gpio, io;
    gpio_irq_f *p = (gpio_irq_f *)private;
    int ret;

    switch (iar)
    {
        case GPIO1_Combined_0_15_IRQn:
        case GPIO1_Combined_16_31_IRQn:
            gpio = 1;
            break;
        case GPIO2_Combined_0_15_IRQn:
        case GPIO2_Combined_16_31_IRQn:
            gpio = 2;
            break;
        case GPIO3_Combined_0_15_IRQn:
        case GPIO3_Combined_16_31_IRQn:
            gpio = 3;
            break;
        case GPIO4_Combined_0_15_IRQn:
        case GPIO4_Combined_16_31_IRQn:
            gpio = 4;
            break;
        case GPIO5_Combined_0_15_IRQn:
        case GPIO5_Combined_16_31_IRQn:
            gpio = 5;
            break;
        default:
            //error
            return;
    }

    for (io = 0; io < 16; io++)
    {
        if (p[io])
            ret = p[io](gpio, io);
        if (ret == 0)
            gpio_clear_inter(gpio, io);
    }

    return;
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
    int irq_id;

    if (gpio > 5 || io > 32)
        return -1;
    
    g_GPIO[gpio]->EDGE_SEL &= ~(1U << io);
    irq.irq_handler = gpio_inter_handler;

    if (io < 16)
    {
        g_gpio_irq[gpio].gpio_irq_00_15[io_tmp] = cb;
        irq.private = (void *)g_gpio_irq[gpio].gpio_irq_00_15;
        irq_id = g_gpio_irq[gpio].irq_id[0];

        icr = &g_GPIO[gpio]->ICR1;
    }
    else
    {
        io_tmp -= 16;

        g_gpio_irq[gpio].gpio_irq_16_31[io_tmp] = cb;
        irq.private = (void *)g_gpio_irq[gpio].gpio_irq_16_31;
        irq_id = g_gpio_irq[gpio].irq_id[1];

        icr = &g_GPIO[gpio]->ICR2;
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

    irq_table_register(irq_id, &irq);
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

void gpio_clear_inter(uint8_t gpio, uint8_t io)
{
    g_GPIO[gpio]->ISR |= (1U << io);

    return;
}