#include <stdint.h>
#include "global_define.h"
#include "stm32f10x_rcc.h"

STATUS rcc_cr_val_set(rcc_cr_struct *p_val)
{
    uint32_t *p_val_pri = (uint32_t *)p_val;
    uint32_t *rcc_cr_addr = (uint32_t *)RCC_CR;
    *rcc_cr_addr = *p_val_pri;
    if ((*rcc_cr_addr) == (*p_val_pri)) {
        return OK;
    } else {
        return ERROR;
    }
}


