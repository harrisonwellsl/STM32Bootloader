#ifndef __GPIO_DRIVER_H__
#define __GPIO_DRIVER_H__

#include <stdint.h>

typedef struct _gpio_reg {
    volatile uint32_t gpio_crl;
    volatile uint32_t gpio_crh;
    volatile uint32_t gpio_idr;
    volatile uint32_t gpio_odr;
    volatile uint32_t gpio_bsrr;
    volatile uint32_t gpio_brr;
    volatile uint32_t gpio_lckr;
} gpio_reg;

typedef struct _afio_reg {
    volatile uint32_t afio_evcr;
    volatile uint32_t afio_mapr;
    volatile uint32_t afio_exticr1;
    volatile uint32_t afio_exticr2;
    volatile uint32_t afio_exticr3;
    volatile uint32_t afio_exticr4;
    volatile uint32_t afio_mapr2;
} afio_reg;

#define GPIOA ((gpio_reg *)(uint32_t)0x40010800)
#define GPIOB ((gpio_reg *)(uint32_t)0x40010C00)
#define GPIOC ((gpio_reg *)(uint32_t)0x40011000)
#define GPIOD ((gpio_reg *)(uint32_t)0x40011400)
#define GPIOE ((gpio_reg *)(uint32_t)0x40011800)
#define GPIOF ((gpio_reg *)(uint32_t)0x40011C00)
#define GPIOG ((gpio_reg *)(uint32_t)0x40012000)

#define AFIO ((afio_reg *)(uint32_t)0x40010000)

#endif /* __GPIO_DRIVER_H__ */