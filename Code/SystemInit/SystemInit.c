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
    stm32UsartPrintf("\r\n");
    stm32UsartPrintf("\r\n===================================");
    stm32UsartPrintf("\r\n====                           ====");
    stm32UsartPrintf("\r\n==  Welcome To The STM32 World!  ==");
    stm32UsartPrintf("\r\n====                           ====");
    stm32UsartPrintf("\r\n===================================");
    stm32UsartPrintf("\r\n");
    stm32UsartPrintf("\r\nShell compile time    %s-%s", __DATE__, __TIME__);
    stm32UsartPrintf("\r\nShell version         %s", "v1.0");
    stm32UsartPrintf("\r\nAuthor                %s", "harrison");
    stm32UsartPrintf("\r\nEmail                 %s", "harrisonwellsl@outlook.com");
    stm32UsartPrintf("\r\n--> ");
}



