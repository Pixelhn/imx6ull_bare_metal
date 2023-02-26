#include "cc.h"
#include "driver/gpio.h"
#include "io/io.h"


GPIO_Type *g_GPIO[6] = 
{
    [1] = GPIO1,
    [2] = GPIO2,
    [3] = GPIO3,
    [4] = GPIO4,
    [5] = GPIO5,
};

#define DEF_PAD_OUT (SRE_SLOW | DSE_6_R0_6 | SPEED_100 | ODE_DISABL | PKE_ENABLE | PUE_DOUP | PUS_100_DOWN | HYS_DISABL)
#define DEF_PAD_IN  (SRE_SLOW | DSE_6_R0_6 | SPEED_100 | ODE_DISABL | PKE_DISABL | PUE_DOUP | PUS_100_DOWN | HYS_ENABLE)

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

int gpio_set_inter(uint8_t gpio, uint8_t io, gpio_interrupt_mode_t mode)
{
    volatile uint32_t icr;
    uint8_t io_tmp = io;

    if (gpio > 5 || io > 32)
        return -1;
    
    g_GPIO[gpio]->EDGE_SEL &= ~(1U << io);

    if (io < 16)
    {
        icr = g_GPIO[gpio]->ICR1;
    }
    else
    {
        icr = g_GPIO[gpio]->ICR2;
        io_tmp -= 16;
    }

    switch(mode)
    {
        case(kGPIO_IntLowLevel):
            icr &= ~(3U << (2 * io_tmp));
            break;
        case(kGPIO_IntHighLevel):
            icr = (icr & (~(3U << (2 * io_tmp)))) | (1U << (2 * io_tmp));
            break;
        case(kGPIO_IntRisingEdge):
            icr = (icr & (~(3U << (2 * io_tmp)))) | (2U << (2 * io_tmp));
            break;
        case(kGPIO_IntFallingEdge):
            icr |= (3U << (2 * io_tmp));
            break;
        case(kGPIO_IntRisingOrFallingEdge):
            g_GPIO[gpio]->EDGE_SEL |= (1U << io);
            break;
        default:
            break;
    }

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
    if (gpio > 5 || io > 32)
        return;
    
    g_GPIO[gpio]->ISR |= (1U << io);

    return;
}