ADD_DEFINITIONS( -DOC_POSTGRESQL )
SET(CMAKE_OSX_ARCHITECTURES x86_64)

SET (CMAKE_CXX_STANDARD 11)

find_package (Python3 COMPONENTS Interpreter Development)
find_package(Boost COMPONENTS python REQUIRED)
#find_package(Python COMPONENTS Interpreter Development)

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

if(NOT PQXX_LIB)
  message(FATAL_ERROR "pqxx library not found")
endif()

if(NOT PQ_LIB)
  message(FATAL_ERROR "pg library not found")
endif()

set(PQXX /usr/local/include/pqxx)
include_directories("/usr/local/include" ${Python3_INCLUDE_DIRS})
link_directories("/usr/local/lib")

FILE (GLOB_RECURSE Files_CPP *.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a;.so;.dylib")

ADD_LIBRARY(wrapper SHARED ${Files_CPP})

TARGET_LINK_LIBRARIES(wrapper -lpqxx -ldl -lpq -lpython3.8 -lboost_regex -lboost_python38 core)
set_target_properties(wrapper PROPERTIES PREFIX "")


#INSTALL(TARGETS ObjectCube LIBRARY DESTINATION /usr/lib)
