# What is this? Do we need this?
#ADD_DEFINITIONS( -DOC_POSTGRESQL )
SET(CMAKE_OSX_ARCHITECTURES x86_64)

SET (CMAKE_CXX_STANDARD 17)




SET(HEADER_FILES /Users/hlysig/.pyenv/versions/3.6.8/include/python3.6m /usr/local/include)
SET(LINK_DIRS /usr/local/lib)


find_package(Boost COMPONENTS python REQUIRED)
include_directories(${HEADER_FILES})
link_directories(${LINK_DIRS})


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

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a;.so;.dylib")

ADD_LIBRARY(wrapper SHARED ${Files_CPP})
TARGET_LINK_LIBRARIES(wrapper -lpqxx -ldl -lpq ${Boost_LIBRARIES} -lpython -lboost_python38-mt core)

#target_link_libraries (helloDemo LINK_PUBLIC Hello)

#INSTALL(TARGETS ObjectCube LIBRARY DESTINATION /usr/lib )


