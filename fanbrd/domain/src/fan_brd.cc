#include "fan_brd.h"
#include "fan_unit.h"
#include "fan_config.h"
#include "fan_box.h"
#include "fan_notifier.h"

#include "assertions.h"
#include "placement.h"

namespace {
struct FanBrdImpl : FanBrd {
private:
    Status Config(const FanConfig& conf) override {
        for (U32 i = 0; i < conf.numOfDrv; i++) {
            new (fanBoxs[i].Alloc()) FanBox(conf.drvs[i]);
            numOfFanBox++;
        }
        return E_OK;
    }

private:
    Status Start() override {
        return EachBox([](FanUnit& fanUnit) {
            return fanUnit.Start();
        });
    }

    Status Adjust(FanSpeed speed) override {
        return EachBox([speed](FanUnit& fanUnit) {
            return fanUnit.Adjust(speed);
        });
    }

    Status Stop() override {
        return EachBox([](FanUnit& fanUnit) {
            return fanUnit.Stop();
        });
    }

    bool IsError() const override {
        U32 numOfErrs = 0;
        for (U32 i = 0; i < numOfFanBox; i++) {
            if (const FanUnit &fan = *fanBoxs[i]; fan.IsError()) {
                numOfErrs++;
            }
        }
        return numOfErrs > numOfFanBox / 2;
    }

private:
    Status Run() override {
        if (IsError()) {
            ASSERT_EXEC_SUCC(notifier.Notify());
        }
        return E_OK;
    }

private:
    template <typename Func>
    Status EachBox(Func func) {
        for (U32 i = 0; i < numOfFanBox; i++) {
            ASSERT_EXEC_SUCC(func(*fanBoxs[i]));
        }
        return E_OK;    
    }

private:
    U32 numOfFanBox = 0;
    Placement<FanBox> fanBoxs[MAX_FAN_DRV_NUM]; 

    FanNotifier notifier;
};
} // namespace

FanBrd& FanBrd::Inst() {
    static FanBrdImpl inst;
    return inst;
}