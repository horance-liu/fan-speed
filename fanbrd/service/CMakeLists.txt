# fanbrd::service
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS
  src/*.cpp
  src/*.cc
  src/*.c
)

add_library(fanbrd_service OBJECT ${srcs})

target_include_directories(fanbrd_service
  PUBLIC  include
  PRIVATE src
)

target_link_libraries(fanbrd_service
  PUBLIC fanbrd::domain
)

add_library(fanbrd::service ALIAS fanbrd_service)