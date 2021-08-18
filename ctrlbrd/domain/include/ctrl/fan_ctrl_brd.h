#ifndef E94BCC6E_2394_4DA9_988B_230D7F68F0E7
#define E94BCC6E_2394_4DA9_988B_230D7F68F0E7

#include "keywords.h"
#include "status.h"

struct FanCtrlConfig;

namespace ctrlbrd {

struct FanBrd;
struct SrvBrd;

DEF_INTERFACE(FanCtrlBrd) {
    static FanCtrlBrd& Inst();

    virtual Status Config(const FanCtrlConfig&) = 0;
    virtual FanBrd* FindFanBrd(U32 slot) = 0;
    virtual SrvBrd* FindSrvBrd(U32 slot) = 0;
};

} // namespace ctrlbrd

#endif /* E94BCC6E_2394_4DA9_988B_230D7F68F0E7 */
