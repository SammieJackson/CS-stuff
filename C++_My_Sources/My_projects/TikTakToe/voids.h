#ifndef VOIDS_H_INCLUDED
#define VOIDS_H_INCLUDED

#include <iostream>
#include <cmath>
#include <windows.h>

#include "Bot.h"

using namespace std;

const int sz = 20000;

void treeint_full()
{
    TreeINT tr;
    tr.create_tree();
    /**
    for (int i = 0; i < 10; ++i)
    {
        NodeINT n = tr.tree_floor[i][0];//[tr.tree_floor[i].size()-1];
        if (n.active) {
            Board b = tr.all_boards[n.board_num];
            b.print();
        }
    } //*/
}

void treeint1()
{
    TreeINT tr;
    tr.create_tree();
    /**
    tr.add_next_floor();
    tr.add_next_floor();
    tr.add_next_floor();
    tr.add_next_floor();
    tr.add_next_floor();
    tr.add_next_floor();
    //tr.add_next_floor(); //*/
    //NodeINT n = tr.tree_floor[3][tr.tree_floor[3].size()-1];
    //**
    NodeINT n = (tr.tree_floor[9])[2];
    Board b = tr.all_boards[n.board_num];
    cout << boolalpha << "\n " << n.active << " " << b.isendgame;
    b.print(); //*/
}

void treeint0()
{
    TreeINT tr;
    tr.add_next_floor();
    tr.add_next_floor();
    tr.add_next_floor();
    tr.add_next_floor();
    tr.add_next_floor();
    /**
    for (int i = 0; i < 4; ++i)
    {
        NodeINT n = tr.tree_floor[i][tr.tree_floor[i].size()-1];
        Board b = tr.all_boards[n.board_num];
        b.print();
    } //**/
    /**
    bool flag = true;
    int t = 0, s = tr.tree_floor[4].size();
    Board b1, b2;
    for (int i = 0; i < s && flag; ++i){
        NodeINT *n1 = &(tr.tree_floor[4][i]);
        b1 = tr.all_boards[n1->board_num];
        for (int j = i + 1; j < s && flag; ++j){
            NodeINT *n2 = &(tr.tree_floor[4][j]);
            b2 = tr.all_boards[n2->board_num];
            if (b1 == b2 && n1->active && n2->active) ++t;//{flag = false; t1 = i; t2 = j;}//++t;//b2.print();
        }
    }
    cout << "\n\n " << t; //**/
}

void main_node0()
{
    Node n;
    Node *p1 = &n;
    Node *p2 = &(*p1);
    Board b = *(n.this_board);
    b = *(p1->this_board);
    b.print();
}

void main_node1()
{
    vector<vector<Node>> vv;
    vector<Node> v;
    Node n;
    v.push_back(n);//v.push_back(n);v.push_back(n);
    vv.push_back(v);
    ///vector<Node> *pv = &(vv.back());
    v.pop_back();
    vv.push_back(v);
    vector<Node> *pv = &(vv[0]);
    ///Node t = (*pv)[0];
    ///Board b = *(t.this_board);
    Node *p = &((*pv)[0]);
    Board b = *(p->this_board);
    b.print();
}


void tree_0()
{
    Tree tr;
    tr.create_tree();
}

void tree_1()
{
    Tree tr;
    //for (int i = 0; i < 4; ++i) {tr.add_next_floor(); cout<< "\n floor "<<i<<" added";}
    tr.add_next_floor(); cout<< "\n floor 0 added";
    tr.add_next_floor(); cout<< "\n floor 1 added";
    tr.add_next_floor(); cout<< "\n floor 2 added";
    tr.add_next_floor(); cout<< "\n floor 3 added";
    /**
    Node tmp = tr.tree_floor[3][8];
    Board tmp_board = *tmp.this_board;
    tmp_board.print(); //*/
    //**
    //cout << tr.floors_added << endl;
    //Node *n1 = &tr.tree_floor[0][0], *n2 = &tr.tree_floor[0][0];
    Board b1, b2;
    int t = 0, t1, t2;
    int s = tr.tree_floor[3].size();
    bool flag = true;
    for (int i = 0; i < s && flag; ++i){
        Node *n1 = &(tr.tree_floor[3][i]);
        b1 = *(*n1).this_board;
        for (int j = i + 1; j < s && flag; ++j){
            Node *n2 = &tr.tree_floor[3][j];
            b2 = *(*n2).this_board;
            if (b1 == b2 && (*n1).active && (*n2).active) ++t;//{flag = false; t1 = i; t2 = j;}//++t;//b2.print();
        }
    }
    cout << "\n\n " << t;
    /**
    cout << "\n " << t1 << " " << t2 << "\n";
    b1.print(); b2.print();  //*/
}

void tree_2()
{
    Tree tr;
    for (int i = 0; i < 4; ++i) {tr.add_next_floor(); cout<< "\n floor "<<i<<" added";}
    Node n, n1;
    Board b;
    n = tr.tree_floor[3].front();
    /**
    for (int i = 0; i < 2; ++i){
        n1 = (*n.parent[i]);
        b = (*n1.this_board);
        b.print();
    } //*/
    //**
    for (int i = 0; i < 4; ++i){
        n1 = tr.tree_floor[i].front();
        b = (*n1.this_board);
        b.print();
    } //*/
}

void tree_00()
{
    Tree tr;
    tr.add_next_floor();
    tr.add_next_floor();
    tr.add_next_floor();
    Node tmp;
    //tmp = tr.tree_floor.front().front();
    tmp = tr.tree_floor[2][10];
    Board tmp_board = *tmp.this_board;
    tmp_board.print();
}




void tree_02()
{
    Node tmp_node;
    Board tmp_board = *(tmp_node.this_board);
    for (int i = 0; i < desk_size; ++i)
    {
        for (int j = 0; j < desk_size; ++j)
        {
            Board child = tmp_board;
            int k = child.change_tile_to_symb('X',i,j);
            if (k == 0) child.print();
            cout << "\n " << child.isendgame << " " << k << "\n";
        }
    }
}

/**
void allpositions(){
    //BoardCode* arr = new BoardCode[sz];
    vector<BoardCode> vct; // = new vector<BoardCode>;
    BoardCode tmp;
    tmp.print();
    //for (int i = 0; i < sz; ++i){arr[i] = tmp;}
    int i = 0, nm = pow(3,9);
    //cout << nm;
    while (i < nm) {
        //arr[i] = tmp;
        vct.emplace_back(tmp);

        ++tmp;
        //tmp.print();
        ++i;
    }
    cout << "\n OK! \n";
    vct[1].print();
}

void main00()
{
    BoardCode tmp;
    tmp.print();
    //vector<BoardCode> *v = new vector<BoardCode>;
    //v->emplace_back(tmp);
    vector<BoardCode> v;
    v.emplace_back(tmp);
    v[0].print();
    //*
    ++tmp;
    tmp.print();
    ++tmp;
    tmp.print();
    ++tmp;
    tmp.print();
    ++tmp;
    tmp.print();
    ///
} //**/

void main0()
{
    GAME g;
    g.print();

    //*
    for (int i = 0; i < 3; ++i) {g.desk[i][i] = 'Y';}
    g.print();
    //*/

    cout << "\n\n  " << g.check_for_endgame();
}

void main_int()
{
    int *a = new int;
    *a = 5;
    cout << "\n " << *a;
    int *b = &(*a);//(int*)(*a);// = new int;
    //*b = *a;
    cout << "\n " << *b;
    (*b) += 1;
    cout << "\n " << *a;
    cout << "\n " << *b;
}

void main_ptr()
{
    int (*a)[2] = new int[2][2];
    a[0][0] = 0;
    a[0][1] = 1;
    a[1][0] = 2;
    a[1][1] = 3;
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < 2; ++j){cout << "\n " << a[i][j];}
    }
    /*
    delete [] a;
    a = new int[1][2];
    cout << "\n " << a[0][0];
    a[0][0] = 2;
    a[0][1] = 3;
    for (int j = 0; j < 2; ++j){cout << "\n " << a[0][j];}; //*/
    cout << "\n -------------------------------------- \n";
    int (*b)[2] = new int[2][2];
    *b[0] = *a[0];
    *b[1] = *a[1];
    cout << "\n " << b[0][1] << "\n";
    //for (int j = 0; j < 2; ++j){cout << "\n " << b[0][j];};
}

void main_ptr2()
{
    int (*a)[2] = new int[2][2];
    a[0][0] = 0;
}

#endif // VOIDS_H_INCLUDED
