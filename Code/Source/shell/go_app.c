#include "shell.h"

extern uint32_t app_run_flag;

void go(void) {
    INFO("AppRun....");
    app_run_flag = 1;
}

