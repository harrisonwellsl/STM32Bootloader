#include "shell.h"

static char cmd_after_parse[5][64] = {0};

cmd_func_count cmd_array[] = {
    {"help", (func)help, 0, "打印当前帮助信息"},
    {"print_ascii", (func)print_ascii, 0, "打印屏幕ASCII码"},
    {"read_reg", (func)read_reg, 1, "读取寄存器的值"},
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
            if (index > cmd_array[cmd_array_index].arg_count) {
                ERROR("[%s] get too many args.", cmd_array[cmd_array_index].name);
                break;
            }
            return_num = cmd_array[cmd_array_index].cmd_func((uint32_t)cmd_after_parse);
            INFO("return = %d", return_num);
            memset(cmd_after_parse, 0x0, sizeof(cmd_after_parse));
        }
    }
}

