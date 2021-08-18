/*
 * fan_brd.h
 *
 *  Created on: Aug 17, 2021
 *      Author: horance
 */

#ifndef H0387D5FF_8EC5_4967_A291_96206A5C811A
#define H0387D5FF_8EC5_4967_A291_96206A5C811A

#include "status.h"
#include "period_hook.h"
#include "fan_unit.h"

struct FanConfig;

namespace fanbrd {

DEF_INTERFACE(FanBrd) EXTENDS(FanUnit, PeriodHook) {
    static FanBrd& Inst();

    virtual Status Config(const FanConfig& conf) = 0;
};

} // namespace fanbrd
#endif /* H0387D5FF_8EC5_4967_A291_96206A5C811A */
