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
#include <cstring>
#include "MyPCAP.h"

using namespace std;

int main(int argc, char *argv[]) // argc is the number of strings pointed to by argv. argc will be 1 + the number of arguments an implementation will prepend name of program to the array.

{
        if (argc > 3) 
        {
                cout << "Too many arguments, please input 2 or less arguments." << endl;
        }
        else
        {
                cout << "Reading:/home/user_sl/Wireshark/" << argv[1] << endl;
        }
	
	pcap_t *pcap; // handle used to read packets from pcap file.
	char errbuf[PCAP_ERRBUF_SIZE]; // error message into a buffer, so program can report error to the user

	if (strcmp(argv[1],"f") == 0)
	{
		pcap = pcap_open_offline(argv[2], errbuf); // called to open a savefile for reading

		if (pcap == NULL)
        	{
                	cout << "pcap_open_offline() failed: " << errbuf << endl; //error in pcap file
                 	return 1;
		}

		for (int i = 0; i < argc; ++i) // iterate through arguments
                {
                          cout << "Reading:/home/user_sl/Wireshark/" << argv[i] << endl;
		}
		
		cout << "pcap_open_offline = " << pcap << endl; // prints description of pcap file
	}
	else if (strcmp(argv[1], "l") == 0)
	{
		string device(argv[2]);
		pcap = pcap_open_live(device.c_str(), BUFSIZ, 1, 1000, errbuf);
		
		if (pcap == NULL)
                {
                        cout << "pcap_open_live() failed: " << errbuf << endl; //error in pcap file
                        return 1;
                }

		
	}
	else
	{
		cout << "Error: This is not a live or offline packet capture. " << endl;
	}

        struct pcap_pkthdr *header; //
        const u_char *data; // unsigned char variable

        u_int packetCount = 0;

        int startYear, startMon, startDay, startHour, startMin, startSec;
	int endYear, endMon, endDay, endHour, endMin, endSec;
        int nYear, nMon, nDay, nHour, nMin, nSec;

        int j = 0;

	int n;
                cout << "Please enter a PCAP packet number: " << endl;
                cin >> n;
	cout << "okay" << n << endl;

        while (pcap_next_ex(pcap, &header, &data) == 1)
        {

		cout << "okay" << n << endl;

                int epoch_time = header->ts.tv_sec;

                time_t epoch = epoch_time;

                struct tm* date = gmtime(&epoch);

                int year = date->tm_year + 1900;

                int month = date->tm_mon + 1;

                int day = date->tm_mday;

                printf("Packet # %i\n", ++packetCount); //counts number of packets in PCAP file.

                cout << "Packet length: " <<  header->len << " bytes." << endl; //computers the length in bytes of each packet.

                printf("Epoch Time: %ld:%ld seconds\n", header->ts.tv_sec, header->ts.tv_usec);

                printf( "Date = %ld,%ld,%ld,%ld:%ld:%ld \n", date->tm_mday, month, year, date->tm_hour, date->tm_min, date->tm_sec);

                MyPCAP proto(data);

                u_char protocol = *(data + 14 + 9);

                if (protocol == IPPROTO_TCP)
                {
                         j++;
                }


                if (packetCount == 1)
                {
                        startYear = date->tm_year + 1900;
                        startMon = date->tm_mon + 1;
                                    startDay = date->tm_mday;
                        startHour = date->tm_hour;
                        startMin = date->tm_min;
                        startSec = date->tm_sec;
                }

                 if (packetCount == 14)
                {
                        endYear = date->tm_year + 1900;
                        endMon = date->tm_mon + 1;
                        endDay = date->tm_mday;
			endHour = date->tm_hour;
                        endMin = date->tm_min;
                        endSec = date->tm_sec;
                }

                 if (packetCount == n)
                {
                        nYear = date->tm_year + 1900;
                        nMon = date->tm_mon + 1;
                        nDay = date->tm_mday;
                        nHour = date->tm_hour;
                        nMin = date->tm_min;
                        nSec = date->tm_sec;
                }

               printf("\n"); //inputs 1 line spaces between each printed packet
        }

        printf( "The start time and date of this PCAP file is = %ld/%ld/%ld %ld:%ld:%ld \n", startDay, startMon, startYear, startHour, startMin, startSec);
        printf( "The end time and date of this PCAP file is = %ld/%ld/%ld %ld:%ld:%ld \n", endDay, endMon, endYear, endHour, endMin, endSec);
        printf( "The time and date of the %d PCAP packet is = %ld/%ld/%ld %ld:%ld:%ld \n", n, nDay, nMon, nYear, nHour, nMin, nSec);
        cout << "There are: " << packetCount << "packets in this PCAP file." << endl;
        cout << "There are: " << j << "TCP packets in this PCAp file." << endl;
}
