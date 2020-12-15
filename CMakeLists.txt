CMAKE_MINIMUM_REQUIRED(VERSION 3.16.3)
PROJECT(ObjectCube)
SET(CMAKE_OSX_ARCHITECTURES x86_64)

#SET(CMAKE_VERBOSE_MAKEFILE ON)

if (APPLE)
    SET (CMAKE_CXX_STANDARD 17)
else()
    SET (CMAKE_CXX_STANDARD 11)
endif()

if (APPLE)
    include_directories("/usr/local/include" "/usr/local/opt/libpq/include" "/usr/local/opt/libpqxx/include")
    link_directories("/usr/local/lib" "/usr/local/opt/libpq/lib" "/usr/local/opt/libpqxx/lib") 
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

ADD_SUBDIRECTORY(src/proto)
ADD_SUBDIRECTORY(src/core)
ADD_SUBDIRECTORY(src/server)
ADD_SUBDIRECTORY(src/client)
