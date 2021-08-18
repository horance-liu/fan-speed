#include "manual_fan_brd_mode.h"
#include "fan_ctrl_sender.h"

Status ManualFanBrdMode::OnError(U32 /* slot */) {
    return E_OK; // ignore pulse from repeat timer
}

Status ManualFanBrdMode::OnHot(U32 /* slot */, U32 /* temp */) {
    return E_OK; // ignore pulse  from repeat timer
}

Status ManualFanBrdMode::ManualAdjust(U32 slot, FanSpeed speed) {
    return sender.SendAdjustSpeedCmd(slot, speed);
}
