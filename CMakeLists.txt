cmake_minimum_required(VERSION 3.7)
project(singleton)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DISTRIBUTION "-O3")
set(CMAKE_C_FLAGS_DISTRIBUTION "-O3")

set(BOOST_ROOT "E:/opt/boost_1_63_0")
set(Boost_INCLUDE_DIR "E:/opt/boost_1_63_0")

find_package(Boost REQUIRED)
if(Boost_FOUND)
    message(STATUS "It works!")
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_MULTITHREADED ON)
    set(Boost_USE_STATIC_RUNTIME ON)
    link_directories(${Boost_LIBRARY_DIRS})
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(SOURCE_FILES main.cpp singleton.h pair.h)
add_executable(singleton ${SOURCE_FILES})
target_link_libraries(singleton ${Boost_LIBRARIES})
