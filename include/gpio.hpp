#ifndef __GPIO_H__
#define __GPIO_H__

const unsigned char mac[6] = {0x50, 0xEB, 0xF6, 0x58, 0x91, 0xEC};

void init_gpio();

void pc_startup();

void pc_shutdown();

void pc_reboot();

#endif
