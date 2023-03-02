#include "imx6ull.h"
#include "driver/epit.h"
#include "irq_table.h"

#include "board/fire_mini.h"

EPIT_Type *g_epit[3] =
{
    [1] = EPIT1,
    [2] = EPIT2,
};

void epit1_irq_handler(IRQn_Type iar, void *private)
{
    epit_cb cb = (epit_cb)private;
    if (gpio_read(D5_LED))
    {
        gpio_write(D5_LED, 0);
    }
    else
    {
        gpio_write(D5_LED, 1);
    }
    cb();

    EPIT1->SR |= 1<<0;
}

int epit_init(unsigned int value, unsigned int frac, epit_cb cb)
{
    EPIT1->CR = 0;

    EPIT1->CR = (1<<24 | frac << 4 | 1<<3 | 1<<2 | 1<<1);
    EPIT1->LR = value;
    EPIT1->CMPR = 0;

    struct irq_table_s epit_irq;

    epit_irq.irq_handler = epit1_irq_handler;
    epit_irq.private = (void *)cb;
    irq_table_register(EPIT1_IRQn, &epit_irq);

    EPIT1->CR |= EPIT_CR_EN(1);
    return 0;
}


