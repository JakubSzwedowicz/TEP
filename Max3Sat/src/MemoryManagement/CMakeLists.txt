set(LIB_MEMORY_SOURCES Control_Block.cpp Shared_Pointer.cpp Unique_Ptr.cpp)

add_library(LIB_MEMORY ${LIB_MEMORY_SOURCES})

target_include_directories(LIB_MEMORY PUBLIC ${INCLUDES_DIR}/MemoryManagement ${INCLUDES_DIR}/Solver ${INCLUDES_DIR}/Population)

target_link_libraries(LIB_MEMORY PRIVATE LIB_SOLVER LIB_POPULATION)