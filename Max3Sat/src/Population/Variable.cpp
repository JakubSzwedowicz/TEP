//
// Author: jakubszwedowicz
// Date: 18.01.2022.
// e-mail: kuba.szwedowicz@gmail.com 
//

#include <stdexcept>

#include "Variable.hpp"

Variable::Variable(int a_number) : m_number(a_number)
{
    if(a_number <= 0) throw std::invalid_argument("Variable number cannot be non-positive!");
}

void Variable::add_clause(const Clause* a_clause)
{
    m_clauses.push_back(a_clause);
}

const std::vector<const Clause*>& Variable::get_clauses() const noexcept
{
    return m_clauses;
}

int Variable::get_number() const noexcept
{
    return m_number;
}
