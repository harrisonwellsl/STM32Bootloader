#ifndef __GLOBAL_DEFINE_H__
#define __GLOBAL_DEFINE_H__

#include "usart_driver.h"

#define INFO(fmt, ...) stm32UsartPrintf(\
                       "\r\n[\033[36mINFO\033[0m] \033[4m%s\033[0m: %d " \
                       fmt, __func__, __LINE__, ##__VA_ARGS__)
                                        
#define WARNING(fmt, ...) stm32UsartPrintf(\
                          "\r\n[\033[33mWARNING\033[0m] \033[4m%s\033[0m: %d " \
                          fmt, __func__, __LINE__, ##__VA_ARGS__)
                          
#define ERROR(fmt, ...) stm32UsartPrintf(\
                          "\r\n[\033[31mERROR\033[0m] \033[4m%s\033[0m: %d " \
                          fmt, __func__, __LINE__, ##__VA_ARGS__)

#endif /* __GLOBAL_DEFINE_H__ */



