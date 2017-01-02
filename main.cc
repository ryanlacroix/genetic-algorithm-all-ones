/*                                                  */
/*        This is the All Ones problem.             */
/* Simple algorithm to evolve a string of just ones */
/*        Started February 10th 2016                */
/*               Ryan Lacroix                       */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "GeneticAlgorithm.h"
#include "Population.h"
#include "Individual.h"

using namespace std;

int main()
{
  srand( time( NULL ) ); // Initialize the random function seed
  GeneticAlgorithm ga(POP_SIZE, MUTATION_RATE, CROSSOVER_RATE, ELITE_COUNT); // pop, mut, cros, elit
  Population* population = ga.makePopulation(CHROM_SIZE);

  ga.evalPopulation(population); // Initial evaluation
  int generation = 1;

  while (ga.isTerminationConditionMet(population) == false)
  {

    // Print fittest individual's chromosome
    cout << "Best solution: "; (population->getFittest(0))->printChromosome(); cout << " Gen " << generation <<  endl;

    // Apply crossover
    population = ga.crossoverPopulation(population);
    ga.evalPopulation(population);

    // Apply mutation
    population = ga.mutatePopulation(population);

    // Next generation
    generation++;
  }

  cout << "Solution found in " << generation << " generations." << endl;
  cout << "Solution: "; (population->getFittest(0))->printChromosome(); cout << endl;

  // Clean up
  delete population;
}
