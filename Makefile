OBJ = main.o GeneticAlgorithm.o Individual.o Chromosome.o Population.o

gAlgo:	$(OBJ)
	g++ -o gAlgo $(OBJ)

main.o: main.cc GeneticAlgorithm.h Population.h Individual.h
	g++ -c main.cc

GeneticAlgorithm.o: GeneticAlgorithm.cc GeneticAlgorithm.h Population.h
	g++ -c GeneticAlgorithm.cc

Individual.o: Individual.cc Individual.h Chromosome.h
	g++ -c Individual.cc

Chromosome.o: Chromosome.cc Chromosome.h
	g++ -c Chromosome.cc

Population.o: Population.cc Population.h Individual.h
	g++ -c Population.cc

clean:
	rm -f *.o gAlgo

