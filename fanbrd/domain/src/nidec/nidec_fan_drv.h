#ifndef D22CD7E0_3A68_422E_A71E_9E9785CFE8DE
#define D22CD7E0_3A68_422E_A71E_9E9785CFE8DE

#include "types.h"

enum NidecFanState {
    NIDEC_FAN_OK,
    NIDEC_FAN_ERR,
};

struct NidecFanDrv {
    NidecFanState SetSpeed(U32 speed);
    NidecFanState GetState() const;
};

#endif /* D22CD7E0_3A68_422E_A71E_9E9785CFE8DE */
