#include "button.h"
#include "imx6ull_fire_mini.h"
#include "irq_table.h"

void button_init()
{
    //时钟
    CCM->CCGR1 |= CCM_CCGR1_CG15(CCGR_OPEN_MODE);

    //引脚复用
    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 1);

    //引脚属性
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, \
    IOMUXC_SNVS_SW_PAD_CTL_PAD_SRE(0X0) | \
    IOMUXC_SNVS_SW_PAD_CTL_PAD_DSE(0X110) | \
    IOMUXC_SNVS_SW_PAD_CTL_PAD_SPEED(0X10) | \
    IOMUXC_SNVS_SW_PAD_CTL_PAD_ODE(0X0) | \
    IOMUXC_SNVS_SW_PAD_CTL_PAD_PKE(0X0) | \
    IOMUXC_SNVS_SW_PAD_CTL_PAD_HYS(0X1) );

    //GPIO属性
    GPIO5->GDIR &= ~(1 << 1);
}

uint32_t button_get()
{
    return (GPIO5->DR) & (1<<1);
}