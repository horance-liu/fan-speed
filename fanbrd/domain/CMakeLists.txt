# fanbrd::domain
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS
  src/*.cpp
  src/*.cc
  src/*.c
)

add_library(fanbrd_domain OBJECT ${srcs})

target_include_directories(fanbrd_domain
  PUBLIC  include
  PRIVATE src
)

target_link_libraries(fanbrd_domain
  PUBLIC pub infra
)

add_library(fanbrd::domain ALIAS fanbrd_domain)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()