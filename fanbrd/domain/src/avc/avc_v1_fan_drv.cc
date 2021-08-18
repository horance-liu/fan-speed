#include "avc_v1_fan_drv.h"

namespace fanbrd {

Status AvcV1FanDrv::Adjust(FanSpeed) {
    return E_OK;
}

bool AvcV1FanDrv::IsError() const {
    return false;
}

} // namespace fanbrd

