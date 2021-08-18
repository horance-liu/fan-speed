#ifndef C40E9DF9_5A42_498B_8AFF_26DFAE7F1D66
#define C40E9DF9_5A42_498B_8AFF_26DFAE7F1D66

#include "keywords.h"
#include "status.h"

namespace ctrlbrd {

DEF_INTERFACE(FanBrdListener) {
    virtual Status OnError(U32 slot) = 0;
};

} // namespace ctrlbrd

#endif /* C40E9DF9_5A42_498B_8AFF_26DFAE7F1D66 */
