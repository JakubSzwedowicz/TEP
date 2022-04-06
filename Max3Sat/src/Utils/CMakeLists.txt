set(LIB_UTILS_SOURCES Timer.cpp Util.cpp)

add_library(LIB_UTILS ${LIB_UTILS_SOURCES})

target_include_directories(LIB_UTILS PUBLIC ${INCLUDES_DIR}/Utils)
