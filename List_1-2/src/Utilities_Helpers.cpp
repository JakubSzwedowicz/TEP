//
// Author: JakubSzwedowicz
// Date: 12.10.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//

#include <iostream>

#include "Utilities_Helpers.hpp"

namespace fun
{
    namespace helpers
    {
        void fill_table(int* a_table_ptr, int a_size, int magic_number)
        {
            if(a_size < 0 || !a_table_ptr)
            {
                return;
            }
            int offset = 10;
            for (int i = 0; i < a_size; i++)
            {
                a_table_ptr[i] = magic_number + (offset++);
            }
        }

        void print_table(int* a_table, int a_size)
        {
            for (int i = 0; i < a_size; i++)
            {
                std::cout << a_table[i] << ", ";
            }
            std::cout << std::endl;
        }
    }
}