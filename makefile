all: run

run: main.o
	g++ -std=c++11 main.o -o run

main.o: graph.h graph.cpp main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm -rf *.o run

