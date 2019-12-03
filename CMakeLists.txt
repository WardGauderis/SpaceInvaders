cmake_minimum_required(VERSION 3.15)
project(spaceInvaders)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE HDRS ${spaceInvaders_SOURCE_DIR}/src/*.h)
file(GLOB_RECURSE SRCS ${spaceInvaders_SOURCE_DIR}/src/*.cpp)

add_executable(SI ${HDRS} ${SRCS} src/utils/event.h src/utils/key.h src/controllers/world.cpp src/controllers/world.h src/models/world.cpp src/models/world.h src/views/world.cpp src/views/world.h src/controllers/player.cpp src/controllers/player.h src/models/player.cpp src/models/player.h src/models/spaceShip.cpp src/models/spaceShip.h src/views/player.cpp src/views/player.h)

target_link_libraries(SI "-lsfml-graphics -lsfml-window -lsfml-system")

set(CMAKE_CXX_FLAGS "-march=native -Wall -Wextra -Wnon-virtual-dtor -Wold-style-cast -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2")
