cmake_minimum_required(VERSION 3.5.1)
project(OC-core)

ADD_DEFINITIONS( -DOC_POSTGRESQL )
SET(CMAKE_OSX_ARCHITECTURES x86_64)

if (APPLE)
    SET (CMAKE_CXX_STANDARD 17)
else()
    SET (CMAKE_CXX_STANDARD 11)
endif()

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)
find_package (Python3 COMPONENTS Interpreter Development)

MESSAGE(${Python3_INCLUDE_DIRS})

if (APPLE)
    include_directories("/usr/local/include" ${Python3_INCLUDE_DIRS})
    link_directories("/usr/local/lib") 
endif()

if(NOT PQXX_LIB)
  message(FATAL_ERROR "pqxx library not found")
endif()

if(NOT PQ_LIB)
  message(FATAL_ERROR "pq library not found")
endif()

FILE (GLOB_RECURSE Files_CPP *.cpp )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../../../../lib)
ADD_LIBRARY(core SHARED ${Files_CPP})
TARGET_LINK_LIBRARIES(core -lpqxx -lpq)
target_include_directories (core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# INSTALL(TARGETS ObjectCube LIBRARY DESTINATION /usr/lib )

