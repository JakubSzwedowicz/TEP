//
// Created by JakubSzwedowicz on 13.10.2021.
//

#include "gtest/gtest.h"
#include "Utilities.hpp"
#include "Table.hpp"

TEST(Test_Utilities, test_should_allocate_2Dtable_5x3)
{
    int** table = NULL;
    const int sizeX = 5;
    const int sizeY = 3;
    ASSERT_EQ(table, nullptr);
    fun::alloc_2Dtable(&table, sizeX, sizeY);
    ASSERT_NE(table, nullptr);
    fun::dealloc_2Dtable(table, sizeX, sizeY);
}
