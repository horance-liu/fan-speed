/*
 *   Copyright (c) 2021, Horance Liu and the respective contributors
 *   All rights reserved.
 * 
 *   Use of this source code is governed by a Apache 2.0 license that can be found
 *   in the LICENSE file.
 */


#include "fan_ctrl_sender.h"
#include "pub_ctrbrd_fanbrd_event.h"

namespace ctrlbrd {

Status FanCtrlSender::SendAdjustSpeedCmd(U32 slot, FanSpeed speed) {
    FanAdjustSpeedCmd cmd = {
        .slot = slot,
        .speed = speed,
    };
    return Send(EV_CTRLBRD_FANBRD_START_ID, &cmd);
}

} // namespace ctrlbrd
