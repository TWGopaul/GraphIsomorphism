//Program: graph.cpp
//Author: Mitchell Krystofiak
//Description: Implementation of the graph class.
//Date: April 22, 2021

#include "graph.h"
#include <algorithm>

//Useful vertex functions: begin, end, size, empty, push_back, pop_back, insert
//			   erase, swap
//
//Useful map functions: begin, end, empty, size, insert, erase, swap, find, lower_bound
//			higher_bound
//
//Useful queue functions: empty, size, front, back, push, emplace, pop, swap

/*enum letter_t 
{
	A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
};*/

template<class T>
Graph<T>::Graph() 
{
	this->graph_t = UNDIRECTED;
	this->time = 0;
	this->isDAG = false;
	this->count_v = 0;
	this->count_e = 0;
}

template<class T>
Graph<T>::Graph(const graph_type & t)
{
	this->graph_t = t;
	this->time = 0;
	if (this->graph_t == DIRECTED)
		this->isDAG = true;
	else
		this->isDAG = false;
	this->count_v = 0;
        this->count_e = 0;
}

template<class T>
Graph<T>::Graph(const Graph & old)
{
	this->graph_t = old.graph_t;
	this->vertices = old.vertices;
	this->time = old.time;
	this->isDAG = old.isDAG;
	this->count_v = old.count_v;
	this->count_e = old.count_e;
}
template<class T>
Graph<T>::~Graph() {}

template<class T>
void Graph<T>::operator=(const Graph & old)
{
	this->graph_t = old.graph_t;
	this->vertices = old.vertices;
	this->time = old.time;
	this->isDAG = old.isDAG;
	this->count_v = old.count_v;
        this->count_e = old.count_e;
}

template<class T>
void Graph<T>::addVertex(T x)
{
	auto search = this->vertices.find(x);
	
	if (search == this->vertices.end())
	{
		std::vector<T> list;
		this->vertices.insert({x, list});
		this->count_v++;
	}

	else
		 std::cout << "Vertex " << x << " is already in the graph!" << std::endl;
}

template<class T>
void Graph<T>::addEdge(T x, T y)
{

	if (vertices.find(x) != vertices.end()) 
	{
		if (vertices.find(y) != vertices.end()) 
		{
			bool exists = false;

			for (auto j = vertices[x].begin(); j != vertices[x].end(); j++)
			{
				if (*j == y)
				{
					exists = true;
					break;
				}
			}
			if (!exists)
			{
				//happens regardless of directed/undirected
				vertices[x].push_back(y);
				//if the graph is undirected, we will reverse the relationship
				if (graph_t == UNDIRECTED && vertices[x] != vertices[y])
					vertices[y].push_back(x);
				this->count_e++;
			}
			else
				std::cout << "The edge pointing from " << x << " to " << y << " already exists!" << std::endl;
		}
		else
			std::cout << "Vertex " << y << " does not exist! Cannot create edge!" << std::endl;
		}
	else
		std::cout << "Vertex " << x << " does not exist! Cannot create edge!" << std::endl;
}

template<class T>
void Graph<T>::print()
{
	int size = vertices.size();

	for (auto i = vertices.begin(); i != vertices.end(); i++)
	{
		std::cout << "Vertex: " << i->first << " Points to: ";
		for (auto j = i->second.begin(); j != i->second.end(); j++)
			std::cout << *j << " ";
		std::cout << std::endl;
	}
}

template<class T>
void Graph<T>::printBFS(T x)
{
	//Tracking the colors, distances and parents.
	std::map<T, color_t> color;
	std::map<T, int> distance;
	std::map<T, T> parent;

	//1. Set each vertex color to white,
	//   set u.distance = inf, and set u.p
	//   = null.
	for (auto i = this->vertices.begin(); i != this->vertices.end(); i++)
	{
		color.insert({i->first, WHITE});
		parent.insert({i->first, -999});
		distance.insert({i->first, 999999999999});
	}
	
	//2. Set x.color = gray, s.d = 0, s.p = nil.
	color[x] = GRAY;
	distance[x] = 0;
	
        //3. Let Q be an empty queue.
        std::queue<T> Q;

	//4. Enqueue x.
	Q.push(x);

	//5. While Q not empty, run algorithm
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();

		for (auto v = this->vertices[u].begin(); v != this->vertices[u].end(); v++)
		{
			if (color[*v] == WHITE)
			{
				color[*v] = GRAY;
				distance[*v] = distance[u] + 1;
				parent[*v] = u;
				Q.push(*v);
			}
			color[u] = BLACK;
		}
	}

	auto c = color.begin();
	auto p = parent.begin();
	auto d = distance.begin();
	
	std::cout << "Breadth First Search Print" << std::endl;
	std::cout << std::endl;
	std::cout << "Root: " << x << std::endl;
	std::cout << "Note: 0 = White, 1 = Gray, 2 = Black" << std::endl;
	std::cout << "--------------------------" << std::endl;

	while (c != color.end())
	{
		std::cout << "Vertex discovered: " << c->first << std::endl;
		std::cout << "Parent: " << p->second << std::endl;
		std::cout << "Color: " << c->second << std::endl;
		std::cout << "Distance from root: " << d->second << std::endl;
		std::cout << std::endl;
		c++;
		p++;
		d++;
	}
}

template<class T>
void Graph<T>::DFSvisit(int u, int print, std::map<int, color_t> & color, std::map<int, int> & parent)
{
	this->time++;
	this->discovery[u] = this->time;
	color[u] = GRAY;
	for (auto i = this->vertices[u].begin(); i != this->vertices[u].end(); i++)
	{
		if (color[*i] == WHITE)
		{
			parent[*i] == WHITE;
			this->DFSvisit(*i, color, parent);
		}
		if (color[*i] == GRAY)
			this->isDAG = false;
	}
	if (print == 1)
	{
		for (int i : vertices[u])
			std::cout << i << " ";
	}
	color[u] = BLACK;
	this->time++;
	this->finish[u] = this->time;
}

template<class T>
void Graph<T>::printDFS(int print)
{
	if (this->is_empty())
		return;
	
	std::map<int, color_t> color;
	std::map<int, int> parent;

	if (print == 1)
	{
		std::cout << "Depth First Search Print" << std::endl;
		std::cout << std::endl;
	}

	for (auto i = this->vertices.begin(); i != this->vertices.end(); i++)
	{
		color.insert({i->first, WHITE});
		parent.insert({i->first, -9999999999});
	}
	this->time = 0;

	for (auto i = this->vertices.begin(); i != this->vertices.end(); i++)
	{
		if (color[i->first] == WHITE)
			this->DFSvisit(i->first, color, parent);
	}
	std::cout << std::endl;
}

template<class T>
void Graph<T>::topSortPrint()
{
	this->printDFS(0);

	if (!this->isDAG)
	{
		std::cout << "Graph must be a DAG!" << std::endl;
		return;
	}

	std::vector<std::pair<int, int>> list;
	
	for (auto i = this->finish.begin(); i != this->finish.end(); i++)
		list.push_back({i->second, i->first});

	std::sort(list.begin(), list.end());
	std::reverse(list.begin(), list.end());

	std::cout << "Topological Sort Print" << std::endl;
	std::cout << std::endl;

	for (std::vector<std::pair<int,int>>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << it->second << "'s tiem: " << it->first << ", ";
	std::cout << std::endl;
}

template<class T>
bool Graph<T>::is_empty()
{
	return this->vertices.empty();
}

template<class T>
graph_type Graph<T>::getGraphType()
{
	return this->graph_t;
}

template<class T>
void Graph<T>::SCCprint()
{
        //Given G = (V,E)
        //Run DFS(G)
        //Compute G_T
        //DFS(G_T)

        if (this->graph_t != DIRECTED)
        {
                std::cout << "Graph must be directed to find SCC's." << std::endl;
                return;
        }

        this->printDFS(0);
        Graph<T> old = *this;

        std::vector<std::pair<int,int>> list;

        for (auto i = this->finish.begin(); i != this->finish.end(); i++)
                list.push_back({i->second, i->first});

        std::sort(list.begin(), list.end());
        std::reverse(list.begin(), list.end());

        std::map<int, color_t> color;

        for (auto i = this->vertices.begin(); i != this->vertices.end(); i++)
                color.insert({i->first,WHITE});

        std::cout << "Strongly Connected Componenets" << std::endl;
        std::cout << std::endl;

        for (auto i = list.begin(); i != list.end(); i++)
        {
                if (color[i->second] == WHITE)
                {
                        this->SCCvisit(i->second, color);
                        std::cout << std::endl;
                }
        }
}

template<class T>
void Graph<T>::SCCvisit(int u, std::map<int, color_t> & color)
{
        color[u] = GRAY;
        for (auto v = this->vertices[u].begin(); v != this->vertices[u].end(); v++)
        {
                if (color[*v] == WHITE)
                        this->SCCvisit(*v, color);
        }
        color[u] = BLACK;
        for (int i: vertices[u])
                std::cout << i << " -> ";
}

template<class T>
bool Graph<T>::is_iso(Graph<T> & H)
{
	bool iso = false;
	std::vector<int> degG = this->degreeSeqVect(1);
	std::vector<int> degH = H.degreeSeqVect(1);
	if (this->count_v != H.count_v)//vertices must match
	{
		std::cout << "Vertex counts different! They are not isomorphic!" << std::endl;
		iso = false;
	}
	else if (this->count_e != H.count_e)//edges must match
	{
		std::cout << "Edge counts are different! They are not isomorphic!" << std::endl;
		iso = false;
	}
	else if (this->graph_t != H.graph_t)//graph types must match
	{
		std::cout << "Graph types are different! They are not isomorphic!" << std::endl;
		iso = false;
	}
	else if (!degreeSeqComp(degG, degH))//degree sequences must match
	{
		std::cout << "Degree sequences are different! they are not isomorphic!" << std::endl;
		iso = false;
	}
	else
	{
		if (iso = permutation(this->degreeSeqMap(), H.degreeSeqMap(), H))
			std::cout << "The graphs are isomorphic!" << std::endl;
		else
			std::cout << "The graphs are not isomorphic!" << std::endl;
	}
	return iso;
}

template<class T>
bool Graph<T>::is_aut(const Graph<T> & G, const Graph<T> & H)
{
	return false;
}

template<class T>
int Graph<T>::getVertexCount()
{
	return this->count_v;
}

template<class T>
int Graph<T>::getEdgeCount()
{
	return this->count_e;
}

template<class T>
std::vector<int> Graph<T>::degreeSeqVect(int sort)
{
	std::vector<int> degree;
	int count = 0;

	for (auto i = this->vertices.begin(); i != this->vertices.end(); i++)
	{
		count = 0;
		for (auto j = i->second.begin(); j != i->second.end(); j++)
			count++;
		degree.push_back(count);
	}
	if (sort == 1)
		std::sort(degree.begin(), degree.end());
		
	return degree;
}

template<class T>
std::map<T,int> Graph<T>::degreeSeqMap()
{
	std::map<T,int> degree;
	int count = 0;
	int j = 0;
	for (auto i = this->vertices.begin(); i != this->vertices.end(); i++)
	{
		count = 0;
		for (auto j = i->second.begin(); j != i->second.end(); j++)
			count++;
		degree.insert({i->first,count});//degree.insert({i->first,count});
		j++;
	}
	return degree;
}

template<class T>
std::map<T,int> Graph<T>::degreeSeqMapZero()
{
        std::map<T,int> degree;
        int count = 0;
        int j = 0;
        for (auto i = this->vertices.begin(); i != this->vertices.end(); i++)
        {
                count = 0;
                for (auto j = i->second.begin(); j != i->second.end(); j++)
                        count++;
                degree.insert({j,count});//degree.insert({i->first,count});
                j++;
        }
        return degree;
}

template<class T>
bool Graph<T>::degreeSeqComp(std::vector<int> a, std::vector<int> b)
{
	//should already be true if calling, but just in case
	if (a.size() != b.size())
		return false;
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i])
			return false;
	return true;
}

template<class T>
int Graph<T>::factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n * factorial(n-1);
}

template<class T>
bool Graph<T>::permutation(std::map<T,int>a, std::map<T,int>b, Graph<T> &H)
{

	//TODO:
	//	Problem: Vertex labels must be equal to compare properly == bad 
	//	We want the graphs to be not necessarily equal in vertex labels
	bool perm = false;
	int count = 0;	//count how many times a permutation is found
	std::vector<int>found;	//vector to store found permutations in H, so they are not searched again

	for(auto i = a.begin(); i != a.end(); i++) //iterate through a's pairs
	{
		bool perm = false;
		while(!perm)
		{
			for(auto j = b.begin(); j != b.end(); j++)	//iterate through b's pairs
			{
				std::vector<int>::iterator it;
				it = find(found.begin(), found.end(), (j->first)); //search found for the key, j
				//compares if the vertex l deg seq's are the same  and a permutation of j is not already used
				if((i->first == j->first) && (i->second == j->second) && (it == found.end())) 
				{
					std::vector<int> tempG = this->vertices[i->first]; 
					std::vector<int> tempH = H.vertices[j->first];
					
					///////////
					perm = is_permutation(tempG.begin(), tempG.end(), tempH.begin());
					if(perm)
					{
						count++;
						found.push_back(j->first);	
					}
				} //end if
			} // end for
			perm = true;	
		}//end while
	}//end for	
	
	return ((count == a.size())&&(count  == found.size())) ?  true: false;
}

