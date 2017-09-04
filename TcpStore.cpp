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
#include "TcpStore.h"

using namespace std;

TcpStore::
