#include "echo-client.h"

void str_cli(int fd);
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

	str_cli(sockfd);


}
void str_cli(int sockfd){
	char sendLine[4096], recvLine[4096];
	memset(sendLine, 0, 4096);
	memset(recvLine, 0, 4096);

	while(fgets(sendLine, 4096, stdin) != NULL) {
		writen(sockfd, sendLine, strlen(sendLine));	
		int r = read(sockfd, recvLine, 4096);
		if (r == 0)
			err_quit("str_cli: server terminated prematurely\n");
		printf("<from server>:%s", recvLine);
	}
}
