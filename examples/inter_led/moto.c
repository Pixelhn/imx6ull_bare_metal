#include "moto.h"
#include "imx6ull.h"


int moto_init()
{
    gpio_init(4, 24, 1, IOMUXC_CSI_DATA03_GPIO4_IO24);
    gpio_init(4, 25, 1, IOMUXC_CSI_DATA04_GPIO4_IO25);
    gpio_init(4, 27, 1, IOMUXC_CSI_DATA06_GPIO4_IO27);
    gpio_init(4, 28, 1, IOMUXC_CSI_DATA07_GPIO4_IO28);
}