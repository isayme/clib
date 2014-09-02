#ifndef __LIBUDP_H
#define __LIBUDP_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include "defs.h"


typedef int (*CALLBACK)(struct sockaddr addr, char *buff, int blen);

enum {STATE_UNINIT, STATE_RUN, STATE_STOP};

typedef struct{
    int sockfd;
    int state;
    CALLBACK func;
}SOCK_INFO;

int udp_init(uint16_t port, void *func);
int udp_uninit();
int udp_reply(struct sockaddr addr, uint8_t *buff, uint16_t blen);
int udp_send(uint8_t *dip, uint16_t dport, uint8_t *buff, uint16_t blen);

#endif
