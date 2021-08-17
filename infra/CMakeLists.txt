# infra
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS
  src/*.cpp
  src/*.cc
  src/*.c
)

add_library(infra ${srcs})

target_include_directories(infra
  PUBLIC  include
  PRIVATE src
)