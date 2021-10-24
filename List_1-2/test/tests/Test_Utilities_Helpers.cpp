//
// Created by JakubSzwedowicz on 13.10.2021.
//

#include "gtest/gtest.h"
#include "Utilities_Helpers.hpp"

TEST(Test_Utilities_Helpers, test_should_return_full_increasing_by_one_table)
{
    const int size = 13;
    const int added_to_offset = 5;
    int* array = new int[size];
    fun::helpers::fill_table(array, size, added_to_offset);
    for (int i = 0; i < size - 1; i++)
    {
        ASSERT_EQ(array[i], array[i + 1] - 1);
    }
    delete[] array;
}

TEST(Test_Utilities_Helpers, test_should_difference_be_equal)
{
    const int size = 11;
    const int first_added_to_offset = 5;
    const int second_added_to_offset = 67;
    int* first_array = new int[size];
    int* second_array = new int[size];
    fun::helpers::fill_table(first_array, size, first_added_to_offset);
    fun::helpers::fill_table(second_array, size, second_added_to_offset);
    for (int i = 0; i < size; i++)
    {
        ASSERT_EQ(second_array[i] - first_array[i], second_added_to_offset - first_added_to_offset);
    }
    delete[] first_array;
    delete[] second_array;
}

TEST(Test_Utilities_Helpers, test_should_not_fill_if_wrong_size_passed)
{
    const int size = 11;
    const int illegal_size = -1;
    const int first_added_to_offset = 5;
    int* first_array = new int[size];
    int some_value = first_array[0];
    fun::helpers::fill_table(first_array, illegal_size, first_added_to_offset);
    ASSERT_EQ(some_value, first_array[0]);
    delete[] first_array;
}