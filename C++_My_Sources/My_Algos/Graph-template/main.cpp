#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "kargers.h"

using namespace std;

//Driver program to test graph functions
void main0(){
/* Let us create following unweighted graph
        0------1
        | \    |
        |   \  |
        |     \|
        2------3   */
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;

    // Use a different seed value for every run.
    srand(time(NULL));

    //printf("\nCut found by Karger's randomized algo is %d\n", kargerMinCut(graph));
    cout<<"\n Cut found by algo is "<<kargerMinCut(graph)<<endl;
    delete graph;
}

void main1(){
    int V=200, E=2517, edges=0;
    //cout<<"\n Please, enter number of nodes: ";
    //cin>>V;
    struct Graph* graph = createGraph(V, E);
    //cout<<"\n Now enter in i-th row number of the node ('i') and numbers of adjacent nodes: \n";
    std::ifstream file("C:/Users/Admin/Desktop/_f370cd8b4d3482c940e4a57f489a200b_kargerMinCut.txt",ios::in);
    if (file.good())
    {
        std::string str;
        int tmp_number, counter=1;
        while(getline(file, str) && counter<V){
            istringstream ss(str);
            int num;
            ss>>tmp_number;
            if (tmp_number != counter) {cout<<"\n Input ERROR!\n"; return;}
            counter++;
            while(ss >> num){
                if (num > tmp_number){
                    graph->edge[edges].src = (tmp_number-1);
                    graph->edge[edges].dest = (num-1);
                    edges++;
                }
            }
        }
        if (edges != E){cout<<"\n Irrelevant info provided!\n"; return;}
    }

    srand(time(NULL));
    //printf("\nCut found by Karger's randomized algo is %d\n", kargerMinCut(graph));
    cout<<"\n\n Cut found by algo is "<<kargerMinCut(graph)<<endl;
    delete graph;
}

void main2(){
    int V, E, edges=0;
    cout<<"\n Please, enter number of nodes and number of edges: ";
    cin>>V; cin>>E;
    struct Graph* graph = createGraph(V, E);
    cout<<"\n Now enter in i-th row number of the node ('i'), number of adjacent nodes and their respective numbers: \n";

        int tmp_number, counter=1;
        for (int i=1; i<=V; i++){
            cin>>tmp_number;
            if (tmp_number != counter) {cout<<"\n Input ERROR!\n"; return;}
            counter++;
            int amount;
            cin>>amount;
            for (int j=1; j<=amount; j++) {
                int num; cin>>num;
                if (num > tmp_number){
                    graph->edge[edges].src = (tmp_number-1);
                    graph->edge[edges].dest = (num-1);
                    edges++;
                }
            }
        }
        if (edges != E){cout<<"\n Irrelevant info provided!\n"; return;}

    srand(time(NULL));
    //printf("\nCut found by Karger's randomized algo is %d\n", kargerMinCut(graph));
    cout<<"\n\n Cut found by algo is "<<kargerMinCut(graph)<<endl;
    delete graph;
}

int count_edges(int V){
    int edges = 0;
    std::ifstream file("C:/Users/Admin/Desktop/_f370cd8b4d3482c940e4a57f489a200b_kargerMinCut.txt",ios::in);
    if (file.good())
    {
        std::string str;
        int tmp_number, counter=1;
        while(getline(file, str) && counter < V){
            istringstream ss(str);
            int num;
            ss>>tmp_number;
            if (tmp_number != counter) {cout<<"\n Input ERROR!\n"; return -1;}
            counter++;
            while(ss >> num){
                if (num > tmp_number){
                    edges++;
                }
            }
        }
    }
    return edges;
}

void main3(){
    int V, E, edges=0;
    cout<<"\n Please, enter number of nodes: ";
    cin>>V;
    E = count_edges(V);
    struct Graph* graph = createGraph(V, E);
    //cout<<"\n Now enter in i-th row number of the node ('i') and numbers of adjacent nodes: \n";
    std::ifstream file("C:/Users/Admin/Desktop/_f370cd8b4d3482c940e4a57f489a200b_kargerMinCut.txt",ios::in);
    if (file.good())
    {
        std::string str;
        int tmp_number, counter=1;
        while(getline(file, str) && counter<V){
            istringstream ss(str);
            int num;
            ss>>tmp_number;
            if (tmp_number != counter) {cout<<"\n Input ERROR!\n"; return;}
            counter++;
            while(ss >> num){
                if (num > tmp_number){
                    graph->edge[edges].src = (tmp_number-1);
                    graph->edge[edges].dest = (num-1);
                    edges++;
                }
            }
        }
        if (edges != E){cout<<"\n Irrelevant info provided!\n"; return;}
    } else cout<<"\n FILE ERROR!\n";

    srand(time(NULL));
    //printf("\nCut found by Karger's randomized algo is %d\n", kargerMinCut(graph));
    int minimum=E;
    for (int i = 0; i<100; i++){
        //struct Graph* graph0 = new Graph;
        //*graph0 = *graph;
        int tmp = kargerMinCut_mod(graph);//graph0
        if (tmp < minimum) minimum=tmp;
        //delete graph0;
    }
    cout<<"\n\n Minimum cut found by algo is "<<minimum<<endl;
    delete graph;
}

int main()
{
    //cout<<endl<<count_edges();
    main3();
    return 0;
}

