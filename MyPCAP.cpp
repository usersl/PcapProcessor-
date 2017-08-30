#include <iostream>
#include <stdio.h>
#include <pcap/pcap.h>
#include <time.h>
#include <net/ethernet.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include "MyPCAP.h"

using namespace std;

MyPCAP::MyPCAP(const u_char *data)
{
	protocol = *(data + eth_header_length + proto_bytes);

	if (protocol == IPPROTO_TCP)
	{
		printf("Protocol = TCP.\n\n");
	}
}

MyPCAP& MyPCAP::operator=(const u_char protocol)
{
	if (protocol == IPPROTO_TCP)
	{
		j++;
	}
}

TcpConversation::TcpConversation(const u_char *data)
{
	portA

