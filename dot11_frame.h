#ifndef DOT11_FRAME_H
#define DOT11_FRAME_H

#endif // DOT11_DEAUTH_FRAME_H
#include "frame_control.h"
#include "mac.h"
#pragma pack(push,1)
class Dot11_frame {
public:
    Frame_control frame_control;//check frame to ds or from ds
    uint16_t duration_id;
    Mac address_1; //receiver address or destination
    Mac address_2; //transmitter or source address
    Mac address_3; // bssid address
    uint16_t sequence_control;

    uint16_t reason_code=CLASS3_FRAME_RECIEVED_FROM_NONASSOCIATED_STA;
   typedef enum {
        CLASS3_FRAME_RECIEVED_FROM_NONASSOCIATED_STA=0x0007,

    }TYPE;

};
#pragma pack(pop)
