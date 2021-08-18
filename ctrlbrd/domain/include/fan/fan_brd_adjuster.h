#ifndef B310558C_8EE4_4001_B6BC_387E4983DAA0
#define B310558C_8EE4_4001_B6BC_387E4983DAA0

#include "keywords.h"
#include "status.h"
#include "pub_ctrbrd_fanbrd_itf.h"

struct FanBrdSpec;

DEF_INTERFACE(FanBrdAdjuster) {
    FanBrdAdjuster(FanBrdSpec&);

    Status ManualAdjust(FanSpeed speed);
    virtual Status ManualAdjust(U32 slot, FanSpeed speed) = 0;

private:
    FanBrdSpec &spec;
};

#endif /* B310558C_8EE4_4001_B6BC_387E4983DAA0 */
