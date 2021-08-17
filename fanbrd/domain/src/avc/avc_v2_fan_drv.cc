#include "avc_v2_fan_drv.h"

Status AvcV2FanDrv::Adjust(FanSpeed) {
    return E_OK;
}

bool AvcV2FanDrv::IsError() const {
    return false;
}