# ctrlbrd::service
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS
  src/*.cpp
  src/*.cc
  src/*.c
)

add_library(ctrlbrd_service OBJECT ${srcs})

target_include_directories(ctrlbrd_service
  PUBLIC  include
  PRIVATE src
)

target_link_libraries(ctrlbrd_service
  PUBLIC ctrlbrd::domain
)

add_library(ctrlbrd::service ALIAS ctrlbrd_service)