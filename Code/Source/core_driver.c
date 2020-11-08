#include "core_driver.h"

void set_nvic_parity(void) {
    SCB_REG_PTR->scb_aircr |= ((uint32_t)0x05FA0000) | ((uint32_t)0x700);
}

void set_nvic_int(uint32_t irq_num) {
    NVIC_REG_PTR->nvic_iser[irq_num >> 0x05] = (uint32_t)0x01 << (irq_num & (uint8_t)0x1F);
}
