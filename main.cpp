#include <stdio.h>
#include "demo.hpp"
// #include "gpio.hpp"
int main()
{
	printf("Remote controll is startup!!!\n");
	test();
	// init_gpio();
	// pc_startup();
	printf("Remote controll is shutdown!!!\n");
	return 0;
}
