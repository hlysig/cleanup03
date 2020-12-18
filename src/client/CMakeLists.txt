project(client)

FILE (GLOB_RECURSE Files_CPP *.cc )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

add_executable (client ${Files_CPP})
target_link_libraries (client LINK_PUBLIC proto)
