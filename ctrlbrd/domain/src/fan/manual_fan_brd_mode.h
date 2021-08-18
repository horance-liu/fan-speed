#ifndef A2DE7D83_F680_493C_A398_F3C2EF5AE0A1
#define A2DE7D83_F680_493C_A398_F3C2EF5AE0A1

#include "fan_brd_mode.h"

struct ManualFanBrdMode : FanBrdMode {
private:
    Status OnError(U32 slot) override;
    Status OnHot(U32 slot, U32 temp) override;
};

#endif /* A2DE7D83_F680_493C_A398_F3C2EF5AE0A1 */
