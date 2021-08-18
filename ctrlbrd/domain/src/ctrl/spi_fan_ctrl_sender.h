#ifndef H520E62C2_A87D_4602_B2BE_1D9E41EFFD4A
#define H520E62C2_A87D_4602_B2BE_1D9E41EFFD4A

#include "fan_ctrl_sender.h"

struct SpiFanCtrlSender : FanCtrlSender {
private:
    Status Send(U32 eventId, const void* event) override;
};

#endif /* H520E62C2_A87D_4602_B2BE_1D9E41EFFD4A */
