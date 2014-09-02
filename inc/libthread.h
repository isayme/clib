#ifndef _THREAD_H
#define _THREAD_H

#define __USE_GNU 
#include <pthread.h>
#include "defs.h"

#define TID_T   pthread_t

typedef pthread_mutex_t CS_T;

int32_t CS_INIT(CS_T *cs);

int32_t CS_ENTER(CS_T *cs);

int32_t CS_LEAVE(CS_T *cs);

int32_t CS_DEL(CS_T *cs);

TID_T THREAD_CREATE(void *(*func)(void*), void* param);

#endif