#include "manual_fan_brd_mode.h"

Status ManualFanBrdMode::OnError(U32 /* slot */) {
    return E_OK;
}

Status ManualFanBrdMode::OnHot(U32 /* slot */, U32 /* temp */) {
    return E_OK;
}
