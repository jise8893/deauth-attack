#ifndef DEAUTH_PACKET_H
#define DEAUTH_PACKET_H

#endif // DEAUTH_PACKET_H
#include "radiotap_header.h"
#include "dot11_frame.h"
#pragma pack(push,1)
struct Deauth_Packet{
    Radiotap_header radiotap_header;

    Dot11_frame dot11_frame;
};
#pragma pack(pop)
