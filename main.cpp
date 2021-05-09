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

using namespace std;

int main()
{
	Graph<int> G(UNDIRECTED);
	Graph<char> K(UNDIRECTED);

	//Graph H for testing permutations	
	Graph<int> H(UNDIRECTED);
	
	for (int i = 1; i <= 8; i++)
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

	cout << "Graph G: " << endl;
	G.print();
	cout << "Vertex count: " << G.getVertexCount() << endl;
	cout << endl;
	cout << "Graph K: " << endl;
	K.print();
	cout << "Vertex count: " << K.getVertexCount() << endl;
	cout << endl;
	cout << "Graph H: " << endl;
	H.print();
	cout << "Vertex count: " << H.getVertexCount() << endl;
	cout << endl;

	G.addEdge(1,2);
	G.addEdge(1,1);
	G.addEdge(1,5);
	G.addEdge(1,6);
	G.addEdge(6,3);
	G.addEdge(3,4);
	G.addEdge(4,8);
	G.addEdge(3,7);
	G.addEdge(7,4);

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
	cout << endl;

	cout << "Graph K: " << endl;
	K.print();
	cout << "Edge count: " << K.getEdgeCount() << endl;
	cout << endl;
	
	cout << "Graph H: " << endl;
	H.print();
	cout << "Edge count: " << H.getEdgeCount() << endl;
	cout << endl;

	cout << "Degree Seqeuncing: " << endl;
	cout << "Graph G: " << endl;
	std::vector<int> degG = G.degreeSeq(1);
	for (int i = 0; i < degG.size(); i++)
		cout << degG[i] << " ";
	cout << endl;
	cout << "Graph K: " << endl;
	std::vector<int> degK = K.degreeSeq(1);
	for (int i =0; i < degK.size(); i++)
		cout << degK[i] << " ";
	cout << endl;

	cout << "Graph H: " << endl;
	std::vector<int> degH = H.degreeSeq(1);
	for (int i = 0; i < degH.size(); i++)
		cout << degH[i] << " ";
	cout << endl;

	if (G.degreeSeq(degG, degK))
		cout << "They are the same." << endl;
	else
		cout << "They are not the same." << endl;
		
	if (G.degreeSeq(degG, degH))
		cout << "They are the same." << endl;
	else
		cout << "They are not the same." << endl;
	std::vector<int> udegG = G.degreeSeq(0);
	std::vector<int> udegH = H.degreeSeq(0);
	cout << "Unsorted G: ";
	for (int i = 0; i < udegG.size(); i++)
		cout << udegG[i] << " ";
	cout << endl;
	cout << "Unsorted H: ";
	for (int i = 0; i < udegH.size(); i++)
		cout << udegH[i] << " ";
	cout << endl;
	G.permutation(udegG, udegH, H);

	
	return 0;
}
