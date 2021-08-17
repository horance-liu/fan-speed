file(GLOB_RECURSE srcs CONFIGURE_DEPENDS
    *.cpp
    *.cc
    *.c
)

add_executable(ctrlbrd_domain_test ${srcs})

target_link_libraries(ctrlbrd_domain_test
  PRIVATE 
    ctrlbrd::domain     # sut
    cctest cctest_main  # xunit
)

add_test(NAME ctrlbrd_domain_test COMMAND ctrlbrd_domain_test)