/*
 * pub_ctrbrd_fanbrd_itf.h
 *
 *  Created on: Aug 17, 2021
 *      Author: horance
 */

#ifndef H00C2614B_1899_41D0_BFC6_A46FD1B775CA
#define H00C2614B_1899_41D0_BFC6_A46FD1B775CA

#include "externc.h"

EXTERN_STDC_BEGIN

typedef enum FanSpeed {
    FAN_SPEED_STOP = 0,
    FAN_SPEED_LOW = 10,
    FAN_SPEED_MID_LOW = 20,
    FAN_SPEED_MID = 30,
    FAN_SPEED_MID_HIGH = 40,
    FAN_SPEED_HIGH = 50,
} FanSpeed;

typedef struct FanAdjustSpeedCmd {
    U32 slot;
    FanSpeed speed;
} FanAdjustSpeedCmd;

typedef enum FanStateType {
    FAN_SPEED_OK,
    FAN_SPEED_ERR,
} FanStateType;

EXTERN_STDC_END

#endif /* H00C2614B_1899_41D0_BFC6_A46FD1B775CA */
