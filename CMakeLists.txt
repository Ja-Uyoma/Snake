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

add_subdirectory(source)
