#include "defines.h"
#include "hid_parser.h"
#include "virtual_ds4.h"
#include "popup_account.h"
#include <ps5/kernel.h>
#include <ps5/thread.h>
#include <ps5/sleep.h>

GSpadCtx g_ctx = {0};

static void main_loop(void *arg)
{
    (void)arg;
    g_ctx.state = STATE_IDLE;
    g_ctx.hid_fd = -1;

    while (1)
    {
        switch (g_ctx.state)
        {
            case STATE_IDLE:
            {
                int fd;
                if (hid_scan_device(&fd))
                {
                    g_ctx.hid_fd = fd;
                    g_ctx.state = STATE_BIND_ACCOUNT;
                }
                else
                {
                    usleep(SAMPLE_INTERVAL_US);
                }
                break;
            }
            case STATE_BIND_ACCOUNT:
            {
                uint64_t aid;
                if (popup_select_account(&aid))
                {
                    g_ctx.account_id = aid;
                    if (virtual_ds4_create(aid))
                    {
                        g_ctx.virtual_created = true;
                        g_ctx.state = STATE_RUNNING;
                    }
                    else
                    {
                        hid_close_device(g_ctx.hid_fd);
                        g_ctx.hid_fd = -1;
                        g_ctx.state = STATE_IDLE;
                    }
                }
                else
                {
                    hid_close_device(g_ctx.hid_fd);
                    g_ctx.hid_fd = -1;
                    g_ctx.state = STATE_IDLE;
                }
                break;
            }
            case STATE_RUNNING:
            {
                DS4Report rep;
                if (hid_read_report(g_ctx.hid_fd, &rep))
                {
                    virtual_ds4_send(&rep);
                }
                else
                {
                    virtual_ds4_destroy();
                    hid_close_device(g_ctx.hid_fd);
                    g_ctx.virtual_created = false;
                    g_ctx.hid_fd = -1;
                    g_ctx.state = STATE_IDLE;
                }
                break;
            }
        }
    }
}

int _start(void)
{
    thread_create(main_loop, NULL, 0x10000, 20);
    thread_detach();
    return 0;
}
