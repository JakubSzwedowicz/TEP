#include <iostream>
#include "Utilities.hpp"
#include "Table.hpp"

int main()
{
    fun::alloc_table_fill_from_5(10);
    int** tab = NULL;
    bool ok = fun::alloc_2Dtable(&tab, 5, 3);
    ok = fun::dealloc_2Dtable(tab, 5, 3);
    std::cout << ok << " " << std::endl;

    Table t;
    std::cout << t << std::endl;
    t = Table("Some name", 5);
    std::cout << t << std::endl;
    Table* p = t.clone();
    std::cout << *p << std::endl;
    delete p;

    std::cout << "================== custom functions ===============" << std::endl;
    fun::change_size(t, 5);
    fun::change_size(&t, 5);

    return 0;
}
