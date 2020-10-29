#include "sys_clk_init.h"
#include "flash_driver.h"

void set_sys_clk_to_72(void) {
    rcc_reg *rcc_reg_ptr = (rcc_reg *)((uint32_t)0x40021000);
    flash_reg *flash_reg_ptr = (flash_reg *)((uint32_t)0x40022000);
    
    /* 开启外部高速时钟 */
    rcc_reg_ptr->rcc_cr |= 0x00010000;
    /* 等待外部时钟准备就绪 */
    while ((rcc_reg_ptr->rcc_cr & 0x00020000) == 0);
    
    /* 设置flash的读取时序 */
    flash_reg_ptr->flash_acr &= ~(uint32_t)0x00000007;
    flash_reg_ptr->flash_acr |= (uint32_t)0x00000002;
    
    /* 设置低速外设时钟分频系数 */
    rcc_reg_ptr->rcc_cfgr |= 0x00000400;
    
    /* 选择外部高速时钟作为PLL输入 */
    rcc_reg_ptr->rcc_cfgr |= 0x00010000;
    
    /* 将PLL输入时钟9倍频 */
    rcc_reg_ptr->rcc_cfgr |= 0x001c0000;
    
    /* 选择PLLCLK作为系统时钟输入 */
    rcc_reg_ptr->rcc_cfgr |= 0x00000002;
    
    /* 使能PLL时钟 */
    rcc_reg_ptr->rcc_cr |= 0x01000000;
    
    /* 等待系统时钟稳定 */
    while ((rcc_reg_ptr->rcc_cr & 0x02000000) == 0);
}


