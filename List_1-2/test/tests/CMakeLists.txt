if(test)

    set(TEST_INCLUDES_DIR "${gtest_SOURCE_DIR}/include" "${gtest_SOURCE_DIR}" "${INCLUDES_DIR}")
    #    set(TEST_SOURCES Test_Utilities.cpp)

    add_executable(TEST_UTILITIES Test_Utilities.cpp)
    add_executable(TEST_UTILITIES_HELPERS Test_Utilities_Helpers.cpp)

    target_link_libraries(TEST_UTILITIES PRIVATE gtest gtest_main UTILITIES_LIB)
    target_link_libraries(TEST_UTILITIES_HELPERS PRIVATE gtest gtest_main UTILITIES_LIB)

    target_include_directories(TEST_UTILITIES PRIVATE ${TEST_INCLUDES_DIR})
    target_include_directories(TEST_UTILITIES_HELPERS PRIVATE ${TEST_INCLUDES_DIR})

    add_test(NAME TEST_UTILITIES COMMAND TEST_UTILITIES)
    add_test(NAME TEST_UTILITIES_HELPERS COMMAND TEST_UTILITIES_HELPERS)


endif()