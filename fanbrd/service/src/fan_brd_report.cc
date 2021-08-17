#include "fan_brd_report.h"
#include "fan_brd.h"
#include "period_task.h"

Status FanBrdReport::Notify(PeriodTask& task) {
    PeriodHook &hook = FanBrd::Inst();
    return task.Start(100 /* ms */, hook);
}
