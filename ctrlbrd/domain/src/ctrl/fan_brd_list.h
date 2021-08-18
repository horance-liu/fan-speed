/*
 * fan_brd_factory.h
 *
 *  Created on: Aug 18, 2021
 *      Author: horance
 */

#ifndef HAEE59019_596E_4333_9E8E_4C3309456442
#define HAEE59019_596E_4333_9E8E_4C3309456442

#include "fan_ctrl_config.h"
#include "fan_brd.h"
#include "status.h"

struct FanBrd;
struct SrvBrd;

struct FanCtrlConfig;
struct FanCtrlSender;
struct FanCtrlAlert;

struct FanBrdList {
    Status Config(const FanCtrlConfig&, FanCtrlSender&, FanCtrlAlert&);

    FanBrd* FindFanBrd(U32 slot) const;
    SrvBrd* FindSrvBrd(U32 slot) const;

private:
    U32 numOfFanBrd = 0;
    FanBrd* fanBrds[MAX_FAN_BRD_NUM] = {nullptr};
};

#endif /* HAEE59019_596E_4333_9E8E_4C3309456442 */
