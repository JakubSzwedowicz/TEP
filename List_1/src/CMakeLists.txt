#set(INCLUDES_DIR "${PROJECT_SOURCE_DIR}/inc/")

add_library(UTILITIES_LIB Utilities.cpp Utilities_Helpers.cpp)
add_library(TABLE_LIB Table.cpp)

target_include_directories(UTILITIES_LIB PRIVATE ${INCLUDES_DIR})
target_include_directories(TABLE_LIB PRIVATE ${INCLUDES_DIR})

set(ALL_LIBS ALL_LIBS)
#
#add_library(${ALL_LIBS} INTERFACE)
#target_link_libraries(${ALL_LIBS} INTERFACE UTILITIES_LIB TABLE_LIB)
#target_include_directories(${ALL_LIBS} INTERFACE ${INCLUDES_DIR})