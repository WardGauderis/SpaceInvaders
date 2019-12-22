cmake_minimum_required(VERSION 3.9)
project(spaceInvaders)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE HDRS ${spaceInvaders_SOURCE_DIR}/src/*.h)
file(GLOB_RECURSE SRCS ${spaceInvaders_SOURCE_DIR}/src/*.cpp)

add_executable(SI ${HDRS} ${SRCS})
target_link_libraries(SI "-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio")

set(CMAKE_CXX_FLAGS "-O3 -march=native -Wall -Wextra -Wnon-virtual-dtor -Wold-style-cast -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion  -Wdouble-promotion -Wformat=2")
# -Wnull-dereference