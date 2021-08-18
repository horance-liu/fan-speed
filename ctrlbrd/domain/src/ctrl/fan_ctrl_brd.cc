#include "fan_ctrl_brd.h"
#include "fan_ctrl_config.h"
#include "fan_ctrl_alert.h"
#include "fan_brd_list.h"

#include "rs581_fan_ctrl_sender.h"
#include "spi_fan_ctrl_sender.h"

#include "assertions.h"
#include "placement.h"

namespace {

struct FanCtrlBrdImpl : FanCtrlBrd {
private:
    Status Config(const FanCtrlConfig& conf) override {
        FanCtrlSender *sender = MakeSender(conf.commType);
        ASSERT_NOT_NIL(sender);

        return fanBrds.Config(conf, *sender, alert);
    }

    FanBrd* FindFanBrd(U32 slot) override {
        return fanBrds.FindFanBrd(slot);
    }

    SrvBrd* FindSrvBrd(U32 slot) override {
        return fanBrds.FindSrvBrd(slot);
    }

private:
    FanCtrlSender* MakeSender(FanCtrlCommType type) {
        switch (type) {
        case FAN_CTRL_COMM_SPI:
            return new (spi.Alloc()) SpiFanCtrlSender();
        case FAN_CTRL_COMM_RS581:
            return new (rs581.Alloc()) Rs581FanCtrlSender();
        default:
            return nullptr;
        }
    }

private:
    union {
        Placement<SpiFanCtrlSender>   spi;
        Placement<Rs581FanCtrlSender> rs581;
    };

    FanCtrlAlert alert;
    FanBrdList fanBrds;
};
} // namespace

FanCtrlBrd& FanCtrlBrd::Inst() {
    static FanCtrlBrdImpl inst;
    return inst;
}
