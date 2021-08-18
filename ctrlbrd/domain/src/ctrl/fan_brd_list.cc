#include "fan_brd_list.h"
#include "fan_ctrl_config.h"
#include "fan_ctrl_alert.h"

#include "fan_brd.h"
#include "srv_brd.h"

#include "fan_brd_spec.h"
#include "fan_brd_state.h"
#include "fan_brd_adjuster.h"

#include "auto_fan_brd_mode.h"
#include "manual_fan_brd_mode.h"

#include "assertions.h"
#include "placement.h"

namespace {

struct FanBrdImpl : FanBrd,
    private FanBrdSpec,
    private FanBrdState,
    private FanBrdAdjuster
{
    FanBrdImpl(U32 slot, FanCtrlSender& sender, FanCtrlAlert& alert)
        : slot(slot), sender(sender), alert(alert) {
    }

    Status Config(const FanBrdConfig& conf) {
        ASSERT_EXEC_SUCC(FanBrdState::Add(*mode));
        ASSERT_EXEC_SUCC(FanBrdState::Add(alert));

        mode = MakeFanBrdMode(conf.mode);
        ASSERT_NOT_NIL(mode);

        return MakeSrvBrds(conf);
    }

private:
    Status MakeSrvBrds(const FanBrdConfig& conf) {
        for (U32 i = 0; i < conf.numOfSvrBrd; i++) {
            ASSERT_TRUE(numOfSrvBrd < MAX_SRV_BRD_NUM);
            new (srvBrds[numOfSrvBrd++].Alloc()) SrvBrd(conf.srvBrds[i]);
        }
        return E_OK;
    }

    FanBrdMode* MakeFanBrdMode(FanBrdModeType type) {
        switch (type) {
        case FAN_BRD_MODEL_AUTO:
            return new (auto_.Alloc()) AutoFanBrdMode(*this);
        case FAN_BRD_MODEL_MANUAL:
            return new (manual.Alloc()) ManualFanBrdMode();
        default:
            return nullptr;
        }
    }

private:
    U32 GetId() const override {
        return slot;
    }

    SrvBrd* FindSrvBrd(U32 slot) const override {
        for (U32 i = 0; i < numOfSrvBrd; i++) {
            if (srvBrds[i]->Matches(slot)) {
                return const_cast<SrvBrd*>(srvBrds[i].GetObject());
            }
        }
        return nullptr;
    }

private:
    U32 slot;

    FanBrdMode *mode = nullptr;
    union {
        Placement<AutoFanBrdMode>   auto_;
        Placement<ManualFanBrdMode> manual;
    };
    IMPL_ROLE_WITH_VAR(FanBrdMode, *mode);

    U32 numOfSrvBrd = 0;
    Placement<SrvBrd> srvBrds[MAX_SRV_BRD_NUM];

    FanCtrlSender& sender;
    IMPL_ROLE_WITH_VAR(FanCtrlSender, sender);

    FanCtrlAlert& alert;

private:
    IMPL_ROLE(FanBrdSpec);
    IMPL_ROLE(FanBrdState);
    IMPL_ROLE(FanBrdAdjuster);

};
} // namespace

Status FanBrdList::Config(const FanCtrlConfig& conf, FanCtrlSender& sender, FanCtrlAlert& alert) {
    for (U32 i = 0; i < conf.numOfFanBrd; i++) {
        auto fanBrd = new FanBrdImpl(conf.fanBrds[i].slot, sender, alert);
        ASSERT_NOT_NIL(fanBrd);

        ASSERT_EXEC_SUCC(fanBrd->Config(conf.fanBrds[i]));

        ASSERT_TRUE(numOfFanBrd < MAX_FAN_BRD_NUM);
        fanBrds[numOfFanBrd++] = fanBrd;
    }
    return E_OK;
}

FanBrd* FanBrdList::FindFanBrd(U32 slot) const {
    for (U32 i = 0; i < numOfFanBrd; i++) {
        if (auto &brd = fanBrds[i]->ROLE(FanBrdSpec); brd.GetId() == slot) {
            return fanBrds[i];
        }
    }
    return nullptr;
}

SrvBrd* FanBrdList::FindSrvBrd(U32 slot) const {
    for (U32 i = 0; i < numOfFanBrd; i++) {
        auto &fanBrd = fanBrds[i]->ROLE(FanBrdSpec);
        if (auto srvBrd = fanBrd.FindSrvBrd(slot); srvBrd != nullptr) {
            return srvBrd;
        }
    }
    return nullptr;
}
