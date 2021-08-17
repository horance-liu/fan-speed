#include "period_task.h"
#include "period_hook.h"
#include "assertions.h"

namespace {
struct RepeatTask : PeriodTask {
    RepeatTask(U32 times) : times(times) {
    }

private:
    Status Start(U32 /* interval */, PeriodHook& hook) override {
        for (U32 i =0; i < times; i++) {
            ASSERT_EXEC_SUCC(hook.Run());
        }
        return E_OK;
    }
    
    Status Stop() override {
        return E_OK;
    }
    
    bool Expired() const override {
        return false;
    }

private:
    U32 times;
};
} // namespace

std::unique_ptr<PeriodTask> PeriodTask::Times(U32 times) {
    return std::make_unique<RepeatTask>(times);
}