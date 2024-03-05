#ifndef LABIRINT_GAME_H
#define LABIRINT_GAME_H
#include <iostream>
#include <conio.h>
#include <string>
#include "Labirint.h"
using namespace std;
class Game{
    private:
        int mode;
        Labirint labirint;
    public:
        Game();
        void start();
        void move_left();
        void move_right();
        void move_up();
        void move_down();
        static void mode_instruction();
        void instruction();
        static void select_player_symbol();
        st check_mode_and_return_size();
        static string check_symb(int x);
        string true_wordform(int x);
};


#endif