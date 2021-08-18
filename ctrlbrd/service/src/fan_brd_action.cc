#include "fan_brd_action.h"
#include "fan_brd_adjuster.h"
#include "fan_brd_state.h"

#include "fan_brd.h"
#include "srv_brd.h"
#include "fan_ctrl_brd.h"

#include "assertions.h"

Status FanBrdAction::InitConfig(const FanCtrlConfig& conf) {
    return FanCtrlBrd::Inst().Config(conf);
}

Status FanBrdAction::ManualAdjust(U32 slot, FanSpeed speed) {
    FanBrd *fanBrd = FanCtrlBrd::Inst().FindFanBrd(slot);
    ASSERT_NOT_NIL(fanBrd);

    return fanBrd->ROLE(FanBrdAdjuster).Adjust(speed);
}

Status FanBrdAction::OnFanBrdErr(U32 slot) {
    FanBrd *fanBrd = FanCtrlBrd::Inst().FindFanBrd(slot);
    ASSERT_NOT_NIL(fanBrd);

    return fanBrd->ROLE(FanBrdState).OnError();
}

Status FanBrdAction::OnTempChanged(U32 slot, U32 temp) {
    SrvBrd *srvBrd = FanCtrlBrd::Inst().FindSrvBrd(slot);
    ASSERT_NOT_NIL(srvBrd);

    return srvBrd->Update(temp);
}
