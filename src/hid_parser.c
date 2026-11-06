#include "hid_parser.h"
#include <ps5/kernel.h>
#include <ps5/hid.h>
#include <string.h>

GSpadCtx g_ctx;

bool hid_scan_device(int *out_fd)
{
    int fd = hid_open_device(TARGET_VID, TARGET_PID);
    if (fd < 0)
        return false;
    *out_fd = fd;
    return true;
}

void hid_close_device(int fd)
{
    if (fd >= 0)
        hid_close(fd);
}

bool hid_read_report(int fd, DS4Report *out_report)
{
    memset(out_report, 0, sizeof(DS4Report));
    uint8_t buf[64];
    int ret = hid_read(fd, buf, sizeof(buf), SAMPLE_INTERVAL_US);
    if (ret <= 0)
        return false;

    // 【重要】真机抓包后修改这里的偏移！
    out_report->dpad      = buf[0] & 0x0F;
    out_report->buttons   = buf[1];
    out_report->special   = buf[2];
    out_report->l2        = buf[3];
    out_report->r2        = buf[4];
    out_report->lx        = (int16_t)buf[5];
    out_report->ly        = (int16_t)buf[6];
    out_report->rx        = (int16_t)buf[7];
    out_report->ry        = (int16_t)buf[8];
    out_report->gyro_x    = (int16_t)(buf[9] | (buf[10] << 8));
    out_report->gyro_y    = (int16_t)(buf[11] | (buf[12] << 8));
    out_report->gyro_z    = (int16_t)(buf[13] | (buf[14] << 8));

    return true;
}
