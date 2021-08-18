#ifndef F381ED95_CBA0_4669_9334_869B50DD6558
#define F381ED95_CBA0_4669_9334_869B50DD6558

///////////////////////////////////////////////////////
#define ASSERT_EXEC_SUCC(func)                   \
do {                                             \
    if (Status status = func; status != E_OK) {  \
        return status;                           \
    }                                            \
} while(0)

///////////////////////////////////////////////////////
#define ASSERT_NOT_NIL(ptr)   \
do {                          \
    if ((ptr) == nullptr) {   \
        return E_NIL_POINTER; \
    }                         \
} while(0)

///////////////////////////////////////////////////////
#define ASSERT_TRUE(expr)             \
do {                                  \
    if (!(expr)) {                    \
        return E_FAILED_PRECONDITION; \
    }                                 \
} while(0)


#endif /* F381ED95_CBA0_4669_9334_869B50DD6558 */
