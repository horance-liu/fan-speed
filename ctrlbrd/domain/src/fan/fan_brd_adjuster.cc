#include "fan_brd_adjuster.h"
#include "fan_brd_spec.h"
#include "fan_ctrl_sender.h"

Status FanBrdAdjuster::Adjust(FanSpeed speed) {
    return Adjust(ROLE(FanBrdSpec).GetId(), speed);
}

Status FanBrdAdjuster::Adjust(U32 slot, FanSpeed speed) {
    FanAdjustSpeedCmd cmd = {
        .slot = slot,
        .speed = speed,
    };
    return ROLE(FanCtrlSender).Send(&cmd);
}
