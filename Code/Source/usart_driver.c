#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

#include "sys_clk_init.h"
#include "gpio_driver.h"
#include "usart_driver.h"
#include "core_driver.h"
#include "global_define.h"
#include "shell.h"

#define BUFFER_SIZE 64

extern cmd_func_count cmd_array[];

static char buffer[BUFFER_SIZE] = {0};
static int buffer_index = 0;
static int direct_control = 0;
//static int current_size = BUFFER_SIZE;

static void usart_clk_init(void) {
    /* 开启GPIOA的时钟 */
    RCC_REG_PTR->rcc_apb2enr |= (uint32_t)0x00000004;
    /* 开启USART的时钟 */
    RCC_REG_PTR->rcc_apb2enr |= (uint32_t)0x00004000;
    /* 开启管脚复用时钟使能 */
    RCC_REG_PTR->rcc_apb2enr |= (uint32_t)0x00000001;
}

static void usart_pin_init(void) {
    /* USART管脚复用设置 */
    AFIO_REG_PTR->afio_mapr |= (uint32_t)0x00000000;
    /* 设置管脚的输入输出 */
    GPIOA_REG_PTR->gpio_crh &= ~(uint32_t)0x00000FF0;
    /* 设置管脚9为串口输出 */
    GPIOA_REG_PTR->gpio_crh |= (uint32_t)0x000000B0;
    /* 设置管脚10为串口输入 */
    GPIOA_REG_PTR->gpio_crh |= (uint32_t)0x00000800;
}

static void usart_config_init(void) {
    /* 设置串口波特率115200 */
    USART_USE->usart_brr |= 0x00000270;
    /* 设置串口相关的配置 */
    USART_USE->usart_cr1 |= 0x0000200C;
    USART_USE->usart_cr2 |= 0x00000000;
    USART_USE->usart_cr3 |= 0x00000000;
    USART_USE->usart_gtpr |= 0x00000000;
}

static void usart_interrupt_init(void) {
    set_nvic_int(37);
    USART_USE->usart_cr1 |= (uint32_t)0x00000020;
}

void usart_init(void) {
    usart_clk_init();
    usart_pin_init();
    usart_config_init();
    usart_interrupt_init();
}

void stm32UsartPrintf(char *fmt, ...) {
    char buffer[128] = {0};
    int index = 0;
    va_list arg;
    va_start(arg, fmt);
    vsprintf(buffer, fmt, arg);
    va_end(arg);
    for (index = 0; buffer[index] != '\0'; ++index) {
        while ((USART_USE->usart_sr & (uint32_t)0x00000040) == 0);
        USART_USE->usart_dr = buffer[index] & 0xFF;
    }
}

void USART1_IRQHandler(void) {
    buffer[buffer_index] = USART_USE->usart_dr & 0xFF;
    /* 如果收到回车，则说明命令已经输入完毕 */
    if (buffer[buffer_index] == '\r') {
        buffer[buffer_index] = '\0';
        if (strlen(buffer) != 0) {
            INFO("Get from usart: [%s], len = (%d)", buffer, strlen(buffer));
            cmd_parse(buffer);
        }
        buffer_index = 0;
        memset(buffer, 0x0, BUFFER_SIZE);
        stm32UsartPrintf("\r\n--> ");
    } else if (buffer[buffer_index] == 0x8) { /* 退格键的处理 */
        if (buffer_index > 0) {
            stm32UsartPrintf("%c", buffer[buffer_index]);
            stm32UsartPrintf(" ");
            stm32UsartPrintf("%c", buffer[buffer_index]);
            buffer[buffer_index] = '\0';
            buffer[--buffer_index] = '\0';
        }
    } else if (buffer[buffer_index] == '\t') { /* 制表符命令补全 */
        uint32_t index = 0;
        uint32_t count = 0;
        uint8_t array_index[256] = {0};
        buffer[buffer_index] = '\0';
        for (index = 0; cmd_array[index].cmd_func != NULL; ++index) {
            if (strncmp(cmd_array[index].name, buffer, strlen(buffer)) == 0) {
                array_index[count++] = index;
            }
        }
        if (count == 0) {
            ;
        } else if (count == 1) {
            memset(buffer, 0x0, sizeof(buffer));
            strcpy(buffer, cmd_array[array_index[0]].name);
            buffer_index = strlen(buffer);
            stm32UsartPrintf("\r--> %s", buffer);
        } else if (strlen(buffer) == 0) {
            uint32_t index = 0;
            buffer[buffer_index] = '\0';
            stm32UsartPrintf("\r\n");
            for (index = 0; cmd_array[index].cmd_func != NULL; ++index) {
                stm32UsartPrintf("%s\t\t", cmd_array[index].name);
                if ((index + 1) % 3 == 0)
                    stm32UsartPrintf("\r\n");
            }
            stm32UsartPrintf("\r\n--> ");
        } else {
            stm32UsartPrintf("\r\n");
            for (index = 0; index < count; index++) {
                stm32UsartPrintf("%s\t\t", cmd_array[array_index[index]].name);
                if ((index + 1) % 3 == 0)
                    stm32UsartPrintf("\r\n");
            }
            if ((index + 1) % 3 == 0)
                stm32UsartPrintf("\r\n\r--> %s", buffer);
            else
                stm32UsartPrintf("\r--> %s", buffer);
        }
        
    } else if (buffer[buffer_index] == 0x18) { /* 软件复位 */
        /* 复位指令 */
        WARNING("Now reset...");
        __asm(" LDR R0, =0XE000ED0C");
        __asm(" LDR R1, =0X05FA0004");
        __asm(" STR R1, [R0]");
        __asm(" B .");
    } else {
        /* 其余情况下打印收到的字符 */
        stm32UsartPrintf("%c", buffer[buffer_index++]);
    }
        
}
