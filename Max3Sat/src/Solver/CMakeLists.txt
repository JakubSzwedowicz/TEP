set(LIB_SOLVER_SOURCES Max3Sat.cpp Optimizer.cpp Problem.cpp)

add_library(LIB_SOLVER ${LIB_SOLVER_SOURCES})

target_include_directories(LIB_SOLVER PUBLIC ${INCLUDES_DIR}/Solver ${INCLUDES_DIR}/MemoryManagement ${INCLUDES_DIR}/Population)

target_link_libraries(LIB_SOLVER PRIVATE LIB_MEMORY LIB_POPULATION)