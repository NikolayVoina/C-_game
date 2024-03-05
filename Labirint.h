#ifndef LABIRINT_LABIRINT_H
#define LABIRINT_LABIRINT_H
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <algorithm>
#include <ctime>
#include "Player.h"

using namespace std;


struct st{
    int x, y;
    st(int x, int y):x(x), y(y) {}
};

const int DC = 4;
const int DX[DC] = {1, 0, -1, 0};
const int DY[DC]= {0, 1, 0, -1};

class Labirint{
private:

    Player player;
    int get_top(int x);
    int get_bot(int x);
    int get_left(int x);
    int get_right(int x);

protected:
    vector < vector < short > > pole;
    int n, m;

public:
    st current_position = st(1, 0);
    Labirint(){}
    Labirint(int n, int m);
    void create_labirint();
    void set_size(int n, int m);
    void generator();
    bool check_generator();
    void dfs(st v, vector < vector < bool >  >&used);
    void show();
    void create_player(const string& s);
    void set_player_position(int x, int y);
    bool check(int x, int y);
    bool is_game_over();
    void show5();
    void increase_counter();
    int get_moves();
};

#endif