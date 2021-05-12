all: run

run: main.o timer.o
	g++ -std=c++11 main.o timer.o -o run

main.o: graph.h graph.cpp main.cpp
	g++ -std=c++11 -c main.cpp

timer.o: timer.cpp
	g++ -std=c++11 -c timer.cpp
clean:
	rm -rf *.o run

