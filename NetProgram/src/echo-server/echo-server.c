#include "../lib/unp.h"
#include "echo-server.h"
#include <arpa/inet.h>

int main(int argc, char const *argv[]) {
	pid_t pid;
	int listenfd, connfd;
    struct sockaddr_in serveraddr, cliaddr;
	socklen_t len;

	char buf[MAXLINE];
    // if (argc != 2) {
    //     err_quit("usage: tcpcli <IPaddress>\n");
    // }
	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(9999);
	bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
	listen(listenfd, 5);
    printf("Listenning at %s:%d\n", inet_ntoa(serveraddr.sin_addr), 9999);

	for (;;) {
		len = sizeof(cliaddr);
		connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len);
		if ((pid = fork()) == 0) {
			// child
			close(listenfd);
			for(;;) {
				bzero(buf, sizeof(buf));
				int ret = recv(connfd, buf, sizeof(buf), 0);
				writen(connfd, buf, sizeof(buf));

				if (ret > 0) {
					printf("%s", buf);
				}

			}
		}
		close(connfd);
	}
    return 0;
}
