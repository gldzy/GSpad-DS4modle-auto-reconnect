#include "popup_account.h"
#include <ps5/ui.h>
#include <ps5/account.h>

bool popup_select_account(uint64_t *selected_account)
{
    uint64_t acc_list[8];
    int count = account_get_list(acc_list, 8);
    if (count <= 0)
        return false;

    int choice = ui_show_select_popup("GSpad 账号绑定", "选择绑定账号", acc_list, count);
    if (choice < 0 || choice >= count)
        return false;
    *selected_account = acc_list[choice];
    return true;
}
