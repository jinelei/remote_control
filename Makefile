CC = `brew --prefix llvm`/bin/clang++
TARGET_PLATFORM = --target=arm-linux-gnueabihf 
SYSROOT = --sysroot=/Users/zhenlei/sysroot
I_SYSROOT = -isysroot=/Users/zhenlei/sysroot 
I_SYSTEM = -isystem=/Users/zhenlei/sysroot/usr/include -isystem=/Users/zhenlei/sysroot/usr/include/c++/10 -isystem=/Users/zhenlei/sysroot/usr/include/arm-linux-gnueabihf/c++/10
# LIBRARY = -L/Users/zhenlei/sysroot/usr/lib/gcc/arm-linux-gnueabihf/10
# COMP_DIR = -B/Users/zhenlei/sysroot/usr/lib/gcc/arm-linux-gnueabihf/10
LIBRARY = -L/Users/zhenlei/sysroot/usr/lib/gcc/arm-linux-gnueabihf/10
COMP_DIR = -B/Users/zhenlei/sysroot/usr/lib/gcc/arm-linux-gnueabihf/10
GCC_TOOLCHAIN = --gcc-toolchain=`brew --prefix arm-linux-gnueabihf-binutils` 

# OBJS = main.o demo.o ttp.o
OBJS = main.o demo.o gpio.o
TARGET = demo

$(TARGET):$(OBJS)
	$(CC) -I./include $(TARGET_PLATFORM) $(SYSROOT) $(I_SYSROOT) $(I_SYSTEM) $(LIBRARY) $(COMP_DIR) $(GCC_TOOLCHAIN) -o $(TARGET) $^ 

%.o:%.cpp
	$(CC) -I./include $(TARGET_PLATFORM) $(SYSROOT) $(I_SYSROOT) $(I_SYSTEM) $(LIBRARY) $(COMP_DIR) $(GCC_TOOLCHAIN) -c $^

clean:
	rm -r $(OBJS) $(TARGET)
