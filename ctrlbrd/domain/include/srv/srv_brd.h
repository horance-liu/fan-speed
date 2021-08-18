#ifndef H5D93C52E_6343_43F0_9F1B_FD1575078616
#define H5D93C52E_6343_43F0_9F1B_FD1575078616

#include "status.h"

struct SrvBrdListener;

struct SrvBrd {
    SrvBrd(U32 slot);

    bool Matches(U32 slot) const;

    Status Add(SrvBrdListener&);
    Status Update(U32 temp);

private:
    Status Notify();

private:
    U32 slot;
    U32 temp = 0;

    enum { MAX_SRV_BRD_TEMP_LISENER_NUM = 2 };

    U32 numOfListener = 0;
    SrvBrdListener *listeners[MAX_SRV_BRD_TEMP_LISENER_NUM];
};


#endif /* H5D93C52E_6343_43F0_9F1B_FD1575078616 */
