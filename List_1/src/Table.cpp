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
    std::cout << "parametr: '" << m_name << "'" << std::endl;
}

Table::Table(Table& a_other) : m_name(a_other.m_name + "_copy"), m_size(a_other.m_size)
{
    m_array = new int[m_size];
    memcpy(m_array, a_other.m_array, sizeof(int) * m_size);
    std::cout << "kopiuj: '" << m_name << "'" << std::endl;
}

Table::~Table()
{

}

void Table::set_name(std::string a_name)
{

}

bool Table::set_new_size(int a_new_size)
{
    return false;
}

Table* Table::clone()
{
    return NULL;
}
