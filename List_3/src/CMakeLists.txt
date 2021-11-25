#set(INCLUDES_DIR "${PROJECT_SOURCE_DIR}/inc/")

add_library(TREE_STATIC_LIB Tree_Static.cpp "${INCLUDES_DIR}/Tree_Static.hpp")
add_library(TREE_DYNAMIC_LIB Tree_Dynamic.cpp "${INCLUDES_DIR}/Tree_Dynamic.hpp")

target_include_directories(TREE_STATIC_LIB PRIVATE ${INCLUDES_DIR})
target_include_directories(TREE_DYNAMIC_LIB PRIVATE ${INCLUDES_DIR})

target_compile_features(TREE_STATIC_LIB PUBLIC cxx_std_11)

#set(ALL_LIBS ALL_LIBS)
#
#add_library(${ALL_LIBS} INTERFACE)
#target_link_libraries(${ALL_LIBS} INTERFACE UTILITIES_LIB TABLE_LIB)
#target_include_directories(${ALL_LIBS} INTERFACE ${INCLUDES_DIR})