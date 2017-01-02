All-ones
========
A C++ implementation of the all-ones problem. A population is generated consisting of individuals each containing a chromosome, represented by a random string of 1s and 0s. Individuals breed with eachother, producing offspring whose genetic makeup is a random mix of both parents as well as the occasional mutation (where one or more gene is randomly changed with no relation to the parents' genetics). If an individual becomes marked as 'elite', that is, if their fitness score is in some specified top percentile, they are immune to mutations. This helps to preserve good genetics and get the next generation of offspring closer to the solution. A solution is found when a string is generated consisting of only 1s.

Mutation rate, population size, chromosome size, crossover rate and number of protected elites all profoundly effect the speed and/or possibility of finding a solution. These values can be optimized using the `#define` statements found in defs.h

Sample solution
---------------
```
Best solution: 11011111111101001001011101111101000 Gen 1
Best solution: 01001110100111111100111111001101111 Gen 2
Best solution: 01001110100111111100111111001101111 Gen 3
Best solution: 01001110100111111100111111001101111 Gen 4
Best solution: 00111110110111101011111100110111101 Gen 5
Best solution: 11110110111111110001011111101101011 Gen 6
Best solution: 11110110111111110001011111101101011 Gen 7
Best solution: 11110110110111110101111111101011011 Gen 8
Best solution: 11110110110111110101111111101011011 Gen 9
Best solution: 11110110110111110101111111101011011 Gen 10
Best solution: 11011111111101011011111101111100111 Gen 11
Best solution: 11110111111011001111111111101011111 Gen 12
Best solution: 11110111111011001111111111101011111 Gen 13
Best solution: 01110111111111101111111111100111111 Gen 14
Best solution: 01110111111111101111111111100111111 Gen 15
Best solution: 01110111111111101111111111100111111 Gen 16
Best solution: 01110111111111101111111111100111111 Gen 17
Best solution: 01110111111111101111111111100111111 Gen 18
Best solution: 01110111111111101111111111100111111 Gen 19
Best solution: 01110111111111101111111111100111111 Gen 20
Best solution: 01110111111111101111111111100111111 Gen 21
Best solution: 10011110111111111111111101111111111 Gen 22
Best solution: 10011110111111111111111101111111111 Gen 23
Best solution: 10011110111111111111111101111111111 Gen 24
Best solution: 10011110111111111111111101111111111 Gen 25
Best solution: 10011110111111111111111101111111111 Gen 26
Best solution: 11111111111111110101111111111110111 Gen 27
Best solution: 11111111111111110101111111111110111 Gen 28
Best solution: 11111111111111110101111111111110111 Gen 29
Best solution: 11111111111111110101111111111110111 Gen 30
Best solution: 11111111111111110101111111111110111 Gen 31
Best solution: 11111111111111110101111111111110111 Gen 32
Best solution: 11111111111111110101111111111110111 Gen 33
Best solution: 11111111111111110101111111111110111 Gen 34
Best solution: 11111111111111110101111111111110111 Gen 35
Best solution: 11111111111111110101111111111110111 Gen 36
Best solution: 11111111111111110101111111111110111 Gen 37
Best solution: 11111111111111110101111111111110111 Gen 38
Best solution: 11111111111111110101111111111110111 Gen 39
Best solution: 11111111111101111110111111111111111 Gen 40
Best solution: 11111111111101111110111111111111111 Gen 41
Solution found in 42 generations.
Solution: 11111111111111111111111111111111111
```