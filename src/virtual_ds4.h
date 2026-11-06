#ifndef VIRTUAL_DS4_H
#define VIRTUAL_DS4_H

#include "key_map.h"

bool virtual_ds4_create(uint64_t account_id);
void virtual_ds4_destroy(void);
bool virtual_ds4_send(const DS4Report *rep);

#endif
