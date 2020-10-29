#ifndef __SYS_CLK_INIT_H__
#define __SYS_CLK_INIT_H__

#include <stdint.h>

#include "global_define.h"

typedef struct _rcc_reg {
    volatile uint32_t rcc_cr;
    volatile uint32_t rcc_cfgr;
    volatile uint32_t rcc_cir;
    volatile uint32_t rcc_apb2rstr;
    volatile uint32_t rcc_apb1rstr;
    volatile uint32_t rcc_ahbenr;
    volatile uint32_t rcc_apb2enr;
    volatile uint32_t rcc_apb1enr;
    volatile uint32_t rcc_bdcr;
    volatile uint32_t rcc_csr;
} rcc_reg;


void set_sys_clk_to_72(void);

#endif /* __SYS_CLK_INIT_H__ */

