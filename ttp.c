#include <stdio.h>
#include <wiringPiI2C.h>
#include <unistd.h>
#include "ttp.h"
#include "gpio.h"

int fd;
int device_addr = 0x57;  // I2C设备地址

void handle_KEY_UP(void) { printf("向上\n"); }
void handle_KEY_DOWN(void) { printf("向下\n"); }
void handle_KEY_LEFT(void) { printf("向左\n"); }
void handle_KEY_RIGHT(void) { printf("向右\n"); }

void handle_KEY_CIRCLE(void) { printf("圆\n"); }
void handle_KEY_CROSS(void) { printf("叉\n"); }
void handle_KEY_TRIANGLE(void) { printf("三角\n"); }
void handle_KEY_SQUARE(void) { printf("矩形\n"); }

void handle_KEY_L(void) { printf("L\n"); }
void handle_KEY_R(void) { printf("R\n"); }
void handle_KEY_START(void) { printf("开始\n"); }
void handle_KEY_SELECT(void) { printf("选择\n"); }
void handle_KEY_HOME(void) { printf("主页\n"); }
void handle_KEY_POWER(void) { pc_startup(); }
void handle_KEY_RASPBERRY(void) { printf("树莓派\n"); }
void handle_KEY_LOGO(void) { printf("微雪\n"); }

// 静态映射表（自动生成）
KeyMapEntry key_map[] = {
    {KEY_UP, handle_KEY_UP},
    {KEY_DOWN, handle_KEY_DOWN},
    {KEY_LEFT, handle_KEY_LEFT},
    {KEY_RIGHT, handle_KEY_RIGHT},

    {KEY_CIRCLE, handle_KEY_CIRCLE},
    {KEY_CROSS, handle_KEY_CROSS},
    {KEY_TRIANGLE, handle_KEY_TRIANGLE},
    {KEY_SQUARE, handle_KEY_SQUARE},

    {KEY_L, handle_KEY_L},
    {KEY_R, handle_KEY_R},

    {KEY_START, handle_KEY_START},
    {KEY_SELECT, handle_KEY_SELECT},
    {KEY_HOME, handle_KEY_HOME},
    {KEY_POWER, handle_KEY_POWER},
    {KEY_RASPBERRY, handle_KEY_RASPBERRY},
    {KEY_LOGO, handle_KEY_LOGO},

    {0, NULL}  // 结束标记
};

void handle_key(int key) {
    for (int i = 0; key_map[i].callback != NULL; i++) {
        if ((key_map[i].key & key) > 0) {
            key_map[i].callback();
        }
    }
}

void init_ttp()
{
    // 初始化I2C
    if ((fd = wiringPiI2CSetup(device_addr)) < 0) {
        fprintf(stderr, "Failed to initialize I2C");
        return;
    }
    printf("Initialized I2C\n");
}

void run_ttp()
{
    while (1)
    {
	uint8_t result = 0x00;
        wiringPiI2CRawRead(fd, &result, 2);
	int value = (((result >> 8) & 0x000000FF) | ((result << 8) & 0x0000FF00)) & 0x0000FFFF;
        if (value != 0)
        {
	    handle_key(value);
        }
	usleep(100000);
    }
}
