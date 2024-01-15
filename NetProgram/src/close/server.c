# include "../lib/unp.h"
# include <string.h>
# include <arpa/inet.h>
# include <sys/select.h>
# include <signal.h>

# define MAXLINE	4096
# define SERVER_PORT 9999

# define LISTENQ 100

static int count;

static void sig_int(int signo) {
  printf("\nreceived %d datagrams\n", count);
  exit(0);
}

int main(int argc, char **argv) {
  int listenfd;
  listenfd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_addr;
  bzero(&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(SERVER_PORT);

  int rt1 = bind(listenfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if (rt1 < 0) {
    printf("bind failed\n");
    exit(1);
  }

  int rt2 = listen(listenfd, LISTENQ);
  if (rt2 < 0) {
    printf("listen failed\n");
    exit(1);
  }

  signal(SIGINT, sig_int);
  signal(SIGPIPE, SIG_IGN);

  int connfd;
  struct sockaddr_in client_addr;

  socklen_t client_len = sizeof(client_addr);

  if ((connfd = accept(listenfd, (struct sockaddr *) &client_addr, &client_len)) < 0) {
    printf("accept error!\n");
    exit(1);
  }

  char message[MAXLINE];
  count = 0;


  for(;;) {
    int n = read(connfd, message, MAXLINE);
    if (n < 0) {
      printf("read error!\n");
      exit(1);
    } else if (n == 0) {
      printf("client closed \n");
      exit(1);
    }

    message[0] = 0;
    printf("received %d bytes: %s\n", n, message);
    count++;

    char send_line[MAXLINE];
    sprintf(send_line, "Hi, %s", message);

    sleep(5);

    int write_nc = send(connfd, send_line, strlen(send_line), 0);
    printf("send bytes: %zu \n", write_nc);
    if (write_nc < 0) {
      printf("write error\n");
      exit(1);
    }
  }
}
