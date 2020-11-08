#include "shell.h"

extern cmd_func_count cmd_array[];

void help(void) {
    uint32_t index = 0;
    stm32UsartPrintf("\r\n%-20s-%s", "Ctrl+x", "复位STM32单片机");
    for (index = 0; cmd_array[index].cmd_func != NULL; ++index) {
        stm32UsartPrintf("\r\n%-20s-%s", cmd_array[index].name, cmd_array[index].func_introduce);
    }
}

