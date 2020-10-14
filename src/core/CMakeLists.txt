# What is this? Do we need this?
ADD_DEFINITIONS( -DOC_POSTGRESQL )
SET(CMAKE_OSX_ARCHITECTURES x86_64)

SET (CMAKE_CXX_STANDARD 11)

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)
find_package (Python3 COMPONENTS Interpreter Development)

MESSAGE(${Python3_INCLUDE_DIRS})

if(NOT PQXX_LIB)
  message(FATAL_ERROR "pqxx library not found")
endif()

if(NOT PQ_LIB)
  message(FATAL_ERROR "pg library not found")
endif()

#set(PQXX /usr/local/include/pqxx)
#include_directories("/usr/local/include")
#link_directories("/usr/local/lib")

#file(MAKE_DIRECTORY /usr/local/ObjectCube )
#file(MAKE_DIRECTORY /usr/local/ObjectCube/plugin )

FILE (GLOB_RECURSE Files_CPP *.cpp )
#FILE(GLOB_RECURSE TEST_CPP "test/*.cpp")
#FILE(GLOB main_CPP "src/main*.cpp")

#LIST(REMOVE_ITEM Files_CPP ${IgnoreFiles_CPP})
#LIST(REMOVE_ITEM Files_CPP ${main_CPP})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

#MESSAGE(STATUS "Contents of IgnoreFiles_CPP: ${IgnoreFiles_CPP}")
#MESSAGE(STATUS "Contents of Files_CPP: ${Files_CPP}")

#set(CMAKE_FIND_LIBRARY_SUFFIXES ".a;.so;.dylib")

ADD_LIBRARY(core SHARED ${Files_CPP})
TARGET_LINK_LIBRARIES(core -lpqxx -lpq)
target_include_directories (core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#INSTALL(TARGETS ObjectCube LIBRARY DESTINATION /usr/lib )


