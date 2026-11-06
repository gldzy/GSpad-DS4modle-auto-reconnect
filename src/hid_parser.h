#ifndef HID_PARSER_H
#define HID_PARSER_H

#include "defines.h"
#include "key_map.h"

bool hid_scan_device(int *out_fd);
void hid_close_device(int fd);
bool hid_read_report(int fd, DS4Report *out_report);

#endif
