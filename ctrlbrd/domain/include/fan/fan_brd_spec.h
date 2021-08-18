/*
 * fan_brd_spec.h
 *
 *  Created on: Aug 18, 2021
 *      Author: horance
 */

#ifndef H604A6666_D5D0_4D7F_8065_67BDBB8F5974
#define H604A6666_D5D0_4D7F_8065_67BDBB8F5974

#include "keywords.h"
#include "types.h"

struct SrvBrd;

DEF_INTERFACE(FanBrdSpec) {
    virtual U32 GetId() const = 0;
    virtual SrvBrd* FindSrvBrd(U32 slot) const = 0;
};



#endif /* H604A6666_D5D0_4D7F_8065_67BDBB8F5974 */
