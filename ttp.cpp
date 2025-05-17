#include <stdio.h>
#include <stdlib.h> //exit()
#include <fcntl.h>  //define O_RDWR
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int fd;

int run()
{
    if ((fd = open("/dev/i2c-1", O_RDWR)) < 0)
    {
        perror("Failed to open i2c device.\n");
        exit(1);
    }

    if (ioctl(fd, I2C_SLAVE, 0x57) < 0)
    {
        printf("Failed to access bus.\n");
        exit(1);
    }

    printf("Success to access bus.\n");
    char buf[2];
    while (1)
    {
        read(fd, buf, 2);
        int result = buf[0] << 8 | buf[1];
        if (result != 0)
        {
            printf("%d\r\n", result);
        }
        for (int y = 5000; y > 0; y--)
            ;
        printf("\e[1:1H\e[2J");
        // for (int j = 5000; j > 0; j--);
    }

    if (close(fd) != 0)
    {
        perror("Failed to close i2c device.\n");
    }
}