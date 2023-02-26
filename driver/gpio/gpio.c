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

int gpio_init(uint8_t gpio, uint8_t io, uint8_t gdir,
                                        uint32_t muxRegister,
                                        uint32_t muxMode,
                                        uint32_t inputRegister,
                                        uint32_t inputDaisy,
                                        uint32_t configRegister)
{
    if (gpio > 5 || io > 32)
        return -1;
    
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

void gpio_set(uint8_t gpio, uint8_t io, int value)
{
    if (gpio > 5 || io > 32)
        return;
    
    if (value)
        g_GPIO[gpio]->DR |= (1 << io);
    else
        g_GPIO[gpio]->DR &= ~(1 << io);

    return; 
}

int gpio_get(uint8_t gpio, uint8_t io)
{
    if (gpio > 5 || io > 32)
        return -1;

    return g_GPIO[gpio]->DR & (1 << 20); 
}