#ifndef TREEINT_H_INCLUDED
#define TREEINT_H_INCLUDED

#include <vector>
#include <list>
#include "Game.h"

struct NodeINT{
public:
    vector<int> parent;
    vector<int> children;
    bool visited = false;
    bool active = true; /// we deactivate a node if it is a duplicate
    int value = 0; // -1 - loss, 0 - draw, 1 - win
    int level_num = 0;
    int board_num = -1;
};

///NodeINT nullNode;

struct TreeINT{
public:
    vector<vector<NodeINT>> tree_floor;
    vector<Board> all_boards;
    //vector<NodeINT> all_nodes;
    int floors_added = -1;
    char symbs[2] = {fst_plr_smb, scnd_plr_smb};

    ///<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,,,

    void clear_duplicates_for_last_floor()
    {
        int p = tree_floor.size(), q = (tree_floor[p-2]).size();
        for (int i = 0; i < q; ++i)
        {
          NodeINT *tmp_par1 = &(tree_floor[p-2][i]);
          if (tmp_par1->active) {
            for (int j = i + 1; j < q; ++j)
            {
              NodeINT *tmp_par2 = &(tree_floor[p-2][j]);
              if (tmp_par2->active) {
                int s1 = (*tmp_par1).children.size(),
                    s2 = (*tmp_par2).children.size();
                bool flag = true;
                for (int l = 0; l < s1 && flag; ++l)
                {
                    for (int k = 0; k < s2 && flag; ++k)
                    {
                        //**
                        int chld1 = tmp_par1->children[l],
                            chld2 = tmp_par2->children[k]; //*/

                        NodeINT *tmp_child1 = &(tree_floor[p-1][chld1]);
                        NodeINT *tmp_child2 = &(tree_floor[p-1][chld2]);
                        //cout << "\n  " << tmp_child1->board_num << tmp_child2->board_num;
                        Board ch1 = all_boards[tmp_child1->board_num];
                        Board ch2 = all_boards[tmp_child2->board_num];
                        if ((ch1 == ch2) && (tmp_child1->level_num != tmp_child2->level_num))
                        {
                            flag = false;
                            (*tmp_par2).children[k] = (*tmp_par1).children[l];
                            (tree_floor[p-1][chld2]).active = false; //(*tmp_child2).active = false;
                            (*tmp_child1).parent.push_back(tmp_par2->level_num);
                            (tree_floor[p-1][chld2]).parent.resize(0); //(*tmp_child2).parent.resize(0);
                        }
                    }
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
            //all_nodes.resize(0);
            NodeINT root;
            Board empti;
            all_boards.push_back(empti);
            root.board_num = 0;
            root.level_num = 0;
            vector<NodeINT> zr_lvl;
            zr_lvl.push_back(root);
            //all_nodes.push_back(root);
            tree_floor.push_back(zr_lvl);
            floors_added++;
            cout << "\n Floor " << floors_added << " done.";
            return;
        }
        int mod = floors_added % 2;
        vector<NodeINT> next_lvl;
        int q = tree_floor.size();
        for (int l = 0; l < (tree_floor[q-1]).size(); ++l)
        {
            NodeINT tmp_node = tree_floor[q-1][l];
            Board tmp_board = all_boards[tmp_node.board_num];
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
                          NodeINT child_node;
                          child_node.board_num = all_boards.size() - 1;
                          child_node.level_num = next_lvl.size();
                          child_node.parent.push_back(tmp_node.level_num);
                          next_lvl.push_back(child_node);
                          //all_nodes.push_back(child_node);
                          (tree_floor[q-1][l]).children.push_back(child_node.level_num);
                      }
                  }///3
              }///2
            }///1
        }
        tree_floor.push_back(next_lvl);
        floors_added++;
        if (floors_added > 2) clear_duplicates_for_last_floor();
        cout << "\n Floor " << floors_added << " done.";
    }


    void create_tree()
    {
        while (floors_added < 9)
        {
            this->add_next_floor();
        }
        cout << "\n All floors done.";
    }
};

#endif // TREEINT_H_INCLUDED
