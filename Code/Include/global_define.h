#ifndef __GLOBAL_DEFINE_H__
#define __GLOBAL_DEFINE_H__

#include <stdint.h>

#define             STATUS                                  int
#define             OK                                      (0)
#define             ERROR                                   (-1)

/* 置位宏定义 */
#define             BIT_VAL_SET(reg_addr, p_val)            do { \
                                                                *(uint32_t *)reg_addr = *(uint32_t *)p_val | *(uint32_t *)reg_addr; \
                                                            }while(0)
/* 清除位宏定义 */
#define             BIT_VAL_RESET(reg_addr, p_val)          do { \
                                                                *(uint32_t *)reg_addr = ~(*(uint32_t *)p_val) & (*(uint32_t *)reg_addr); \
                                                            }while(0)

#endif /* __GLOBAL_DEFINE_H__ */



