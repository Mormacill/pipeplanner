#REV1.0

default:pipe

pipe: rrf.o main.o
	g++ -g -o pipe rrf.o main.o

rrf.o: rrf.cpp
	g++ -g -c rrf.cpp

main.o: main.cpp rrf.h
	g++ -g -c main.cpp

clean:
	rm *.o
