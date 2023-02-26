#ifndef __IRQ_TABLE_H__
#define __IRQ_TABLE_H__

#include "imx6ull.h"

typedef void (*irq_handler_f)(IRQn_Type iar, void *private);

struct irq_table_s
{
    irq_handler_f   irq_handler;
    void *          private;
};

int irq_table_init();

int irq_table_register(IRQn_Type iar, struct irq_table_s *irq);


#endif