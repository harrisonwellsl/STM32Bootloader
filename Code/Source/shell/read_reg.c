#include "shell.h"

typedef char (*cmd_after_parse)[5][64];

int read_reg(uint32_t arg_addr) {
    cmd_after_parse in_args = (cmd_after_parse)arg_addr;
    INFO("arg_addr = 0x%08x", arg_addr);
    INFO("%s-%s", in_args[0], in_args[1]);
    uint32_t addr = atoi((const char *)in_args[1]);
    INFO("addr = 0x%08x", addr);
    INFO("Read 0x%08x", *(uint32_t *)addr);
    return 0;
}

