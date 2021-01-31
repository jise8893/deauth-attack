#ifndef MAC_H
#define MAC_H

#endif // MAC_H
#include <cstdint>
#include <iostream>
#include <cstring>
#include <string>
class Mac final{
    static const int SIZE=6;
public:
    Mac(){};
    Mac(const uint8_t * r){memcpy(this->mac_,r,SIZE);}
    Mac(const std::string r);
    explicit operator std::string() const;


    operator uint8_t*() const {return const_cast<uint8_t*>(mac_);}

    uint8_t mac_[SIZE]={0,};
};
