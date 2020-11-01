#include "SystemInit.h"

#include "usart_driver.h"

void SystemInit()
{
	set_sys_clk_to_72();
    usart_init();
}



