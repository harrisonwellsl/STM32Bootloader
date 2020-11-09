#include "shell.h"

int write_reg(uint32_t arg_addr) {
    char in_args[5][32] = {0};
    memcpy(in_args, (void *)arg_addr, 5 * 32);
    uint32_t addr = strtoul(in_args[1], 0, 0);
    uint32_t value = strtoul(in_args[2], 0, 0);
    *(uint32_t *)addr = value;
    return value;
}

