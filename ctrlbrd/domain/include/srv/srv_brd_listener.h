#ifndef FF073112_53EC_421E_9D6A_658235EF4E4C
#define FF073112_53EC_421E_9D6A_658235EF4E4C

#include "status.h"
#include "keywords.h"

DEF_INTERFACE(SrvBrdListener) {
    virtual Status OnHot(U32 slot, U32 temp) = 0;
};

#endif /* FF073112_53EC_421E_9D6A_658235EF4E4C */
