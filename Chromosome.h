#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include "defs.h"
class Chromosome {
friend class Individual;
  public:
    Chromosome(int[], int);
      /* Generates chromosome from input array     */
    Chromosome(int);
      /* Generates random sequence of defined size */
    ~Chromosome();
    int getSize();
    int* getSequence();
  private:
    int* sequence;
    int size;
};
#endif
