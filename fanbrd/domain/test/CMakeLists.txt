file(GLOB_RECURSE srcs CONFIGURE_DEPENDS
    *.cpp
    *.cc
    *.c
)

add_executable(fanbrd_domain_test ${srcs})

target_link_libraries(fanbrd_domain_test
  PRIVATE 
    fanbrd::domain     # sut
    cctest cctest_main  # xunit
)

add_test(NAME fanbrd_domain_test COMMAND fanbrd_domain_test)