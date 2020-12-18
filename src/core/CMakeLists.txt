project(OC-core)

ADD_DEFINITIONS( -DOC_POSTGRESQL )

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)
find_package (Python3 COMPONENTS Interpreter Development)

MESSAGE(${Python3_INCLUDE_DIRS})

FILE (GLOB_RECURSE Files_CPP *.cpp )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

ADD_LIBRARY(core SHARED ${Files_CPP})
TARGET_LINK_LIBRARIES(core -lpqxx -lpq)
target_include_directories (core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

