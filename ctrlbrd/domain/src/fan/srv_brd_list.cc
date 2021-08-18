#include "srv_brd_list.h"
#include "fan_brd_mode.h"
#include "fan_ctrl_alert.h"
#include "assertions.h"

namespace ctrlbrd {

Status SrvBrdList::Config(const FanBrdConfig& conf, FanCtrlAlert& alert, FanBrdMode& mode) {
    for (U32 i = 0; i < conf.numOfSvrBrd; i++) {
        ASSERT_TRUE(numOfSrvBrd < MAX_SRV_BRD_NUM);
        SrvBrd *srvBrd = new (srvBrds[numOfSrvBrd++].Alloc()) SrvBrd(conf.srvBrds[i]);
        srvBrd->Add(mode);
        srvBrd->Add(alert);
    }
    return E_OK;
}

const SrvBrd* SrvBrdList::Find(U32 slot) const {
    for (U32 i = 0; i < numOfSrvBrd; i++) {
        if (srvBrds[i]->Matches(slot)) {
            return srvBrds[i].GetObject();
        }
    }
    return nullptr;
}

} // namespace ctrlbrd
