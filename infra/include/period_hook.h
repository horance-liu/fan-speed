#ifndef ACC03011_ECE1_4ADD_92AF_5AD881D6D797
#define ACC03011_ECE1_4ADD_92AF_5AD881D6D797

#include "keywords.h"
#include "status.h"

DEF_INTERFACE(PeriodHook) {
    virtual Status Run() = 0;
};

#endif /* ACC03011_ECE1_4ADD_92AF_5AD881D6D797 */
