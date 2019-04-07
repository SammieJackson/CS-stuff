#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>
#include <sstream>

using namespace std;

const int desk_size = 3;
const char empty_tile = '0', fst_plr_smb = 'X', scnd_plr_smb = 'Y';

struct GAME
{
public:

    char start_symb = empty_tile, player_smbs[2] = {fst_plr_smb, scnd_plr_smb}, first_player = fst_plr_smb, second_player = scnd_plr_smb;
    //int desk[desk_size][desk_size] = {{0,0,0},{0,0,0},{0,0,0}};
    //char desk[desk_size][desk_size] = {{'0','0','0'},{'0','0','0'},{'0','0','0'}};
    char desk[desk_size][desk_size];
    int steps_made = 0;

    GAME(){
        for (int i = 0; i < desk_size; ++i) {
            for (int j = 0; j < desk_size; ++j){desk[i][j] = start_symb;}
        }
    }

    void print() const
    {
        ostringstream css;
        for (int j = 0; j < desk_size; ++j) {
            css << "\n  ";
            for (int i = 0; i < desk_size; ++i)
            {
                css << desk[j][i];
                if (i != (desk_size - 1)) css << " | ";
            }
            if (j != (desk_size - 1)) css << "\n -----------";
        }
        css << "\n\n";
        cout << css.str();
    }

    int make_step(char symb, int vert, int horiz)
    {
        if ( (vert < 0) || (vert > (desk_size - 1)) || (horiz < 0) || (horiz > (desk_size - 1)) || (desk[vert][horiz] != start_symb) || (symb == start_symb) ) return 1;
        desk[vert][horiz] = symb;
        return 0;
    }

    int make_step_for_first(int vert, int horiz)
    {
        return make_step(first_player, vert, horiz);
    }

    int make_step_for_second(int vert, int horiz)
    {
        return make_step(second_player, vert, horiz);
    }

    char check_for_endgame()
    {
        for (int i = 0; i < desk_size; ++i)
        {
            if ( (desk[0][i] == first_player && desk[1][i] == first_player && desk[2][i] == first_player) ||
                 (desk[i][0] == first_player && desk[i][1] == first_player && desk[i][2] == first_player) )
                return first_player;
            if ( (desk[0][i] == second_player && desk[1][i] == second_player && desk[2][i] == second_player) ||
                 (desk[i][0] == second_player && desk[i][1] == second_player && desk[i][2] == second_player) )
                return second_player;
        }
        if ( (desk[0][0] == first_player && desk[1][1] == first_player && desk[2][2] == first_player) ||
             (desk[2][0] == first_player && desk[1][1] == first_player && desk[0][2] == first_player) )
                return first_player;
        if ( (desk[0][0] == second_player && desk[1][1] == second_player && desk[2][2] == second_player) ||
                 (desk[2][0] == second_player && desk[1][1] == second_player && desk[0][2] == second_player) )
                return second_player;
        return start_symb;
    }

private:
};

/// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

const int desk_size_sq = desk_size * desk_size;

class BoardDyn
{
private:
    //char (*board)[desk_size];

public:
    char (*board)[desk_size] = new char[desk_size][desk_size];
    ///int codenum[desk_size_sq];
    bool isendgame = false;
    char winner = empty_tile;

    BoardDyn()
    {
        board = new char[desk_size][desk_size];
        for (int i = 0; i < desk_size; ++i){
            for (int j = 0; j < desk_size; ++j) {board[i][j] = empty_tile;}
        }
    }

    void check_for_endgame() //const
    {
        for (int i = 0; i < desk_size; ++i)
        {
            if ( (board[0][i] == fst_plr_smb && board[1][i] == fst_plr_smb && board[2][i] == fst_plr_smb) ||
                 (board[i][0] == fst_plr_smb && board[i][1] == fst_plr_smb && board[i][2] == fst_plr_smb) )
                { isendgame = true; winner = fst_plr_smb; return;} //first_player
            if ( (board[0][i] == scnd_plr_smb && board[1][i] == scnd_plr_smb && board[2][i] == scnd_plr_smb) ||
                 (board[i][0] == scnd_plr_smb && board[i][1] == scnd_plr_smb && board[i][2] == scnd_plr_smb) )
                { isendgame = true; winner = scnd_plr_smb; return;} //second_player
        }
        if ( (board[0][0] == fst_plr_smb && board[1][1] == fst_plr_smb && board[2][2] == fst_plr_smb) ||
             (board[2][0] == fst_plr_smb && board[1][1] == fst_plr_smb && board[0][2] == fst_plr_smb) )
                { isendgame = true; winner = fst_plr_smb; return;} //first_player
        if ( (board[0][0] == scnd_plr_smb && board[1][1] == scnd_plr_smb && board[2][2] == scnd_plr_smb) ||
             (board[2][0] == scnd_plr_smb && board[1][1] == scnd_plr_smb && board[0][2] == scnd_plr_smb) )
                { isendgame = true; winner = scnd_plr_smb; return;} //second_player
    }

    int change_tile_to_symb(char symb, int vert, int horiz)
    {
        if (this->isendgame) return 1;
        if ( (vert < 0) || (vert > 2) || (horiz < 0) || (horiz > 2) || (board[vert][horiz] != empty_tile) || (symb == empty_tile) ) return 1;
        board[vert][horiz] = symb;
        check_for_endgame();
        return 0;
    }

    int make_move_frst(int vert, int horiz)
    {
        return change_tile_to_symb(fst_plr_smb, vert, horiz);
    }

    int make_move_scnd(int vert, int horiz)
    {
        return change_tile_to_symb(scnd_plr_smb, vert, horiz);
    }

    BoardDyn& make_move(char symb, int vert, int horiz) const
    {
        BoardDyn res = (*this);
        res.change_tile_to_symb(symb, vert, horiz);
        return res;
    }

    BoardDyn& move_fst(int vert, int horiz) const
    {
        BoardDyn res = (*this);
        res.make_move_frst(vert, horiz);
        return res;
    }

    BoardDyn& move_scnd(int vert, int horiz) const
    {
        BoardDyn res = (*this);
        res.make_move_scnd(vert, horiz);
        return res;
    }

    int different_tiles(const BoardDyn& other)
    {
        int cntr = 0;
        for (int i = 0; i < desk_size; ++i){
            for (int j = 0; j < desk_size; ++j) {
                if (this->board[i][j] != other.board[i][j]) cntr++;
            }
        }
        return cntr;
    }

    bool operator==(const BoardDyn& other) const
    {
        bool flag = true;
        for (int i = 0; i < desk_size && flag; ++i){
            for (int j = 0; j < desk_size && flag; ++j){
                if (this->board[i][j] != other.board[i][j]) flag = false;
            }
        }
        return flag;
    }

    //**
    void operator=(const BoardDyn& other)
    {
        delete [] board;
        board = new char[desk_size][desk_size];
        ///*board = *(other.board);
        ///for (int i = 0; i < desk_size; ++i) {*board[i] = *(other.board[i]);}
        for (int i = 0; i < desk_size; ++i) {for (int j = 0; j < desk_size; ++j) {board[i][j] = other.board[i][j];} }
        isendgame = other.isendgame;
        winner = other.winner;
    } //**/

    void print() const
    {
        ostringstream css;
        for (int j = 0; j < desk_size; ++j) {
            css << "\n  ";
            for (int i = 0; i < desk_size; ++i)
            {
                css << board[j][i];
                if (i != (desk_size - 1)) css << " | ";
            }
            if (j != (desk_size - 1)) css << "\n -----------";
        }
        css << "\n\n";
        cout << css.str();
    }

};

class Board
{
private:
    //char (*board)[desk_size];

public:
    char board[desk_size][desk_size];// = new char[desk_size];
    int codenum[desk_size_sq];
    bool isendgame = false;
    char winner = empty_tile;

    Board()
    {
        for (int i = 0; i < desk_size; ++i){
            for (int j = 0; j < desk_size; ++j) {board[i][j] = empty_tile;}
        }
    }

    void check_for_endgame() //const
    {
        for (int i = 0; i < desk_size; ++i)
        {
            if ( (board[0][i] == fst_plr_smb && board[1][i] == fst_plr_smb && board[2][i] == fst_plr_smb) ||
                 (board[i][0] == fst_plr_smb && board[i][1] == fst_plr_smb && board[i][2] == fst_plr_smb) )
                { isendgame = true; winner = fst_plr_smb; return;} //first_player
            if ( (board[0][i] == scnd_plr_smb && board[1][i] == scnd_plr_smb && board[2][i] == scnd_plr_smb) ||
                 (board[i][0] == scnd_plr_smb && board[i][1] == scnd_plr_smb && board[i][2] == scnd_plr_smb) )
                { isendgame = true; winner = scnd_plr_smb; return;} //second_player
        }
        if ( (board[0][0] == fst_plr_smb && board[1][1] == fst_plr_smb && board[2][2] == fst_plr_smb) ||
             (board[2][0] == fst_plr_smb && board[1][1] == fst_plr_smb && board[0][2] == fst_plr_smb) )
                { isendgame = true; winner = fst_plr_smb; return;} //first_player
        if ( (board[0][0] == scnd_plr_smb && board[1][1] == scnd_plr_smb && board[2][2] == scnd_plr_smb) ||
             (board[2][0] == scnd_plr_smb && board[1][1] == scnd_plr_smb && board[0][2] == scnd_plr_smb) )
                { isendgame = true; winner = scnd_plr_smb; return;} //second_player
    }

    int change_tile_to_symb(char symb, int vert, int horiz)
    {
        if (this->isendgame) return 1;
        if ( (vert < 0) || (vert > 2) || (horiz < 0) || (horiz > 2) || (board[vert][horiz] != empty_tile) || (symb == empty_tile) ) return 1;
        board[vert][horiz] = symb;
        check_for_endgame();
        return 0;
    }

    int make_move_frst(int vert, int horiz)
    {
        return change_tile_to_symb(fst_plr_smb, vert, horiz);
    }

    int make_move_scnd(int vert, int horiz)
    {
        return change_tile_to_symb(scnd_plr_smb, vert, horiz);
    }

    Board& make_move(char symb, int vert, int horiz) const
    {
        Board res = (*this);
        res.change_tile_to_symb(symb, vert, horiz);
        return res;
    }

    Board& move_fst(int vert, int horiz) const
    {
        Board res = (*this);
        res.make_move_frst(vert, horiz);
        return res;
    }

    Board& move_scnd(int vert, int horiz) const
    {
        Board res = (*this);
        res.make_move_scnd(vert, horiz);
        return res;
    }

    int different_tiles(const Board& other)
    {
        int cntr = 0;
        for (int i = 0; i < desk_size; ++i){
            for (int j = 0; j < desk_size; ++j) {
                if (this->board[i][j] != other.board[i][j]) cntr++;
            }
        }
        return cntr;
    }

    bool operator==(const Board& other) const
    {
        bool flag = true;
        for (int i = 0; i < desk_size && flag; ++i){
            for (int j = 0; j < desk_size && flag; ++j){
                if (this->board[i][j] != other.board[i][j]) flag = false;
            }
        }
        return flag;
    }

    /**
    void operator=(const Board& other)
    {

    } //**/

    void print() const
    {
        ostringstream css;
        for (int j = 0; j < desk_size; ++j) {
            css << "\n  ";
            for (int i = 0; i < desk_size; ++i)
            {
                css << board[j][i];
                if (i != (desk_size - 1)) css << " | ";
            }
            if (j != (desk_size - 1)) css << "\n -----------";
        }
        css << "\n\n";
        cout << css.str();
    }

};

/**
class BoardCode {
private:
    int* num = new int;

public:
    BoardCode()
    {
        num = new int[desk_size_sq];
        for (int i = 0; i < desk_size_sq; ++i){num[i] = 0;}
    }

    //*
    ~BoardCode()
    {
        delete[] num;
    }
    //

    BoardCode(const BoardDyn& that)
    {
        num = new int[desk_size_sq];
        int k = 0;
        for (int i = 0; i < desk_size; ++i){
            for (int j = 0; j < desk_size; ++j) {
                char smb = that.board[i][j];
                int n = 0;
                switch(smb){
                    X: n = 1;
                            break;
                    Y: n = 2;
                            break;
                }
                num[k] = n;
                ++k;
            }
        }
    }

    void print()
    {
        ostringstream css;
        css << "\n ";
        for (int j = 0; j < desk_size_sq; ++j) {
            css << num[j];
        }
        css << " ";
        cout << css.str();
    }

    BoardCode& operator++()
    {
        int k = desk_size_sq - 1;
        bool flag = true;
        while (k >= 0 && flag) {
            num[k] += 1;
            if (num[k] >= 3) {
                num[k] = 0;
                --k;
            } else flag = false;
        }
        return (*this);
    }

};

//**/


#endif // GAME_H_INCLUDED
