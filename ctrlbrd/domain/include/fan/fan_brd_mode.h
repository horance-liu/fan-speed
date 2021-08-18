#ifndef CA06A525_8C33_43B9_986D_290665674A54
#define CA06A525_8C33_43B9_986D_290665674A54

#include "fan_brd_adjuster.h"
#include "srv_brd_listener.h"
#include "fan_brd_listener.h"

namespace ctrlbrd {

struct FanCtrlSender;
struct FanBrdSpec;

struct FanBrdMode : FanBrdAdjuster, FanBrdListener, SrvBrdListener {
    FanBrdMode(FanCtrlSender&, FanBrdSpec&);

protected:
    FanCtrlSender &sender;
};

} // namespace ctrlbrd

#endif /* CA06A525_8C33_43B9_986D_290665674A54 */
