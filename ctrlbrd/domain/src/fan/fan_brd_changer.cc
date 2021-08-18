#include "fan_brd_changer.h"

namespace ctrlbrd {

FanBrdMode* FanBrdChanger::Create(FanBrdModeType type) {
    this->type = type;
    switch (type) {
    case FAN_BRD_MODEL_AUTO:
        return new (auto_.Alloc())  AutoFanBrdMode(ROLE(FanCtrlSender), ROLE(FanBrdSpec));
    case FAN_BRD_MODEL_MANUAL:
        return new (manual.Alloc()) ManualFanBrdMode(ROLE(FanCtrlSender), ROLE(FanBrdSpec));
    default:
        return nullptr;
    }
}

void FanBrdChanger::Destroy() {
    switch (type) {
    case FAN_BRD_MODEL_AUTO:
        auto_->~AutoFanBrdMode();
        break;
    case FAN_BRD_MODEL_MANUAL:
        manual->~ManualFanBrdMode();
        break;
    default:
        break;
    }
}

FanBrdChanger::FanBrdChanger(FanBrdModeType type) : mode(Create(type)) {
}

void FanBrdChanger::Change(FanBrdModeType type) {
    if (this->type != type) {
        Destroy();
        mode = Create(type);
    }
}

const FanBrdMode& FanBrdChanger::GetMode() const {
    return *mode;
}

} // namespace ctrlbrd

