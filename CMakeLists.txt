
project(bridge_wall)
cmake_minimum_required(VERSION 3.1)

include(cmake/macros.cmake)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 14)

## Find dependencies ##

find_package(ospray REQUIRED)
include(${OSPRAY_USE_FILE})

## Build devices ##

add_subdirectory(render)


## Build apps ##
# add_subdirectory(apps)
