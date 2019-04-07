#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>

struct Node{
    int in, out, num, deg = 0, deg_t = 0, prev_node = 0, curr_pos = 1;
    bool visited=0;
    int* adj;//starts with adj[0];
    int* adj_t;
};

struct Graph_{
    int V;
    Node* node;
    int* sorted_by_out;
};

struct Graph_* createGraph_(int V)

{
    struct Graph_* graph = new Graph_;
    graph->V = V;
    graph->node  = new Node[V+1];
    for (int i=1; i<=V; i++){
        graph->node[i].num = i;
        graph->node[i].adj = new int[1];
        graph->node[i].adj_t = new int[1];
    }
    graph->sorted_by_out = new int[V+1];
    return graph;
}

void add_edge(struct Graph_* graph, int src, int dest){
    graph->node[src].adj[graph->node[src].deg+1] = dest;
    graph->node[src].deg++;
    graph->node[dest].adj_t[graph->node[dest].deg_t+1] = src;
    graph->node[dest].deg_t++;
}


void DFS_regular_(struct Graph_* graph){
    int time = 1;
    Node* current; current = &graph->node[1]; // int curr_num = 1;
    Node* previous;
    while (time <= 2*(graph->V)) {
        std::cout<<current->num<<" ";
        if (current->visited == 0) { // current == node[curr_num] -- here we mark a node and set in time
            current->visited = 1;
            current->in = time;
            time++;
        }
        if (current->curr_pos <= current->deg)
        while (current->curr_pos <= current->deg){
            if (graph->node[current->adj[current->curr_pos]].visited == 0) {
                graph->node[current->adj[current->curr_pos]].prev_node = current->num;
                previous = current;
                current = &graph->node[current->adj[current->curr_pos]];
                break;
            } else {current->curr_pos++;}
        }
        if ((current->curr_pos > current->deg) && (current->num != 1)){ //step back, except for root
            current->out = time;
            current = previous;
            if (current->prev_node != 1) previous = &graph->node[current->prev_node];
            time++;
        } else
        if ((current->curr_pos > current->deg) && (current->num == 1)) {//step back for root - finish
            current->out = time;
        }
    }
}

#endif // GRAPH_H_INCLUDED



/*

// An Iterative C++ program to do DFS traversal from
// a given source vertex. DFS(int s) traverses vertices
// reachable from s.
#include<bits/stdc++.h>
using namespace std;

// This class represents a directed graph using adjacency
// list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // to add an edge to graph
    void DFS(int s);  // prints all vertices in DFS manner
    // from a given source.
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

// prints all not yet visited vertices reachable from s
void Graph::DFS(int s)
{
    // Initially mark all verices as not visited
    vector<bool> visited(V, false);

    // Create a stack for DFS
    stack<int> stack;

    // Push the current source node.
    stack.push(s);

    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        s = stack.top();
        stack.pop();

        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited[s])
        {
            cout << s << " ";
            visited[s] = true;
        }

        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then puah it
        // to the stack.
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i])
                stack.push(*i);
    }
}

// Driver program to test methods of graph class
int main()
{
    Graph g(5); // Total 5 vertices in graph
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);

    cout << "Following is Depth First Traversal\n";
    g.DFS(0);

    return 0;
}



// An Iterative C++ program to do DFS traversal from
// a given source vertex. DFS(int s) traverses vertices
// reachable from s.
#include<bits/stdc++.h>
using namespace std;

// This class represents a directed graph using adjacency
// list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // to add an edge to graph
    void DFS();  // prints all vertices in DFS manner

    // prints all not yet visited vertices reachable from s
    void DFSUtil(int s, vector<bool> &visited);
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

// prints all not yet visited vertices reachable from s
void Graph::DFSUtil(int s, vector<bool> &visited)
{
    // Create a stack for DFS
    stack<int> stack;

    // Puah the current source node.
    stack.push(s);

    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        s = stack.top();
        stack.pop();

        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited[s])
        {
            cout << s << " ";
            visited[s] = true;
        }

        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then puah it
        // to the stack.
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i])
                stack.push(*i);
    }
}

// prints all vertices in DFS manner
void Graph::DFS()
{
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i])
            DFSUtil(i, visited);
}

// Driver program to test methods of graph class
int main()
{
    Graph g(5);  // Total 5 vertices in graph
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    cout << "Following is Depth First Traversal\n";
    g.DFS();

    return 0;
}
*/
