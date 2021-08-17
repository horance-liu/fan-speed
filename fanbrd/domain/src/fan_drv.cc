#include "fan_drv.h"

namespace {
class NilFanDrv : public FanDrv {
    Status Adjust(FanSpeed) {
        return E_UNAVAILABLE;
    }

    bool IsError() const {
        return true;
    }
};
} // namespace

FanDrv* FanDrv::Nil() {
    static NilFanDrv nil;
    return &nil;
}