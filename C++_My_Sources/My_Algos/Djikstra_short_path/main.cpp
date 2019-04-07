#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
//#include "geeks_I.h"
//#include "geeks_II.h"

using namespace std;

bool get_pair(std::string& str, int& a, int& b){
    std::istringstream ss(str);
    ss>>a;
    if (ss.fail()) {cout<<"\n Could not read a first number in pair. \n"; return 0;}
    char c;
    ss>>c;
    if(c != ',') {cout<<"\n Comma not found. \n"; return 0;}
    ss>>b;
    if (ss.fail()) {cout<<"\n Could not read the second number in pair. \n"; return 0;}
    return 1;
}

int mini_dist(int *&dist, bool sptSet[], int V)
{
   // Initialize min value
   int mini = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= mini)
         mini = dist[v], min_index = v;

   return min_index;
}


class Graph{
private:

public:
    static const int V = 200;
    int (*adj_matr)[V+1];
    Graph(int v);
    void add_edge(int num1, int num2, int w);
    void short_path(int src, int *&dist);
};

Graph::Graph(int v)
{
    //adj_matr = new int[V+1][V+1];
    //const int V0 = V+1;
    int(*adj)[V+1] = new int[V+1][V+1];
    adj_matr = adj;
    for (int i = 0; i <= V; ++i){
        for (int j = 0; j <= V; ++j){
            adj_matr[i][j] = 0;
        }
    }
}

void Graph::add_edge(int num1, int num2, int w){
    if (num1 > this->V || num2 > this->V) {cout<<"\n Node number is too big! \n"; return;}
    if (w <= 0) {cout<<"\n Zero or negative edge weight! \n"; return;}
    if (this->adj_matr[num1][num2] != 0 || this->adj_matr[num2][num1] != 0) {cout<<"\n Redefinition of an edge! \n"; return;}
    this->adj_matr[num1][num2] = w;
    this->adj_matr[num2][num1] = w;
}

void Graph::short_path(int src, int *&dist){
    bool sptSet[V+1];
    int V = this->V;
    for (int i = 1; i <= V; i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int counter = 1; counter <= V; ++counter){
        int u = mini_dist(dist, sptSet, V);
        sptSet[u] = true;
        for (int v = 1; v <= V; ++v){
            if (!sptSet[v] && this->adj_matr[u][v] && dist[u] != INT_MAX && dist[u]+this->adj_matr[u][v] < dist[v])
            dist[v] = dist[u] + this->adj_matr[u][v];
        }
    }
}

void build_graph(class Graph* graph){
    ifstream file("C:/Users/Admin/Desktop/_dcf1d02570e57d23ab526b1e33ba6f12_dijkstraData.txt",ios::in);
    if (file.good()){
        std::string str, tmp_pair;
        int tmp_line_num, tmp_node=1;
        while (getline(file, str)){
            std::istringstream ss(str);
            ss>>tmp_line_num;
            if (tmp_line_num > graph->V) {cout<<"\n Too many nodes in the input. (line - "<<tmp_line_num<<") \n"; break;}
            if (tmp_line_num != tmp_node) {cout<<"\n Invalid node number sequence. (line - "<<tmp_line_num<<") \n"; break;}
            while (ss>>tmp_pair){
                int num1=tmp_line_num, num2, weight;
                if (!get_pair(tmp_pair, num2, weight)) {cout<<"\n Invalid pair syntax. (line - "<<tmp_line_num<<") \n"; break;}
                if (num1 < 0 || num1 > graph->V) {cout<<"\n Invalid input - node number (line number) is out of range. (line - "<<tmp_line_num<<") \n"; break;}
                if (num2 < 0 || num2 > graph->V) {cout<<"\n Invalid input - node number (first in pair) is out of range. (line - "<<tmp_line_num<<") \n"; break;}
                if (weight < 0) {cout<<"\n Invalid input - negative weight. (line - "<<tmp_line_num<<") \n"; break;}
                if (num2 > num1) graph->add_edge(num1, num2, weight);
            }
            ++tmp_node;
        }
    } else cout<<"\n FILE ERROR! \n";
}

int main()
{
    //main00();
    int V = 200;
    cout<<"\n Enter the number of vertices, please: ";
    //cin>>V;
    Graph* graph = new Graph(V);
    int* dist = new int[V+1];
    build_graph(graph);
    graph->short_path(1, dist);
    int arr[10]={7,37,59,82,99,115,133,165,188,197};
    cout<<"\n\n "<<dist[arr[0]];
    for(int i = 1; i < 10; ++i){
        cout<<","<<dist[arr[i]];
    }
    cout<<endl;

    //for (int i = 1; i <= V; ++i){cout<<"\n  "<<dist[i];}

    delete[] dist;
    delete graph;

    return 0;
}
