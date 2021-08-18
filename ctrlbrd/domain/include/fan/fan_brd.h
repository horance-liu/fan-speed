/*
 * fan_brd.h
 *
 *  Created on: Aug 18, 2021
 *      Author: horance
 */

#ifndef HE728A470_5E21_4338_B1B6_2176AAA5C63A
#define HE728A470_5E21_4338_B1B6_2176AAA5C63A

#include "keywords.h"

struct FanBrdState;
struct FanBrdMode;
struct FanBrdSpec;
struct FanBrdChanger;

DEF_INTERFACE(FanBrd) {
    HAS_ROLE(FanBrdSpec);
    HAS_ROLE(FanBrdState);
    HAS_ROLE(FanBrdMode);
    HAS_ROLE(FanBrdChanger);
};



#endif /* HE728A470_5E21_4338_B1B6_2176AAA5C63A */
