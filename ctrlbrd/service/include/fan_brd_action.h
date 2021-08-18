#ifndef HB27D5960_6AC3_4187_B5E0_1EA8BBC90A53
#define HB27D5960_6AC3_4187_B5E0_1EA8BBC90A53

#include "status.h"
#include "fan_ctrl_config.h"
#include "pub_ctrbrd_fanbrd_itf.h"

struct FanCtrlConfig;

struct FanBrdAction {
    Status InitConfig(const FanCtrlConfig&);
    Status ManualAdjust(U32 fanBrdSlot, FanSpeed);
    Status ChangeMode(U32 fanBrdSlot, FanBrdModeType);

    Status OnFanBrdErr(U32 fanBrdSlot);
    Status OnTempChanged(U32 srvBrdSlot, U32 temp);
};

#endif /* HB27D5960_6AC3_4187_B5E0_1EA8BBC90A53 */
