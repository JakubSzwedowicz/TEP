#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <stdexcept>

#include "Max3Sat.hpp"
#include "Optimizer.hpp"

Max3Sat::Max3Sat() noexcept
{
    m_clauses.reserve(s_DEFAULT_VARIABLES_SIZE);
    m_clauses.emplace_back(-99999, -99999, -99999);    // empty clause to fill the array

    m_variables.reserve(s_DEFAULT_VARIABLES_SIZE);
    m_variables.emplace_back(999999);    // empty clause to fill the array
}

Max3Sat::~Max3Sat() noexcept
{

}

bool Max3Sat::load(const std::string& a_filename) noexcept
{
    std::ifstream file(a_filename);
    if (file.is_open())
    {
        std::string skip;
        int number_of_variables = 1;

        float fx, fy, fz;  // there are negative zeros (-0) so float needs to be used
        while (file >> skip >> fx >> fy >> fz >> skip)
        {
            //[0, 49]
            //[-50, -1]U[1, 50]
            int ix = static_cast<int>(std::signbit(fx) == 1 ? -fx - 1 : fx + 1); // Gives -1 or +1 for -0 or +0
            int iy = static_cast<int>(std::signbit(fy) == 1 ? -fy - 1 : fy + 1);
            int iz = static_cast<int>(std::signbit(fz) == 1 ? -fz - 1 : fz + 1);

            m_clauses.emplace_back(ix, iy, iz);
            number_of_variables = std::max({ix, iy, iz, number_of_variables});
        }
        file.close();
        build_variables(number_of_variables);
        return true;
    } else
    {
        std::cout << "File could not be opened!" << std::endl;
        return false;
    }
}

float Max3Sat::evaluate(std::vector<bool>& a_genotype) const noexcept
{

    return matched_cases(a_genotype) / (m_clauses.size() - 1);
}

int Max3Sat::matched_cases(const std::vector<bool>& a_genotype) const noexcept
{
    int score = 0;
    for (auto clause = m_clauses.cbegin() + 1; clause != m_clauses.cend(); clause++)
    {
        auto& formula = clause->get_formula();
        score += clause->is_met(a_genotype[std::abs(formula[0])], a_genotype[std::abs(formula[1])],
                                a_genotype[std::abs(formula[2])]);
    }
    return score;
}

int Max3Sat::get_number_of_variables()
{
    return m_variables.size() - 1;
}


int Max3Sat::get_number_of_clauses()
{
    return m_clauses.size() - 1;
}


void Max3Sat::build_variables(int a_number_of_variables) noexcept
{
    for(int i = 1; i < a_number_of_variables + 1; i++)
        m_variables.emplace_back(i) ;

    for (auto clause = m_clauses.cbegin() + 1; clause != m_clauses.cend(); clause++)
    {
        auto& formula = clause->get_formula();
        m_variables[std::abs(formula[0])].add_clause(clause.base());
        m_variables[std::abs(formula[1])].add_clause(clause.base());
        m_variables[std::abs(formula[2])].add_clause(clause.base());
    }
}

void Max3Sat::run()
{
    try
    {
        Optimizer opt(tep::Unique_Ptr<Problem>(new Max3Sat()));
//        opt.load_instance("max3sat/200/m3s_200_0.txt");
        opt.load_instance("max3sat/50/m3s_50_0.txt");
        opt.initialize();

        for (int i = 0; i < 1000; i++)
            opt.run_iteration();

        int* res_array;
        int res_length;
        std::cout << "Best result: " << opt.get_best_score() << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << "Should not happened: " << ex.what() << std::endl;
    }
}
