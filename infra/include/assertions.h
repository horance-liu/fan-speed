#ifndef F381ED95_CBA0_4669_9334_869B50DD6558
#define F381ED95_CBA0_4669_9334_869B50DD6558

#define ASSERT_EXEC_SUCC(func)                   \
do {                                             \
    if (Status status = func; status != E_OK) {  \
        return status;                           \
    }                                            \
} while(0)

#endif /* F381ED95_CBA0_4669_9334_869B50DD6558 */
