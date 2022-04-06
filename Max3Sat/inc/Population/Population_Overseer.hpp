//
// Author: jakubszwedowicz
// Date: 18.01.2022.
// e-mail: kuba.szwedowicz@gmail.com 
//

#ifndef PROJECT_POPULATION_OVERSEER_HPP
#define PROJECT_POPULATION_OVERSEER_HPP
#include <array>
#include <random>

#include "Individual.hpp"

class Problem;
class Optimizer;
class Population_Overseer
{
public:
    // CTORs
    Population_Overseer(Optimizer& a_optimizer, const Problem& a_problem, int a_genotype_size, int a_population_size);
    ~Population_Overseer() = default;

    // FUNCTIONS
    void advance_population() noexcept;

    // GETTERS
    int get_generation_number() const noexcept;
    int get_curr_best_score() const noexcept;
    Individual& get_curr_best_individual() const noexcept;
    int get_best_score() const noexcept;
    const Individual& get_best_individual() const noexcept;
    float get_best_fitness() const noexcept;
private:
    void initialize_population(std::vector<Individual>& a_population) noexcept;
    void update_best(Individual& a_child1, Individual& a_child2) noexcept;

    const int m_genotype_size;
    int m_population_size;
    int m_generation_number;

    std::mt19937 m_genotype_generator;
    std::mt19937 m_extra_generator;

    const Problem& m_problem;
    Optimizer& m_optimizer;

    std::vector<Individual> m_old_generation;
    std::vector<Individual> m_new_generation;
    int m_curr_best_score;
    Individual* m_best_curr_individual;
    int m_best_score;
    Individual m_best_individual;
};


#endif //PROJECT_POPULATION_OVERSEER_HPP
