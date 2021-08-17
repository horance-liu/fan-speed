# pub
add_library(pub INTERFACE)

target_include_directories(pub
  INTERFACE .
)

target_link_libraries(pub
  INTERFACE infra
)