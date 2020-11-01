#include <stdarg.h>
#include <stdio.h>

#include "sys_clk_init.h"
#include "gpio_driver.h"
#include "usart_driver.h"

static void usart_clk_init(void) {
    /* 开启GPIOA的时钟 */
    RCC_REG_PTR->rcc_apb2enr |= (uint32_t)0x00000004;
    /* 开启USART的时钟 */
    RCC_REG_PTR->rcc_apb2enr |= (uint32_t)0x00004000;
    /* 开启管脚复用时钟使能 */
    RCC_REG_PTR->rcc_apb2enr |= (uint32_t)0x00000001;
}

static void usart_pin_init(void) {
    /* USART管脚复用设置 */
    AFIO->afio_mapr |= (uint32_t)0x00000000;
    /* 设置管脚的输入输出 */
    GPIOA->gpio_crh &= ~(uint32_t)0x00000FF0;
    /* 设置管脚9为串口输出 */
    GPIOA->gpio_crh |= (uint32_t)0x000000B0;
    /* 设置管脚10为串口输入 */
    GPIOA->gpio_crh |= (uint32_t)0x00000800;
}

static void usart_config_init(void) {
    /* 设置串口波特率115200 */
    USART->usart_brr |= 0x00000270;
    /* 设置串口相关的配置 */
    USART->usart_cr1 |= 0x0000200C;
    USART->usart_cr2 |= 0x00000000;
    USART->usart_cr3 |= 0x00000000;
    USART->usart_gtpr |= 0x00000000;
}

void usart_init(void) {
    usart_clk_init();
    usart_pin_init();
    usart_config_init();
}

void stm32UsartPrintf(char *fmt, ...) {
    char buffer[128] = {0};
    int index = 0;
    va_list arg;
    va_start(arg, fmt);
    vsprintf(buffer, fmt, arg);
    va_end(arg);
    for (index = 0; buffer[index] != '\0'; ++index) {
        while ((USART->usart_sr & (uint32_t)0x00000040) == 0);
        USART->usart_dr = buffer[index] & 0xFF;
    }
}

void USART1_IRQHandler(void) {
    
}
