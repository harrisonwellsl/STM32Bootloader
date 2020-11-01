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

#define USART1 ((uint32_t)0x40013800)
#define USART2 ((uint32_t)0x40004400)
#define USART3 ((uint32_t)0x40004800)
#define USART4 ((uint32_t)0x40004C00)
#define USART5 ((uint32_t)0x40005000)

#define USART ((usart_reg *)USART1)

void usart_init(void);
void stm32UsartPrintf(char *fmt, ...);

#endif /* __USART_DRIVER_H__ */


