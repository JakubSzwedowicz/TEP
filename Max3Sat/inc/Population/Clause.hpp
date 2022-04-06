//
// Author: jakubszwedowicz
// Date: 18.01.2022.
// e-mail: kuba.szwedowicz@gmail.com 
//

#ifndef PROJECT_CLAUSE_HPP
#define PROJECT_CLAUSE_HPP
#include "tuple"

class Clause
{
public:
    Clause(int a_x, int a_y, int a_z) noexcept;
    bool is_met(int a_x, int a_y, int a_z) const noexcept;
    bool is_met(bool a_x_sign, bool a_y_sign, bool a_z_sign) const noexcept;
    const std::array<int, 3>& get_formula() const noexcept;
private:
    std::array<int, 3> m_formula;
};


#endif //PROJECT_CLAUSE_HPP
