CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)

PROJECT(ObjectCube)
SET(CMAKE_VERBOSE_MAKEFILE ON)

ADD_SUBDIRECTORY(src/core src/core/cmake/build)
ADD_SUBDIRECTORY(src/server src/server/cmake/build)

#add_subdirectory (src/wrapper)
