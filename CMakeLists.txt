cmake_minimum_required(VERSION 3.15)
project(spaceInvaders)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE HDRS ${spaceInvaders_SOURCE_DIR}/src/*.h)
file(GLOB_RECURSE SRCS ${spaceInvaders_SOURCE_DIR}/src/*.cpp)

add_executable(SI ${HDRS} ${SRCS} src/utils/transformation.cpp src/utils/transformation.h src/utils/observer.cpp src/utils/observer.h src/models/game.cpp src/models/game.h src/controllers/game.cpp src/controllers/game.h src/views/game.cpp src/views/game.h src/views/view.cpp src/views/view.h src/models/model.cpp src/models/model.h src/controllers/controller.cpp src/controllers/controller.h src/models/spaceShip.cpp src/models/spaceShip.h src/utils/vector.cpp src/utils/vector.h src/controllers/spaceShip.cpp src/controllers/spaceShip.h src/views/spaceShip.cpp src/views/spaceShip.h)

target_link_libraries(SI "-lsfml-graphics -lsfml-window -lsfml-system")

set(CMAKE_CXX_FLAGS "-march=native -Wall -Wextra -Wnon-virtual-dtor -Wold-style-cast -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2")
