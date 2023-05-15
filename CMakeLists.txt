cmake_minimum_required(VERSION 3.20)
project(drone)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-std=c++17 -g -Wall -Wextra -pedantic -lws2_32 -Wno-pragma -Wno-unknown-pragmas)

add_library(udp udpsocket.cpp)
if(WIN32)
target_link_libraries(udp wsock32 ws2_32)
endif (WIN32)

add_library(drone drone.cpp state.cpp navigations.cpp statedata.cpp coordinate.cpp)
target_link_libraries(drone PUBLIC udp)


add_executable(repl repl.cpp)
target_link_libraries(repl PUBLIC udp)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC drone)