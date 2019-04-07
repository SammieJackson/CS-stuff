#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <list>
#include <stack>
#include <vector>

using namespace std;

void test_SCC();
void test_adj();
void test_DFS();
void test_transpose();

class Graph
{
public:
    vector< vector<int> > adj;    /// An array of adjacency lists
    vector<int> degs, prevs, checks;    /// degrees of all vertices

    /// Fills Stack with vertices (in increasing order of finishing
    /// times). The top element of stack has the maximum finishing
    /// time
    void fillOrder(int v, bool* visited, vector<int> &vec);
    void fillOrd_rec(bool* visited, vector<int> &vec);

    /// A recursive function to print DFS starting from v
    void DFSUtil_mod(int v, bool* visited, int& counter);
    void DFSUtil_rec(int v, bool* visited, int& counter);
//public:
    int V;    /// Number of vertices
    Graph(int V);
    void addEdge(int v, int w);

    /// The main function that finds and prints strongly connected
    /// components
    void findSCCs();

    /// Function that returns reverse (or transpose) of this graph
    Graph getTranspose();
};


#endif // ALGO_H_INCLUDED
