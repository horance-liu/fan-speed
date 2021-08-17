/*
 * period_task.h
 *
 *  Created on: Aug 17, 2021
 *      Author: horance
 */

#ifndef HFE82E3F9_99AF_4AEB_AB49_A84BCC21F00F
#define HFE82E3F9_99AF_4AEB_AB49_A84BCC21F00F

#include "keywords.h"
#include "status.h"
#include <memory>

struct PeriodHook;

DEF_INTERFACE(PeriodTask) {
    virtual Status Start(U32 interval, PeriodHook& task) = 0;
    virtual Status Stop() = 0;
    virtual bool Expired() const = 0;

    static std::unique_ptr<PeriodTask> Times(U32 times = 1);
};

#endif /* HFE82E3F9_99AF_4AEB_AB49_A84BCC21F00F */
