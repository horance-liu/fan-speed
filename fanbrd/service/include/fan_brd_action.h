#ifndef BB0AC7EE_5C70_4B9D_A425_36F06EC0D61E
#define BB0AC7EE_5C70_4B9D_A425_36F06EC0D61E

#include "status.h"
#include "pub_ctrbrd_fanbrd_itf.h"

struct FanConfig;

struct FanBrdAction {
    Status Start();
    Status Stop();

    Status Config(const FanConfig&);
    Status Adjust(FanSpeed speed);  
};

#endif /* BB0AC7EE_5C70_4B9D_A425_36F06EC0D61E */
