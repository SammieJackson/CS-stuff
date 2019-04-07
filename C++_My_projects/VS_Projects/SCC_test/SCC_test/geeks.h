#ifndef GEEKS_H_INCLUDED
#define GEEKS_H_INCLUDED

/// C++ Implementation of Kosaraju's algorithm to print all SCCs
#include <iostream>
#include <list>
#include <stack>
using namespace std;

/// 01.11.17 -  try to change list<int> to list<long> - tried - not helping

class Graph
{

	list<int> *adj;    /// An array of adjacency lists
	int* degs;    /// degrees of all vertices

				  /// Fills Stack with vertices (in increasing order of finishing
				  /// times). The top element of stack has the maximum finishing
				  /// time
	void fillOrder(int v, bool visited[], stack<int> &Stack);

	/// A recursive function to print DFS starting from v
	void DFSUtil(int v, bool visited[]);
	void DFSUtil_mod(int v, bool visited[], long& counter);
public:
	int V;    /// No. of vertices
	Graph(int V);
	void addEdge(int v, int w);

	/// The main function that finds and prints strongly connected
	/// components
	void printSCCs();
	///void printSCCs_mod();
	void findSCCs();

	/// Function that returns reverse (or transpose) of this graph
	Graph getTranspose();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V + 1];
	degs = new int[V + 1];
	for (int i = 1; i <= V; ++i) { degs[i] = 0; }
}

/// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[])
{
	/// Mark the current node as visited and print it
	visited[v] = true;
	cout << v << " ";

	/// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 1; v <= V; v++) /// was - v = 0; v < V; ...
	{
		/// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); /// Add w to v’s list.
	degs[v] += 1;
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)/// <<--- ERROR!!!
{
	/// Mark the current node as visited and print it
	visited[v] = true;

	/// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	if (degs[v] > 0)
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
			if (!visited[*i])
				fillOrder(*i, visited, Stack);

	/// All vertices reachable from v are processed by now, push v
	Stack.push(v);
}

/// The main function that finds and prints all strongly connected
/// components
void Graph::printSCCs()
{
	stack<int> Stack;

	/// Mark all the vertices as not visited (For first DFS)
	bool *visited = new bool[V + 1];
	for (int i = 1; i <= V; i++) /// was i =0; i < V; ...
		visited[i] = false;

	/// Fill vertices in stack according to their finishing times
	for (int i = 1; i <= V; i++) /// was i = 0; i < V; ...
		if (visited[i] == false)
			fillOrder(i, visited, Stack);

	/// Create a reversed graph
	Graph gr = getTranspose();

	/// Mark all the vertices as not visited (For second DFS)
	for (int i = 1; i <= V; i++) /// was - look up
		visited[i] = false;

	/// Now process all vertices in order defined by Stack
	while (Stack.empty() == false)
	{
		/// Pop a vertex from stack
		int v = Stack.top();
		Stack.pop();

		/// Print Strongly connected component of the popped vertex
		if (visited[v] == false)
		{
			gr.DFSUtil(v, visited);
			cout << endl;
		}
	}
}

/// Driver program to test above functions
int main0()
{
	// Create a graph given in the above diagram
	Graph g(5);
	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(3, 4);

	cout << "Following are strongly connected components in "
		"given graph \n";
	g.printSCCs();

	return 0;
}

void built_Gr_cin(Graph* graph) {
	int src, dest;
	cin >> src;
	cin >> dest;
	while (!cin.fail()) {
		if (src > graph->V) { cout << "\n Input ERROR!\n"; return; }
		if (dest > graph->V) { cout << "\n Input ERROR!\n"; return; }
		graph->addEdge(src, dest);
		cin >> src;
		cin >> dest;
	}
}



void Graph::findSCCs()
{
	stack<int> Stack;

	/// Mark all the vertices as not visited (For first DFS)
	bool *visited = new bool[V];
	for (int i = 1; i <= V; i++) /// was i = 0; i < V; ...
		visited[i] = false;

	/// Fill vertices in stack according to their finishing times
	for (int i = 1; i <= V; i++) /// was i = 0; i < V; ...
		if (visited[i] == false)
			fillOrder(i, visited, Stack);

	/// Create a reversed graph
	Graph gr = getTranspose();

	/// Mark all the vertices as not visited (For second DFS)
	for (int i = 1; i <= V; i++) /// was - look up
		visited[i] = false;

	/// Now process all vertices in order defined by Stack
	int max_scc[6]{ 0,0,0,0,0,0 };
	while (Stack.empty() == false)
	{
		/// Pop a vertex from stack
		int v = Stack.top();
		Stack.pop();

		/// Print Strongly connected component of the popped vertex
		if (visited[v] == false)
		{
			long counter = 0;
			gr.DFSUtil_mod(v, visited, counter);
			if (counter > 1) cout << "\n " << counter << endl;
			///cout << endl << counter;
			if (counter > max_scc[5]) { for (int i = 1; i <= 4; ++i) { max_scc[i] = max_scc[i + 1]; } max_scc[5] = counter; }
			else
				if (counter > max_scc[4]) { for (int i = 1; i <= 3; ++i) { max_scc[i] = max_scc[i + 1]; } max_scc[4] = counter; }
				else
					if (counter > max_scc[3]) { for (int i = 1; i <= 2; ++i) { max_scc[i] = max_scc[i + 1]; } max_scc[3] = counter; }
					else
						if (counter > max_scc[2]) { for (int i = 1; i <= 1; ++i) { max_scc[i] = max_scc[i + 1]; } max_scc[2] = counter; }
						else
							if (counter > max_scc[1]) { max_scc[1] = counter; }
		}
	}
	cout << "\n\n ";
	for (int i = 1; i <= 5; ++i) { cout << max_scc[i] << " "; }
	cout << endl;
}

void Graph::DFSUtil_mod(int v, bool visited[], long& counter)
{
	/// Mark the current node as visited and print it
	visited[v] = true;
	///cout << v << " ";
	++counter;

	/// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil_mod(*i, visited, counter);
}


#endif // GEEKS_H_INCLUDED
