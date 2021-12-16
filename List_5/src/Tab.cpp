//
// Author: jakubszwedowicz
// Date: 16.12.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//

#include <iostream>
#include <utility>

#include "Tab.hpp"

using namespace tep;

Tab::Tab(const Tab& a_other) : m_array(nullptr), m_size(0)
{
    copy(a_other);
    std::cout << "[CTOR(const Tab&)]" << std::endl;
}

Tab::~Tab()
{
    delete[] m_array;
    std::cout << "[DTOR]" << std::endl;
}

Tab& Tab::operator=(const Tab& a_other)
{
    std::cout << "[oeprator=(const Tab&)]" << std::endl;

    delete[] m_array;
    copy(a_other);
    return (*this);
}

Tab& Tab::operator=(Tab&& a_other)
{
    std::cout << "[oeprator=(Tab&&)]" << std::endl;

    delete[] m_array;
    m_array = std::exchange(a_other.m_array, nullptr);
    m_size = std::exchange(a_other.m_size, 0);
    return (*this);
}

void Tab::copy(const Tab& a_other)
{
    if (m_array != nullptr)
    {
        delete[] m_array;
    }
    m_array = new int[a_other.m_size];
    m_size = a_other.m_size;
    std::copy(a_other.m_array, a_other.m_array + a_other.m_size, m_array);
}

Tab::Tab(Tab&& a_other)
{
    std::cout << "[CTOR(TAB&&)]" << std::endl;
    m_array = std::exchange(a_other.m_array, nullptr);
    m_size = a_other.m_size;
}

bool Tab::set_size(int a_new_size)
{
    if (a_new_size <= 0)
    {
        return false;
    }
    int* new_array = new int[a_new_size];
    std::copy(m_array, m_array + (a_new_size > m_size ? m_size : a_new_size), new_array);
    m_array = new_array;
    m_size = a_new_size;
}

namespace
{
    Tab create()
    {
        tep::Tab res;
        res.set_size(5);
        return std::move(res);
    }
}

void Tab::test_class()
{
    Tab c_tab = create();
}
