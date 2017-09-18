#ifndef TCPCONVERSATION_H
#define TCPCONVERSATION_H

#include <iostream>
#include <pcap/pcap.h>
#include <time.h>
#include <net/ethernet.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>

using namespace std;

class TcpConversation
{
	public:
		TcpConversation::TcpConversation(const u_char *date);

	private:
		int portA;
		int portB;
		string ipA;
		string ipB;

};

#endif
