#ifndef POPULATION_H
#define POPULATION_H

#include "defs.h"
#include "Individual.h"

class Population {
  public:
    Population(int);
      /* Input: population size                   */
      /* Note: This population array is empty     */

    Population(int, int);
      /* Input: population size, chromosome length*/
      /*  Note: Fills population array with       */
      /*        Individuals containing randomly   */
      /*        generated chromosomes             */

    ~Population();
       /* Destructor. Cleans out Population** */

    Individual** getPopulation();

    Individual* getFittest(int);
      /*  Input: Rank of individual. 0 is highest */
      /* Output: Individual at given rank         */

    void removeIndividual(int);
      /* Deletes individual in old population     */
      /* Only use when replacing with offspring   */

    void setPopulationFitness(double);
    double getPopulationFitness();
    int size();
    Individual* setIndividual(Individual*, int);
    Individual* getIndividual(int);

    // Might need to add a shuffle later

  private:
    Individual** population;
    int populationFitness;
    int popSize;
};
#endif
