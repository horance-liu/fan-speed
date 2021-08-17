#ifndef F2EF157B_7E4D_468C_AC43_08A1DAB28A78
#define F2EF157B_7E4D_468C_AC43_08A1DAB28A78

#include "fan_drv.h"

struct AvcV2FanDrv : FanDrv {
private:
    Status Adjust(FanSpeed) override;
    bool IsError() const override;
};

#endif /* F2EF157B_7E4D_468C_AC43_08A1DAB28A78 */
