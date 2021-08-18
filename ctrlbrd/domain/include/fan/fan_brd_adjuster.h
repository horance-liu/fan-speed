#ifndef B310558C_8EE4_4001_B6BC_387E4983DAA0
#define B310558C_8EE4_4001_B6BC_387E4983DAA0

#include "keywords.h"
#include "status.h"
#include "pub_ctrbrd_fanbrd_itf.h"

struct FanBrdSpec;
struct FanCtrlSender;

DEF_INTERFACE(FanBrdAdjuster) {
    Status Adjust(FanSpeed speed);
    Status Adjust(U32 slot, FanSpeed speed);

private:
    USE_ROLE(FanBrdSpec);
    USE_ROLE(FanCtrlSender);
};

#endif /* B310558C_8EE4_4001_B6BC_387E4983DAA0 */
