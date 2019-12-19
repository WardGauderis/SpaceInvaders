cmake_minimum_required(VERSION 3.15)
project(spaceInvaders)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE HDRS ${spaceInvaders_SOURCE_DIR}/src/*.h)
file(GLOB_RECURSE SRCS ${spaceInvaders_SOURCE_DIR}/src/*.cpp)

add_executable(SI ${HDRS} ${SRCS} src/models/physicalEntity.cpp src/models/physicalEntity.h src/views/physicalEntity.cpp src/views/physicalEntity.h src/controllers/physicalEntity.cpp src/controllers/physicalEntity.h src/models/bullet.cpp src/models/bullet.h src/views/bullet.cpp src/views/bullet.h src/models/wave.cpp src/models/wave.h src/models/enemy.cpp src/models/enemy.h src/controllers/enemy.cpp src/controllers/enemy.h src/views/enemy.cpp src/views/enemy.h src/views/wave.cpp src/views/wave.h src/views/display.cpp src/views/display.h src/models/shield.cpp src/models/shield.h src/views/model.cpp src/views/model.h src/models/explosion.cpp src/models/explosion.h src/views/explosion.cpp src/views/explosion.h)

target_link_libraries(SI "-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio")

set(CMAKE_CXX_FLAGS "-march=native -Wall -Wextra -Wnon-virtual-dtor -Wold-style-cast -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2")
