#include <iostream>
#include "Shared_Pointer.hpp"
#include "Tab.hpp"


int main()
{
    tep::Shared_Ptr<int> sptr;
    sptr.reset(new int(5));

    tep::Shared_Ptr<int> sptr2;
    sptr2 = sptr;

    std::cout << *sptr << std::endl;
    std::cout << *sptr2 << std::endl;

    *sptr2 = 4;

    std::cout << *sptr << std::endl;
    std::cout << *sptr2 << std::endl;

    tep::Tab::test_class();
    return 0;

}
