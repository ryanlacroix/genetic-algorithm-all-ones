#include <iostream>
#include "Population.h"

using namespace std;

Population::Population(int size)
  : population(new Individual*[size]), popSize(size),
    populationFitness(-1)
{}
Population::Population(int size, int cLength)
  : population(new Individual*[size]), popSize(size),
    populationFitness(-1)
{
  // Fill array with Individual objects
  for (int i = 0; i < size; i++){
    population[i] = new Individual(cLength);
  }
}

Population::~Population()
{
  for (int i = 0; i < popSize; i++){
    delete population[i];
  }
  delete[] population;
}

void Population::removeIndividual(int index)
{
  if (index < popSize)
    delete population[index];
}

Individual* Population::getFittest(int rank)
{
  Individual** sortedPop;
  sortedPop = population;
  // Sort the population by fitness
  Individual* temp;
  for(int i = 0; i < popSize; i++){
    for(int j = 0;j < popSize - 1; j++){
      if(sortedPop[j]->getFitness() < sortedPop[j+1]->getFitness()){
        temp = sortedPop[j];
        sortedPop[j] = sortedPop[j+1];
        sortedPop[j+1] = temp;
      }
    }
  }
  return sortedPop[rank];
}

Individual* Population::setIndividual(Individual* newInd, int index)
{
  Individual* temp;
  temp = population[index];
  population[index] = newInd;
  return temp;
}
void Population::setPopulationFitness(double fit){ populationFitness = fit; }
double Population::getPopulationFitness()       { return populationFitness; }
int Population::size()                                    { return popSize; }
Individual* Population::getIndividual(int index){ return population[index]; }

Individual** Population::getPopulation()
{
  return population;
}
