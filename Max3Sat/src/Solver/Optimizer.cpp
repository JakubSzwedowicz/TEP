#include <iostream>
#include <algorithm>

#include "Population_Overseer.hpp"
#include "Optimizer.hpp"
#include "Problem.hpp"
#include "Unique_Ptr.hpp"
#include "Individual.hpp"

Optimizer::Optimizer(tep::Unique_Ptr<Problem>&& a_problem) noexcept
        : m_problem(std::move(a_problem))
{

}

void Optimizer::load_instance(const std::string& a_filename) noexcept
{
    m_problem->load(a_filename);
}

void Optimizer::initialize()
{
    m_population_overseer.reset(new Population_Overseer(*this, *m_problem, m_problem->get_number_of_variables(),
                                                        m_problem->get_number_of_clauses()));
    m_preserved_individuals_number = static_cast<int>((m_preserve_population_threshold / 100.0) * m_problem->get_number_of_clauses());
}

void Optimizer::run_iteration()
{
    m_population_overseer->advance_population();
    std::cout << "Iteration " << m_population_overseer->get_generation_number() << ": best score = "
              << m_population_overseer->get_best_score() << std::endl;
}

void Optimizer::crossover_mutate(Individual& a_child1, Individual& a_child2, Individual& a_parent1,
                                 Individual& a_parent2) noexcept
{
    if (!apply_crossing()) // Mutation alone
    {
        // No Crossing
        a_child1.m_genotype = a_parent1.m_genotype;
        a_child2.m_genotype = a_parent2.m_genotype;

        // Mutation
        for (int i = 1; i < a_child1.m_genotype.size() + 1; i++)  // TODO: Ugly +1
        {
            mutation(a_child1, a_child2, i);
        }
    } else  // Crossing + Mutation
    {
        for (int i = 1; i < a_child1.m_genotype.size() + 1; i++)
        {
            // Crossing
            crossing(a_child1, a_child2, a_parent1, a_parent2, i);

            // Mutation
            mutation(a_child1, a_child2, i);
        }
    }
}

void Optimizer::preserve_population(std::vector<Individual>& a_newPopulation,
                                    std::vector<Individual>& a_oldPopulation) noexcept
{
    a_oldPopulation.swap(a_newPopulation);
    std::partial_sort(std::begin(a_newPopulation), std::begin(a_newPopulation) + m_preserved_individuals_number,
                      std::end(a_newPopulation), std::greater<Individual>());
    std::swap_ranges(std::begin(a_newPopulation), std::begin(a_newPopulation) + m_preserved_individuals_number,
                       std::begin(a_oldPopulation));
}

Individual& Optimizer::fightclub(std::vector<Individual>& a_population) noexcept
{
    int first = m_fightclub_generator() % a_population.size();
    int second = m_fightclub_generator() % a_population.size();

    return a_population[first].m_score >= a_population[second].m_score ? a_population[first]
                                                                       : a_population[second];
}

const Individual& Optimizer::get_best_individual() const noexcept
{
    return m_population_overseer->get_best_individual();
}

int Optimizer::get_best_score() const noexcept
{
    return m_population_overseer->get_best_score();
}


void Optimizer::crossing(Individual& a_child1, Individual& a_child2, const Individual& a_parent1,
                         const Individual& a_parent2, int a_gene) noexcept
{
    if (m_crossing_generator() % 100 < m_crossing_threshold)
        a_child1.m_genotype[a_gene] = a_parent1.m_genotype[a_gene];
    if (m_crossing_generator() % 100 < m_crossing_threshold)
        a_child1.m_genotype[a_gene] = a_parent2.m_genotype[a_gene];
    a_child2.m_genotype[a_gene] = !a_child1.m_genotype[a_gene];
}

void Optimizer::mutation(Individual& a_child1, Individual& a_child2, int a_gene) noexcept
{
    if (m_mutation_generator() % 100 < m_mutation_threshold)
        a_child1.m_genotype[a_gene] = !a_child1.m_genotype[a_gene];
    if (m_mutation_generator() % 100 < m_mutation_threshold)
        a_child2.m_genotype[a_gene] = !a_child2.m_genotype[a_gene];
}

bool Optimizer::apply_crossing() noexcept
{
    return m_crossing_generator() % 100 >= m_crossing_threshold;
}
