//
// Author: jakubszwedowicz
// Date: 18.01.2022.
// e-mail: kuba.szwedowicz@gmail.com 
//

#include "Individual.hpp"
#include "Util.hpp"

Individual::Individual() noexcept
        : m_genotype(), m_score(0)
{

}

Individual::Individual(std::mt19937& a_genotype_generator, int a_genotype_size) noexcept
        : m_genotype(std::move(rand_vector(a_genotype_generator, a_genotype_size + 1))), m_score(0)
{

}

int Individual::get_score() const noexcept
{
    return m_score;
}

const std::vector<bool>& Individual::get_genotype() const noexcept
{
    return m_genotype;
}

void Individual::update_score(int a_newScore) noexcept
{
    m_score = a_newScore;
}

bool Individual::operator<(const Individual& a_other) const
{
    return m_score < a_other.m_score;
}

bool Individual::operator>(const Individual& a_other) const
{
    return m_score > a_other.m_score;
}
