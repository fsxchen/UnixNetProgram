#include <stdio.h>
#include <stdlib.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <strings.h>

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <errno.h>

#ifndef MAXLINE
#define MAXLINE 4096
#endif

void err_quit(char *format, ...);
