#ifndef KEY_MAP_H
#define KEY_MAP_H

// 小鸡启明星二代 -> DS4 虚拟手柄映射
#define GS_KEY_PS          (1 << 0)   // Home键
#define GS_KEY_TOUCH_CLICK  (1 << 1)   // Home下方键
#define GS_KEY_TOUCH_LEFT   (1 << 2)   // Home左侧键
#define GS_KEY_TOUCH_RIGHT  (1 << 3)   // Home右侧键

typedef struct {
    uint8_t dpad;
    uint8_t buttons;
    uint8_t special;
    uint8_t l2;
    uint8_t r2;
    int16_t lx, ly;
    int16_t rx, ry;
    int16_t gyro_x, gyro_y, gyro_z;
} DS4Report;

#endif
