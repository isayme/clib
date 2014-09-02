#ifndef __LIBCONFIG_H
#define __LIBCONFIG_H

#include "defs.h"

int32_t libconfig_open(char *cfg_path);
int32_t libconfig_close();
int32_t libconfig_get_cfg(char *key, char *value, int32_t value_len);

int32_t get_cfg_from_file(char *key, char *value, int32_t value_len, char *cfg_path);

#endif
