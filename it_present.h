#ifndef IT_PRESENT_H
#define IT_PRESENT_H

#endif // IT_PRESENT_H
#include <cstdint>
#pragma pack(push,1)

struct ItPresent{
    uint8_t TSFT:1;
    uint8_t Flags:1;
    uint8_t Rate:1;
    uint8_t Channel:1;
    uint8_t FHSS:1;
    uint8_t dBm_Antenna_Signal:1;
    uint8_t dBm_Antenna_Noise:1;
    uint8_t Lock_Quality:1;
    uint8_t TX_Attenuation:1;
    uint8_t db_TX_Attenuation:1;
    uint8_t dBm_TX_Power:1;
    uint8_t Antenna:1;
    uint8_t dB_Antenna_Signal:1;
    uint8_t dB_Antenna_Noise:1;
    uint8_t RX_flags:1;
    uint8_t TX_flags:1;
    uint8_t RTS:1;
    uint8_t data_retries:1;
    uint8_t XChannel:1;
    uint8_t Channel_:1;
    uint8_t MCS_information:1;
    uint8_t A_MPDU_Status:1;
    uint8_t VHT_information:1;
    uint8_t frame_timestamp:1;
    uint8_t HE_information:1;
    uint8_t HE_MU_information:1;
    uint8_t PSDU:1;
    uint8_t L_SIG:1;
    uint8_t Reserved:1;
    uint8_t Radiotap_NS_next:1;
    uint8_t Vendor_NS_next:1;
    uint8_t Ext:1;
    enum Type{
        Absent=0,
        Present=1,
    } ;
};
#pragma pack(pop)
