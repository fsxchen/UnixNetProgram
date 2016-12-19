#include "../lib/unp.h"
#include <arpa/inet.h>
  


int main(int argc, char const *argv[]) {

	int sockfd;
	struct sockaddr_in servaddr;

    if (argc != 3) {
       err_quit("usage: %s <IPaddress> <port>\n", argv[0]);
	}

	int SERVER_PORT = 0;
	SERVER_PORT = atoi(argv[2]);
	printf("%d\n", SERVER_PORT);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERVER_PORT);

}
