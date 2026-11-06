#ifndef DEFINES_H
#define DEFINES_H

#include <stdint.h>
#include <stdbool.h>

#define TARGET_VID      0x0e6f
#define TARGET_PID      0x0184
#define SAMPLE_RATE_HZ  250
#define SAMPLE_INTERVAL_US (1000000 / SAMPLE_RATE_HZ)

typedef enum {
    STATE_IDLE,
    STATE_BIND_ACCOUNT,
    STATE_RUNNING
} PadState;

typedef struct {
    bool connected;
    bool virtual_created;
    uint64_t account_id;
    int32_t hid_fd;
    PadState state;
} GSpadCtx;

extern GSpadCtx g_ctx;

#endif
