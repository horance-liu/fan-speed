#include "nidec_fan_drv.h"

NidecFanState NidecFanDrv::SetSpeed(U32 /* speed */) {
    return NIDEC_FAN_OK;
}

NidecFanState NidecFanDrv::GetState() const {
    return NIDEC_FAN_OK;
}