#ifndef BD9D9FA4_105D_49E9_82A6_F7ACC55B0A87
#define BD9D9FA4_105D_49E9_82A6_F7ACC55B0A87

#include "types.h"
#include "pub_ctrbrd_fanbrd_itf.h"

EXTERN_STDC_BEGIN

typedef enum FanBrdModeType {
    FAN_BRD_MODEL_AUTO,
    FAN_BRD_MODEL_MANUAL,
} FanBrdModeType;

#define MAX_SRV_BRD_NUM 2

typedef struct FanBrdConfig {
    U32 slot;
    FanBrdModeType mode;

    U32 numOfSvrBrd;
    U32 srvBrds[MAX_SRV_BRD_NUM];
} FanBrdConfig;

typedef enum FanCtrlCommType {
    FAN_CTRL_COMM_SPI,
    FAN_CTRL_COMM_RS581,
} FanCtrlCommType;

#define MAX_FAN_BRD_NUM 4

typedef struct FanCtrlConfig {
    U32 numOfFanBrd;
    FanBrdConfig fanBrds[MAX_FAN_BRD_NUM];

    FanCtrlCommType commType;
} FanCtrlConfig;

EXTERN_STDC_END

#endif /* BD9D9FA4_105D_49E9_82A6_F7ACC55B0A87 */
