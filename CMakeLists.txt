cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)

project(my_lib VERSION 1.0.1 DESCRIPTION "my_lib")

include(CheckCXXCompilerFlag)

check_cxx_compiler_flag("-march=native" _march_native_works)
check_cxx_compiler_flag("-xHost" _xhost_works)

set(_CXX_FLAGS)
if(_march_native_works)
    message(STATUS "Using processor's vector instructions (-march=native compiler flag set)")
    set(_CXX_FLAGS "-march=native")
elseif(_xhost_works)
    message(STATUS "Using processor's vector instructions (-xHost compiler flag set)")
    set(_CXX_FLAGS "-xHost")
else()
    message(STATUS "No suitable compiler flag found for vectorization")
endif()

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

add_library(my_lib SHARED
    my_lib.cpp
    my_lib.hpp
)
set_target_properties(my_lib PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(my_lib PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})

add_executable(my_app
    my_app.cpp
)
target_link_libraries(my_app my_lib)
