#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#include "GeneticAlgorithm.h"
#include "Population.h"

GeneticAlgorithm::GeneticAlgorithm(int pop, double mut, double cross, int elite)
  : populationSize(pop), mutationRate(mut), crossoverRate(cross), elitismCount(elite)
{}

Population* GeneticAlgorithm::makePopulation(int cLength)
// Note: size comes from Genetic Algorithm containing population
{
  Population* newPop;
  newPop = new Population(populationSize, cLength);
  return newPop;
}

bool GeneticAlgorithm::isTerminationConditionMet(Population* pop)
// Tests each individual for sufficient fitness
{
  int i;
  for (i = 0; i < populationSize; i++){
    if ((pop->getIndividual(i))->getFitness() == 1){
      return true;
    }
  }
  return false;
}

Individual* GeneticAlgorithm::selectParent(Population* pop)
{
  // Calculate position of individual to breed
  double popFitness = pop->getPopulationFitness();
  double rouletteWheelPosition = (rand()/double(RAND_MAX)) * popFitness;

  int i;
  double spinWheel = 0;
  for (i = 0; i < populationSize; i++){
    spinWheel += (pop->getIndividual(i))->getFitness();
    if (spinWheel > rouletteWheelPosition){
      return pop->getIndividual(i);
    }
  }
  return pop->getIndividual(populationSize - 1);
}

Population* GeneticAlgorithm::mutatePopulation(Population* pop)
{
  int i;
  for (i = 0; i < pop->size(); i++){
    Individual* currInd;
    currInd = pop->getFittest(i);
    if (i >= elitismCount){
      // Skip over elite
      int o;
      for (o = 0; o < currInd->getChromosomeLength(); o++){
        // Iterate through genome
        if ((rand()/double(RAND_MAX)) < mutationRate){
          // Apply random mutations
          if (currInd->getGene(o) == 1){
            currInd->setGene(o, 0);
          } else {
            currInd->setGene(o, 1);
          }
        }
      }
    }
  }
  return pop;
}

Population* GeneticAlgorithm::crossoverPopulation(Population* pop)
{
  // Loop through individuals in order of fitness
  int i;
  for (i = 0; i < pop->size(); i++){
    Individual* p1 = pop->getFittest(i);

    // Determine if individual should breed
    if (crossoverRate > (rand()/double(RAND_MAX)) && i > elitismCount){
      Individual* offspring;
      Individual* p2;
      offspring = new Individual(p1->getChromosomeLength());
      p2 = selectParent(pop);
      // Build genome
      int o;
      for (o = 0; o < p1->getChromosomeLength(); o++){
        if ((rand()/double(RAND_MAX)) > 0.5){
          offspring->setGene(o, p1->getGene(o));
        } else {
          offspring->setGene(o, p2->getGene(o));
        }
      }
      pop->removeIndividual(i);
      pop->setIndividual(offspring, i);

    } else {
      pop->setIndividual(p1, i);
    }
  }
  return pop;
}

double GeneticAlgorithm::calcFitness(Individual* indiv)
// Calculate fitness based on number of ones in chromosome
{
  int numberOfOnes = 0;
  int i;
  // Determine number of ones
  for (i = 0; i < indiv->getChromosomeLength(); i++){
    if (indiv->getGene(i) == 1){
      numberOfOnes++;
    }
  }
  // Calculate fitness rating
  double fitness = ((double(numberOfOnes))/double(indiv->getChromosomeLength()));
  indiv->setFitness(fitness);
  return fitness;
}

void GeneticAlgorithm::evalPopulation(Population* pop)
// Evaluate fitness of each individual in population
{
  double totalFitness = 0;
  int i;
  for (i = 0; i < populationSize; i++){
    totalFitness += calcFitness((pop->getIndividual(i)));
  }
  pop->setPopulationFitness(totalFitness);
}



