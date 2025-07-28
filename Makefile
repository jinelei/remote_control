CC = gcc
OBJS = main.o ttp.o gpio.o
TARGET = remote-control

# gcc -o main main.c -l wiringPi

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $^ -l wiringPi

%.o:%.c
	$(CC) -c $^

clean:
	rm -r $(OBJS) $(TARGET)
