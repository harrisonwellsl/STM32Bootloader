#ifndef __SHELL_H__
#define __SHELL_H__

#include <ctype.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "usart_driver.h"
#include "global_define.h"

typedef int (*func)(uint32_t);

typedef struct _cmd_func_count {
    char *name;
    func cmd_func;
    uint32_t arg_count;
    char *func_introduce;
} cmd_func_count;

void print_ascii(void);
void help(void);
void cmd_parse(char *cmd);
int read_reg(uint32_t arg_addr);
void clear(void);
#endif /* __SHELL_H__ */