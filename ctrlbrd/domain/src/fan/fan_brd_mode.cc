#include "fan_brd_mode.h"

namespace ctrlbrd {

FanBrdMode::FanBrdMode(FanCtrlSender &sender, FanBrdSpec& spec)
    : FanBrdAdjuster(spec), sender(sender)
{}

} // namespace ctrlbrd
