/*
 * rs581_fan_ctrl_sender.h
 *
 *  Created on: Aug 18, 2021
 *      Author: horance
 */

#ifndef HBCA4A81B_13BA_486C_B51C_EBE4FA41967F
#define HBCA4A81B_13BA_486C_B51C_EBE4FA41967F

#include "fan_ctrl_sender.h"

struct Rs581FanCtrlSender : FanCtrlSender {
private:
    Status Send(const void*) override;
};

#endif /* HBCA4A81B_13BA_486C_B51C_EBE4FA41967F */