#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <vector>
#include <list>
#include "Game.h"

//const Board zero;

struct Node{
public:
    vector<Node*> parent;
    Board *this_board = nullptr;//new Board;
    vector<Node*> children;
    bool visited = false;
    bool active = true; /// we deactivate a node if it is a duplicate
    int value = 0; // -1 - loss, 0 - draw, 1 - win
    int number = 0; //board_number = -1;
};

///Node nullNode;

struct Tree{
public:
    vector<vector<Node>> tree_floor;
    list<Board> all_boards;
    list<Node> all_nodes;
    int floors_added = -1;
    bool cleared[desk_size_sq] = {0,0,0,0,0,0,0,0,0};
    char symbs[2] = {fst_plr_smb, scnd_plr_smb};

    void clear_duplicates_for_last_floor()
    {
        int s = tree_floor.size();
        vector<Node> *curr_parents = &tree_floor[s-2],
                     *curr_children = &tree_floor[s-1];
        ///*curr_parents = &tree_floor[s];
        ///*curr_children = &tree_floor[s+1];
        /**
        Node *tmp_par1,// = new Node,
             *tmp_par2,// = new Node,
             *tmp_child1,// = new Node,
             *tmp_child2;// = new Node;
        */
        s = (*curr_parents).size();
        for (int i = 0; i < s; ++i)
        {
            for (int j = i + 1; j < s; ++j)
            {
                Node *tmp_par1 = &((*curr_parents)[i]);
                Node *tmp_par2 = &((*curr_parents)[j]);
                ///Node *tmp_par1 = &(tree_floor[s-2][i]);
                ///Node *tmp_par2 = &(tree_floor[s-2][j]);
                int s1 = (*tmp_par1).children.size(),
                    s2 = (*tmp_par2).children.size();
                bool flag = true;
                for (int l = 0; l < s1 && flag; ++l)
                {
                    for (int k = 0; k < s2 && flag; ++k)
                    {
                        ///Node *tmp_child1 = &(*(*tmp_par1).children[l]);
                        ///Node *tmp_child2 = &(*(*tmp_par2).children[k]);
                        //**
                        int chld1 = tmp_par1->children[l]->number,
                            chld2 = tmp_par2->children[k]->number; //*/
                        /**
                        Node *tmp_child1 = &((*curr_children)[chld1]);
                        Node *tmp_child2 = &((*curr_children)[chld2]); //*/
                        Node *tmp_child1 = &(*(tmp_par1->children[l]));
                        Node *tmp_child2 = &(*(tmp_par2->children[k]));
                        Board ch1 = *(tmp_child1->this_board);
                        Board ch2 = *(tmp_child2->this_board);
                        if (ch1 == ch2)
                        {
                            flag = false;
                            (*tmp_par2).children[k] = (*tmp_par1).children[l];
                            (*(*tmp_par2).children[k]).active = false;
                              (*tree_floor[s][i].children[k]).active = false;///<<<<<<<<<
                              tree_floor[s+1][chld2].active = false;         ///<<<<<<<<<
                            (*tmp_child1).parent.push_back(tmp_par2);
                            (*tmp_child2).parent.resize(0);
                            (*tmp_child2).active = false;
                        }
                    }
                }
            }
        }
    }

    void add_next_floor()
    {
        if (floors_added == desk_size_sq) return;
        if (floors_added == -1) {
            all_boards.resize(0);
            all_nodes.resize(0);
            Node root;
            Board empti;
            all_boards.push_back(empti);
            *(root.this_board) = all_boards.back();
            vector<Node> zr_lvl;
            zr_lvl.push_back(root);
            all_nodes.push_back(root);
            tree_floor.push_back(zr_lvl);
            floors_added++;
            return;
        }
        int mod = floors_added % 2;
        vector<Node> lvl;
        tree_floor.push_back(lvl);
        int q = tree_floor.size();
        vector<Node> *crnt_lvl = &(tree_floor[q-2]);
        vector<Node> *next_lvl = &(tree_floor.back());
        for (int l = 0; l < (*crnt_lvl).size(); ++l)
        {
            Node tmp_node = (*crnt_lvl)[l];
            Board tmp_board = *(tmp_node.this_board);
            if (tmp_node.active && !tmp_board.isendgame)
            {///1
              for (int i = 0; i < desk_size; ++i)
              {///2
                  for (int j = 0; j < desk_size; ++j)
                  {///3
                      Board child = tmp_board;
                      int k = child.change_tile_to_symb(symbs[mod],i,j);
                      if (k == 0)
                      {
                          all_boards.push_back(child);
                          Node child_node;
                          *(child_node.this_board) = all_boards.back();
                          child_node.number = (tree_floor.back()).size();
                          Node* this_parent = &((*crnt_lvl)[l]);
                          child_node.parent.push_back(this_parent);
                          (tree_floor.back()).push_back(child_node);
                          all_nodes.push_back(child_node);
                          Node *tmp_pntr = &((tree_floor.back()).back());
                          ((*crnt_lvl)[l]).children.push_back(tmp_pntr);
                      }
                  }///3
              }///2
            }///1
        }
        //tree_floor.push_back(next_lvl);
        //delete crnt_lvl;
        floors_added++;
        if (floors_added > 2) clear_duplicates_for_last_floor();
    }

    void create_tree()
    {
        while (floors_added < 9)
        {
            this->add_next_floor();
            cout << "\n Floor " << floors_added << " done.";
        }
    }
};

#endif // TREE_H_INCLUDED
