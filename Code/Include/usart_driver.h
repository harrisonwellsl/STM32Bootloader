#ifndef __USART_DRIVER_H__
#define __USART_DRIVER_H__

#include <stdint.h>

typedef struct _usart_reg {
    volatile uint32_t usart_sr;
    volatile uint32_t usart_dr;
    volatile uint32_t usart_brr;
    volatile uint32_t usart_cr1;
    volatile uint32_t usart_cr2;
    volatile uint32_t usart_cr3;
    volatile uint32_t usart_gtpr;
} usart_reg;

#define USART1_REG_PTR ((uint32_t)0x40013800)
#define USART2_REG_PTR ((uint32_t)0x40004400)
#define USART3_REG_PTR ((uint32_t)0x40004800)
#define USART4_REG_PTR ((uint32_t)0x40004C00)
#define USART5_REG_PTR ((uint32_t)0x40005000)

#define USART_USE ((usart_reg *)USART1_REG_PTR)

void usart_init(void);
void stm32UsartPrintf(char *fmt, ...);

#endif /* __USART_DRIVER_H__ */


