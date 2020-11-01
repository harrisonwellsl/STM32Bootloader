#ifndef __NVIC_DRIVER_H__
#define __NVIC_DRIVER_H__

#include <stdint.h>

typedef struct _nvic_reg {
    volatile uint32_t nvic_iser0;
    volatile uint32_t nvic_iser1;
    volatile uint32_t nvic_iser2;
} nvic_reg;

#endif /* __NVIC_DRIVER_H__ */