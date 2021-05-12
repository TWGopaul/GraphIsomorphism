//Program: graph.h (Updated from Lab10)
//Author: Mitchell Krystofiak
//Description: Graph class definition.
//Date: April 29
//, 2021

#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <vector>
#include <queue>
#include <iostream>

//Project 3 thoughts
//For isomorphism class, maybe have an overloaded operator == to compare two graphs.
//If graphs are equal, then we automatically have an automorphism. Implement BFS for
//the isomorphism searching, then we can check for "edge preserving" isomorphisms.

enum color_t { WHITE, GRAY, BLACK };
enum graph_type { UNDIRECTED, DIRECTED };

template <class T>
class Graph
{
	private:	
		//Vertex tracking map
		std::map<T, std::vector<T>> vertices;
		
		//DFS tracking maps
		std::map<int, int> discovery;
		std::map<int, int> finish;

		graph_type graph_t;

		int time;
		bool isDAG;

		//edge and vertex count
		int count_v;
		int count_e;

		//DFS assister
		void DFSvisit(int,int, std::map<int, color_t> &, std::map<int, int> &);
	public:
		//Default constructor == graph will be undirected
		Graph();

		//Constructor == Decides undirected/directed
		Graph(const graph_type &);

		//Copy Constructor
		Graph(const Graph<T> &);

		//Destructor
		~Graph();

		// operator=
		void operator=(const Graph &);

		//Adds a Vertex
		void addVertex(T);

		//Adds an Edge
		void addEdge(T, T);

		//Prints the graph
		void print();

		//Prints the BFS searching algorithm
		void printBFS(T);

		//Prints the DFS searching algorithm
		void printDFS(int);

		//Topological sort algorithm
		void topSortPrint();

		//Returns true if empty graph
		bool is_empty();

		//Returns the graph type
		graph_type getGraphType();
		
		//Strongly Connected Components
                void SCCprint();
                void SCCvisit(int, std::map<int, color_t> &);

		//PROJECT 3 FUNCTIONS

		bool is_iso(Graph<T> &);

		bool is_aut(const Graph<T> &, const Graph<T> &);
		
		int getVertexCount();	
		
		int getEdgeCount();

		std::map<T, int> degreeSeqMap();

		std::map<T,int> degreeSeqMap(std::map<T,std::vector<T>>);
		
		std::map<T, std::vector<T>> zeroMap();

		//still need this function for comparing degree sequences
		std::vector<int> degreeSeqVect(int);

		bool degreeSeqComp(std::vector<int>, std::vector<int>);
		
		//returns true if H's adj lists are permutations of G's adj lists
		//takes G's and H's deg sequence vectors and H's vertex map as parameters
		bool permutation(std::map<T,int>, std::map<T,int>, std::map<T,std::vector<T>> &, std::map<T,std::vector<T>> &);
};
	
#include "graph.cpp"
#endif
