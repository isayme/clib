#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "libdaemon.h"

int daemonize(int nochdir, int noclose)
{
#if (defined _BSD_SOURCE) || (defined _XOPEN_SOURCE && _XOPEN_SOURCE < 500)
    return daemon(nochdir, noclose);
#else
    int fd;
    int i;
    
    switch (fork())
    {
        case -1:
            // fork failed.
            return -1;
        case 0:
            // child process.
            break;
        default:
            // fork success, parent exit.
            exit(0);
    }
    
    /* Create a new SID for the child process */
    if (setsid()) return -1;
    
    /* Change the current working directory */
    if (!nochdir) chdir("/");
    
    /* Close out the standard file descriptors */
    if (!noclose)
    {
        for (i = 0; i < 1024; i++) close(i);
        fd = open("/dev/null", O_RDWR);
        dup(0); dup(0);
    }
    
    return 0;
#endif
}
