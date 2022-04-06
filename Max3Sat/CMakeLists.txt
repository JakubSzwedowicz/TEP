cmake_minimum_required(VERSION 3.21)
project(Project)

set(CMAKE_CXX_STANDARD 14)

set(INCLUDES_DIR "${PROJECT_SOURCE_DIR}/inc/")

add_executable(PROJECT main.cpp)
target_link_libraries(PROJECT PUBLIC ${INCLUDES_DIR}/Solver)
target_link_libraries(PROJECT PRIVATE LIB_SOLVER)

add_subdirectory(src)