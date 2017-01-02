#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

#include "Chromosome.h"

using namespace std;

Chromosome::Chromosome(int chrom[], int s)
  : size(s)
{
  sequence = new int[size];
  for (int i; i < size; i++){
    sequence[i] = chrom[i];
  }
}
Chromosome::Chromosome(int s)
  : size(s)
{
  sequence = new int[s];
  // Randomize each gene to binary value
  for (int i = 0; i < size; i++){
    sequence[i] = (rand() % 2);
  }
}
Chromosome::~Chromosome()
{
  delete[] sequence;
}
int Chromosome::getSize(){ return size; }
