#include <iostream>
#include <string>
#include <string>
#include <array>
#include <iterator>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <queue>
#include <cmath>

using namespace std;

// MINIMUM SPANNING TREE (KRUSKAL'S ALGO.)

struct node
{
	int u;
	int v;
	int wt;
	node(int first, int second, int weight)
	{
		u = first;
		v = second;
		wt = weight;
	}
};

bool comp(node a, node b)
{
	return a.wt < b.wt;
}

int findPar(int u, vector<int> &parent)
{
	if (u == parent[u])
		return u;
	return parent[u] = findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
	u = findPar(u, parent);
	v = findPar(v, parent);
	if (rank[u] < rank[v])
	{
		parent[u] = v;
	}
	else if (rank[v] < rank[u])
	{
		parent[v] = u;
	}
	else
	{
		parent[v] = u;
		rank[u]++;
	}
}
int main()
{
	int N = 5, m = 6;
	vector<node> edges;
	edges.push_back(node(0, 1, 2));
	edges.push_back(node(0, 3, 6));
	edges.push_back(node(1, 0, 2));
	edges.push_back(node(1, 2, 3));
	edges.push_back(node(1, 3, 8));
	edges.push_back(node(1, 4, 5));
	edges.push_back(node(2, 1, 3));
	edges.push_back(node(2, 4, 7));
	edges.push_back(node(3, 0, 6));
	edges.push_back(node(3, 1, 8));
	edges.push_back(node(4, 1, 5));
	edges.push_back(node(4, 2, 7));
	sort(edges.begin(), edges.end(), comp);

	vector<int> parent(N);
	for (int i = 0; i < N; i++)
		parent[i] = i;
	vector<int> rank(N, 0);

	int cost = 0;
	vector<pair<int, int>> mst;
	for (auto it : edges)
	{
		if (findPar(it.u, parent) != findPar(it.v, parent))
		{
			cost += it.wt;
			mst.push_back({it.u, it.v});
			unionn(it.u, it.v, parent, rank);
		}
	}
	cout << cost << endl;
	for (auto it : mst)
		cout << it.first << " - " << it.second << endl;
	return 0;
}

// PUTTING GRAPH INTO LINKED LIST MANNER EACH PARENTWISE

// A structure to represent an adjacency list node
struct AdjListNode
{
	int dest;
	struct AdjListNode *next;
};

// A structure to represent an adjacency list
struct AdjList
{
	struct AdjListNode *head;
};

// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices
// in graph)
struct Graph
{
	int V;
	struct AdjList *array;
};

// A utility function to create a new adjacency list node
struct AdjListNode *newAdjListNode(int dest)
{
	struct AdjListNode *newNode = (struct AdjListNode *)malloc(
		sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph *createGraph(int V)
{
	struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
	graph->V = V;

	// Create an array of adjacency lists. Size of
	// array will be V
	graph->array = (struct AdjList *)malloc(
		V * sizeof(struct AdjList));

	// Initialize each adjacency list as empty by
	// making head as NULL
	int i;
	for (i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph *graph, int src, int dest)
{
	// Add an edge from src to dest. A new node is
	// added to the adjacency list of src. The node
	// is added at the beginning
	struct AdjListNode *check = NULL;
	struct AdjListNode *newNode = newAdjListNode(dest);

	if (graph->array[src].head == NULL)
	{
		newNode->next = graph->array[src].head;
		graph->array[src].head = newNode;
	}
	else
	{

		check = graph->array[src].head;
		while (check->next != NULL)
		{
			check = check->next;
		}
		// graph->array[src].head = newNode;
		check->next = newNode;
	}

	// Since graph is undirected, add an edge from
	// dest to src also
	newNode = newAdjListNode(src);
	if (graph->array[dest].head == NULL)
	{
		newNode->next = graph->array[dest].head;
		graph->array[dest].head = newNode;
	}
	else
	{
		check = graph->array[dest].head;
		while (check->next != NULL)
		{
			check = check->next;
		}
		check->next = newNode;
	}

	// newNode = newAdjListNode(src);
	// newNode->next = graph->array[dest].head;
	// graph->array[dest].head = newNode;
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(struct Graph *graph)
{
	int v;
	for (v = 0; v < graph->V; ++v)
	{
		struct AdjListNode *pCrawl = graph->array[v].head;
		printf("\n Adjacency list of vertex %d\n head ", v);
		while (pCrawl)
		{
			printf("-> %d", pCrawl->dest);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}

// Driver program to test above functions
int main()
{
	// create the graph given in above fugure
	int V = 5;
	struct Graph *graph = createGraph(V);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	// print the adjacency list representation of the above
	// graph
	printGraph(graph);
	return 0;
}

// STRONGLT CONNECTRD COMPONENT (TAGEN ALGO.)

// A C++ program to find strongly connected components in a given
// directed graph using Tarjan's algorithm (single DFS)
#include <iostream>
#include <list>
#include <stack>
#define NIL -1
using namespace std;

// A class that represents an directed graph
class Graph
{
	int V;			// No. of vertices
	list<int> *adj; // A dynamic array of adjacency lists

	// A Recursive DFS based function used by SCC()
	void SCCUtil(int u, int disc[], int low[],
				 stack<int> *st, bool stackMember[]);

public:
	Graph(int V);				// Constructor
	void addEdge(int v, int w); // function to add an edge to graph
	void SCC();					// prints strongly connected components
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

// A recursive function that finds and prints strongly connected
// components using DFS traversal
// u --> The vertex to be visited next
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> earliest visited vertex (the vertex with minimum
//			 discovery time) that can be reached from subtree
//			 rooted with current vertex
// *st -- >> To store all the connected ancestors (could be part
//		 of SCC)
// stackMember[] --> bit/index array for faster check whether
//				 a node is in stack
void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st,
					bool stackMember[])
{
	// A static variable is used for simplicity, we can avoid use
	// of static variable by passing a pointer.
	static int time = 0;

	// Initialize discovery time and low value
	disc[u] = low[u] = ++time;
	st->push(u);
	stackMember[u] = true;

	// Go through all vertices adjacent to this
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i; // v is current adjacent of 'u'

		// If v is not visited yet, then recur for it
		if (disc[v] == -1)
		{
			SCCUtil(v, disc, low, st, stackMember);

			// Check if the subtree rooted with 'v' has a
			// connection to one of the ancestors of 'u'
			// Case 1 (per above discussion on Disc and Low value)
			low[u] = min(low[u], low[v]);
		}

		// Update low value of 'u' only of 'v' is still in stack
		// (i.e. it's a back edge, not cross edge).
		// Case 2 (per above discussion on Disc and Low value)
		else if (stackMember[v] == true)
			low[u] = min(low[u], disc[v]);
	}

	// head node found, pop the stack and print an SCC
	int w = 0; // To store stack extracted vertices
	if (low[u] == disc[u])
	{
		while (st->top() != u)
		{
			w = (int)st->top();
			cout << w << " ";
			stackMember[w] = false;
			st->pop();
		}
		w = (int)st->top();
		cout << w << "\n";
		stackMember[w] = false;
		st->pop();
	}
}

// The function to do DFS traversal. It uses SCCUtil()
void Graph::SCC()
{
	int *disc = new int[V];
	int *low = new int[V];
	bool *stackMember = new bool[V];
	stack<int> *st = new stack<int>();

	// Initialize disc and low, and stackMember arrays
	for (int i = 0; i < V; i++)
	{
		disc[i] = NIL;
		low[i] = NIL;
		stackMember[i] = false;
	}

	// Call the recursive helper function to find strongly
	// connected components in DFS tree with vertex 'i'
	for (int i = 0; i < V; i++)
		if (disc[i] == NIL)
			SCCUtil(i, disc, low, st, stackMember);
}

// Driver program to test above function
int main()
{
	cout << "\nSCCs in first graph \n";
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.SCC();

	cout << "\nSCCs in second graph \n";
	Graph g2(4);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.addEdge(2, 3);
	g2.SCC();

	cout << "\nSCCs in third graph \n";
	Graph g3(7);
	g3.addEdge(0, 1);
	g3.addEdge(1, 2);
	g3.addEdge(2, 0);
	g3.addEdge(1, 3);
	g3.addEdge(1, 4);
	g3.addEdge(1, 6);
	g3.addEdge(3, 5);
	g3.addEdge(4, 5);
	g3.SCC();

	cout << "\nSCCs in fourth graph \n";
	Graph g4(11);
	g4.addEdge(0, 1);
	g4.addEdge(0, 3);
	g4.addEdge(1, 2);
	g4.addEdge(1, 4);
	g4.addEdge(2, 0);
	g4.addEdge(2, 6);
	g4.addEdge(3, 2);
	g4.addEdge(4, 5);
	g4.addEdge(4, 6);
	g4.addEdge(5, 6);
	g4.addEdge(5, 7);
	g4.addEdge(5, 8);
	g4.addEdge(5, 9);
	g4.addEdge(6, 4);
	g4.addEdge(7, 9);
	g4.addEdge(8, 9);
	g4.addEdge(9, 8);
	g4.SCC();

	cout << "\nSCCs in fifth graph \n";
	Graph g5(5);
	g5.addEdge(0, 1);
	g5.addEdge(1, 2);
	g5.addEdge(2, 3);
	g5.addEdge(2, 4);
	g5.addEdge(3, 0);
	g5.addEdge(4, 2);
	g5.SCC();

	return 0;
}

// ALIEN DICTIONARY  (TOPOLOGICAL SORTING)

// METHOD-1
//  A C++ program to order of characters in an alien language
#include <bits/stdc++.h>
using namespace std;

// Class to represent a graph
class Graph
{
	int V; // No. of vertices'

	// Pointer to an array containing adjacency listsList
	list<int> *adj;

	// A function used by topologicalSort
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints a Topological Sort of the complete graph
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
	// Mark the current node as visited.
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack);

	// Push current vertex to stack which stores result
	Stack.push(v);
}

// The function to do Topological Sort. It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{
	stack<int> Stack;

	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to store Topological Sort
	// starting from all vertices one by one
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack);

	// Print contents of stack
	while (Stack.empty() == false)
	{
		cout << (char)('a' + Stack.top()) << " ";
		Stack.pop();
	}
}

int min(int x, int y)
{
	return (x < y) ? x : y;
}

// This function finds and prints order of character from a sorted
// array of words. n is size of words[]. alpha is set of possible
// alphabets.
// For simplicity, this function is written in a way that only
// first 'alpha' characters can be there in words array. For
// example if alpha is 7, then words[] should have only 'a', 'b',
// 'c' 'd', 'e', 'f', 'g'
void printOrder(string words[], int n, int alpha)
{
	// Create a graph with 'alpha' edges
	Graph g(alpha);

	// Process all adjacent pairs of words and create a graph
	for (int i = 0; i < n - 1; i++)
	{
		// Take the current two words and find the first mismatching
		// character
		string word1 = words[i], word2 = words[i + 1];
		for (int j = 0; j < min(word1.length(), word2.length()); j++)
		{
			// If we find a mismatching character, then add an edge
			// from character of word1 to that of word2
			if (word1[j] != word2[j])
			{
				g.addEdge(word1[j] - 'a', word2[j] - 'a');
				break;
			}
		}
	}

	// Print topological sort of the above created graph
	g.topologicalSort();
}

// Driver program to test above functions
int main()
{
	string words[] = {"caa", "aaa", "aab"};
	printOrder(words, 3, 3);
	return 0;
}

// SAME SBOVE PROBLEM (METHOD-2)

void dfs(char from, unordered_map > &adj_list,
		 string &topological_order, unordered_set &visited)
{
	visited.insert(from);
	for (auto it = adj_list[from].begin(); it != adj_list[from].end(); it++)
	{
		if (visited.find(*it) == visited.end())
		{
			dfs(*it, adj_list, topological_order, visited);
		}
	}
	topological_order = from + topological_order;
}

// Topological sort.
string topological_sort(unordered_map > &adj_list)
{
	string topological_order = "";
	unordered_set visited;
	for (auto it = adj_list.begin(); it != adj_list.end(); it++)
	{
		// If current node is not visited then visit it and visit nodes reachable from that node.
		if (visited.find(it->first) == visited.end())
		{
			dfs(it->first, adj_list, topological_order, visited);
		}
	}
	return topological_order;
}

string find_order(vector words)
{
	int n = words.size();
	// Contains adjacent nodes.
	unordered_map > adj_list;

	/*
	Initialize nodes with no edges. This is imp. Otherwise testcases having only one type of
	character will fail.
	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < words[i].length(); j++)
		{
			adj_list[words[i][j]] = vector(0);
		}
	}

	// Find mismatch and add edges.
	for (int i = 0; i < n - 1; i++)
	{
		int min_len = min(words[i].length(), words[i + 1].length());
		for (int j = 0; j < min_len; j++)
		{
			if (words[i][j] != words[i + 1][j])
			{
				adj_list[words[i][j]].push_back(words[i + 1][j]);
				break;
			}
		}
	}

	return topological_sort(adj_list);
}
