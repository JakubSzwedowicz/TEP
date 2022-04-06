//
// Author: jakubszwedowicz
// Date: 16.12.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//
#include "Control_Block.hpp"

using namespace tep;

Control_Block::Control_Block() : m_counter(0)
{

}

int Control_Block::get_counter() const
{
    return m_counter;
}

int Control_Block::is_valid() const
{
    return m_counter != 0;
}

void Control_Block::decrement()
{
    m_counter--;
}

void Control_Block::increment()
{
    m_counter++;
}

