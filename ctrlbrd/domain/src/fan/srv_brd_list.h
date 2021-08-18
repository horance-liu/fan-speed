
#ifndef H45C25E35_AF7D_4770_9A3F_35128658051F
#define H45C25E35_AF7D_4770_9A3F_35128658051F

#include "srv_brd.h"
#include "fan_ctrl_config.h"
#include "placement.h"

struct FanCtrlAlert;
struct FanBrdMode;

struct SrvBrdList {
    Status Config(const FanBrdConfig& conf, FanCtrlAlert& alert, FanBrdMode& mode);

    const SrvBrd* Find(U32 slot) const;

private:
    U32 numOfSrvBrd = 0;
    Placement<SrvBrd> srvBrds[MAX_SRV_BRD_NUM];
};


#endif /* H45C25E35_AF7D_4770_9A3F_35128658051F */
