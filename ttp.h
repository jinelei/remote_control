#ifndef __TTP_H__
#define __TTP_H__

// 按键键码定义
enum {
    // 方向键 (D-Pad)
    KEY_UP        = 0x0400,
    KEY_DOWN      = 0x0100,
    KEY_LEFT      = 0x0800,
    KEY_RIGHT     = 0x0200,

    // 动作键
    KEY_CIRCLE    = 0x0001,  // 圈
    KEY_CROSS     = 0x0002,  // 叉
    KEY_TRIANGLE  = 0x8000,  // 三角形
    KEY_SQUARE    = 0x0004,  // 正方形

    // 肩部按键
    KEY_L        = 0x0080,  // L
    KEY_R        = 0x0008,  // R

    // 控制键
    KEY_START     = 0x0020,  // + 键
    KEY_SELECT    = 0x0040,  // - 键
    KEY_HOME      = 0x0010,  // LOGO/主页键
    KEY_POWER     = 0x1000,  // 电源键

    // 特殊键
    KEY_RASPBERRY  = 0x2000, // 树莓派徽标
    KEY_LOGO 	   = 0x4000, // 微雪徽标
};

// 回调函数类型
typedef void (*TouchPadKeyCallback)(void);

// 按键映射表项
typedef struct {
    int key;
    TouchPadKeyCallback callback;
} KeyMapEntry;

// 回调函数
void handle_KEY_UP(void);
void handle_KEY_DOWN(void);
void handle_KEY_LEFT(void);
void handle_KEY_RIGHT(void);

void handle_KEY_CIRCLE(void);
void handle_KEY_CROSS(void);
void handle_KEY_TRIANGLE(void);
void handle_KEY_SQUARE(void);

void handle_KEY_L(void);
void handle_KEY_R(void);

void handle_KEY_START(void);
void handle_KEY_SELECT(void);
void handle_KEY_HOME(void);
void handle_KEY_POWER(void);
void handle_KEY_RASPBERRY(void);
void handle_KEY_LOGO(void);

// 处理按键
void handle_key(int key);

void init_ttp();

void run_ttp();

#endif
