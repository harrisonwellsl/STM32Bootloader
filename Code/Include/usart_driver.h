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

#endif /* __USART_DRIVER_H__ */


