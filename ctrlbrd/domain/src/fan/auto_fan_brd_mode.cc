#include "auto_fan_brd_mode.h"
#include "fan_brd_adjuster.h"
#include "array_size.h"

AutoFanBrdMode::AutoFanBrdMode(FanBrdAdjuster& adjuster) : adjuster(adjuster) {
}

Status AutoFanBrdMode::OnError(U32 slot) {
    return adjuster.Adjust(slot, FAN_SPEED_HIGH);
}

namespace {

struct Temp2Speed {
    U32 minTemp;
    FanSpeed speed;
} speeds[] = {
    {25, FAN_SPEED_HIGH},
    {20, FAN_SPEED_MID_HIGH},
    {15, FAN_SPEED_MID},
    {10, FAN_SPEED_MID_LOW},
    {5,  FAN_SPEED_LOW},
    {0,  FAN_SPEED_STOP},
};

FanSpeed GetFanSpeed(U32 temp) {
    for (U32 i = 0; i < ARRAY_SIZE(speeds); i++) {
        if (temp >= speeds[i].minTemp) {
            return speeds[i].speed;
        }
    }
    return FAN_SPEED_STOP;
}
} // namespace

Status AutoFanBrdMode::OnHot(U32 slot, U32 temp) {
    FanSpeed speed = GetFanSpeed(temp);
    return adjuster.Adjust(slot, speed);
}
