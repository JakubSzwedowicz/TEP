//
// Author: jakubszwedowicz
// Date: 18.01.2022.
// e-mail: kuba.szwedowicz@gmail.com 
//

#ifndef PROJECT_PROBLEM_HPP
#define PROJECT_PROBLEM_HPP

#include <vector>
#include <string>

class Problem
{
public:
    virtual ~Problem()
    {};

    virtual void run() = 0;

    virtual bool load(const std::string& a_filename) = 0;

    virtual float evaluate(std::vector<bool>& a_genotype) const noexcept = 0;

    virtual int matched_cases(const std::vector<bool>& a_genotype) const noexcept = 0;

    virtual int get_number_of_variables() = 0;

    virtual int get_number_of_clauses() = 0;

};


#endif //PROJECT_PROBLEM_HPP
