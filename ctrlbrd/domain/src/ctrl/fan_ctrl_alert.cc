#include "fan_ctrl_alert.h"

Status FanCtrlAlert::OnError(U32 /* slot */) {
    return E_OK;
}

Status FanCtrlAlert::OnHot(U32 /* slot */, U32 /* temp */) {
    return E_OK;
}
