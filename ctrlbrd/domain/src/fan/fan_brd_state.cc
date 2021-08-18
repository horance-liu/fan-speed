#include "fan_brd_state.h"
#include "fan_brd_listener.h"
#include "fan_brd_spec.h"

#include "assertions.h"

namespace ctrlbrd {

Status FanBrdState::Add(FanBrdListener& listener) {
    ASSERT_TRUE(numOfListener < MAX_FAN_BRD_STATE_LISTENER_NUM);

    listeners[numOfListener++] = &listener;

    return E_OK;
}

Status FanBrdState::OnError() {
    for (U32 i = 0; i < numOfListener; i++) {
        ASSERT_EXEC_SUCC(listeners[i]->OnError(ROLE(FanBrdSpec).GetId()));
    }
    return E_OK;
}

} // namespace ctrlbrd
