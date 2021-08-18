#include "fan_brd_action.h"
#include "fan_brd_adjuster.h"
#include "fan_brd_changer.h"
#include "fan_brd_mode.h"
#include "fan_brd_state.h"

#include "fan_brd.h"
#include "srv_brd.h"
#include "fan_ctrl_brd.h"

#include "assertions.h"

namespace ctrlbrd {

Status FanBrdAction::InitConfig(const FanCtrlConfig& conf) {
    return FanCtrlBrd::Inst().Config(conf);
}

Status FanBrdAction::ManualAdjust(U32 fanBrdSlot, FanSpeed speed) {
    FanBrd *fanBrd = FanCtrlBrd::Inst().FindFanBrd(fanBrdSlot);
    ASSERT_NOT_NIL(fanBrd);

    FanBrdAdjuster &adjuster = fanBrd->ROLE(FanBrdMode);
    return adjuster.ManualAdjust(speed);
}

Status FanBrdAction::ChangeMode(U32 fanBrdSlot, FanBrdModeType type) {
    FanBrd *fanBrd = FanCtrlBrd::Inst().FindFanBrd(fanBrdSlot);
    ASSERT_NOT_NIL(fanBrd);

    fanBrd->ROLE(FanBrdChanger).Change(type);

    return E_OK;
}

Status FanBrdAction::OnFanBrdErr(U32 fanBrdSlot) {
    FanBrd *fanBrd = FanCtrlBrd::Inst().FindFanBrd(fanBrdSlot);
    ASSERT_NOT_NIL(fanBrd);

    return fanBrd->ROLE(FanBrdState).OnError();
}

Status FanBrdAction::OnTempChanged(U32 srvBrdSlot, U32 temp) {
    SrvBrd *srvBrd = FanCtrlBrd::Inst().FindSrvBrd(srvBrdSlot);
    ASSERT_NOT_NIL(srvBrd);

    return srvBrd->Update(temp);
}

} // namespace ctrlbrd
