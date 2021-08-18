#include "fan_brd_adjuster.h"
#include "fan_brd_spec.h"

FanBrdAdjuster::FanBrdAdjuster(FanBrdSpec& spec) : spec(spec) {
}

Status FanBrdAdjuster::ManualAdjust(FanSpeed speed) {
    return ManualAdjust(spec.GetId(), speed);
}
