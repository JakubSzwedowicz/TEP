#pragma once

#include <random>
#include <vector>

#include "Max3Sat.hpp"
#include "Unique_Ptr.hpp"
//#include "Population_Overseer.hpp"

class Population_Overseer;
class Individual;
class Optimizer
{
public:
    // CTORs
    Optimizer(tep::Unique_Ptr<Problem>&& a_problem) noexcept;
    ~Optimizer()
    {};

    // FUNCTIONS
    void load_instance(const std::string& a_filename) noexcept;
    void initialize();
    void run_iteration();

    void crossover_mutate(Individual& a_child1, Individual& a_child2, Individual& a_parent1, Individual& a_parent2) noexcept;
    void preserve_population(std::vector<Individual>& a_newPopulation, std::vector<Individual>& a_oldPopulation) noexcept;

    Individual& fightclub(std::vector<Individual>& a_population) noexcept;

    // GETTERS
    const Individual& get_best_individual() const noexcept;
    int get_best_score() const noexcept;

private:
    // FUNCTIONS
    inline bool apply_crossing() noexcept;
    inline void crossing(Individual& a_child1, Individual& a_child2, const Individual& a_parent1, const Individual& a_parent2, int a_gene) noexcept;
    inline void mutation(Individual& a_child1, Individual& a_child2, int a_gene) noexcept;

    // MEMBERS
    Individual* m_best_found;
    tep::Unique_Ptr<Problem> m_problem;
    tep::Unique_Ptr<Population_Overseer> m_population_overseer;  // Class managing the population

    // MEMBERS FOR RANDOMNESS
    const int m_preserve_population_threshold = 20;
    int m_preserved_individuals_number;

    const int m_crossing_threshold = 80;
    std::mt19937 m_crossing_generator;
    const int m_mutation_threshold = 30;
    std::mt19937 m_mutation_generator;
    std::mt19937 m_fightclub_generator;


};//class Optimizer


