/*
 * fan_brd_action.h
 *
 *  Created on: Aug 18, 2021
 *      Author: horance
 */

#ifndef HB27D5960_6AC3_4187_B5E0_1EA8BBC90A53
#define HB27D5960_6AC3_4187_B5E0_1EA8BBC90A53

#include "status.h"
#include "pub_ctrbrd_fanbrd_itf.h"

struct FanCtrlConfig;

struct FanBrdAction {
    Status InitConfig(const FanCtrlConfig&);
    Status ManualAdjust(U32 slot, FanSpeed);

    Status OnFanBrdErr(U32 slot);
    Status OnTempChanged(U32 slot, U32 temp);
};

#endif /* HB27D5960_6AC3_4187_B5E0_1EA8BBC90A53 */
