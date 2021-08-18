#include "fan_notifier.h"

namespace fanbrd {

Status FanNotifier::Notify(U32, FanStateType) {
    // report to ctrl brd ...
    return E_OK;
}

} // namespace fanbrd
