# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
CMAKE_MINIMUM_REQUIRED(VERSION 3.18.2)
#set(CMAKE_CXX_COMPILER "g++")
project(objectcube)
set(CMAKE_VERBOSE_MAKEFILE ON)

# Recurse into the "Hello" and "Demo" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
add_subdirectory (src/core)
add_subdirectory (src/wrapper)
