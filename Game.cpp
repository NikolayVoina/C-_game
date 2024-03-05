#include "Game.h"

void Game::mode_instruction() {
    cout << "Enter game complexity: \n";
    cout << "1) 25 x 50 \n";
    cout << "2) 25 x 75 \n";
    cout << "3) 50 x 75 \n";
    cout << "Enter value in range from 1 to 3: ";

}

st Game::check_mode_and_return_size() {
    switch (mode) {
        case 1:
        default:
            return st(25, 50);
        case 2:
            return st(25, 75);
        case 3:
            return st(50, 75);
    }
}

void Game::select_player_symbol() {
    cout << "Choose player symbol: \n";
    cout << "1) @ \n";
    cout << "2) % \n";
    cout << "3) * \n";
    cout << "Enter value in range from 1 to 3: ";
}

string Game::check_symb(int x) {
    switch (x) {
        case 1:
        default:
            return "";
        case 2:
            return "%";
        case 3:
            return "*";
    }
}

void Game::move_down() {
    int x = labirint.current_position.x + 1;
    int y = labirint.current_position.y;
    if (labirint.check(x, y)){
        labirint.set_player_position(x, y);
    }
}

void Game::move_up() {
    int x = labirint.current_position.x - 1;
    int y = labirint.current_position.y;
    if (labirint.check(x, y)){
        labirint.set_player_position(x, y);
    }
}

void Game::move_right() {
    int x = labirint.current_position.x;
    int y = labirint.current_position.y + 1;
    if (labirint.check(x, y)){
        labirint.set_player_position(x, y);
    }
}

void Game::move_left() {
    int x = labirint.current_position.x;
    int y = labirint.current_position.y - 1;
    if (labirint.check(x, y)){
        labirint.set_player_position(x, y);
    }
}

string Game::true_wordform(int x) {
    if (x > 1) {
        return " steps";
    }else{
        return " step";
    }
}

void Game::instruction() {
    cout << "You can control your character using: ";
    cout << " arrows on keyboard, or {w, a, s, d}";
    system("pause");
}

void Game::start() {
    instruction();
    bool gameover = false;
    while (!gameover){
        system("cls");
        labirint.show5();
        int ch = getch();
        switch (ch) {
            case 72:
            case (int)'w':
            case (int)'W':
                move_up();
                break;
            case 80:
            case (int)'s':
            case (int)'S':
                move_down();
                break;
            case 75:
            case (int)'a':
            case (int)'A':
                move_left();
                break;
            case 77:
            case (int)'d':
            case (int)'D':
                move_right();
                break;
        }
        gameover = labirint.is_game_over();
    }
    system("cls");
    labirint.show();
    int steps = labirint.get_moves();
    string step_word = true_wordform(steps);
    cout << "You've made it " << steps << step_word << "\n";
    system("pause");
}

Game::Game(){
    mode_instruction();
    cin >> mode;
    st size = check_mode_and_return_size();
    labirint.set_size(size.x, size.y);
    select_player_symbol();
    int symb;
    cin >> symb;
    labirint.create_player(check_symb(symb));
}