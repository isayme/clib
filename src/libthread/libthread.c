#include "libthread.h"

int32_t CS_INIT(CS_T *cs)
{
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE_NP);
    return pthread_mutex_init(cs,&attr);
}

int32_t CS_ENTER(CS_T *cs)
{
    return pthread_mutex_lock(cs);
}

int32_t CS_LEAVE(CS_T *cs)
{
    return pthread_mutex_unlock(cs);
}

int32_t CS_DEL(CS_T *cs)
{
    return pthread_mutex_destroy(cs);
}

TID_T THREAD_CREATE(void *(*func)(void*), void* param)
{
    TID_T    tid;
    int32_t    ret;

    ret = pthread_create(&tid,NULL,func,param);
    if (ret == 0)
        return tid;
    else
        return (TID_T)-1;
}
