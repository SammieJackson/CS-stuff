#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

/*
class Graph_I{
public:
    Graph_I()=default;
    Graph_I(const Graph_I&)=default;
    Graph_I(Graph_I&&)=default;
    operator =(const Graph_I&)=default;
    operator =(Graph_I&&)=default;

    Graph_I(int*& g_arr);
    void get_graph();

private:
    int g_size;
    int* arr=nullptr;
    long int edges;
};
*/

/*
class Graph_II{
public:
    Graph_II()=default;
    Graph_II(const Graph_II&)=default;
    Graph_II(Graph_II&&)=default;
    operator =(const Graph_II&)=default;
    operator =(Graph_II&&)=default;

    //Graph_II();
    void get_graph();

private:
    int g_size;
    long int edges;
    struct Node{const int number, int* adjac_nodes, Node* next};
    Node* head;

public:
    class Iterator{
    public:
        Iterator(Node *current=nullptr);
        virtual Iterator& operator ++();

    private:
        Node* current;
    };
    Iterator begin() const;
};

class Edge{
public:
    int node1, node2;
    Edge(int a, int b);
};
*/



#endif // GRAPH_H_INCLUDED
