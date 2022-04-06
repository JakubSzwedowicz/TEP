//
// Author: jakubszwedowicz
// Date: 18.01.2022.
// e-mail: kuba.szwedowicz@gmail.com 
//

#include <iostream>
#include <exception>

#include <cmath>

#include "Clause.hpp"

Clause::Clause(int a_x, int a_y, int a_z) noexcept
        : m_formula({a_x, a_y, a_z})
{

}

bool Clause::is_met(int a_x, int a_y, int a_z) const noexcept
{
    return m_formula[0] == a_x && m_formula[1] == a_y && m_formula[2] == a_z;
}

bool Clause::is_met(bool a_x_sign, bool a_y_sign, bool a_z_sign) const noexcept
{
    return std::signbit(m_formula[0]) == a_x_sign
           && std::signbit(m_formula[1]) == a_y_sign
           && std::signbit(m_formula[2]) == a_z_sign;
}

const std::array<int, 3>& Clause::get_formula() const noexcept
{
    return m_formula;
}
