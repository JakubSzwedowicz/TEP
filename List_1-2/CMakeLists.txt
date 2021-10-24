cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME "List 1")
set(CMAKE_CXX_FLAGS "-g -Wall -Werror")
set(CMAKE_CXX_STANDARD 98)

project(${PROJECT_NAME}
        DESCRIPTION "This project contains functions and a class to show basic examples of how to manage memory"
        VERSION 1.0
        LANGUAGES CXX)

set(INCLUDES_DIR "${PROJECT_SOURCE_DIR}/inc/")
enable_testing()
add_subdirectory(src)
add_subdirectory(test)

set(MAIN_APP_SOURCES main.cpp)
set(MAIN_APP APP)

add_executable(${MAIN_APP} ${MAIN_APP_SOURCES})

target_include_directories(${MAIN_APP} PRIVATE ${INCLUDES_DIR})

target_link_libraries(${MAIN_APP} PRIVATE UTILITIES_LIB TABLE_LIB)
