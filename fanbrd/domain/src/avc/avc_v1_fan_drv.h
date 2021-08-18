#ifndef E1310092_DAAA_430B_89D7_8E9450D526D9
#define E1310092_DAAA_430B_89D7_8E9450D526D9

#include "fan_drv.h"

namespace fanbrd {

struct AvcV1FanDrv : FanDrv {
private:
    Status Adjust(FanSpeed) override;
    bool IsError() const override;
};

} // namespace fanbrd

#endif /* E1310092_DAAA_430B_89D7_8E9450D526D9 */
