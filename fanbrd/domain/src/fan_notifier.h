#ifndef F2AD136D_316C_4E05_A09C_C9F60491D516
#define F2AD136D_316C_4E05_A09C_C9F60491D516

#include "status.h"
#include "pub_ctrbrd_fanbrd_itf.h"

namespace fanbrd {

struct FanNotifier {
    Status Notify(U32 slot, FanStateType);
};

} // namespace fanbrd

#endif /* F2AD136D_316C_4E05_A09C_C9F60491D516 */
