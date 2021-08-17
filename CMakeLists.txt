cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(fan-speed VERSION 1.0 LANGUAGES C CXX)

# global options
option(FAN_SPEED_BUILD_TEST "Set to ON to build tests" ON)

# treat all warnings as errors
if (UNIX)
  add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

if(FAN_SPEED_BUILD_TEST)
  include(CTest)
  enable_testing()
endif()

# set c++ standard to c++17.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
message(STATUS "C++17 support has been enabled by default.")

add_subdirectory(pub)
add_subdirectory(infra)
add_subdirectory(ctrlbrd)
add_subdirectory(fanbrd)