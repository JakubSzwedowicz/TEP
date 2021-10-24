//
// Author: JakubSzwedowicz
// Date: 12.10.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//
#include <iostream>
#include <stdexcept>

#include "Utilities.hpp"
#include "Utilities_Helpers.hpp"

namespace fun
{

    void alloc_table_fill_from_5(int a_size)
    {
        const int magic_number = get_magic_number();

        if (a_size <= 0)
        {
            return;
        }
        int* array = new int[a_size];
        helpers::fill_table(array, a_size, magic_number);
        helpers::print_table(array, a_size);
        delete[] array;
    }

    int get_magic_number()
    {
        static const int magic_number = 5;
        return magic_number;
    }

    bool alloc_2Dtable(int*** a_2Dtable_ptr, int a_sizeX, int a_sizeY)
    {
        if (a_sizeX <= 0 || a_sizeY <= 0)
        {
            return false;
        }
        int i = 0;
        try
        {
            if ((*a_2Dtable_ptr) != NULL)
            {
                dealloc_2Dtable(*a_2Dtable_ptr, a_sizeX, a_sizeY);
            }
            (*a_2Dtable_ptr) = new int* [a_sizeX];
            for (i = 0; i < a_sizeX; i++)
            {
                (*a_2Dtable_ptr)[i] = new int[a_sizeY];
            }
            return true;
        }
        catch (const std::exception& ex)
        {
            dealloc_2Dtable(*a_2Dtable_ptr, i, a_sizeY);
            std::cout << ex.what() << std::endl;
            return false;
        }
    }

    bool dealloc_2Dtable(int** a_2Dtable_ptr, int a_sizeX, int a_sizeY)
    {
        if (a_sizeX <= 0)
        {
            return false;
        }
        for (int i = 0; i < a_sizeX; i++)
        {
            delete[] a_2Dtable_ptr[i];
        }
        delete[] a_2Dtable_ptr;
        return true;
    }

    void  change_size(Table* a_table, int a_new_size)
    {
        a_table->set_new_size(a_new_size);
    }

    void  change_size(Table a_table, int a_new_size)
    {
        a_table.set_new_size(a_new_size);
    }

}