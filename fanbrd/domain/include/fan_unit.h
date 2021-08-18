#ifndef H5B4AB2ED_3839_4D77_B269_59D3FAF6B97B
#define H5B4AB2ED_3839_4D77_B269_59D3FAF6B97B

#include "status.h"
#include "keywords.h"
#include "pub_ctrbrd_fanbrd_itf.h"

namespace fanbrd {

DEF_INTERFACE(FanUnit) {
    virtual Status Start() = 0;
    virtual Status Adjust(FanSpeed speed) = 0;
    virtual Status Stop() = 0;
    virtual bool IsError() const = 0;
};

} // namespace fanbrd

#endif /* H5B4AB2ED_3839_4D77_B269_59D3FAF6B97B */
