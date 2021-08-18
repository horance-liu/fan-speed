#include "fan_brd_list.h"

#include "srv_brd_list.h"
//#include "fan_ctrl_config.h"
#include "fan_ctrl_alert.h"
//
//#include "fan_brd.h"
//#include "srv_brd.h"

#include "fan_brd_spec.h"
#include "fan_brd_state.h"
#include "fan_brd_changer.h"

//#include "fan_brd_adjuster.h"
#include "assertions.h"

namespace {

struct FanBrdImpl : FanBrd,
    private FanBrdSpec,
    private FanBrdState,
    private FanBrdChanger
{
    FanBrdImpl(const FanBrdConfig& conf, FanCtrlSender& sender, FanCtrlAlert& alert)
        : FanBrdChanger(conf.mode), slot(conf.slot), sender(sender), alert(alert) {
    }

    Status Config(const FanBrdConfig& conf) {
        ASSERT_EXEC_SUCC(FanBrdState::Add(mode()));
        ASSERT_EXEC_SUCC(FanBrdState::Add(alert));

        return srvBrds.Config(conf, alert, mode());
    }

private:
    U32 GetId() const override {
        return slot;
    }

    SrvBrd* FindSrvBrd(U32 slot) const override {
        return const_cast<SrvBrd*>(srvBrds.Find(slot));
    }

    FanBrdMode& mode() const {
        return const_cast<FanBrdMode&>(FanBrdChanger::GetMode());
    }

private:
    U32 slot;

    FanCtrlSender& sender;
    IMPL_ROLE_WITH_VAR(FanCtrlSender, sender);

    FanCtrlAlert& alert;

    IMPL_ROLE_WITH_VAR(FanBrdMode, mode());

    SrvBrdList srvBrds;

private:
    IMPL_ROLE(FanBrdSpec);
    IMPL_ROLE(FanBrdState);
    IMPL_ROLE(FanBrdChanger);
};
} // namespace

Status FanBrdList::Config(const FanCtrlConfig& conf, FanCtrlSender& sender, FanCtrlAlert& alert) {
    for (U32 i = 0; i < conf.numOfFanBrd; i++) {
        auto fanBrd = new FanBrdImpl(conf.fanBrds[i], sender, alert);
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
