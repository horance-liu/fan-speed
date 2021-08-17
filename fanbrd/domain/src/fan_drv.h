#ifndef A05CFFBF_68D5_4211_AA04_E5979CE075B1
#define A05CFFBF_68D5_4211_AA04_E5979CE075B1

#include "keywords.h"
#include "status.h"
#include "pub_ctrbrd_fanbrd_itf.h"

DEF_INTERFACE(FanDrv) {
    static FanDrv* Nil();

    virtual Status Adjust(FanSpeed speed) = 0;
    virtual bool IsError() const = 0;
};

#endif /* A05CFFBF_68D5_4211_AA04_E5979CE075B1 */
