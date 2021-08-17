#ifndef C41CFCCB_7FCB_4274_BD90_A9A7CF7317A4
#define C41CFCCB_7FCB_4274_BD90_A9A7CF7317A4

#include "fan_unit.h"
#include "fan_config.h"
#include "fan_state.h"

struct FanDrv;

struct FanBox : FanUnit {
    FanBox(FanDrvType);
    ~FanBox();

private:
    Status Start() override;
    Status Adjust(FanSpeed speed) override;
    Status Stop() override;
    bool IsError() const override;

private:
    FanDrv *drv;
    FanState state;
};

#endif /* C41CFCCB_7FCB_4274_BD90_A9A7CF7317A4 */
