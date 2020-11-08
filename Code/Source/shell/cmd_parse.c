#include "shell.h"

static char cmd_after_parse[5][32] = {0};

cmd_func_count cmd_array[] = {
    {"help", (func)help, 0, "打印当前帮助信息"},
    {"print_ascii", (func)print_ascii, 0, "打印屏幕ASCII码"},
    {"read_reg", (func)read_reg, 1, "读取指定寄存器的值，例如：read_reg 0x40021000"},
    {"write_reg", (func)write_reg, 2, "向指定寄存器写入值，例如：write_reg 0x40021000 0x100"},
    {"go", (func)go, 0, "运行APP"},
    {"clear", (func)clear, 0, "清除当前屏幕内容"},
    {NULL, NULL, NULL, NULL}
};

void cmd_parse(char *cmd) {
    int index = 0;
    int cmd_array_index = 0;
    int return_num = 0;
    
    char *p_cmd = strtok(cmd, " ");

    while (p_cmd != NULL) {
        strcpy(cmd_after_parse[index++], p_cmd);
        p_cmd = strtok(NULL, " ");
    }
    index--;
    
    for (cmd_array_index = 0;
         cmd_array[cmd_array_index].cmd_func != NULL;
         cmd_array_index++) {
        if (strcmp(cmd_array[cmd_array_index].name, cmd_after_parse[0]) == 0) {
            if (index != cmd_array[cmd_array_index].arg_count) {
                ERROR("[%s] get wrong args.", cmd_array[cmd_array_index].name);
                break;
            }
            return_num = cmd_array[cmd_array_index].cmd_func((uint32_t)cmd_after_parse);
            INFO("return = 0x%08X, value = %d", return_num, return_num);
            memset(cmd_after_parse, 0x0, sizeof(cmd_after_parse));
        }
    }
}

