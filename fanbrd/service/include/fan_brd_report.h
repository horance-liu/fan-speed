#ifndef C7CDE9A3_61A7_405F_B6A1_DD19EFD68329
#define C7CDE9A3_61A7_405F_B6A1_DD19EFD68329

#include "status.h"

struct PeriodTask;

namespace fanbrd {

struct FanBrdReport {
    Status Notify(PeriodTask& task);
};

} // namespace fanbrd

#endif /* C7CDE9A3_61A7_405F_B6A1_DD19EFD68329 */
