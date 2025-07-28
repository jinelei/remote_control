#include <stdio.h>
#include <wiringPi.h>
#include "ttp.h"
#include "gpio.h"

int main(int argc, char *argv[])
{
    int run_mode = 0;

    if (argc != 2)
    {
        fprintf(stderr, "Remote controll: run with [-s] [startup] [shutdown] [reboot]");
	return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-s") == 0) {
            run_mode = 1;
	} else if (strcmp(argv[i], "startup") == 0) {
            run_mode = 2;
	} else if (strcmp(argv[i], "shutdown") == 0) {
            run_mode = 3;
	} else if (strcmp(argv[i], "reboot") == 0) {
            run_mode = 4;
        } else {
            fprintf(stderr, "Remote controll: run with unknown commond: '%s'\n", argv[i]);
            return 1;
	}
    }

    // 判断模式并执行相应操作
    switch (run_mode)
    {
	case 1:
            init_gpio();
            printf("Remote controll: run on service mode!!!\n");
            init_ttp();
            run_ttp();
	    break;
	case 2:
            init_gpio();
            printf("Remote controll: run with command startup!!!\n");
            pc_startup();
	    break;
	case 3:
            init_gpio();
            printf("Remote controll: run with command shutdown!!!\n");
            pc_shutdown();
	    break;
	case 4:
            init_gpio();
            printf("Remote controll: run with command reboot!!!\n");
            pc_reboot();
	    break;
	default:
	    break;
    }

    return 0;
}
