project(server)

SET(CMAKE_OSX_ARCHITECTURES x86_64)
ADD_DEFINITIONS( -DOC_POSTGRESQL )

FILE (GLOB_RECURSE Files_CPP *.cc )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

add_executable (server ${Files_CPP})
target_link_libraries (server LINK_PUBLIC core proto)
