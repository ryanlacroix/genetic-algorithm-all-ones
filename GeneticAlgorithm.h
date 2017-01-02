#ifndef GALGORITHM_H
#define GALGORITHM_H
#include "Population.h"

class GeneticAlgorithm {

  public:
    GeneticAlgorithm(int, double, double, int);
      /* Population size, mutation rate, crossover rate, elitism */

    Population* makePopulation(int);
      /* Input: Desired length of chromosomes         */

    double calcFitness(Individual*);
      /* Calculate the fitness of an individual       */
      /* Called by evalPopulation()                   */

    void evalPopulation(Population*);
      /* Calls calcFitness on every individual        */

    Population* mutatePopulation(Population*);
      /* Mutate population when appropriate           */

    bool isTerminationConditionMet(Population*);
      /* Tests each individual for sufficient fitness */

    Individual* selectParent(Population*);
    Population* crossoverPopulation(Population*);

  private:
    int populationSize;
    double mutationRate;
    double crossoverRate;
    int elitismCount;
};


#endif
