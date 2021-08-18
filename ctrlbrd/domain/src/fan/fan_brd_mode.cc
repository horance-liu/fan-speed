#include "fan_brd_mode.h"

FanBrdMode::FanBrdMode(FanCtrlSender &sender, FanBrdSpec& spec)
    : FanBrdAdjuster(spec), sender(sender)
{}
