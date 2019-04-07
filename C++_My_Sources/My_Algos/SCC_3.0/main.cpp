#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "algo.h"

using namespace std;

void build_Graph(Graph* graph){
    std::ifstream file("_410e934e6553ac56409b2cb7096a44aa_SCC.txt", ios::in);
    if (file.good()){
        std::string str;
        int src, dest;
        while (getline(file, str)){
            istringstream ss(str);
            ss>>src; ss>>dest;
            if (src < 1 || src > graph->V || dest < 1 || dest > graph->V) cout<<"\n Input error! Number out of range! \n"; else
            if (src != dest) graph->addEdge(src, dest);
        }
    } else cout<<"\n FILE ERROR!\n";
    /// "C:/Users/Admin/Documents/MyDocs/Eduation/CS/C++/My_Algos/SCC_3.0/_410e934e6553ac56409b2cb7096a44aa_SCC.txt"
}

/**
void main1()
{
    std::ifstream file("_410e934e6553ac56409b2cb7096a44aa_SCC.txt", ios::in);
    if (file.good()){
        std::string str;
        int dest, tmp;
        getline(file, str);
        getline(file, str);
        getline(file, str);
        istringstream ss(str);
        ss>>tmp; ss>> dest;
        cout<<"\n "<<tmp<<" -> "<<dest<<endl;
    } else cout<<"\n FILE ERROR!\n";
}
//**/

int main()
{
    //**
    int V = 875714;
    Graph* graph = new Graph(V);
    build_Graph(graph);
    graph->findSCCs();
    //**/

    ///main1();
    ///test_SCC();
    ///test_DFS();
    ///test_adj();
    ///test_transpose();
    return 0;
}
