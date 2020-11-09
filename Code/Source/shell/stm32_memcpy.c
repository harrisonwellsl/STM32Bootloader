#include "shell.h"

void *stm32_memcpy(uint32_t arg_addr) {
    char in_args[5][32] = {0};
    memcpy(in_args, (void *)arg_addr, 5 * 32);
    uint32_t dst_addr = strtoul(in_args[1], 0, 0);
    uint32_t src_addr = strtoul(in_args[2], 0, 0);
    uint32_t count = strtoul(in_args[3], 0, 0);
    return memcpy((void *)dst_addr, (const void *)src_addr, count);
}

