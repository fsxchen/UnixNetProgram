#include "../../lib/unp.h"
#include "echo-server.h"
#include <arpa/inet.h>

int main(int argc, char const *argv[]) {
	int i, maxi, maxfd, listenfd, confd, sockfd;
	int clilen;
	int nready, client[FD_SETSIZE];
	size_t n;
	fd_set rset, allset;
	char buf[MAXLINE];
    struct sockaddr_in serveraddr, cliaddr;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(9999);
	bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
	listen(listenfd, 5);
    printf("Listenning at %s:%d\n", inet_ntoa(serveraddr.sin_addr), 9999);

	maxfd = listenfd;

	maxi = -1;
	for (i = 0; i < FD_SETSIZE; i++) {
		client[i] = -1;
	}
	FD_ZERO(&allset);
	FD_SET(listenfd, &allset);

	for (;;) {
		rset = allset;
		nready = select(maxfd + 1, &rset, NULL, NULL, NULL);
		printf("sssssssss\n");
		if (FD_ISSET(listenfd, &rset)) {
			clilen = sizeof(cliaddr);
			confd = accept(listenfd, (SA *)&cliaddr, &clilen);
			
			for(i = 0; i < FD_SETSIZE; i++) {
				if (client[i] < 0) {
					client[i] = confd;
					break;
				}
			}
			printf("i is %d\n", i);
			printf("aaaaaaaaaaaaaaaaaaa\n");
			if (i == FD_SETSIZE)
				err_quit("too many clients");

			FD_SET(confd, &allset);

			if (i > maxi)
				maxi = i;

			printf("nready is %d\n", nready);

			if (--nready <= 0){
				printf("hahaha");
				continue;
			}
		}
		printf("====================");
		for (i = 0; i <= maxi; i++) {
			printf(i);
			printf("...\n");
			if ((sockfd = client[i]) < 0)
				continue;

			if (FD_ISSET(sockfd, &rset)) {
				if ((n = read(sockfd, buf, MAXLINE)) == 0) {
					close(sockfd);
					FD_CLR(sockfd, &allset);
					client[i] = -1;
				} else{
					printf(buf);
					printf("......\n");
					writen(sockfd, buf, n);
				}
				if (--nready <= 0)
					break;
			}
		}
	}


    return 0;
}
