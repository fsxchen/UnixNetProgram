#include "echo-client.h"

void str_cli(FILE *fp, int fd);
int main(int argc, char const *argv[]) {

	int sockfd;
	int confd;
	struct sockaddr_in servaddr;

    if (argc != 3) {
       err_quit("usage: %s <IPaddress> <port>\n", argv[0]);
	}

	int SERVER_PORT = 0;
	SERVER_PORT = atoi(argv[2]);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERVER_PORT);


	if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1)
		err_quit("error!\n");

	str_cli(stdin, sockfd);


}
void str_cli(FILE *fp, int sockfd) {
	int maxfd, stdineof;
	fd_set rset;
	char buf[MAXLINE];
	int n;
	char sendLine[4096], recvLine[4096];
	memset(sendLine, 0, 4096);
	memset(recvLine, 0, 4096);
	FD_ZERO(&rset);
	
	stdineof = 0;

	for (;;) {
		FD_SET(fileno(fp), &rset);
		FD_SET(sockfd, &rset);
		maxfd = max(fileno(fp), sockfd) + 1;
		select(maxfd, &rset, NULL, NULL, NULL);

		if (FD_ISSET(sockfd, &rset)) {
			// socket is ok
			if (read(sockfd, recvLine, 4096) == 0) {
				err_quit("server terminated permaturely");
			}
			fputs(recvLine, stdout);
		}

		if (FD_ISSET(fileno(fp), &rset)) {
			if(fgets(sendLine, 4096, fp) == NULL)
				return;
			send(sockfd, sendLine, strlen(sendLine), 0);
		}
	}
}
