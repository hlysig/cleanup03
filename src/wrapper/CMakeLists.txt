ADD_DEFINITIONS( -DOC_POSTGRESQL )
SET(CMAKE_OSX_ARCHITECTURES x86_64)

SET (CMAKE_CXX_STANDARD 11)

find_package (Python3 COMPONENTS Interpreter Development)
find_package(Boost COMPONENTS python REQUIRED)

if (APPLE)
    include_directories("/usr/local/include" "/usr/local/Cellar/python@3.9/3.9.0/Frameworks/Python.framework/Versions/3.9/include/python3.9")
    link_directories("/usr/local/Cellar/python@3.9/3.9.0/Frameworks/Python.framework/Versions/3.9/lib" "/usr/local/lib")

else()
    include_directories("/usr/local/include" ${Python3_INCLUDE_DIRS})
    link_directories("/usr/local/lib") 
endif()


FILE (GLOB_RECURSE Files_CPP *.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a;.so;.dylib")

ADD_LIBRARY(wrapper SHARED ${Files_CPP})

if (APPLE)
    TARGET_LINK_LIBRARIES(wrapper -lpython3.9 -lboost_regex-mt -lboost_python39-mt core)
else()
    TARGET_LINK_LIBRARIES(wrapper -ldl -lpython3.8 -lboost_regex -lboost_python38 core)
endif()


set_target_properties(wrapper PROPERTIES PREFIX "")
