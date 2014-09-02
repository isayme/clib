#ifndef __LIB_THREADPOOL
#define __LIB_THREADPOOL

#include "defs.h"
#define __USE_GNU 
#include <pthread.h>

#define TP_F_RUNNING 0x01
#define TP_F_STOPPING 0x02

#define TPW_F_BUSY 0x01
#define TPW_F_IDLE 0x02

// user work function define
typedef void (*tp_func)(void *);

typedef struct tp_worker_s tp_worker_t;

typedef struct thread_pool_s {
    pthread_mutex_t lock;
    //pthread_cond_t cond;
    tp_worker_t *t_worker;
    tp_worker_t *t_head;
    tp_worker_t *t_tail;
    int32_t t_num;  // thread number
    uint8_t flags;    // RUNNING, STOPPING 
}thread_pool_t;

struct tp_worker_s {
    thread_pool_t *parent;      // pool 
    pthread_mutex_t lock;
    pthread_cond_t cond;
    pthread_t tid;              // thread id
    int32_t id;                   // worker id
    tp_func func;               // user function
    void *arg;                  // user function argument
    
    uint8_t flags;                // not use
    struct tp_worker_s *next;   // pointer to next idle thread
};

thread_pool_t *tp_create(int t_num);

int32_t tp_add_task(thread_pool_t *tp, tp_func fn, void *arg);

int32_t tp_destroy(thread_pool_t *tp);

#endif