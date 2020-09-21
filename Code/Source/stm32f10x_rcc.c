#include <stdint.h>
#include "global_define.h"
#include "stm32f10x_rcc.h"

STATUS rcc_cr_val_set(rcc_cr_struct *p_val)
{
    *(uint32_t *)RCC_CR = *(uint32_t *)p_val | *(uint32_t *)RCC_CR;
    if (((*(uint32_t *)RCC_CR) & (~(*(uint32_t *)p_val))) == 0) {
        return OK;
    } else {
        return ERROR;
    }
}


