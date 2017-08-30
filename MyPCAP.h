#ifndef MYPCAP_H
#define MYPCAP_H

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

class MyPCAP
{
	
	public: 
		MyPCAP(const u_char *data);
		MyPCAP& operator=(const u_char protocol);

	private:
		u_char protocol;
		int portA;
		int portB;
		string ipA;
		string ipB;
		const int eth_header_length = 14;
		const int proto_bytes = 9;
		int j;	
};

#endif
