/*
 * fan_ctrl_sender.h
 *
 *  Created on: Aug 18, 2021
 *      Author: horance
 */

#ifndef HA9A1FD70_A549_4C03_98DF_21BBB7F7AF95
#define HA9A1FD70_A549_4C03_98DF_21BBB7F7AF95

#include "keywords.h"
#include "status.h"
#include "pub_ctrbrd_fanbrd_itf.h"

DEF_INTERFACE(FanCtrlSender) {
    Status SendAdjustSpeedCmd(U32 slot, FanSpeed);

private:
    virtual Status Send(U32 eventId, const void* event) = 0;
};

#endif /* HA9A1FD70_A549_4C03_98DF_21BBB7F7AF95 */
