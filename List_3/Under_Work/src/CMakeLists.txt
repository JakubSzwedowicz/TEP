#set(INCLUDES_DIR "${PROJECT_SOURCE_DIR}/inc/")

add_library(ITREE_BASE_LIB Tree_Base.cpp)
add_library(TREE_STATIC_LIB Tree_Static.cpp)
add_library(TREE_DYNAMIC_LIB Tree_Dynamic.cpp)

target_include_directories(ITREE_BASE_LIB PRIVATE ${INCLUDES_DIR})
target_include_directories(TREE_STATIC_LIB PRIVATE ${INCLUDES_DIR})
target_include_directories(TREE_DYNAMIC_LIB PRIVATE ${INCLUDES_DIR})

set(ALL_LIBS ALL_LIBS)
#
#add_library(${ALL_LIBS} INTERFACE)
#target_link_libraries(${ALL_LIBS} INTERFACE UTILITIES_LIB TABLE_LIB)
#target_include_directories(${ALL_LIBS} INTERFACE ${INCLUDES_DIR})