//
// Author: jakubszwedowicz
// Date: 18.01.2022.
// e-mail: kuba.szwedowicz@gmail.com 
//

#ifndef PROJECT_INDIVIDUAL_HPP
#define PROJECT_INDIVIDUAL_HPP


#include <vector>
#include <random>

#include "Unique_Ptr.hpp"

class Optimizer;
class Individual
{
public:
    // CTOR
    Individual() noexcept;

    Individual(std::mt19937& a_genotype_generator, int a_genotype_size) noexcept;

    Individual(Individual&&) = default;

    Individual(const Individual&) = delete;

    Individual& operator=(const Individual&) = default;

    Individual& operator=(Individual&&) = default;

    // FUNCTIONS
    bool operator<(const Individual &a_other) const;
    bool operator>(const Individual &a_other) const;

    // Getters
    int get_score() const noexcept;

    const std::vector<bool>& get_genotype() const noexcept;

    // SETTERS
    void update_score(int a_newScore) noexcept;

    friend class Optimizer;
private:
    std::vector<bool> m_genotype;
    int m_score;
};

//std::mt19937 Individual::m_crossing_generator;
#endif //PROJECT_INDIVIDUAL_HPP
