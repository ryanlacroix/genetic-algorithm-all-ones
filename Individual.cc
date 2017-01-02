#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

#include "Individual.h"
#include "Chromosome.h"

Individual::Individual(int chrom[], int size) // Cuts off digits past size
{
  chromosome = new Chromosome(chrom, size);
}
Individual::Individual(int size)
{
  chromosome = new Chromosome(size);
}

Individual::~Individual()
{
  delete chromosome;
}

Chromosome* Individual::getChromosome(){ return chromosome; }
int Individual::getChromosomeLength(){ return chromosome->getSize(); }
void Individual::setGene(int offset, int gene){ chromosome->sequence[offset] = gene; }
int Individual::getGene(int offset){ return chromosome->sequence[offset]; }
void Individual::setFitness(double fit){ fitness = fit; }
double Individual::getFitness(){ return fitness; }
void Individual::printChromosome()
{
  int size;
  int i;
  size = chromosome->getSize();
  for (i = 0; i < size; i++){
    cout << getGene(i);
  }
}

