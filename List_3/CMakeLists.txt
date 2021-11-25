cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME "List 3")
#set(CMAKE_CXX_FLAGS "-g -Wall -Werror")
#set(CMAKE_CXX_FLAGS "-g -Werror")
set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME}
        DESCRIPTION "This project contains functions and a class to show basic examples of how to manage memory"
        VERSION 1.0
        LANGUAGES CXX)

set(INCLUDES_DIR "${PROJECT_SOURCE_DIR}/inc/")
#enable_testing()
add_subdirectory(src)
#add_subdirectory(test)

set(MAIN_EXEC_SOURCES main.cpp)
set(MAIN_EXEC APP)

add_executable(${MAIN_EXEC} ${MAIN_EXEC_SOURCES})

target_include_directories(${MAIN_EXEC} PUBLIC ${INCLUDES_DIR})

target_link_libraries(${MAIN_EXEC} PUBLIC TREE_STATIC_LIB TREE_DYNAMIC_LIB)
