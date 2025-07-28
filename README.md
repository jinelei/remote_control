# TouchPad中按键的定义

|按键|键码（16进制)｜键码（10进制)|
|:---|:---|:---|
|KEY_UP|0x0400|1024|
|KEY_DOWN|0x0100|256|
|KEY_LEFT|0x0800|2048|
|KEY_RIGHT|0x0200|512|
|KEY_CIRCLE|0x0001|1|
|KEY_CROSS|0x0002|2|
|KEY_SQUARE|0x0004|4|
|KEY_TRIANGLE|0x8000|32768|
|KEY_L|0x0080|128|
|KEY_R|0x0008|8|
|KEY_START|0x0020|32|
|KEY_SELECT|0x0040|64|
|KEY_HOME|0x0010|16|
|KEY_POWER|0x1000|4096|
|KEY_RASPBERRY|0x2000|8192|
|KEY_LOGO|0x4000|16384|

`brew --prefix llvm`/bin/clang++ --target=arm-linux-gnueabihf --sysroot=$HOME/sysroot -isysroot=$HOME/sysroot -isystem=$HOME/sysroot/usr/include/c++/10 -isystem=$HOME/sysroot/usr/include/arm-linux-gnueabihf/c++/10 -L$HOME/sysroot/usr/lib/gcc/arm-linux-gnueabihf/10 -B$HOME/sysroot/usr/lib/gcc/arm-linux-gnueabihf/10 --gcc-toolchain=`brew --prefix arm-linux-gnueabihf-binutils` -o hello hello.cpp
scp hello jinelei@pi:~


