#include "irq_table.h"
#include "imx6ull.h"

struct irq_table_s g_irq_tables[NUMBER_OF_INT_VECTORS];
int irqNesting;


void default_irq_handler(IRQn_Type iar, void *private)
{
    while(1)
    {

    }
    return;
}

int irq_table_init()
{
    int i;
    struct irq_table_s default_irq;

    GIC_Init();
    __set_VBAR(0x87800000);
    irqNesting = 0;

    default_irq.irq_handler = default_irq_handler;
    default_irq.private = NULL;

    for (i = 0; i <NUMBER_OF_INT_VECTORS; i++)
    {
        irq_table_register(i, &default_irq);
    }

    return 0;
}

int irq_table_register(IRQn_Type iar, struct irq_table_s *irq)
{
    if (iar < 0 || iar >= NUMBER_OF_INT_VECTORS)
        return -1;
    if (irq->irq_handler == NULL)
        return -1;

    g_irq_tables[iar] = *irq;

    return 0;
}

void irq_table_run(unsigned int giccIar) 
{
   uint32_t intNum = giccIar & 0x3FFUL;
   
   /* 检查中断号是否符合要求 */
   if ((intNum == 1023) || (intNum >= NUMBER_OF_INT_VECTORS))
   {
	 	return;
   }
 
  __enable_irq();      /* Support nesting interrupt */
   irqNesting++;	/* 中断嵌套计数器加一 */

   /* 根据传递进来的中断号，在irqTable中调用确定的中断服务函数*/
   g_irq_tables[intNum].irq_handler(intNum, g_irq_tables[intNum].private);
 
   irqNesting--;	/* 中断执行完成，中断嵌套寄存器减一 */
  __disable_irq();

}

