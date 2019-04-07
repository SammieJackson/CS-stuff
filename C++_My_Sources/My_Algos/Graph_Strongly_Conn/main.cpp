#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//#include <ctype.h> //for check if string is number
#include <stdio.h>
#include <stdlib.h>
//#include "graph.h"
#include "geeks_algo.h"

using namespace std;

/*
bool check_num(std::string& word){
    bool isNumber = true;
    for(string::const_iterator k = word.begin(); k != word.end(); ++k)
    isNumber &&= isdigit(*k);
}


void print_graph_(struct Graph_* graph){
    for (int i=1; i<=graph->V; i++){
        std::cout<<std::endl<<graph->node[i].num<<" - "<<graph->node[i].deg;
    }
}

void built_graph_(struct Graph_* graph){
    std::ifstream file("‪C:/Users/Admin/Desktop/_graph.txt",ios::in);
    if (file.good()) {
        std::string str;
        while(getline(file, str)){
            istringstream ss(str);
            int src, dest;
            ss>>src;
            if (src > graph->V) {cout<<"\n Input ERROR!\n"; return;}
            ss>>dest;
            if (dest > graph->V) {cout<<"\n Input ERROR!\n"; return;}
            add_edge(graph, src, dest);
        }
    } else cout<<"\n FILE ERROR!\n";
}

void built_gr_cin(struct Graph_* graph){
    int src, dest;
    cin>>src;
    cin>>dest;
    while(!cin.fail()){
        if (src > graph->V) {cout<<"\n Input ERROR!\n"; return;}
        if (dest > graph->V) {cout<<"\n Input ERROR!\n"; return;}
        add_edge(graph, src, dest);
        cin>>src;
        cin>>dest;
    }
}
*/

void build_Graph(Graph* graph){
    std::ifstream file("‪C:/Users/Admin/Documents/MyDocs/Education/CS/C++/My_Algos/Graph_Strongly_Conn/_410e934e6553ac56409b2cb7096a44aa_SCC.txt",ios::in);
    //std::ifstream file("C:/Users/Admin/Desktop/_f370cd8b4d3482c940e4a57f489a200b_kargerMinCut.txt",ios::in);
    if (file.good()) {
        std::string str;
        while(getline(file, str)){
            istringstream ss(str);
            int src, dest;
            ss>>src;
            if (src > graph->V) {cout<<"\n Input ERROR!\n"; return;}
            ss>>dest;
            if (dest > graph->V) {cout<<"\n Input ERROR!\n"; return;}
            graph->addEdge(src, dest);
        }
    } else cout<<"\n FILE ERROR!\n";
}


void build_Graph_2(Graph* graph){
    std::ifstream file("‪_410e934e6553ac56409b2cb7096a44aa_SCC.txt", ios::in);
    if (file.good()) {
        std::string str;
        int src, dest, tmp;
        bool i=1;
        while(getline(file, str)){
            istringstream ss(str);
            while (ss>>tmp) {
                if (tmp < 1 || tmp > graph->V) cout<<"\n Input error! Number out of range! \n"; else
                if (i == 1) {src = tmp; ++i;} else
                if (i == 0) {dest = tmp; ++i; graph->addEdge(src, dest);}
            }
        }
    } else cout<<"\n FILE ERROR!\n";
}



int main()
{
    //main0();

    //cout<<"\n Please enter the number of vertices:";
    int V = 875714;
    //cin>>V;

    Graph* graph = new Graph(V);
    //built_Gr_cin(graph);
    build_Graph(graph);
    //graph->printSCCs();
    graph->findSCCs();

    /*
    struct Graph_* graph0 = createGraph_(V);
    //built_graph_(graph0);
    built_gr_cin(graph0);
    //print_graph_(graph0); cout<<endl;
    DFS_regular_(graph0);
    */


    return 0;
}
