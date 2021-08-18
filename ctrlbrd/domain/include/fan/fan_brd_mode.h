#ifndef CA06A525_8C33_43B9_986D_290665674A54
#define CA06A525_8C33_43B9_986D_290665674A54

#include "srv_brd_listener.h"
#include "fan_brd_listener.h"

struct FanBrdMode : FanBrdListener, SrvBrdListener
{};

#endif /* CA06A525_8C33_43B9_986D_290665674A54 */
