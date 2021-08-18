#include "fan_brd_action.h"
#include "fan_brd.h"

namespace fanbrd {

Status FanBrdAction::Config(const FanConfig& conf) {
    return FanBrd::Inst().Config(conf);
}

Status FanBrdAction::Start() {
    return FanBrd::Inst().Start();
}

Status FanBrdAction::Adjust(FanSpeed speed) {
    return FanBrd::Inst().Adjust(speed);
}

Status FanBrdAction::Stop() {
    return FanBrd::Inst().Stop();
}

} // namespace fanbrd
