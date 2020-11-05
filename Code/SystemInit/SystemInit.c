#include "SystemInit.h"

#include "global_define.h"
#include "usart_driver.h"
#include "core_driver.h"
#include "shell.h"

void SystemInit()
{
	set_sys_clk_to_72();
    set_nvic_parity();
    usart_init();
    print_ascii();
    INFO("Shell compile time    %s-%s", __DATE__, __TIME__);
    INFO("Shell version         %s", "v1.0");
    stm32UsartPrintf("\r\n--> ");
}



