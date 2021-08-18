#include "fan_state.h"

namespace fanbrd {

inline Status FanState::Ok(State to) {
    state = to;
    return E_OK;
}

inline Status FanState::Error(Status status) {
    state = ERROR;
    return status;
}

Status FanState::Transfer(State from, State to) {
    return state != from ? Error(E_INVALID_ARGUMENT) : Ok(to);
}

bool FanState::IsInit() const {
    return state == INIT;
}

bool FanState::IsReady() const {
    return state == READY;
}

bool FanState::IsError() const {
    return state == ERROR;
}

} // namespace fanbrd
