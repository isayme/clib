#ifndef __LIBCONFIG_H
#define __LIBCONFIG_H

#include "defs.h"

INT32 libconfig_open(char *cfg_path);
INT32 libconfig_close();
INT32 libconfig_get_cfg(char *key, char *value, INT32 value_len);

INT32 get_cfg_from_file(char *key, char *value, INT32 value_len, char *cfg_path);

#endif
