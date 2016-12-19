#ifndef _ARP_ATTACK_H
#define _ARP_ATTACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <net/ethernet.h>
#include <netinet/if_ether.h>
#include <netpacket/packet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

typedef struct _addr_t {
  struct in_addr sin_addr;
  struct _addr_t *next;
}addr_t;

/*
** get the ip address from the ip range
** reutrn: a linklist of address
*/
addr_t *get_ip_range (char *low, char *high);

/*
** description: free the linklist
*/
void free_addr (addr_t *head);

/*
** send free arp
*/
void send_free_arp (addr_t *head);

void send_request_arp (addr_t *head);

void get_lan_mac (addr_t *head);


#endif
