//
// Author: jakubszwedowicz
// Date: 18.01.2022.
// e-mail: kuba.szwedowicz@gmail.com 
//

#include <iostream>

#include "Population_Overseer.hpp"
#include "Problem.hpp"
#include "Individual.hpp"
#include "Optimizer.hpp"

Population_Overseer::Population_Overseer(Optimizer& a_optimizer, const Problem& a_problem, int a_genotype_size, int a_population_size)
        : m_optimizer(a_optimizer)
        , m_problem(a_problem)
        , m_best_score(0)
        , m_curr_best_score(0)
        , m_best_individual()
        , m_best_curr_individual(nullptr)
        , m_genotype_size(a_genotype_size)
        , m_population_size(a_population_size)
        , m_generation_number(1)
{
    if (a_genotype_size <= 0 || a_population_size <= 0 || a_population_size % 2 == 0)   // == 0 because
        throw std::invalid_argument(
                std::string(__func__) + ": passed parameters can't be non-positive and population size has to be even");

    initialize_population(m_new_generation);
    initialize_population(m_old_generation);
}


void Population_Overseer::advance_population() noexcept
{
    for (auto it1 = m_new_generation.begin(), it2 = m_new_generation.begin() + 1;
         it2 != m_new_generation.end(); it1 += 2, it2 += 2)
    {
        Individual& parent1 = m_optimizer.fightclub(m_old_generation);
        Individual& parent2 = m_optimizer.fightclub(m_old_generation);
        m_optimizer.crossover_mutate(*it1, *it2, parent1, parent2);
        it1->update_score(m_problem.matched_cases(it1->get_genotype()));
        it2->update_score(m_problem.matched_cases(it2->get_genotype()));
        update_best(*it1, *it2);
    }
//    for(int i = 0; i < m_population_size; i++)
//    {
//        std::cout << std::endl;
//        for (int j = 0; j < m_genotype_size; j++)
//            std::cout << m_new_generation[i].m_genotype[j] << " ";
//        std::cout << std::endl;
//    }
    m_optimizer.preserve_population(m_new_generation, m_old_generation);
    m_generation_number++;
}

void Population_Overseer::initialize_population(std::vector<Individual>& a_population) noexcept
{
    a_population.reserve(m_population_size);
    for (int i = 0; i < m_population_size; i++)
    {
        a_population.emplace_back(m_genotype_generator, m_genotype_size);
    }
}

int Population_Overseer::get_generation_number() const noexcept
{
    return m_generation_number;
}

void Population_Overseer::update_best(Individual& a_child1, Individual& a_child2) noexcept
{
    Individual& better_child = a_child1.get_score() > a_child2.get_score() ? a_child1 : a_child2;

    if (better_child.get_score() > m_curr_best_score)
    {
        m_curr_best_score = better_child.get_score();
        m_best_curr_individual = &better_child;

        if (m_curr_best_score > m_best_score)
        {
            m_best_score = m_curr_best_score;
            m_best_individual = *m_best_curr_individual;
        }
    }
}

int Population_Overseer::get_curr_best_score() const noexcept
{
    return m_curr_best_score;
}

Individual& Population_Overseer::get_curr_best_individual() const noexcept
{
    return *m_best_curr_individual;
}

int Population_Overseer::get_best_score() const noexcept
{
    return m_best_score;
}

const Individual& Population_Overseer::get_best_individual() const noexcept
{
    return m_best_individual;
}

float Population_Overseer::get_best_fitness() const noexcept
{
    return m_best_score / m_genotype_size;
}
