#ifndef B75124E6_6AC4_4C8F_9214_A9C961AA727C
#define B75124E6_6AC4_4C8F_9214_A9C961AA727C

#include "types.h"
#include "externc.h"

EXTERN_STDC_BEGIN

#define MAX_FAN_DRV_NUM 8

enum FanDrvType {
    FAN_DRV_NIDEC,
    FAN_DRV_AVC_V1,
    FAN_DRV_AVC_V2,
    MAX_FAN_DRV_TYPE,
};

struct FanConfig {
    U32 slot;

    U32 numOfDrv;
    FanDrvType drvs[MAX_FAN_DRV_NUM];
};

EXTERN_STDC_END

#endif /* B75124E6_6AC4_4C8F_9214_A9C961AA727C */
