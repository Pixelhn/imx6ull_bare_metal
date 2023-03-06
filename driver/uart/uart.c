#include "cc.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include "io/io.h"


/*
* @description : 关闭指定的 UART
* @param – base : 要关闭的 UART
* @return : 无
*/
void uart_disable(UART_Type *base)
{
    base->UCR1 &= ~(1<<0); 
}

/*
* @description : 打开指定的 UART
* @param – base : 要打开的 UART
* @return : 无
*/
void uart_enable(UART_Type *base)
{
    base->UCR1 |= (1<<0); 
}

/*
* @description : 复位指定的 UART
* @param – base : 要复位的 UART
* @return : 无
*/
void uart_softreset(UART_Type *base)
{
    base->UCR2 &= ~(1<<0); /* 复位 UART */
    while((base->UCR2 & 0x1) == 0); /* 等待复位完成 */
}

int uart_init()
{
    IOMUXC_SetPinMux(IOMUXC_UART1_TX_DATA_UART1_TX, 0);
    IOMUXC_SetPinMux(IOMUXC_UART1_RX_DATA_UART1_RX, 0);

    IOMUXC_SetPinConfig(IOMUXC_UART1_TX_DATA_UART1_TX, SRE_SLOW | ODE_DISABL | HYS_DISABL | PKE_DISABL | DSE_6_R0_6 | SPEED_100);
    IOMUXC_SetPinConfig(IOMUXC_UART1_RX_DATA_UART1_RX, SRE_SLOW | ODE_DISABL | HYS_DISABL | PKE_DISABL | DSE_6_R0_6 | SPEED_100);

    uart_disable(UART1);
    uart_softreset(UART1);

    UART1->UCR1 = 0;
    UART1->UCR1 &= ~(1 << 14);

/*
* 设置 UART 的 UCR2 寄存器，设置字长，停止位，校验模式，关闭硬件流控
* bit14: 1 忽略 RTS 引脚
* bit8: 0 关闭奇偶校验
* bit6: 0 1 位停止位
* bit5: 1 8 位数据位
* bit2: 1 打开发送
* bit1: 1 打开接收
*/
    UART1->UCR2 |= (1<<14) | (1<<5) | (1<<2) | (1<<1);
    UART1->UCR3 |= 1<<2; /* UCR3 的 bit2 必须为 1 */

    UART1->UFCR = 5<<7;
    UART1->UBIR = 71;
    UART1->UBMR = 3124;

    uart_enable(UART1);

    return 0;
}

void uart_putc(unsigned char c)
{
    while(((UART1->USR2 >> 3) &0X01) == 0);/* 等待上一次发送完成 */
    UART1->UTXD = c & 0XFF; /* 发送数据 */
}

/*
* @description : 发送一个字符串
* @param - str : 要发送的字符串
* @return : 无
*/
void uart_puts(char *str)
{
    char *p = str;

    while(*p)
    uart_putc(*p++);
}

/*
* @description : 接收一个字符
* @param : 无
* @return : 接收到的字符
*/
unsigned char uart_getc(void)
{
    while((UART1->USR2 & 0x1) == 0); /* 等待接收完成 */
    return UART1->URXD; /* 返回接收到的数据 */
}