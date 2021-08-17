# ctrlbrd::domain
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS
  src/*.cpp
  src/*.cc
  src/*.c
)

add_library(ctrlbrd_domain OBJECT ${srcs})

target_include_directories(ctrlbrd_domain
  PUBLIC  include
  PRIVATE src
)

target_link_libraries(ctrlbrd_domain
  PUBLIC pub
)

add_library(ctrlbrd::domain ALIAS ctrlbrd_domain)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()