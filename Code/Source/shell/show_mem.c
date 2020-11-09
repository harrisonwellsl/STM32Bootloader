#include "shell.h"

void show_mem(uint32_t arg_addr) {
    char in_args[5][32] = {0};
    memcpy(in_args, (void *)arg_addr, 5 * 32);
    uint32_t addr = strtoul(in_args[1], 0, 0);
    uint32_t count = strtoul(in_args[2], 0, 0);
    uint32_t bytes = strtoul(in_args[3], 0, 0);
    uint32_t index = 0;
    uint32_t count_line = 0;
    if (bytes == 1) {
        stm32UsartPrintf("\r\n");
        for (index = 0; index < count; ++index) {
            if (count_line % 8 == 0)
                stm32UsartPrintf("0x%08X:  ", addr);
            addr += index;
            stm32UsartPrintf("0x%02X  ", *(uint8_t *)(addr));
            if ((count_line + 1) % 8 == 0)
                stm32UsartPrintf("\r\n");
            count_line++;
        }
    } else if (bytes == 2) {
        stm32UsartPrintf("\r\n");
        for (index = 0; index < count; index += 2) {
            if (count_line % 6 == 0)
                stm32UsartPrintf("0x%08X:  ", addr);
            addr += index;
            stm32UsartPrintf("0x%04X    ", *(uint16_t *)(addr));
            if ((count_line + 1) % 6 == 0)
                stm32UsartPrintf("\r\n");
            count_line++;
        }
    } else if (bytes == 4) {
        stm32UsartPrintf("\r\n");
        for (index = 0; index < count; index += 4) {
            if (count_line % 3 == 0)
                stm32UsartPrintf("0x%08X:  ", addr);
            addr += index;
            stm32UsartPrintf("0x%08X    ", *(uint32_t *)(addr));
            if ((count_line + 1) % 3 == 0)
                stm32UsartPrintf("\r\n");
            count_line++;
        }
    } else {
        ERROR("Wrong argument.");
    }
}


