#include <iostream>
#include "Game.h"

using namespace std;

int main() {
    system("chcp 65001");
    srand(time(nullptr));
    system("cls");
    Game game = Game();
    game.start();
    return 0;
}
