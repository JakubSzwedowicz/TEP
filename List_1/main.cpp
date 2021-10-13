#include <iostream>
#include "Utilities.hpp"
#include "Table.hpp"

int main()
{
    fun::alloc_table_fill_from_5(10);
    int** tab = NULL;
    bool ok = fun::alloc_2Dtable(&tab, 5, 3);
    std::cout << ok << " " << tab[4][2] << std::endl;
    ok = fun::dealloc_2Dtable(tab, 5, 3);
//    std::cout << ok << " " << tab[4][2] << std::endl;
//    std::cout << ok << std::endl;
    std::cout << "Hello, World!" << std::endl;

    Table t, a;
    std::cout << t << std::endl;
    t = Table("Some name", 5);
    std::cout << t << std::endl;
//    t = Table();
    return 0;
}
