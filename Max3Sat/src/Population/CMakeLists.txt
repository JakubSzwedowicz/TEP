set(LIB_POPULATION_SOURCES Population_Overseer.cpp Individual.cpp Variable.cpp Clause.cpp)

add_library(LIB_POPULATION ${LIB_POPULATION_SOURCES})

target_include_directories(LIB_POPULATION PUBLIC ${INCLUDES_DIR}/Population ${INCLUDES_DIR}/Utils)

target_link_libraries(LIB_POPULATION PRIVATE LIB_SOLVER LIB_UTILS)