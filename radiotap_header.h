#ifndef RADIOTAP_HEADER_H
#define RADIOTAP_HEADER_H

#endif // RADIOTAP_HEADER_H
#include <cstdint>
#include "it_present.h"
#pragma pack(push,1)
struct RadiotapHeader{
    uint8_t it_version=0;
    uint8_t it_pad=0;
    uint16_t it_len;
    uint32_t it_present;
    uint8_t rate;

};
#pragma pack(pop)
