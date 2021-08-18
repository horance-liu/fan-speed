#ifndef EBB8AA2B_19D9_453A_8A3D_68465BAE360D
#define EBB8AA2B_19D9_453A_8A3D_68465BAE360D

#include "fan_brd_mode.h"

struct FanBrdAdjuster;

struct AutoFanBrdMode : FanBrdMode {
    AutoFanBrdMode(FanBrdAdjuster& adjuster);

private:
    Status OnError(U32 slot) override;
    Status OnHot(U32 slot, U32 temp) override;

protected:
    FanBrdAdjuster& adjuster;
};

#endif /* EBB8AA2B_19D9_453A_8A3D_68465BAE360D */
