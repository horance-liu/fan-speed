#include "spi_fan_ctrl_sender.h"

namespace ctrlbrd {

Status SpiFanCtrlSender::Send(U32 /* eventId */, const void* /* event */) {
    return E_OK;
}

} // namespace ctrlbrd

