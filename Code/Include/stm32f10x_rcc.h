#ifndef __STM32F10X_RCC_H__
#define __STM32F10X_RCC_H__

#include <stdint.h>
#include "global_define.h"

/* RCC时钟外设寄存器基地址 */
#define				RCC_REGISTER_BASE               0x40021000

/* RCC时钟控制寄存器基地址 */
#define				RCC_CR                          ((RCC_REGISTER_BASE) + 0x00000000)

/* RCC时钟控制器寄存器功能定义 */
#define             PLL3_UNLOCKED                   0
#define             PLL3_LOCKED                     1
#define             PLL3_OFF                        0
#define             PLL3_ON                         1

#define             PLL2_UNLOCKED                   0
#define             PLL2_LOCKED                     1
#define             PLL2_OFF                        0
#define             PLL2_ON                         1

#define             PLL_UNLOCKED                    0
#define             PLL_LOCKED                      1
#define             PLL_OFF                         0
#define             PLL_ON                          1

#define             CLOCK_DETECTOR_OFF              0
#define             CLOCK_DETECTOR_ON               1            /* 如果外部3-25MHz振荡器就位，则时钟探测开启 */

#define             HSE_3_25_MHZ_OSC_NOT_BY_P       0
#define             HSE_3_25_MHZ_OSC_BY_P           1

#define             HSE_3_25_MHZ_OSC_NOT_RDY        0
#define             HSE_3_25_MHZ_OSC_RDY            1

#define             HSE_OSC_OFF                     0
#define             HSE_OSC_ON                      1

#define             HSI_8_MHZ_NOT_RDY               0
#define             HSI_8_MHZ_RDY                   1

#define             HSI_8MHZ_OSC_OFF                0
#define             HSI_8MHZ_OSC_ON                 1

/* RCC时钟控制寄存器结构体定义 */
typedef struct {
    uint32_t reserved1: 2;
    
    /* PLL3定义 */
    uint32_t pll3rdy: 1;
    uint32_t pll3on: 1;
    
    /* PLL2定义 */
    uint32_t pll2rdy: 1;
    uint32_t pll2on: 1;
    
    /* PLL定义 */
    uint32_t pllrdy: 1;
    uint32_t pllon: 1;
    
    uint32_t reserved2: 4;
    
    /* 时钟安全系统使能 */
    uint32_t csson: 1;
    
    /* 外部高速时钟被旁路 */
    uint32_t hsebyp: 1;
    
    /* 外部高速时钟准备 */
    uint32_t hserdy: 1;
    
    /* 外部高速时钟使能 */
    uint32_t hseon: 1;
    
    /* 内部高速时钟校准，在系统启动时被初始化 */
    uint32_t hsical: 8;
    
    /* 内部时钟调整 */
    uint32_t hsitrim: 5;
    
    uint32_t reserved3: 1;
    
    /* 内部高速时钟就绪位，默认值16，调整8MHz±1% */
    uint32_t hsirdy: 1;
    
    /* 内部高速时钟使能 */
    uint32_t hsion: 1;
} rcc_cr_struct;

/* RCC时钟配置寄存器基地址 */
#define				RCC_CFGR                        (RCC_REGISTER + 0x00000004)
/* RCC时钟中断寄存器基地址 */
#define				RCC_CIR                         (RCC_REGISTER + 0x00000008)
/* APB2外设复位寄存器 */
#define				RCC_APB2RSTR                    (RCC_REGISTER + 0x0000000C)
/* APB1外设复位寄存器 */
#define				RCC_APB1RSTR                    (RCC_REGISTER + 0x00000010)

#endif /* __STM32F10X_RCC_H__ */


