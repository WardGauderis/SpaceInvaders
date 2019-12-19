cmake_minimum_required(VERSION 3.10)
project(spaceInvaders)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE HDRS ${spaceInvaders_SOURCE_DIR}/src/*.h)
file(GLOB_RECURSE SRCS ${spaceInvaders_SOURCE_DIR}/src/*.cpp)

add_executable(SI ${HDRS} ${SRCS} src/views/shield.cpp src/views/shield.h)
target_link_libraries(SI "-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio")

set(CMAKE_CXX_FLAGS "-march=native -Wall -Wextra -Wnon-virtual-dtor -Wold-style-cast -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2")
