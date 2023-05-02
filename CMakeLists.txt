cmake_minimum_required(VERSION 3.20)
project(drone)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-std=c++17 -g -Wall -Wextra -pedantic -lws2_32)

add_library(udp udpsocket.cpp)
add_library(drone drone.cpp)
add_library(state state.cpp)
add_library(navigations navigations.cpp)
add_library(statedata statedata.cpp)
add_library(coordinate coordinate.cpp)
if(WIN32)
target_link_libraries(udp wsock32 ws2_32)
endif (WIN32)
target_link_libraries(drone PUBLIC udp)

# add_executable(repl repl.cpp)
# target_link_libraries(repl PUBLIC udp)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC udp drone state statedata coordinate navigations)