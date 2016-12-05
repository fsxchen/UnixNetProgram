#include "../lib/unp.h"
#include <arpa/inet.h>

int main(int argc, char const *argv[]) {

    if (argc != 3) {
	   printf("err_quit..");
       err_quit("usage:  <IPaddress> <port>\n");
	}
}
