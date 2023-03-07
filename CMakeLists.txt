cmake_minimum_required(VERSION 3.20)
project(udp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-std=c++17 -g -Wall -Wextra -pedantic)

add_library(udp udpsocket.cpp)
add_library(drone drone.cpp)
if(WIN32)
target_link_libraries(udp wsock32)
endif (WIN32)

add_executable(repl repl.cpp)
target_link_libraries(repl PUBLIC udp)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC udp drone)