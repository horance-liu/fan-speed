#include "rs581_fan_ctrl_sender.h"

namespace ctrlbrd {

Status Rs581FanCtrlSender::Send(U32 /* eventId */, const void* /* event */) {
    return E_OK;
}

} // namespace ctrlbrd
