#ifndef LABIRINT_PLAYER_H
#define LABIRINT_PLAYER_H
#include <string>

using namespace std;

class Player{
private:
    int moves;
public:
    string symbol;
    Player();
    Player(const string& s);
    void increase_moves();
    int get_moves();
};

#endif
