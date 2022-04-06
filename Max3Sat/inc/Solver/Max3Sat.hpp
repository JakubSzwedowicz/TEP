#pragma once

#include <string>
#include <vector>
#include <tuple>

#include "Problem.hpp"
#include "Clause.hpp"
#include "Variable.hpp"

class Max3Sat : public Problem
{
public:
    Max3Sat() noexcept;

    ~Max3Sat() noexcept override;

    bool load(const std::string& a_filename) noexcept override;
    float evaluate(std::vector<bool>& a_genotype) const noexcept override;
    int matched_cases(const std::vector<bool>& a_genotype) const noexcept override;
    int get_number_of_variables() override;
    int get_number_of_clauses() override;
    void run() override;
protected:
private:
    void build_variables(int a_number_of_variables) noexcept;
    static const int s_DEFAULT_VARIABLES_SIZE = 50;
    std::vector<Variable> m_variables;
    std::vector<Clause> m_clauses;
};//class Max3Sat


