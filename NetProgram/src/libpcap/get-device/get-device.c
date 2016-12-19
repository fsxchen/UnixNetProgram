#include <stdio.h>
#include <pcap.h>

int main() {
	char *dev, errbuf[PCAP_ERRBUF_SIZE];
	dev = pcap_lookupdev(errbuf);
	printf("Device: %s\n", dev);
	return 0;
}
