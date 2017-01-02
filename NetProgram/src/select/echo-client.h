#include "../lib/unp.h"
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
size_t readline(int fd, void *vptr, size_t maxlen);
#include <sys/select.h>


int
FD_ISSET(int fd, fd_set *fdset);

void
FD_SET(int fd, fd_set *fdset);

void
FD_ZERO(int fd_set *fdset);

int
select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds, fd_set *restrict errorfds,
    struct timeval *restrict timeout);ssize_t writen(int fd, void *vptr, size_t n);
