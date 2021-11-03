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

    Table t, c;
    std::cout << t << std::endl;
    t = Table("Some name", 5);
    t.set_value_at(0, 2);
    t.set_value_at(1, 23);
    t.set_value_at(4, 6);

    c.set_value_at(2, 5);
    c.set_value_at(0, 4);
    c.set_value_at(3, 25);
    c.set_value_at(4, 2);
    std::cout << t << std::endl;
    Table* p = t.clone();
    std::cout << *p << std::endl;
    delete p;

    std::cout << "================== custom functions ===============" << std::endl;
//    fun::change_size(t, 5);
    fun::change_size(&t, 5);


    std::cout << "================== custom functions ===============" << std::endl;
    Table k;
    k = t + c;
    std::cout << "t = " << t << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "k = " << k << std::endl;

    return 0;
}
