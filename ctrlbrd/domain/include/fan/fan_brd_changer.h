/*
 *   Copyright (c) 2021, Horance Liu and the respective contributors
 *   All rights reserved.
 * 
 *   Use of this source code is governed by a Apache 2.0 license that can be found
 *   in the LICENSE file.
 */

#ifndef H56827870_F847_4485_AD9C_D18AC098F73C
#define H56827870_F847_4485_AD9C_D18AC098F73C

#include "fan_ctrl_config.h"
#include "auto_fan_brd_mode.h"
#include "manual_fan_brd_mode.h"

#include "placement.h"

namespace ctrlbrd {

struct FanCtrlSender;
struct FanBrdSpec;

DEF_INTERFACE(FanBrdChanger) {
    FanBrdChanger(FanBrdModeType type);

    void Change(FanBrdModeType type);

    const FanBrdMode& GetMode() const;
//    FanBrdMode& GetMode();

private:
    FanBrdMode* Create(FanBrdModeType);
    void Destroy();

private:
    FanBrdModeType type = FAN_BRD_MODEL_MAX;
    FanBrdMode *mode = nullptr;

    union {
        Placement<AutoFanBrdMode>   auto_;
        Placement<ManualFanBrdMode> manual;
    };

private:
    USE_ROLE(FanBrdSpec);
    USE_ROLE(FanCtrlSender);
};

} // namespace ctrlbrd

#endif /* H56827870_F847_4485_AD9C_D18AC098F73C */
