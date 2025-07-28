#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wiringPi.h>
#include "gpio.h"

void init_gpio()
{
    wiringPiSetup();
    pinMode(25, OUTPUT);
    pinMode(28, OUTPUT);
    pinMode(29, OUTPUT);
    printf("Initialized GPIO\n");
}

void pc_startup()
{
    digitalWrite(25, LOW);
    usleep(500000);
    digitalWrite(25, HIGH);
    printf("Command executed successfully: pc_startup\n");
}

void pc_shutdown()
{
    digitalWrite(25, LOW);
    usleep(500000);
    digitalWrite(25, HIGH);
    printf("Command executed successfully: pc_shutdown\n");
}

void pc_reboot()
{
    digitalWrite(28, LOW);
    usleep(1500000);
    digitalWrite(28, HIGH);
    usleep(500000);
    digitalWrite(25, LOW);
    usleep(500000);
    digitalWrite(25, HIGH);
    printf("Command executed successfully: pc_reboot\n");
}
