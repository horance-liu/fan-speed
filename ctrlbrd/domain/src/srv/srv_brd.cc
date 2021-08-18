#include "srv_brd.h"

#include "srv_brd_listener.h"
#include "assertions.h"

namespace ctrlbrd {

SrvBrd::SrvBrd(U32 slot) : slot(slot) {
}

bool SrvBrd::Matches(U32 slot) const {
    return this->slot == slot;
}

Status SrvBrd::Add(SrvBrdListener& listener) {
    ASSERT_TRUE(numOfListener < MAX_SRV_BRD_TEMP_LISENER_NUM);
    listeners[numOfListener++] = &listener;

    return E_OK;
}

inline Status SrvBrd::Notify() {
    for (U32 i = 0; i < numOfListener; i++) {
        ASSERT_EXEC_SUCC(listeners[i]->OnHot(slot, temp));
    }
    return E_OK;
}

#define MAX_SRV_BRD_TEMP 20

Status SrvBrd::Update(U32 temp) {
    this->temp = temp;
    if (temp < MAX_SRV_BRD_TEMP) {
        ASSERT_EXEC_SUCC(Notify());
    }
    return E_OK;
}

} // namespace ctrlbrd
