#include <stdio.h>
#include <string.h>
#include <stdlib.h> //exit()
#include <fcntl.h>  //define O_RDWR
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <wiringPi.h>
#include "gpio.hpp"

void init_gpio()
{
    printf("init_gpio: startup\n");
    wiringPiSetup();
    pinMode(25, OUTPUT);
    pinMode(28, OUTPUT);
    pinMode(29, OUTPUT);
}

void pc_startup()
{
    printf("Received request: startup\n");
    digitalWrite(25, LOW);
    usleep(8000 * 1000);
    digitalWrite(25, HIGH);
    printf("Operation successed: startup\n");
}

void pc_shutdown()
{
    printf("Received request: shutdown\n");
    digitalWrite(25, LOW);
    usleep(8000 * 1000);
    digitalWrite(25, HIGH);
    printf("Operation successed: shutdown\n");
}

void pc_reboot()
{
    printf("Received request: reboot\n");
    digitalWrite(28, LOW);
    usleep(300 * 1000);
    digitalWrite(28, HIGH);
    printf("Operation successed: reboot\n");
}