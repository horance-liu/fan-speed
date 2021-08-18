#ifndef C40E9DF9_5A42_498B_8AFF_26DFAE7F1D66
#define C40E9DF9_5A42_498B_8AFF_26DFAE7F1D66

#include "keywords.h"
#include "status.h"

DEF_INTERFACE(FanBrdListener) {
    virtual Status OnError(U32 slot) = 0;
};

#endif /* C40E9DF9_5A42_498B_8AFF_26DFAE7F1D66 */
