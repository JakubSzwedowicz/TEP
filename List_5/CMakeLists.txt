cmake_minimum_required(VERSION 3.21)
project (List_5)

set(CMAKE_CXX_STANDARD 17)

add_executable(LIST_5 main.cpp src/Control_Block.cpp src/Shared_Pointer.cpp src/Tab.cpp)

target_include_directories(LIST_5 PRIVATE ${PROJECT_SOURCE_DIR}/inc/)
