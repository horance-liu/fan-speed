/*
 * fan_ctrl_sender.h
 *
 *  Created on: Aug 18, 2021
 *      Author: horance
 */

#ifndef HA9A1FD70_A549_4C03_98DF_21BBB7F7AF95
#define HA9A1FD70_A549_4C03_98DF_21BBB7F7AF95

#include "keywords.h"
#include "status.h"

DEF_INTERFACE(FanCtrlSender) {
    virtual Status Send(const void*) = 0;
};

#endif /* HA9A1FD70_A549_4C03_98DF_21BBB7F7AF95 */
