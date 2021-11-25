#include <iostream>

#include "Tree_Static.hpp"
#include "Tree_Dynamic.hpp"

int main()
{
//    Tree_Static<int>::tree_test();

    std::cout << " DYNAMIC TREE " << std::endl;
    Tree_Dynamic<int>::tree_test();

};