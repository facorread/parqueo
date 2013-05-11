project(parqueo)

cmake_minimum_required(VERSION 2.8)

add_executable(parqueo vehiculo.cpp apartamento.cpp main.cpp)
set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type")
set(CMAKE_CXX_FLAGS "--pedantic-errors -Wall -Wextra -Werror -ftabstop=4 -march=native -std=gnu++0x -fshow-column -ftabstop=4 -frounding-math -pipe ${FABIO_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "-ggdb3 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(FABIO_CXX_FLAGS "-Wall -Wextra -Werror -DFABIO_THREADS=2" CACHE STRING "C++ flags for the current directory")

# Debug statements
# set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

