#include "moto.h"
#include "imx6ull.h"





int moto_init()
{
    gpio_init(4, 24, 1, IOMUXC_CSI_DATA03_GPIO4_IO24);
    gpio_init(4, 25, 1, IOMUXC_CSI_DATA04_GPIO4_IO25);
    gpio_init(4, 27, 1, IOMUXC_CSI_DATA06_GPIO4_IO27);
    gpio_init(4, 28, 1, IOMUXC_CSI_DATA07_GPIO4_IO28);
}

#if 0
uint8_t p4[4] = 
{
    [0] = 1,
    [1] = 2,
    [2] = 4,
    [3] = 8,
};
int count = 0;

int moto_loop()
{
    uint8_t this = p4[count];
    count++;
    if (count >= 4)
        count = 0;
    gpio_write(4, 24, this & 1);
    gpio_write(4, 25, this & 2);
    gpio_write(4, 27, this & 4);
    gpio_write(4, 28, this & 8);
}

#else

uint8_t p8[8] = 
{
    [0] = 1,    //1000
    [1] = 3,    //1100
    [2] = 2,    //0100
    [3] = 6,    //0110
    [4] = 4,    //0010
    [5] = 12,   //0011
    [6] = 8,    //0001
    [7] = 9,    //1001
};
int count = 0;

void moto_loop()
{
    uint8_t this = p8[count];
    count++;
    if (count >= 8)
        count = 0;
    gpio_write(4, 24, this & 1);
    gpio_write(4, 25, this & 2);
    gpio_write(4, 27, this & 4);
    gpio_write(4, 28, this & 8);
}


#endif


