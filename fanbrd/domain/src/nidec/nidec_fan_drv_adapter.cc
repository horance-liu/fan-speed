#include "nidec_fan_drv_adapter.h"

namespace fanbrd {

Status NidecFanDrvAdapter::Adjust(FanSpeed speed) {
    return SetSpeed(10 * speed) == NIDEC_FAN_OK ? E_OK : E_UNAVAILABLE;
}

bool NidecFanDrvAdapter::IsError() const {
    NidecFanState state = GetState();
    return state == NIDEC_FAN_OK;
}

} // namespace fanbrd
