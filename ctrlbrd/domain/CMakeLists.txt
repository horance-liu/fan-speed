# ctrlbrd::domain
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS
  src/*.cpp
  src/*.cc
  src/*.c
)

add_library(ctrlbrd_domain OBJECT ${srcs})

target_include_directories(ctrlbrd_domain
  PUBLIC  include/ctrl include/fan include/srv
  PRIVATE src/ctrl     src/fan     src/srv
)

target_link_libraries(ctrlbrd_domain
  PUBLIC pub
)

add_library(ctrlbrd::domain ALIAS ctrlbrd_domain)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()