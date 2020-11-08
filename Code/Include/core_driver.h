#ifndef __NVIC_DRIVER_H__
#define __NVIC_DRIVER_H__

#include <stdint.h>

typedef struct _nvic_reg {
    volatile uint32_t nvic_iser[3];
    uint32_t resv0[29];
    volatile uint32_t nvic_icer[3];
    uint32_t resv1[94];
    volatile uint32_t nvic_ispr[3];
    uint32_t resv2[29];
    volatile uint32_t nvic_icpr[3];
} nvic_reg;

#define NVIC_REG_PTR ((nvic_reg *)(uint32_t)0xE000E100)

typedef struct _scb_reg {
    volatile uint32_t scb_cpuid;
    volatile uint32_t scb_icsr;
    volatile uint32_t scb_vtor;
    volatile uint32_t scb_aircr;
    volatile uint32_t scb_scr;
    volatile uint32_t scb_ccr;
    volatile uint32_t scb_shpr1;
} scb_reg;

#define SCB_REG_PTR ((scb_reg *)(uint32_t)0xE000ED00)

void set_nvic_parity(void);
void set_nvic_int(uint32_t irq_num);

#endif /* __NVIC_DRIVER_H__ */


