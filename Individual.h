#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include <string>
#include "defs.h"
#include "Chromosome.h"

class Individual {

  public:
    Individual(int[], int);
      /* takes array of genes, size of chromosome*/

    Individual(int);
      /* takes size of chromosome                */
      /* generates chromosome randomly           */

    ~Individual();

    Chromosome* getChromosome();
    int   getChromosomeLength();
    void      setGene(int, int);
    int            getGene(int);
    void     setFitness(double);
    double         getFitness();
    
    void      printChromosome();
  private:
    Chromosome* chromosome;
    double fitness;
};

#endif
