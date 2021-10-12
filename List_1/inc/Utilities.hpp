//
// Author: JakubSzwedowicz
// Date: 12.10.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//

#ifndef LIST_1_UTILITIES_HPP
#define LIST_1_UTILITIES_HPP

namespace fun
{
    void alloc_table_fill_from_5(int a_size);
    bool alloc_2Dtable(int*** a_2Dtable_ptr, int a_sizeX, int a_sizeY);
    bool dealloc_2Dtable(int** a_table_ptr, int a_sizeX, int a_sizeY);
}

#endif //LIST_1_UTILITIES_HPP
