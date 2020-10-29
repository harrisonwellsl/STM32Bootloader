#ifndef __FLASH_DRIVER_H__
#define __FLASH_DRIVER_H__

#include <stdint.h>

typedef struct _flash_reg {
    volatile uint32_t flash_acr;
    volatile uint32_t flash_keyr;
    volatile uint32_t flash_optkeyr;
    volatile uint32_t flash_sr;
    volatile uint32_t flash_cr;
    volatile uint32_t flash_ar;
    volatile uint32_t resv;
    volatile uint32_t flash_obr;
    volatile uint32_t flash_wrpr;
} flash_reg;

#endif /* __FLASH_DRIVER_H__ */



