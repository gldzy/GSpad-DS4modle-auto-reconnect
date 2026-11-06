#include "virtual_ds4.h"
#include <ps5/vpad.h>
#include <ps5/kernel.h>

static uint64_t g_vpad_handle = 0;

bool virtual_ds4_create(uint64_t account_id)
{
    if (g_vpad_handle != 0)
        return true;
    g_vpad_handle = vpad_create_ds4(account_id);
    return g_vpad_handle != 0;
}

void virtual_ds4_destroy(void)
{
    if (g_vpad_handle == 0)
        return;
    vpad_destroy(g_vpad_handle);
    g_vpad_handle = 0;
}

bool virtual_ds4_send(const DS4Report *rep)
{
    if (g_vpad_handle == 0)
        return false;
    return vpad_send_ds4_report(g_vpad_handle, rep);
}
