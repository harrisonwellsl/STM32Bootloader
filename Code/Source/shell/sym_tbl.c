#include "shell.h"

cmd_func_count cmd_array[] = {
    {"help", (func)help, 0, "打印当前帮助信息"},
    {"print_ascii", (func)print_ascii, 0, "打印屏幕ASCII码"},
    {"read_reg", (func)read_reg, 1, "读取指定寄存器的值，例如：read_reg 0x40021000"},
    {"write_reg", (func)write_reg, 2, "向指定寄存器写入值，例如：write_reg 0x40021000 0x100"},
    {"show_mem", (func)show_mem, 3, "打印一段连续内存空间，例如：show_mem 0x40021000 0x10 0x4"},
    {"stm32_memset", (func)stm32_memset, 3, "与C语言标准库函数memset功能相同，设置一段内存的值"},
    {"stm32_memcpy", (func)stm32_memcpy, 3, "与C语言标准库函数memcpy功能相同，拷贝一段内存的值"},
    {"go", (func)go, 0, "运行APP"},
    {"clear", (func)clear, 0, "清除当前屏幕内容"},
    {NULL, NULL, 0, NULL}
};

