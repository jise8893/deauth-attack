#ifndef FRAME_CONTROL_H
#define FRAME_CONTROL_H

#endif // FRAME_CONTROL_H
#define management 0
#include <cstdint>
#include <string>
#pragma pack(push,1)
class Frame_control{
public:
    unsigned int protocol:2; //version fix 0
    unsigned int type:2; //control data type etc)management type ...
    unsigned int subtype:4; // subtype etc) management's type beacon or probe request ...
    unsigned int to_ds :1;
    unsigned int from_ds :1;
    unsigned int more_flag:1;
    unsigned int retry:1;
    unsigned int powermgmt:1;
    unsigned int more_data:1;
    unsigned int protected_frame:1;
    unsigned int order:1;


    enum Management{
        Association_Request=0,
        Association_Response=1,
        Reassociation_Request=2,
        Reassociation_Response=3,
        Disassociation=10,
        Deauthentication=12,

    };
};

#pragma pack(pop)
