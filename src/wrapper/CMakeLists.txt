# What is this? Do we need this?
ADD_DEFINITIONS( -DOC_POSTGRESQL )
SET(CMAKE_OSX_ARCHITECTURES x86_64)

SET (CMAKE_CXX_STANDARD 17)

SET(HEADER_FILES /Users/hlysig/.pyenv/versions/3.6.8/include/python3.6m /usr/local/include)
SET(LINK_DIRS /usr/local/lib)

find_package(Boost COMPONENTS python REQUIRED)
include_directories(${HEADER_FILES})
link_directories(${LINK_DIRS})

find_package(Python COMPONENTS Interpreter Development)

message("Python_FOUND:${Python_FOUND}")
message("Python_VERSION:${Python_VERSION}")
message("Python_Development_FOUND:${Python_Development_FOUND}")
message("Python_LIBRARIES:${Python_LIBRARIES}")

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

if(NOT PQXX_LIB)
  message(FATAL_ERROR "pqxx library not found")
endif()

if(NOT PQ_LIB)
  message(FATAL_ERROR "pg library not found")
endif()

set(PQXX /usr/local/include/pqxx)
include_directories("/usr/local/include")
link_directories("/usr/local/lib")

FILE (GLOB_RECURSE Files_CPP *.cpp )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a;.so;.dylib")

ADD_LIBRARY(wrapper SHARED ${Files_CPP})
TARGET_LINK_LIBRARIES(wrapper -lpqxx -ldl -lpq ${Boost_LIBRARIES} ${Python_LIBRARIES} -lboost_python38-mt core)
set_target_properties(wrapper PROPERTIES PREFIX "")

#target_link_libraries (helloDemo LINK_PUBLIC Hello)

#INSTALL(TARGETS ObjectCube LIBRARY DESTINATION /usr/lib )
