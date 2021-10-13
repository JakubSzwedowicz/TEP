//
// Author: JakubSzwedowicz
// Date: 12.10.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//

#include <iostream>
#include <cstring>
#include "Table.hpp"

Table::Table() : m_name("Default table name"), m_size(10)
{
    m_array = new int[m_size];
    std::cout << "bezp: '" << m_name << "'" << std::endl;
}

Table::Table(std::string a_name, int a_size) : m_name(a_name), m_size(a_size)
{
    if (m_size <= 0)
    {
        m_size = 1;
    }
    m_array = new int[m_size];
    std::cout << "parametr: '" << m_name << "'" << std::endl;
}

Table::Table(Table& a_other) : m_name(a_other.m_name + "_copy"), m_size(a_other.m_size)
{
    m_array = new int[m_size];
    memcpy(m_array, a_other.m_array, sizeof(int) * m_size);
    std::cout << "kopiuj: '" << m_name << "'" << std::endl;
}

Table& Table::operator=(const Table& a_table)
{
    std::cout << "operator=" << std::endl;
    if (this == &a_table)
    {
        return *this;
    }
    delete[] m_array;
    m_size = a_table.m_size;
    m_name = a_table.m_name;
    m_array = new int[m_size];
    memcpy(m_array, a_table.m_array, sizeof(int) * m_size);
    return *this;
}

Table::~Table()
{
    std::cout << "DTOR" << std::endl;
    delete[] m_array;
}

void Table::set_name(std::string a_name)
{
    m_name = a_name;
}

bool Table::set_new_size(int a_new_size)
{
    if (a_new_size <= 0)
    {
        return false;
    }
    int* new_array = new int[a_new_size];
    memcpy(new_array, m_array, sizeof(int) * (a_new_size > m_size ? m_size : a_new_size));
    delete[] m_array;
    m_array = new_array;
    return true;
}

Table* Table::clone()
{
    Table* t = new Table(*this);
    return t;
}

const std::string& Table::get_name() const
{
    return m_name;
}

int Table::get_size() const
{
    return m_size;
}

const int* Table::get_array() const
{
    return m_array;
}

std::ostream& operator<<(std::ostream& a_out, const Table& a_table)
{
    a_out << "name = " << a_table.m_name << ", size = " << a_table.m_size;
    a_out << ", array = [";
    for (int i = 0; i < a_table.m_size; i++)
    {
        a_out << " " << a_table.m_array[i];
    }
    a_out << "]";
    return a_out;
}



