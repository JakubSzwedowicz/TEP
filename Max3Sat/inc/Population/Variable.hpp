//
// Author: jakubszwedowicz
// Date: 18.01.2022.
// e-mail: kuba.szwedowicz@gmail.com 
//

#ifndef PROJECT_VARIABLE_HPP
#define PROJECT_VARIABLE_HPP
#include <vector>
#include <bitset>

class Clause;
class Variable
{
public:
    Variable(int a_number);
    void add_clause(const Clause* a_clause);
    const std::vector<const Clause*>& get_clauses() const noexcept;
    int get_number() const noexcept;
private:
    const int m_number;
    std::vector<const Clause*> m_clauses;
};


#endif //PROJECT_VARIABLE_HPP
