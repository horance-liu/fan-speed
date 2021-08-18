#include "fan_box.h"
#include "nidec/nidec_fan_drv_adapter.h"
#include "avc/avc_v1_fan_drv.h"
#include "avc/avc_v2_fan_drv.h"

namespace fanbrd {

namespace {
FanDrv* DoMake(FanDrvType type) {
    switch (type) {
    case FAN_DRV_NIDEC:  return new NidecFanDrvAdapter();
    case FAN_DRV_AVC_V1: return new AvcV1FanDrv();    
    case FAN_DRV_AVC_V2: return new AvcV2FanDrv();    
    default: return nullptr;        
    }
}

FanDrv* Make(FanDrvType type) {
    auto drv = DoMake(type);
    return drv != nullptr ? drv : FanDrv::Nil();
}
} // namespace

FanBox::FanBox(FanDrvType type) : drv(Make(type)) {
}

FanBox::~FanBox() {
    if (drv != FanDrv::Nil()) {
        delete drv;
    }
}

Status FanBox::Start() {
    return state.Transfer(FanState::INIT, FanState::READY);
}

Status FanBox::Adjust(FanSpeed speed) {
    if (IsError() || !state.IsReady()) {
        return E_UNAVAILABLE;
    }
    return drv->Adjust(speed);
}

Status FanBox::Stop() {
    return state.Transfer(FanState::READY, FanState::INIT);
}

bool FanBox::IsError() const {
    return state.IsError() || drv->IsError();
}

} // namespace fanbrd
