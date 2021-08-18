#ifndef EC1B644B_1D22_4DD4_A4C5_EDD1B247AA17
#define EC1B644B_1D22_4DD4_A4C5_EDD1B247AA17

#include "keywords.h"
#include "status.h"

struct FanBrdSpec;
struct FanBrdListener;

DEF_INTERFACE(FanBrdState) {
    Status Add(FanBrdListener&);
    Status OnError();

private:
    enum { MAX_FAN_BRD_STATE_LISTENER_NUM = 2 };

    U32 numOfListener = 0;
    FanBrdListener* listeners[MAX_FAN_BRD_STATE_LISTENER_NUM] = {nullptr};

private:
    USE_ROLE(FanBrdSpec);
};

#endif /* EC1B644B_1D22_4DD4_A4C5_EDD1B247AA17 */
