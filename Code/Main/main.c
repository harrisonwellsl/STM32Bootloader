#include <stdint.h>

#include "app.h"

uint32_t app_run_flag = 0;

int main()
{
    while (1) {
        if (app_run_flag) {
            app_run_flag = 0;
            app();
        }
    }
	return 0;
}



