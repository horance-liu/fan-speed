#ifndef EBB8AA2B_19D9_453A_8A3D_68465BAE360D
#define EBB8AA2B_19D9_453A_8A3D_68465BAE360D

#include "fan_brd_mode.h"

namespace ctrlbrd {

struct FanCtrlSender;

struct AutoFanBrdMode : FanBrdMode {
    using FanBrdMode::FanBrdMode;

private:
    Status OnError(U32 slot) override;
    Status OnHot(U32 slot, U32 temp) override;
    Status ManualAdjust(U32 slot, FanSpeed speed) override;
};

} // namespace ctrlbrd

#endif /* EBB8AA2B_19D9_453A_8A3D_68465BAE360D */
