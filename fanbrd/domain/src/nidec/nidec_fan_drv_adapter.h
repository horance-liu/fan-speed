#ifndef EA20235E_1E9D_49B4_B767_182FBD951C20
#define EA20235E_1E9D_49B4_B767_182FBD951C20

#include "fan_drv.h"
#include "nidec_fan_drv.h"

struct NidecFanDrvAdapter : private NidecFanDrv, FanDrv {
private:
    Status Adjust(FanSpeed) override;
    bool IsError() const override;
};

#endif /* EA20235E_1E9D_49B4_B767_182FBD951C20 */
