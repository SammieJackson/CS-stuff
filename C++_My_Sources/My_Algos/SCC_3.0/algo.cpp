#include <vector>
#include <list>
#include <iostream>
#include <ctime>
#include <algorithm>
#include "algo.h"

using namespace std;

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V+1);
    degs.resize(V+1);
    prevs.resize(V+1);
    checks.resize(V+1);
    for (int i = 0; i <= V; ++i) checks[i] = 0;
    for (int i = 0; i <= V; ++i) prevs[i] = 0;
    for (int i = 1; i <= V; ++i) degs[i] = 0;
}

void Graph::addEdge(int v, int w)
{
    if (v > V || w > V || v == w) return;
    adj[v].push_back(w); /// Add w to v’s list.
    degs[v] += 1;
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 1; v <= V; v++)
    {
        /// Recur for all the vertices adjacent to this vertex
        for(vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.addEdge((*i),v);
        }
    }
    return g;
}

void Graph::fillOrder(int v, bool* visited, vector<int>& vec)
{
    /// Mark the current node as visited and print it
    visited[v] = true;

    /// Recur for all the vertices adjacent to this vertex
    if (degs[v] > 0)
    for(vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            fillOrder(*i, visited, vec);

    /// All vertices reachable from v are processed by now, push v
    vec.push_back(v);
}

void Graph::DFSUtil_mod(int v, bool* visited, int& counter)
{
    /// Mark the current node as visited and print it
    visited[v] = true;
    ++counter;

    /// Recur for all the vertices adjacent to this vertex
    for (vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil_mod(*i, visited, counter);
}

///___________________________________________________________________

void Graph::DFSUtil_rec(int v, bool* visited, int& counter)
{
    if (degs[v] == 0) {visited[v] = true; counter = 1; return;}
    if (degs[v] == 1) {visited[v] = true; int next = adj[v][0]; if (visited[next]) {counter = 1; return;}}

    int current = v;
    while (checks[v] < degs[v]) {
        if (!visited[current]) visited[current] = true;
        if (checks[current] == degs[current] && prevs[current] != 0)
        {
            counter++;
            current = prevs[current];
            checks[current]++;
        } else {
            int next = checks[current];
            while( next < degs[current] && visited[adj[current][next]] ) {next++; checks[current]++;}
            if (next < degs[current]) {
                int prev = current;
                current = adj[current][next];
                prevs[current] = prev;
            } else {
                if (prevs[current] != 0) {
                    counter++;
                    current = prevs[current];
                    checks[current]++;
                }
            }
        }
    }
    counter++;
}

void Graph::fillOrd_rec(bool* visited, vector<int>& vec)
{
    for (int i = 0; i <= V; ++i) checks[i] = 0;
    for (int i = 0; i <= V; ++i) prevs[i] = 0;
    int curr = 1, current;
    while (curr <= V) {
      if (!visited[curr]) {
        current = curr;
        while (checks[curr] < degs[curr]) {
            if (!visited[current]) visited[current] = true;
            if (checks[current] == degs[current] && prevs[current] != 0)
            {
                vec.push_back(current);
                current = prevs[current];
                checks[current]++;
            } else {
                int next = checks[current];
                while( next < degs[current] && visited[adj[current][next]] ) {next++; checks[current]++;}
                if (next < degs[current]) {
                    int prev = current;
                    current = adj[current][next];
                    prevs[current] = prev;
                } else {
                    vec.push_back(current);
                    current = prevs[current];
                    checks[current]++;
                }
            }
        }
        vec.push_back(curr);
      }
      curr++;
    }
}

///______________________________________________________

void Graph::findSCCs()
{
    clock_t t;

    vector<int> stak;
    /// Mark all the vertices as not visited (For first DFS)
    bool *visited = new bool[V+1];
    for(int i = 1; i <= V; i++)
        visited[i] = false;

    t = clock();

    /// Fill vertices in stack according to their finishing times
    fillOrd_rec(visited, stak);
    t = clock() - t;
    cout << "\n Direct graph order filled! It took " << ( ((float)t)/CLOCKS_PER_SEC ) << " seconds. \n";

    t = clock();
    /// Create a reversed graph
    Graph gr = this->getTranspose();
    t = clock() - t;
    cout << "\n Transpose formed! It took " << ( ((float)t)/CLOCKS_PER_SEC ) << " seconds. \n";

    /// Mark all the vertices as not visited (For second DFS)
    for(int i = 1; i <= V; i++)
        visited[i] = false;

    /// Now process all vertices in order defined by Stack
    //int max_scc[6]{0,0,0,0,0,0};
    vector<int> sccs;
    int c = 0;
    while (!stak.empty())
    {
        /// Pop a vertex from stack
        int v = stak.back();
        stak.pop_back();

        /// Print Strongly connected component of the popped vertex
        if (!visited[v])
        {
            int counter = 0;
            //t = clock();
            gr.DFSUtil_rec(v, visited, counter);
            //t = clock() - t;
            //cout << endl << v << ": It took " << ( ((float)t)/CLOCKS_PER_SEC ) << " seconds. \n";
            if (counter > 1) sccs.push_back(counter);
            //if (counter > 1) cout<<"\n "<<counter<<endl;

            ++c; if (c == 100) {c = 0; cout << "\n " << v;}
        }
    }
    cout<<"\n\n ";
    if (sccs.size() <= 6) for (int i = 0; i < sccs.size(); ++i) cout << sccs[i] << " ";
    else {
        sort(sccs.rbegin(),sccs.rend());
        for (int i = 0; i < 6; ++i) cout << sccs[i] << " ";
    }
    //for (int i = 1; i <= 5; ++i) {cout<<max_scc[i]<<" ";}
    cout<<endl;
}


///<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void test_SCC()
{
    Graph g(5);
    for (int i = 1; i < 5; ++i){
        for (int j = 1; j < 5; ++j) {g.addEdge(i,j);}
    }
    g.findSCCs();
}

void test_DFS()
{
    Graph g(5);
    for (int i = 1; i < 5; ++i){
        for (int j = 1; j < 5; ++j) {g.addEdge(i,j);}
    }
    int c = 0;
    bool* visited = new bool[6]; for (int i = 1; i < 6; ++i) {visited[i] = false;}
    g.DFSUtil_rec(1,visited, c);
    cout << endl << c;
}

void test_adj()
{
    Graph g(5);
    for (int i = 1; i < 5; ++i){
        for (int j = 1; j < 5; ++j) {g.addEdge(i,j);}
    }
    ///for (vector<int>::iterator i = g.adj[1].begin(); i != g.adj[1].end(); ++i){cout << endl << " 1 -> " << (*i);}
    int s = g.adj[1].size();
    for (int i = 0; i < s; ++i) {cout << endl << " 1 -> " << g.adj[1][i];}
    cout << endl << " 5 : " << g.degs[5];
}

void test_transpose()
{
    Graph g(5);
    for (int i = 1; i < 4; ++i){
        for (int j = 1; j < 4; ++j) {g.addEdge(i,j);}
    }
    g.addEdge(4,1); g.addEdge(1,4);
    Graph g2 = g.getTranspose();
    int s = g2.adj[4].size(); for (int i = 0; i < s; ++i) {cout << endl << " 4 -> " << g2.adj[4][i];}
    cout << endl << " 4 : " << g2.degs[4];
}
