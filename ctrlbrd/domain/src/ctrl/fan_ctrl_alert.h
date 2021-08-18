#ifndef D3EEB047_9D3A_44D3_BAC1_39B57FA8C778
#define D3EEB047_9D3A_44D3_BAC1_39B57FA8C778

#include "fan_brd_listener.h"
#include "srv_brd_listener.h"

struct FanCtrlAlert : FanBrdListener, SrvBrdListener {
private:
    Status OnError(U32 slot) override;
    Status OnHot(U32 slot, U32 temp) override;
};

#endif /* D3EEB047_9D3A_44D3_BAC1_39B57FA8C778 */
