//Program: main.cpp
//Author: Mitchell Krystofiak
//Description: Testing algorithm for:
//	       - Depth First Search (DFS)
//	       - Topological Sort
//	       - Adding Vertices/Edges
//	       - Adjacency List Printing (if time permits)
//	       - Directed Acyclic Graphs (DAG)
//Date: April 28, 2021

#include <iostream>
#include "graph.h"
#include "timer.h"

using namespace std;

int main()
{
	Graph<int> G(UNDIRECTED);
	Graph<int> K(UNDIRECTED);

	//Graph H for testing permutations	
	Graph<int> H(UNDIRECTED);
	
	for (int i = 1; i < 9; i++)
	{
		G.addVertex(i);
		H.addVertex(i);
	}
	
	K.addVertex('A');
        K.addVertex('B');
        K.addVertex('C');
        K.addVertex('D');
        K.addVertex('E');
        K.addVertex('F');
        K.addVertex('G');
        K.addVertex('H');

	G.addEdge(1,2);
	G.addEdge(1,1);
	G.addEdge(1,5);
	G.addEdge(1,6);
	G.addEdge(6,3);
	G.addEdge(3,4);
	G.addEdge(4,8);
	G.addEdge(3,7);
	G.addEdge(7,4);
	//G.addEdge(9,1);

	K.addEdge('A','B');
	K.addEdge('A','A');
	K.addEdge('A','E');
	K.addEdge('A','F');
	K.addEdge('F','C');
	K.addEdge('C','D');
	K.addEdge('D','H');
	K.addEdge('C','G');
	K.addEdge('G','D');

	H.addEdge(1,2);
	H.addEdge(1,1);
	H.addEdge(1,5);
	H.addEdge(1,6);
	H.addEdge(6,3);
	H.addEdge(3,4);
	H.addEdge(4,8);
	H.addEdge(3,7);
	H.addEdge(7,4);

	cout << "Graph G: " << endl;
	G.print();
	cout << "Edge count: " << G.getEdgeCount() << endl;
	cout << "Vertex count: " << G.getVertexCount() << endl;
	cout << endl;

	cout << "Graph K: " << endl;
	K.print();
	cout << "Edge count: " << K.getEdgeCount() << endl;
	cout << "Vertex count: " << K.getVertexCount() << endl;
	cout << endl;
	
	cout << "Graph H: " << endl;
	H.print();
	cout << "Edge count: " << H.getEdgeCount() << endl;
	cout << "Vertex count: " << H.getVertexCount() << endl;
	cout << endl;

	cout << "Degree Seqeunces" << endl;
	cout << "----------------" << endl;
	cout << endl;
	cout << "Graph G: " << endl;
	std::vector<int> degG = G.degreeSeqVect(1);
	for (int i = 0; i < degG.size(); i++)
		cout << degG[i] << " ";
	cout << endl;
	cout << "Graph K: " << endl;
	std::vector<int> degK = K.degreeSeqVect(1);
	for (int i =0; i < degK.size(); i++)
		cout << degK[i] << " ";
	cout << endl;
	cout << "Graph H: " << endl;
	std::vector<int> degH = H.degreeSeqVect(1);
	for (int i = 0; i < degH.size(); i++)
		cout << degH[i] << " ";
	cout << endl;
	cout << "Degree sequence comparisons" << endl;
	cout << "---------------------------" << endl;
	cout << endl;

	if (G.degreeSeqComp(degG, degK))
		cout << "The degree sequence of G is the same as K's." << endl;
	else
		cout << "The degree sequence of G is not the same as K's." << endl;
		
	if (G.degreeSeqComp(degG, degH))
		cout << "The degree sequence of G is the same as H's." << endl;
	else
		cout << "The degree sequence of G is not the same as K's." << endl;
	std::vector<int> udegG = G.degreeSeqVect(0);
	std::vector<int> udegH = H.degreeSeqVect(0);
	
	std::map<int,int> degMapG = G.degreeSeqMap();
	std::map<int,int> degMapH = H.degreeSeqMap();
	
	cout << endl;
	cout << "Isomorphism testing" << endl;
	cout << "-------------------" << endl;
	cout << endl;
	cout << "G isomorphic to K?" << endl;
	G.is_iso(K);
	cout << endl;
	cout << "G isomorphic to H?" << endl;
	G.is_iso(H);
	cout << endl;
	cout << "K isomorphic to H?" << endl;
	K.is_iso(H);
	cout << endl;
	
	cout << "Begin thorough testing and time analysis" << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;

	Timer timer;
	
	cout << "G isomorphic to K?" << endl;
	timer.start_timer();
	G.is_iso(K);
	timer.end_timer();
	timer.print_time();
	timer.reset_timer();
	cout << endl;
	cout << "G isomorphic to H?" << endl;
	timer.start_timer();
	G.is_iso(H);
	timer.end_timer();
	timer.print_time();
	timer.reset_timer();
	cout << endl;
	cout << "K isomorphic to H?" << endl;
	timer.start_timer();
	K.is_iso(H);
	timer.end_timer();
	timer.print_time();
	timer.reset_timer();
	cout << endl;

	Graph<int> x(UNDIRECTED);
	Graph<int> y(UNDIRECTED);

	
	for (int i = 1; i <= 8; i++)
	{
		x.addVertex(i);
		y.addVertex(9-i);
	}
	x.addEdge(1, 2);
	x.addEdge(1, 3);
	x.addEdge(2, 4);
	x.addEdge(4, 6);
	x.addEdge(4, 7);
	x.addEdge(6, 5);
	x.addEdge(5, 4);
	x.addEdge(8, 3);
	x.addEdge(8, 7);

	y.addEdge(8,7);
	y.addEdge(8,3);
	y.addEdge(5,4);
	y.addEdge(6,5);
	y.addEdge(4,7);
	y.addEdge(4,6);
	y.addEdge(2,4);
	y.addEdge(1,3);
	y.addEdge(1,2);

	cout << "Graph x: " << endl;
	x.print();
	cout << endl;
	cout << "Graph y: " << endl;
	y.print();
	cout << endl;
	cout << "x isomorphic to y?" << endl;
	timer.start_timer();
	x.is_iso(y);
	timer.end_timer();
	timer.print_time();
	timer.reset_timer();
	cout << endl;

	Graph<char> r(UNDIRECTED);
	Graph<char> s(UNDIRECTED);
	
	r.addVertex('a');
	r.addVertex('b');
	r.addVertex('c');
	r.addVertex('d');
	r.addVertex('g');
	r.addVertex('h');
	r.addVertex('i');
	r.addVertex('j');

	s.addVertex('1');
	s.addVertex('2');
	s.addVertex('3');
	s.addVertex('4');
	s.addVertex('5');
	s.addVertex('6');
	s.addVertex('7');
	s.addVertex('8');

	r.addEdge('a','g');
	r.addEdge('a','h');
	r.addEdge('a','i');
	r.addEdge('b','g');
	r.addEdge('b','h');
	r.addEdge('b','j');
	r.addEdge('c','g');
	r.addEdge('c','i');
	r.addEdge('c','j');
	r.addEdge('d','h');
	r.addEdge('d','i');
	r.addEdge('d','j');
	
	s.addEdge('1','2');
	s.addEdge('1','4');
	s.addEdge('1','5');
	s.addEdge('2','6');
	s.addEdge('2','3');
	s.addEdge('3','4');
	s.addEdge('3','7');
	s.addEdge('4','8');
	s.addEdge('5','6');
	s.addEdge('5','8');
	s.addEdge('6','7');
	s.addEdge('7','8');

	cout << "Graph r: " << endl;
	r.print();
	cout << endl;
	cout << "Graph s: " << endl;
	s.print();
	cout << endl;
	cout << "r isomorphic to s?" << endl;
	timer.start_timer();
	r.is_iso(s);
	timer.end_timer();
	timer.print_time();
	timer.reset_timer();
	cout << endl;
	
	return 0;
}
