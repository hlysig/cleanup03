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

FILE (GLOB_RECURSE Files_CPP *.cpp )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

ADD_LIBRARY(core SHARED ${Files_CPP})
TARGET_LINK_LIBRARIES(core -lpqxx -lpq)
target_include_directories (core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# INSTALL(TARGETS ObjectCube LIBRARY DESTINATION /usr/lib )

