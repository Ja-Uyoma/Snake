cmake_minimum_required(VERSION 3.14)

include(cmake/EnforceOutOfSourceBuilds.cmake)

project(Snake 
    VERSION 0.1.1 
    DESCRIPTION "The classic game of Snake"
    LANGUAGES CXX
)

if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
endif(NOT DEFINED CMAKE_CXX_STANDARD)

set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/StandardProjectSettings.cmake)

# Declare executable

add_executable(snake_exe)
target_sources(snake_exe PRIVATE source/main.cpp)

add_executable(snake::exe ALIAS snake_exe)

set_property(TARGET snake_exe PROPERTY OUTPUT_NAME snake)

target_compile_features(snake_exe PRIVATE cxx_std_20)

target_compile_options(snake_exe 
    PRIVATE $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall -Wextra -Werror -Wpedantic>
    PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/Wall>
)
